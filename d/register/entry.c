// regiser: entry.c
// by Doing

#include <ansi.h>
#include <login.h>
#include <command.h>

inherit ROOM;

int is_chat_room() { return 1; }

int do_choose(string arg);
int do_washto(string arg);
int do_born(string arg);

mapping born = ([
        "��������" : "/d/guanwai/kedian",
        "��������" : "/d/beijing/kedian",
        "��³����" : "/d/taishan/kedian",
        "�ؽ�����" : "/d/changan/kezhan",
        "�ɹ�����" : 0,
        "��ԭ����" : "/d/shaolin/kedian1",
        "��������" : "/d/xingxiu/kedian",
        "��������" : "/d/jingzhou/kedian",
        "��������" : "/d/city/kedian",
        "��������" : "/d/suzhou/kedian",
        "��������" : "/d/hangzhou/kedian",
        "��������" : "/d/fuzhou/kedian",
        "��������" : "/d/city3/kedian",
        "��������" : "/d/dali/kedian",
        "ǭ������" : 0,
        "��������" : "/d/foshan/beidimiao",
        "ŷ������" : ([ "born"      : "��������",
                        "surname"   : "ŷ��",
                        "startroom" : "/d/baituo/dating",
                     ]),
        "�������" : ([ "born"      : "��������",
                        "surname"   : "��",
                        "startroom" : "/d/guanwai/xiaowu",
                     ]),
        "���ϻ���" : ([ "born"      : "��������",
                        "surname"   : "��",
                        "startroom" : "/d/dali/wangfugate",
                     ]),
        "Ľ������" : ([ "born"      : "��������",
                        "surname"   : "Ľ��",
                        "startroom" : "/d/yanziwu/cuixia",
                     ]),
        "��������" : ([ "born"      : "��������",
                        "surname"   : "��",
                        "startroom" : "/d/tangmen/kedian",
                     ]),
]);

void create()
{
        int i, k;
        string desc;
        string *position;

        set("short", HIR "����֮��" NOR);
        set("long",
"��������̹ſ���أ�����΢�磬��س��������ܻ��磬��ããһ\n"
"Ƭ���������������������������֮�ȡ�\n"
"����������һ��ʯͷ���ɵĳ��ӣ�����ˮ�峺ȴ�����ף���֪����������\n"
"����������Ϸ�������̫���������󣬲�֪�кΰ����\n"
"�����Ա���һ������(paizi)��(���룺[1;32mlook paizi[2;37;0m �ɿ��������ϵ�����)\n"
);
        set("no_fight", 1);
        set("item_desc", ([
                "paizi" : "Ͷ̥���������£��мǲ��ɲ��ʣ�ѡ�÷��򣬾�����born <����>��\n"
        ]));

        set("objects", ([
                __DIR__"npc/pangu" : 1,
        ]));

        // set("no_say", "�̹����ڱ�Ŀ��˼�����������˵����\n");

        desc = query("item_desc/paizi");
        position = keys(born);

        for (i = 0, k = 1; i < sizeof(position); i++)
        {
                if (! stringp(born[position[i]]))
                        continue;

                desc += sprintf("%2d. " HIW "%s" NOR "\n", k++, position[i]);
        }

        for (i = 0; i < sizeof(position); i++)
        {
                if (! mapp(born[position[i]]))
                        continue;

                desc += sprintf("%2d. " HIC "%s" NOR "\n", k++, position[i]);
        }
        set("item_desc/paizi", desc);

        setup();
}

void init()
{
        add_action("do_choose", "choose");
        add_action("do_washto", "washto");
        add_action("do_born", "born");
}

int do_choose(string arg)
{
        object me;
        int n;

        if (! objectp(me = this_player()) ||
            ! userp(me))
                return 1;
        
        if (! arg || arg == "")
        	n = 1;
        else
        	sscanf(arg, "%d", n);

        if (n < 1 || n > 4)
        {
                write("��ֻ��ѡ��(choose)ϵͳ���ṩ�������ֽ�ɫ�Ը�\n"
                    HIC "\t1" NOR ". ��������\n"
                    HIC "\t2" NOR ". ������\n"
                    HIC "\t3" NOR ". �ĺ�����\n"
                    HIC "\t4" NOR ". ���ռ�թ ("
                    HIC "1" NOR "-" HIC "4" NOR ")\n");
                return 1;
        }

        switch(n)
        {
        case 1:
                me->set("character", "��������");
                break;
        case 2:
                me->set("character", "������");
                break;
        case 3:
                me->set("character", "�ĺ�����");
                break;
        case 4:
                me->set("character", "���ռ�թ");
                break;
        }
        
        write(HIC "��ѡ����" NOR HIM + me->query("character") + NOR HIC"���Ը񣬽����������ϴ(washto)�츳�ˡ�\n" NOR, me);
        return 1;
}
        
