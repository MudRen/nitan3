// shanlu3.c
// Date: Nov.1997 by Venus

inherit BUILD_ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
СϪ���ɽ·����Ϫ��һ��Сʯ�š�Ϫ��ũ��С������Ϸ���֡������Ȥ��
�㲻����Ȼ��̾��һʱ������Զ�ܽ���֮�⡣���ϱ㵽�������ã����¾�������
�á�
LONG );
        set("exits", ([
            "southup"   : "/d/hangzhou/faxisi",
            "northdown" : "/d/hangzhou/fajinsi",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/boy" : 3,
        ]));
        set("outdoors", "hangzhou");
        set("max_room", 4);
        setup();
}
