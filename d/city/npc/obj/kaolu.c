//kaolu.c
//By Dumbness@HUAXIA 2003-5-9 13:16

inherit ITEM;

void create()
{
        set_name("С��¯", ({ "kaolu" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("value", 100000);
                set("material", "stone");
                set("long", "һ�������Ƴɵ�С��¯�����ƺ�������������������Щʲô\n");
        }
        
        setup();
}
void init()
{
        add_action("do_kao","kao");
        add_action("do_kao","fry");
}                             

int do_kao(string arg)
{
        object me;
        object tar;
        object meat;
        string name;
        int supply;
        me = this_player();

        if( !arg || arg == "")
                return notify_fail("�㿾ʲô��\n");
        if(!objectp(tar = present(arg, me)) )
                return notify_fail("�㿾ʲô��\n");
        if(tar->is_character() && !tar->is_corpse())
                return notify_fail("��...���������к���֮�£��㻹�������������ɣ�\n");
        if( !tar->is_character() && !tar->is_corpse())
                return notify_fail("�����㲻���Կ��Ķ�����\n");

        supply = me->query_skill("cooking");
        if ( supply < 30) 
                return notify_fail("��ĳ�������̫�������ѧ����հɣ�\n"); 
                
        if( tar->is_corpse())
        {
                name=tar->query("name");
                name=replace_string(name,"һ��","");
                name=replace_string(name,"��ʬ��","");
                if (name=="����")         
                        return notify_fail("�����������ˣ�����ʲô����\n");
                else
                        name="��"+name+"��";

                supply = supply/20;
                if(supply<=0) supply = 1;
                        
                meat = new("/d/city/npc/obj/meat");
                meat->set_name(name, ({"kaorou", "rou", "fried meat", "meat" }) );
                meat->set("food_remaining", supply);
                meat->move(me);
        }

        message_vision("$N��$n�г�Ƭ�ŵ�С��¯�$nһ����ͱ����һ��������Ŀ��⴮��\n", me, tar);
        tar->move(environment(me));
        destruct(tar);
        return 1;
}


