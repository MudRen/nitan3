//Room: guozijian.c

inherit ROOM;

void create ()
{
        set ("short", "���Ӽ�");
        set("long", @LONG
���Ӽ��ǳ�͢�����˲ŵĵط����߸ߵ͵͵������������š������ﲻʱ����
��������������ѧ��ģ�����˴���������ʲô���⣬����һЩ������������üͷ
�Ҵҵ��߹���������˼����ʲô���⡣
LONG );
        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 1
        	"south" : "/d/changan/baihu3",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/xueshi" : 1,
	]));
              
        set("coor/x", -390);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
