#include <weapon.h>
#include <ansi.h>
inherit TASK;
void create()
{
        set_name(MAG"�˵�"NOR, ({ "yan dao", "dao" }) );
        set_weight(4000);
        if( clonep() )
            destruct(this_object());
        else {
                set("unit", "��");
                set("jungle",1);
                set("material", "iron");
                set("long", "����һ��ר���˸�̫����˵���\n");
                set("wield_msg", "$N���һ�Ѻ����͵�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n�������䡣\n");
        }
        set("owner", "������");
} 
