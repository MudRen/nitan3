//Room: liande-dadao5.c

inherit ROOM;

void create ()
{
        set ("short", "���´��");
        set("long", @LONG
���ڽֵ������ϱ��������еĴ�֣��Ͷ����Ķ������ֻ��ཻ����ɡ�����
����������ʵ�ҹ����ȴ�������������ƻ�ͨ��������һ�����֡�����С�ֺ��
������Щ���ֽ����ã���Ȼ����
LONG );
        set("exits",([//sizeof() == 3
        	"south" : "/d/changan/liande-nankou",
        	"north" : "/d/changan/liande-dadao4",
        	"east" : "/d/changan/xiaojia-qianyuan",
        ]));

        set("outdoors", "changan");
        set("coor/x", -360);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
        
