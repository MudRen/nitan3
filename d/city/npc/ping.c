#include <ansi.h>
#include <medical.h>

inherit NPC;
inherit F_DEALER;

string ask_job();
int do_peiyao(string arg);
int working(object me);
int halt_working(object me);
int ask_me();
int ask_riyue();

void create()
{
        set_name("ƽһָ", ({ "ping yizhi", "ping", "yizhi" }));
        set("title", "ҩ���ϰ�");
        set("nickname", HIW "ɱ����ҽ" NOR);
        set("gender", "����");
        set("long", "������ҽ���߳��ġ�ɱ����ҽ��ƽһָ���������Ը��\n"
                    "�֣�����ʲô�˶�ҽ�ġ�\n");
        set("age", 65);

        set("int", 38);
        
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("shen_type", 1);

        set("combat_exp", 500000);
        set("attitude", "heroism");

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 60);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 50);
        set("inquiry", ([
                "��ҩ"   : (: ask_job :),
                "����"   : (: ask_job :),
                "job"    : (: ask_job :),
                "����"   : (: ask_me  :),   
                "�������" : (: ask_riyue :),                             
        ]));

        set("vendor_goods", ({
                HERB("chaihu"),         // ���
                HERB("chenpi"),         // ��Ƥ
                HERB("chongcao"),       // ���
                HERB("chuanwu"),        // ����
                HERB("dahuang"),        // ���
                HERB("dangui"),         // ����
                HERB("duhuo"),          // ����
                HERB("fangfeng"),       // ����
                HERB("fuzi"),           // ����
                HERB("gsliu"),          // ��ʯ��
                HERB("guiwei"),         // ��β
                HERB("hafen"),          // ���
                HERB("heshouwu"),       // ������
                HERB("honghua"),        // �컨
                HERB("huangqi"),        // ����
                HERB("lurong"),         // ¹��
                HERB("xiongdan"),       // �ܵ�
                HERB("juhua"),          // �ջ�
                HERB("lanhua"),         // ����
                HERB("lingxian"),       // ����
                HERB("lingzhi"),        // ��֥
                HERB("mahuang"),        // ���
                HERB("moyao"),          // ûҩ
                HERB("niuhuang"),       // ţ��
                HERB("niuxi"),          // ţϥ
                HERB("qianjinzi"),      // ǧ����
                HERB("renshen"),        // �˲�
                HERB("ruxiang"),        // ����
                HERB("shadan"),         // �赨
                HERB("shancha"),        // ɽ�軨
                HERB("shanjia"),        // ɽ��
                HERB("shengdi"),        // ����
                HERB("shenglg"),        // ������
                HERB("sumu"),           // ��ľ
                HERB("taoxian"),        // ����
                HERB("tenghuang"),      // �ٻ�
                HERB("tianqi"),         // ����
                HERB("tugou"),          // ����
                HERB("wulingzhi"),      // ����֬
                HERB("xiefen"),         // Ы��
                HERB("xijiao"),         // Ϭ��
                HERB("xionghuang"),     // �ۻ�
                HERB("xuejie"),         // Ѫ��
                HERB("xuelian"),        // ѩ��
                HERB("yanwo"),          // ����
                HERB("yjhua"),          // ���
                HERB("yuanzhi"),        // Զ־
                HERB("zihua"),          // �ϻ�
                HERB("zzfen"),          // �����
                "/clone/misc/yanbo",    // �в�                
                "/clone/drug/tianqi-san",
                "/d/city/obj/shanshen",
                "/clone/medicine/jinmisan",
                "/clone/book/medical_book",
        }));

        setup();
        add_money("silver", 50);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_peiyao", "peiyao");
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

string ask_job()
{
        object me;
        object *obs;

        me = this_player();
        if (me->query_temp("job/peiyao"))
                return "����ɵĻ��������ô��";

        if (count_gt(me->query("combat_exp"), 30000))
                return "�������Ҳ̫�������˰ɡ�";

        if (count_lt(me->query("combat_exp"), 3000))
                return "��ƾ�������������ҿ�����ҩ�ʶ��˲�������";

        if (me->query("qi") < 5)
                return "�㻹����ЪЪ�ɣ���һ�۳��������ҿɸ�������";

        if (! interactive(me))
                return "����";

        obs = filter_array(all_inventory(environment()),
                           (: interactive($1) &&
                              $1 != $(me) &&
                              $1->query_temp("job/peiyao") &&
                              query_ip_number($1) == query_ip_number($(me)) :));
        /*
        if (sizeof(obs) > 0)
                return "�����Ѿ���" + obs[0]->name() + "�ڸɻ��ˣ���ȵȰɡ�";
        */

        me->set_temp("job/peiyao", 1);
        return "�ã���Ͱ�����ҩ(peiyao)�ɣ��������⼸ζ��";
}

