// heal.c
// Updated by Lonely

// �ο���������
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **\
 * heal.c �ڹ��������˹���                                              *
 *                                                                      *
 * �ڹ�Ӧ��ӵ�м��ֹ��еĹ��ܣ������еĴ��������š��������˾����˾����� *
 * �Լ������еı�ƴ������������ת��Ϣ��������ҲӦ���������ڹ���Ӧ���е� *
 * ���ܡ�                                                               *
 * ��̶���е��˺�ϵͳ�������˺�������ȫû�����������������������£��� *
 * �ڹ��ߣ�������Ȼ���׺á�����ȴδ�أ��ֲ�����һ�ˣ����������������� *
 * ����������ˡ����������ڴ󲿷������ֻ�ܽ��������ҩ��ĸ��������ơ� *
 * ��������ͨ���˶�����ͨ����ת��Ϣ�����ƣ������߲���춲�ͬ�ڹ�������� *
 * ����Ч���ĺû��������������Խ�أ�Ч��ԽС��������ǰ������һ�ζ����� *
 * �����͹̶��ָ����١�ͨ�����˵Ŀ�����������ӿ������ٶȡ������˵Ŀ��� *
 * �ٶȣ������ȡ���������Ƶĳ̶ȣ�����ҩ���ҩ�ԣ��Լ�����ļ��⹹�죬 *
 * Ҳ������̶�����constitution��                                       *
 * ����������ֳ������˵Ĳ�ͬ����������̶���˺�ϵͳ���ø������ԣ���Щ�� *
 * �Ժ���Ҫ�ı�ģ�������Ҫ˵����ֻ�����¹���ֻ����������Ϊǰ�ῼ�ǣ��� *
 * �Ի��������̶���е��˺�ϵͳ��������Ĳ������ԡ�                     *
 *                                                                      *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/


#include <ansi.h>

mapping eff_heal = ([
        "yinyang-shiertian"     : 21,   // ת�����ܣ���ǿ���ڹ���
        "jiuyin-shengong"       : 10,   // ����ʦ�ڹ���ǿ��
        "bluesea-force"         : 10,   // ����ʦ�ڹ���ǿ��
        "never-defeated"        : 10,   // ����ʦ�ڹ���ǿ��
        "kuihua-mogong"         : 10,   // ����ʦ�ڹ���ǿ��
        "jiuyang-shengong"      : 9,    // �����������˷����Ч���޿����ɡ�
        "taixuan-gong"          : 9,    // �ο������񹦡�
        "yijinjing"             : 9,
        "hunyuan-yiqi"          : 8,    // ����׽�Լ������������˷����Ч����
        "zixia-shengong"        : 8,    // ��ϼ�񹦼���Ԫ�������Ʒ���û��ʲô�ἰ�������м�
                                        // ������˵�Ч�����Լ�����Ⱥ���������������ϰ��ϼ
                                        // �����������ˣ��ɼ�����Ʒ����Ч�������������
                                        // �׽���������������������������ǵ�������ϼ��
                                        // û��ʲô�ر�� exert��ҲӦ������ϼ�������Ʒ���
                                        // ��Ч�����������ڹ����á�
        "taiji-shengong"        : 8,
        "xiantian-gong"         : 8,    // �������൱ƪ���ᵽ�䵱��������ȫ�������ڹ������ˡ�
        "kurong-changong"       : 7,    // �����ڹ������˷����Ч���ܺã����������Ʒ���ȴû
                                        // ��ʲô�ر�֮����
        "linji-zhuang"          : 7,    // �����ڹ������˷���û��ʲô�ر����������������Ǿ�
                                        // ��һϵ��
        "bibo-shengong"         : 6,
        "yunu-xinfa"            : 6,
        "xiaowuxiang"           : 5,
        "sanku-shengong"        : 5,    // �����񹦣�Ϊ�����ڹ�������һ��,���ƶ����泬ǿ��
        "huntian-qigong"        : 4,    // ���칦����󡹦������������ߵĶ��Ǹ���һ·���ڹ���
        "hamagong"              : 4,    // ��������˷���������Щ��
        "longxiang-gong"        : 4,
        "beiming-shengong"      : 3,    // ��ڤ������������������������Ӱ������ʱ��Ч����
        "huagong-dafa"          : 2,    // �������Զ������������˷���Ч��Ӧ����Ϊ���á�
        "dulong-dafa"           : 2,
        "hongming-xuangong"     : 1,
        "ding-force"            : 1,    // ���������ڹ�����δ���ἰ������Ϊ���ɿ���
]);


