// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <room.h>

// inherit HARBOR;
inherit ROOM;

void create()
{
	set("short", "��̲");
	set("long", @LONG
����������𽭺����һ����ˡ��������ȥ�����˺��콻�ʴ����㺣
Ÿ��Ӱ���������֣����ܼ�����һ����Ӱ�����ɵ�����һ�󷢻š�������
һƬ������ϼ�����֣������ƽ�����ɫ�ͷף��������ĵģ��ƺ�͸�ŹŹ֡�
����ǰ����һ��ʯ��(shibei)�������ƺ���Щ�ּ����Ա���һ���ʯ(sto
ne)�����߲���һ�Ҵ�(chuan)��
LONG );

	set("exits", ([
		"north" : __DIR__"thzhen1",
	]));

	set("item_desc",([
	        "shibei" : "
����......����......ռ�����......
......����......����......������ʱ......\n",

	        "stone" : "��ʯ�Ϸ���һ�鰼�ۣ�����һ��Ť���İ�����״��\n",
                "chuan" : "�����һ���������ϵ�Ĵ󴬡����ϵĿ��˻����ֻҪ\n"
                          "�ϴ�(enter)�Ϳ��Ի���ԭ��\n",
	]));

	set("outdoors", "taohua");

        set("island", "�һ���");
        set("shape", "��һ�ɼ����˱ǻ���ĺ��紵����");
        set("navigate/locx", 30);
        set("navigate/locy", -180);

	setup();

}

void init()
{

        add_action("do_put", "put");
        add_action("do_pozhen", "pozhen");
        add_action("do_enter", "enter");
        add_action("do_pozhen","����");
}

int do_put(string arg)
{
        object me;
        string item, target;

        me = this_player();

        if (! arg || sscanf(arg, "%s in %s", item, target) != 2)
                return notify_fail("ʲ�᣿\n");

        if (! present("tie bagua", me))
                return notify_fail("ʲ�᣿\n");

        if (item != "tie bagua")
                return notify_fail("ʲ�᣿\n");

        if (target != "stone")
                return notify_fail("ʲ�᣿\n");

        message_vision("$N�������Է����ʯ������\n", me);
        message_vision(HIW "ֻ�������������죬�������������߷ֿ���һ��С·������$N��ǰ\n"
                       "$N��æ���������ԣ��������֡�������$N����ָֻ���ԭ״��\n\n" NOR, me);

        me->move("/d/taohua/xiaojing");

        return 1;

}

int do_pozhen()
{
        object me;

        me = this_player();

        if (me->query_skill("qimen-wuxing", 1) < 120) 
        {
                me->receive_damage("jing", 50);
                me->receive_damage("qi", 50);
                message_vision("$Nڤ˼������β�����⣬������ƣ����ͬ����ħһ������Ȼһ������������\n", me);
                me->move("/d/taohua/thzhen1");
    
        } else 
        {

                message_vision(HIW "$N��˼Ƭ�̣����ֵ��������˱仯��ȫ����Ȼ���أ�\n"
                               "����һ����Ц������һ�����������֣���һ�䣬��һת����Ӱ�ٲ���\n" NOR, me);

        me->move("/d/taohua/xiaojing");
        }
        return 1;

}
int do_enter ( string arg )
{
        object ob ;
        string dir;
        if( !arg || arg !="chuan" ) 
        {
                tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
                return 1 ;
        }
        ob = this_player () ;
        message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
        message_vision("�������𷫣��������������С�\n", ob);
        ob ->move("/d/taohua/dahai") ;
        tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
        call_out("rtaohua", 10 , ob );
        return 1 ;
}
void rtaohua( object ob )
{
        if (base_name(environment(ob)) != "/d/taohua/dahai")
                return;

        tell_object(ob , "�����ڵִ�����ԭ��һ���������С������´�����\n" ) ;
        ob->move ("/d/quanzhou/jiaxinggang") ;
}

