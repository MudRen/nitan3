#include <ansi.h>

inherit NPC;
inherit F_DEALER;
inherit F_NOCLONE;

mixed ask_me();
mixed ask_me3();

void create()
{
        set_name("����", ({ "nan xian", "nan", "xian" }));
        set("long", @LONG
����������ɼ���뷢�԰ס�������ò���ʵ
ȴΪ����ͷ���������������кųơ�����
���󡹵����͡���Ϊ��������а������ʱ����
�����������춯�صĴ�١���ƽ��ս��������
�ڱ�������ʧ���֡�
LONG);
        set("nickname", HIW "��������" NOR);
        set("title", HIC "����̩��" NOR);
        set("gender", "����" );
        set("age", 74);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("combat_exp", 12000000);

/*
        set_skill("force", 500);
        set_skill("huntian-baojian", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("unarmed", 500);
        set_skill("sword", 500);
        set_skill("lunhui-jian", 500);
        set_skill("poison", 500);
        set_skill("medical", 500);
        set_skill("lingbo-weibu", 500);
        set_skill("qiankun-danuoyi", 500);
        set_skill("buddhism", 500);
        set_skill("taoism", 500);
        set_skill("literate", 500);
        set_skill("martial-cognize", 500);

        map_skill("force", "huntian-baojian");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("unarmed", "huntian-baojian");
        map_skill("dodge", "lingbo-weibu");
        map_skill("sword", "lunhui-jian");

        prepare_skill("unarmed", "huntian-baojian");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hui" :),
                (: perform_action, "sword.hui" :),
                (: perform_action, "sword.hui" :),
                (: exert_function, "sword" :),
                (: exert_function, "sword" :),
                (: exert_function, "sword" :),
                (: exert_function, "recover" :),
                (: exert_function, "regenerate" :),
                (: exert_function, "powerup" :),
        }));
*/

        set("inquiry", ([
                "name" : "����������һ�ִ��Ŷ��ѣ������к����壿",
                "����" : "�㾡���Ǹ������ļһ�������",
                "��̶" : (: ask_me :),                
                "����" : (: ask_me :),  
                "gift" : (: ask_me :),
                "����": (: ask_me3 :),
                "������": (: ask_me3 :),
                "��ɽ����": (: ask_me3 :),
                "�μӱ���": (: ask_me3 :),          
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

/*
        if (! clonep(this_object()))
        {
                move("/d/xiakedao/haibin");
                message_vision(WHT "\nͻȻ������ǰһ��������ƺ����˸�"
                               "��Ӱ��\n" NOR, this_object());
                set("startroom", "/d/xiakedao/haibin");
        }
*/
        set("startroom", "/d/city/wumiao");
        check_clone(); 
}

// ����ѯ��
mixed accept_ask(object who, string topic)
{
        // return ULTRA_QUEST_D->accept_ask(this_object(), who, topic);
}

void fight_ob(object ob)
{
        if (is_fighting(ob))
                return;

        command("say �ߣ���֪���");
        command("exert powerup");
        command("exert sword");
        ::fight_ob(ob);
}

int accept_fight(object who)
{
        command("say û��Ȥ��");
        return 0;
}

int accept_ansuan(object who)
{
        return notify_fail("����밵�㣬������ǰһ��������̫�����\n");
}

mixed ask_me()
{
        object me = this_player();
        object ob;
        
        if ((int) me->query("welcomegift"))
        {
                command("say �Ǻǡ���������Ĳ����ˣ��Ϸ��Ѿ������������ˣ�");
                return 1;
        }
        else
        {
                me->set("welcomegift", 1);
                me->add("food", 5000);
                me->add("water", 10000);
                /*
                me->set("kar", 30);
                me->set("per", 30);
                */
                me->set("tianfu", 4);
                // me->add("potential", 1000);
                
                ob = new("/adm/npc/obj/gift");
                ob->move(me); 

                // ob->move(this_object()); 
                // command("give gift to " + me->query("id"));       
                
        /*
                CHANNEL_D->do_channel(me, "es", sprintf("����%s���չ��١���̶����61.128.162.81 : 2001��\n            ���ѵõ����͵İ����ͽ�����������ʼ������ˣ�", 
                                      me->name(1)));
        */
                                      
                message_vision(HIW "$N" HIW "���һָ��ͻȻ�����һ��" HIM "��" HIY "��" HIR "ϼ" HIC "��" HIW "����$n��ת˲���ţ�\n" NOR, 
                               this_object(), me);
                               
                tell_object(me, HIG "�����͸�����һ�����gift��������� look gift ��������ʲô���\n" NOR);
                return 1;
        }
}

mixed ask_me3()
{
        object me = this_player();

        tell_object(me, HIY "����˵������Ȼ��Ҫ�μӱ��䣬��ô�Ϸ������һ�̣�\n" NOR);
        message_vision(HIY "ֻ����������һ�У�һ���������$N��$N�ڿշ�ȥ��\n" NOR, me);
        me->move("/d/huashan/houzhiwangyu");
        return 1;
}
void unconcious()
{
        die();
}

int accept_object(object who, object ob)
{
        return ULTRA_QUEST_D->accept_object(this_object(), who, ob);
}
