// Room: /d/suzhou/kedian3.c
// Date: May,31 1998 Java

inherit ROOM;

void create()
{
	set("short", "�͵��¥");
        set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ�������ٿ�����
���¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ���������ŵ����˹�
ȥ��
LONG );
	set("sleep_room", 1);
	set("no_fight", 1);
        set("hotel",1);
	set("no_clean_up", 0);
	set("exits", ([
		"out" : "/d/suzhou/kedian2",
	]));
	set("coor/x", 210);
	set("coor/y", -190);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");
	return ::valid_leave(me, dir);
}

