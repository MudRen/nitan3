#include <ansi.h>
#define RIDE_CMD        "/cmds/std/ride" 
inherit NPC;

int ask_quest(string arg);

void create()
{
        set_name("���μ��", ({"jian jun"}));
        set("gender", "����");
        set("age", random(20) + 20);

        set("long", "����һ�����ǻʹ��е�һ��̫�࣬���𿹻��ɹž������ִ��εļ����\n");
        set("combat_exp", 800000);
        set("attitude", "peaceful");
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("max_neili", 2000);
        set("neili", 1000);
        set("no_get", 1);

        setup();
        carry_object("clone/cloth/cloth")->wear();
}

void init()
{
        add_action("ask_quest", ({ "lingming" }));
}


int ask_quest(string arg)
{
        object me, ob, ling;
        object horse;
        
        ob = this_player();
        me = this_object();
        
        if (! arg)
        {
                tell_object(ob, "����Ҫ����ȥ��ʲô���飿��\n");
                return 1;
        }
        
        if (ob->query_temp("warquest/party") != "song")
        {
                tell_object(ob, "�㻹û�вμ��ξ����������������\n");
                return 1;
        }
                
        switch(arg)
        {
        case "enlist":
        case "zhaomu-xinbing" :          
                count = 600000;
                if (WAR_D->query_moneys() < count)
                {
                        tell_object(ob, "���������Ѿ����࣬����������֧����ļ�±��Ŀ�֧��\n");
                        return 1;
                }

                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������б�Ա�ѷ���\n��������ʲ�����ȥ����������ļ�±�" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);
                ob->set("party/party_name", HIY "����" NOR);
                ob->set("party/rank", HIY "����Ӫͳ��" NOR);
                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);
                }
                ob->set_temp("warquest/purchase", "enlist");
                ob->set_temp("warquest/quest", "��ļ�±��������Դ");
                WAR_D->change_moneys(-count);
                ob->command("stock");
                break;
        case "stock-weapon":
        case "gouzhi-bingjia" :
                count = 600000;
                if (WAR_D->query_moneys() < count)
                {
                        tell_object(ob, "���������Ѿ����࣬����������֧�����ñ��׵Ŀ�֧��\n");
                        return 1;
                }

                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������б����Ϳ����ѷ���\n��������ʲ�����ȥ�������ڲɹ������Ϳ���" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);
                ob->set("party/party_name", HIY "����" NOR);
                ob->set("party/rank", HIY "����Ӫͳ��" NOR);
                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);
                }
                ob->set_temp("warquest/purchase", "weapon");
                ob->set_temp("warquest/quest", "���ñ��ף��������");
                WAR_D->change_moneys(-count);
                ob->command("stock");
                break;
        case "stock-arrow":
        case "gouzhi-yujian" :
                count = 600000;
                if (WAR_D->query_moneys() < count)
                {
                        tell_object(ob, "���������Ѿ����࣬����������֧����������Ŀ�֧��\n");
                        return 1;
                }

                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "������Ӫ��¥����ѷ���\n��������ʲ�����ȥ�������ڲɹ����" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);
                ob->set("party/party_name", HIY "����" NOR);
                ob->set("party/rank", HIY "����Ӫͳ��" NOR);
                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);
                }
                ob->set_temp("warquest/purchase", "arrow");
                ob->set_temp("warquest/quest", "����������������");
                WAR_D->change_moneys(-count);
                ob->command("stock");
                break;
        case "stock-horse":
        case "gouzhi-zhanma" :
                count = 600000;
                if (WAR_D->query_moneys() < count)
                {
                        tell_object(ob, "���������Ѿ����࣬����������֧������ս��Ŀ�֧��\n");
                        return 1;
                }

                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "��������ս���ѷ���\n��������ʲ�����ȥ�������ڲɹ�ս��" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);
                ob->set("party/party_name", HIY "����" NOR);
                ob->set("party/rank", HIY "����Ӫͳ��" NOR);
                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);
                }
                ob->set_temp("warquest/purchase", "horse");
                ob->set_temp("warquest/quest", "����ս���������");
                WAR_D->change_moneys(-count);
                ob->command("stock");
                break;
        case "stock-stone":
        case "gouzhi-shimu" :
                count = 600000;
                if (WAR_D->query_moneys() < count)
                {
                        tell_object(ob, "���������Ѿ����࣬����������֧������ʯľ�Ŀ�֧��\n");
                        return 1;
                }

                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������й�ʯ����ľ�ѷ���\n��������ʲ�����ȥ�������ڲɹ�ʯͷ��ľ��" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);
                ob->set("party/party_name", HIY "����" NOR);
                ob->set("party/rank", HIY "����Ӫͳ��" NOR);
                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);
                }
                ob->set_temp("warquest/purchase", "stone");
                ob->set_temp("warquest/quest", "����ʯľ���������");
                WAR_D->change_moneys(-count);
                ob->command("stock");
                break;
        case "guard-xiangyang":
        case "shouwei-xiangyang" :
                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�����ɹ������ɧ���Ҵ��������ǣ�\n��������ʲ�����ȥ����פ�سǳ�" +
                               "���������󣬾����۴���\n" NOR, me, ob);
                ob->set("party/party_name", HIY "����" NOR);
                ob->set("party/rank", HIY "���Ӫͳ��" NOR);

                ob->set_temp("warquest/guard", 1);
                ob->set_temp("warquest/quest", "�����������ȹ̺�");
                // ob->command("guard");
                ob->move("/d/xiangyang/guofuting");
                break;
        case "yayun-liangcao":
        case "escort-forage" :
                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������������ѷ���\n��������ʲ����ڰ����ڽ���ʦ��Ӧ֮����Ѻ��" +
                               "�����У��������󣬾����۴���\n" NOR, me, ob);

                ob->set("party/party_name", HIY "����" NOR);
                ob->set("party/rank", HIY "����Ӫͳ��" NOR);
                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);
                }
                ob->set_temp("warquest/purchase", "forage");
                ob->set_temp("warquest/quest", "Ѻ�����ݣ��������");
                ob->command("stock");
                break;
        case "train-infantry":
        case "xunlian-bubing":
                if (ob->query_temp("warquest/train")
                &&  ob->query_temp("warquest/train") != "infantry")
                {
                        tell_object(ob, "���Ѿ�������ְ�ˣ�\n");
                        return 1;
                }

                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������м�����ս֮ʦ��\n����ӽ�ѵ��һ֧���񲽱����Ա���ʱ֮�裬" +
                               "��������\n" NOR, me, ob);
                ob->set("party/party_name", HIW "����" NOR);
                ob->set("party/rank", HIW "����Ӫͳ��" NOR);
                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);
                }
                ob->set_temp("warquest/train", "infantry");
                ob->set_temp("warquest/quest", "ѵ����������ս׼��");
                ob->command("drill");
                break;

        case "xunlian-qibing":
        case "train-cavalry":
                if (ob->query_temp("warquest/train")
                &&  ob->query_temp("warquest/train") != "cavalry")
                {
                        tell_object(ob, "���Ѿ�������ְ�ˣ�\n");
                        return 1;
                }

                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������м�����ս֮ʦ��\n����ӽ�ѵ��һ֧����������Ա���ʱ֮�裬" +
                               "��������\n" NOR, me, ob);

                ob->set("party/party_name", HIR "����" NOR);
                ob->set("party/rank", HIR "����Ӫͳ��" NOR);
                if (! present("zhan ma", ob))
                {
                        horse = new("/d/city2/song/horse");
                        if (horse->move(environment(ob)))
                                RIDE_CMD->do_ride(ob, horse);
                        else destruct(horse);
                }
                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);
                }
                ob->set_temp("warquest/train", "cavalry");
                ob->set_temp("warquest/quest", "ѵ���������ս׼��");
                ob->command("drill");
                break;

        case "train-archer":
        case "xunlian-gongnu":
                if (ob->query_temp("warquest/train")
                &&  ob->query_temp("warquest/train") != "archer")
                {
                        tell_object(ob, "���Ѿ�������ְ�ˣ�\n");
                        return 1;
                }

                message_vision(HIR "$N��һ��˼���Ӱ�ǰ���һö���������$n���" +
                               "�������м�����ս֮ʦ��\n����ӽ�ѵ��һ֧���񹭼��֣��Ա���ʱ֮�裬" +
                               "��������\n" NOR, me, ob);
                ob->set("party/party_name", HIB "����" NOR);
                ob->set("party/rank", HIB "����Ӫͳ��" NOR);

                if (! present("ling jian", ob))
                {
                        ling = new("/adm/npc/obj/lingjian");
                        ling->set("owner", ob->query("id"));
                        ling->move(ob);
                }

                ob->set_temp("warquest/train", "archer");
                ob->set_temp("warquest/quest", "ѵ����������ս׼��");
                ob->command("drill");
                break;
        default:
                tell_object(ob, "����Ҫ������ʲô���飿��\n");
                return 1;
        }

        message_vision("�ڽ������Ӧ����ĩ����������\n", me, ob);
        return 1;
}

int accept_hit(object me)
{
        if (playerp(me))
        {
                command("heng");
                command("say ��Ҫ��Ҫ������");
                return 0;
        }
}

int accept_fight(object me)
{
        if (playerp(me))
        {
                command("heng");
                command("say ��Ҫ��Ҫ������");
                return 0;
        }
}

int accept_kill(object me)
{
        if (playerp(me))
        {
                message_vision(CYN "$N" CYN "��ŭ�����������������������������˵��һ�ư�$n" CYN
                               "�����ڵء�\n" NOR, this_object(), me);
                me->unconcious();
                return -1;
        }
}
