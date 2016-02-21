// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jian.c ����

#include <ansi.h>
#include "gaibang.h"

#define POBU    "/d/gaibang/npc/obj/po-bu"
#define LING    "/d/gaibang/npc/obj/qingzhu-ling"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

mixed ask_me();

void create()
{
        set_name("����", ({ "jian zhanglao", "jian", "zhanglao" }));
        set("long", @LONG
������ؤ���ִ�����ϣ�������ִ�Ʒ�����
��������ȡ�������������𣬵�������˭��
�������־������顣
LONG);
        set("nickname", HIR "ִ������" NOR);
        set("title", "ؤ��Ŵ�����");
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        
        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);
        set("max_qi", 4200);
        set("max_jing", 3500);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 180);
        set("combat_exp", 2000000);
        set("level", 20);
        set("score", 500000);
        set("shen_type", 1);

        set_skill("force", 240);
        set_skill("huntian-qigong", 240);
        set_skill("dodge", 220);
        set_skill("feiyan-zoubi", 220);
        set_skill("unarmed", 200);
        set_skill("changquan", 200);
        set_skill("hand", 220);
        set_skill("shexing-diaoshou", 220);
        set_skill("strike", 220);
        set_skill("xiaoyaoyou", 220);
        set_skill("parry", 220);
        set_skill("staff", 240);
        set_skill("fengmo-zhang", 220);
        set_skill("jiaohua-bangfa", 220);
        set_skill("blade", 220);
        set_skill("liuhe-dao", 220);
        set_skill("begging", 260);
        set_skill("checking", 260);
        set_skill("literate", 200);
        set_skill("martial-cognize", 200);

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-diaoshou");
        map_skill("unarmed", "changquan");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("parry", "fumo-zhang");
        map_skill("staff", "fengmo-zhang");
        map_skill("strike", "xiaoyaoyou");
        map_skill("blade", "liuhe-dao");

        prepare_skill("hand", "shexing-diaoshou");

        create_family("ؤ��", 18, "�Ŵ�����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "staff.luan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("inquiry", ([
                "������" : (: ask_me :)
        ]));

        set("master_ob",4);
	setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        object ob;
        mapping myfam;
        
        ::init();
        set_heart_beat(1);      
        if (interactive(ob = this_player()) && ! is_fighting() 
        &&  file_name(environment(this_object())) == "/d/city/gbandao") 
        {
                myfam = (mapping)ob->query("family");
                if ((! myfam || myfam["family_name"] != "ؤ��") &&
                        (! wizardp(ob))) {
                        remove_call_out("saying");
                        call_out("saying", 2, ob);
                }
        }
}

void saying(object ob)
{
        if (! ob || environment(ob) != environment())
                return;

        message_sort("\n\n$n����$Nһ�ۣ������˵����������������˼�˵�Ҳ���"
                     "�������ؤ����ӣ����ֲ�����ؤ��Ҵ����ܿ��԰ɣ���"
                     "˵������һ̧��$N˳��Ӧ��һ������ɵġ�ƨ�����ƽɳ����ʽ��"
                     "������ߴ\n\n", ob, this_object());
        remove_call_out("kicking");
        call_out("kicking", 1, ob);
        
}

void kicking(object ob)
{
        if (! ob || environment(ob) != environment())
                return;

        ob->move("/d/city/pomiao");
        message("vision", "ֻ�����ء���һ����������" +  ob->query("name") +
                "��С������˳�����ƨ������һ�������Ьӡ��\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
        command("hmm");
        command("say �Ϸ���ͽ�ܣ��㻹����ذɡ�");
}

mixed ask_me()
{
        object ob, me;
        int lvl, gx;

        me = this_player();

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����뱾��������������֪�˻��Ӻ�̸��";

          if (count_lt(me->query("combat_exp"),  10000))
                return "�ٺ٣������㱾��Ҳ����˼��Ҫ�����";

        lvl = me->query("family/beggarlvl");

        if (lvl >= 9)
                return "���Ѿ��Ǳ��ﳤ���ˣ��ֺ�ȥ�����Ǽƽϡ�";

        if (lvl <= 0)
                gx = 100;
        else
                gx = lvl * 100 + 200;

        if (me->query("family/gongji") < gx)
                return "��Ϊ����Ч����������ʱ���ܸ���������";

        if (present("qingzhu ling", me))
                return "�����ϲ����Ѿ�������������";

        if (time() - me->query_temp("have_ling") < 100)
                return "�Ҳ��ǸողŸ�����һ������΢�Ȼ�ɡ�";

        ob = new(LING);
        ob->move(this_object());

        command("give qingzhu ling to " + me->query("id"));
        me->set_temp("have_ling", time());

        return "ƾ���������������������ͬ�Ŵ�ʦ����ս��";
}

int accept_object(object ob, object obj)
{
        object me = this_object();
        int r;
        int lvl, exp, pot, sc, ww, gx;
        string msg;

        if (r = ::accept_object(ob, obj))
                return r;

        if (base_name(obj) != POBU)
        {
                command("say ��������ֶ�����ʲô��");
                return 0;
        }

        if (obj->query("owner") != ob->name())
        {
                command("say ������Ʋ��Ǵ�����͵���ģ�");
                return 0;
        }

        if (ob->query_temp("have_cloth") < 1)
        {
                command("say �������ʤ��ô������ô��û��˵��");
                return 0;
        }

        lvl = ob->query("family/beggarlvl");

        if (lvl >= 9)
        {
                command("say ���Ѿ��Ǳ��ﳤ���ˣ����뵱������");
                return 0;
        }

        if (lvl <= 0)
                gx = 100;
        else
                gx = lvl * 100 + 200;

        if (ob->query("family/gongji") < gx)
        {
                command("say �������Ϊ����Ч����������ʱ���ܸ���������");
                return 0;
        }

        ob->add("family/beggarlvl", 1);
        ob->set("title", ob->query_temp("newtitle"));
        ob->delete_temp("have_cloth");
        ob->delete_temp("newtitle");

        message_vision(HIY "\n$N" HIY "�ӹ����Ʋ���Ȼ���䶤"
                       "��$n" HIY "�����·��ϣ�ٲȻһ���¿ڴ�"
                       "��\n\n" NOR, me, ob);
        command("nod");
        command("say ��Ȼ�������͵��μǰ�棬Ϊ�������");

        lvl = lvl + 1;
        exp = lvl * 600 + random(lvl * 400);
        pot = lvl * 300 + random(lvl * 200);
        sc = lvl * 80 + random(lvl * 50);
        ww = lvl * 50 + random(lvl * 30);

        ob->add("combat_exp", exp);
        ob->add("potential", pot);
        ob->add("score", sc);
        ob->add("weiwang", ww);
        ob->add("family/gongji", -gx);

        msg = HIC "\nͨ�������ľ�����������" +
              chinese_number(exp) + "�㾭�顢" +
              chinese_number(pot) + "��Ǳ�ܡ�" +
              chinese_number(sc) + "�㽭�������Լ�" +
              chinese_number(ww) + "�㽭��������ͬʱ"
              "������" + chinese_number(gx) + "����"
              "�ɹ��ף���ѧ�õ��˾�����\n\n" NOR;

        tell_object(ob, sort_string(msg, 54));
        ob->improve_skill("martial-cognize", 1500000);

        destruct(obj);
        return 1;
}


