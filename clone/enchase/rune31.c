//rune31.c

// Jah ��

#include <ansi.h>

inherit ITEM;

int is_rune_ob() { return 1; }
int is_enchase_ob() { return 1; } 
void create()
{
        set_name(HIW "����" NOR, ({ "rune jah", "rune31", "rune"}));
        set_weight(1800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ģ���(JAH)�����Է��밼����Ʒ��\n");
                set("unit", "��");
                set("enchase/SN", 31);
                set("enchase/type", "all");
                set("enchase/cur_firm", 100); 
                set("enchase/wspe_data", ([
                        "damage"        : 3000,              
                ]));
                set("enchase/aspe_data", ([
                        "derive_effect" : 20,   
                        "research_effect" : 20,   
                ]));
                set("value", 20000);
        }
        setup();
}

int query_autoload() { return 1; }

