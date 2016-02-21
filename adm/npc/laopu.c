// laopu.c ɨ������

#include "/d/room/roomnpc/roomnpc.h"

inherit NPC;
inherit F_GUARDER;

void do_wield();
void do_unwield();
int  accept_object(object who, object ob);
void init_status();

string query_save_file()
{
        object env;

        if (!objectp(env = environment()) ||
            strsrch(base_name(env),"/data/room/") == -1 ||
            !env->query("room_owner_id") )
                return 0;

        return sprintf("/data/room/%s/laopu", env->query("room_owner_id"));
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

void create()
{
        set_name("ɨ������", ({"lao pu", "saodi laopu"}) );
        set("gender", "����" );
        set("age", 50 + random(20));
        set("long", "����һ��ɨ�ص������ˣ���������ȥ�ƺ���������\n");
        set("attitude", "friendly");

        set("max_qi", 4000);
        set("max_jing", 8000);
        set("max_neili", 4000);
        set("neili", 4000);
        set("combat_exp",10000000);
        set("no_get",1);
        set("max_vip",10);
        set("auto_perform",1);

        set_skill("force", 800);
        set_skill("parry", 800);
        set_skill("dodge", 800);
        set_skill("strike",800);
        set_skill("claw",800);
        set_skill("jiuyang-shengong", 800);
        set_skill("lingbo-weibu", 800);
        set_skill("qiankun-danuoyi", 800);
        set_skill("jiuyin-baiguzhao", 800);
        set_skill("cuixin-zhang", 800);

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

        set("can_perform/jiuyin-baiguzhao/shenzhao",1);
        setup();

        call_out("init_status",0);

        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_invite", "invite");
        add_action("do_show", "show");
        add_action("do_vip", "vip");
        add_action("list_vip", "listvip");
        add_action("add_force", "addforce");
        add_action("add_skill", "addskill");
        add_action("buy_vip", "buyvip");
        add_action("add_hujiu", "addhujiu");
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
                message_vision("$N��ü�����Ķ�$n�������ɲ�Ҫ���ҿ���"
                               "����Ц����\n", this_object(), ob);
                return 0;
        }

        command("yun powerup");
        command("yun shield");

        if (query("can_hujiu") && query("owner"))
                CHANNEL_D->do_channel( this_object(), "chat", query("owner") + "�����������˹��򵽴��ſ�������");

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

        command("yun powerup");
        command("yun shield");

        if (query("can_hujiu") && query("owner"))
                CHANNEL_D->do_channel( this_object(), "chat", query("owner") + "�����������˹��򵽴��ſ�������");

        return ::accept_fight(ob);
}

int accept_kill(object ob)
{
        if (is_owner(ob))
        {
                message_vision("$Nһ����̾����������Ȼ���˲������ˣ���"
                               "�հգ���������������ȥ�������ˡ���\n"
                               "˵�գ����˶���ɨ�ѣ�ƮȻ��ȥ��\n",
                               this_object(), ob);
                destruct(this_object());
                return 0;
        }

        command("yun powerup");
        command("yun shield");

        if (query("can_hujiu") && query("owner"))
                CHANNEL_D->do_channel( this_object(), "chat", query("owner") + "�����������˹��򵽴��ſ�������");

        return ::accept_kill(ob);
}

void init_status()
{
        mixed lvl;

        restore();
        set("jiali", this_object()->query_skill("force")/2);
        lvl = this_object()->query_skill("force",1) - 1;
        lvl = count_div(count_mul(count_mul(lvl, lvl), lvl), 10);
        if (count_lt(lvl, 10000000)) lvl = "10000000";
        set("combat_exp",lvl);
        set("auto_perform", 1);
        
        if (stringp(query_save_file()) && environment())
                set("owner",environment()->query("room_owner"));
        reset_action();
        recover();
}

