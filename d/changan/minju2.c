//Room: minju2.c

inherit ROOM;

void create ()
{
        set ("short", "���");
        set("long", @LONG
���������ǿ�������������ض���Ȼ�������һ����ɫ��ɫ�ľ�����ױ̨��
ǰ��������ź�ľԲ�Ρ��Ҳ�ǽ���Ϲ���һ����Ů����ͼ���������м��бʼ���
�������С�֣��ڲ�����һ�ź�ɫ��ᣴ��ҵĵͰ�ľ齡�
LONG );
        set("exits", 
        ([ //sizeof() == 1
        	"north" : "/d/changan/huarui2",
        ]));

        set("coor/x", -420);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
