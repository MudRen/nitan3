//Room: fengxu4.c

inherit ROOM;

void create ()
{
        set ("short", "��ڼ��");
        set("long", @LONG
��ڼ���ǳ��������Ĵ�֣���ʯ��·��ֱ����չ��ȥ��һ·�����˱ȼ磬��
�账��������֮����ֱ�����ɾ��ء����������̸�
LONG );
        set("exits", 
        ([ //sizeof() == 3
		"north" : "/d/changan/fengxu3",
        	"south" : "/d/changan/fengxu5",
        	"east" : "/d/changan/lingyange",
        ]));

        set("outdoors", "changan");
        set("coor/x", -380);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
