//Room: xubufang.c

inherit ROOM;

void create ()
{
	set ("short", "Ѳ����");
        set("long", @LONG
�����ǳ�������ά���ΰ���Ѳ�������ĵط������ſڷ���������ͭʨ������
��һ��������ǽ�����Ű�ɫ���ᣬ��úܺ񣬷·�Ը�˿�����ǽ��ʯ�ڣ�������
����ͭ���������м�����ü��Ŀ�����������Ѳ������һ���ƺ���������ʲô��
�ϱ���һ��С�ţ��ƺ���������
LONG );
	set("exits", ([
        	"west" : "/d/changan/fengxu5",
        ]));
        set("objects", ([
        	"/d/changan/npc/butou"  : 1,
        	"/d/changan/npc/guanbing" : 2,
        ]));

        set("coor/x", -370);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object me, key, nroom;
	me = this_player();
	if (! arg || arg != "door")
		return notify_fail("��Ҫ��ʲô��\n");

	if (! (key = present("laofang key", me)))
		return notify_fail("��û�п�����ŵ�Կ�ס�\n");

	if (! (nroom = find_object("/d/changan/laofang")))
	      	nroom = load_object("/d/changan/laofang");

	set("exits/south", "/d/changan/laofang");
	nroom->set("exits/north", __FILE__);
	message("vision", "ֻ�����꣡һ����Կ�׶��ˡ���"
                "�������Ѿ����ˡ�\n", this_object() );
	me->set_temp("used_laofang_key", 1);
	destruct(key);
        call_out("close_door",60);
	return 1;
}

void close_door()
{
        delete("exits/south");
        }
