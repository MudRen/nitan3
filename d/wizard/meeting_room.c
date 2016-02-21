// meeting_room.c

#include <ansi.h>
#include <command.h>
inherit ROOM;

#define SAY_CMD         "/cmds/std/say"

int do_start(string arg);
int do_say(string msg);
int do_over();
int do_not();

void create()
{
        set("short", "��ʦ������");
        set("long", @LONG
���������̶��ʦ�Ļ��������ڡ��շ�ˢ��������ǽ���Ϲ�����
̶�� ��ʦ���񣬷ֱ��У��ߴ���ʤ��(lonely)������(ken)����ȫ��
��(sinb)����̶����ʦ����һ������(yezh)������è(dump)����̶
�� ��ʦ���񣬷ֱ��У����(wind)����Ҷ(qiy) ���Ϻ�����(jak)��
����(dream)��������ѩ(hhm)�ȵȡ����ӵ����������һ���ľ���Σ�
����̶��ʦ�����������õġ�
LONG );

        set("exits", ([ 
                "down" : __DIR__"wizard_room",
        ]));

        set("valid_startroom", 1);
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_clean_up", 0);

        setup();

        call_other("/clone/board/meet_b", "???");
}

void init()
{
        add_action("do_say", "say");
        add_action("do_say", "'");
        add_action("do_start", "start");
        add_action("do_over", "over");
        add_action("do_not", "tell");
        add_action("do_not", "replay");
        add_action("do_not", "whisper");
        add_action("do_not", "kickout");
        add_action("do_not", "goto");
        add_action("do_not", "call");
        add_action("do_not", "flyto");
        add_action("do_not", "home");
        add_action("do_not", "dual");  
        add_action("do_not", "dest"); 
        add_action("do_not", "quit");      
}


int do_start(string arg)
{
        object me;

        me = this_player();

        if (wiz_level(me) < wiz_level("(arch)"))
                return notify_fail("�Բ�������Ȩ�ٿ���ʦ���顣\n");

        if ((int)query("meeting_trigger") != 0)
                return notify_fail("�������ڽ����С�\n");

        set("meeting_trigger", 1);

        foreach (object player in users())
        {
                if (! wizardp(player))
                        continue;
                        
                if (player == me)
                        continue;

                tell_object(player, sprintf(GRN "%s(%s)�����㣺��ʦ���������ٿ����뵽��ʦ�����ҿ��ᡣ\n" NOR, 
                                            me->query("name"), me->query("id")));
                                            
                player->move("/d/wizard/meeting_room.c");
                message_vision("$N׼ʱ�����˻᳡��\n", player);       
                player->set_temp("disable_type", HIW "<������>" NOR);                                 
        }

        me->set_temp("keeper", 1);
        
        message_vision(HIW "\n$N�������������������ڿ�ʼ����\n" NOR, me);

        log_file("meeting.log", sprintf("%s(%s) start the meeting on %s.\n", 
                                        me->name(1), geteuid(me),
                                        ctime(time())));     
        return 1;
}

int do_say(string msg)
{
        if (! msg) return 0;

        SAY_CMD->main(this_player(), msg);
        
        if ((int)query("meeting_trigger") == 1)        
                log_file("meeting.log", sprintf(CYN "%s(%s)˵����" + msg + "\n" NOR,
                                                this_player()->name(1), 
                                                this_player()->query("id")));
        return 1;
}

int do_over()
{
        object *ob, me;
        int i;
        string wiz_status;
        me = this_player();
        
        if (! wizardp(me) || wiz_level(me) < wiz_level("(arch)"))
                return notify_fail("��û��Ȩ����ֹ���顣\n");
                
        if ((int)query("meeting_trigger") == 0)
                return notify_fail("����û�н����κλ��顣\n");
        
        delete("meeting_trigger");
 
        foreach (object player in users())
        {
                if (! wizardp(player))
                        continue;
                        
                if (player->query_temp("disable_type") ==  HIW "<������>" NOR)       
                        player->delete_temp("disable_type");   
        }
        
        message_vision(HIW "\n$N�������������������ڽ�������\n" NOR, me);
        log_file("meeting.log", sprintf("%s(%s) over the meeting on %s.\n", 
                                        me->name(1), geteuid(me), 
                                        ctime(time())));
        return 1;
}

int do_not()
{
       if (query("meeting_trigger"))
       {
               write("��ר�Ŀ��ᣡ\n");
               return 1;
       }
       return 0;
}

int valid_leave(object me, string dir)
{
        if (query("meeting_trigger"))
                return notify_fail("�������ڿ����أ����������Ҳ��Ҫȥ��\n");
                
        return ::valid_leave(me, dir);
}


