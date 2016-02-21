// Written by Lonely@nitan3

#include <ansi.h>
inherit F_DBASE;


#define MAZE            "maze.c"
#define ENTRY           "enter.c"
#define EXIT            "out.c"
#define MAZE_DIR        "/d/maze/"
#define MAZE_DATA       "/data/maze/"  

#define DEST_TIME       1800   // 60 ���Ӻ�����
#define REMOVE_TIME     15     // 30 �������

int clean_up() { return 1; }

nosave object *total = ({ });
public object *query_total() { return total; }
public int remove_maze(object me, string arg);
private void init_player(object me);
private void restore_status(object me);
private void auto_check();
int check_out(object me);
int check_quit(object me);

public string query_maze_file(string x, string y)
{
        return sprintf(MAZE_DATA + "%s/%s/", x, y);
}

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "�Թ�����");
        CHANNEL_D->do_channel(this_object(), "sys", "�Թ�ϵͳ�Ѿ�������");
}

protected mixed create_maze(object me, string maze)
{
        string src, dst;
        string filename;

        src = MAZE_DIR + maze + "/" + MAZE;
        dst = query_maze_file(me->query("id"), maze) + MAZE;
        assure_file(dst);
        cp(src, dst);
        
        src = MAZE_DIR + maze + "/" + ENTRY;
        dst = query_maze_file(me->query("id"), maze) + ENTRY;
        filename = dst;
        cp(src, dst);
        
        src = MAZE_DIR + maze + "/" + EXIT;
        dst = query_maze_file(me->query("id"), maze) + EXIT;
        cp(src, dst);
        
        return filename;
}

public int enter_maze(object me, string arg) 
{
        string efile, mfile;
        object *member, ob;
        object *inv, obj;
        string id;
        int s;
        
        if( me->query_condition("killer") )
        {
                tell_object(me, "ɱ��ͨ�����ǲ��ܽ��븱���ġ�\n");
                return 0;
        }

        if( !wizardp(me) && 
            time() - me->query_temp("maze/time") < 180 )
        {
                tell_object(me, "Ϊ�˽�����ϷCPU��������Ϸ�����Ĵ�������ÿ��3����һ�Ρ�\n");
                return 0;
        }

        inv = deep_inventory(me);
        if( inv && sizeof(inv) > 0 )
        {
                foreach( obj in inv ) 
                        if( obj && obj->is_character() ) {
                                tell_object(me, "�����Խ�������ɫ����NPCͨ�����ķ�ʽ���������ڡ�\n");
                                return 0;
                        }
        }
                
        member = me->query_team_member(); 
        if( !member || !sizeof(member) )
                id = me->query("id");
        else        
                id = me->query_team_leader()->query("id");
                
        efile = query_maze_file(id, arg) + ENTRY;
        mfile = query_maze_file(id, arg) + MAZE; 
        
        // �Ѿ�������
        if( file_size(efile) > 0 )
        {
                if( !ob = find_object(efile) )
                {                        
                        if( sizeof(member) && ! me->is_team_leader() )
                        { 
                                tell_object(me, "�����ɶӳ���������������ġ�\n");
                                return 0;
                        }
                                        
                        if( !ob = load_object(efile) )
                        {
                                tell_object(me, "������������ʧ�ܣ����֮����\n");
                                return 0;
                        }
                        
                        obj = get_object(mfile);
                        obj->set("quest/time", time());
                        
                        s = SCHEDULE_D->set_event(DEST_TIME, 0, this_object(), "remove_maze", me, arg);
                        obj->set("quest/schedule", s);
                }
        } else 
        {       
                // û�д�����      
                efile = create_maze(me, arg);  
                if( !ob = get_object(efile) )
                {
                        tell_object(me, "������������ʧ�ܣ����֮����\n");
                        return 0;
                }
                
                mfile = query_maze_file(me->query("id"), arg) + MAZE; 
                obj = get_object(mfile);
                obj->set("quest/time", time());
                
                s = SCHEDULE_D->set_event(DEST_TIME, 0, this_object(), "remove_maze", me, arg);
                obj->set("quest/schedule", s);
        }

        if( !arrayp(total) )
                total = ({ me });
        else
        if( member_array(me, total) == -1 )
                total += ({ me });
                        
        tell_object(me, HIR "ף���������\n" NOR);
        me->set_temp("maze/time", time());
        me->set_temp("maze/name", arg);
        me->set_temp("maze/entry_room", environment(me));
        init_player(me);
        me->move(ob); 
        set_heart_beat(1);
        return 1;
}

private void heart_beat()
{
        if( sizeof(total) )
                auto_check();
        else
                set_heart_beat(0);
}

// check all the players who join the maze
private void auto_check()
{
        object ob;
        string room;
        object *lost;
        int i;

        lost = ({ });
        for( i = 0; i < sizeof(total); i++ )
        {
                if( !objectp(total[i]) )
                {
                        total[i] = 0;
                        continue;
                }
                room = base_name(environment(total[i]));
                if( !sscanf(room, MAZE_DATA + "%*s") )
                {
                        // not in maze room
                        restore_status(total[i]);
                        total[i] = 0;
                        continue;
                }
                if( total[i]->query("qi") < 1 || total[i]->query("jing") < 1 )
                        lost += ({ total[i] });
        }

        // kickout the players who lost competition
        foreach( ob in lost )
                check_out(ob);

        total -= ({ 0 });
        return;
}

