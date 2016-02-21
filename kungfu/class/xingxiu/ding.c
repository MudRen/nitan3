// ding.c ������

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

#include "xingxiu.h"
#include <ansi.h>

int ask_ding();
int ask_book();
int ask_poison();
int ask_staff();
int ask_job();
string ask_me();
string ask_du1();
string ask_du2();
string ask_xiangliao();
int do_answer(string arg);
void no_answer(object user);

#define ANTI_ROBOT "/kungfu/class/xingxiu/robot"
#define SUO "/clone/lonely/rousisuo"

void create()
{
        set_name("������", ({ "ding chunqiu", "ding" }));
        set("nickname", HIG "�����Ϲ�" NOR);
        set("long", @LONG
�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����
��������������ò���棬�ɷ���ǡ�
LONG );
        set("gender", "����");
        set("age", 60);
        set("attitude", "friendly");
        set("class", "scholar");
        set("shen_type", -1);
        set("str", 25);
        set("int", 30);
        set("con", 38);
        set("dex", 38);
        
        set("max_qi", 6400);
        set("max_jing", 2900);
        set("neili", 7300);
        set("max_neili", 7300);
        set("jiali", 120);
        set("level", 30);
        set("combat_exp", 3850000);

        set_skill("force", 460);
        set_skill("huagong-dafa", 460);
        set_skill("guixi-gong", 460);
        set_skill("throwing", 440);
        set_skill("feixing-shu", 440);
        set_skill("dodge", 440);
        set_skill("zhaixing-gong", 440);
        set_skill("strike", 460);
        set_skill("chousui-zhang", 460);
        set_skill("claw", 440);
        set_skill("sanyin-zhua", 440);
        set_skill("whip", 440);
        set_skill("chanhun-suo", 440);
        set_skill("parry", 440);
        set_skill("staff", 440);
        set_skill("poison", 400);
        set_skill("tianshan-zhang", 440);
        set_skill("literate", 400);
        set_skill("medical", 460);
        set_skill("xingxiu-qishu", 460);
        set_skill("martial-cognize", 280);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixing-gong");
        map_skill("strike", "chousui-zhang");
        map_skill("claw", "sanyin-zhua");
        map_skill("whip", "chanhun-suo");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");
        map_skill("poison", "xingxiu-qishu");
        map_skill("throwing", "feixing-shu");

        prepare_skill("strike", "chousui-zhang");
        prepare_skill("claw", "sanyin-zhua");

        set("book_count", 1);
        set("zhen_count", 1);
        set("san_count", 1);
        set("xiangliao_count", random(10) + 10);

        set("inquiry", ([
                "����" : (: ask_job :),
                "job" : (: ask_job :),        
                "������" : (: ask_staff :),
                "����"       : (: ask_me :),
                "���޶���"   : (: ask_me :),
                "������"     : (: ask_du1 :),
                "����"       : (: ask_xiangliao :),
                "��ң��Цɢ" : (: ask_du2 :),
                "��ľ����" : (: ask_ding : ),
                "���Ͼ綾" : (: ask_poison :),
                "�ⶾ" : (: ask_poison :),
                "book" : (: ask_book :),
                "�׽��ƪ" : (: ask_book :),                
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                //(: perform_action, "staff.fugu" :),
                //(: perform_action, "staff.xue" :),
                //(: perform_action, "strike.tao" :),
                (: perform_action, "strike.dan" :),
                (: perform_action, "strike.tao" :),
                (: perform_action, "strike.shi" :),
                (: perform_action, "claw.zhua" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        create_family("������", 1, "��ɽ��ʦ");
        set("class", "taoist");

        set_temp("apply/damage", 180);
        set_temp("apply/armor", 400);
        set_temp("apply/attack", 250);
        set_temp("apply/dodge", 250);
        set_temp("apply/parry", 250);

        set("master_ob", 5);
	setup();
        //carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        //set_temp("handing", carry_object("/clone/misc/duwan"));

}

void init()
{
        object me;
        object ob,ob1;
        string poison;

        ::init();
        
        me = this_player();

        if (! interactive(me))
                return;
                       
        add_action("do_answer", "answer", 1);
        
        if( interactive(ob=this_player()) && ob->query_condition("bingcan_posion") ) 
        {
		   command("? " + ob->query("id"));
		   command("say " + ob->query("name") + "��ͽ��,���ƺ����˱��Ͼ綾��\n");
        }
	
        if (interactive(ob=this_player()) && ob->query("family/master_id") == "ding chunqiu"
        && (!present("yu di", this_player()))){
                ob1=new("/d/xingxiu/obj/yudi");
                ob1->move(this_player());
                command("say ��ֻ������������޵��ӵĻ��������ú����ţ�����Ū����");
                write("���������һֻ��ѡ�\n");
        }

        if (living(this_object()) && present("shenmuwang ding", me))
        {
                command("say �üһԭ����͵���ҵ���ľ�����������ɣ�");
                kill_ob(me);
                return;
        }

        add_action("do_flatter", "flatter");
}

int ask_book()
{
	object ob;
       object me=this_player();

       if(me->query("canbook")==1 && (!present("yijinjing", me)) ) {
		tell_object(me,"������˵��������ͽ������û��͸�Ȿ�׽�İ���ô��\n");
		tell_object(me,"�Ǻðɡ��Ȿ�������㣬�û�ȥ�úò���ɣ�\n");
		tell_object(me,"ͽ����һ��Ҫ��ס��ǧ�������ľ����һ��������Ҫ��Ȼ�������߻���ħ����\n");
              ob=new("/clone/book/yjj_book2.c");

		ob->move(me);
		write("���������һ���׽��\n");
		return 1;
	}
	else
		return 0;
}

int ask_ding()
{	
	object ob;
	object me=this_player();
        if(me->query("ask/ding")==1 && (!present("shenmu wangding",me)) && me->query("family/master_id") == "ding chunqiu")
	{
		tell_object(me,"�ҿ���Ѱ���׽��������ľ�����ŵ���ʧ�����������Ȼ��Ҫ����ȥ�ɡ�\n");
        ob=new("/clone/misc/swmuding");
		ob->move(me);
              me->delete("ask/ding");
		return 1;
	}
	else return 0;
	
}

int ask_poison()
{
	object ob=this_player();
	if(ob->query("family/master_id" )=="ding chunqiu" && ob->query_condition("bingcan_poison")) 
	{
	tell_object(ob,HIY "Ҫ����Ͼ綾�����ְ취��������׽��ƪ��
	Ȼ�������ľ�������������󷨣���㶾�����ʲô��
	��ϧ�����Ǳ���ƪ������Ȼ���䲻������������ҵ���
	����Ļ����ҿ����Ժ��Ȼ���ֲ������󷨵�ȱ������
	��֮�⣬ֻ�ܿ�ҩ���ӹ��˽��ˣ�\n" NOR);
	return 1; }
	else
	return 0;
}	

int do_answer(string arg)
{
        int result;
        object me = this_object(), user = this_player();
        result = ANTI_ROBOT->do_answer(arg, user, me);

        if (result == 2) {
                command("whisper " + user->query("id") + " �ã��ã��ã��������ڷ����ˡ�");
                command("say " + user->name(1) + "������ʲô����ֻ�����Ұɣ�");
                user->set("passed_ding", 1);
                return 1;
        }

        if (result == -1) {
                command("hummer " + user->query("id"));
                command("say " + user->name(1) + "�������������Ȼ����ƭ���ɣ����ҹ�һ��ȥ��");
                user->add("ding_robot", 1);
                user->set("robot_ding", user->query("mud_age") + user->query("ding_robot")*600);
                return 1;
        }

        return result;
}

void no_answer(object user)
{
        if(objectp(present(user->query("id"), environment()))) {
        command("beep " + user->query("id"));
        command("heihei " + user->query("id"));
        command("say " + user->name(1) + "������Ϊ��װ���Ҿ��β���������");
        command("say ���ҹ�һ��ȥ�ɣ�");
        }
else {
        command("tell " + user->query("id") + " " + user->name(1) + "������Ϊ��װ���Ҿ��β���������");
        command("tell " + user->query("id") + "����ʱ�ò��Ÿ����������ˣ�");
}
        user->add("ding_robot", 1);
        user->set("robot_ding", user->query("mud_age") + user->query("ding_robot")*600);
}

void attempt_apprentice(object me)
{

        if ((int)me->query("shen") > -12000)
        {
                command("say ������Խ����Խ��׵������Ե׵ġ�");
                return;
        }

//        if ((int)me->query("combat_exp") < 300000)
        if (count_lt(me->query("combat_exp"), 300000))
        {
                command("say �����΢ĩ���������ѧ�����ɵ������");
                return;
        }

        if (me->query_skill("chousui-zhang", 1) < 120)
        {
                command("say ������ƶ�û��������Ȼ�����������ң�");
                return;
        }

        if ((int)me->query_skill("poison", 1) < 120)
        {
                command("say �㶾����ûѧ���ף������������ң�");
                return;
        }

        if( me->query_temp("pending/flatter"))
        {
                command("say ����˲������ɷ�����������������㣿");
                return;
        } else
        {
                command("say ���������ɱ������������ʥ����ô������");
                message_vision("�����Ϲ�΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        if (! this_player()->query_temp("pending/flatter"))
                return 0;

        if (! arg) return notify_fail("��˵����ʲô��\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N����˵����" + arg + "\n", this_player());
        if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�������") >=0
         || strsrch(arg, "�������") >=0 || strsrch(arg, "�Ž��ޱ�") >=0 )) {
                command("smile");
                command("say �⻹��ࡣ\n");
                welcome(this_player());
                command("recruit " + this_player()->query("id"));
        } else
        {
                command("say ����˲����ҷ���������������㣿");
        }
        return 1;
}

// �������ɣ�������أ��������Ž��ޱ�
string ask_me()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��\n";

        if (query("book_count") < 1)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���\n";

        add("book_count", -1);
        ob = new("/clone/book/dujing_2");
        ob->move(this_player());
        return "�ðɣ��Ȿ�����޶��������û�ȥ�ú����С�\n";
}

string ask_du1()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��\n";

        if (this_player()->query_skill("poison", 1) < 50)
                return "��Ķ������δ�����ò������ֶ�����\n";

        if (query("zhen_count") < 1)
                return "�������ˣ������붼�����ˡ�\n";

        add("zhen_count", -1);
        ob = new("/d/xingxiu/obj/bilinzhen");
        ob->move(this_player());
        return "�ðɣ������������Щ��ɡ�\n";
}

string ask_du2()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��\n";

        if (this_player()->query_skill("poison", 1)<100)
                return "��Ķ������δ�����ò������ֶ�����\n";

        if (query("san_count") < 1)
                return "�������ˣ�����ûʲôʣ���ˡ�\n";

        add("san_count", -1);
        ob = new("/d/xingxiu/obj/sanxiaosan");
        ob->move(this_player());
        return "�ðɣ������ҩ���û�ȥ�Ƽ����ðɡ�\n";
}

string ask_xiangliao()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��\n";

        if (is_busy() || is_fighting())
                return "�Ȼ����û��������æ����ô��\n";

        if (this_player()->query_temp("get_xiangliao"))
                return "�ղŲ��Ǹ������𣿲�����ô��������˰ɣ�\n";

        if (this_player()->query_skill("poison", 1) < 40)
                return "��Ķ������̫�����������˵�ɣ�\n";

        if (query("xiangliao_count") < 1)
                return "�������ˣ�����ûʲôʣ�µ������ˣ��㻹��ȥ�ֿ����ҿ��ɣ�\n";

        add("xiangliao_count", -1);
        ob = new("/clone/misc/xiangliao");
        ob->set_amount(random(50) + 100);
        ob->move(this_player());
        start_busy(2);
        this_player()->set_temp("get_xiangliao", 1);
        call_out("clear_xiangliao_flag", 180);
        return "�ðɣ���Щ��������ȥ�����ðɡ�\n";
}

void reset()
{
        set("book_count", 1);
        set("zhen_count", 1);
        set("san_count", 3);
        set("zhen_count", 7);
        set("wxs_count",3);        
        set("xiangliao_count", random(10) + 10);
}

/*
void unconcious()
{
        die();
}
*/

int accept_ask(object me, string topic)
{
        switch(topic)
        {
             case "����" :
             case "����" :
             case "����" :
                 return QUEST_D->accept_ask(this_object(), me, topic);

             case "�����":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/chanhun-suo/duo",
                                 "name"     :  "�����",
                                 "sk1"      :  "chanhun-suo",
                                 "lv1"      :  100,
                                 "sk2"      :  "force",
                                 "lv2"      :  130,
                                 "shen"     :  -10000,
                                 "family/gongji" :  80,
                                 "force"    :  80 ]));
                  break;

             case "���ĵ�":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/chousui-zhang/dan",
                                 "name"     :  "���ĵ�",
                                 "sk1"      :  "chousui-zhang",
                                 "lv1"      :  140,
                                 "sk2"      :  "force",
                                 "lv2"      :  140,
                                 "sk3"      :  "poison",
                                 "lv3"      :  140,
                                 "sk4"      :  "throwing",
                                 "lv4"      :  140,
                                 "shen"     :  -22000,
                                 "neili"    :  1800,
                                 "family/gongji" :  950 ]));
                  break;

             case "��������":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/chousui-zhang/tao",
                                 "name"     :  "��������",
                                 "sk1"      :  "chousui-zhang",
                                 "lv1"      :  220,
                                 "sk2"      :  "poison",
                                 "lv2"      :  250,
                                 "sk3"      :  "huagong-dafa",
                                 "lv3"      :  220,
                                 "shen"     :  -38000,
                                 "neili"    :  3000,
                                 "family/gongji" :  1200 ]));
                  break;

             case "�������":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/chousui-zhang/huoyan",
                                 "name"     :  "�������",
                                 "sk1"      :  "chousui-zhang",
                                 "lv1"      :  140,
                                 "sk2"      :  "force",
                                 "lv2"      :  140,
                                 "sk3"      :  "poison",
                                 "lv3"      :  140,
                                 "sk4"      :  "throwing",
                                 "lv4"      :  140,
                                 "shen"     :  -22000,
                                 "neili"    :  1800,
                                 "family/gongji" :  950 ]));
                  break;

             case "�������":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/chousui-zhang/huoqiu",
                                 "name"     :  "�������",
                                 "sk1"      :  "chousui-zhang",
                                 "lv1"      :  140,
                                 "sk2"      :  "force",
                                 "lv2"      :  140,
                                 "sk3"      :  "poison",
                                 "lv3"      :  140,
                                 "sk4"      :  "throwing",
                                 "lv4"      :  140,
                                 "shen"     :  -22000,
                                 "neili"    :  1800,
                                 "family/gongji" :  950 ]));
                  break;

             case "�������":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/chousui-zhang/biyan",
                                 "name"     :  "�������",
                                 "sk1"      :  "chousui-zhang",
                                 "lv1"      :  140,
                                 "sk2"      :  "force",
                                 "lv2"      :  140,
                                 "sk3"      :  "poison",
                                 "lv3"      :  140,
                                 "sk4"      :  "throwing",
                                 "lv4"      :  140,
                                 "shen"     :  -22000,
                                 "neili"    :  1800,
                                 "family/gongji" :  1000 ]));
                  break;

             case "�������":
                 return MASTER_D->teach_pfm(me, this_object(),
                               (["perform"  :  "can_perform/chousui-zhang/huolang",
                                 "name"     :  "�������",
                                 "sk1"      :  "chousui-zhang",
                                 "lv1"      :  200,
                                 "sk2"      :  "force",
                                 "lv2"      :  200,
                                 "sk3"      :  "poison",
                                 "lv3"      :  200,
                                 "sk4"      :  "throwing",
                                 "lv4"      :  200,
                                 "shen"     :  -50000,
                                 "neili"    :  1800,
                                 "family/gongji" :  2000 ]));
                  break;                                                      
 
             case "��˿��" :
                return MASTER_D->give_item(me, this_object(),
                               (["item"     :  SUO,
                                 "master"   :  1,
                                 "sk1"      :  "chanhun-suo",
                                 "lv1"      :  140,
                                 "shen"     :  -30000 ]));
                  break;
                             
             default : 
                  return 0;
                           
        }
}

