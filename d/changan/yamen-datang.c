//Room: yamen-datang.c

inherit ROOM;

void create ()
{
        set ("short", "����������");
        set("long", @LONG
����������֮����һ������֮�ƣ����������ľ�������ǰ��һ�ź�ľ������
��������֪�����ˡ�����һ�����ң�д��"��������"�ĸ��̽���֡�����վ����
һλ��ʦү��
LONG );
        set("exits", 
        ([ //sizeof() == 1
        	"north" : "/d/changan/yamen",
        ]));
        set("objects", 
        ([ //sizeof() == 2
        	"/d/changan/npc/zhifu" : 1,
        	"/d/changan/npc/shiye" : 1,
        ]));

        set("coor/x", -390);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
