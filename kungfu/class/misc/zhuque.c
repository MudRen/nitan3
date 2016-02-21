// nanhai.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIR "��ȸ" NOR, ({ "fire phoenix", "phoenix", "fenghuang" }) );
        set("title", HIR "����" NOR);
        set("gender", "Ů��");
        set("age", 20);
        set("long", @LONG
����һֻ�޴�Ļ��ˣ�����ȼ�������ܵ��һ𣬲�ʱ����һ����˺���ѷεĹֽС�
LONG );
        set("combat_exp", 10000000);
        set("shen_type", 0);
        set("attitude", "heroism");
        set("max_neili", 220000);
        set("neili", 220000);
        set("max_jing", 180000);
        set("jing", 180000);
        set("max_qi", 100000);
        set("qi", 100000);
        set("jingli", 120000);
        set("max_jingli", 120000);

        set("str", 60);
        set("int", 100);
        set("con", 100);
        set("dex", 100);

        set_skill("unarmed", 1000);
        set_skill("sword", 1000);
        set_skill("parry", 1000);
        set_skill("dodge", 1000);
        set_skill("force", 1000);

        set("jiali", 400);

        set_temp("apply/attack", 800);
        set_temp("apply/unarmed_damage", 600);
        set_temp("apply/armor", 300);

        if (clonep(this_object()))
        {
                set("chat_chance", 30);
                set("chat_msg", ({ (: random_move :) }));
                set("born_time", time());
                keep_heart_beat();
        }

        setup();
}

void fight_ob(object ob)
{
        if (is_fighting(ob))
                return;

        message_vision(HIR "$Nһ����˻������������䣬"
                       "�����ĵ����ѡ�\n" NOR, this_object(), ob);

        ::fight_ob(ob);
        if (! is_killing(ob->query("id")))
                kill_ob(ob);
}

int accept_fight(object ob)
{
        message_vision("$Nһ����˻������������\n",
                       this_object(), ob);
        kill_ob(ob);
        return -1;
}

int accept_kill(object ob)
{
        return 1;
}

int accept_hit(object ob)
{
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        ob->receive_wound("qi", 160 + random(170), me);
        me->set("neili", me->query("max_neili"));
        return HIR "$N" HIR "��Χ���汬�ǣ�������䣬��ʱ��$n"
               HIR "ʹ�಻�����������ܡ�\n" NOR;
}

void unconcious()
{
        die();
}

void die()
{
        object ob;
        string str;
        string* prize = ({
             "/clone/fam/etc/zhuquejiao",
             "/clone/fam/etc/zhuquejin",
             "/clone/fam/etc/yumao",
        });

        // �������
        if (! this_object()->query("is_die"))
        {
            message_sort(HIR "\n$N" HIR "һ����˻���ض�ɽҡ����Ȼ�䣬���������죬$N"
                         HIR "�ڿն����ڰ���������ţ��漴�ֻص���ԭ�ء�\n" NOR, this_object());

            this_object()->start_busy(2 + random(5));

            CHANNEL_D->do_channel(this_object(), "rumor",
                        "��˵" + name() + HIM "��������������������\n" NOR);

            set("max_neili", 220000);
            set("neili", 220000);
            set("max_jing", 180000);
            set("jing", 180000);
            set("eff_jing", 180000);
            set("max_qi", 340000);
            set("qi", 340000);
            set("eff_qi", 340000);
            set("jingli", 120000);
            set("max_jingli", 120000);

            set("str", 100);
            set("int", 100);
            set("con", 100);
            set("dex", 200);

            set_skill("unarmed", 1800);
            set_skill("sword", 1800);
            set_skill("parry", 1800);
            set_skill("dodge", 1800);
            set_skill("force", 1800);
            
            add("is_die", 1);
            return ;
        }

        str = prize[random(sizeof(prize))];
        ob = new(str);
        command("chat ��ѽ���˼��Ȼ�����ܴ���ң����һص�����ɽ������ǧ����˵��");
        message_sort(HIR "$N" HIR "����һŤ��������ģ�"
                     "ֻ���������һ������$N" HIR "���ϵ�����һ" +
                     ob->query("unit") + ob->name() +
                     HIR "��\n" NOR, this_object());
        ob->move(environment());
        destruct(this_object());
}

void random_move()
{
        if (time() - query("born_time") > 2400)
        {
                message_vision("$N����ææ�����ˡ�\n", this_object());
                CHANNEL_D->do_channel(this_object(), "rumor",
                        "��˵" + name() + HIM "�����˼�������ӣ�ˮ�������������ֻص��˻���ɽ��" NOR);
                destruct(this_object());
                return;
        }
        NPC_D->random_move(this_object());
}