int do_wash(string arg)
{
        int i;
        int points;
        int tmpstr, tmpint, tmpcon, tmpdex;
        object me;
        mapping my;

        if (! objectp(me = this_player()) ||
            ! userp(me))
                return 1;

        if (! me->query("character"))
        {
                write(HIC "�㻹����ȷ��(choose)����Ľ�ɫ�Ը���ѡ�츳�ɡ�\n" NOR, me);
                return 1;
        }
                
        write(HIC "�����������أ���ʱ��һ�ɼ������˽�ȥ��\n" NOR, me);

        tmpstr = tmpint = tmpcon = tmpdex = 13;

        switch (me->query("type"))
        {
        case "��ʿ��":
                tmpstr = 20;
                break;

        case "�ǻ���":
                tmpint = 20;
                break;

        case "������":
                tmpcon = 20;
                break;

        case "������":
                tmpdex = 20;
                break;

        default:
                break;
        }

        points = 80 - (tmpstr + tmpint + tmpcon + tmpdex);
        for (i = 0; i < points; i++) {
                switch (random(4)) {
                case 0: if (tmpstr < 30) tmpstr++; else i--; break;
                case 1: if (tmpint < 30) tmpint++; else i--; break;
                case 2: if (tmpcon < 30) tmpcon++; else i--; break;
                case 3: if (tmpdex < 30) tmpdex++; else i--; break;
                }
        }

        my = me->query_entire_dbase();

        my["str"] = tmpstr;
        my["int"] = tmpint;
        my["con"] = tmpcon;
        my["dex"] = tmpdex;
        my["kar"] = 10 + random(21);
        my["per"] = 10 + random(21);

        write(HIC "��ž����һ�����㱻ʪ���������˳�����\n" NOR, me);
        write(sprintf(HIY "\n����λ�õ����������츳�ֱ��ǣ�\n"
                          "�������� " HIG "%d" HIY " �� "
                          "���ԣ��� " HIG "%d" HIY " �� "
                          "���ǣ��� " HIG "%d" HIY " �� "
                          "������ " HIG "%d" HIY " ��\n"
                          "��������⣬��ȥͶ̥(born)�ɣ�\n\n" NOR,
                      tmpstr, tmpint, tmpcon, tmpdex));
        me->set_temp("washed", 1);

        return 1;
}

int do_washto(string arg) 
{ 
        int tmpstr, tmpint, tmpcon, tmpdex, dower; 
        object me; 
        mapping my; 
  
        if (! objectp(me = this_player()) ||
            ! userp(me))
                return 1;

        if (! me->query("character"))
        {
                write(HIC "�㻹����ȷ��(choose)����Ľ�ɫ�Ը���ѡ�츳�ɡ�\n" NOR, me);
                return 1;
        }
        
        if (! arg || sscanf(arg, "%d %d %d %d", tmpstr, tmpint, tmpcon, tmpdex) != 4)
                return notify_fail("ָ���ʽ��washto <����> <����> <����> <��>\n" +
                		   "��    �磺washto 20 20 20 20\n"); 
  
        if (tmpstr > 30 || tmpstr < 13) 
                return notify_fail("����ѡ���������ֵҪ�������13��30֮�䡣\n"); 
        
        if (tmpint > 30 || tmpint < 13) 
                return notify_fail("����ѡ���������ֵҪ�������13��30֮�䡣\n"); 
                
        if (tmpcon > 30 || tmpcon < 13) 
                return notify_fail("����ѡ��ĸ�����ֵҪ�������13��30֮�䡣\n"); 
                
        if (tmpdex > 30 || tmpdex < 13) 
                return notify_fail("����ѡ�������ֵҪ�������13��30֮�䡣\n"); 

        if (tmpstr + tmpint + tmpcon + tmpdex > 80) 
                return notify_fail("����ѡ����츳��ֵ�ܺͲ��ܴ���80��\n"); 
        
        dower = 80 - (tmpstr + tmpint + tmpcon + tmpdex);
      
        write(HIC "���������ǳأ���ʱ��һ�ɼ������˽�ȥ��\n" NOR, me); 
        my = me->query_entire_dbase(); 
  
        my["str"] = tmpstr; 
        my["int"] = tmpint; 
        my["con"] = tmpcon; 
        my["dex"] = tmpdex; 
        my["kar"] = 10 + random(21); 
        my["per"] = 10 + random(21); 
  	if (dower > 0)
  	my["dow"] = dower;
  	
        write(HIC "ֻ����ž����һ�����㱻ʪ���������˳�����\n" NOR, me); 
        write(sprintf(HIY "\n����λ�õ����������츳�ֱ��ǣ�\n" 
                    "�������� " HIG "%d" HIY " �� " 
                    "���ԣ��� " HIG "%d" HIY " �� " 
                    "���ǣ��� " HIG "%d" HIY " �� " 
                    "������ " HIG "%d" HIY " ��\n" 
                    "�츳�ܺ�Ϊ�� " HIR "%d" HIY " ������������⣬��ȥͶ̥(born)�ɣ�������" HIR "<born ��������>\n\n" NOR,
                     tmpstr, tmpint, tmpcon, tmpdex, 80 - dower)); 
        me->set_temp("washed", 1); 
  
        return 1; 
}

