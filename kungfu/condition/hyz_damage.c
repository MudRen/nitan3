// hyz_damage.c ��Ԫ�޼�����
// by Lonely

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON; 

string name() { return "hyz_damage"; } 

string chinese_name() { return "��Ԫ�޼�������"; } 

string update_msg_others() 
{
        return HIW "$N" HIW "����ɫͻȻ��Ϊ�԰ף�ҡҡ��׹���ƺ������˷����ˣ�\n" NOR; 
}

string update_msg_self() 
{
        return HIW "��Ȼ��һ��ͷ��Ŀѣ�������еĻ�Ԫ�޼������˷����ˣ�\n" NOR; 
}

