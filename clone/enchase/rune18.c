//rune18.c

// Ko ��

#include <ansi.h>

inherit ITEM;

int is_rune_ob() { return 1; }
int is_enchase_ob() { return 1; } 
void create()
{
        set_name(HIW "����" NOR, ({ "rune ko", "rune18", "rune"}));
        set_weight(1800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ģ���(KO)�����Է��밼����Ʒ��\n");
                set("unit", "��");
                set("enchase/SN", 18);
                set("enchase/type", "all");
                set("enchase/cur_firm", 100); 
                set("enchase/wspe_data", ([
                        "add_fire"     : 30,               
                ]));
                set("enchase/aspe_data", ([
                        "avoid_fire"   : 10,     
                ]));
                set("value", 20000);
        }
        setup();
}

int query_autoload() { return 1; }