// set player's override functions
private void init_player(object me)
{
        me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
        me->set_override("die", (: call_other, __FILE__, "check_out" :));
        // me->set_override("quit", (: call_other, __FILE__, "check_quit" :));
        me->set_temp("backup/killer", me->query_killer());
        me->set_temp("backup/want", me->query_want());

        me->set("backup/condition", me->query_condition());
        me->clear_condition();
        
}

int check_out(object me)
{
        object ob;
        mapping my;
        string msg;
        string room;

        room = base_name(environment(me));
        if( !sscanf(room,  MAZE_DATA +"%*s") )
        {
                // not in maze room
                total -= ({ me });
                return 0;
        }

        my = me->query_entire_dbase();
        my["eff_qi"] = my["max_qi"];
        my["eff_jing"] = my["max_jing"];
        my["qi"] = 1;
        my["jing"] = 1;

        tell_object(me, HIR "\n�������ǰһ��ģ��...�������ˣ�\n" NOR);
        if( ob = me->query_last_damage_from() )
                msg = WHT "\n$N��" + ob->name(1) + "������ˣ��Ǳ����ӣ�\n\n" NOR;
        else
                msg = WHT "\n$N�������ˣ��Ǳ����ӣ�\n\n" NOR;
                
        message_vision(msg, me);

        restore_status(me);
        total -= ({ me });
        me->move(me->query_temp("maze/entry_room"));
        message("vision", "һ����Ӱٿ�Ĵ��˳������漴���ǡ�ž����"
                "һ�����ͼ�" + me->name() +"ˤ���˵��ϣ�һ��������"
                "������ӡ�\n", environment(me), ({ me }));
        tell_object(me, "�������У�����ñ���������������"
                    "���ص�ˤ���˵��ϡ�\n");
        if( !living(me) )
                me->revive();
                
        return 1;
}

// overide function of quit
int check_quit(object me)
{
        restore_status(me);
        if( arrayp(total) )
                total -= ({ me });
                
        me->dismiss_team(me);
        tell_object(me, "���ӳ��˸�����\n");

        // continue run quit function
        me->move(me->query_temp("maze/entry_room"));
        message("vision", "ֻ��" + me->name() + "������ŵ����˳�����\n",
                environment(me), ({ me }));
        return 1;
}

private void restore_status(object me)
{
        object *inv, obj; 
        mapping cnd;
        string *ks;
        int i;

        inv = deep_inventory(me);
        if( inv && sizeof(inv) > 0 )
        {
                foreach( obj in inv ) 
                        if( obj && obj->query("maze_item") ) 
                                destruct(obj); 
        }
        me->delete_override("unconcious");
        me->delete_override("die");
        // me->delete_override("quit");
        remove_maze(me, me->query_temp("maze/name"));
        
        me->remove_all_enemy(1);
        me->remove_all_killer();
        me->clear_condition();
        me->receive_damage("qi", 0);
        me->apply_killer(me->query_temp("backup/killer"));
        me->apply_want(me->query_temp("backup/want"));

        cnd = me->query("backup/condition");
        me->delete("backup/condition");
        me->delete_temp("block_msg/all");
        if( !mapp(cnd) ) return;
        ks = keys(cnd);
        for( i = 0; i < sizeof(ks); i++ )
                me->apply_condition(ks[i], cnd[ks[i]]);
}

public mixed query_maze_dir(object ob) 
{
        object env;
        string user, maze, dir;
        
        env = environment(ob);
        if( !env ) return 0;

        if( sscanf(base_name(env), MAZE_DATA + "%s/%s/%*s", 
                user, maze) != 3 )
                return 0;
                
        dir = query_maze_file(user, maze);
        
        return dir;
}

public object query_maze_mainobj(object ob) 
{
        string file;
        
        file = query_maze_dir(ob) + MAZE;
        
        return get_object(file);
}

public void delay_remove_maze(object who, string arg) 
{
        SCHEDULE_D->set_event(REMOVE_TIME, 0, this_object(), "remove_maze", who, arg);
        // who->start_call_out((: call_other, __FILE__, 
        //                        "remove_maze", who, arg :), REMOVE_TIME); 
}

public int remove_maze(object me, string arg)
{
        string filename;
        object ob;
        int s;
        
        if( !objectp(me) ) return 0;
        
        me->set_temp("maze/time", time());
        
        filename = query_maze_file(me->query("id"), arg) + MAZE;
        ob = find_object(filename);
        if( ob ) 
        {
                if( s = ob->query("quest/schedule") )
                        SCHEDULE_D->delete_event(s);
                        
                destruct(ob);
        }

        filename = query_maze_file(me->query("id"), arg) + ENTRY;
        ob = find_object(filename);
        if( ob ) destruct(ob);
                
        filename = query_maze_file(me->query("id"), arg) + EXIT;
        ob = find_object(filename);
        if( ob ) destruct(ob);  
          
        return 1;
}
