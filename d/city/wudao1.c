// Room: /city/wudao1.c

#include <ansi.h>

inherit "/d/city/underlt";

void create()
{
        set("short", "�����");
        set("long", @LONG
���������滷ɽ��ֻ�б����������ڵ�һƺɽ��ƽ�ء�ɽ��ɽ�������λ���
���죬ɽ���µ�ƽ���̲������м�����˸���̨������һ���ȥ���������
�����α����ȫ��������������ı��䳡�أ�
LONG );
        set("outdoors", "city");
        set("exits", ([
                "leitai"      : "/d/city/leitai",
                "east"        : "/d/city/wudao4",
                "north"        : __DIR__ "biwu_gate",
//                "south"        : __DIR__ "mishuchu",
        ]));
        set("no_fight", 1);
	set("coor/x", -60);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        init_here();
        replace_program("/d/city/underlt");
}
