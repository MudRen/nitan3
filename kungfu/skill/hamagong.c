// hamagong.c ��󡹦
// Update By Qdz

#include <ansi.h>
inherit FORCE;

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("hamagong", 1);
        return lvl * lvl * 15 * 22 / 100 / 200;
}

mapping *action = ({
([      "action" : "$N����������һ�ֳŵأ����Ӻ�ͦ��ֻ��һ����$n��$l�ĳ�",
        "dodge"  : 0,
        "force"  : 310,
        "attack" : 103,
        "parry"  : 21,
        "damage" : 58,
        "lvl"    : 0,
        "damage_type": "����" 
]), 
([      "action" : "$N˿��������ɫ��˫��΢��������ƽ�죬���������󡹦��"
                   "����������һ������$n",
        "dodge"  : 0,
        "force"  : 332,
        "attack" : 112,
        "parry"  : 37,
        "damage" : 61,
        "lvl"    : 250,
        "damage_type": "����"
]), 
([      "action" : "$N���۱�ס����������Ƭ�̣���Ծ�����۾�Ҳ����������˫"
                   "�Ʊ���$n�ķ������˳�ȥ",
        "dodge"  : 0,
        "force"  : 360,
        "attack" : 122,
        "parry"  : 53,
        "damage" : 72,
        "lvl"    : 260,
        "damage_type": "����"
]),
([      "action" : "$N�Ų�ҡҡ�ϻϣ���Ȼ˫��һ�䡢һ�ǣ����и��һ���кȣ�"
                   "������$n��Ȼ�Ƴ�",
        "dodge"  : 5,
        "force"  : 410,
        "attack" : 143,
        "parry"  : 67,
        "damage" : 81,
        "lvl"    : 270,
        "damage_type": "����"
]), 
});

mapping *reverse_action = ({
([      "action": "����$N���������������������������һ������ݺݵĳ�$n�˽�����",
	"dodge": -15,
	"parry": -20,
	"force": 300,
	"damage": 60,
	"damage_type": "����"
]),
([      "action":"����$N���Ƹ������������°�ĭ����ͷ��$n��ײ",
	"parry": 15,
	"force": 360,
	"damage": 70,
	"damage_type": "����"
]),
([      "action":"$N����ſڣ�����һ��������$n$lҧ�䣬�ֿ���׼",
	"dodge": -5,
	"force": 420,
	"damage": 80,
	"weapon": "����",
	"damage_type": "ҧ��"
]),
([      "action":"$Nһ����ĭ���£���Ю���磬����̵����ĭҲ�����˹�������",
	"dodge": -45,
	"force": 480,
	"damage": 90,
	"weapon":"��ĭ",
	"damage_type": "����"
]),
([      "action":"$N��Ȼ���죬һ����ĭ��$n������ȥ�����ƻ���$n���ܵķ�λ��ͬʱ����һ��Ũ̵�½�����",
	"dodge": 30,
	"force": 540,
	"damage": 100,
	"weapon" : "Ũ̵",
	"damage_type": "����"
]),
([      "action":"��ʱ$N��ʹ����������ϣ��Ź֣�������ף�����ʱ��������ʱ��ֱ������Ȼһ�ֳŵأ����Ӻ�ͦ��һ�ֳ��ƴ���$n$l",
	"dodge": 10,
	"force": 600,
	"damage": 110,
	"damage_type": "����"
]),
});

int valid_enable(string usage)
{ 
	if (usage == "force" || usage == "parry" ) return 1;
	if (usage == "strike") {
		if (this_player()->query_skill("hamagong",1) < 200) {
			message_vision("$N�������������й������Ľ��˼�����Ҫ����󡹦�ھ�����ȭ��֮�ϣ����������ʹ�ò��ϡ�\n", this_player() );
			write("��ĸ�󡹦����㣬�޷����������Ʒ��С�\n");
			return 0;
		}
		return 1;
	}
	return 0;
}

int can_not_hubo() {return 1;}

