//Room: /d/dali/hongsheng2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ʥ����");
        set("long", @LONG
�����Ǻ�ʥ�����ڲ�������ǽ���϶����з��裬�����÷���̧ͷ��������
�Կ�������������«����ɡ�ǡ����ּ��������еȡ�ɡ�ǳɰ˽��Σ����Ϲ��з�
�졣
LONG );
	set("exits",([ /* sizeof() == 1 */
	    "down"   : "/d/dali/hongsheng1",
	    "up"     : "/d/dali/hongsheng3",
	]));
	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        string c_exp;
        int c_skill;
	if (dir == "up" )
	{
                c_exp   = me->query("combat_exp");
		c_skill = (int)me->query_skill("dodge",1);
                if (me->query("qi") > 20)
                {
        		me->receive_damage("qi", 20);
                        if ((count_lt(count_div(count_mul(count_mul(c_skill, c_skill),c_skill), 10), c_exp)) && (c_skill<101))
        		me->improve_skill("dodge", (int)me->query_skill("dodge", 1) / 5);
        		tell_object(me,"������һ��¥����Щ���ˡ�\n");
                } else
                {
                        me->set("qi", 0);
        		tell_object(me,"�������������ˡ�\n");
                        return 0;
                }
	}
	return 1;
}
