//rune29.c

// Sur ɪ

#include <ansi.h>

inherit ITEM;

int is_rune_ob() { return 1; }
int is_enchase_ob() { return 1; } 
void create()
{
        set_name(HIW "����" NOR, ({ "rune sur", "rune29", "rune"}));
        set_weight(1800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ģ�ɪ(SUR)�����Է��밼����Ʒ��\n");
                set("unit", "��");
                set("enchase/SN", 29);
                set("enchase/type", "all");
                set("enchase/cur_firm", 100); 
                set("enchase/wspe_data", ([
                        "ap_power"      : 50,              
                ]));
                set("enchase/aspe_data", ([
                        "armor"         : 3000,   
                ]));
                set("value", 20000);
        }
        setup();
}

int query_autoload() { return 1; }

