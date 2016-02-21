#include <ansi.h> 
inherit "/d/maze/necropolis/necropolis_npc";

void create()
{
        set_name("����", ({ "xing wu","xing"}) );
        set("gender", "����" );

        set("str", 50);
        set("con", 120);
        set("dex", 22); 
        set("int", 50);
        set("class","shaolin");     
        set("long",
        ""
        );
        //set("force_factor", 150);
        set("auto_perform", 2); 
        set("max_qi", 8000000);
	set("eff_qi", 480000);        
        set("max_jing", 8500000);
        set("eff_jing",850000);
        set("neili", 8000000);
        set("max_neili", 4500000);
        set("max_jingli", 500000);
        set("combat_exp", 300000000);

	set_skill("buddhism", 1200);
	set_skill("literate", 1200);
	set_skill("sanscrit", 1200);
	set_skill("martial-cognize", 500); 

	set_skill("blade", 1200);
	set_skill("claw", 1200);
	set_skill("club", 1200);
	set_skill("cuff", 1200);
	set_skill("dodge", 1200);
	set_skill("finger", 1200);
	set_skill("force", 1200);
	set_skill("hand", 1200);
	set_skill("parry", 1200);
	set_skill("staff", 1200);
	set_skill("strike", 1200);
	set_skill("sword", 1200);
	set_skill("whip", 1200);
        set_skill("unarmed", 1200);
	set_skill("medical", 1200);
	set_skill("shaolin-yishu", 1200);

	set_skill("banruo-zhang", 1200);
	set_skill("shenzhang-bada", 1200);
	set_skill("xumishan-zhang", 1200);
	set_skill("cibei-dao", 1200);
	set_skill("damo-jian", 1200);
	set_skill("fengyun-shou", 1200);
	set_skill("fumo-jian", 1200);
	set_skill("hunyuan-yiqi", 1200);
	set_skill("shaolin-xinfa", 1200);
	set_skill("jingang-quan", 1200);
	set_skill("longzhua-gong", 1200);
	set_skill("luohan-quan", 1200);
	set_skill("nianhua-zhi", 1200);
	set_skill("xiuluo-zhi", 1200);
        set_skill("yipai-liangsan", 1200);
	set_skill("duoluoye-zhi", 1200);
	set_skill("jingang-zhi", 1200);
	set_skill("wuxiang-zhi", 1200);
	set_skill("pudu-zhang", 1200);
	set_skill("qianye-shou", 1200);
	set_skill("sanhua-zhang", 1200);
	set_skill("riyue-bian", 1200);
	set_skill("shaolin-shenfa", 1200);
	set_skill("weituo-gun", 1200);
	set_skill("wuchang-zhang", 1200);
	set_skill("xiuluo-dao", 1200);
	set_skill("yingzhua-gong", 1200);
	set_skill("yijinjing", 1200);
	set_skill("yizhi-chan", 1200);
	set_skill("zui-gun", 1200);
        set_skill("zui-quan", 1200);

	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");
	map_skill("whip", "riyue-bian");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
        set_temp("apply/attack", 3000);
        set_temp("apply/defense", 3000);
        set_temp("apply/damage", 1500);
        set_temp("apply/unarmed_damage", 1500);

        setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
        carry_object("/clone/weapon/sword")->wield();
        carry_object(__DIR__"obj/spirit_tower");
}  


int is_undead() {
	return 0;
}
