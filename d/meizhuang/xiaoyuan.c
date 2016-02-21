inherit ROOM;

void create()
{
        set("short", "����СԺ");
        set("long", @LONG
�����¶��ţ�����һ���������ǳ���ͨ��СС��Ժ�䣬��������
�橣���������ʯ��������̦���Ե�ƽ���������С�����ͨ������ʯ
��֮ǰ����ǰ�ݺ��߰������ز�ø�ͦ���ڵ��������������ġ�Ժ��
��û��ʲô���裬ֻ�м��Ѹ�ľ��(wood)���ڽ����������һ����
������עĿ�� 
LONG );
        set("exits", ([
                "south" : __DIR__"yuedong",
                "enter" : __DIR__"xiaowu",
        ]));

        set("item_desc",([
                "wood" : "һ��Ѹɲ�������һ������ɫ�Ƚ��ر�\n",
        ]));
        set("objects", ([
                __DIR__"npc/shi" : 1,
        ]));

        set("outdoors", "meizhuang");

        setup();
}

void init()
{
        add_action("do_pull", "pull");
        add_action("do_unlock", "unlock");
        if (present("ding jian", environment(this_player())))
                delete("exits/east");
}
int do_unlock(string arg)
{
        object ob;
        if (query("exits/east"))
                return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
        if (!arg || (arg != "men" && arg != "east"))
                return notify_fail("��Ҫ��ʲô��\n");
        if (!(ob = present("tong yaoshi", this_player())))
                return notify_fail("�㲻��������\n");
        set("exits/east", "/d/meizhuang/mishi2");
        message_vision("$N�Ѻ���Կ�׷Ž��ŵİ��ݴ�, ���ߵ�һ���������Ĵ��ˡ�\n", this_player());
        destruct(ob);
        return 1;
}
int do_pull(string arg)
{
        object me , ob;
        me = this_player();
        if (arg == "wood" && !present("sea-wood", me) && query("weapon_count") >= 1)
        {
                add("weapon_count", -1);
                ob=new("/d/meizhuang/obj/sea-wood");
                ob->move("/d/meizhuang/xiaoyuan");
                message_vision("$N��ľ����ﲦŪ��, һ�����ε�ľ�����˳���.\n", me);
                return 1;
        }
        else {
                message_vision("$N���˰���,Ҳû�з���ʲô�ر�Ķ���.\n", me);
                return 1;
             }
}
int valid_leave(object me, string dir)
{
        object shi;

        if (dir != "enter" ||
            ! objectp(shi = present("shi lingwei", this_object())))
                return ::valid_leave(me, dir);

        return shi->permit_pass(me, dir);
}
