inherit ROOM;

void create()
{
    set("short", "��ɽС��");
    set("long", @LONG
��ɽС���ǻ�ɽ��λ���ϵı�������������򵥣�ȴ������Ȼ��С��
���и�С��������ֻ���е��ڳ����߷��裬�е�վ�ڳ�����ЪϢ����λ��
�ϲ�ϲ�����˴��ţ�����ɽ����Ҳ���ٵ��á�
LONG
    );

    set("exits", ([
        "southdown" : __DIR__"chaopath2",
    ]));

    set("objects", ([
        CLASS_D("huashan") + "/gao-laozhe" : 1,
        CLASS_D("huashan") + "/ai-laozhe" : 1,
    ]));

    set("no_clean_up", 0);

    setup();
    replace_program(ROOM);
}

