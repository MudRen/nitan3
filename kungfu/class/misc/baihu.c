// nanhai.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW "�׻�" NOR, ({ "white tiger", "white", "tiger" }) );
        set("title", HIC "����" NOR);
        set("gender", "����");
        set("age", 5);
        set("long", @LONG
����һֻ�޴�İ׻�����׳�ޱȡ���Ϊ̫�׽��ǵ����
LONG );
        set("combat_exp", 10000000);
        set("shen_type", 0);
        set("attitude", "heroism");
        set("max_neili", 220000);
        set("neili", 220000);
        set("max_jing", 180000);
        set("jing", 180000);
        set("max_qi", 340000);
        set("qi", 340000);
        set("jingli", 120000);
        set("max_jingli", 120000);

        set("str", 160);
        set("int", 30);
        set("con", 80);
        set("dex", 80);

        set_skill("unarmed", 1800);
        set_skill("sword", 1800);
        set_skill("parry", 1800);
        set_skill("dodge", 1800);
        set_skill("force", 1800);

        set("jiali", 300);

        set_temp("apply/attack", 400);
        set_temp("apply/unarmed_damage", 600);
        set_temp("apply/armor", 1000);

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

        message_vision(HIW "$Nһ����Х��������צ����Ŀ������\n" NOR, this_object(), ob);

        ::fight_ob(ob);
        if (! is_killing(ob->query("id")))
                kill_ob(ob);
}

int accept_fight(object ob)
{
        message_vision(HIW "$N" HIW "һ����Х������$n" HIW "������\n" NOR,
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
        ob->receive_wound("qi", 200 + random(200), me);
        me->set("neili", me->query("max_neili"));
        return HIW "$N" HIW "��Χ�������ƣ���Ŀ��������ʱ��$n"
               HIW "�Ի��ѣ������԰Ρ�\n" NOR;
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
             "/clone/fam/etc/hugu",
             "/clone/fam/etc/hujin",
             "/clone/fam/etc/hupi",
        });

        str = prize[random(sizeof(prize))];
        ob = new(str);
        command("chat ��~����~~����");
        CHANNEL_D->do_channel(this_object(), "rumor", HIW "�����������һ�ȥ�ɣ�" NOR);
        command("chat ��~����~~����");
        CHANNEL_D->do_channel(this_object(), "rumor", HIM "��˵�׻���̫�׽���ץ����ͥ��\n" NOR);        
        message_sort(HIR "$N" HIR "����һŤ����ʧ�������У�"
                     "ֻ���������һ������$N" HIR "���ϵ�����һ" +
                     ob->query("unit") + ob->name() +
                     HIR "��\n" NOR, this_object());
        ob->move(environment());
        destruct(this_object());
}

void random_move()
{
        if (time() - query("born_time") > 1800)
        {
                message_vision("$N����ææ�����ˡ�\n", this_object());
                CHANNEL_D->do_channel(this_object(), "rumor",
                        "��˵" + name() + HIM "��ң���䣬�������ڱ�̫�׽���ץ����ͥ��" NOR);
                destruct(this_object());
                return;
        }
        NPC_D->random_move(this_object());
}

