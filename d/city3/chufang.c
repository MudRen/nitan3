// Room: chufang.c

inherit ROOM;
void create()
{
	set("short", "��¥����");
        set("long", @LONG
�����Ǿ�¥����ĳ�����������ˮ��ǰ���в��ٵĻ����ժ�˺���ϴ�����
����һЩ���վ������ֱð���͹���ǰŬ���ķ����Ÿ�ɫ���ȣ���һ�����ִ��
������������ߺ�ȣ�ָ�ֻ��ŵ�ȴ���ɻ
LONG );
	set("exits", ([
                "west" : "/d/city3/jiudian",
	]));
        set("objects", ([
                "/d/city3/npc/chuniang" : 1,
        ]) );
	set("no_fight", 1);
	set("no_sleep_room", 1);
	set("coor/x", -390);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
