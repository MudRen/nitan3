// upgrade

#include <ansi.h>

inherit F_CLEAN_UP;

#define PERIOD          864
#define PERIOD_POT      20000
#define PERIOD_MAR      12000

int clossing(object me);
int halt_closing(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        int exercise_cost;
        object where;
        
        seteuid(getuid());
        where = environment(me);
        
        if (! arg)
                return notify_fail("��Ҫ����ʲô�书��\n");
        
        if (! me->query_skill(arg) || 
            file_size(SKILL_D(arg) + ".c") < 0)    
               return notify_fail("��Ҫ�������书�����ڻ��㲻����书��\n");
        
        if (! SKILL_D(arg)->is_invent_skill())
               return notify_fail(to_chinese(arg) + "�������Դ��书���޷�ͨ�����ַ�ʽ������\n");  
               
        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

        if (! where->query("no_fight"))
                return notify_fail("��������������̫��ȫ�ɣ�\n");

        if (! where->query("sleep_room"))
                return notify_fail("�����һ���ܹ���Ϣ�ĵط�������\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
                        
        if (count_lt(count_sub(me->query("potential"), me->query("learned_points")), 1000000)) 
                return notify_fail("���Ǳ�ܲ�����û��������\n");

        if (count_lt(me->query("experience"), count_add(me->query("learned_experience"), 600000))) 
                return notify_fail("�����ڻ��۵�ʵս��ỹ̫�١�\n"); 
        
        if ((int)me->query("qi") * 100 / me->query("max_qi") < 90)
                return notify_fail("�����ڵ���̫���ˣ��޷�����������\n");

        if ((int)me->query("jing") * 100 / me->query("max_jing") < 90)
                return notify_fail("�����ڵľ�̫���ˣ��޷�����������\n");

        if ((int)me->query("max_neili") < 4000)
                return notify_fail("������������в��㣬����Ŀǰ������"
                                   "���г�ʱ���������\n");

        if ((int)me->query("neili") * 100 / me->query("max_neili") < 90)
                return notify_fail("�����ڵ�����̫���ˣ��޷�����������\n");

        message_vision("$N��ϥ���£���ʼڤ���˹����չ�����" + to_chinese(arg) + "��\n", me);
        me->set("startroom", base_name(where));
        me->set("doing", "invent");
        me->set("upgrade", arg);
        CLOSE_D->user_closed(me, "invent");
        me->start_busy(bind((:call_other, __FILE__, "closing" :), me),
                       bind((:call_other, __FILE__, "halt_closing" :), me));
        CHANNEL_D->do_channel(this_object(), "rumor",
                              sprintf("����ʦ%s(%s)��ʼ�չ�����%s��",
                              me->name(1), me->query("id"), to_chinese(arg)));

        return 1;
}

int continue_upgradeing(object me)
{
        me->start_busy(bind((:call_other, __FILE__, "closing" :), me),
                       bind((:call_other, __FILE__, "halt_closing" :), me));
        CLOSE_D->user_closed(me);
        tell_object(me, HIR "\n������չ�����" + to_chinese(me->query("upgrade")) + "...\n" NOR);
        return 1;
}

int closing(object me)
{
        int t;
        int tn;
        mixed pot, mar;
        int r;
        int exp_inc;
        string skill;
        
        skill = me->query("upgrade");  
        pot = me->query("potential");
        mar = me->query("experience");
        if (count_le(pot, me->query("learned_points")) 
        ||  count_le(mar, me->query("learned_experience")))
        {
                tell_object(me, "���Ǳ�ܻ����ľ��ˡ�\n");
                message_vision("$N����˫Ŀ����������һ������վ��������\n", me);
                CLOSE_D->user_opened(me);
                CHANNEL_D->do_channel(this_object(), "rumor",
                                      sprintf("��˵%s(%s)����%s����Բ����",
                                      me->name(1), me->query("id"), to_chinese(skill)));
                if (! interactive(me))
                {
                        me->force_me("chat* haha");
                        call_out("user_quit", 0, me);
                }

                return 0;
        }

        if (count_gt(me->add("learned_points", PERIOD_POT / 2 + random(PERIOD_POT)), pot))
                me->set("learned_points", pot);

        if (count_gt(me->add("learned_experience", PERIOD_MAR / 2 + random(PERIOD_MAR)), mar))
                me->set("learned_experience", mar);
                
        t = me->query_temp("last_closing");
        tn = time();
        if (tn - t < 0)
        {
                me->set_temp("last_closing", tn);
                return 1;
        }

        if (tn - t < PERIOD)
                return 1;

        me->set_temp("last_closing", tn);
                
        if (random(10) == 0)
                tell_object(me, "�չ�����" + to_chinese(skill) + "��...\n");
        
        /*
        if ((random(100) < 3) && me->can_improve_neili())
        {
                tell_object(me, HIR "����ڹ��������򣬸е����������ˣ�\n" NOR);
                me->add("improve/neili", 1);
                me->improve_neili(10 + random(20));
        }

        if ((random(100) < 3) && me->can_improve_jingli())
        {
                tell_object(me, HIM "�����ͨ�������򣬸е����������ˣ�\n" NOR);
                me->add("improve/jingli", 1);
                me->improve_jingli(5 + random(10));
        }
        */

        exp_inc = 50 + random(100);
        exp_inc = exp_inc * (100 + me->query_skill("martial-cognize", 1)) / 500;
        exp_inc = exp_inc * (100 + me->query("int")) / 100;
        me->add("combat_exp", exp_inc);
        me->improve_skill("martial-cognize", 800 + random(800));

        tell_object(me, HIY "���" + to_chinese(skill) + "��������\n" NOR);
        me->improve_skill(skill, 5000 + random(1000));
        SKILLS_D->upgrade_skill_power(skill); 

        return 1;
}

int halt_closing(object me)
{
        CLOSE_D->user_opened(me);
        tell_object(me, "����ֹ�˱չ�����" + to_chinese(me->query("upgrade")) + "��\n");
        message_vision(HIY "$N" HIY "���һ��������������һ��������ʱ"
                       "�����������Ĳ���\n\n" NOR, me);

        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + me->name(1) +
                              "����" + to_chinese(me->query("upgrade")) + "��;ͻȻ������");
        return 1;
}

protected void user_quit(object me)
{
        if (! objectp(me) || interactive(me))
                return;

        me->force_me("quit");
}

int help(object me)
{
        write(@HELP
ָ���ʽ : upgrade

�չ������Դ��书��ֻ�����Դ��书�Ժ���ܹ��չ���������Դ��书��
Ҫ�������һ����ȫ���ҿ�����Ϣ�ĵط���������������ǰ��Ҫ��һ��
���Ǳ�ܼ���ʮ����ᣬ�չؿ�ʼ�Ժ���������Ժ����ɫ����Ȼ��
�����У�ֱ�������ֹ����(halt)����Ǳ�ܻ����ľ����ڼ�����ҵ�
���顢�Դ��书����ѧ�������Դ��书��������������

HELP );
        return 1;
}

