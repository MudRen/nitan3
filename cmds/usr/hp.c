// hp cmds (Mon  09-04-95)
// Update by Doing
// Update by Lonely

#include <ansi.h>
inherit F_CLEAN_UP;

string status_color(int current, int max);
 
int main(object me, string arg)
{
        object ob;
        mapping my;
        string sp;
        int craze;
 
        seteuid(getuid(me));

        if (arg && (arg == "-m"
           || sscanf(arg, "-m %s", arg)
           || sscanf(arg, "%s -m", arg)))
        {
                int ml, mn;
                mixed need;
                string combat_exp;
                int lv, level, exp;

                if (arg == "-m")
                        ob = me;
                else
                if (wizardp(me) || me->query("couple/child_id"))
                {
                        ob = present(arg, environment(me));

                        if (! ob || ! ob->is_character())
                                ob = find_player(arg);

                        if (! ob || ! ob->is_character())
                                ob = find_living(arg);

                        if (! ob || ! ob->is_character() || ! me->visible(ob)) 
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                        if (! wizardp(me) && me->query("couple/child_id") != ob->query("id"))
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                } else
                        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

                my = ob->query_entire_dbase();

                if (userp(ob) && (! stringp(my["born"]) || ! my["born"]))
                        return notify_fail("��û�г����ţ��쿴ʲô��\n");

                if (my["max_jing"] < 1 || my["max_qi"] < 1)
                        return notify_fail("�޷��쿴" + ob->name(1) + "��״̬��\n");

                // ����ȭ���Ӽ�������
                if (ob->query("special_skill/might"))
                        ml = (int)ob->query_skill("force") * 2 / 3;
                else
                        ml = (int)ob->query_skill("force") / 2;

                // ��ŭ֮�����Ӽ�ŭ����
                if (ob->query("special_skill/wrath"))
                        mn = ob->query_max_craze() / 70;
                else
                        mn = ob->query_max_craze() / 100;

#ifdef LONELY_IMPROVED               
                combat_exp = count_div(ob->query("combat_exp"), 100);
             	sscanf(combat_exp, "%d", exp);               
                level = to_int(pow(to_float(exp), 1.0 / 3)) * 10 + 1;
	
               	lv = ob->query("level");
               	if (lv < 1) lv = 1;
               	need = count_sub(count_mul(count_mul(lv + 1, lv +1), 10000), ob->query("combat_exp"));
               	if (count_lt(need, 1)) need = "1";
#else
                exp = ob->query("combat_exp") / 100;
                level = to_int(pow(to_float(exp), 1.0 / 3)) * 10 + 1;

                lv = ob->query("level");
                if (lv < 1) lv = 1;
                need = (lv + 1) * (lv + 1) * 10000 - ob->query("combat_exp");
                
                if (need < 1) need = 1;
#endif
                sp = (ob == me ? "��" : ob->name()) + "Ŀǰ�������������£�\n";
                sp += HIC "��" HIY "����������������������������������������������"
                      "����������������" HIC "��\n" NOR;

                sp += sprintf(HIC "���������ޡ� " HIG " %-21d"
                              HIC "���������ޡ� " HIG " %d\n",
                      ob->query_current_jingli_limit(), ob->query_current_neili_limit());

                sp += sprintf(HIC "��Ǳ�����ޡ� " HIG " %-21s"
                              HIC "��������ޡ� " HIG " %d\n",
                      count_sub(ob->query_potential_limit(), ob->query("learned_points")),
                      ob->query_experience_limit() - (int)ob->query("learned_experience"));

                sp += sprintf(HIC "����ǰ�ȼ��� " NOR + WHT " %-21d"
                              HIC "���������衿 " NOR + WHT " %s\n", lv, need);
                
                sp += sprintf(HIC "�����ܵ����� " NOR + WHT " %-21d"
                              HIC "���书���ޡ� " NOR + WHT " %d\n",
                      ob->query("points"), level);

                if (mn > 0)
                        sp += sprintf(HIC "������ŭ�� " NOR + WHT " %d\t\t   ", mn);
                else
                        sp += HIC "������ŭ�� " NOR + WHT " ������\t\t   ";

                sp += sprintf(HIC "���������� " NOR + WHT " %d\n", ml);

                sp += HIW "������������  " NOR + sprintf("%-37s",
                      (! ob->query("combat/WPK") && ! ob->query("no_newbie") && (ob->query("newbie") ||
                      count_lt(ob->query("combat_exp"), 20000000))) ? HIY "���o��" NOR :
                      HIY "�o���o" NOR);

                sp += HIW "��ɱ¾������  " NOR + sprintf("%s",
                      (ob->query("combat/WPK") || ob->query("no_newbie")) ? HIY "�o���o\n" NOR :
                      HIY "���o��\n" NOR);

                sp += HIC "��" HIY "����������������������������������������������"
                      "����������������" HIC "��\n" NOR;
                tell_object(me, sp);
                return 1;
        }

        if (arg && (arg == "-g"
           || sscanf(arg, "-g %s", arg)
           || sscanf(arg, "%s -g", arg)))
        {
                if (arg == "-g")
                        ob = me;
                else
                if (wizardp(me) || me->query("couple/child_id"))
                {
                        ob = present(arg, environment(me));

                        if (! ob || ! ob->is_character())
                                ob = find_player(arg);

                        if (! ob || ! ob->is_character())
                                ob = find_living(arg);

                        if (! ob || ! ob->is_character() || ! me->visible(ob)) 
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                        if (! wizardp(me) && me->query("couple/child_id") != ob->query("id"))
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");
                } else
                        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

                my = ob->query_entire_dbase();

                if (userp(ob) && (! stringp(my["born"]) || ! my["born"]))
                        return notify_fail("��û�г����ţ��쿴ʲô��\n");

                if (my["max_jing"] < 1 || my["max_qi"] < 1)
                        return notify_fail("�޷��쿴" + ob->name(1) + "��״̬��\n");

                sp = (ob == me ? "��" : ob->name()) + "Ŀǰ���츳�������£�\n";
                sp += HIC "��" HIY "����������������������������������������������"
                      "����������������" HIC "��\n" NOR;
                sp += HIY "�� �� �� �� " HIC "����ʼ�� �����졻 ���ɹ��� ��ʧ�ܡ�"
                      " �����¡� ��ת����\n" NOR;
                sp += HIC "��" HIY "����������������������������������������������"
                      "����������������" HIC "��\n" NOR;

                sp += sprintf(HIW "�� �� �� �� " NOR + WHT " [%3d]    ["
                      HIG "%3d" NOR + WHT "]    [" HIW "%3d" NOR + WHT "]    ["
                      HIR "%3d" NOR + WHT "]    [" HIM "%3d" NOR + WHT "]    ["
                      HIB "%3d" NOR + WHT "]\n",
                ob->query("str") - ob->query("gift/str/succeed") - ob->query("gift/sun"),
                ob->query("str"),
                ob->query("gift/str/succeed"),
                ob->query("gift/str/fail"),
                ob->query("gift/sun"),
                ob->query("tattoo/tattoo_str"));

                sp += sprintf(HIW "�� �� �� �� " NOR + WHT " [%3d]    ["
                      HIG "%3d" NOR + WHT "]    [" HIW "%3d" NOR + WHT "]    ["
                      HIR "%3d" NOR + WHT "]    [" HIM "%3d" NOR + WHT "]    ["
                      HIB "%3d" NOR + WHT "]\n",
                ob->query("int") - ob->query("gift/int/succeed") - ob->query("gift/water"),
                ob->query("int"),
                ob->query("gift/int/succeed"),
                ob->query("gift/int/fail"),
                ob->query("gift/water"),
                ob->query("tattoo/tattoo_int"));

                sp += sprintf(HIW "�� �� �� �� " NOR + WHT " [%3d]    ["
                      HIG "%3d" NOR + WHT "]    [" HIW "%3d" NOR + WHT "]    ["
                      HIR "%3d" NOR + WHT "]    [" HIM "%3d" NOR + WHT "]    ["
                      HIB "%3d" NOR + WHT "]\n",
                ob->query("con") - ob->query("gift/con/succeed") - ob->query("gift/lighting"),
                ob->query("con"),
                ob->query("gift/con/succeed"),
                ob->query("gift/con/fail"),
                ob->query("gift/lighting"),
                ob->query("tattoo/tattoo_con"));

                sp += sprintf(HIW "�� �� �� �� " NOR + WHT " [%3d]    ["
                      HIG "%3d" NOR + WHT "]    [" HIW "%3d" NOR + WHT "]    ["
                      HIR "%3d" NOR + WHT "]    [" HIM "%3d" NOR + WHT "]    ["
                      HIB "%3d" NOR + WHT "]\n",
                ob->query("dex") - ob->query("gift/dex/succeed") - ob->query("gift/feng"),
                ob->query("dex"),
                ob->query("gift/dex/succeed"),
                ob->query("gift/dex/fail"),
                ob->query("gift/feng"),
                ob->query("tattoo/tattoo_dex"));
                
                sp += sprintf(HIW "�� �� ò �� " NOR + WHT " [%3d]    ["
                      HIG "%3d" NOR + WHT "]    [" HIW "%3d" NOR + WHT "]    ["
                      HIR "%3d" NOR + WHT "]    [" HIM "%3d" NOR + WHT "]    ["
                      HIB "%3d" NOR + WHT "]\n",
                ob->query("per") - ob->query("gift/per/succeed") - ob->query("gift/pergive"),
                ob->query("per"),
                ob->query("gift/per/succeed"),
                ob->query("gift/per/fail"),
                ob->query("gift/pergive"),
                ob->query("tattoo/tattoo_per"));

                sp += sprintf(HIW "�� �� Ե �� " NOR + WHT " [%3d]    ["
                      HIG "%3d" NOR + WHT "]    [" HIW "%3d" NOR + WHT "]    ["
                      HIR "%3d" NOR + WHT "]    [" HIM "%3d" NOR + WHT "]    ["
                      HIB "%3d" NOR + WHT "]\n",
                ob->query("kar") - ob->query("gift/kar/succeed") - ob->query("gift/kargive"),
                ob->query("kar"),
                ob->query("gift/kar/succeed"),
                ob->query("gift/kar/fail"),
                ob->query("gift/kargive"),
                ob->query("tattoo/tattoo_kar"));
                
                sp += HIC "��" HIY "����������������������������������������������"
                      "����������������" HIC "��\n" NOR;
                tell_object(me, sp);
                return 1;
        }

        if (! arg)
                ob = me;
        else
        if (wizardp(me) || me->query("couple/child_id") || me->query("private_room"))
        {
                ob = present(arg, environment(me));
                if (! ob || (! ob->is_character() && ! ob->is_owner(me))) ob = find_player(arg);
                if (! ob || (! ob->is_character() && ! ob->is_owner(me))) ob = find_living(arg);
                if (! ob || (! ob->is_character() && ! ob->is_owner(me)) || ! me->visible(ob))
                        return notify_fail("��Ҫ�쿴˭��״̬��\n");

                if (! wizardp(me) && me->query("couple/child_id") != ob->query("id") &&
                    ! ob->is_owner(me))
                        return notify_fail("��Ҫ�쿴˭��״̬��\n");
        } else
                return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

        my = ob->query_entire_dbase();

        if (userp(ob) && (! stringp(my["born"]) || ! my["born"]))
                return notify_fail("��û�г����ţ��쿴ʲô��\n");

        if (my["max_jing"] < 1 || my["max_qi"] < 1)
                return notify_fail("�޷��쿴" + ob->name(1) + "��״̬��\n");

        sp = (ob == me ? "��" : ob->name()) + "Ŀǰ��״̬�������£�\n";
        sp += HIC "��" HIY "����������������������������������������������"
              "����������������" HIC "��\n" NOR;

        sp += sprintf(HIC "�� �� �� �� %s%5d/ %5d %s(%3d%%)"
                      HIC "    �� �� �� �� %s%5d / %5d (+%d)\n",
                status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),
                             my["eff_jing"] * 100 / my["max_jing"],
                status_color(my["jingli"], my["max_jingli"]), my["jingli"],
                             my["max_jingli"], my["jiajing"] );

        sp += sprintf(HIC "�� �� Ѫ �� %s%5d/ %5d %s(%3d%%)"
                      HIC "    �� �� �� �� %s%5d / %5d (+%d)\n",
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]),
                             my["eff_qi"] * 100 / my["max_qi"],
                status_color(my["neili"], my["max_neili"]), my["neili"],
                             my["max_neili"], my["jiali"] );

        sp += sprintf(HIW "�� ʳ �� �� %s%5d/ %5d      " HIW "     �� Ǳ �� ��  %s%s\n",
                status_color(my["food"], ob->max_food_capacity()),
                my["food"], ob->max_food_capacity(),
                count_ge(ob->query("potential"), ob->query_potential_limit()) ? HIM : HIY,
                count_sub(ob->query("potential"), ob->query("learned_points")));

        sp += sprintf(HIW "�� �� ˮ �� %s%5d/ %5d      " HIW "     �� �� �� ��  %s%d\n",
                status_color(my["water"], ob->max_water_capacity()),
                my["water"], ob->max_water_capacity(),
                my["experience"] >= ob->query_experience_limit() ? HIM : HIY,
                my["experience"] - my["learned_experience"]);

        if (craze = me->query_craze())
        {
                if (me->is_most_craze())
                        sp += HIR "�� �� " BLINK "ŭ" NOR HIR " ��  " +
                              sprintf("%-22s", me->query("character") == "��������" ?
                                               "�������" : "ŭ������");
                else
                        sp += sprintf(HIR "�� �� ŭ �� %5d/ %5d (+%-3d)    ",
                                      craze, me->query_max_craze(),
                                      me->query("jianu"));
        } else
        {
                sp += HIC "�� ƽ �� ��  ������������������    ";
        }
        sp += sprintf(HIW "�� �� �� ��  " HIC "%s\n", count_add(my["combat_exp"], 0));
        sp += HIC "��" HIY "����������������������������������������������"
              "����������������" HIC "��\n" NOR;
        tell_object(me, sp);
        return 1;
}
 
