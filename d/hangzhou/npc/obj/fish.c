// fish.c ��������
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

int decayed = 0;
void create()
{
        set_name(RED"��������"NOR, ({"fish"}));
        set_weight(1300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������˵��������㣬�������еĽ�ɫ����
���ƶ��ɣ���������һ���ˡ�\n");
                set("unit", "��");
                set("value", 120);
                set("food_remaining", 20);
                set("food_supply", 20);
        }
}
void decay(int phase) 
{
        string msg;
        object env;
        env = environment();
        decayed = phase;
        set("on_fulan",1);
        set("value",0);
        set("food_remaining",0);
        switch(phase)
        {
                case 1:
                        msg =  name(1) + "��ʼ�����ˣ�����һ�����ŵ���ζ��\n";
                        set("old_name",name(1));
                        set_name("���ʵ�" + query("old_name"),({ query("id") }));
                        call_out("decay", 120, phase + 1);
                        break;
                case 2:
                        msg = name(1) + "��ʼ�����ˣ����泤�������ë���������ŵĳ�ζ��\n";
                        set_name("���õ�" + query("old_name"),({ query("id") }));
                        call_out("decay", 60, phase + 1);
                        break;
                case 3:
                        msg = "һ��紵������" + name(1) + "���ɻҴ�ɢ�ˡ�\n";
                        if( env )
                                all_inventory(this_object())->move(env);
                        tell_room(env, msg);
                        destruct(this_object());
                        return;
        }
        while (env && env->is_character())
                env = environment(env);
        if (env) tell_room(env, msg); 
}
