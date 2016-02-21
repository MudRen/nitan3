#include <ansi.h>
inherit NPC;

int do_kill(string arg);
int is_stay_in_room() { return 1; }

void create()
{
        int skill, nl;
        mixed exp;

        set_name("�ɹſɺ�",({ "menggu kehan", "kehan"  }));
        set("gender", "����" );
        set("long", "����Ǵ˴�������ֵ��ɹſɺ���\n");

        set("int", 30);
        set("str", 60 + random(20));
        set("con", 20 + random(20));
        set("dex", 20 + random(20));
        set("age", 20 + random(30));
        set("per", 20 + random(10));
        set("no_get", 1);

        exp = UPDATE_D->query_max_exp();
        skill = to_int(pow(to_float(atoi(count_div(exp, 100))), 1.0 / 3)) * 10;
        skill += 200;
        nl = skill * 10 + atoi(count_div(exp, 10000));

        set("combat_exp", exp);
        set("max_neili", nl);
        set("neili", query("max_neili") * 3 / 2);
        set("max_jingli", nl);
        set("jingli", query("max_jingli"));
        set("max_qi", nl * 10);
        set("eff_qi", query("max_qi"));
        set("qi", query("eff_qi"));
        set("max_jing", nl);
        set("eff_jing", query("max_jing"));
        set("jiali", skill / 2);

        set_skill("longxiang-gong", skill);
        set_skill("xuedao-daofa", skill);
        set_skill("shenkong-xing", skill);
        set_skill("dashou-yin", skill);
        set_skill("hand", skill);
        set_skill("force", skill);
        set_skill("dodge", skill);
        set_skill("blade", skill);
        set_skill("parry", skill);
        set_skill("arrow", skill*2/3);

        map_skill("force", "longxiang-gong");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand",  "dashou-yin");
        map_skill("parry", "xuedao-daofa");
        map_skill("blade", "xuedao-daofa");

        prepare_skill("hand", "dashou-yin");

        set_temp("warquest/party", "meng");

        add_temp("apply/armor", 600);
        add_temp("apply/attack", 500);
        add_temp("apply/damage", 500);
        setup();

        carry_object("/clone/weapon/bow8");
        carry_object("/clone/weapon/bow8");
        carry_object("/clone/weapon/bow8");
        carry_object("/clone/weapon/bow8");
        carry_object("/clone/weapon/bow8");
        carry_object(__DIR__"obj/wandao");
        carry_object(__DIR__"obj/wandao");
        carry_object(__DIR__"obj/wandao");
        carry_object(__DIR__"obj/wandao");
        carry_object(__DIR__"obj/wandao")->wield();
        carry_object(__DIR__"obj/tiejia")->wear();
        carry_object(__DIR__"obj/pifeng")->wear();
}

void init()
{
	::init();
	
        add_action("do_kill",
                ({ "team kill", "array kill", "touxi", "kill",
                   "hit", "fight", "steal", "beg", "persuade",
                   "perform", "yong", "exert", "yun", "throw",
                   "conjure", "recall" }));
}

int do_kill(string arg)
{
        string what, who;

        if (! arg) return 0;

        if (this_object()->id(arg))
        {
                write("��û�и�������ɹű�Ү���������ܣ���\n");
                return 1;
        } else
        if ((sscanf(arg, "%s from %s",what, who) == 2 ||
             sscanf(arg, "%s at %s", what, who) == 2 ||
             sscanf(arg, "%s on %s", what, who) == 2 ||
             sscanf(arg, "%s %s", what, who) == 2) &&
             this_object()->id(who)) {
                write("��û�и�������ɹű�Ү���������ܣ���\n");
                return 1;
        } else
        if (arg == "roar" || arg == "hou")
        {
                write("��û�и�������ɹű�Ү���������ܣ���\n");
                return 1;
        }

        return 0;
}

varargs void die(object killer) 
{
        int i;
        object ob, obj;

        recover();
        return;
        if (! objectp(ob = query_last_damage_from())) return;
        if (ob->query_temp("warquest/party") != "song") return;

        message_vision("$N������ɹ�����ڼ����翹�����ڱ�����" +
                        HIR "������" NOR "��\n",
                        this_object());
                        
        ob->add_temp("warquest/reward", 50);

        for (i=0; i<10; i++)
        {
                obj = new("/clone/enchase/BLUjewel");
                obj->move(environment(this_object()));
        }

        WAR_D->win_kingwar();
        
        return ::die();
}

