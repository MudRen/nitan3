//rune12.c

// Sol ����

#include <ansi.h>

inherit ITEM;

int is_rune_ob() { return 1; }
int is_enchase_ob() { return 1; } 
void create()
{
        set_name(HIW "����" NOR, ({ "rune sol", "rune12", "rune"}));
        set_weight(1800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ģ�����(SOL)�����Է��밼����Ʒ��\n");
                set("unit", "��");
                set("enchase/SN", 12);
                set("enchase/type", "all");
                set("enchase/cur_firm", 100); 
                set("enchase/wspe_data", ([
                        "da_power"      : 20,                 
                ]));
                set("enchase/aspe_data", ([
                        "derive_effect"  : 10,       
                ]));
                set("value", 20000);
        }
        setup();
}

int query_autoload() { return 1; }

