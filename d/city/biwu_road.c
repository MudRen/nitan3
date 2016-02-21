#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_look(string arg);

void create()
{
    set("short", HIY"��������"NOR);
    set("long", @LONG
����һ���̵ܶ����ȣ�����ͨ��������Ϣ�ң��Ӵ��Ž���ֱ�ߣ�����������
���������
LONG );

    set("no_fight",1);
    set("no_beg",1);
    set("no_steal",1);
    set("biwu_room",1);

    set("exits", ([
        "west"  : "/d/city/biwu_restroom",
        "south" : "/d/city/biwu_gate",
        "north" : "/d/city/biwu_dating",
        "east"  : "/d/city/xinrui_dating",
    ]));

    set("no_clean_up", 0);
	set("coor/x", -60);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}
 int valid_leave(object me, string dir)
{
        //mapping conditions; 
        if (dir != "south") return 1;
//        if (wizardp(me)) return 1;

/*
        if (mapp(conditions = me->query_condition()))
               me->clear_condition();
*/
 
        if (me->query("eff_qi") < me->query("max_qi") ) 
               me->set("eff_qi",me->query("max_qi"));

        if (me->query("eff_jing") < me->query("max_jing"))
               me->set("eff_jing",me->query("max_jing"));

        return 1;
}
