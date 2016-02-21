// laonu.c ��ū

#include <ansi.h>

inherit "/inherit/char/punisher";

void create()
{
	set_name("��һ��", ({ "hu yidao", "hu" }));
	set("long",  "����һ���⺷����ı����󺺣�˫�۾�������\n");
	set("gender", "����");
	set("age", 58);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 38);
	set("int", 31);
	set("con", 32);
	set("dex", 36);
	
	set("max_qi", 60000);
	set("max_jing", 30000);
	set("neili", 75000);
	set("max_neili", 75000);
	set("jiali", 150);
	set("combat_exp", 25000000);
	set("score", 10000000);

        set_skill("force", 2100);            // �����ڹ�
        set_skill("lengyue-shengong", 2100); // ������
        set_skill("blade", 2400);            // ��������
        set_skill("hujia-daofa", 2400);      // ���ҵ���
        set_skill("dodge", 2400);            // ��������
        set_skill("taxue-wuhen", 2400);      // ̤ѩ�޺�
        set_skill("parry", 2200);            // �����м�
        set_skill("throwing", 2400);         // ��������
        set_skill("mantian-xing", 2400);     // ������
        set_skill("strike", 1800);           // �����Ʒ�
        set_skill("tianchang-zhang", 1800);  // �쳤�Ʒ�
        set_skill("cuff", 1800);             // ����ȭ��
        set_skill("hujia-quan", 1800);       // ����ȭ��

        map_skill("force", "lengyue-shengong");
        map_skill("blade", "hujia-daofa");
        map_skill("dodge", "taxue-wuhen");
        map_skill("parry", "hujia-daofa");
        map_skill("throwing", "mantian-xing");
        map_skill("strike", "tianchang-zhang");
        map_skill("cuff", "hujia-quan");

        prepare_skill("strike", "tianchang-zhang");
        prepare_skill("cuff",   "hujia-quan");

	create_family("�������", 0, "��ׯ��");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "blade.bafang" :),
		(: perform_action, "blade.po" :),
		(: perform_action, "cuff.kuai" :),
		(: exert_function, "recover" :),
	}));

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
