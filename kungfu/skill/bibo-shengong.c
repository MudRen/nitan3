// bibo-shengong.c �̲���
// By Jungu
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int query_neili_improve(object me)
{
    int lvl;

    lvl = (int)me->query_skill("bibo-shengong", 1);
    return lvl * lvl * 15 * 10 / 100 / 200;
}

int valid_force(string force)
{
    return 1;
    return (force == "luoying-xinfa");
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("bibo-shengong", 1);

	if (me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ�������������"
                                   "��������ı̲��񹦡�\n");

/*
        if (me->query_skill("chuixiao-jifa", 1) < 100)
                return notify_fail("��û�о�ͨ���＼�����޷�"
                                   "���̲��񹦵İ��ء�\n");
*/

	return ::valid_learn(me);
}

int practice_skill(object me)
{
    return notify_fail("�̲���ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
    return __DIR__"bibo-shengong/" + func;
}

mapping curing_msg(object me)
{
        return ([
"apply_short"	:me->name()+"��̤�����Է�λ�����������ˡ�",
"start_self"    :HIY"���������񣬽��»���̤����Է�λ����ʼ���ñ̲��񹦵������ơ�\n"NOR,
"on_self"   :HIG"����»���̤�����Է�λ�������������оŹ���һ��Ǳ�˱̲��񹦵������ơ�\n"NOR,
"start_other"	:HIG""+me->name()+"�����߶��������ɼ��ٽ���ת���Ƴ�����������ʱ��ʱ�֡�\n"NOR,
"finish_self"	:HIY"�㻺�����߶�ʱ���Ծ�����˳�������˾�ȥ���ڶ�����ľ֮λͣ���˲�����\n"NOR,
"finish_other"	:me->name()+"�����ѱϣ���������һ�����ˣ�ͣ�½Ų�������ȥ��ɫ�����������ӡ�\n",
"unfinish_self"	:"���������Ų�������������������Ϣ��̷��������ͣ�½Ų����ݻ����ˡ�\n",
"unfinish_other":me->name()+"ͣ�½Ų��������������ˣ���ɫ�������ö��ˡ�\n",
"halt_self"	:"��������Ϣ��Ӳ�����ؽ���Ϣѹ����ȥ��ͣ���˽Ų���\n",
"halt_other"	:me->name() +"����ͣ�²���������һ���³�һ����Ѫ������������֮ɢ�ݡ�\n",
"dazuo"		:"������۾�����̤���ԣ������幬�����г����䣬��Ϣ������\n",
"tuna"		:"�㻺���غ������������д��˳���ӿ���ȣ�����ȴ����һƬ��������ܡ�\n",
        ]);
}
