// wangcheng.c

inherit NPC;

void create()
{
        set_name("����", ({ "wang cheng","wang"}) );
        set("gender", "����" );
        set("title", "������̷���������");
        set("age", 65);
        set("long", "������İ��֣�������Ц����ʵΪ��ʮ�ֺݶ���\n");
        set("attitude", "friendly");
        set("shen_type", -1);

        set("per", 21);
        set("str", 23);
        set("int", 23);
        set("con", 22);
        set("dex", 20);

        set("max_qi", 1000);
        set("max_jing",1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 150);
        set("combat_exp", 350000);
        set("score", 30000);

        set_skill("force", 100);
        set_skill("riyue-xinfa", 100);
        set_skill("dodge", 90);
        set_skill("piaomiao-shenfa", 90);
        set_skill("hand", 110);
        set_skill("huanmo-longtianwu", 110);
        set_skill("cuff", 110);
        set_skill("xuwu-piaomiao", 110);
        set_skill("parry", 90);
        set_skill("literate", 50);
        set_skill("sword", 100);
        set_skill("riyue-jian", 100);

        map_skill("sword", "riyue-jian");
        map_skill("force", "riyue-xinfa");
        map_skill("dodge", "piaomiao-shenfa");
        map_skill("hand", "huanmo-longtianwu");
        map_skill("cuff", "xuwu-piaomiao");
        map_skill("parry", "riyue-jian");

        prepare_skill("hand", "huanmo-longtianwu");
        prepare_skill("cuff", "xuwu-piaomiao");

        create_family("�������",2,"���� ����������");

        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/d/heimuya/npc/obj/cloth")->wear();
}

