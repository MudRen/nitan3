//Room: jiulou2.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����¥��¥");
        set("long", 
"��¥�Ǿ�¥��������������Ŀ����Ƕ������������¥�µĿ����ǰ���\n"
"��������¥���ľƲ�Ҳ������¥�Ƴ������ֵġ����Թ��ų���ֱ���ݽǣ�\n"
HIR "       �������������ԾƸ߸裬����¥ͷ��������ͬ�֣�\n"
    "       ������һ�Σ��ٷ��յ���ƺὭ�ϣ����������\n"NOR );


        set("exits", ([
        	"down" : "/d/changan/jiulou",
        ]));
        set("objects", ([
        	"/d/changan/npc/yang-laoban" : 1,
        ]));

        set("coor/x", -430);
	set("coor/y", 50);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
