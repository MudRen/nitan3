// team command: form

#include <ansi.h>

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string target;
        object *t;

        if (! pointerp(t = me->query_team()) || ! me->is_team_leader())
                return notify_fail("�������һ����������������֯���Ρ�\n");

        if (sscanf(arg,"%s to %s",arg,target) != 2)
                target = "no enemy";

        if (! me->query_skill(arg, 1))
                return notify_fail("����������ûѧ����\n");
        if (target == "no enemy")
                return SKILL_D(arg)->form_array(me);
        else
                return SKILL_D(arg)->form_array(me,target);
}