string status_color(int current, int max)
{
        int percent;
 
        if (max > 0)
                percent = current * 100 / max;
        else
                percent = 100;

        if (percent > 100) return HIC;
        if (percent >= 90) return HIG;
        if (percent >= 60) return HIY;
        if (percent >= 30) return YEL;
        if (percent >= 10) return HIR;
        return RED;
}
 
int help(object me)
{
        write(@HELP
ָ���ʽ��hp [-m] [-g]
          hp [-m] [-g] <��������>               ����ʦר�ã�

���ָ�������ʾ���ָ������ľ�����������ֵ�������� -m ��
�������ϸ���г�������ֵ�������Ч��ֵ�������� -g �������
��ϸ���г�����츳����״̬�����С�ԭʼ��ָ����Ͷ̥��ת������
�������߱���ԭʼֵ�������졻����ָ�����������Ե���ֵ������
���Կ���ͨ���Ե����Ǽ��������Ի�������������ɹ����͡�ʧ�ܡ�
��ָ���������������������ɵ���Ч���������¡���ָ���Ƿ�������
Ϸ��ͨ��ĳЩ������������Ӧ���������ԡ����ġ�ת�������ʾ��
�Ƿ�ͨ����ת�����;���������˺������ԡ�

���ָ�score
HELP);
        return 1;
}
