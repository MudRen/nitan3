////Room: qixiang3.c

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set("long", @LONG
������ǳ����Ǳ�һ��������Ĵ����������ྻ������ʮ�����֣�����
����������Ϣ����ֵ������̼��Ƽ������СС�ĵ��̱��ڶ������ֵı�����һ
�Ҷĳ����������������ϲ���ǡ��ĳ����ϰ�Ϊ�˷�����ˣ�����������ֶ���
����һ�ҵ��̡�
LONG );
        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/changan/dangpu",
        	"north" : "/d/changan/duchang",
        	"west" : "/d/changan/qixiang2",
        	"east" : "/d/changan/beian-daokou",
        ]));

        set("outdoors", "changan");
        set("coor/x", -410);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
