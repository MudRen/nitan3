#include <ansi.h>
inherit ROOM;

int do_knock(string arg);
int do_open(string arg);

void create()
{
        set("short", "��ׯ");
        set("long", @LONG
ׯ԰�Ĵ������ǡ���ׯ���������֡����ɫ�Ĵ���(gate)������
���ţ����澲���ĵ�һ��������û�С�
LONG);
        set("exits", ([
                "east" : __DIR__"dadao1",
        ]));
        set("objects", ([
                "/clone/quarry/gou2" : 2,
        ]));
        set("item_desc", ([
                "gate" : "���Ĵ��Ž����ţ�����(knock)���ɡ�\n"
        ]));        
        set("no_clean_up", 0);
        setup();
        // replace_program(ROOM);
}

void init()
{
        add_action("do_knock", "knock");
        add_action("do_open","open");
}
int do_open(string arg)
{
        if(arg=="gate")
        return notify_fail("�������������ţ����һ�㶯����û�У������Ǵ����淴���ˡ�\n");
        else return 0;
}

int do_knock(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg=="") 
                return notify_fail("��Ҫ��ʲô��\n");
          if (arg != "gate")
                return notify_fail("��Ҫ��ʲô��\n");
          if( arg=="gate" ) {
                message_vision("$N�����������š�\n", me);
                if (me->query("bunch/bunch_name")!="С����" && (int)me->query("shen") <= 0)
                {
                        message_vision(HIB"����֨ѽһ�����ˣ�������̽����ͷ��������$N����˵����������Ͷ������С����İɣ�����
˵��һ�Ѱ�$N���˽�ȥ��\n"NOR, me);
                        me->move("/d/hangzhou/xdh_hzfb");
                        return 1;
                }
                if( good_bunch(me) || (int)me->query("shen") > 0 ) 
                { 
                        message_vision("����֨ѽһ�����ˣ�������̽����ͷ��������$N����˵��������������Ҳ�����ˣ���Ĳ��ͷ���ô����\n�ű����صĹ����ˡ�\n",me);  
                        return 1; 
                } 
                message_vision("����֨ѽһ�����ˣ�������̽����ͷ��������$N����˵��������Ȼ�Ǳ�����ֵܣ��ͽ����ɣ�����
˵��һ�Ѱ�$N���˽�ȥ��\n",me);
                me->move("/d/hangzhou/xdh_hzfb"); 
                return 1; 
        }
        
        return 1;
}
