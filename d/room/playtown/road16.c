// /d/playertown/road3.c ��ʯС��
// Build 1999.12.10 bmw

inherit BUILD_ROOM;

void create()
{
	set("short","��ʯС��");
	set("long",
"����һ������ʯ�ӵ�С·�����߳��ż��Ÿߴ������������С·�ı�\n"
"������������С����ߺ��������ż��о�������ɣ���������ͨ�������\n"
"·�������С·�������ׯ�����ġ�\n"
);

	set("recordable_room",1);
	set("outdoors","playertown");
	set("exits",([
		"east"	: __DIR__"road3",
//         "enter"  : "/data/room/chuchu/xiaoyuan",
	]));
	
	setup();
	
	// replace_program(ROOM);
	
}
