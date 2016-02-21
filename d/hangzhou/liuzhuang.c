// liuzhuang.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
        set("short", "��ׯ");
        set("long", @LONG
ׯ԰�Ĵ������ǡ���ׯ���������֡�����(gate)���գ����澲���ĵ�һ����
����û�С�
LONG );
        set("exits", ([
            	"east"  : "/d/hangzhou/dadao3",
		"south" : "/d/hangzhou/liuzhuang1",
		"north" : "/d/hangzhou/liuzhuang2",
        ]));
        set("item_desc", ([
           	"gate" : "���Ĵ��Ž����ţ�����(knock)���ɡ�\n"
        ]));
        set("objects", ([
                "/d/hangzhou/npc/guanjia" : 1,
                "/d/hangzhou/npc/jiading" : 2,
        ]));
        setup();
}

void init()
{
        add_action("do_knock", "knock");
}

int do_knock(string arg)
{
        object me;

        me = this_player();
	message_vision("$N���ˣ��ˣ��ˣ����������������ţ�������ȴһ"
		       "�㶯����û�С�\n", me);
        return 1;
}

