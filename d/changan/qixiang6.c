//Room: qixiang6.c

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set("long", @LONG
������ǳ����Ǳ�һ��������Ĵ����������ྻ������ʮ�����֣�����
����������Ϣ����ֵ������̼��Ƽ������СС�ĵ��̱��ڶ�����������һ��ҩ
�꣬�����͵��˺����´����������±��ڡ�
LONG );
        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/changan/weapon-shop",
        	"north" : "/d/changan/yaopu",
        	"west" : "/d/changan/qixiang5",
        	"east" : "/d/changan/liande-beikou",
        ]));

        set("outdoors", "changan");
        set("coor/x", -370);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
