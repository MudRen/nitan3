// xtong3.c Сͯ

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("Сͯ", ({ "xiao tong","xiao","tong" }) );
        set("gender", "����" );
        set("age", 13);
        set("long", "����һ�������Сͯ������һ�����£�һ���ɰ������ӡ�\n");
        set("shen_type", 1);
        set("combat_exp", 50000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("attitude", "friendly");

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver",random(50));
}

