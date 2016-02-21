// Room: /d/suzhou/hutong3.c
// Date: May 31, 98  Java
// Updated by rama
inherit ROOM;
#include <ansi.h>

int do_open(string arg);
int do_knock(string arg);

void create() {
        set("short", "��ͬ");
        set("long", @LONG
����һ���ڰ��������С������з·�Ʈ����һ��������Ϣ��������å
���ε������Ͼ��ܻص���֣��㻹�ǸϿ��߰ɡ��Ա��и�ľ�ţ�door���� 
LONG );
        set("outdoors", "suzhou");
        set("no_clean_up", 0);
        set("exits", ([
                "west"      : __DIR__"hutong2",
                "southeast" : __DIR__"dongdajie2",
        ]));
        set("item_desc", ([
                "door" : "����ľ�Ž����ţ���Щ�����ˡ�\n" ,
        ]));

        set("objects", ([ 
                "/d/city/npc/liumang" : 2, 
        ]));
        set("coor/x", 230);
	set("coor/y", -190);
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
        return notify_fail("������������ľ�ţ����һ�㶯����û�У������Ǳ������ˣ�\n");
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
                if (me->query("bunch/bunch_name")=="������")
                {
                        message_vision(HIB"ľ��֨ѽһ�����ˣ�������̽����ͷ��������$N����˵������ԭ�����Լ��ֵܣ�����
˵��һ�Ѱ�$N���˽�ȥ��\n"NOR, me);
                        me->move("/d/suzhou/xlm_zb");
                        return 1;
                }

                if (me->query("bunch/bunch_name")!="������" && (int)me->query("shen") <= 0)
                {
                        message_vision(HIB"ľ��֨ѽһ�����ˣ�������̽����ͷ��������$N����˵����������Ͷ�����������ŵİɣ�����
˵��һ�Ѱ�$N���˽�ȥ��\n"NOR, me);
                        me->move("/d/suzhou/xlm_zb");
                        return 1;
                }
                if( good_bunch(me) || (int)me->query("shen") > 0 ) 
                { 
                          message_vision("ľ��֨ѽһ�����ˣ�������̽����ͷ��������$N����˵��������������Ҳ�����ˣ���Ĳ��ͷ���ô����\n�ű����صĹ����ˡ�\n",me); 
                        return 1; 
                } 
                message_vision("ľ��֨ѽһ�����ˣ�������̽����ͷ��������$N����˵��������Ȼ�Ǳ��ŵ��ֵܣ��ͽ����ɣ�����
˵��һ�Ѱ�$N���˽�ȥ��\n",me); 
                me->move("/d/suzhou/xlm_zb");
                return 1; 
        }
        
        return 1;
}
  
