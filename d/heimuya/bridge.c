//bridge.c

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����һ��С���ţ���ľ�¶��ϵı�ѩ�ڻ��γ�һ���峺��СϪ�������»���
��������ʱ����Ƥ��С��Ծ��ˮ�棬�������»���һ������ɫ�Ļ��ߡ�
LONG );
        set("outdoors", "baituo");
        set("exits", ([
            "northwest" : "/d/baituo/guangchang",
            "east" : "/d/baituo/xijie",
        ]));
        set("objects",([
                "/d/heimuya/npc/cungu" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
