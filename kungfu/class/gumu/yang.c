// yang.c ���

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#include <ansi.h>
#include "gumu.h"

string ask_yunv();
int not_to_learn_ss(object ob);
mixed teach_sad();
string ask_sword();
int ask_youju();
mixed ask_me();

void create()
{
        set_name("���", ({"yang guo", "yang"}));
        set("gender", "����");
        set("age", 26);
        set("long", @LONG
������ȥüĿ֮����һ������֮����Ȼ������ԼԼȴ���˸е�һ����֮�飬
����յ����ģ���Ȼ���ǲм���
LONG );
        set("attitude", "friendly");

        set("str", 35);
        set("int", 36);
        set("con", 34);
        set("dex", 32);

        set("qi", 7800);
        set("max_qi", 7800);
        set("jing", 6900);
        set("max_jing", 6900);
        set("neili", 8500);
        set("max_neili", 8500);
        set("jiali", 120);
        set("no_get", 1);

        set("combat_exp", 5750000);

        set("couple/id", "xiao longnv");
        set("couple/name", "С��Ů");

        set_skill("force", 490);
        set_skill("yunv-xinfa", 490);
        set_skill("surge-force", 490);
        set_skill("sword", 480);
        set_skill("yunv-jian", 480);
        set_skill("quanzhen-jian", 480);
        set_skill("xuantie-jian", 480);
        set_skill("dodge", 450);
        set_skill("yunv-shenfa", 450);
        set_skill("parry", 485);
        set_skill("unarmed", 485);
        set_skill("meinv-quan", 470);
        set_skill("strike", 480);
        set_skill("sad-strike", 480);
        set_skill("fireice-strike", 480);
        set_skill("tianluo-diwang", 460);
        set_skill("literate", 350);
        set_skill("taoism", 400);
        set_skill("medical", 480);
        set_skill("array", 480);
        set_skill("yunv-xinjing", 480);
        set_skill("throwing", 440);
        set_skill("yufeng-zhen", 440);
        set_skill("hebi-jianzhen", 440);
        set_skill("martial-cognize", 400);

        map_skill("force", "surge-force");
        map_skill("sword", "xuantie-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "sad-strike");
        map_skill("strike", "tianluo-diwang");

        prepare_skill("unarmed", "sad-strike");

        create_family("��Ĺ��", 3, "����");

        set("inquiry", ([
                "������" : "��...�٣�",
	        "����"   : "�������������Ĵ�����",
		"����"   : "��ʦ��ô...�治��˵����",
		"С��Ů" : "����������Ӹ�ʲô��",
		"�"   : "���ˣ�������Ҳ�ա�",
                "�����" : "����ͷ��û�У��ܾ�û�������ˡ�",
                "��Ȼ������" : (: teach_sad :),
                "��������"   : "���Ƕ���ǰ��������ѧ���������ҵ���ϰ�ã�\n",
                "������" :   (: ask_sword :),
                "��������" : (: ask_sword :),
                "��Ĺ�ľ�" : (: ask_youju :),    
        ]));
        
        set("guarder", ([
                "refuse_home" : "$N��$n�����������",
                "refuse_other": "$N��$n���������ǹ�Ĺ���������ĵط�������Ҫ���ţ�",
                "refuse_carry": "$N��$n�ȵ����������ϵ��˸������£�",
        ]));

        set("no_teach/sad_strike", (: not_to_learn_ss :));        

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
	        (: perform_action, "strike.wang" :),
	        (: perform_action, "unarmed.xiao" :),
	        (: perform_action, "unarmed.tuo" :),
	        (: exert_function, "recover" :),
	        (: exert_function, "powerup" :),
        }));

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

	set("master_ob",5);
	setup();

        carry_object("/clone/cloth/qingyi")->wear();
}

