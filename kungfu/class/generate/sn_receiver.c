// person used in quest

inherit CLASS_D("generate") + "/chinese";

int  accept_object(object who, object ob);

void random_move();
void destruct_me();
int is_stay_in_room() { return 1; }
int is_ultra() {return 1;}

void create()
{
        ::create();
        set("gender",query("gender"));
	set("age", 30 + random(30));
        if (arrayp(query("from")) && sizeof(query("from")))
                set("long",query("from")[random(sizeof(query("form")))] + "\n��˵������뽭�����Ϻ������йء�\n");
        else
                set("long","��˵������뽭�����Ϻ������йء�\n");

	set("attitude", "friendly");
        set("chat_chance", 30);
        set("chat_msg", ({ (: random_move :) }));
        set("scale", 100);
	set_temp("born_time", time());
        keep_heart_beat();
}

void set_from_me(object me)
{
        string exp;

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
	if (time() - query_temp("born_time") > 900)
	{
		destruct_me();
		return;
	}
}

int accept_object(object who, object ob)
{
        object rob;

        if (ob->query("send_to") == query("id"))
        {
                command("nod");
                rob = new("/clone/misc/receipt");
                rob->set("reply_by", query("id"));
                rob->set("reply_to", ob->query("send_from"));
                rob->set("reply_to_name", ob->query("send_from_name"));
                rob->set("receive_from", who->query("id"));
                rob->set("receive_from_name", who->name(1));
                rob->set("long", "����һ����" + name() + "�յ�" +
                                 ob->query("send_from_name") + "����Ʒд�Ļ�ִ��\n");
                command("say ��л��λ" + RANK_D->query_respect(who) + "��"+ob->name(1)+"������");
                message_vision("$N����$nһ�Ż�ִ��\n", this_object(), who);
                rob->move(who, 1);
                destruct(ob);
                remove_call_out("destruct_me");
                call_out("destruct_me", 0);
                return 1;
        }

        return 0;
}

void destruct_me()
{
        message_vision("$N����ææ�����ˡ�\n", this_object());
        destruct(this_object());
}