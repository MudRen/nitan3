//Room: gongbu.c

inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG
�����������ϰ�����Ĺ����������е�������û����������������
��������ĸ��������Դ��������ӹ��γ��Ϻõ��òģ�Ȼ�������
����ת�˸��ء������Ĺ������澡�����µ��ܹ��ɽ���
LONG);
        set("exits",  ([ //sizeof() == 2
                "west"  : __DIR__"nanan-dadao",
                "north" : __DIR__"gongbu-tong",
                "south" : __DIR__"gongbu-shi",
        ]));

        set("coor/x", -390);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

