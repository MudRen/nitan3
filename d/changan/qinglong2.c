//Room: qinglong2.c

inherit ROOM;

void create ()
{
        set ("short", "������");
        set("long", @LONG
�������ǳ��������Ĵ�֣���ʯ��·��ֱ����չ��ȥ��һ·�����˱ȼ磬��
�账��������֮����ֱ�����ɾ��ء��������ǹʻʹ��Ľ�ˮ���ˣ�������һ����
·ͨ�򳤰������š�
LONG );
        set("exits", 
        ([ //sizeof() == 4
        	"north" : "/d/changan/bridge2",
		"south" : "/d/changan/nanan-dadao",
        	"west" : "/d/changan/qinglong1",
        	"east" : "/d/changan/qinglong3",
        ]));

        set("outdoors", "changan");
        set("coor/x", -400);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
