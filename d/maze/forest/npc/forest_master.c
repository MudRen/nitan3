inherit NPC;
#include <ansi.h>

void give_reward_forest(object ob, int ref_exp);

mapping itemlist = ([      
        "/d/maze/forest/npc/obj/bear_dan":1,
        "/d/maze/forest/npc/obj/bear_hand":5,
        "/d/maze/forest/npc/obj/bear_skin":10,
        "/d/maze/forest/npc/obj/snake_egg":1,
        "/d/maze/forest/npc/obj/snake_dan":5,
        "/d/maze/forest/npc/obj/snake_skin":10,
        "/d/maze/forest/npc/obj/tiger_xxx":1,
        "/d/maze/forest/npc/obj/tiger_bone":5,
        "/d/maze/forest/npc/obj/tiger_skin":10,
        "/d/maze/forest/npc/obj/wolf_eye":1,
        "/d/maze/forest/npc/obj/wolf_meat":5,
        "/d/maze/forest/npc/obj/wolf_skin":10,
        "/d/maze/forest/npc/obj/dragon_skin":3,
        "/d/maze/forest/npc/rabbit":1,
        "/d/maze/forest/npc/toad":1,
]);

void create()
{
        set_name(HIG "����������" NOR, ({ "forest hunter","hunter" }) );

        set("gender", "����");
        set("age", 30);
        set("long",
                GRN"\n    ����һ�������չ��ߣ�����һ�������������ȡ��Ľ�����
                \n      ʮ����Ƥ  �������  һ������
                \n      ʮ����Ƥ  ��ֻ����  һֻ�ܵ�	
                \n      ʮ�Ż�Ƥ  ��߻���  һ������
                \n      ʮ����Ƥ  ����ߵ�  һ���ߵ�
                \n      ��������  һ������
                \n      һֻ��å��
                \n"NOR);
        set("attitude", "peaceful");
        set("str", 26000);
        set("com", 30);
        set("int", 24);
        set("dex", 30);
        set("per", 50);



        set("chat_chance", 10);
        set("chat_msg", ({
                BLU"����������˵�����չ��������\n"NOR ,
	        YEL"����������˵�������������߶��˵ĺ��Ӱ�......\n"NOR ,

        }) );

        set("combat_exp", 12000000);
        set("attitude", "peaceful");

        set_skill("unarmed", 300);
        set_skill("dodge", 300);

        set("max_qi", 4500);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);

        setup();

}

int accept_object(object me, object obj)
{
	string filename;
	int need_amount,amount,exp;
	filename = base_name(obj);
	
	if (undefinedp(itemlist[filename]))
        {
	        command("shake");
                command("say ����ʲô�������Ҳ���Ҫ��");
                return 0;
        }
        
        need_amount = itemlist[filename];
	if (need_amount<=0 )
		return 0;
	if (function_exists("query_amount",obj) && obj->query_amount()<need_amount )
		return 0;

	exp = 5000;

	if (function_exists("query_amount",obj))
		amount = obj->query_amount();
	else 
		amount = 1;

	exp = exp/need_amount*amount;

        command("pat "+me->query("id"));
	give_reward_forest(me,exp);
        destruct(obj);
	return 1;
}

void give_reward_forest(object ob, int ref_exp) 
{
	//ref_exp�ǲο����飬exp��Ӱ��gold���߼���ҿ��Ե�forest��Ǯ
        mixed user_exp;
        int exp,pot,tih,score,gold;
	string reward_msg;
        // gold = ref_exp/500;
	user_exp = ob->query("combat_exp");
	if (count_lt(user_exp,10000000))
		exp = ref_exp*5/4;
	else if (count_lt(user_exp,20000000))
		exp = ref_exp;
	else if (count_lt(user_exp,50000000))
		exp = ref_exp/2;
        else if (count_lt(user_exp,100000000))
		exp = ref_exp/10;
	else
		exp = 0;;

	pot = exp/2;
        score = exp/50;
        tih = exp/30;
        gold = ref_exp/500;
	reward_msg =GRN"��õ��˱��꣺\n\t\t" +
	chinese_number(exp) + "��ʵս����\n\t\t"+
	chinese_number(pot) + "��Ǳ��\n\t\t" +
        chinese_number(tih) + "�����\n\t\t" +
	chinese_number(score) + "������\n\t\t" + 
	chinese_number(gold) + "���ƽ�\n"NOR;
	tell_object(ob,reward_msg);
	ob->add("combat_exp",exp);
	ob->add("potential",pot);
        ob->add("experience",tih); 
	ob->add("score",score);
	ob->add("balance",gold*10000);
}
