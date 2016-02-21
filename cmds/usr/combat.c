// shop.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if (! wizardp(me) && time() - me->query_temp("last_combat") < 10)  
                return notify_fail("ϵͳ�������̾���������� ....\n");   

        me->set_temp("last_combat", time());
        SKILLS_D->query_skill_power(me, arg);
        return 1;
}

int help (object me)
{
        write(@HELP
�鿴�书���ֲ���ֵ
    combat attack             �鿴����������
    combat dodge              �鿴����������
    combat parry              �鿴�м�������
    combat damage             �鿴�˺�������
    combat force              �鿴�ڹ�������
    combat difficult          �鿴�Ѷȵ�����
    combat ultimate           �鿴�ռ����书
    combat expert             �鿴�������书
    combat advance            �鿴�߼����书
    combat normal             �鿴��ͨ���书
    combat public             �鿴�������书
    combat family             �鿴���ɵ��书
    combat private            �鿴�Դ����书
    combat <��������>         �鿴�������书
    combat <��������>         �鿴���书����
    combat <��������>         �鿴�ɼ����书

HELP);
        return 1;
}