void clear_xiangliao_flag()
{
        if (this_player()->query_temp("get_xiangliao"))
               this_player()->delete_temp("get_xiangliao");
      
        return;
}

int ask_staff()
{
	object me=this_player();
	object waguan;
	mapping fam;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] !="������"){
		command("?");
		return 1;
	}
		
	if (me->query("tianshan")==1){
		command("say ��Ҫ���������ĵ���Ц��");
		return 1;
	}
	
	if (me->query_skill("pixie-jian",1)>=10){
		command("hmm");
		command("say ������ʧ�������������˹���");
		return 1;	
	}
			
        if (me->query_skill("staff", 1) < 200){
		command("say ������ȷ�����Ϊ������");
	}
	
	if (me->query_str() < 50) {
		command("say �������̫���ˣ��úö��������������Ұɡ�");
		return 1;
	}
	
	if (me->query_con() < 50) {
		command("say ����ڹ���Ϊ̫���ˣ��úö��������������Ұɡ�");
		return 1;
	}
		
	if (me->query_int() < 35) {
		command("sneer");
		command("say ������ѧ��������������̫���ȥ�úö�һ����ɡ�");
		return 1;
	}
		
	
                message_vision(HIG"$N΢΢һЦ����$n����һ�ԣ������ؽ�����ɽ��������һ�С�\n", this_object(), this_player());
                message_vision(HIG"$n��$N�Ľ����£�����ɽ�ȷ�������һ���µ���⡣", this_object(), this_player());
                me->set("tianshan", 1);
                tell_object(this_object(),HIC"�����ɽ�ȷ������ˣ�");
        	me->add_skill("tianshan-zhang", 10);
                return 1;
        
        
	return 1;
}

