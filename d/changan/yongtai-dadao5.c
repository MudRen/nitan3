//Room: yongtai-dadao5.c

inherit ROOM;

void create ()
{
        set ("short", "��̩���");
        set("long", @LONG
���ڽֵ������ϱ��������еĴ�֣��Ͷ����Ķ������ֻ��ཻ����ɡ�����
����������ʵ�ҹ����ȴ�������������ƻ�ͨ��������һ�����֡�����С�ֺ��
������Щ���ֽ����ã���Ȼ����
LONG );
        set("exits",([//sizeof() == 2
        	"south" : "/d/changan/yongtai-nankou",
        	"north" : "/d/changan/yongtai-dadao4",
        ]));

        set("outdoors", "changan");
        set("coor/x", -440);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
        
