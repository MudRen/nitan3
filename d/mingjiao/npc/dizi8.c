// dizi8.c �����Ž���
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�����Ž���", ({"jiao zhong","zhong"}));
        set("long","����һλ�������·����ŵĽ��ڡ�\n");
        set("gender", "����");
        set("attitude", "peaceful");
        set("class", random(2)?"bonze":"taoist");
        set("age", 20+random(40));
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 500);
        set("max_jing", 600);
        set("neili", 600);
        set("max_neili", 600);
        set("jiaji", 1);
        set("combat_exp", 40000+(random(40000)));
        
        set_skill("force", 40);
        set_skill("shenghuo-shengong", 40);
        set_skill("dodge", 40);
        set_skill("qingfu-shenfa", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("lieyan-dao", 40);
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("parry", "lieyan-dao");
        map_skill("blade", "lieyan-dao");

        setup();
        create_family("����",39,"����");
        carry_object("/clone/weapon/blade")->wield();
        carry_object("/d/mingjiao/obj/black-cloth")->wear();
}

void attempt_apprentice(object ob)
{     
        command("say �Ǻǣ����书��΢���ɲ�����ͽ����");
        return;
}
