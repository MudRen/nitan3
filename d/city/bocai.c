//Room: bocai.c

inherit ROOM;

void create ()
{
        set ("short", "���ʵ�");
        set("long", @LONG
�������ṩ��Ʊ����Ĳ������ֳ�����ǽ�Ϲ���������������ʷ���롣����
�������У������໥�������´ε��н����롣�������Ϲ���ǳЦ��Ҳ������Ŀͨ
�죬�������ѡ�ϲ�����ʵ�����������������ϰ�ѯ�ʡ�
LONG );
        set("exits",  ([
                "south" : "/d/city/daxiao",
        ]));

        set("objects", ([
                // "/adm/npc/lottery" : 1,
        ]));
        set("no_fight", 1);

	set("coor/x", -20);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_getnum", "getnum");
}

int do_getnum()
{
        object me = this_player();
        int i, n;
        string num = "��ѡ���룺";

        if (me->is_busy())
              return notify_fail("�����ڷ������롣\n");

        for (i = 0; i < 5; i++)
        {
              n = random(10);
              num += sprintf("%d", n);
        }
        num += "\n";
        tell_object(me, num);
        me->start_busy(1);
        return 1;
}
