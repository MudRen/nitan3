// pi.c ����ˤ�ӵ��㽶Ƥ
// By Alf, Last Update 2002.0915

#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIY"�㽶Ƥ"NOR,({"xiangjiao pi","pi"}));
    set_weight(200);
    if(clonep())
        set_default_object(__FILE__);
    else
    {
        set("unit","��");
        set("long","һ���㽶Ƥ��\n");
        set("no_get","һ���㽶Ƥ�������˲����ˣ���Ҳ���Ӷ��ģ�\n");
        set("value",1);
        set("env/invisible",1);
        set("pi_gone",10+random(10));
    }
    setup();
}
 

void init()
{
    int chance,age;
    object me,ob;
    string msg;
    me = this_player();
    ob = this_object();

    age = 60 - me->query("age");
    if (age < 0) age = 0;
    chance = (me->query_dex() + age)/2;
    
    if(interactive(me) && living(me) && random(chance) == 1) 
    {
        msg = HIY""+me->name()+"��С�Ĳ����㽶Ƥ�ϣ������ˡ�һ��ˤ�˸�����ſ";
        me->start_busy(2);
        
        if(ob->query("pi_gone") <= 0)
        {
            msg += "���㽶Ƥȴ��֪����ȥ�ˡ�\n";
            tell_room(environment(me),msg);
            destruct(ob);
        }
        else
        {
            ob->set("long","һ���㽶Ƥ����֪����˭���ġ�\n");
            ob->set("env/invisible",0);
            ob->add("pi_gone",-1);
            msg += "��\n"+me->name()+"վ��������������ƨ�ɣ�һ����ɱ���������̵ĵ�����˭�ɵģ���\n"NOR;
            tell_room(environment(me),msg);
        }
    }
}

