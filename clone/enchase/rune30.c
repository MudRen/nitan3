//rune30.c

// Ber ؐ

#include <ansi.h>

inherit ITEM;

int is_rune_ob() { return 1; }
int is_enchase_ob() { return 1; } 
void create()
{
        set_name(HIW "����" NOR, ({ "rune ber", "rune30", "rune"}));
        set_weight(1800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ģ�ؐ(BER)�����Է��밼����Ʒ��\n");
                set("unit", "��");
                set("enchase/SN", 30);
                set("enchase/type", "all");
                set("enchase/cur_firm", 100); 
                set("enchase/wspe_data", ([
                        "da_power"      : 50,              
                ]));
                set("enchase/aspe_data", ([
                        "unarmed_damage": 1000,   
                ]));
                set("value", 20000);
        }
        setup();
}

int query_autoload() { return 1; }

