inherit ROOM;
void create()
{
        set("short", "�����Ż���");
        set("long",
"�������ߡ���ʮ�����ȣ��໥���������಻����ֱ�������޾���ÿ��\n"
"����ת�䴦����һյ�������ҡ�β����ĻƵơ��ȱߵ�̶ˮ�ڵƹ�����\n"
"�·���ī�̵���⡣\n"
);
        set("no_magic", "1");

        setup();
}

int valid_leave(object me, string dir)
{
        object killer;

        if (random(me->query("kar")) < 20 && 
            ! objectp(present("figure", environment(me)))) 
        {
                killer = new("/quest/npc/killer");
                NPC_D->set_from_me(killer, me, 100);
                message_vision(killer->name() + "�����ȵ���˭�˸��ô�����ɽׯ�����������ɣ�\n", me);
                killer->move(environment(me));
                killer->set_leader(me);
                return notify_fail("ֻ��ͻȻ�ӵذ��´ܳ�һ�ˣ���ס�����ȥ·��\n");
        }
        return ::valid_leave(me, dir);
}


