//Room: baihu3.c

inherit ROOM;

void create ()
{
        set ("short", "�׻���");
        set("long", @LONG
�������ǳ��������Ĵ�֣���ʯ��·��ֱ����չ��ȥ��һ·�����˱ȼ磬��
�账��������֮����ֱ�����ɾ��ء����涫�ߴ������ʵĶ������������ǵ�����
ѧ�����Ӽࡣ
LONG );
        set("exits", 
        ([ //sizeof() == 3
		"north" : "/d/changan/guozijian",
        	"west" : "/d/changan/baihu2",
        	"east" : "/d/changan/fengxu1",
        ]));

        set("outdoors", "changan");
        set("coor/x", -390);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
