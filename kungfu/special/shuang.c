// shuang.c ��ʿ��˫
// Created by Lonely

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIY "��ʿ��˫" NOR; }

int perform(object me, string skill)
{
        return notify_fail("�������߳Ǹ�������������Լ������ԣ�\n"
                           "���˴�Ħ��͸������������������������\n"
                           "�������������书�й������Ե����ơ�\n");
}


