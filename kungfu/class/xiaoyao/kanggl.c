// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "xiaoyao.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_me();

void create()
{
        set_name("������", ({ "kang guangling", "kang", "guangling" }));
        set("long", "ֻ�����߶�͹򪣬��ò��ţ�Ц���е���\n"
                    "ɫ��Ϊ���ӣ����б���һ�����١�\n");
        set("gender", "����");
        set("title", "��ң�ɺ��Ȱ���");
        set("nickname", YEL "�ٵ�" NOR);
        set("age", 58);
        set("attitude", "friendly");
        set("class", "scholar");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 38);
        
        set("max_qi", 3500);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 120);
        set("level", 10);
        set("combat_exp", 1500000);
        set("book_count", 1);

        set_skill("force", 180);
        set_skill("xiaowuxiang", 180);
        set_skill("dodge", 160);
        set_skill("feiyan-zoubi", 160);
        set_skill("strike", 160);
        set_skill("liuyang-zhang", 160);
        set_skill("hand", 160);
        set_skill("qingyun-shou", 160);
        set_skill("parry", 160);
        set_skill("blade", 180);
        set_skill("ruyi-dao", 180);
        set_skill("literate", 140);
        set_skill("tanqin-jifa", 220);
        set_skill("qiuyue-lai", 220);
        set_skill("martial-cognize", 160);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("hand", "qingyun-shou");
        map_skill("strike", "liuyang-zhang");
        map_skill("parry", "ruyi-dao");
        map_skill("blade", "ruyi-dao");
        map_skill("tanqin-jifa", "qiuyue-lai");

        prepare_skill("hand", "qingyun-shou");
        prepare_skill("strike", "liuyang-zhang");

        create_family("��ң��", 3, "����");

        set("inquiry", ([
                "����" : (: ask_me :),
        ]) );
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.zhuo" :),
                (: perform_action, "strike.pan" :),
                (: perform_action, "blade.ruyi" :),
                (: exert_function, "recover" :),
        }));

        set("master_ob", 3);
	setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
        set_temp("handing", carry_object("/d/changan/npc/obj/muqin"));
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query_int() < 28)
        {
                command("hmm");
                command("say �������̫���ôѧ�ҵ��ټ���");
                return;
        }

        if (ob->query_skill("xiaowuxiang", 1) < 30)
        {
                command("sigh");
                command("say �������ŵ������ķ���û��ѧ�ã�����������㣿");
                return;
        }

        command("say �ðɣ�������Ϊͽ����ѧЩ��������������������䡣");
        command("recruit " + ob->query("id"));
}

mixed ask_me()
{
        object me, ob;
        
        ob = this_player(); 
        if (query("book_count") < 1)
                return "�������ˣ��������Ѿ����͸������ˡ�";   

        add("book_count", -1);                  
        command("say �ðɣ����ҾͰ����͸����ˡ�\n");
        message_vision(HIY "������΢Ц�Ŵӻ����ó���һ���飬���˸�$N\n\n" NOR, ob);
        me = new("/clone/book/hand_book");
        me->move(ob);
        return "�Ȿ���׿�ǧ��Ҫ�������ˡ�\n";
}