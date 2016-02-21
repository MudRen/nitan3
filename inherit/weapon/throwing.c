// throwing.c

#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

varargs void init_throwing(int damage, int flag)
{
	if (clonep(this_object())) return;

	set("weapon_prop/damage", damage);
	set("flag", POINTED);
}

void setup()
{
	if (clonep(this_object())) return;

        set("no_wield", "������������װ���ġ�\n");
	set("skill_type", "throwing");
        set("consistence", 100);
	if (! query("actions"))
        {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "throw" }) );
                set("stable", 0);
	}
}

string extra_long()
{
        string str;
        
        str =  "��Ʒ����    ��    ����\n";
        str += "��    ��    ��    ����\n";
        str += sprintf("��    ��    ��    %d\n", query("weapon_prop/damage"));
        str += sprintf("��    ��    ��    %d\n", this_object()->query_weight());
        str += sprintf("ɱ    ¾    ��    %d\n", query("combat/PKS"));
        str += sprintf("ʹ�÷�ʽ    ��    ����ָ�� hand %s װ����\n", query("id"));
        str += sprintf("                  ����ָ�� hand none ж�¡�\n", query("id"));
        if (this_object()->query_autoload())
                str += "���߶�ʧ    ��    ��\n";
        else
                str += "���߶�ʧ    ��    ��\n";
        return str;
}
