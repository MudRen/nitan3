//Room: minju4.c

inherit ROOM;

void create ()
{
        set ("short", "���");
        set("long", @LONG
������һ�����ס������̨�Ϸ��Ŵ��С��С����ɹޣ��������Ż���֮��
�Ķ��������ȴ��Ӵ󿪣�Ʈ��һ�ɻ��ݵ�����ζ�������ʮ�����֣�һ�Ŵ�ľ��
�ӣ���Χ���ż������ӣ������������һ�𣬲�֪��̸ʲô��
LONG );
        set("exits", 
        ([ //sizeof() == 1
        	"north" : "/d/changan/huarui4",
        ]));

        set("coor/x", -390);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
