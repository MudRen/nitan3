//rune13.c

// Shael ɳ��

#include <ansi.h>

inherit ITEM;

int is_rune_ob() { return 1; }
int is_enchase_ob() { return 1; } 
void create()
{
        set_name(HIW "����" NOR, ({ "rune shael", "rune13", "rune"}));
        set_weight(1800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ģ�ɳ��(SHAEL)�����Է��밼����Ʒ��\n");
                set("unit", "��");
                set("enchase/SN", 13);
                set("enchase/type", "all");
                set("enchase/cur_firm", 100); 
                set("enchase/wspe_data", ([
                        "damage"        : 1000,                 
                ]));
                set("enchase/aspe_data", ([
                        "practice_effect": 10,
                ]));
                set("value", 20000);
        }
        setup();
}

int query_autoload() { return 1; }

