// lwchang3.c
// By haiyan

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
������������̵����䳡���������ż���ľ�ˣ������ڵ��ӳ��ڴ˴�����а
�������ܳ����Ź���ɫ�ʡ�
LONG );
        set("exits", ([
            "south"    : "/d/heimuya/midao02",
        ]));
        set("objects", ([
            "/clone/npc/mu-ren" : 4,
        ]));

        setup();
        replace_program(ROOM);
}

