// Room: /city/wudao2.c

#include <ansi.h>
inherit "/d/city/underlt";

void create()
{
        set("short", "�����");
        set("long", @LONG
���������滷ɽ��ֻ�б����������ڵ�һƺɽ��ƽ�ء�ɽ��ɽ�������λ�
�����죬ɽ���µ�ƽ���̲������м�����˸���̨������һ���ȥ�������
�������α����ȫ��������������ı��䳡�أ�
LONG );
        set("outdoors", "city");
        set("exits", ([
                "leitai"      : "/d/city/leitai2",
                "west"        : "/d/city/wudao4",
        ]));
        set("no_fight", 1);
        setup();

        init_here();
        replace_program("/d/city/underlt");
}

