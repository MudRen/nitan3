//Room: nan-chengmen.c

inherit ROOM;

void create ()
{
        set ("short", "�����ϳ���");
        set("long", @LONG
�����ǵ��ϳ��š�����Ļ��ǺӼ������������ҳǸ�ǽ����һ�򵱹أ���
��Ī��֮�ƣ����ڻ�פ������Ӫʿ����Զ����Ӫ���࣬����ƺ����ľ�����֮�ƣ�
������¥��ֻ����¥�ߴ������ڱ����������ţ�ʿ������������ȥ��Զ����
����Ҫ���书��
LONG );
        set("exits", ([ /* sizeof() == 2 */ 
        	"southwest" : "/d/quanzhen/guandao1",
        	"north" : "/d/changan/nanan-daokou",
        ]));
        set("objects", ([ //sizeof() == 3
        	"/d/changan/npc/wujiang" : 1,
        	"/d/changan/npc/guanbing": 2,
        ]));

        set("outdoors", 1);
        set("coor/x", -400);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
