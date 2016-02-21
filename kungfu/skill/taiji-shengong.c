// Created by Lonely
// taiji-shengong.c ̫����

#include <ansi.h>

inherit FORCE;

int valid_force(string force) { return 1; }       

int query_neili_improve(object me)  
{
        int lvl; 
        lvl = (int)me->query_skill("taiji-shengong", 1); 
        return lvl * lvl * 22 * 15 / 100 / 200; 
}

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("taiji-shengong", 1);


        if (me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ����������������������̫���񹦡�\n");

        if (me->query("class") == "bonze" )
                return notify_fail("̫���񹦽����������ϣ���Υ��������徻֮�⣬"
                        + RANK_D->query_respect(me) + "���޴˹������������\n");

        if (lvl > 10 && (int)me->query("shen") < lvl * 100
             && me->query_skill("taoism", 1) < 100) 
                return notify_fail("�����������̫���ˡ�\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("̫����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"taiji-shengong/" + func;
}


mapping curing_msg(object me)
{
        return ([
                "apply_short"   : "����һ�Դ����붨��ͷ�������뵰���������������",
                "start_self"    : "Ǳ��������������Ѩ����ת���ˣ�������Ϣ��\n",
                "start_other"   : "��Ŀ���£�Ƭ��֮ʱ��ͷ��ð��˿˿������\n",
                "finish_self"   : "ֻ����Ϣ��ת˳�������������ϵ��վ��������\n",
                "finish_other"  : "�Ұ׵���ɫ�������󣬻��������ۣ�վ��������\n",
                "unfinish_self" : "���������������󾢲��̣����ò��������ڰ��˵���Ϣ�ջء�\n",
                "unfinish_other": me->query("eff_qi") < me->query("max_qi") * 3 / 4 ?
                                  "�͵����һ�ţ����������Ѫ��\n" :
                                  "�͵����һ�ţ��³����Ϻ���Ѫ��\n",
        ]);
}

                

