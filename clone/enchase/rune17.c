//rune17.c

// Lum �Rķ

#include <ansi.h>

inherit ITEM;

int is_rune_ob() { return 1; }
int is_enchase_ob() { return 1; } 
void create()
{
        set_name(HIW "����" NOR, ({ "rune lum", "rune17", "rune"}));
        set_weight(1800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ģ��Rķ(KUM)�����Է��밼����Ʒ��\n");
                set("unit", "��");
                set("enchase/SN", 17);
                set("enchase/type", "all");
                set("enchase/cur_firm", 100); 
                set("enchase/wspe_data", ([
                        "add_lighting"   : 20,               
                ]));
                set("enchase/aspe_data", ([
                        "avoid_lighting" : 10,     
                ]));
                set("value", 20000);
        }
        setup();
}

int query_autoload() { return 1; }

