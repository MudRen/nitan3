// diaogan.c ����

#include <ansi.h>

inherit ITEM;

void init()
{
        if (interactive(this_player()) &&
            environment() == this_player())
        {
                add_action("do_fish", "fish");
                add_action("do_draw", "draw");
        }
}

void create()
{
        set_name(HIG "����" NOR, ({ "diao gan", "gan" }));
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ�������߳��õĵ��ͣ�������������(fish)��\n");
                set("value", 2000);
        }

        setup();
}

int do_fish()
{
        object yr;
        object ob;
        object me = this_player();

        if (! arrayp(environment(me)->query("resource/fish")))
                return notify_fail("���￴������������ӡ�\n");

        if (! objectp(yr = present("yu er", me)) || yr->query_amount() < 1)
                return notify_fail("������û������ˡ�\n");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("�㻹��æ����ͷ�ϵ�������˵�ɡ�\n");

        if (sizeof(filter_array(all_inventory(environment(me)), (: $1->is_character() && $1->query_temp("fishing_env") :))) > 20)
                return notify_fail("�㻹�ǻ����ط�����ɣ�����������̫���ˡ�\n");

        tell_object(me, "���ͳ�һ���������ϸ�ķ��ڵ����ϣ�����һ˦�ˣ�ֻ��ˮ���ϵ�����\n"
                       "һ����ԲȦ���м�ֻ��һ����ɫ�ĸ���������ˮ��������\n");
        yr->add_amount(-1);
        me->start_busy((: call_other, __FILE__, "finishing" :),
                       (: call_other, __FILE__, "halt_finishing" :));
        set_temp("owner", me);
        me->set_temp("fishing", 0);
        me->set_temp("fishing_env", environment(me));
        return 1;
}

int finishing(object me)
{
        int stage;
        string msg;

        if (environment(me) != me->query_temp("fishing_env"))
        {
                me->delete_temp("fishing");
                me->delete_temp("fishing_env");
                return 0;
        }

        switch (stage = me->query_temp("fishing"))
        {
        case 1:
                if (random(4))
                {
                        msg = "$N�ĸ���������𶯣�һ��һ�µ�ҡ�θ���ͣ��";
                        break;
                }

                msg = "$N�ĸ��Ӻ�Ȼ���ҵ���������";
                stage++;
                break;

        case 2:
        case 3:
                msg = random(2) ? "$N�ĸ��Ӻ������ҡ�ڸ���ͣ��"
                                         : "$N�ĸ�����Ȼ����һ�ܣ�Ȼ��������ˮ�档";
                stage++;
                break;
        case 4:
                msg = random(2) ? "һ����ҵ�ҡ�ڹ��󣬸��Ӱ���"
                                           "������$N��æ������ͣ�һ�����Ͽտ���Ҳ��"
                                         : "������Ȼ�����Ұڶ�����Ȼ�ְ��������ˣ�$N�ɻ��"
                                           "������ͣ���������\n���㹳������ʲôҲû�С�";
                                           
                tell_object(me, CYN "����������(draw)�����ˣ��װ׵�����һ�������\n" NOR);
                me->delete_temp("fishing");
                delete_temp("owner");
                return 0;

        default:
                if (random(5))
                {
                        if (random(3)) return 1;
                        msg = random(2) ? "ˮ�沨��������û��ʲô�仯��"
                                        : "΢������Ĵ���ˮ�浴��һ���ϸ�ˣ�����û�����Ϲ���";
                        break;
                }
                msg = "��Ȼ$N�ĸ�������һ�¡�";
                stage = 1;
                break;
        }
        msg += "\n";
        msg = replace_string(msg, "$N", "��");
        tell_object(me, msg);
                
        me->set_temp("fishing", stage);
        return 1;
}

int halt_finishing(object me)
{
        delete_temp("owner");
        me->delete_temp("fishing");
        message_vision("$N������ͣ��������ǲ����ٵ��ˡ�\n",  me);
        return 1;
}


int do_draw(string arg)
{
        string *fish;
        object ob;
        object me;
        int stage;
        mixed exp;
        mixed pot;

        if (! arg || ! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();

        if (query_temp("owner") != me)
                return notify_fail("����û�ڵ��㣬���˸�ʲô��\n");

        if (environment(me) != me->query_temp("fishing_env"))
                return 0;

        stage = me->query_temp("fishing");
        if (stage < 2)
        {
                tell_object(me, "����æһ�����ͣ��߸ߵľ���������ȴ�����������Ȼ����"
                                "�������ӣ�ֻ��\n��ͷɥ�������°Ѹ�˦�˳�ȥ��\n");
                me->set_temp("fishing", 0);
                return 1;
        }

        fish = environment(me)->query("resource/fish");
        if (sizeof(fish) < 1)
                log_file("log", sprintf("variable: resource/fish error in %s.\n",
                                        base_name(environment(me))));
        ob = new(fish[random(sizeof(fish))]);

        tell_object(me, random(2) ? "���ּ��ۿ죬�͵�һ�յ��ͣ�ֻ���������һ" +
                                   ob->query("unit") + "Ť��Ťȥ��" +
                                   ob->name() + "��\n"
                                 : "��˳��һ���ˣ���ʱ��һ" + ob->query("unit") +
                                   ob->name() + "����������\n");
        tell_object(me, HIG "�������һ" + ob->query("unit") +
                        ob->name() + HIG + "��\n" NOR);
        ob->move(me, 1);

        delete_temp("owner");
        me->delete_temp("fishing");
        me->delete_temp("fishing_env");

        if (me->query("total_hatred") > 1 && random(2)) 
                me->add("total_hatred", -1);
        if (count_lt(me->query("combat_exp"), 300000) ||
            count_gt(me->query("combat_exp"), 800000))
                return 1;

        exp = 150 + random(100);
        pot = exp / 2;
        me->add("combat_exp", exp);
        if (count_lt(me->query("potential"), me->query_potential_limit()))
                me->add("potential", pot);
        tell_object(me, HIC "������΢΢һ��������ѧ�����������һ�㡣\n" NOR);
        return 1;
}

int move(mixed dest, int raw)
{
        object me;

        if (me = query_temp("owner"))
                me->interrupt_me();

        return ::move(dest, raw);
}

