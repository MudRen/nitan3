inherit ITEM;
#include <ansi.h>

int do_makeup();
void remove_effect(object);

void create()
{
        set_name(HIR "��֬" NOR, ({ "yan zhi","yanzhi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����Ϻ�õ�廨�����Ѭϸ�˶��ɵ���֬��������ϼ������Ϯ�ˡ�����Ů\n���ӻ�ױ(makeup)�ıر�Ʒ��\n");
                set("value", 1);
        }
}

void init()
{
        add_action("do_makeup", "makeup");
}

int do_makeup()
{
        object me;
        object huafen, you;
        string str;
        
        me = this_player();
        if(me->query_temp("makeuped"))
        {
                write("��ոջ���ױ�������ٻ��ˣ�ױ��̫ŨЧ�����ʵ��䷴�ġ�\n");
                return 0;
        }
        
        str = me->query("gender");
        if( (str != "Ů��") && (str != "����"))
        {
                if(str == "����")
                {
                        write("�����˻�ʲôױ��\n");
                        return 0;
                }
                else
                {
                        write("�㲻���Ի�ױ��\n");
                        return 0;
                }
        }

        huafen = present("huafen dai",me); 
        if(!huafen) 
        {
                write("������۰ɣ�û�л���Ү��\n");
                return 1;
        }
        you = present("baohua you",me); 
        if(!you) 
        {
                write("�����ٻ��Ͱɣ�û���ٻ���Ү��\n");
                return 1;
        }

        message_vision("$N��С��ˢ���ϵ��ٻ��ͣ��������������ҵ�ͷ����\n", me);
        message_vision("$N���·���������С�ĵ�����Щ��֬���ӷ������ģ�������Сָմ��Щ���ڴ��ϣ�\n���Ժ촽�����������Ρ�\n", me);
        if((me->query_per()>25) && (str != "����"))
                message_vision(HIM"$N��ʣ�µ���֬С�ĵ��������ο�����������˫�գ��������գ���������ܽ��Ŀ��\n���꣬������ȻһЦ������ǰ���ǧ����\n"NOR, me);
        else if(me->query_per()<15)
                message_vision(BLU"$N��ʣ�µ���֬С�ĵ��������ο�����������˫�գ��������գ������Լ������İ�\n�������µ�������ױ����������ǲ��ҹ�ά��\n"NOR, me);
        else
                message_vision(HIG"$N��ʣ�µ���֬С�ĵ��������ο�����������˫�գ��������գ��ƺ���Ư���˵㡣\n"NOR, me);

        me->start_busy(5);
        me->add_temp("apply/per", 1); 
        me->set_temp("makeuped", 1);

        destruct(huafen);
        destruct(you);
        destruct(this_object());
        return 1;
}
        
void remove_effect(object me)
{
        if (me->query_temp("makeuped"))
        {
                me->add_temp("apply/per", -1);
                me->delete_temp("makeuped");
                tell_object(me, "æµ��һ�죬���ױȫ���ˣ����Ҹ��ط���ϴһ���ˡ�\n");
        }
}

