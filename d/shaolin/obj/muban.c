inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_climb", "zou");
}

void create()
{
        set_name("ľ��", ({"mu ban", "ban"}));
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���ľ�壬���ڷ����ϡ�\n");
                set("unit", "��");
                set("material", "wood");
        }
        setup();
}

int do_climb(string arg)
{
        object me = this_player();
        
        if (!id(arg))
                return notify_fail("��Ҫ�ߵ��Ķ�ȥ��\n");
        if (this_player()->query_temp("marks/��1") ) 
        {
                write("����ôû��û�˵��ߣ�\n");
                return 1;
        }
        else 
        {
                message("vision",this_player()->name() + "С��������ߵ�ľ����,����ȥ���е㷢��\n",
                        environment(me), ({me}) );
                write("��С��������ߵ���ľ����,����:������û�пָ�֢!��\n");
                this_player()->set_temp("marks/��1", 1);
                return 1;
        }
}


