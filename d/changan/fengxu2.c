//Room: fengxu2.c

inherit ROOM;

void create ()
{
        set ("short", "��ڼ��");
        set("long", @LONG
��ڼ���ǳ��������Ĵ�֣���ʯ��·��ֱ����չ��ȥ��һ·�����˱ȼ磬��
�账��������֮����ֱ�����ɾ��ء�
LONG );
        set("exits", 
        ([ //sizeof() == 2
		"north" : "/d/changan/fengxu1",
        	"south" : "/d/changan/fengxu3",
        ]));

        set("outdoors", "changan");
        set("coor/x", -380);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
