#include "/d/room/roomnpc/roomnpc.h"

inherit CLASS_D("generate") + "/chinese";
inherit F_GUARDER;
inherit F_COAGENT;

int  accept_object(object who, object ob);

string query_save_file()
{
        object env;

        if (!objectp(env = environment()) ||
            strsrch(base_name(env),"/data/room/") == -1 ||
            !env->query("room_owner_id") )
                return 0;

        return sprintf("/data/room/%s/shouwei", env->query("room_owner_id"));
}

int save()
{
        string file;
        
        if (!query("startroom") ||
            !environment() ||
            query("startroom") != base_name(environment()))
                return 0;

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file + __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}
int restore()
{
        string file;
        if( stringp(file = this_object()->query_save_file()) && file_size(file + __SAVE_EXTENSION__) > 0 )
                return restore_object(file);
        return 0;
}

void do_unwield()
{
        command("yun powerup");
        command("yun shield");
}

void do_wield()
{
        command("yun powerup");
        command("yun shield");
}

void init_status()
{
        int lvl;

        restore();
        set("jiali", this_object()->query_skill("force")/2);
        lvl = this_object()->query_skill("force",1);
        lvl = (lvl-1)*(lvl-1)*(lvl-1)/10;
        if (lvl < 10000000) lvl = 10000000;
        set("combat_exp",lvl);
        set("auto_perform", 1);
        
        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "lingbo-weibu");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("claw", "jiuyin-baiguzhao");
        map_skill("strike" , "cuixin-zhang");

        prepare_skill("claw", "jiuyin-baiguzhao");
        prepare_skill("strike", "cuixin-zhang");

        set("chat_chance", 30);
        set("chat_msg", ({
                (: do_unwield :),
        }));

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: do_wield :),
        }));

        if (stringp(query_save_file()) && environment())
                set("owner",environment()->query("room_owner"));
        reset_action();
        recover();
}

void create()
{
        ::create();
        set_name(query("name"), ({ query("id"), "shou wei", "guarder" }));
        NPC_D->init_npc_skill(this_object(), 7 + random(2));
	set("gender", "����" );
	set("age", 30 + random(30));
	set("long", "���ǿ���ׯ԰������������ȥ�ƺ���������\n");
	set("attitude", "friendly");

        set("max_qi", 4800);
        set("eff_qi", 4800);
        set("qi", 4800);
        set("max_jing", 2400);
        set("eff_jing", 2400);
        set("jing", 2400);
        set("max_neili", 5200);
        set("neili", 5200);
        set("jiali", 100);
        set("max_vip",10);
        set("auto_perform",1); 
        call_out("init_status",0);
}

void init()
{
        ::init();
        add_action("do_invite", "invite");
        add_action("do_show", "show");
        add_action("do_vip", "vip");
        add_action("list_vip", "listvip");
        add_action("buy_vip", "buyvip");       
        add_action("add_force", "addforce"); 
        add_action("add_skill", "addskill"); 
}

int accept_object(object who, object ob)
{
	object obn;

        if (! ob->query("money_id"))
                return 0;

        if (is_owner(who))
        {
                message_vision(name() + "��$Nʩ��һ��\n", who);
                destruct(ob);
                return 1;
        }
	return 0;
}

int accept_hit(object ob)
{
        if (is_owner(ob))
        {
                message_vision("$N��æ�ڰ��֣���$n�������ɲ�Ҫ���ҿ���"
                               "����Ц����\n", this_object(), ob);
                return 0;
        }

        return ::accept_hit(ob);
}

int accept_fight(object ob)
{
        if (is_owner(ob))
        {
                message_vision("$N����һ������æ��$n������С�Ĳ��ң�С"
                               "�Ĳ��ң���\n", this_object(), ob);
                return 0;
        }

        return ::accept_fight(ob);
}

int accept_kill(object ob)
{
        if (is_owner(ob))
        {
                message_vision("$Nһ����̾����������Ȼ���˲������ˣ���"
                               "�հգ���������������ȥ�������ˡ���\n"
                               "˵�գ�$Nһ���֣�����һ���¾�ƮȻ��ȥ��\n",
                               this_object(), ob);
                destruct(this_object());
                return 0;
        }

        return ::accept_kill(ob);
}
