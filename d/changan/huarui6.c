//Room: huarui6.c

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set("long", @LONG
������ǳ�������һ��������Ĵ����Ҳ�ǳ����ǵľ�������һ����ʯ����
�ɵĽַ����ϱ߿ɼ�һЩ���סլ����ͷ�д�������Ʈ��������ζ����Զ����
���Ҽһ������׵����������д��˼�ե���͵Ĵ���ζ��
LONG );
        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/changan/minju6",
        	"north" : "/d/changan/tuchangguan",
        	"west" : "/d/changan/huarui5",
        	"east" : "/d/changan/liande-nankou",
        ]));

        set("outdoors", "changan");
        set("coor/x", -370);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
