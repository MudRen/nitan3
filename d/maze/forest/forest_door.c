#include <ansi.h>
inherit ITEM;

void create()
{
                
        set_name(HIG"ԭʼɭ�����"NOR, ({ "forest door","door"}) );
        set_weight(5);
        set("no_get",1);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"�������ڿ��Խ���ԭʼɭ���Թ�������(enter door)\n"NOR); 
                set("unit", "��");
                set("lore",1);
                set("value", 20);
        }
        setup();
}
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg) {
        int time;
        if (arg!="door")
                return 0;
        if (count_gt(this_player()->query("combat_exp"), 100000000))
                return notify_fail("���Ѿ����������ˣ����ǲ�Ҫ��ȥ�ˣ�\n");

        this_player()->delete_temp("maze");
        time = this_player()->query_temp("maze/time")+180-time();
        if(time>0)
                return notify_fail("�㻹��Ҫ��"+CHINESE_D->chinese_period(time)+"���ܽ���ԭʼɭ���Թ�������\n");
        MAZE_D->enter_maze(this_player(), "forest");
        return 1;
}

