//Room: huarui4.c

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set("long", @LONG
������ǳ�������һ��������Ĵ����Ҳ�ǳ����ǵľ�������һ����ʯ����
�ɵĽַ����ϱ߿ɼ�һЩ���סլ��������С��������ͷ�д�������Ʈ������
��ζ����Զ�������Ҽһ������׵����������д��˼�ե���͵Ĵ���ζ��
LONG );
        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/changan/minju4",
        	"north" : "/d/changan/xiaojinghu",
        	"west" : "/d/changan/nanan-daokou",
        	"east" : "/d/changan/huarui5",
        ]));

        set("outdoors", "changan");
        set("coor/x", -390);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
