//TOHSQ3.C

inherit ROOM;

void create()
{
	set("short", "ɽ·");
        set("long", @LONG
�����ӽ��ȵ��ˣ��������ٲ���ס��ȥ·���ٲ���һƥ�����������£���
к��һ��̶֮�У�ˮ������������ֱ������������ɽʯ���ʣ����ڶ��£�������
�����Ͷ��ɡ���̶ǰ����ʯ��ĥ�����������������������������
LONG );
	set("exits", ([
		"southeast" :__DIR__"tohsq2",
                "west"  : __DIR__"bshantan",
	]));

	set("outdoors", "mingjiao");
	setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me;

        me = this_player();
        if (! arg)
        {
		message_vision("$Nһ���ۣ���̶��������ȥ��ֻ�������"
			       "�ǣ��Ͻ������࿹��\n",me);
                me->move(__DIR__"hsqtan1");
                return 1;
        }

	return notify_fail("��Ҫ�����Ķ���\n");
}

