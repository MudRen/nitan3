// Copyright (C) 2003, by Xlz. All rights reserved.  
// This software can not be used, copied, or modified   
// in any form without the written permission from authors.  
// chi-sword.c ��
// for only one object in mud   

#include <ansi.h>   
#include <weapon.h>   
inherit SWORD;   
inherit F_UNIQUE;   
void create()   
{ 
        set_name(HIR "������" NOR, ({"chixiao sword", "chixiao", "sword"}));   
        set_weight(15000); 
        if (clonep())   
                set_default_object(__FILE__);   
        else {
                set("unit", "��");   
                set("long", HIY "����һ�������߲��顢�Ż���ĺ�����ˡ�����˪ѩ�ı�����\n"
                                "��ѽ�����ն������ĳ���������������һ�ѵ۵�֮����\n" NOR);
        set("value", 100000);  
        set("material", "steel");  
        set("no_sell", "�ҵ��졭�㡭��֪������ɶô������Ҳ����������");   
        set("unique", 1);     
        set("rigidity", 500);   
        set("replica_ob", "/clone/weapon/changjian");  
        set("no_put",1);
        set("no_steal",1); 
        set("wield_msg",HIR"$N[��]��һ�����һ�ѳལ����Ȼ���Ա�����һ��������Χ��$Nת��\n"NOR);   
        set("unwield_msg",HIR"$N�����еĳལ���뽣�ʣ�������������ɵ���գ���ʧ�ˡ�\n"NOR);    
        } 
        init_sword(900);   
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)  
{ 
        victim->receive_damage("jing", me->query("str") * 2, me);  
        victim->receive_wound("jing", me->query("str") * 2, me);  
        return HIR "�ལ[��]һ���죬���ǣ����������ſھ�ҧ$n"  
               HIR "��$nֻ���������¡�\n" NOR; 
}
