//meipo.c

#include <ansi.h>
inherit NPC;

string ask_hunyin();

void create()
{
      set_name("��ý��",({"mei po", "mei"}));
      set("age", 65);
      set("gender", "Ů��");
      set("nickname", "��Ե�춨");
      set_skill("unarmed", 40);

      set("inquiry",([
            "���ܶ���" :  (: ask_hunyin :),
      ]));

        set("chat_chance", 15); 
        set("chat_msg", ({ 
                "��ý�����������˵������˵��ɽ���д�˵�е�ѩ�������ǿ����͸���������õ�����Ŷ��\n",
                "��ý��ڨڨ��˵������������Ǹ�ȳ�ӣ��������ҿ�û˵�����ǰ�����޶����ˣ����ܹ��ң�\n",
                "��ý��͵͵һЦ����ѩ�������������ǻ�����ò�����������ӿ�Ҫ����������£����ܾ���ô������С���ӡ�\n"
        }) ); 

      setup();
      carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
      object ob;

      ::init();

      if (interactive(ob=this_player())&&!is_fighting())
      {
           remove_call_out("greeting");
           call_out("greeting", 1, ob);
      }
      add_action("do_agree", "agree");
}

void greeting(object ob)
{
      if (!ob||environment(ob)!=environment())   return;
      if (ob->query("age") >= 18 && !ob->query("couple"))
      {
           if (ob->query("gender") == "����")
           {
                 message_vision("$N��$nҡͷ̾������ϧ�Ǹ�̫�࣬��ȻҲ��" +
                                "Ȣϱ����ʱ���ˡ�\n", this_object(), ob);
                 return;
           }

           if (ob->query("gender") == "����")
           {
                 if (ob->query("per") < 20)

                 message_vision("$N����$n������һ������λ���ӿ���Ҫ������" +
                                "������ܶ������ģ�\n", this_object(), ob);
                 else

                 message_vision("$N����ǰ��$n��������һ���˲ģ���Ҫ������" +
                                "������ܶ���\n", this_object(), ob);
                 return;
           }

           if (ob->query("gender") == "Ů��")
           {
                 if (ob->query("per") < 20)

                 message_vision("$N����$n��̾�˿�������λ�����䲻��ޣ���Ҫ��" +
                                "�����˼�ȴ�����£�\n", this_object(), ob);
                 else

                 message_vision("$N����ǰ��$n�����ÿ��ε��˶�����Ҫ������" +
                                "������ܶ���\n", this_object(), ob);
                 return;
           }
      }
      return;
}

string ask_hunyin()
{
      object *list = users();
      object ob = this_player();
      string who, gender = ob->query("gender");
      int i, p;

      if (gender == "����")
           return "�����̫�࣬�����Ҷ����麦�ˣ�";

      if (ob->query("couple"))
           return "�㶼�ǽ��˻������, ����ʲô����";

      if (ob->query("age") < 18)
           return "��ôС�����Ҷ�������������\n";

      if (ob->query_temp("mameipo/agree"))
           return "��ô��" + ob->query_temp("mameipo/agree") +
                  "��û�д�Ӧ������������\n";

      i = 0;
      while ( i <sizeof(list))
      {
           if (list[i]->query("gender") == gender ||
               list[i]->query("gender") == "����" ||
               list[i]->query("age") < 18 ||
               list[i]->query("age") > ob->query("age") + 5 ||
               list[i]->query("age") < ob->query("age") - 5 ||
               list[i]->query("class") == "bonze" ||
               list[i]->query("couple"))
           list[i] = 0;
           i++;
      }

      list -= ({ 0 });
      if ( sizeof(list) > 0 )
      {
           p = random(sizeof(list));
           who = list[p]->query("id");
           ob->set_temp("mameipo/who", who);
           return "����" + list[p]->query("name") + "(" + list[p]->query("id") + ")" +
                  "��������䣬��������Σ�(agree)\n";
      }
      else   return "��ʱ���Ҳ�������������ˡ�";
}

int do_agree()
{
      object who, ob = this_player();

      if (!ob->query_temp("mameipo/who"))
      {
           tell_object(ob, "��ý�Ŷ�����������������Ӹ�����ܶ���ô��\n");
           return 1;
      }

      tell_object(ob, HIC"��ý�Ŷ����������ˣ������Ӿ͸��������¶����Է�˵˵��\n"NOR);
      who = find_player(ob->query_temp("mameipo/who"));
      if (!who)
      {
           tell_object(ob,HIC"��ý�Ŷ��������ϧ�������������Ҳ�����������ˡ�\n"NOR);
           return 1;
      }

      tell_object(who, ob->query("name") + "�л�ý�Ÿ���������"+ HIR +"��õ��"NOR+"��\n");
      command("tell " + ob->query_temp("mameipo/who") + " " + ob->query("name") + "(" +
              ob->query("id") + ")���������˼���������Ӹ���˵˵��\n");
      new("/d/city/obj/rrose")->move(who);
      tell_object(ob, HIC"��ý�Ŷ�������������Ѿ��������˼ת���ˣ������ȥ���װɡ�\n"NOR);
      ob->delete_temp("mameipo/who");
      ob->set_temp("mameipo/agree", who->query("name") + "(" + who->query("id") + ")");
      return 1;
}