int ask_job(){
	
	object me=this_player();
	object waguan;
	mapping fam;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] !="������"){
		command("?");
		return 0;
	}
		
        if (me->query("robot_ding") > me->query("mud_age")) {
                command("say �ߣ��ϴ���ƭ���ɵ��£����ɻ�û�к��������أ������ڻ������������ǣ�");
                command("say ���ȸ��һ�ȥ�ú÷�ʡ�Լ�һ�£��Ժ�������");
                return 1;
        }

        if(me->query("robot_answer")) return notify_fail("����Ϸ����ǰ��������ˣ�\n");

        if (random(4) == 1 && !me->query("passed_ding")) {
                command("say ��ҹ�Ϸ������˸�䣬˵��" + me->name(1) + "���²���ʵ����д��������ƭ�Ϸ�");
                command("say �����Ϸ�����Ҫ����һ�ʣ��������ˣ�");
                ANTI_ROBOT->get_question(me, this_object());
                return 1;
        }

        if(me->query_temp("xx_job")==1) {
                command("say ��С�ӣ���һ������û����ɾ͸������ҹ�����");
                return 1;
        }
        command ("say �����������������ҪһЩ�������㵽��ɽ��Щ�����Ұɡ���");
	waguan=new("/d/xingxiu/obj/waguan");
        me->set_temp("xx_job",1);
	if (!present("wa guan", me)) waguan->move(me);
	    message_vision("������˳�ִ���������ȡ��һ��С�߹��Ӹ��㡣\n", me);
		command ("say ����ȥ��أ�·��С�ġ���");
	return 1;

}

