// shanlu2.c
// Date: Nov.1997 by Venus

inherit BUILD_ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����������Ǻܿ��ɽ·�ϣ�ֻ�����Է�����������ɫ���ˡ�һ��СϪ��·
������������Ϫ����һũ�ҡ�ɽ��С����ʹ������������֮�⡣���ϱ㵽������
�á����¾��������á�
LONG );
        set("exits", ([
            "southup"   : "/d/hangzhou/fajinsi",
            "northdown" : "/d/hangzhou/fajingsi",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/honghua2" : 2,
        ]));
        set("outdoors", "hangzhou");
        set("max_room", 4);
        setup();
}