int do_peiyao(string arg)
{
        object me;

        me = this_player();
        if (me->is_busy())
                return notify_fail("����æ���أ����ż���\n");

        if (! me->query_temp("job/peiyao"))
        {
                message_vision(CYN "$N" CYN "����ץ��ζҩ���ƣ�������$n"
                               CYN "ŭ�ȵ������ҷ��£����Ҷ���\n" NOR,
                               me, this_object());
                return 1;
        }

        me->set_temp("job/step", 1);
        me->start_busy(bind((: call_other, __FILE__, "working" :), me),
                       bind((: call_other, __FILE__, "halt_working" :), me));
        tell_object(me, HIY "�㿪ʼ������\n" NOR);
        return 1;
}

int working(object me)
{
        object ob;
        string msg;
        int finish;
        int b;

        if (! me->query_temp("job/step"))
                me->set_temp("job/step", 1);

        if (! living(me))
        {
                me->delete_temp("job/peiyao");
                me->delete_temp("job/step");
                return 0;
        }

        finish = 0;
        me->receive_damage("qi", 1);
        switch (me->query_temp("job/step"))
        {
        case 1:
                msg = "$N��������ѡ����һЩҩ�ġ�";
                break;
        case 2:
                msg = "$N��ҩ�ķŽ�ҩ�ʣ�ʹ������������";
                break;
        case 3:
                msg = "ҩ�Ľ���������м������һ��";
                break;
        case 4:
                msg = "��м��$N�ĵ�Ū��Խ��Խϸ���𽥱���˷�ĩ��";
                break;
        default:
                msg = "$N��ҩ�İ��ã��ݸ�$n��";
                finish = 1;
                break;
        }
        msg += "\n";

        if (finish)
        {
                msg += CYN "$n" CYN "����$N" CYN "���ҩ����ͷ������������"
                       "���Ǹ���ı��꣡\n" NOR;

                me->delete_temp("job/peiyao");
                me->delete_temp("job/step");

                b = 90 + random(40);
                me->add("combat_exp", b);
                me->improve_potential(b);

                ob = new("/clone/money/coin");
                ob->set_amount(10);
                ob->move(me, 1);
        }

        msg = replace_string(msg, "$N", "��");
        msg = replace_string(msg, "$n", name());
        tell_object(me, msg);

        if (finish)
        {
                if (b > 0)
                {
                        tell_object(me, HIC "\n������" + chinese_number(b) +
                                        "�㾭���Ǳ�ܡ�\n\n" NOR);
                }

                if (random(1000) == 1)
                {
                        msg = HIW "\n$n" HIW "��$N" HIW "�ٺ�һЦ�������ɵò�"
                              "�����е���˼���������ĥ���������͸���������"
                              "��\n" NOR;

                        message_vision(msg, me, this_object());
                        ob = new("/clone/misc/dymo");
                        ob->move(me, 1);
                        tell_object(me, HIC "\n������һ��" + ob->name() +
                                        HIC "��\n" NOR);
                }

                return 0;
        }

        me->add_temp("job/step", 1);
        return 1;
}

int halt_working(object me)
{
        message_vision(HIY "$N" HIY "�����еĻ�һ˦�����µ��������ˣ������ˣ�\n"
                       NOR, me);
        me->delete_temp("job/peiyao");
        me->delete_temp("job/step");
        return 1;
}

int accept_object(object who, object ob)
{
        object obj;
        
        if (! who->query_temp("������"))
        {
                message_vision("ƽһָ��$N˵��ҽһ�ˣ�ɱһ�ˣ��Ϸ���Ǯ��\n", who);
                return 0 ;
        }
        if (ob->query("money_id") && ob->value() >= 50000)
        {
                destruct(ob);
                message_vision("ƽһָ������$N��Ǯ������$Nһ������ڣ�\n" , who);
                this_player()->delete_temp("������" );
                obj=new("/d/city/npc/obj/shouwu");
                obj->move(this_player());
        }
        return 1;
}

int ask_me()
{
        object ob = this_player();

        if (ob->query("family/family_name") != "�������")
        {
                command("say �Ϸ�ҽһ��ɱһ�ˣ������������ɡ�\n");
                return 1;
        }
        if ((int)ob->query("eff_qi") == (int)ob->query("max_qi"))
        {
                command("say ����û�����ˣ�����ǲ�Ϸ���\n");
                return 1;
        }
        else
        {
                message_vision("ƽһָ��ָ΢������ָһ����һ��ҩ�輲����$N���ʺ�$N"
                                "���ɡ����ࡱһ�����븹�У��ٸ�������ˬ����������\n", ob);
                ob->set("eff_qi", (int)ob->query("max_qi"));
                ob->set("eff_jing", (int)ob->query("max_jing"));
                command("say �ߣ�����������书�������֣���ú�ȥѧѧ�����ٶ��������ˣ�����ɡ�\n");
                return 1;
        }
}

int ask_riyue()
{
        object ob = this_player();

        if (ob->query("family/family_name") != "�������")
                return notify_fail("������������ձ�һͳ������\n");

        message("vision", "ƽһָ����һ�ţ��ѽ�" + ob->name() + "�ߵ���Ӱ���١�\n", environment(ob), ob);
        ob->move("/d/heimuya/midao7");
        tell_object(ob, "ƽһָ����һ�ţ������߽����ص���\n");
        return 1;
}
