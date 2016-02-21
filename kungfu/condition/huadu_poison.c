// Code of ShenZhou
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

inherit POISON;

string name() { return "huadu_poison"; }

string chinese_name() { return "���޳涾"; }
string *query_valid_force() 
{ 
        return ({
                "yijinjing",
                "lengyue-shengong",
                "bahuang-gong",
                "beiming-shengong",
                });
}


string update_msg_others()
{
        return HIM "$N" HIB "��Ŀ��ɢ�ң���ɫ�쳣�����Ϸ���һ�������\n" NOR;
}

string update_msg_self()
{
        return HIR "���Ȼ�θ�һ���ʹ�������ڵ����޳涾�����ˣ��������ζ������ĸ����ͣ�\n" NOR;
}