void init()
{
        ::init();
        add_action("do_yuanyi", "yuanyi");
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") == query("family/family_name"))
        {
                if (query_skill(skill, 1) < 1 ||
                    SKILL_D(skill)->type() != "martial")
                        return 0;

                if (ob->query("int") < 24)
                {
                        command("say ���������ʲ��ѣ��ҽ�����̫�ۡ�");
                        return -1;
                }

                return 1;
        }
        
        if (skill == "unarmed" &&
            this_player()->query_skill("sad-strike", 1) > 0 &&
            this_player()->query_skill(skill, 1) < 200)
                return 1;

        if (skill != "sad-strike")
        {
                command("say �㻹�������ʦ��ȥѧϰ�ɣ�");
                return 0;
        }

        if (not_to_learn_ss(ob))
                return -1;

        if (this_player()->query_skill(skill, 1) > 400)
                return 0;

        return 1;
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query_int() < 32)
        {
                command("say ������ʲ�������������ϳ��书��");
                return;
        }

        if ((int)ob->query_skill("force") < 150)
        {
                command("say �����Ϊʦô������ڹ������������ɣ�");
                return;
        }

        if ((int)ob->query("max_neili") < 1000)
        {
                command("say �������������������Ҳ���ٰ���");
                return;
        }

        command("say �ðɣ�����Ҳ���������ˣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}

string ask_sword()
{
        object ob = this_player();
        mapping fam = ob->query("family");
        if (! fam || fam["family_name"] != "��Ĺ��")
                return RANK_D->query_respect(ob) + "���ҹ�Ĺ���ˣ���֪���˻�������";
        if (fam["generation"] > 4)
                return RANK_D->query_respect(ob) + "����������´��ˣ����ǵ��Ժ���˵�ɡ�";
        if (ob->query("ygpass"))
                return "�Ҳ����Ѿ���������������������֮����ô��";
        if (ob->query("gender")== "����")
        {
                command("pat "+ ob->query("id"));
                command("say ���������������ϣ����������������ڶ��´���Ĺǰ��������������");
                ob->set("ygpass", 1);
                return "������Ϣ���������У����ص��������ں�ˮ�������ľ��ϣ���ú�ȥ����һ�°ɡ�";
        }
        if (ob->query("gender") == "Ů��"){
        if ((int)ob->query_str() < 35)
                return "��λ" + RANK_D->query_respect(ob) + "������������Ҫ���ߵ��������㻹����Ŭ��һ���ɡ�";
        if ((int)ob->query_dex() < 35)
                return "��λ" + RANK_D->query_respect(ob) + "���ں�ˮ����ϰ����������Ҫ���ߵ������㻹����Ŭ��һ���ɡ�";
        if ((int)ob->query_skill("sword", 1) < 200)
                return "��λ" + RANK_D->query_respect(ob) + "�Ļ���������������������������Եֵ���ˮ�ĳ����";
        if ((int)ob->query_int() < 35)
                return "��λ" + RANK_D->query_respect(ob) + "�����Ի������ߣ������������Ҫ���Ŀھ���";
          	command("pat "+ ob->query("id"));
          	command("say ���������������ϣ����������������ڶ��´���Ĺǰ��������������");
          	ob->set("ygpass", 1);
          	return "������Ϣ���������У����ص��������ں�ˮ�������ľ��ϣ���ú�ȥ����һ�°ɡ�";
        }
}

int ask_youju()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "��Ĺ��") {
                command("say ���ǡ���Ůȭ�������һ�е���ʽ���������Դ��ġ�");
                return 1;
        }
	if (ob->query("family/master_name") == "��Ī��") {
                command("say ���ǡ���Ůȭ�������һ�е���ʽ���������Դ��ġ�");
                command("say ������ʦ����Ī��ĵ��ӣ��ұ�����ָ�����㡣");
                command("say ��Ȼһ�������������Ը������Ϊ��ȥ�����ϵ�а����ָ�������С���Ĺ�ľӡ�����Ը��(yuanyi)��");
        	ob->set_temp("mark/youju", 1);
		return 1;
		}     
        if (ob->query("can_perform/meinv-quan/you") > 0 ) {
                command("say �㲻���Ѿ�ѧ������");
                return 1;
        }
        if ((int)ob->query_skill("unarmed", 1) < 120) {
                command("say Ҫʹ�������ľ�����Ҫ�����ȭ�����㻹�Ƕ���ϰ��ϰ����Ůȭ������˵�ɡ�");
                return 1;
        }
	command("say ���ǡ���Ůȭ�������һ�е���ʽ���������Դ��ġ�");
	command("say �ã���Ȼһ�����������ҿ�ν��Ե������ָ�������С���Ĺ�ľӡ���");
	message_vision( "$N��ϸ��$n�����ˡ���Ĺ�ľӡ��ľ�Ҫ���ڡ�\n",this_object(), ob );
        ob->set("can_perform/meinv-quan/you", 1);
        return 1;
}
int do_yuanyi()
{
        object me = this_player();

        if (! me->query_temp("mark/youju"))
                return 0;
      
	message_vision("$n������$N���ϼ������Ŵ�Ѩ�������¡�\n", me, this_object() );
        write("��е�ͷ����һ��̩ͨ��\n");
        me->set("shen", 0);
	command("say �ã����ӿɽ̣��Ҿ�ָ�������С���Ĺ�ľӡ���");
	message_vision( "$N��ϸ��$n�����ˡ���Ĺ�ľӡ��ľ�Ҫ���ڡ�\n",this_object(), me );
        me->delete_temp("mark/youju", 1);
        me->set("can_perform/meinv-quan/you", 1);
        return 1;
}

