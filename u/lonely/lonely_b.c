#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name("���Բ�", ({ "board" }));
        set("location", "/u/lonely/workroom");
        set("board_id", "lonely_b");
        set("wizard_only", 1);
        set("long", HIY "���ǽ�Ͽ�����ϣ��Źֵ����ģ�Ҳ��֪��������Щʲô��\n" NOR);
        setup();
        set("capacity", 1000);
        replace_program(BULLETIN_BOARD);
}
