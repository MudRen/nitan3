//rune02.c

// Eld ����

#include <ansi.h>

inherit ITEM;

int is_rune_ob() { return 1; }
int is_enchase_ob() { return 1; } 
void create()
{
        set_name(HIW "����" NOR, ({ "rune eld", "rune02", "rune"}));
        set_weight(1800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ģ�����(ELD)�����Է��밼����Ʒ��\n");
                set("unit", "��");
                set("enchase/SN", 2);
                set("enchase/type", "all");
                set("enchase/cur_firm", 100); 
                set("enchase/wspe_data", ([
                        "ap_power"      : 5,                 
                ]));
                set("enchase/aspe_data", ([
                        "effqi_recover" : 200,       
                ]));
                set("value", 20000);
        }
        setup();
}

int query_autoload() { return 1; }

