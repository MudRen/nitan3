#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("��٤��", ({ "shu", "book" }));
        set_weight(50);
        set("no_drop", "�������������뿪�㡣\n");
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long",
                        "����һ��𾭡����ļз���д��һЩ�ּ�ģ�����־䣬�ƺ��ᵽһЩ��������ʲ��ġ�\n");
                set("value", 500);
                set("material", "silk");
        }
}

void init()
{
        if( this_player() == environment() )
        {
                add_action("do_qu", "qu");
                add_action("do_qu", "na");
        }
}

int do_qu(string arg)
{
        object me, book;
        
        me = this_player();

        if (! arg || ! id(arg))
                return 0;

        if (! me->query("jiuyang/zhang"))
        {
                write("ʲô��\n");
                return 1;
        }

        message_vision(WHT "\n$N" WHT "�𿪾��ļз죬�����������и��ؼ�"
                       "��д�š�" HIR "�����澭"
                       NOR + WHT "����\n" NOR, me);

        tell_object(me, HIC "������һ�������澭��\n" NOR);
        
        book = new("/clone/book/jiuyang-book");
        book->move(me, 1);
        destruct(this_object());
        return 1;
}
