//Room: dong-chengmen.c

inherit ROOM;

void create ()
{
        set ("short", "����������");
        set ("long", @LONG
�����ǵĶ����š�����Ļ��ǺӼ������������ҳǸ�ǽ����һ�򵱹أ���
��Ī��֮�ƣ����ڻ�פ������Ӫʿ����Զ����Ӫ���࣬����ƺ����ľ�����֮�ƣ�
������¥��ֻ����¥�ߴ������ڱ����������ţ�ʿ����� 
LONG);
        set("exits", ([ /* sizeof() == 2 */ 
        	"east"  :  "/d/changan/road4",
        	"west" : "/d/changan/dongan-daokou",
        ]));
        set("objects", ([ //sizeof() == 3
        	"/d/changan/npc/wujiang" : 1,
        	"/d/changan/npc/guanbing" :2,
        ]));

        set("outdoors", 1);
        set("coor/x", -350);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
