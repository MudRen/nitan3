// xuelian.c ѩ��
// Modified by Dumbness, 2003-5-21 20:39

#include <ansi.h>;
#include <armor.h>

inherit HEAD;

void init();

void create()
{
        set_name(HIM"ѩ��"NOR, ({"xuelian", "lian", "lotus"}));
        set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIW"����һ�侧Ө��ѩ��������Ȼ������ɫ��ѩɽ֮�����ţ��峺�鶯�������\n�㸧ο������\n"NOR);
                set("value", 20000);
                set("no_sell", 1);
                set("no_put",1);
                set("medicine", 1);
                set("only_do_effect", 1);
                set("armor_prop/personality", 5);
                set("armor_prop/per", 2); 
                set("wear_msg",         
                        HIM"$N����Ĵ����Ƕ䴫˵�е�ѩ�������Լ��·�Ҳ�����һ���Ȼ������ѩɽ\n"
                        "֮�ߵ�ѩ��������ʳ�˼��̻����峺����Ө��͸���۲���ת����һ�����\n"
                        "�����Ӱҹҹ�ǻ������˵����硭��\n"NOR);
                set("remove_msg", WHT"$N����ذ�$n"WHT"��ͷ��ժ����������ʱ��Ȼʧɫ��������ת�鶯��\n"NOR); 
        }
        setup();
}

int do_effect(object me)
{
        if (me->query_condition("cool_drug") > 0)
        {
                me->add("max_jingli", -5);
                me->add("eff_jing", -5);
                message_vision(HIR "$N����һöѩ����ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
                destruct(this_object());
                return 1;
        }
        message_vision(HIM"$N����һ֧ѩ����һ������Ƶ����������ķΣ��پ�������ˬ��\n"NOR, me);
        me->set("eff_jing", (int)me->query("max_jing"));
        me->set("jing", (int)me->query("max_jing"));
        me->set("jingli", (int)me->query("max_jingli"));
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
        me->apply_condition("cool_drug", 30);

        if (random(3)==1)
        { 
                if((me->query_jingli_limit() - me->query("max_jingli")) > 5 )
                {
                        me->add("max_jingli", 5);
                        me->add("eff_jing", 5);
                }
        }

        me->set("neili", (int)me->query("max_neili"));
        me->set("jingli", (int)me->query("max_jingli"));
        
        if ((int)me->query_condition("snake_poison") > 0) 
                me->apply_condition("snake_poison", 0);
  
        if ((int)me->query_condition("insect_poison") > 0) 
                me->apply_condition("insect_poison", 0);
 
        if ((int)me->query_condition("sl_poison") > 0) 
                me->apply_condition("sl_poison", 0);
   
        if ((int)me->query_condition("xx_poison") > 10 
                && (int)me->query_condition("xx_poison") < 50) 
                me->apply_condition("xx_poison", 0);
        destruct(this_object());
        return 1;
}

