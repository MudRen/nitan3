
#define TASK_DIR        "/task/"
#define TASK_OB_DIR     TASK_DIR + "obj/"
#define DEBUG(x)        tell_object(find_player("lonely"), x)
#define RATE 4


#include <ansi.h>

inherit BUNCHER;
inherit F_DEALER;

int redeem(string arg);
mixed ask_back();

mapping *big_task;
string  *all_trade;

mixed   trade_task(int index);
string  ask_task(int index, string name);
mapping *query_big_task() { return big_task; }
string  *query_all_trade() { return all_trade; }

void create()
{
        set_name("���", ({ "tang nan", "tang", "nan" }));
        set("title", "�����ϰ�");
        set("shen_type", 0);
        set("gender", "����");
        set_max_encumbrance(100000000);
        set("age", 35);
        set("str", 100);
        set("long", "��˵������Ĵ��Ƽҵĺ����\n");
        set("no_get_from", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

        set("combat_exp", 50000);
        set("attitude", "friendly");

        set("inquiry", ([
                "���־�ת" : (: ask_back :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_sell", "sell");
        add_action("do_value", "value");
        add_action("do_redeem", "redeem");
        add_action("do_pawn", "pawn");
        add_action("do_check", "check");
        add_action("do_look", ({"guankan", "kan"}));
}

mixed ask_back()
{
        object me;

        me = this_player();
        if (me->query("family/family_name") != "������")
        {
                message_vision(CYN "$N" CYN "һ��ãȻ����ɶ���ղ���˵ɶ��\n" NOR,
                               this_object(), me);
                return -1;
        }

        message_sort(HIY "\n$N" HIY "���˿�$n" HIY "����Ц�������漴��$n"
                     HIY "���ߵ���˵������С�����Ϊ�����˼�׼�����ˣ���"
                     "�ڹ�̨���棬����������ɡ���˵��$N" HIY "������$n"
                     HIY "�첽��������ȥ��\n\n" NOR, this_object(), me);
        me->move("/d/xueshan/midao");
        tell_object(me, CYN + name() + "˵�������������һֱ���Ͼ����ˡ�\n"
                        HIC + name() + "˵��㼱��ææ���˻�ȥ��\n" NOR);
        return -1;
}

void unconcious()
{
        die();
}

void die()
{
        message_vision("\n$N���ˡ�\n", this_object());
        destruct(this_object());
}

string ask_task(int index, string name)
{
        string* trades = keys(big_task[index]["trade"]);
        string msg = "������ܹ�����";
        for(int i = 0; i < sizeof(trades); i++) 
                msg += trades[i] + ((i < (sizeof(trades) - 2)) ? 
                        "��" : ((i < (sizeof(trades) - 1)) ? 
                        HIC "��" NOR : HIC "�Ļ����ҾͰ�" + name + HIC + "���㡣" NOR));
        return msg;
}

mixed trade_task(int index)
{
        object who = this_player();
        object me = this_object();
        object ob;
        string* trades = keys(big_task[index]["trade"]);
        string file_name;

        for(int i = 0; i < sizeof(trades); i++) {
                   ob = present(big_task[index]["trade"][trades[i]], who);
                   if(!objectp(ob) || !ob->query("task_ob"))
                        return "�����õ���" + trades[i] + "��˵�ɡ�";
        }

        for(int i = 0; i < sizeof(trades); i++) {
                message_vision("$N�ó�" + trades[i] + "��$n��\n", who, me);
                TASK_D->finish(present(big_task[index]["trade"][trades[i]], who), who);
                destruct(present(big_task[index]["trade"][trades[i]], who));
        }
        file_name = big_task[index]["file_name"];
        ob = find_object(TASK_OB_DIR + file_name);
        if(!objectp(ob)) ob = load_object(TASK_OB_DIR + file_name);
        ob->move(who);
        ob->set("big_task", 1);
        ob->set("task_ob", 1);
        message_vision("$N�ó�" + ob->name() + "��$n��\n", me, who);

        return -1;
}

void add_big(string arg, int i)
{
        string name;
        object task_ob;

        task_ob = find_object(TASK_OB_DIR + arg);
        if(!objectp(task_ob)) task_ob = load_object(TASK_OB_DIR + arg);
        name = task_ob->query("name");

        big_task[i] = (["file_name" : arg,
                        "name" : name,
                        "trade" : 0,
                ]);

        set("inquiry/" + filter_color(name), (: ask_task, i, name :));
        set("inquiry/�һ�" + filter_color(name), (: trade_task, i :));
        all_trade[sizeof(all_trade) - i - 1] = task_ob->query("id");
        destruct(task_ob);
}

void task_announce()
{
        string msg = "���յõ���";
        mapping *task = TASK_D->query_task();
        int k, task_s = sizeof(task);

        for(int i = 0; i < sizeof(big_task); i++) {
                for(int j = 0; j < RATE; j++) {
                        k = random(task_s);
                        if(member_array(task[k]["id"], all_trade) != -1) {
                                j--;
                                continue;
                        }
                        if(!mapp(big_task[i]["trade"])) big_task[i]["trade"] = ([task[k]["name"] : task[k]["id"]]);
                        else big_task[i]["trade"] += ([task[k]["name"] : task[k]["id"]]);
                        all_trade[i * RATE + j] = task[k]["id"];
                }
                msg += big_task[i]["name"] + ((i < (sizeof(big_task) - 2)) ? 
                        "��" : ((i < (sizeof(big_task) - 1)) ? 
                        HIC "��" NOR : HIC "����֪��λ����������Ҫ��" NOR));
        }
        set("inquiry/�һ�", "��������" + msg[10..<34] + "���Ժ��㽻����");
        command("chat " + msg);
}

void clean_big_task(int n)
{
        delete("inquiry");
        set("inquiry/���־�ת", (: ask_back :));
        big_task = allocate(n);
        all_trade = allocate(n*RATE + n);
}

