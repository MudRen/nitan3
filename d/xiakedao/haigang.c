// Room: /d/xiakedao/xkroad5.c
// Modified by Java on Feb.14.1998

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�����Ǹ�СС��ۡ����溣��Ư���ż���С����̧������������
�����ޱ��޼ʡ���Ÿ�ӹ��˼⣬������Ȼ���м������������Ĵ���
���ߣ�����ͣ����һЩС��(boat)��
LONG );
        set("outdoors", "nanhai");

        set("resource/quarry", ([
                "/clone/quarry/gui" :  40,
                "/clone/quarry/eyu" :  3,
                "/clone/quarry/haibei" :  5,
        ]));
	set("exits", ([
		"east" : __DIR__"xkroad4",
	]));

	set("objects", ([
		__DIR__"npc/renter" : 1,
	]));

        set("item_desc", ([
                "boat" : "���Ҵ��ɵ����͵���\n",
        ]));


	setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object ob, lingpai;
        //string dir;

        if (arg != "boat")
                return notify_fail("��Ҫȥ�Ķ���\n" );

        ob = this_player();

        if (! lingpai = present("shangfa ling", ob))
                return notify_fail(HIC "����˵��������û�����Ʒ�������ܵ����͵�ȥ��\n" NOR);

        message_vision(HIG "������˵�ͷ��������Ȼ���������Ʒ�����Ҿ����㵽���͵�ȥ����\n" NOR, ob);
        
        destruct(lingpai);

        message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
        message_vision("�������𷫣��������Ϸ����С�\n", ob);
        
        ob->move("/d/xiakedao/duchuan");
        tell_object(ob, BLU "���ں��Ϻ�����һ����.......\n" NOR ) ;
        call_out("home", 7, ob);
        return 1;
}

void home(object ob)
{
        if (! objectp(ob))
                return;

        tell_object(ob, "�����ڵִ����Ϻ����ߡ������´�����\n");
        ob->move (__DIR__"haitan");
        message("vision", ob->name() + "����С�ۣ����˹�����\n",
                environment(ob), ob);
}
