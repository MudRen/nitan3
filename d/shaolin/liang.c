#include <room.h>

inherit ROOM;

void create()
{ 
       set("short","�ؾ�����");
       set("long", @LONG
�������ڲؾ���ķ��������¹��ƣ���Χ����һЩ�ߴ�����(shujia)��
LONG );
        set("exits", ([
                "down" : __DIR__"cjlou1",
        ]));       
        set("item_desc", ([
                "shujia" : "��ܶ��ϻ����˺��Ļҳ���\n",
                "���"   : "��ܶ��ϻ����˺��Ļҳ���\n",
        ]) ); 
        set("objects", ([
                "/d/shaolin/obj/muban" : 1,
         ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return 0;
        if( arg == "shujia" )
        {
                if (me->query_temp("marks/��1") ) 
                {
                        if (me->query_skill("dodge",1)<100)
                                write("����ͼ������ܵĶ��ˣ�������������ȥ��\n");
                        else 
                        {
                                write("������Ծ������ܶ��ˡ�\n");
                                message("vision",
                                        me->name() + "һ����Ծ������ܶ��ˡ�\n",
                                        environment(me), ({me}) );
                                me->move("/d/shaolin/shujiad");

                        }

                        return 1;
                }
        }
}

int valid_leave(object me, string dir)
{
        me->delete_temp("marks/��1");
        return ::valid_leave(me, dir);
}


