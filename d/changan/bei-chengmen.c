//Room: bei-chengmen.c

inherit ROOM;

void create ()
{
        set ("short", "����������");
        set("long", @LONG
�����ǵı����š�����Ļ��ǺӼ������������ҳǸ�ǽ����һ�򵱹أ���
��Ī��֮�ƣ����ڻ�פ������Ӫʿ����Զ����Ӫ���࣬����ƺ����ľ�����֮�ƣ�
������¥��ֻ����¥�ߴ������ڱ����������ţ�ʿ�����   
LONG );
        set("exits", ([ /* sizeof() == 2 */ 
        	"north" : "/d/changan/tulu1",
        	"south" : "/d/changan/beian-daokou",
        ]));
        set("objects", ([ //sizeof() == 3
        	"/d/changan/npc/wujiang" : 1,
        	"/d/changan/npc/guanbing" :2,
        ]));

        set("outdoors", 1);
        set("coor/x", -400);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
