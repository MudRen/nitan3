// yinyuan-qian.c ��Եǩ
// By Alf, Last Update 2002.1130

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIM"��Եǩ"NOR, ({"yinyuan qian", "qian"}));
    set_weight(500);
    if(clonep())
        set_default_object(__FILE__);
    else
    {
        set("unit", "֧");
        set("long", HIC"����һ֧����������õ���Եǩ������д�ţ�\n"NOR);
        set("value", 0);
        set("material", "bamboo");
    }
    setup();
}
