// Lamaism.c
// by Lonely

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        int lvl;
        
        lvl = (int)me->query_skill("lamaism", 1);

        if (me->query("class") != "bonze" && me->query("family/family_name") != "���ϻ���" && lvl > 39)
                return notify_fail("��δ����ţ���Ե���ϣ��޷������޳������񷨡�\n");

        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("�����ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}