mixed teach_sad()
{
        object ob = this_player();

        if (ob->query_skill("sad-strike", 1) >= 1)
        {
                command("say �㲻���Ѿ�������");
                return 1;
        }

        if (ob->query("gender") != "����")
        {
                command("say �������书ֻ�ʺ������������㻹�����˰ɣ�");
                return 1;
        }

        if (ob->query("static/sadly") < 3)
        {
                command("say ����᲻������˼�����ӵ��黳��"
                        "�޷�����ҵ���Ȼ�����ƣ�");
                return 1;
        }

        if (ob->query("character") == "���ռ�թ" || 
            ob->query("character") == "�ĺ�����")
        {
                command("say ��һ������ȥ���ˣ��޷�������Ȼ����ľ��磡");
                return 1;
        }

        if (ob->query("int") < 24)
        {
                command("say ���������Բ��㣬�޷�������Ȼ�����ơ�");
                return 1;
        }

        if (ob->query("str") < 28)
        {
                command("say ������������㣬�޷�������Ȼ�����ơ�");
                return 1;
        }

        if ((int)ob->query("max_neili") < 3000)
        {
                command("say ���������Ϊ���㣬�޷�����Ȼ�����ơ�");
                return 1;
        }

        if (ob->query_skill("force") < 320)
        {
                command("say ���ڹ���Ϊ���㣬�޷�������Ȼ�����ơ�");
                return 1;
        }                

        if ((int)ob->query_skill("unarmed", 1) < 200)
        {
                command("say ��Ļ���ȭ�Ų�����죬�޷�����Ȼ�����ơ�");
                return 1;

        }

        if (ob->query_skill("martial-cognize", 1) < 200)
        {
                command("say ����ѧ�������㣬�޷���������Ȼ�����ơ�");

                return 1;
        }

        message_vision(HIW "$n" HIW "���˿�$N" HIW "�������ã�����Ҳ��������"
                       "ԨԴ���Ҿʹ�����Ȼ�����ƣ�\n" NOR, ob, this_object());

        ob->set_skill("sad-strike", 10);

        tell_object(ob, HIG "��ѧ���ˡ���Ȼ�����ơ���\n" NOR);
 
        command("tan");
        command("say ��ȥ��ϰ�ɣ��ǵ�Ҫ�úöԴ�������ӣ�");

        return 1;
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����" :
        case "����" :
        case "����" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;

        case "���־�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuantie-jian/juan",
                           "free"    : 1,
                           "name"    : "���־�",
                           "sk1"     : "xuantie-jian",
                           "lv1"     : 100,
                           "neili"   : 3000,
                           "force"   : 400,
                        ]));
                break;

        case "�󽭶�ȥ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuantie-jian/dong",
                           "free"    : 1,
                           "name"    : "�󽭶�ȥ",
                           "sk1"     : "xuantie-jian",
                           "lv1"     : 200,
                           "neili"   : 5000,
                           "force"   : 400,
                         ]));
                break;

        case "����Ⱥħ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuantie-jian/dang",
                           "name"    : "����Ⱥħ",
                           "sk1"     : "xuantie-jian",
                           "lv1"     : 70,
                           "sk2"     : "force",
                           "lv2"     : 90,
                           "gongxian": 600, ]));
                break;

        case "������ӿ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuantie-jian/hai",
                           "name"    : "������ӿ",
                           "sk1"     : "xuantie-jian",
                           "lv1"     : 130,
                           "sk2"     : "force",
                           "lv2"     : 120,
                           "sk3"     : "dodge",
                           "lv3"     : 100,
                           "gongxian": 400, ]));

                break;
                
        case "ǧ��һ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xuantie-jian/qianjun",
                           "name"    : "ǧ��һ��",
                           "sk1"     : "xuantie-jian",
                           "lv1"     : 130,
                           "sk2"     : "force",
                           "lv2"     : 120,
                           "sk3"     : "dodge",
                           "lv3"     : 100,
                           "gongxian": 400, ]));

                break;
                                
        case "��Ȼ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                          ([ "perform" : "can_perform/sad-strike/xiao",
                           "free"    : 1,
                           "name"    : "��Ȼ����",
                           "sk1"     : "sad-strike",
                           "lv1"     : 150,
                           "neili"   : 3200,
                           "force"   : 320,
                         ]));
                break;

        case "�����ˮ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/sad-strike/tuo",
                           "free"    : 1,
                           "name"    : "�����ˮ",
                           "sk1"     : "sad-strike",
                           "lv1"     : 180,
                           "neili"   : 4000,
                           "force"   : 360,
                         ]));
                break;

        default:
                return 0;
        }
}

