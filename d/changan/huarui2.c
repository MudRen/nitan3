//Room: huarui2.c

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set("long", @LONG
������ǳ�������һ��������Ĵ����Ҳ�ǳ����ǵľ�������һ����ʯ����
�ɵĽַ����ϱ߿ɼ�һЩ���סլ��������һ��С��ݣ���ͷ�д�������Ʈ����
�����ζ����Զ�������Ҽһ������׵����������д��˼�ե���͵Ĵ���ζ��
LONG );
        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/changan/minju2",
        	"north" : "/d/changan/mianguan",
        	"west" : "/d/changan/huarui1",
        	"east" : "/d/changan/huarui3",
        ]));

        set("outdoors", "changan");
        set("coor/x", -420);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
