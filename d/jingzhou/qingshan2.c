inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
˳ɽ���ߣ�ɽ�ƽ��������������Ӳݾ��������� ʹ����
�����ߡ�
LONG);
        set("exits", ([
                "westup" : __DIR__"qingshan",
                "eastdown" : __DIR__"road4",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        set("coor/x", -340);
	set("coor/y", -190);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}

