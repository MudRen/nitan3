//Room: xiyuan.c

inherit ROOM;

void create ()
{
        set ("short", "ϷԺ");
        set("long", @LONG
���������İ����������˴���һ�����ɵ����е���ɫ��Ϸ̨��Ϸ̨���߹���
��յ�����ĵ�����ǰ������Щ���ʣ�������һЩ���Ͳ����Ϳ������Ρ�
LONG );
        set("exits", ([
        	"south" : "/d/changan/liande-beikou",
        ]));
        set("objects", ([
        	"/d/changan/npc/xizi" : 1,
        ]));

        set("coor/x", -360);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}


