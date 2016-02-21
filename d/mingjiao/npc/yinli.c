// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yinli.c ����

inherit NPC;
#include <ansi.h>

mixed ask_qianzhu();
mixed ask_he();

string *qianzhu_message = ({
        "ǧ����������һ�Ŷ���, ��ʵ������ָ��, �ڹ�, �Ṧ, �м�����, һͨ��ͨ��\n",
        "��ǧ�����ּ�Ϊ��ʱ����, �������֮�����ɡ�\n",
        "ǧ��������������Ϊ����, Ҫ����Ϊ�˱���, �ҲŲ����ء�\n",
        "ǧ��������������, ��Խ������Խ����, ��Ҳ�������˰���ֻ������ѡ�\n",
        "����ǧ������ʱ�������, ����һ��������Ϊ�������ɡ�\n",
        "��������ֻ֪�����ɱɱ, ʵս������ḻ, ������ô�κε����ҵ�ǧ������?\n",
        "������ǧ�����ֵ�, ֻ�󶾹���տ, ��ʵս���鵹ûʲô��ϵ��\n",
        "ǧ������һ��ʩչ, ��ҩ�ɾ�, ֻ���ж����Լ��������������⡣\n",
        "ǧ�����������ҵļҴ��书, ��˵ûʲô����, �ɵ���������, �����޼���Ҳ����ס��һָ��\n",
        "����ǧ�������Ժ���ò����, ���ǲ���˵�ˡ�\n",
        "Ҫ˵��������, ������ǧֻ����Ҳ����ࡣ\n",
        "����������ֻ��֩���Ժ�ͻϮ(tuxi)���˵�Ч���ɾ������ˡ�\n",
});

void create()
{
        set_name("����", ({ "yin li", "yin", "li" }));
        set("gender", "Ů��");
        set("age", 19);
        set("long","���Ǹ�ʮ�߰������Ů�����β�ȹ���Ǹ����ƶŮ��\n"+
                   "������ڣ����ϼ������ף�����͹͹�����ü��ǳ�ª��\n"+
                   "ֻ��һ������������ɣ����Ҳ���������㡣\n");
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 26);
        set("per", 6);
        set("unique", 1);
        set("location", 1);
        set("combat_exp", 300000);
        set("shen", -500);
        set("attitude", "peaceful");
        set("max_qi",600);
        set("max_jing",600);
        set("neili",800);
        set("max_neili",800);
        set("jiali",20);
        set_temp("no_return", 1);
        set_skill("unarmed", 60);
        set_skill("parry",60);
        set_skill("qingfu-shenfa",60);
        set_skill("dodge", 60);
        set_skill("throwing",60);
        set_skill("duoming-jinhua",60);
        set_skill("qianzhu-wandushou", 60);
        set_skill("finger", 60);
        set_skill("force",60);
        set_skill("shenghuo-shengong",60);
        map_skill("force","shenghuo-shengong");
        map_skill("finger","qianzhu-wandushou");
        map_skill("dodge","qingfu-shenfa");
        map_skill("throwing","duoming-jinhua");
        map_skill("parry","duoming-jinhua");
        prepare_skill("finger","qianzhu-wandushou");
	set("inquiry", ([
	        "ǧ������" : (: ask_qianzhu :),
	        "����" : "��, ��Ҫ�����¸��ı��������Ӹ������ú�����\n",
	        "��Ұ��" : "�����ҵ���\n",
	        "������" : "������үү��\n",
	        "������" : "�����ҹùá�\n",
	        "������" : "��, ����ȥ��˹����\n",
	        "��Ҷ����" : "��Ҷ������Ҳû������\n",
	        "����ţ" : "��, �����ҽ��, Ҫ������, ��Ҷ����Ҳ��������\n",
	        "���ѹ�" : "��, �ѹõĶ����Ǽ��ߵ�, ���ҵ�ǧ������ȴҲ����һ����\n",
	        "������" : "С�����˳���Ư��, �����۲���ô�á�\n",
	        "����" : "�Թ����Ļ�����, ���������\n",
	        "���޼�" : "��û���ĵġ����Ķ���������, �ҵ������Ҳ�������\n",
                "����" : (: ask_he :), 

	]));
	
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        setup();
        carry_object("/d/mingjiao/obj/green-cloth")->wear();
        carry_object("/clone/weapon/feihuangshi")->wield();
}

mixed ask_qianzhu() 
{
        object he, player = this_player(), me = this_object();
        int flags, level, idx;

        if (player->is_busy()) 
        {
	        return "����������������û��������˵�İ���\n";
        }

        flags = player->query_temp("qianzhu-wandushou/flags");
        level = player->query_skill("qianzhu-wandushou", 1);

        if (flags >= 1023 && level < 10) 
        {
	        command("say �ð�, ������ô����, �Ҿͽ������Ź���ɡ�\n");
                player->set_skill("qianzhu-wandushou", 10);
	        message_vision("$Nָ����$nһЩ������ǧ�����֡�\n", me, player);
                tell_object(player, "ʦ�������, ���п�����, �������Լ����������û�н��У�����������Ҫ��\n");
                return 1;
        }else 
        {
	        player->start_busy(1 + random(3));
                idx = random(sizeof(qianzhu_message));
	        if (idx < 10) 
	        {
	                flags = flags | (1 << idx);
   	        }
	        player->set_temp("qianzhu-wandushou/flags", flags);
	        return qianzhu_message[idx];
        }
}

mixed ask_he() 
{
        object player = this_player();
        object he;

        if (player->query_skill("qianzhu-wandushou", 1) < 10) 
        {
	        return "�����ز���ʶ, ����Ҳ��ð��ô��\n";
        }

        if (objectp(present("jin he", player))) {
	        return "���Ѿ��н����ˡ�\n�����Ҹ�ƫƧ������, ץһֻ��֩��, �Լ��Ϳ�����������\n";
        }
        he = new ("/clone/misc/jinhe");
        he->move(player);
        tell_object(player, "����ô��ô��С��, �ð�, ���ٸ���һ����\n");
        message_vision("$N��$nһ�����С�\n", this_object(), player);
        return 1;
}
