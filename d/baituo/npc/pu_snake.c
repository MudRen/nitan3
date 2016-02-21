// Code of ShenZhou
// pu_snake.c ��˹����
// by maco

#include <ansi.h>

inherit SNAKE;

void create()
{
	set_name("��˹����", ({ "pusiqu she", "snake", "she", "pusiqu" }) );
	set("age", 100);
	set("long", "�������Ͻ��������ͷ��������ǣ���״ʮ�ֹ��졣\n�������м��أ���Ϊ��˹���ߣ���˵����������磬���Ѳ�׽��\n");
	set("attitude", "peaceful");

        set_weight(13800);
	set("str", 28 );
	set("con", 38 );
	set("int", 20);
	set("dex", 38 );

	set("max_jing", 4000);
	set("max_qi", 4000);
	set("max_jingli", 4000);


	set("combat_exp", 1000000);

	set_temp("apply/attack", 150);
	set_temp("apply/damage", 150);
	set_temp("apply/dodge", 200);
	set_temp("apply/armor", 150);

        set("snake_poison", ([
                "level"  : 150,
                "perhit" : 50,
                "remain" : 80,
                "maximum": 80,
                "supply" : 3,
        ]));
	set("bt_snake", 1);
        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��", "���" }) );
        set("verbs", ({ "bite" }) );

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && !is_fighting()
	     && random(ob->query_kar()) < 25) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}
}

void unconcious()
{	
	if(random(4) == 0 ) {
		message_vision("��˹�����������У���һ���㼱�ܶ��ӣ����֮������Ӱ���١�\n", this_object());
		destruct(this_object());
	}
	else {
		this_object()->disable_player(" <���Բ���>");
		this_object()->set("jing", 0);
		this_object()->set("qi", 0);
		COMBAT_D->announce(this_object(), "unconcious");
		call_out("revive", random(100 - query("con")) + 30);
	}
}

void die()
{
	object ob;
	message_vision("$Nȫ��Ť�������ڻ���һ��������ֱ������\n", this_object());
        ob = new(__DIR__"obj/mangshe-dan");
	ob->set("name","��˹���ߵ�");
	ob->set("long", "һö����ɫ���ߵ��������ȳ���\n");
	ob->move(environment(this_object()));
	destruct(this_object());
}

