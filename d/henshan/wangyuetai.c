#include <ansi.h>

inherit JIETI;
inherit ROOM;

void create()
{
        set("short", "����̨");
        set("long", 
"����̨��ף�ڵ��һ���ʾ�ʯ��ÿ��ҹ������µ��գ���\n�����̱�"
"�֣�����������ԣ�������ɫ����ӳ�Ͱ���Ⱥ�塣��\nʱ��Ȼ�����"
"��ʮ���壬����������У�ʼ���·��޴���Ҳ��\nǰ�������ʫ��" HIW ""
"�˼������ѽԾ����˵������δ�͡�" NOR "��\n"
);
        set("exits", ([
               "southup"    : __DIR__"zhurongdian",
        ]));

        set("objects", ([
                __DIR__"npc/youke"    : 3,
        ]));    

        set("outdoors", "henshan");

        set("no_clean_up", 0);

        set("coor/x", -40);
	set("coor/y", 110);
	set("coor/z", 30);
	setup();
}

void init()
{
        add_action("do_jieti","jieti");
        add_action("do_decide","decide");
}

