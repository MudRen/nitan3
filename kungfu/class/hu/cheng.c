// cheng.c

#include <ansi.h>;

inherit NPC;

#define SHENPIAN    "/clone/book/yaowang"

mixed ask_shenpian();

void create()
{
        set_name("������", ({ "cheng lingsu", "cheng" }));
        set("gender", "Ů��");
        set("age", 24);
        set("long", @long
������ȥ˫ü��������֪����ʲô���£�������òƽƽ���������ڡ�
�����С�����Ŵֲ�������
long);
        set("attitude", "peaceful");
        set("str", 22);
        set("int", 35);
        set("con", 31);
        set("dex", 27);
        set("chat_chance", 10);
        set("chat_msg", ({
                "�����ذ�����̾�˿�����\n",
        }));

        set("qi", 2500);
        set("max_qi", 2500);
        set("jing", 1200);
        set("max_jing", 1200);
        set("neili", 2800);
        set("max_neili", 2800);
        set("jiali", 40);
        set("combat_exp", 400000);
     
        set_skill("force", 150);
        set_skill("poison", 270);
        set_skill("dispel-poison", 270);
        set_skill("medical", 270);
        set_skill("yaowang-miaoshu", 270);

        set("inquiry",([
                "���":     "��...��...\n",
                "Ԭ����":   "��...��������ʲô��\n",
                "ҩ����ƪ" : (: ask_shenpian :),
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object me, string skill)
{
        if (me->query("family/family_name") != "�������")
        {
                command("say ����˭������ʲô��");
                return -1;
        }

        if (skill != "poison" && skill != "dispel-poison" &&
            skill != "medical" && skill != "yaowang-miaoshu")
        {
                command("say ��ֻ�ᶾ����ҽ��������Ҿ�û���ӽ�������");
                return -1;
        }

        if ((int)me->query("shen") < 0)
        {
                command("sigh");
                command("say ����������а·���ҿɲ��ܽ��㶾����");
                return -1;
        }

        if (! me->query_temp("can_learn/cheng/poison"))
        {
                me->set_temp("can_learn/cheng/poison", 1);
                command("say ���ں���������ϣ��Ҿͽ���һ�㱾�°ɣ����Ҫ����Ϊ֮��");
                return 1;
        }

        return 1;
}

mixed ask_shenpian()
{
        object me;
        object ob;
        object owner;

        me = this_player();
        if (me->is_bad())
        {
                if (me->query("family/family_name") == "�������")
                        message_vision(CYN "$N" CYN "���һ������$n" CYN "����"
                                       "�����ѵ���������ʦ������ô����������ھ�"
                                       "Ȼ���������һ�һ��������а�����������"
                                       "����ҩ����ƪ�������㣿��\n" NOR,
                                       this_object(), me);
                else
                        message_vision(CYN "$N" CYN "��Цһ������$n" CYN "˵��"
                                       "������һ��а����ͽ������̰ͼ���ɱ��"
                                       "��\n" NOR,
                                       this_object(), me);
                return 1;
        }

        if (me->query("family/family_name") != "�������")
                return "�㲻�ǹ�����ҵģ���������ʲô��";

        if (me->query("shen") < 100000)
                return "�������������û���������ҩ����ƪ���Ҳ��ܸ��㡣";

        if (me->query_skill("medical", 1) < 100)
                return "�����ҽ����δѧ�ã���������Ҳ��������";

        ob = find_object(SHENPIAN);
        if (! ob) ob = load_object(SHENPIAN);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "���⡶ҩ����ƪ�����ڲ�������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ�������Ѿ��ѡ�ҩ����ƪ�������ͬ��ʦ�ֵ��ˡ�";

                if (owner->query("family/master_id") == query("id"))
                        return "�ţ���ҩ����ƪ����������ͬ��ʦ�ֵ�" + owner->query("name") +
                               "�����ȥ�����ɡ�";
                else
                        return "���ŵġ�ҩ����ƪ������������" + owner->query("name") +
                               "֮�֣���ȥ����ȡ�����ɣ�";
        }

        ob->move(this_object());
        message_vision(HIC "$N" HIC "΢΢һЦ���������Ȿ��ҩ����ƪ������"
                       "���㣬��ס��ǧ�򲻿�����Ϊ����������\n" NOR,
                       this_object(), me);
        command("give yaowang shenpian to " + me->query("id"));
        return 1;
}

