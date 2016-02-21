// sheshenya.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ�μ�խ���յ�ɽ�£�����������ƣ�����Ԩ���޵ס��粻С�ģ�
һʧ�����ȥ��ֻ������ͷ���Ҳ����������и�Сɽ��(dong)���ܶ཭��
�����벻����ʱ��ѡ����������(jump)����ɱ��
LONG );
        set("exits", ([ /* sizeof() == 1 */
                "eastdown" : __DIR__"canglong",
        ]));
        set("item_desc", ([
                "dong" : "����������ʯ�ڵ�С�����ں����Ĳ�֪�ж��\n",
        ]));
        set("outdoors", "huashan" );

        setup();
}

void init()
{
        object me = this_player();
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
	add_action("do_jump", "jump");        
        if (me->query_temp("xunshan")) 
                me->set_temp("xunshan/sheshen", 1);
        return;
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="dong" )
        {
                if( (fam = me->query("family")) && fam["family_name"] == "ؤ��")
                {
                        message("vision",
                                me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��",
                                environment(me), ({me}) );
                        me->move("/d/gaibang/undertre");
                        message("vision",
                                me->name() + "�Ӷ������˽�����\n",
                                environment(me), ({me}) );
                                return 1;
                } else  
                        return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
        }
}

int do_jump(string arg)
{
	object ob;
	int new_gin;
	ob = this_player();
        new_gin = random( ob->query("max_qi")*3 );
        if ( new_gin > ob->query("qi") ) new_gin = ob->query("qi") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
		return notify_fail("����Ҫ������ɱ����ô�벻������\n");
	tell_object(ob, HIR"�㲻��˼��������һԾ�����������¡�������\n"NOR);
	message("vision", NOR"ֻ��" + ob->query("name") + "�����ң���������������֮�С�������\n"NOR, 
	        environment(ob), ob);
        if((random((int)ob->query("kar")) < 5 ) && ((int)ob->query_skill("dodge") < 200))
	{
                ob->set_temp("die_reason", "������ɱ����");
		ob->die();
		return 1;
	}
        ob->receive_damage("qi", new_gin);
        ob->move("/d/yihua/yanfeng");
	return 1;
}
