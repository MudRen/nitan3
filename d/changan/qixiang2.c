//Room: qixiang2.c

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set("long", @LONG
������ǳ����Ǳ�һ��������Ĵ����������ྻ������ʮ�����֣�����
����������Ϣ����ֵ������̼��Ƽ������СС�ĵ��̱��ڶ������ֵı�������
��������һ�Ҳ�ݣ���ݵĶ�����һ��ˮ���ꡣ
LONG );
        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/changan/fruit-shop",
        	"north" : "/d/changan/tea-shop",
        	"west" : "/d/changan/qixiang1",
        	"east" : "/d/changan/qixiang3",
        ]));

        set("outdoors", "changan");
        set("coor/x", -420);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
