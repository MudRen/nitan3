//ROOM: fen0.c
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
������������̽��µ�һ���á�������ľ�²�Զ�����µ�һ��������ͯ��
���ƹܴ��á�
LONG );
        set("exits", ([
            "north" :  "/d/heimuya/grass1",
        ]));
	set("objects",([
            CLASS_D("riyue") + "/tongbw": 1,
	]));
//        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

