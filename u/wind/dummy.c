// liumang.c ��å

inherit NPC;

void create()
{
        set_name("���Դ���", ({ "dummy", "mi" }));
	set("gender", "����");
	set("age", 19);
        set("long", "����һ��������ʦ�ǲ����书�õĴ��ס�\n ������ľ�����ģ��������ף��������á�\n");
	
	set("combat_exp", 1000);
	set("shen_type", -1);
        set("max_qi", 5000000);
        set("eff_qi", 5000000);
        set("qi", 5000000);
        set("max_jing", 5000000);
        set("jing", 5000000);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",2);
}
 void die(object killer) 
     { 
             object ob; 
             object ob1; 
             ob1=new("/kungfu/class/xingxiu/xiaofeng");
             ob1->move(environment()); 
             ::die(killer); 
     } 
