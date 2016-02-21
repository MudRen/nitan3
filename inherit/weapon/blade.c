// blade.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_blade(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	set("skill_type", "blade");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "hack" }) );
	}
}

string extra_long()
{
        string str;
        
        str =  "��Ʒ����    ��    ����\n";
        str += "��    ��    ��    ��\n";
        str += sprintf("��    ��    ��    %d\n", query("weapon_prop/damage"));
        str += sprintf("��    ��    ��    %d\n", this_object()->query_weight());
        str += sprintf("ɱ    ¾    ��    %d\n", query("combat/PKS"));
        str += sprintf("ʹ�÷�ʽ    ��    ����ָ�� wield %s װ����\n", query("id"));
        str += sprintf("                  ����ָ�� unwield %s ж�¡�\n", query("id"));
        if (this_object()->query_autoload())
                str += "���߶�ʧ    ��    ��\n";
        else
                str += "���߶�ʧ    ��    ��\n";
        return str;
}
