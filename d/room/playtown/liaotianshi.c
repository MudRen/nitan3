// Room: /d/playertown/liaotianshi.c ������
// Build 1999.12.10 bmw

inherit ROOM;
void create()
{
        set("short", "������");
        set("long",
"����һ������ͨ�ķ��䣬����ֻ�����صذ���һЩ������Ϣ���Σ�һ\n"
"������������к��ſ��ˡ������ﵽ���ۼ���һȺȺ���ˣ��໥����Ž�\n"
"���š��ڷ�����ұ���һ��С���䣬ż����һЩƣ��������ұߵķ�����ȥ��\n"
);
	set("no_fight", 1);

        set("exits", ([
                "north"  : __DIR__"miao",
        ]));
        setup();
        replace_program(ROOM);
}
