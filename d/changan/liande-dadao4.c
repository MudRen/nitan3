//Room: liande-dadao4.c

inherit ROOM;

void create ()
{
        set ("short", "���´��");
        set("long", @LONG
���ڽֵ������ϱ��������еĴ�֣��Ͷ����Ķ������ֻ��ཻ����ɡ�����
����������ʵ�ҹ����ȴ�������������ƻ�ͨ��������һ�����֡�����С�ֺ��
������Щ���ֽ����ã���Ȼ���򡣶�����һ��������
LONG );
        set("exits",([//sizeof() == 2
       		"south" : "/d/changan/liande-dadao5",
        	"north" : "/d/changan/dongan-daokou",
        ]));

        set("outdoors", "changan");
        set("coor/x", -360);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
        
