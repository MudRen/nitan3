inherit NPC;

void create()
{
        set_name("���ϰ�", ({ "wang laobang", "publisher", "wang"}));
        set("long", "����һλ�װ����ֵ������ˣ�����΢΢�������Ǹ����̺���ģ����\n"
                "����������һ��С���ӣ���Ц���е����´������㡣\n"
                "��˵�������Թ��ƾ٣������β��к������Է���Ϊҵ�ˡ�\n");
        set("gender", "����");
        set("age", 45);
        set("weight", 50000);
        set("str", 25);
        set("dex", 25);
        set("attitude", "peaceful");

        set("combat_exp", 75000);
        set("shen_type", 0);

        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("literate", 300);

        set("neili", 4000); 
        set("max_neili", 4000);
        set("jiali", 500);

        carry_object("/clone/cloth/cloth")->wear();

}

