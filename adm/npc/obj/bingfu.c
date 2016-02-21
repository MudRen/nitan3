// rewrited by Lonely@nitan3

#include <ansi.h>
#include <room.h>
#include <command.h>

inherit ITEM;

mapping bingfa = ([
        "fenzhan"    : "��ս",
        "fendou"     : "�ܶ�",
        "fenxun"     : "��Ѹ",
        "qishe"      : "����",
        "benshe"     : "����",
        "feishe"     : "����",
        "tupo"       : "ͻ��",
        "tujin"      : "ͻ��",
        "tuji"       : "ͻ��",
/*
        "crossbow" : ([ "qishe"      : "����",
                        "lianshe"    : "����",
                        "liannu"     : "����",
                     ]),
                     
        "siegecity": ([ "jinglan"    : "����",
                        "chongche"   : "�峵",
                        "fashi"      : "��ʯ",
                        "xiangbing"  : "���",
                        "luoshi"     : "��ʯ",
                        "leimu"      : "��ľ",
                        "shetai"     : "��̨",
                        "jianchui"   : "�ⴸ",
                     ]),
        "ruse"     : ([ "hunluan"    : "����",
                        "xianjing"   : "����",
                        "gongxin"    : "����",
                        "huanshu"    : "����",
                        "yingzao"    : "Ӫ��",
                        "poxian"     : "����",
                        "jiaoyu"     : "����",
                        "ruma"       : "����",
                     ]),
        "resource" : ([ "guwu"       : "����",
                        "zhiliao"    : "����",
                        "yaoshu"     : "����",
                     ]),
*/                     
]);

mapping zhenfa = ([
        "putong"   : "��ͨ��",
        "yulin"    : "������",
        "fengshi"  : "��ʸ��",
        "heyi"     : "������",
        "yanyue"   : "������",
        "fangyuan" : "��Բ��",
        "yanxing"  : "������",
        "changshe" : "������",
        "yunlong"  : "������",
]);

