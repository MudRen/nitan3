//ren.c

#include <ansi.h>
#include "riyue.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_linghuchong();

void create()
{
        set_name("��ӯӯ", ({ "ren yingying","ren","ying"}) );
        set("gender", "Ů��" );
        set("age", 20);
        set("shen_type", 1);
        set("combat_exp", 500000);

        set("per", 30);
        set("str", 16);
        set("dex", 27);
        set("con", 17);
        set("int", 18);

        set("attitude", "friendly");
        set("chat_chance", 3);
        set("chat_msg",({
        "��ӯӯ˵������֪��������������ˣ��Ƿ��ֺ���С������һ��......\n",
        "��ӯӯ˵����Ҳ��֪����˼�û�����������漱������.......\n",
        }) );

        create_family("�������",2,"���� ʥ��");

        set_skill("force", 100);
        set_skill("riyue-xinfa", 100);
        set_skill("dodge", 100);
        set_skill("piaomiao-shenfa", 100);
        set_skill("hand", 100);
        set_skill("huanmo-longtianwu", 100);
        set_skill("cuff", 100);
        set_skill("xuwu-piaomiao", 100);
        set_skill("parry", 100);
        set_skill("literate", 120);
        set_skill("sword", 100);
        set_skill("riyue-jian", 100);

        map_skill("force", "riyue-xinfa");
        map_skill("dodge", "piaomiao-shenfa");
        map_skill("hand", "huanmo-longtianwu");
        map_skill("cuff", "xuwu-piaomiao");
        map_skill("sword", "riyue-jian");
        map_skill("parry", "riyue-jian");

        prepare_skill("hand", "huanmo-longtianwu");
        prepare_skill("cuff", "xuwu-piaomiao");

        set("inquiry",([
            "�����" : (: ask_linghuchong:),
        ]) );
        set("letter",1);

        set("master_ob",2);
	setup();
        carry_object("/clone/cloth/female5-cloth")->wear();
        carry_object("/d/heimuya/npc/obj/jin")->wear();
        carry_object("/d/heimuya/npc/obj/changjian")->wield();
        carry_object("/d/heimuya/npc/obj/letter");
}

void attempt_apprentice(object ob)
{
    if(! permit_recruit(ob))  return;

    if((int)ob->query("shen") > 0)
    {
         command("say �ҵ��������㣬���ǽ����᲻��Ӧ�ģ�");
         return;
    }

    command("recruit " + ob->query("id"));
    ob->set("title", HIM "������̽���" NOR);
}

string ask_linghuchong()
{
    object me = this_player();
    object ob;

    message_vision("��ӯӯ˵����ȥ���ϻ�ɽһȥ���������ţ������������Ұ�......\n", me );
    if(! query("letter"))
        return "��λ" + RANK_D->query_respect(me) + "�����Ѿ���" +
               "�����ȥѰ���ˣ�Ҳ��֪����ô���ˡ�";
    message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"����������"
                   "�ţ���Ҫ���ҵ�����壬�Ͱ��Ž��������������׵ġ�\n" , me);
    ob=new("/d/heimuya/npc/obj/letter");
    ob->move(me);
    set("letter", 0);
    me->set_temp("ren_qingxin", 1);
    return "����ŷ��㽻������塣\n";
}

void reset()
{
     set("letter", 1);
}

