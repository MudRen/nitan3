// /d/shenlong/npc/yinhuan.c
// ALN Sep / 97

inherit SNAKE;

int snake_attspeed(object);

void create()
{
        set_name("������", ({ "snake", "yinhuan she", "she","yinhuan" }) );
        set("race", "����");
        set("age", 8);
        set("long", "һ��ȫ���������⣬����һȦȦԲ���Ķ��ߡ�\n");
        set("attitude", "peaceful");

        set("str", 29);
        set("cor", 30);

        set("jingli",100);

        set("combat_exp", 10000 + random(5000));
        set_temp("apply/attack", 10 + random(10));
        set_temp("apply/damage", 5 + random(5));
        set_temp("apply/armor", 4 + random(4));

        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        victim->affect_by("snake_poison", 
                ([ "level" : 30 + random(30),
                   "id"    : "yinhuan she",
                   "duration" : 10 + random(10) ]));
}