int not_to_learn_ss(object ob)
{
        if (ob->query("gender") == "Ů��")
        {
                command("say �������书���ʺ�Ů����ѧϰ���������˰ɣ�");
                return 1;
        }

        if (ob->query_temp("can_learn/yang/sad-strike"))
                return 0;

        if (ob->query("family/family_name") != query("family/family_name"))
        {
                command("say " + RANK_D->query_respect(ob) + "�㲻���ҵ��״����ӣ����Һθɣ�");
                return 1;
        }

        if (ob->query("static/sadly") < 3)
        {
                command("say ����᲻������˼�����ӵ��黳��"
                        "�޷�����ҵ���Ȼ�����ƣ�");
                return 1;
        }

        message_vision("$n���˿�$N�������ã�����Ҳ��������"
                       "ԨԴ���Ҿʹ�����Ȼ�����ƣ�\n",
                       ob, this_object());
        ob->set_temp("can_learn/yang/sad-strike", 1);
        return 0;
}

/*
mixed ask_me()
{
        object me;

        me = this_player();
        if (me->query("can_perform/sad-strike/wannian"))
                return "�Լ��úö���ϰ�ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�㲻���ҵ��״����ӣ��γ����ԣ�";

        if (me->query("shen") < 200000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����һ�У�";

        if (me->query_skill("sad-strike", 1) < 180)
                return "�����Ȼ�����ƻ������������һ����ܽ�����һ�У�";

        message_vision(HIM "$n" HIM "���������ڹ���Ȼ���Լ������ٶ���$N"HIM"�ӳ�һ�ƣ�\n"
                       HIM "$n" HIM "��һ����Ȼ����ޱȣ�����$N"HIM"ȷ��һ�е����ƿ��ú�͸����Ȼ������׾ٵıܿ��ˣ�\n"
                       "����$N" HIM "���Ϊʲô��һ����ô���ʱ��$n"HIM"������ͻȻ���Ա�һת�����ô�����$N"HIM"���ؿ��ϣ�����\n"
                       "$N"HIM"���һ��������Ѿ����У���æ�����ڹ�Ӳ������������һ�У�����......\n" NOR,
                       me, this_object());
        command("sigh");
        command("say �������һ�°ɡ�");
        tell_object(me, HIG "��ѧ���������ҡ�\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 160000);
        me->set("can_perform/sad-strike/wannian", 1);
        me->unconcious();
        return 1;
}
*/
/*
void unconcious()
{
        die();
}
*/
       void die(object killer)  
           {  
                   object ob;  
                   ob = new("/kungfu/class/gumu/yang"); 
                   ob->move(environment());  
                   ::die(killer);  
           }  
