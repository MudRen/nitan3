#include <ansi.h>
inherit COMBINED_ITEM; 

void create()
{
        set_name(HIY "�ն�" NOR, ({ "you er","you", "er" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����ר���������ո������޵ġ� \n");
                set("base_unit", "��"); 
                set("base_weight", 30); 
                set("base_value", 1000); 
                set("no_sell", "��Ұ�޳ԵĶ�����Ҳ���ң�"); 
                set("lure", 1);
                set("level", 10);
        }
        set_amount(1);
        setup();
}

