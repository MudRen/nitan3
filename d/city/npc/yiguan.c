// yiguan.c ���

inherit NPC;

void create()
{
    set_name("���", ({ "yi guan", "yi", "guan" }));
        set("gender", "����");
    set("age", 42);
        set("long", "��Ϊ������ŵش��½Ӵ���������̫���ڽ��ţ����Ե�Ҫ��ʵ����Щ��\n");

    set("combat_exp", 8000);
        set("shen", 0);

        set_skill("unarmed", 30);
        set_skill("dodge", 40);
        set_skill("parry", 40);

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 10);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
