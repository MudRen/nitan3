// gzf ���ɷ�

#include <ansi.h>;
inherit NPC;

void create()
{
        set_name(HIW "���ɷ�" NOR, ({ "gzf" }));
        set("title", HIR "�嶯֮��" NOR);
        set("gender", "����");
        set("age", 35);
        set("no_get", 1);
        set("long", sort_msg(HIY"����һλ�ɷ���ǵ�������ˣ����������ķ�������"
                "������̶���Ժ�������������˽�����ɷ�����̶������ʵ���֮һ����"
                "ϧ����������̶�����������������ʱ����ɱ����ʾ�������뿪��̶��\n" NOR));
        set("combat_exp", 60000);
        set("shen_type", 1);
        set("attitude", "friendly");

        set("apply/attack", 50);
        set("apply/defense", 50);

        set("max_qi", 800);
        set("max_jing", 800);
        set("max_neili", 800);

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