int accept_object(object who, object ob){

	object me=this_player();
	mapping fam;
        int pot, exp;
        string msg;

	if (!(fam = this_player()->query("family")) || fam["family_name"] !="������"){
		command("?");
		return 0;
	}		

	if(ob->query("id")=="du dan"){

              if (this_player()->query_temp("xx_job")!=1 || ob->query("player")!=me->query("id")) {
			command("hehe");
			return 0;
		} else {
                     command("pat "+this_player()->query("id"));        
			command("say �����ģ�������Խ����Խ˳���ˡ�\n");
			// exp triple
			pot = random(100)+100;
			exp = 200 + random( 50 );

//          if(me->query("combat_exp") > 6400000)
          if(count_gt(me->query("combat_exp"), 6400000))
          {
            pot /= 2;
            exp = exp / 2;
          }
			me->add("combat_exp", exp);
			me->add("potential", pot);
			if(me->query("potential")>me->query_potential_limit())
				me->set("potential",me->query_potential_limit());
                        msg = sprintf("��ץ��õ� %d �㾭��� %d ��Ǳ�ܡ�\n", exp, pot);
                        tell_object(me,msg);
			me->delete_temp("xx_job");
			me->delete_temp("found");
			me->delete_temp("bug_hold");
			me->delete_temp("bug_out");
                        me->delete("passed_ding");
                        call_out("destob",2,ob);
			return 1;
		}
	}
	if(ob->query("id")=="a zi"){

                        command("say ̫���ˣ������а������ͽץ�����ˣ�\n");
                        command("say �����ģ��������ͽ�����ȹص��η�����ȥ��\n");
                        tell_object(me,"��������������޵��ӰѰ����ϳ�ȥ�ˡ�\n");
			pot = random(300)+80;
			exp = 500 + random( 20 );
			me->add("combat_exp", exp);
			me->add("potential", pot);
			if(me->query("potential")>me->query_potential_limit())
				me->set("potential",me->query_potential_limit());
			me->set("ask/ding", 1);
                        destruct(ob); 
			return 1;
	}
	if(ob->query("id")=="noname book")
	{
        if (!ob->query("my_owner") || ob->query("my_owner") != me)
                return notify_fail("������ŭ��������������������ƶ������������ˣ�\n");
                // if(me->query("ask/ding")==1)
                if(me)
		{
			tell_object(me,"�⡭�������׽��ƪ������
ͽ������������һͳ�������������ˣ������Ȼ����ȡ�ã��պ��㵱ȻҲ��
����ϰ����Ϊʦ�����������¼����������ʦͽ��ͬ�о���\n");
			me->set("canbook",1);
			return 1;
		}
		else
		return notify_fail("������ŭ�������������Ǻε���ݣ����������������������Ҳ�Ҫ����\n");
	}
			
	if(ob->query("id")=="ling pai"){
		if(ob->query("player")!=me->query("id")){
			command("hehe");
			return 0;
		} else {
			command("hehehe");
			command("say �����ģ�����Щ�Գ��������ɵ�֪�����ɵ�������\n");
			if (ob->query("menpai")=="huashan" || ob->query("menpai")=="quanzhen")
				exp = 100 + random( 50 );
			else  if(ob->query("menpai")=="mingjiao") {
				command("say �š������̾�ȻҲ���Ҹ����ˡ�\n");
				//exp triple
				exp = 120 + random( 60 );
			} else	exp = 70+random(30);
//          if(me->query("combat_exp") > 6400000)
          if(count_gt(me->query("combat_exp"), 6400000))
          {
            exp = exp / 2;
          }
			me->add("combat_exp", exp);
                        msg = sprintf("������Ƶõ� %d �㾭�顣\n", exp);
                        tell_object(me,msg);
			call_out("destob",1,ob);
                        me->delete("passed_ding");
			return 1;					
		}
	}
	
	return ::accept_object(who, ob);
}	

void destob(object ob){
	destruct(ob);
}
