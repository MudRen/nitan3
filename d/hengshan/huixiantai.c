// Room: /d/hengshan/huixiantai.c
#include <room.h>
inherit JIETI;
inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
�߳���������ܿ���һ��ʯ�ߣ������ھ����������һ��С
�ң����ǻ���̨��̨������Ⱥ�ɵ����������飬����ʤ����
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "eastdown"  : __DIR__"beiyuedian",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jieti","jieti");
        add_action("do_decide","decide");
}

