// /d/playertown/road2.c ��ʯС��
// Build 1999.12.10 bmw

inherit BUILD_ROOM;

void create()
{
	set("short","��ʯС��");
	set("long",
"����һ������ʯ�ӵ�С·�����߳��ż��Ÿߴ������������Χ��һС\n"
"Ƭ�յأ���ɫ�����ǳ��ʺϽ�����\n"
);

	set("recordable_room",1);
	set("outdoors","playertown");
	set("exits",([
		"west" : __DIR__"miao",
//          "north" : "/u/adx/workroom1",
		"east" : __DIR__"road19",
	]));
	
	setup();
	
	// replace_program(ROOM);
	
}
