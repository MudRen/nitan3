// shanlu5.c
// Date: Nov.1997 by Venus

inherit BUILD_ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ��ɽ���С������ɽ��Ұ���������͵Ĳ��ũ����Ů���ڻ�Ц����
�ɲ裬���˲��ɵþ���������ɱ��ֻ��þӴ˵ء�ɽ·�����������ߣ����߾�
����������������һ����·��
LONG );
        set("exits", ([
                "westup"   : "/d/hangzhou/shanlu4",
                "northeast": "/d/hangzhou/tulu1",
                "north"    : "/d/hangzhou/longjing",
                "east"     : "/d/hangzhou/yanxiadong",
        ]));
        set("objects", ([
                "/d/hangzhou/npc/caichanu" :2,
        ]));
        set("outdoors", "hangzhou");
        set("max_room", 4);
        setup();
}