void create()
{
        set_name(HIY "����" NOR, ({"bing fu", "fu"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long",HIY"һö����Ԫ˧����ǲ���Ļ�ͷ������\n"NOR);
                set("material", "copper");
                set("no_get", 1);
                set("no_steal", 1);
                set("no_put", 1);
                set("no_drop", 1);
        }
        set("master", "��̎���ٺ�");
        set("owner", "lonely");
        setup();
}

void init()
{
        object me, ob;

        me = this_player();
        ob = this_object();

        if (me->query("id") == ob->query("owner"))
        {
                add_action("do_stock", ({ "stock", "gouzhi" }));
                add_action("do_move", ({ "move", "yidong" }));
                add_action("do_train", ({ "drill", "xunlian", "train" }));
                add_action("do_attack", ({ "assault", "gongji", "attack", "tuji" }));
                add_action("do_order",  ({ "order", "mingling" }));
                add_action("do_inquiry", ({ "inquiry", "chakan" }));
                // add_action("do_exert", ({ "exert", "yun", "touch" }));
                add_action("do_exert", ({ "touch" }));
                add_action("do_kill",
                        ({ "team kill", "array kill", "touxi", "kill",
                           "hit", "fight", "steal", "beg", "persuade",
                           "perform", "yong", "exert", "yun", "throw",
                           "ansuan", "conjure", "recall" }));        
        }
}

int do_kill(string arg)
{
        string what, who;

        if (! arg) return 0;

        if (this_object()->id(arg))
        {
                write("��û�и�����Ǿ���Ү���������ܣ���\n");
                return 1;
        } else
        if ((sscanf(arg, "%s from %s",what, who) == 2 ||
             sscanf(arg, "%s at %s", what, who) == 2 ||
             sscanf(arg, "%s on %s", what, who) == 2 ||
             sscanf(arg, "%s %s", what, who) == 2) &&
             this_object()->id(who)) {
                write("��û�и�����Ǿ���Ү���������ܣ���\n");
                return 1;
        } else
        if (arg == "roar" || arg == "hou")
        {
                write("��û�и�����Ǿ���Ү���������ܣ���\n");
                return 1;
        }

        return 0;
}

void attack_over(object me)
{
        if (objectp(me))
        {
                message_vision(HIW "$N��������һ�ӣ���������һ��������"
                        + "��ʼ����׼��������һ�ֵĹ�������\n" NOR, me); 
                me->delete_temp("warquest/attack");
        }
        return;
}      

int do_attack(string arg)
{
        object me, ob;
        object env, room;
        string who, dir;
        string zhen, craft;

        me = this_player();
        env = environment(me);

        if (! arg) return notify_fail("��Ҫָ�Ӳ��ӳ�˭���������\n");

        // if (me->query("env/auto_contruel"))
        if (me->query("env/auto_war"))
                return notify_fail("���Ѿ�����Ϊ��ϵͳ�Զ�ָ����ս�������Լ����������޸����á�\n");

        if (me->query_temp("warquest/attack"))
                return notify_fail("��Ķ������������������Ҫ�ҷ������ˣ�\n");

        if (! me->query_temp("warquest/train"))
                return notify_fail("��δ��һ��һ�䣬ָ�Ӹ�ʲôѽ��\n");

        if (me->query_temp("warquest/group") < 1)
                return notify_fail("��Ķ����Ѿ���ʧ�������޷��������ˣ�\n");

        if (env->query("no_fight"))
                return notify_fail("���ﲻ��ս������\n");

        if (sscanf(arg, "%s with %s & %s", who, zhen, craft, dir) < 3)
                return notify_fail("ָ���ʽ�������� attack <sb.> with <array> & <craft> ָ����Ķ��飡\n");

        if (! objectp(ob = present(who, env)))
                return notify_fail("�޷��ҵ�Ŀ�꣬���� attack <sb.> with <array> & <craft> ָ����Ķ��飡\n");

        if (! ob->query_temp("warquest") || ob->query_temp("warquest/party") != "meng")
                return notify_fail("������������ǲ�Ҫ���������Ƿǵĺã�\n");

        if (! me->query("array/" + zhen) && zhen != "putong")
                return notify_fail("��Ŀǰ��û��ͨ����" + zhenfa[zhen] + "�������󷨣�\n");

        if (! me->query("craft/infantry/" + craft))
                return notify_fail("��Ŀǰ��û��ͨ����" + bingfa[craft] + "�����ֱ�����\n");

        message_vision(HIY "$N�����б���һ�ӣ���ȵ�����������" + zhenfa[zhen] +
                "����׼����о������桪��>" + bingfa[craft] + "����\n" NOR, me, ob);

        me->set_temp("warquest/attack", 1);
        me->set_temp("warquest/array", zhenfa[zhen]);
        // me->start_call_out((: call_other, WAR_D, "attack_over", me :), 10);
        call_out("attack_over", 10, me);    
        WAR_D->do_attack(me, ob, zhenfa[zhen], bingfa[craft], env);
        return 1;
}

int do_exert(string arg)
{
        tell_object(this_player(),
                "������������֮ͳ˧�ˣ�һ��һ������˼��\n");
        return 1;
}

int do_stock(string arg)
{
        object me;
        
        me = this_player();

        if (base_name(environment(me)) != "/d/city2/sying1")
                return notify_fail("���Ȼ������Ӫ���ɾ��������а��г̣�\n");

        if (! arg || arg == "")
                return notify_fail("����Ҫ�����ȥ��ʲô?\n");
              
        me->set_temp("warquest/purchase", arg);
                                
        if (me->query_temp("warquest/move"))
                return notify_fail("�����Ѿ�������ȥ�ˣ�\n");
                
        switch(me->query_temp("warquest/purchase"))
        {
        case "weapon" :
                message_vision(HIW "$N�����ȵ������Ҿ������汾˧" +
                        "���������ǹ��ñ��ף��������󣡣�\n" NOR, me);
                break;
        case "horse"  :
                message_vision(HIW "$N�����ȵ������Ҿ������汾˧" +
                        "���������ǹ���ս���������󣡣�\n" NOR, me);
                break;
        case "stone"  :
                message_vision(HIW "$N�����ȵ������Ҿ������汾˧" +
                        "���������ǹ���ʯľ���������󣡣�\n" NOR, me);
                break;
        case "arrow"  :
                message_vision(HIW "$N�����ȵ������Ҿ������汾˧" +
                        "���������ǹ���������������󣡣�\n" NOR, me);
                break;
        case "enlist" :
                message_vision(HIW "$N�����ȵ������Ҿ������汾˧" +
                        "������������ļ�±����������󣡣�\n" NOR, me);
                break;
        case "forage" :
                message_vision(HIW "$N�����ȵ������Ҿ������汾˧" +
                        "������ʦѺ�����ݣ��������󣡣�\n" NOR, me);
                break;
        default :
                tell_object(me, "����Ҫ�����ȥ��ʲô?\n");
                me->delete_temp("warquest/purchase");
                return 1;
                break;
        }

        me->set_temp("warquest/move", "forward");
        me->set_temp("warquest/move_from", "/d/city2/sying1");
                
        return 1;
}

int do_train(string arg)
{
        object me, env;

        me = this_player();
        env = environment(me);

        if (base_name(environment(me)) != "/d/city2/sying1")
                return notify_fail("���Ȼ������Ӫ���ܵ���ѵ���ľ���\n");

        if (me->query_temp("warquest/train_begin"))
                return notify_fail("�㲻������ѵ�������𣿣�\n");

        message_vision(HIW "$N�����ȵ������Ҿ��������汾˧" +
                "ǰȥ���������������󣡣�\n" NOR, me);

        me->set_temp("warquest/train", "infantry");
        me->move("/d/city2/sying2");
        me->set_temp("warquest/train_begin", 1);
        return 1;
}


int do_order(string arg)
{
        object me, env, ob, ling, obb;
        string who, what, dir;
        int i, n, flag;
        mapping jiang;

        me = this_player();
        env = environment(me);
        if (! arg || sscanf(arg, "%s to %s", who, what) != 2)
                return notify_fail("���� order sb to do sth. ���������\n");

        if (! objectp(ob = present(who, env)))
                return notify_fail("����û������Ե��ȵ��������죡\n");

        if (ob->query_temp("warquest/party") != "song")
                return notify_fail("�Է������ξ�����ι�����ȣ���\n");

        if (! ob->query_temp("warquest/train") ||
            ob->query_temp("warquest/group") < 1)
                return notify_fail("��֧������δѵ����죬�ѿ����ã�\n");

        if (ob->query_temp("warquest/purchase"))
                return notify_fail("�Է����ڽ��о�����������ò�Ҫ�������ľ��ӣ���\n");
                        
        if (ob == me) return notify_fail("�Լ������Լ����㲻���۰��㣿��\n");
        
        if (userp(ob)) notify_fail("�㲻��������ҽ��죡\n");

        switch(what)
        {
        case "follow":
                message_vision(HIY "$N��һ��˼��������ҵ����������$n��" +
                        "��˧����ӭս�ɹŴ����\n�����뼴�̵���������ͬ��˧������\n" NOR, me, ob);
                message_vision(HIW "$N����Ӧ����ĩ��������ԸΪ����ЧȮ��֮�ͣ�\n" NOR, ob);
                ob->set_leader(me);
                break;

        case "stop":               
                message_vision(HIY "$N��ϸ�鿴�����ܵĵ��Σ�������ҵ����������$n���" +
                        "����ֹͣ�����н�����\n" NOR, me, ob);
                message_vision(HIW "$N����Ӧ����ĩ����������\n" NOR, ob);
                ob->command("move stop");
                break;

        default:                
                if (sscanf(what, "guard %s", dir) == 1
                &&  env->query("exits/" + dir))
                {
                        message_vision(HIY "$N��ϸ�鿴�����ܵĵ��Σ�������ҵ����������$n���" +
                                "�˴�������Ҫ��\n�����ѹ��������뽫���ڴ˴����Զ��أ�\n" NOR, me, ob);
                        message_vision(HIW "$N����Ӧ����ĩ������������һ��һ�䣬����ʧ��أ�\n" NOR, ob);
                        ob->set_leader(0);
                        ob->command("guard " + dir);
                } else
                if (sscanf(what, "move %s", dir) == 1
                &&  env->query("exits/" + dir))
                {
                        message_vision(HIY "$N��ϸ�鿴�����ܵĵ��Σ�������ҵ����������$n���" +
                                "�������첿��\n�����н����������󣡣�\n" NOR, me, ob);
                        message_vision(HIW "$N����Ӧ����ĩ����������\n" NOR, ob);
                        ob->set_leader(0);
                        ob->command("move " + dir);
                } else
                if (env->query("exits/" + what))
                {
                        ob->set_leader(0);
                        GO_CMD->main(ob, what);
                } else
                        return notify_fail("��Ϊһ��֮˧���벻Ҫ������ľ�Ȩ��\n");
                break;
        }
        ob->set_temp("warquest/battle", 1);
        ob->set_temp("warquest/quest", "���ӳ�����ӭս�ɾ�");
        return 1;
}

int do_inquiry(string arg)
{
        object me = this_player();
        
        return WAR_D->do_inquiry(me, arg);
}

int do_move(string dir)
{
        object me, env;

        me = this_player();
        env = environment(me);

        if (! dir || dir == "stop")
        {
                remove_call_out("on_move");
                write("�����н���ֹ��\n");
                return 1;
        }

        if (env->query("exits/" + dir))
        {
                remove_call_out("on_move");
                call_out("on_move", 2, me, dir);
                write("���ӿ�ʼ�н���\n");
                return 1;
        }
        else
                write("�޷��ƶ���û��ָ������ĳ��ڣ�\n");

        return 1;
}

void on_move(object me, string dir)
{
        object env;

        if (! me) return;

        env = environment(me);
        if (! env->query("exits/" + dir))
        {
                write("�޷��ƶ���û��ָ������ĳ��ڣ�\n");
                return;
        }

        if (me->is_fighting() ||
            me->query_temp("warquest/attack"))
        {
                remove_call_out("on_move");
                call_out("on_move", 4, me, dir);
                return;
        } else
        if (GO_CMD->main(me, dir))
        {
                remove_call_out("on_move");
                call_out("on_move", 2, me, dir);
                return;
        } else
        {
                write("�޷��ƶ����н���ֹ��\n");
                return;
        }
}

void owner_is_killed() { destruct(this_object()); }
