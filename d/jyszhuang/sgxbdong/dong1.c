#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIW"̫��"NOR);
        set("long", @LONG
�������Ϲ�ʱ������һ�����ض�Ѩ����˵����������Ϲ�ʱ������������
һ����Ϊ̫���ı�����������Щ��ѽѽ�ģ���֪������ʲô���ء�    
LONG );
        set("indoors", "city");
        set("exits", ([
        "south":   __DIR__"dongkou",
        ]));
        set("no_fly",1);
        set("no_clean_up", 0);
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_beg", "1");
        setup();
}
void init()
{
       if(this_player()->query("zhuanshi/jineng"))
       add_action("do_break","break");
       else
       {
        message_vision(HIY"��Ȼ���п�������$N�����һ�Ѿ���"
        +"ת�۲�֪ȥ��\n"NOR,this_player());
        this_player()->move(__DIR__"yongdao");
       }
}

int do_break(string arg)
{
       object me=this_player(),ob,*ulist,*ilist;
       int i,j;

        ilist=all_inventory(me);
        j=sizeof(ilist);
        while(j--)
        if(ilist[j]->query("zhuanshi/jineng"))
        {
         write("�������Ѿ�������������ˣ���Ҫ̰�����ᣡ\n");
         return 1;
        } 

       if(!arg || arg!="bi")
       {
        write("��Ҫ����������ʲô��\n");
        return 1;
       }
       if(me->query("neili") < me->query("max_neili"))
       {
        write("��������������ӯ���޷�ʩչ�ڹ��𿪶��ڣ�\n");
        return 1;
       }
       me->set("neili",0);
       me->start_busy(10);
       ulist=users();
       i=sizeof(ulist);
       while (i--)
       {
        if ( !environment(ulist[i]) ) continue; 
        ilist=all_inventory(ulist[i]);
        for(j=0;j<sizeof(ilist);j++)
        if(ilist[j]->query("biwu") && ilist[j]->query("id_id")=="tai-e jian")
        {
         ob=ilist[j];
         write("�������ˣ�"+ob->query("name")+"�Ѿ�����ȡ���ˣ�\n");
         return 1;
        }
       }

       ob=new(__DIR__"obj/tai-e");
       ob->move(environment(me)); 
       message_vision(
       HIW"$N�����������͵س����ڻ�ȥ��ֻ�����һ�����죬һ���׹�\n"
       +"��ڶ��������һ���䵽�������ǰ��\n"NOR,me);
       message("channel:rumor",HIM"��ԡѪ���š�����"NOR+ob->query("name")
       +HIM"���µ���������\n"NOR,users()); 
       return 1;
}

