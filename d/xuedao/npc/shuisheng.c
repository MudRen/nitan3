// shuidai.c

inherit NPC;
#include <ansi.h>;
void create()
{
       set_name("ˮ��", ({ "shui sheng", "shui" }));
       set("long", 
     "�����������桰�仨��ˮ���е�����ˮ᷵�Ů�������ĺ�����������\n");
       set("gender", "Ů��");
       set("age", 21);
       set("attitude", "peaceful");
       set("shen_type", 0);
       set("str", 35);
       set("int", 38);
       set("con", 35);
       set("dex", 35);

       set("max_qi", 2000);
       set("max_jing", 500);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 30);
       set("combat_exp", 800000);
       set("shen_type", 1);

       set_skill("force", 100);
       set_skill("huashan-neigong", 100);
       set_skill("dodge", 100);
       set_skill("huashan-shenfa", 100);
       set_skill("strike", 100);
       set_skill("huashan-zhangfa", 100);
       set_skill("parry", 100);
       set_skill("sword", 100);
       set_skill("huashan-jianfa", 100);
       set_skill("literate", 80);

       map_skill("force", "huashan-neigong");
       map_skill("dodge", "huashan-shenfa");
       map_skill("strike", "huashan-zhangfa");
       map_skill("parry", "huashan-jianfa");
       map_skill("sword", "huashan-jianfa");

       setup();
       carry_object("/clone/weapon/changjian")->wield();
}


