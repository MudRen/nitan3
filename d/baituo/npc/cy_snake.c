// Code of JHSH
// cy_snake.c ����(���ݣ����ݸ�Ŀ)
// by maco

#include <ansi.h>

inherit SNAKE;

int auto_perform_duwu();

void create()
{
	int poison = 10;
        set_name(HIR"����"NOR, ({ "chi yan", "she", "snake" }) );
	set("long", "����һ������ͨ��Ķ��ߣ��������磬ϸС��ָ��\n�γ�ʱ�������Ȫ���η��֣��綾�ޱȣ���˵���Ǳ���ҧ�����߲�������\n");
	set("age", 100);
	set("attitude", "aggressive");

	set_weight(8000);

	set("str", 30 + poison );
	set("con", 30 + poison );
	set("int", 20);
	set("dex", 30 + poison );

	set("max_jing", 10000);
	set("max_qi", 12000);
	set("qi", 12000);
	set("max_jingli", 10000);

	set("combat_exp", 2000000);

	set_temp("apply/attack", 500);
	set_temp("apply/damage", 300);
	set_temp("apply/dodge", 400);
	set_temp("apply/armor", 200);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: auto_perform_duwu :),
	}));

        set("snake_poison", ([
                "level"  : 45,
                "perhit" : 25,
                "remain" : 45,
                "maximum": 45,
                "supply" : 2,
        ]));
	set("bt_snake", 1);

	setup();
}


#include "snake_perform.h"
