//meat.c
//By Dumbness@HUAXIA 2003-5-9 13:16

inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("����", ({"kaorou", "rou", "fried meat", "meat" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("long", "һ����⿺õ�������Ŀ��⣬�Ѿ�����������ʲô�����ˣ�ֻ�ŵ�һ�ɹɵ������˱Ƕ�����\n");
                set("unit", "��");
                set("food_remaining", 10);
                set("food_supply", 50); 
                set("material", "bone");
        }
        setup();
}

