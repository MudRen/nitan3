//Room: huarui5.c

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set("long", @LONG
������ǳ�������һ��������Ĵ����Ҳ�ǳ����ǵľ�������һ����ʯ����
�ɵĽַ����ϱ߿ɼ�һЩ���סլ����ͷ�д�������Ʈ��������ζ����Զ����
���Ҽһ������׵����������д��˼�ե���͵Ĵ���ζ��·�������С��������
�ֳ�����ˣ�š�����
LONG );
        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/changan/minju5",
        	"west" : "/d/changan/huarui4",
        	"east" : "/d/changan/huarui6",
        	"north" : "/d/changan/zahuopu",
        ]));

        set("outdoors", "changan");
        set("coor/x", -380);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
