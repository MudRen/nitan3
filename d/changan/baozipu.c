//Room: baozipu.c

inherit ROOM;

void create ()
{
        set ("short", "������");
        set("long", @LONG
������İ��貢���Ǻܽ������������˼���Բľ�����������������ҵķ���
���ѳ������ӡ�һ��С���û����ɵĿ��ڹ�̨�ߣ������������ֻ���������
������˸��к�����������������Ⲣ����ô�á�
LONG );
        //set("item_desc", ([" *** " : " *** ", ]));
        set("exits", 
        ([ //sizeof() == 1
        	"north" : "/d/changan/yongtai-nankou",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/huoji" : 1,
        ]));

	set("no_clean_up", 0);
        set("coor/x", -440);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