int exert(object me, object target)
{
        string force;
        mapping msg;

        if (me->is_fighting())
                return notify_fail("ս�����˹����ˣ�������\n");

        if (me->is_busy())
                return notify_fail("����æ������ͷ��������˵��\n");

        force = me->query_skill_mapped("force");
        if (! stringp(force))
                return notify_fail("�ȼ�����������ڹ���\n");

        if ((int)me->query("eff_qi") >= (int)me->query("max_qi"))
                return notify_fail("��������Ѫ��ӯ������Ҫ���ˡ�\n");

        if ((int)me->query_skill(force, 1) < 20)
                return notify_fail("���" + to_chinese(force) + "��Ϊ��������\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("�������������\n");

        if ((int)me->query("eff_qi") < (int)me->query("max_qi") / 5)
                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
        
        msg = SKILL_D(force)->heal_msg(me);
                
        if (! msg || undefinedp(msg["start_self"]))
	        write(HIW "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
        else 
                write(msg["start_self"]);               

        me->set_temp("pending/healing", 1);
        
        if (! msg || undefinedp(msg["apply_short"]))
                me->set_short_desc("�����ڵ����˹����ˡ�");                
        else    
                me->set_short_desc(msg["apply_short"]);

        if (! msg || undefinedp(msg["start_other"]))
		tell_room(environment(me), HIW + me->name() + "��ϥ���£���ʼ�˹����ˡ�\n" NOR, me);
        else
		tell_room(environment(me), msg["start_other"], me); 
		                
        me->start_busy((:call_other, __FILE__, "healing" :),
                       (:call_other, __FILE__, "halt_healing" :));

        return 1;
}

// ������
int healing(object me)
{
        string force;
        int recover_points, lvl, con, eff;
        mapping msg;

        force = me->query_skill_mapped("force");
        if (! stringp(force))
        {
                // û�������ڹ��ˣ�
                tell_object(me, "��һʱ���Զ����������������ֻ������ͣ���ˡ�\n");
                me->set_temp("pending/healing", 0);
                me->set_short_desc(0);
                message_vision("$N̾�˿�����ҡҡ�λε�վ��������\n", me);
                return 0;
        }
        
        msg = SKILL_D(force)->heal_msg(me);

        if (me->query("eff_qi") < me->query("max_qi"))
        {
                // ��Ҫ��������
                if (me->query("neili") < 50)
                {
                        if (! msg || undefinedp(msg["unfinish_self"]))
                                tell_object(me, "������������ã������ھ����м�����ת���ˣ�ֻ���ݻ����ˣ�վ��������\n");
                        else    
                                tell_object(me, msg["unfinish_self"]);
                                
                        me->set_temp("pending/healing", 0);
                        me->set_short_desc(0);
                        
                        if (! msg || undefinedp(msg["unfinish_other"]))
                                tell_room(environment(me), me->name() + "̾�˿�����ҡҡ�λε�վ��������\n", me);
                        else    
                                tell_room(environment(me), msg["unfinish_other"], me);
                                
                        return 0;
                }
                
                lvl = (int)me->query_skill("force") / 10;
                con = (int)me->query_con();
                eff = eff_heal[force];
                if (! eff ) eff = 3;

                recover_points = con + lvl * eff;
                if (me->query("breakup"))
                        recover_points *= 3;
                me->receive_curing("qi", recover_points);                                
                me->add("neili", -50);
                
                if (! msg || undefinedp(msg["heal_msg"]))
                {
                        switch (random(10))
                        {
                        case 0:
                                tell_object(me, "������" + to_chinese(force) + "����"
                                                "���Ѩ������ת���ƽ���ʹ��\n");
                                break;
                        case 1:
                                tell_object(me, "�㽫�������뵤������г嶥��͸�๬"
                                                "���پ�����ˬ�졣\n");
                                break;
                        case 2:
                                tell_object(me, "�㽫����������֫���࣬���ֻ��յ��"
                                                 "����Ȭ�����١�\n");
                                break;
                        }
                        return 1;
                } else
                {
                        tell_object(me, msg["heal_msg"]);
                        return 1;
                }
        }

        // �ָ����
        me->set_temp("pending/exercise", 0);
        me->set_short_desc(0);
        if (! msg || undefinedp(msg["finish_self"]))
                tell_object(me, HIY "���˹���ϣ��³�һ����Ѫ���Ծ�����˳�������˾�ȥ����Ԫ�����վ��������\n" NOR);
        else    
                tell_room(me, msg["finish_self"]); 
                
        if (! msg || undefinedp(msg["finish_other"]))
                tell_room(environment(me), HIY + me->name() + "�˹���ϣ��³�һ����Ѫ��վ����������ɫ�������ö��ˡ�\n" NOR, me);
        else
                tell_room(environment(me), msg["finish_other"], me);      
                
        return 0;
}

// ֹͣ����
int halt_healing(object me)
{
        string force;
        mapping msg;
        
        if (stringp(force = me->query_skill_mapped("force"))) 
                msg = SKILL_D(force)->heal_msg(me);
        
        if (! msg || undefinedp(msg["halt_self"]))
                tell_object(me, "�㽫�����ջص��΢΢��Ϣ��վ��������\n");
        else    
                tell_object(me, msg["halt_self"]);
                
        if (! msg || undefinedp(msg["halt_other"]))
                tell_room(environment(me), me->name() + "�͵���һ������ͻȻվ��������\n", me);
        else    
                tell_room(environment(me), msg["halt_other"], me);
                
        me->set_temp("pending/healing", 0);
        me->set_short_desc(0);
        if (me->query("neili") > 100)
                me->add("neili", -100);
        else
                me->set("neili", 0);
        return 1;
}
