#include <ansi.h> 
#include <condition.h> 

inherit F_CLEAN_UP; 
inherit POISON; 

string name() { return "qs_poison"; } 
string chinese_name() { return "����ȭ����"; } 

string update_msg_others() 
{
       return HIW "$N" HIW "ͻȻ����һ�Σ��������������ص����ˣ�\n" NOR; 
}

string update_msg_self() 
{
       return HIW "����»�㱣������ܼ��У��������������������ˣ�\n" NOR; 
}