int valid_learn(object me)
{
        mapping skl; 
        string *sname;
        int v, i, k=0;

        if (me->query("character") == "��������"
           || me->query("character") == "������")
                return notify_fail("�����а��������󡹦�����쳣�����ƻ��˼���"
                                   "�����Ǳ���Ϊ�\n");

        /*
        if ((int)me->query("con") < 32)
                return notify_fail("����������������޷�������󡹦��\n");

        if ((int)me->query("dex") < 32)
                return notify_fail("��������̫��޷�������󡹦��\n");
        */
                                                   
       if ( me->query("gender") == "����" && me->query("hamagong", 1) > 49)
                return notify_fail("���޸����ԣ���������������������ĸ�󡹦��\n");

        /*
        if ((int)me->query_skill("poison", 1) < 50)
                return notify_fail("��Ļ�����������㣬��������󡹦��\n");
        */

        i = (int)me->query_skill("hamagong", 1);

        if ((int)me->query_skill("force", 1) < 30
         || (int)me->query_skill("force", 1)/2 < i/3 )
                return notify_fail("��Ļ����ڹ�����㣬����ѧ��󡹦��\n");

        if (this_player()->query("tianmo_jieti/times")) 
                return ::valid_learn(me);

        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("hamagong", 1) > 99){

                for(v=0; v<sizeof(skl); v++) {
                        if (SKILL_D(sname[v])->check() == "force")
                        k++;  
                }
                if ( k >=3 )
                return notify_fail("�����ڲ�ͬ���������ײ����������������ڹ���\n");
        }

        if ( me->query("class")=="bonze" )
        {
                if (me->query("gender")=="Ů��")
                        return notify_fail("С�������󡹦�����±��˽���ͺͷ�����\n");
                if (me->query("gender")=="����")
                        return notify_fail("��ʦ������󡹦�����±��˽���ͺͷ�����\n");
        }

        if ( me->query("family/family_name") == "ؤ��" )
                return notify_fail("�Ͻл���ͽ��ѧ���˸�󡹦��\n");

        if ( me->query("family/family_name") == "�䵱��")
                return notify_fail("�ϵ�����󡹦�����±��˽���ţ���Ӹ����\n");

       return ::valid_learn(me);
}

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
	int i, level;
	string *power_msg = 
	({
		HIR"$N���������������󡹦��˫��ƽ�ƣ�������ü�����������к���������֮�����з缲��Ѹ���;���ʵ�Ƿ�ͬС��"NOR,
		WHT"$N�������ŭ�𣬶�������������˫�����������δ�����Ʒ��ѽ����³�������һ�ɾ���ֱ��$n���ţ��Ƶ���ǿ�ޱ�"NOR,
		HIR"$N��ɫ���������������鼡��΢΢ǣ�����������������һ����У�˫��ͦ����һ�ɾ������ֱײ�ĳ�$n�ƽ�����"NOR,
		WHT"$N�׵����ӣ����й������Ľ���������˫���Ƴ����Ը�󡹦��$n�͹���$n������$P��������֮�£�ֻ���û�����������������"NOR,
	});
	string *reverse_msg = 
	({
		HIM"����$N�������أ��������ף������������Լ�������ץһ�ѣ������������Լ����Ϻ���һ�ţ�ÿһ�ƴ򽫳�������;����ر䣬ʵ��֪�򽫺δ�"NOR,
		HIM"$N��Ȼ���������������Լ��������⣬��һ����˫�־ݵأ�����$n�����ط���һ������Ȼ�����Ծ��˫����$n��������"NOR,
		HIM"ͻȻ֮�䣬$N������������ȫȻ���أ����й����ޱȣ�����󡹦��ת���ã�������֮��������֮����������׽��"NOR,
		HIM"$Nȫ������˳���棬����������Ȼ���˴�������Ǵ��д��ţ����ֵֹ�������$n����ѽ�"NOR,
	});

	level   = (int) me->query_skill("hamagong",1);

	if (me->query_skill_mapped("force") == "hamagong" ) {
		if ( !me->query_temp("hmg_dzjm") && me->query_temp("powerup") && random(me->query_skill("force")) > 250 && me->query("neili") > 1000 && me->query("jiali") > 100)
			return ([
			"action": power_msg[random(sizeof(power_msg))],
			"dodge": 20,
			"parry": 20,
			"force": 650+random(100),
			"damage": 120,
			"damage_type": random(2)?"����":"����"
			]);
		else if ( me->query_temp("reverse") && random(me->query_skill("force")) > 400  && random(me->query_skill("strike")) > 300 && me->query("neili") > 1000 )
			return ([
			"action": reverse_msg[random(sizeof(reverse_msg))],
			"dodge": 100,
			"parry": 100,
			"force": 630+random(100),
			"damage": 120+random(20),
			"damage_type": "����",
			]);
	}
	if ( me->query_temp("hmg_dzjm") )
		return reverse_action[random(sizeof(reverse_action))];
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if (me->query("family/master_id") != "ouyang feng"
	&& me->query_skill("hamagong", 1) > 99)
		 return notify_fail("��󡹦�����ָ����ܼ�����ߡ�\n");
		 
	if (me->query_temp("weapon"))
		 return notify_fail("���Ӳ��ֱֳ��У���������󡹦Ҳ������֡�\n");
		 
	if ((int)me->query("jing") < 50)
		return notify_fail("��ľ�����������󡹦��\n");
		
	if ((int)me->query("neili") < 100)
		return notify_fail("���������������󡹦��\n");
		  me->add("neili", -30);
		  me->receive_damage("jing", 10);
	if (me->query_skill("hamagong", 1) > 100){
		me->add("neili", -40);
		  me->receive_damage("jing", 20);
	}
	if (me->query_skill("hamagong", 1) > 150){
		  me->add("neili", -20);
		  me->receive_damage("jing", 10);
	}
	if (me->query_skill("hamagong", 1) > 200){
		  me->add("neili", -10);
		  me->receive_damage("jing", 10);
	}
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("hamagong", 1);

        if (damage_bonus < 150
           || lvl < 180
           || me->query("neili") < 300
           || me->query_temp("weapon")
           || me->query_temp("secondary_weapon")
           || me->query_skill_mapped("force") != "hamagong"
           || me->query_skill_mapped("unarmed") != "hamagong"
           || me->query_skill_prepared("unarmed") != "hamagong")
                return 0;

        if (damage_bonus / 6 > victim->query_con())
        {
                me->add("neili", -30);
                victim->receive_wound("qi", (damage_bonus - 90) / 3, me);
                return WHT "$n" WHT "Ӳ����$N" WHT "һ�ƣ���ʱȫ"
                       "��һ���������������һ����Ѫ��\n" NOR;
        }
}

