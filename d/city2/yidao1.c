inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "�������");
        set("long",
"������ͨ�����ξ��ǵ����������������ս��ֹ���Եø���ػ���\n"
"����ʱ����������ƥ�ɱ�����������һ�����̣���;��ʱ�����˴�����֣�\n"
"��������ͣ���ĺá�\n"
);
        set("outdoors", "xiangyang");
        set("no_fly",1);

        set("exits", ([
                "east"  : "/d/xiangyang/westgate2", 
                "west"  : __DIR__"yidao2",
        ]));
        setup();
}

