#include <ansi.h>
inherit ROOM;

int do_open(string arg);
int do_knock(string arg);
int do_back();

void create()
{
	set("short", "����");
	set("long", @LONG
���������µ�һ����ۡ�������ľ��涣��ڸ�ͤͤ����
��ʿ�Ҵ���ȥ��û�˵ÿ����㣬��û�˽Ӵ��㡣����õ�һ��
���ɵ�ʧ�䡣�Ա���һ��ľ�ţ�door����
LONG);
	set("exits", ([
		"northeast" : __DIR__"westroad1",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("item_desc", ([
                "door" : "����ľ�Ž����ţ���Щ�����ˡ�\n" ,
        ]));        
	set("no_clean_up", 0);
	set("coor/x", -460);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
}

void init()
{
        object me = this_player();

        if (me->query("family/family_name") == "������")
        {
                tell_object(me, HIG "\n��ͻȻ���ֶ����ɵ������ڴ˴���"
                                "���š�\n" NOR);
                me->set_temp("want_leave", 1);

                remove_call_out("letter");
                call_out("letter", 3, me);
        }
        add_action("do_back",  "back");
        add_action("do_knock", "knock");
        add_action("do_open", "open");
}

void letter(object me)
{
        if (! objectp(me))
                return;

        if (! me->query_temp("want_leave")) 
                return;

        tell_object(me, WHT "  ����������������\n"
                            "  �������������Щ�\n"
                            "  �������ܵ��ܹ���\n"
                            "  ��ֱͨ(" HIY "back" NOR + WHT ")�멧\n"
                            "  ���һ����ִ�\n"
                            "  ����������������\n" NOR);
}

int do_back()
{
        object me = this_player();

        if (me->query_temp("want_leave")) 
        {
                message("vision", HIC "��Ȼ��ֻ��" + me->name() + HIC
                                  "����һ�Σ���û����Ӱ��\n" NOR,
                                  environment(me), ({me}));
                me->move("/d/emei/midao5");
                tell_object(me, HIC "\n�����������������ڵ��ܵ���\n\n" NOR);
        }
        return 1;
}

int do_open(string arg)
{
        if(arg=="door")
        return notify_fail("������������ľ�ţ����һ�㶯����û�У������Ǳ������ˣ�\n");
        else return 0;
}

int do_knock(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg=="") 
                return notify_fail("��Ҫ��ʲô��\n");
          if (arg != "door")
                return notify_fail("��Ҫ��ʲô��\n");
          if( arg=="door" ) {
                message_vision("$N����������ľ�š�\n", me);
                if (me->query("bunch/bunch_name")!="������" && (int)me->query("shen") <= 0)
                {
                        message_vision(HIB"ľ��֨ѽһ�����ˣ�������̽����ͷ��������$N����˵����������Ͷ�����������ŵİɣ�����
˵��һ�Ѱ�$N���˽�ȥ��\n"NOR, me);
                        me->move("/d/city3/xlm_cdfb");
                        return 1;
                }
                if (good_bunch(me) || (me->query("bunch/bunch_name") != "������"  && (int)me->query("shen") > 0)) 
                { 
                                command("say ��������аħ������Ҵ�ô��\n"); 
                        return 1; 
                } 
                message_vision("ľ��֨ѽһ�����ˣ�������̽����ͷ��������$N����˵��������Ȼ�Ǳ��ŵ��ֵܣ��ͽ����ɣ�����
˵��һ�Ѱ�$N���˽�ȥ��\n",me);
                me->move("/d/city3/xlm_cdfb"); 
                return 1; 
        }
        
        return 1;
}
