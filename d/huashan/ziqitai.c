inherit JIETI;
inherit BUILD_ROOM;

void create()
{
        set("short", "����̨");
        set("long", @LONG
����̨�����������ڣ����ɲ������գ���Ϊ������ǣ�ÿ������
�죬ɽ��֮�о��������������֡���Ŀ�������羰�续������������
��طǳ���⡣
LONG);
        set("outdoors", "huashan");
        set("exits",([ /* sizeof() == 1 */
            "eastdown": __DIR__"chaopath2",
        ]));
        set("max_room", 3);
        setup();
}

void init()
{
        add_action("do_jieti", "jieti");
        add_action("do_decide", "decide");
}
