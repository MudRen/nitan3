//rune28.c

// Lo �_

#include <ansi.h>

inherit ITEM;

int is_rune_ob() { return 1; }
int is_enchase_ob() { return 1; } 
void create()
{
        set_name(HIW "����" NOR, ({ "rune lo", "rune28", "rune"}));
        set_weight(1800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ģ��_(LO)�����Է��밼����Ʒ��\n");
                set("unit", "��");
                set("enchase/SN", 28);
                set("enchase/type", "all");
                set("enchase/cur_firm", 100); 
                set("enchase/wspe_data", ([
                        "avoid_parry"   : 40,              
                ]));
                set("enchase/aspe_data", ([
                        "dp_power"      : 10,   
                ]));
                set("value", 20000);
        }
        setup();
}

int query_autoload() { return 1; }

