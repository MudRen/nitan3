//Room: yongtai-dadao1.c

inherit ROOM;

void create ()
{
        set ("short", "��̩���");
        set("long", @LONG
���ڽֵ������ϱ��������еĴ�֣��Ͷ����Ķ������ֻ��ཻ����ɡ�����
����������ʵ�ҹ����ȴ�������������ƻ�ͨ��������һ�����֡�����С�ֺ��
������Щ���ֽ����ã���Ȼ����
LONG );
        set("exits",([//sizeof() == 4
        	"south" : "/d/changan/yongtai-dadao2",
        	"north" : "/d/changan/yongtai-beikou",
        	"east" : "/d/changan/huozhan",
        ]));

        set("outdoors", "changan");
        set("coor/x", -440);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
        
