#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIB "ҹ�Ɑ" NOR,({"yeguangbei"}));
    set_weight(300);
        if( clonep() )
            destruct(this_object());
        else {
        set("long", "һ��ʢ�����ʺ���Ѫ���������Ƶ�ҹ�Ɑ��\n");
                set("unit", "��");
        set("value", 0);
        set("max_liquid", 10);
        } 
        set("owner","������");
        set("liquid", ([
        "type": "alcohol",
        "name": "��������",
                "remaining": 5,
        "drunk_apply": 20,
        ]) );
}       
