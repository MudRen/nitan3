// person used in quest

inherit CLASS_D("generate") + "/chinese";

void random_move();
void destruct_me();
int  is_stay_in_room();

void create()
{
        ::create();
        set("gender", "����" );
        set("age", 30 + random(30));
        set("long", "");
        set("attitude", "friendly");
        set("chat_chance", 30);
        set("chat_msg", ({ (: random_move :) }));
        set("scale", 100);
        set_temp("born_time", time());
        if (clonep()) keep_heart_beat();
}

void set_from_me(object me)
{
        int exp;

        NPC_D->init_npc_skill(this_object(), NPC_D->check_level(me));
}

int accept_fight(object ob)
{
        command("say �ܺã����ҾͲ������ˡ�");
        kill_ob(ob);
        return 1;
}

int accept_hit(object ob)
{
        command("say �ߣ�ʲô�ˣ�");
        kill_ob(ob);
        return 1;
}

void random_move()
{
        if (time() - query_temp("born_time") > 1200)
        {
                destruct_me();
                return;
        }
        NPC_D->random_move(this_object());
}

void destruct_me()
{
        message_vision("$N����ææ�����ˡ�\n", this_object());
        destruct(this_object());
}

