// tiexiao.c ����
#include <ansi.h>
#include <music.h> 

inherit ITEM;
inherit "/inherit/misc/_xiao";

void create()
{
        set_name(YEL "����" NOR,({ "tie xiao", "xiao" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("value", 300);
                set("material", "steel");
                set("long", "һ����ͨ���ƶ����������Щ׹�֡�\n");
        }
        setup();

}

void init() 
{
        add_action("play_xiao", "play"); 
}
