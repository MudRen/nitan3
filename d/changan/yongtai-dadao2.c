//Room: yongtai-dadao2.c

inherit ROOM;

void create ()
{
        set ("short", "��̩���");
        set("long", @LONG
���ڽֵ������ϱ��������еĴ�֣��Ͷ����Ķ������ֻ��ཻ����ɡ�����
����������ʵ�ҹ����ȴ�������������ƻ�ͨ��������һ�����֡�����С�ֺ��
������Щ���ֽ����ã���Ȼ���򡣶��洫��һ����������ĺ�������֪����ʲ
ô�ط���
LONG );
        set("exits",([//sizeof() == 2
        	"south" : "/d/changan/yongtai-dadao3",
        	"north" : "/d/changan/yongtai-dadao1",
                "east"  : "/d/pk/entry",
        ]));

        set("outdoors", "changan");
        set("coor/x", -440);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
