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
                "east"  : __DIR__"yidao2", 
                "north"  : __DIR__"chengmen",
        ]));

        setup();
}

