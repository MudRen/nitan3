// shandao1.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������һ����ɽ�����Ƽ�֮�վ���һ��խС���͵�ɽ��ͨ��ɽ�ϣ�����ɽ��
��һƬ��̲��
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
            "eastdown" : "/d/heimuya/changtan",
            "westup"   : "/d/heimuya/shandao2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
