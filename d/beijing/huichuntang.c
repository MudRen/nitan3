#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ش���ҩ��");
        set("long", @LONG
�ش���ҩ�����������������������������ҩ�̡��㻹û�߽�������ŵ�
һ��ŨŨ��ҩ����ζ�����Ǵ�ҩ���ϵļ��ٸ�С������ɢ�������ġ�һλ�����
��̨��վ�ţ�����Ц���к��ſ��ˡ�
LONG );
       set("exits", ([
                "west" : "/d/beijing/xi_2",
                "east" : "/d/beijing/liandan_neiting",
        ]));
        set("objects", ([
                "/d/beijing/npc/kid1" : 1,
                "/d/beijing/npc/yaopuhuoji" : 1,
        ]));
        set("outdoors", "beijing");
	set("coor/x", -40);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}