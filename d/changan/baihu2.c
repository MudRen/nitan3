//Room: baihu2.c

inherit ROOM;

void create ()
{
        set ("short", "�׻���");
        set("long", @LONG
�׻����ǳ��������Ĵ�֣���ʯ��·��ֱ����չ��ȥ��һ·�����˱ȼ磬��
�账��������֮����ֱ�����ɾ��ء����Ͼ��ǹʻʹ��Ľ�ˮ���ˣ�������һ����
·ͨ�򳤰��Ǳ��š�
LONG );
        set("exits", 
        ([ //sizeof() == 4
        	"south" : "/d/changan/bridge1",
		"north" : "/d/changan/beian-dadao",
        	"west" : "/d/changan/baihu1",
        	"east" : "/d/changan/baihu3",
        ]));

        set("outdoors", "changan");
        set("coor/x", -400);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
