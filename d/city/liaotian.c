inherit ROOM;

int is_chat_room()
{
	return 1;
}

void create()
{
        set("short", "�͵�跿");
        set("long", @LONG
���������ݿ�ջ�Ĳ�԰��������������µ��˶���������
���С�������ڿ����м䣬æ����ͣ���������С��Ҳϲ��
���������Ҷ��ۻ��
LONG);
        set("no_fight", 1);
        set("can_trade", 1);
        set("no_sleep_room", 1);

        set("exits", ([
                "south" : __DIR__"kedian",
        ]));

	set("coor/x", 10);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

