// fengjiang.c ��佬
// By Lgg,1998.9

#include <ansi.h>
inherit ITEM;

int decayed = 0;
void create()
{
        set_name("��佬", ({"jiang", "feng jiang"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һƿ����䳲���ɵĽ���\n");
                set("unit", "ƿ");
                set("value", 30);
                set("only_do_effect", 1); 
                set("can_fulan",1);
        }
}

int do_effect(object me)
{
        me->set("jing", (int)me->query("max_jing"));
        message_vision(HIY"$N������һƿ��佬������佬�ǳ��ĸ���ʵ���Ǻóԡ�\n"NOR,me);
        if (me->query_condition("yufengdu") > 0)
        {
                me->clear_condition("yufengdu");
                tell_object(me,HIY "��о����ڵķ䶾��������ȥ��\n" NOR, me);
        }
        destruct(this_object());
        return 1;
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

