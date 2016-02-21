// xiang.c
//Update by haiyan

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int ask_kill();
mixed ask_pfm();

void create()
{
    set_name("������", ({ "xiang wentian", "xiang"}));
    set("nickname", HIR "��������" NOR );
    set("gender", "����");
    set("title", "������̹�����ʹ");
    set("long", "������������̵Ĺ�����ʹ��Ϊ�˼�Ϊ��ˬ��\n");
    set("age", 56);
    set("shen_type", -1);
    set("attitude", "peaceful"); 

    set("str", 21);
    set("per", 28);
    set("int", 30);
    set("con", 26);
    set("dex", 30);
    set("chat_chance", 1);
    set("inquiry", ([
      "����ͤ"     : "�����ˣ���ɱ��\n",
      "��������"   : "��λ��ͽ���ҷ�ɱ�������ɣ�\n",
      "������"     : "��������������ʮ��......\n",
      "ɱ��������" : (: ask_kill :),
      "������ˮ"   : (: ask_pfm :),
      "����"       : (: ask_pfm :),
    ]));
    set("qi", 4000);
    set("max_qi", 4000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 3500);
    set("max_neili", 3500);
    set("jiali", 350);

    set("combat_exp", 2500000);
    set("score", 0);

    set_skill("force", 150);
    set_skill("riyue-xinfa", 150);
    set_skill("dodge", 150);
    set_skill("piaomiao-shenfa", 150);
    set_skill("hand", 150);
    set_skill("huanmo-longtianwu", 150);
    set_skill("cuff", 150);
    set_skill("xuwu-piaomiao", 150);
    set_skill("parry", 150);
    set_skill("whip", 180);
    set_skill("liushui-bian", 180);
    set_skill("literate", 110);

    set_skill("sword", 150);
    set_skill("riyue-jian", 150);
    map_skill("sword", "riyue-jian");
    map_skill("force", "riyue-xinfa");
    map_skill("dodge", "piaomiao-shenfa");
    map_skill("hand", "huanmo-longtianwu");
    map_skill("cuff", "xuwu-piaomiao");
    map_skill("parry", "liushui-bian");
    map_skill("whip", "liushui-bian");

    prepare_skill("hand", "huanmo-longtianwu");
    prepare_skill("cuff", "xuwu-piaomiao");

    create_family("�������", 2, "������ʹ");
    set("have_ling",1);
    set("master_ob",3);
	setup();
    carry_object("/d/heimuya/npc/obj/cloth")->wear();
    carry_object("/clone/weapon/changbian")->wield();
}

void attempt_apprentice(object ob)
{
    if (ob->query("family/family_name") == "�������")
        command("say �Ϸ��Ѳ��յ��ӣ�������������һ�ױ޷���������ѧ���ҿ��Խ��㡣");
    else
        command("say �Ҳ��յ��ӡ�");
    return;
}

int recognize_apprentice(object ob, string skill)
{
     if (ob->query("family/family_name") == "�������")
     {
         if (skill != "whip" && skill != "liushui-bian")
         {
             command("say ��ֻ���޷�������������ʦ��ȥѧ��");
             return -1;
         }

         if (ob->query("character") == "��������" && skill == "liushui-bian")
         {
             command("say �㲻�ʺ�ѧ�����ž�����");
             return -1;
         }

         if (ob->query("shen") > 0)
         {
             command("heng");
             command("say ���Ȼ�������ɾ��ӣ���ѧ�����ֵ��С����ʲô��");
             return -1;
         }

         if (skill == "liushui-bian" && ob->query_skill("whip", 1) < 150)
         {
             command("say ��Ի����޷������Ҳδ��̫���˵㡣");
             return -1;
         }

         if (skill == "whip")
         {
             if (!ob->query("can_learn/xiang/whip"))
             {
                  command("say �ðɣ��Ҿͽ���һ����ڱ޷��Ļ���֪ʶ��");
                  ob->set("can_learn/xiang/whip", 1);
             }
             return 1;
         }

         if (skill == "liushui-bian")
         {
             if (!ob->query("can_learn/xiang/liushui-bian"))
             {
                  command("say �ܺã�����ʹ�����ˮ�޷���");
                  ob->set("can_learn/xiang/liushui-bian", 1);
             }
             return 1;
         }
     }
     return 0;
}

mixed ask_pfm()
{
      object me = this_player();

      if (me->query("can_perform/liushui-bian/wang"))
              return "��Ҫ���Ϸ��д�һ����";

      if (me->query("family/family_name") != query("family/family_name"))
              return "������书�������֣���λ" + RANK_D->query_respect(me) +
                     "��Ȼ��ѧ���������������Σ�";

      if (me->query_skill("liushui-bian", 1) < 180)
              return "�����ˮ�޷����������ң�������ô�����أ�";

      message_vision(HIY "$n" HIY "��$N" HIY "���˵�ͷ���㿴�ǿ��ʯ��\n" HIY
                     "ֻ��$n" HIY "���г���һ������Ȼ���ϻӳ���ֻ������" HIY
                     "����һ�����ߣ�ֱ���ʯ��ȥ��\n" HIW
                     "���ȡ���һ������ʯ�ѱ������Ƭ�����·�ɢ��\n" NOR,
                     me, this_object());
      command("say �㿴����û�У�");
      tell_object(me, HIY "��ѧ���ˡ�������ˮ����һ�С�\n" NOR);
      if (me->can_improve_skill("whip"))
            me->improve_skill("whip", 160000);
      me->set("can_perform/liushui-bian/wang", 1);
      return 1;
}

int ask_kill()
{
      object ob, me = this_player();
      if (!query("have_ling"))
            command("say �ҵ������������Ѿ��������ˣ���ô����ȥ��");
      else
      {
            command("tell " + me->query("id") + " ��Ҫȥɱ�������ܣ�\n");
            message_vision(HIC "�������$N���˵�ͷ˵��������һ��֮����\n" NOR, me);
            ob=new("/d/heimuya/npc/obj/card4");
            ob->move(me);
            delete("have_ling");
            tell_object(me, "������ӻ�������һ����������������ϡ�\n");
      }
      return 1;
}

void reset()
{
      set("have_ling",1);
}
