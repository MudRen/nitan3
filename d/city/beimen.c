// Room: /city/beimen.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǳ����ţ���Ϊ����ʧ�𣬵����ڳ�ǽ���Ǻں����ģ���˰�ֽ���ֵĹ�
����ʾ(gaoshi)���Ե��ر����ۡ�������һƬ��ɽ���룬һ������С����ɽ����
�Ѷ��ϡ�
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
             "east" : "/d/city/yanzhidian",
		"south" : "/d/city/beidajie2",
		"north" : "/d/shaolin/yidao",
		"west"  : "/d/huanghe/caodi1",
	]));
        set("objects", ([
                "/kungfu/class/yunlong/ma" : 1,
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
//	set("no_clean_up", 0);
	set("outdoors", "city");
	set("coor/x", 0);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}
