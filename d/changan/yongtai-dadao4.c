//Room: yongtai-dadao4.c

inherit ROOM;

void create ()
{
        set ("short", "��̩���");
        set("long", @LONG
���ڽֵ������ϱ��������еĴ�֣��Ͷ����Ķ������ֻ��ཻ����ɡ�����
����������ʵ�ҹ����ȴ�������������ƻ�ͨ��������һ�����֡�����С�ֺ��
������Щ���ֽ����ã���Ȼ���򡣶�����һ��������
LONG );
        set("exits",([//sizeof() == 3
        	"south" : "/d/changan/yongtai-dadao5",
        	"north" : "/d/changan/xian-daokou",
        	"east" :"/d/changan/miao"
        ]));

        set("outdoors", "changan");
        set("coor/x", -440);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
        
