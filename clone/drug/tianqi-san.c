// Code of HUAXIA
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY "�����赨ɢ" NOR, ({"tianqi san", "san"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "������һ�������赨ɢ���ɽ⻯ʬ�۶���\n");
                set("value", 10000);
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
   if (!me->query_condition("hsf_poison"))
   {
      tell_object(me, "����û�л�ʬ�۶����ҳ�ҩ���\n");
      return 1;
   }

   message_vision("$N����һ��" + name() + "��\n", me);
   tell_object(me, "���������ǳ��Ŀࡣ\n");

   if ((int)me->query_condition("hsf_poison") < 100) {
      me->clear_condition("hsf_poison");
      tell_object(me, "������˿ڲ�����ʹ����ʬ�۶��Ѿ�����ˡ�\n");
   } else if ((int)me->query_condition("hsf_poison") >= 100)
   {
      me->apply_condition("hsf_poison",(int)me->query_condition("hsf_poison")-90);
      tell_object(me, "����ú�����һ�㣬������ʬ�۶���û����ȫ������\n");
   }

   destruct(this_object());
   return 1;
}

