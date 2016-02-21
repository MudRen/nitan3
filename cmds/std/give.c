// give.c
#include <ansi.h>
#include <config.h>

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who, int info);
int accept_object(object me, object who, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
        string no_accept;
       // mixed info;
	int i, amount;

	if (! arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if (sscanf(arg, "%s to %s", item, target) == 2 ||
	    sscanf(arg, "%s %s", target, item) == 2 );
	else return notify_fail("��Ҫ��˭ʲô������\n");

	if (! objectp(who = present(target, environment(me))))
        {
                string ext;

                if (sscanf(arg, "%s %s %s", ext, target, item) != 3 ||
                    ! objectp(who = present(ext + " " + target, environment(me))))
		        return notify_fail("����û������ˡ�\n");
        }


        if (me == who) return notify_fail("ë�������Լ����Լ���������\n");
        if (in_input(who))
                return notify_fail("�㻹�ǵõ��˼�æ������˵�ɡ�\n");
        if (! living(who))
                return notify_fail("�㻹�ǵõ��˼�������˵�ɡ�\n");

        if (playerp(me) && !wizardp(me) && stringp(no_accept = who->query("env/no_accept")))
        {
                if ((no_accept == "all" || no_accept == "ALL" ||
                     is_sub(me->query("id"), no_accept)) &&
                    ! is_sub(me->query("id"), who->query("env/can_accept")))
                {
                        // user refuse to accept
		        return notify_fail("�˼����ڲ���Ҫʲô������\n");
                }
        }

	if (sscanf(item, "%d %s", amount, item) == 2)
        {
		if (! objectp(obj = present(item, me)) && item[0] > 160)
		{
			inv = all_inventory(me);
			for (i = 0; i < sizeof(inv); i++)
			if (filter_color(inv[i]->name(1)) == item)
			{
				obj = inv[i];
				break;
			}
		}
		
		if (!obj)
			return notify_fail("������û������������\n");

		if (me->query_temp("is_riding") == obj)
			return notify_fail("�����������ء�\n");

		if (! obj->query_amount())
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");

		if (amount < 1)
			return notify_fail("����������������һ����\n");

		if (amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");

		else if (amount == (int)obj->query_amount())
                {
                        do_give(me,obj,who,1);
                        return 1;
		} else
                {
			obj->set_amount((int)obj->query_amount() - amount);
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
                         if (do_give(me, obj2, who,1))
				return 1;
			else
                        if (obj2)
                        {
				obj->set_amount((int)obj->query_amount() + amount);
                                destruct(obj2);
				return 1;
			}
		}
	}

	if (item == "all")
        {
                inv = all_inventory(me);
		for (amount = 0, i = 0; i < sizeof(inv); i++)
                {
                        if (! living(me)) break;
                        if (environment(me) != environment(who)) break;
			if (objectp(inv[i]) &&
                            me->query_temp("is_riding") != inv[i])
                                amount += do_give(me, inv[i], who, 0);
		}
                if (! amount)
		{
                        write("��ʲô��û�и���ȥ��\n");
			return 1;
		}
                message_vision("$N��һ�Ѷ����ݸ�$n��\n",me,who);

		write("�����ˡ�\n");
		return 1;
	}

	if (! objectp(obj = present(item, me)) && item[0] > 160)
	{
		inv = all_inventory(me);
		for (i = 0; i < sizeof(inv); i++)
		if (filter_color(inv[i]->name(1)) == item)
		{
			obj = inv[i];
			break;
		}
	}
	if (!obj)
		return notify_fail("������û������������\n");

	if (me->query_temp("is_riding") == obj)
		return notify_fail("�����������ء�\n");

        do_give(me, obj, who, 1);
        return 1;
}

int do_give(object me, object obj, object who,int info)
{
        if (obj->query("no_drop") && !who->is_ultra())
        {
		tell_object(me, "�����������������ˡ�\n");
                return 0;
        }

	if (living(obj))
	{
		tell_object(me, "���ģ�����ô����������Ҳ����\n");
		return 0;
	}

        if (obj->query("dynamic_quest") && playerp(who))
        {
                tell_object(me, "����������������ˣ�\n");
                return 0;
        }
        
        if (playerp(who) &&
            sizeof(filter_array(all_inventory(who), (: ! $1->query("equipped") :))) >= MAX_ITEM_CARRIED &&
            ! obj->can_combine_to(who))
        {
		tell_object(me, "�˼����ϵĶ���ʵ����̫���ˣ�û�����ö����ˡ�\n");
                return 0;
        }

	switch ((string)obj->query("equipped"))
	{
	case "worn":
		tell_object(me, obj->name() + "�������������ܸ����ˡ�\n");
                return 0;

	case "wielded":
                tell_object(me, obj->name() + "������װ�����ܸ����ˡ�\n");
                return 0;
	}
		
        if (info)
        message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);

        /*
        if (obj->query("dynamic_quest"))
        {
                if (TASK_D->quest_reward(me, who, obj))
                return 1;
        }
        */

        if (obj->query("task_ob"))
        {
                if (TASK_D->task_reward(me, who, obj))
                return 1;
        }
        
        if (! playerp(who))
        {
                function f;
                int r;

                r = 0;

                // ������Ʒ��ʱ�����ж��Ƿ�ΪNPC��������
                if (me->query("bunch_quest") && me->query("bunch_quest/type") == "Ѱ����Ʒ")
                        r = accept_object(me, who, obj);

                if (! r)
                {
                        // ������Ʒ��ʱ�����ж��Ƿ������صĽ��պ���
                        f = who->query_temp("override/accept_object", 1);
                        if (functionp(f))
                                r = (*f)(who, me, obj);
                        else
                                r = 0;
                }

                if (! r)
                        // ���صĺ��������ܣ�Ҳ������(����-1)
                        // ��ô�͵���accept_object���д���
                        r = who->accept_object(me, obj);

                if (! objectp(who)) return 0;
                switch (r)
                {
                case 0:
                        if (info)
                        message_vision("$n����Ҫ$N��" + obj->name() + "��\n", me, who);
        		return r;
                case -1:
                        // The receiver will handle all the things
                        if (! obj || environment(obj) == who)
                                return 1;
                        return 0;
                default:
                        break;
                }
                if (! objectp(obj))
                        // The receive has destructted the object
                        return 1;
        }

        if (! playerp(who) && obj->value())
        {
		message_vision("$n�ӹ���$N��" + obj->short() + "��\n", me, who);
		destruct(obj);
		return 1;
	}

        if (! obj->move(who))
        {
                message_vision("Ȼ��$nû����ס$N��" + obj->name() + "��\n", me, who);
                return 0;
        }

        return 1;
}

int accept_object(object me, object who, object ob)
{
        mapping bunch_quest,b;
        object reward;

        int exp;
        int pot;
        int score;
        int weiwang;

        if (ob->is_character() || ob->is_item_make())
                // ���������������ı���
                return 0;

        bunch_quest = me->query("bunch_quest");

        //��������
        if (bunch_quest["target"] != base_name(who))
                return 0;

        //��������
        if (ob->name() != bunch_quest["obj_name"])
                return 0;

        message_sort("$N�ӹ�" + ob->name() + "��������ȥ���˿���ϲ��"
                     "��ʤ��һʱ���Ǽ�����֡����βŶ�$n��������λ" +
                     RANK_D->query_respect(me) +
                     "��ʵ���Ǹм����������С��˼�����Ц�ɣ���\n", who, me);

        message_vision("$N����$nһЩ������Ϊ���ꡣ\n", who, me);

        reward = new("/clone/money/silver");
        reward->set_amount(20);
        reward->move(me, 1);

        // ����
        me->add("pk_score", -2);
        if (me->query("pk_score") < 0) me->set("pk_score", 0);

        exp = bunch_quest["bonus"];
        exp += atoi(count_div(me->query("combat_exp"), 5000));
        exp += random(exp/2);
        pot = exp/(2 + random(2));
        score = 5 + random(10);
        weiwang = 5 + random(10);

        b = ([ "exp" : exp,
               "pot" : pot,
               "score" : score,
               "weiwang" : weiwang,
               "prompt": "�ڰ���" + who->name() + "Ѱ��" + bunch_quest["obj_name"] +
                         HIG "�Ĺ����У���������" ]);

        QUEST_D->delay_bonus(me, b);

        me->delete("bunch_quest");
        me->add_temp("finish_bunch_times",1);

        destruct(ob);
        return -1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : give <��Ʒ����> | all to <ĳ��>
      �� : give <ĳ��> <��Ʒ����> | all
 
���ָ��������㽫ĳ����Ʒ�����ˣ���Ȼ��������Ҫӵ��������Ʒ��
 
HELP );
        return 1;
}
