//Room: huarui3.c

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set("long", @LONG
������ǳ�������һ��������Ĵ����Ҳ�ǳ����ǵľ�������һ����ʯ����
�ɵĽַ����ϱ߿ɼ�һЩ���סլ��������һ�һ��꣬��ͷ�д�������Ʈ�����
����ζ����Զ�������Ҽһ������׵����������д��˼�ե���͵Ĵ���ζ��
LONG );
        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/changan/minju3",
        	"north" : "/d/changan/huadian",
        	"west" : "/d/changan/huarui2",
        	"east" : "/d/changan/nanan-daokou",
        ]));

        set("outdoors", "changan");
        set("coor/x", -410);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
