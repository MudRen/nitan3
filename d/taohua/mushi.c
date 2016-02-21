inherit ROOM;

void create()
{
  
        set("short", "Ĺ��");
        set("long", @LONG
����һ�����Ĺ�ҡ�Ĺ�Ҷ�����һ���ر�����������
���⡣�������һ����ף���Χ��ѷ����������������档��
�Ź���������ǰ,���Ϸ�������(panzi).Ĺ�Ҷ�������������
���Ļ��񡣻����ϵ��ٸ���Ц��Ȼ���ͲҰ׵���׼������͵�
����γ���һ�����Ļ��档
LONG);
        set("exits", ([
                "up" : __DIR__"mudao",
        ]));

        if (random(1000) > 998)
                set("objects", ([
                        "/clone/money/gold" : 10,
                        "/clone/fam/item/haoyue" : 1,
                        "/clone/fam/etc/lv5b" : 1,
                ]));
	else
        if (random(100) > 98)
                set("objects", ([
                        "/clone/money/gold" : 5,
                        "/clone/fam/etc/lv5a" : 1,
                ]));
	else
        if (random(100) > 97)
                set("objects", ([
                        "/clone/money/gold" : 5,
                        "/clone/fam/etc/lv5d" : 1,
                ]));
	else
        if (random(10) > 8)
                set("objects", ([
                        "/clone/money/gold" : 1,
                ]));

        set("item_desc", ([
                "panzi" : @TEXT
    ����ϸ����һ�����ӣ�����һ�����̣�����������ž�Ө��
    ���顣��Щ�����ƺ������ó���(pick zhu)��
TEXT
        ]) );

        setup();
}

void init()
{           object me = this_player();
            add_action("do_pick","pick");
            me->set_temp("taohua/Ĺ��", 0); 
}
void reset()
{
        ::reset();
        set("pick_available" , 6);
}
int do_pick(string arg)
{
       object me,obj,killer;

       me = this_player();
       if( !arg || arg!="zhu" )
              return notify_fail("��Ҫ��ʲô? \n");
         if (me->is_busy()) return notify_fail("������æ���أ�\n");
/*
       if( me->query("family/family_name") == "�һ���" )
              return notify_fail("�����һ�������, ����͵�����Ķ���? \n");
*/
       if ( query("pick_available") )
       {
         message_vision("$N���������ó���һ�����顣\n",this_player() );
         obj = new ("/d/taohua/obj/mingzhu");
         obj->move(me);
         add("pick_available", -1);
         me->start_busy(3);
         if ( me->query_temp("taohua/Ĺ��") ) return 1;
         killer = new ("/d/taohua/npc/shoumu") ;
         message_vision("\nͻȻĹ���д���һ�����ţ��������߳�һ����Ĺ��ū��\n"
         "��$N�ȵ������ӸҶ��������˵Ķ�����Ҳ�Ҷ���\n", me);
         killer->move(environment(me));
         killer->kill_ob(me);
         me->set_temp("taohua/Ĺ��", 1);
       }
       return 1;
}

