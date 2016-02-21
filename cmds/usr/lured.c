// lured.c

#include <ansi.h>
inherit F_CLEAN_UP;

void hunting(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object yr;
        int t;

        if (! mapp(environment(me)->query("resource/quarry")))
                return notify_fail("���￴������Ұ�޳��ֵ����ӡ�\n");
 
        if (! objectp(yr = present("you er", me)) || yr->query_amount() < 1 ||
            ! yr->query("lure"))
                return notify_fail("������û���ն��ˡ�\n");    
                
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ������˵�ɣ�\n");

        if (me->query_temp("hunting"))
                return notify_fail("���ż����ٵȵȣ�\n");

        message_vision(HIG "$N��" + yr->name() + "���ڵ��ϣ�����һ�Ծ����غ��� ����\n" NOR, me);
        yr->add_amount(-1);
        
        t = 3 + random(3);
        
        me->set_temp("hunting", 1);     
        me->set_temp("hunting_env", environment(me));

        me->start_call_out((: call_other, __FILE__, "do_hunting", me :), t);
        me->start_busy(t);

        return 1;
}

void do_hunting(object me)
{
        object obq;
        object env;
        string* temp;
        string str;
        mapping quarry;
        int i, point;

        env = environment(me);
        if (env != me->query_temp("hunting_env"))
        {
                me->delete_temp("hunting");
                me->delete_temp("huning_env");
                return;
        }

        quarry = env->query("resource/quarry");
        temp = keys(quarry);
        i = random(sizeof(temp));

        me->delete_temp("hunting");
        me->delete_temp("hunting_env");

        // ��ü����ж��Ƿ������
        point = quarry[temp[i]];

        if (random(100) >= point)
        {
                write(HIY "����˰���ȴ����������֣����ն��Ѿ����ʣ�ֻ�����ա�\n" NOR);
                return;
        }       
        
        obq = new(temp[i]);
        obq->move(env);
        obq->set("owner", me->query("id"));

        switch(random(4))
        {
                case 0:
                        message_vision(HIG "��һ�����һֻ" + obq->name() + HIG "���˳�������"
                                      "�ն�һ��ҧ�����\n" NOR, me);
                        break;

                case 1:
                        message_vision(HIM "ת�ۼ䣬һֻ" + obq->name() + HIM "ͻȻ���֣���" 
                                       "�ն��̽����\n" NOR, me);
                        break;

                case 2:
                        message_vision(HIW "���ã�һֻ" + obq->name() + HIW "��ҡ��ڵ�����"
                                       "��������ϸ�ش������ն���\n" NOR, me);
                        break;

                default:
                        message_vision(HIC "��ʱ��һֻ" + obq->name() + HIC "���˹�����һ�ڽ�"
                                       "�ն����������ϣ���ò̰��֮����\n" NOR, me);
                        break;
        }

        return;
        
}

int help(object me)
{
        write(@HELP
ָ���ʽ :

        lured <�ն�>���ڵ�ǰ�ص�����ն��ȴ�������֡�
                      ע��һ��ֻ�ܷ�һ���ն���
                     
HELP
    );
    return 1;
}

