// Updated by rama

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��ͬ");
        set("long", @LONG
���������������ϰ��յľ�ס����ֻ����ͬ��������ЩС���棬�����С�С
�ӻ��̵ȡ�һЩ���������������������ƺ�����������Щ���ء��Ա��и�Сľ
�ţ�door����
LONG );
        set("outdoors", "xiangyang");
        set("exits", ([
                "south" : "/d/xiangyang/jiekou1",
        ]));
        set("objects", ([
                "/d/xiangyang/npc/girl" : 2,
        ]));

        set("item_desc", ([
                "door" : "����ľ���ţ��������൱�¾ɡ�\n" ,
        ]));

        set("coor/x", -320);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_knock", "knock");
        add_action("do_open","open");
}
int do_open(string arg)
{
        if(arg=="door")
        return notify_fail("�������������ţ����һ�㶯����û�У������Ǵ����淴���ˡ�\n");
        else return 0;
}

int do_knock(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg=="") 
                return notify_fail("��Ҫ��ʲô��\n");
          if (arg != "door")
                return notify_fail("��Ҫ��ʲô��\n");
          if( arg=="door" ) {
                message_vision("$N����������ľ�š�\n", me);
                if (me->query("bunch/bunch_name")!="�ڰ׵�" && (int)me->query("shen") <= 0)
                {
                        message_vision(HIB"ľ��֨ѽһ�����ˣ�������̽����ͷ��������$N����˵����������Ͷ�����Ǻڰ׵��İɣ�����
˵��һ�Ѱ�$N���˽�ȥ��\n"NOR, me);
                        me->move("/d/xiangyang/hbd_xyfb");
                        return 1;
                }
                if( good_bunch(me) || (int)me->query("shen") > 0 && me->query("bunch/bunch_name")!="�ڰ׵�" ) 
                { 
                        message_vision("ľ��֨ѽһ�����ˣ�������̽����ͷ��������$N����˵��������������Ҳ�����ˣ���Ĳ��ͷ���ô����\n�ű����صĹ����ˡ�\n",me);  
                        return 1; 
                } 
                message_vision("�Ű�֨ѽһ�����ˣ�������̽����ͷ��������$N����˵��������Ȼ�Ǳ�����ֵܣ��ͽ����ɣ�����
˵��һ�Ѱ�$N���˽�ȥ��\n",me);
                me->move("/d/xiangyang/hbd_xyfb"); 
                return 1; 
        }
        
        return 1;
}
  
