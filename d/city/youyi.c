// Room: youyi.c
// smallfish 2002/12/7 

#include <ansi.h>

inherit ROOM;

int is_chat_room() { return 1;} 
void create()
{
        set("short", "��̶��վ������");
    set("long",
"�������������վ������һ���ŵĶ����������롢���������С��\n"
"�䡣�����д�����ħ��ƽʱ�����������ź��������͵������������\n"
"�൱������������׾����ҵ�("HIW"find"NOR")�Լ������䣬�����������鿴\n"
"�������Լ������䡣����Ҳ�ɸ�����д�š�\n"
        );
    set("objects", ([
    ]));

 set("no_fight",1);
        set("exits", ([
                "west" : "/d/city/yizhan",
        ]));

        set("coor/x", -5);
	set("coor/y", 15);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_find","find");
   add_action("do_nothing",({
      "practice","lian","meditate","respirate","study","du",
               "tuna","exercise","dazuo","learn","xue","perform","xun"}));
}

int do_find()
{
        object me,ob;
        string id;
        
        me = this_player();
        id = me->query("id");
        
        if(present("mailbox",me))
        {
                write("���Ѿ��������䣬��������ã��� look mailbox\n");
                return 1;
        }
        if(file_size("/data/mail/"+id[0..0]+"/"+id+".o")<0)
                write("���������Ŀǰû���κ��ż���\n");
        ob = new("/clone/misc/mailbox");
        ob->move(me);
        
        write("��Ͻ����Լ������䣬���ڿ���ʹ������ָ������������ʼ���\n\n"
                "mail <ĳ��>               ���Ÿ����ˡ�\n"
                "forward <�ż����> <ĳ��> ��ĳ����ת�ĸ����ˡ�\n"
                "from                      �鿴�����е��ż���\n"
                "read <�ż����>           �Ķ�һ���ż���\n"
                "discard <�ż����>        ����һ���ż���\n");
        return 1;
}

int do_nothing()
{
   write("���ﲻ�������ĵط���\n");
   return 1;
}
int valid_leave(object me, string dir)
{
        object obn;

        if( dir== "west"&&obn = present("mailbox",me))
        {
                destruct(obn);
                write("����������÷��£����뿪�����\n");
        }
        return ::valid_leave(me,dir);
}