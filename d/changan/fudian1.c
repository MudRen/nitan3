//Room: fudian1.c

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set("long", @LONG
�������ϻʹ����Ϊ�ͣ���߳����������������ж࣬����һ��ʮ�ɵĳ�
���ߵ����ӻʹ����������һ���������Գ�һ����ϵ��������ɭ��
LONG );
        set("exits", 
        ([ //sizeof() == 1
        	"west" : "/d/changan/huanggong",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/shiwei" : 2,
        ]));
	
        set("coor/x", -390);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