int do_born(string arg)
{
        object me;
        object obj;
        object item;
        mixed dest;
        string new_name;
        string msg;

        if (! objectp(me = this_player()) ||
            ! userp(me))
                return 1;

        if (! me->query("character"))
                return notify_fail("����ѡ��(choose)�ý�ɫ�Ը�����Ͷ̥Ҳ���ٰ���\n");
                
        if (! me->query_temp("washed"))
                return notify_fail("��������������ϴһ��(washto)��ѡ����츳����Ͷ̥Ҳ���ٰ���\n");

        if (arg && arg[0] < 160)
                return notify_fail("������������ĵ���������born �������ϣ�������born ŷ�������Ա���Ͷ��̥��\n");

        new_name = 0;
        if (arg) sscanf(arg, "%s %s", arg, new_name);

        if (! arg || (! stringp(dest = born[arg]) && ! mapp(dest)))
        {
                message_vision("�и�������ݺݵĶ�$N˵����Ҫ��ʲô��Ͷ̥ȥ���\n", me);
                return 1;
        }

        if (mapp(dest) && stringp(dest["notice"]))
                return notify_fail(dest["notice"]);

        if (stringp(dest))
        {
                if (! objectp(obj = find_object(dest)))
                        obj = load_object(dest);
                me->set("startroom", dest);
                me->set("born", arg);
                me->set("born_family", "û��");
        } else
        {
                if (! objectp(obj = find_object(dest["startroom"])))
                        obj = load_object(dest["startroom"]);

                if (new_name)
                {
                        if (! sscanf(new_name, dest["surname"] + "%*s"))
                                new_name = dest["surname"] + new_name;

                        if (strlen(new_name) > 8)
                                return notify_fail("�������̫���ˡ�\n");

                        if (strlen(new_name) < 4)
                                return notify_fail("�������̫���ˡ�\n");

                        if (! is_chinese(new_name))
                                return notify_fail("���������������֡�\n");
                }

                if (me->query("surname") != dest["surname"])
                {
                        // ������Ҫ�仯
                        NAME_D->remove_name(me->name(1), me->query("id"));
                        if (! new_name) new_name = dest["surname"] + me->query("purename");
                        if (stringp(msg = NAME_D->invalid_new_name(new_name)))
                        {
                                write(msg);
                                write("����Կ�����Ͷ�����ҵ�ʱ������ѡ�����֣�born <����> <����>\n");
                                return 1;
                        }
                        me->set("surname", dest["surname"]);
                        me->set("purename", new_name[strlen(dest["surname"])..<1]);
                        me->set_name();
                        NAME_D->map_name(me->name(1), me->query("id"));
                }

                me->set("startroom", dest["startroom"]);
                me->set("born", dest["born"]);
                me->set("born_family", arg);

                if (mapp(dest["family"]))
                {
                        me->set("family", dest["family"]);
                        me->assign_apprentice(dest["family"]["title"], 0);
                }
        }
        if (! objectp(obj))
        {
                message_vision("�и�������˵������ô����������...\n", me);
                return 1;
        }

        message_vision("һ�����������$N��ʧ����Ӱ���١�\n", me);
        
        foreach (item in all_inventory(me))
                if (! item->query("armor_type"))
                {
                        message_vision("$N������$n��\n", me, item);
                        if (item->is_character() || item->query("value"))
                                item->move(environment(me));
                        else
                                destruct(item);
                }

        // ѡ�����⼼��
        UPDATE_D->born_player(me);

        me->move(obj);
        me->set("mud_age", 0);
        me->set("age", 14);
        me->save();
        HELP_CMD->main(me, "rules");
        message_vision("$N�����۾�����㯵��������İ�������硣\n", me);

        return 1;
}
