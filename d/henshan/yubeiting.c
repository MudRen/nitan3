inherit ROOM;

void create()
{
        set("short", "����ͤ");
        set("long", @LONG
����Ϊ�����������ʯ���������ɣ�ʯ���������������
ǧ��Ĵ�ʯ���ϣ�������ϸ�壬��Ϊ������
LONG);
        set("exits", ([ 
               "south"  : __DIR__"zhengchuan",
               "north"  : __DIR__"jiayingmen",
        ]));

        set("no_clean_up", 0);

        set("coor/x", 0);
	set("coor/y", -70);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

