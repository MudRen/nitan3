#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIR "���" NOR, ({ "hongbao" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ��СС�ĺ�����������ţ������ĳ����ơ�\n");
          }
    set("owner", "������");
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg)
{
        object gold;
        if(arg != "hongbao" && arg != "���") return 0;
        if(query("opened"))
                return notify_fail("���С������������ǿյģ�\n");
        gold = new("/clone/money/gold");
        gold->set_amount(2);
        gold->set("name","����Ҷ��");
        gold->set("base_unit","��");
        gold->move(this_player());
        set("opened",1);
        return notify_fail("���С������������ó����Ŵ���Ҷ�ӣ�\n");
}
