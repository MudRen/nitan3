//  jitan.c ��̳

inherit ROOM;

void create()
{
        set("short","��̳");
        set("long", @LONG
�����Ǵ����¼�̳���м�һ����̨����ʯ���͡���Χ������ľ��
�����ͣ��Ա�һ��ʢˮ��­������һֻ���塣һЩʹ��Ϳ���������
���������������ȡ�
LONG );
        set("outdoors","xueshan");
        set("no_fight","1");
        set("exits",([
                "north" : "/d/xueshan/chang",
        ]));
        set("objects",([
                "/d/xueshan/npc/x_lama": 2,
//                "/d/xueshan/npc/fsgelun": 2,
//                "/d/xueshan/obj/jitan2": 1,
//                "/d/xueshan/obj/faling": 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

/*
int valid_leave(object me, string dir)
{
        object ob;
        ob=(present("fa tan", (environment(me))));
        if (! objectp(ob)) return ::valid_leave(me, dir);
        if ( me->query("name") == ob->query("pending")
        && ob->query("burning"))
                return notify_fail("�㷨��û��������ߣ�\n");
        return ::valid_leave(me, dir);
}
*/
