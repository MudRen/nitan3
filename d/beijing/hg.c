#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ʹ����");
        set("long", @LONG
��������Ͻ��ǵ����ŵĴ�Ѱ�������ǵ������������ģ�������Բ���
����;������������ǸϿ��뿪Ϊ�á�[2;37;0m
LONG );
        set("exits", ([
                "north" : "/d/beijing/hgmen_n",
                "south" : "/d/beijing/hgmen_s",
                "west" : "/d/beijing/hg_w",
        ]));
        set("objects", ([
                "/d/beijing/npc/yuqian1" : 2,
        ]));
        set("outdoors", "beijing");
	set("coor/x", -30);
	set("coor/y", 290);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

