//Room: fufeng1.c

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set("long", @LONG
������ǳ��������Ĵ�֣���ʯ��·��ֱ����չ��ȥ��һ·�����˱ȼ磬��
�账��������֮����ֱ�����ɾ��ء������ǰ׻��֡�
LONG );
        set("exits", 
        ([ //sizeof() == 3
        	"south" : "/d/changan/fufeng2",
        	"east" : "/d/changan/baihu1",
        ]));

        set("outdoors", "changan");
        set("coor/x", -420);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
