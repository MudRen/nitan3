// by Lonely

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "snake_poison"; }

string chinese_name() { return "�߶�"; }

string update_msg_others()
{
       return BLU "$N���۷�ֱ������ɪɪ����������\n" NOR;
}

string update_msg_self()
{
        return BLU "$Nʹ���������һ����\n" NOR;
}

