//Room: fengxu5.c

inherit ROOM;

void create ()
{
        set ("short", "��ڼ��");
        set("long", @LONG
��ڼ���ǳ��������Ĵ�֣���ʯ��·��ֱ����չ��ȥ��һ·�����˱ȼ磬��
�账��������֮����ֱ�����ɾ��ء������������֣������ǳ����ǵ�Ѳ������
LONG );
        set("exits", 
        ([ //sizeof() == 3
		"north" : "/d/changan/fengxu4",
        	"west" : "/d/changan/qinglong3",
        	"east" : "/d/changan/xunbufang",
        ]));

        set("outdoors", "changan");
        set("coor/x", -380);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
