// zhong.c

#include <ansi.h>

inherit "/inherit/char/punisher";

void create()
{
	set_name("��־��", ({ "pang toutuo", "pang" ,"toutuo"}));
	set("title", HIY "������" NOR "�󻤷�");
	set("nickname",HIR "�ɶ�������" NOR);
	set("long", "��ͷ�������ߣ������ݵó��棻����Ƥ����ͷ��˫\n"
                    "Ŀ���ݣ�������罩ʬһ�㡣\n" );
	set("gender", "����");
	set("age", 44);

	set("str", 32);
        set("int", 28);
        set("con", 31);
	set("dex", 25);

	set("max_qi", 47000);
        set("qi", 47000);
	set("max_jing", 24000);
        set("jing", 24000);
	set("neili", 58000); 
	set("max_neili", 58000);
	set("jiali", 120);
	set("score", 10000000);

	set("combat_exp", 50000000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 2000);
	set_skill("hand", 2000);
	set_skill("strike", 2000);
	set_skill("staff", 2000);
	set_skill("parry", 2000);
	set_skill("dodge", 2000);
	set_skill("yixing-bufa", 2000);
	set_skill("shenlong-bashi", 2000);
	set_skill("huagu-mianzhang", 2000);
	set_skill("shenlong-xinfa", 2000);
	set_skill("shedao-qigong", 2000);

	map_skill("staff", "shedao-qigong");
	map_skill("force", "shenlong-xinfa");
	map_skill("hand", "shenlong-bashi");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "shedao-qigong");
	map_skill("dodge", "yixing-bufa");
	prepare_skill("hand", "shenlong-bashi");
	prepare_skill("strike", "huagu-mianzhang");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.xian" :),
                (: perform_action, "strike.hua" :),
                (: perform_action, "staff.fei" :),
                (: exert_function, "recover" :),
        }));

	create_family("������", 0, "����ʹ");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangzhang")->wield();
}
