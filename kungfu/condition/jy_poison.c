#include <ansi.h> 
#include <condition.h> 

inherit F_CLEAN_UP; 
inherit POISON; 

string name() { return "jy_poison"; } 
string chinese_name() { return "�����׹�צ��"; } 

string update_msg_others() 
{
       return BLU "$N" BLU "ͻȻֻϥ�����������������£����з��������ƹ�ĺɺ�֮����\n" NOR; 
}

string update_msg_self() 
{
       return BLU "���Ȼ�е����彩ֱ���Ѿ�����ʹ���ˡ�\n" NOR; 
}