string exert_function_file(string func)
{
        return __DIR__"hamagong/exert/" + func;
}

string perform_action_file(string action)
{
	return __DIR__"hamagong/perform/" + action;
}
mapping curing_msg(object me)
{
        return ([
"apply_short" :me->name()+"��ͷ֧�ڵ��ϣ�˫�Ų�£��������ա�",
"start_self" :HIW"�㵹ת���壬��ͷ֧�أ�˫�Ų�£��������գ������󡹦��ת�ķ����ˡ�\n"NOR,
"on_self" :HIM"�㵹����Ϣ���������ߣ��о����ƴ�����ɫ��\n"NOR,
"start_other" :HIM""+me->name()+"��ɫ������ͷ�½��ϵ����ţ���������ɢ����һ�ɺ�����\n"NOR,
"finish_self" :HIW"��е�ȫ������ͨ�����裬�ֽ�һ�����͵�Ծ��\n"NOR,
"finish_other" :me->name()+"����һ���ֽ�һ����ͻȻԾ�𣬺���Ҳ��֮����ɢȥ��\n",
"unfinish_self" :"��������ת�������ˣ�ͻȻ�е������Ҵܣ��ų�һ���亹��ֻ��ͣ��������\n",
"unfinish_other":me->name()+"��Ȼ����˫�ۣ�����վ�𣬵���ɫ����������\n",
"halt_self" :"�㽫���ߵ�����ѹ�ص��˫���ŵأ�վ��������\n",
"halt_other" :me->name() +"�������������ڣ�վ�������������ƺ����Ϻ��˲��١�\n",
        ]);
}
