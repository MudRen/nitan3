// /d/playertown/road1.c ��ʯС��
// Build 1999.12.10 bmw

inherit BUILD_ROOM;

void create()
{
	set("short","��ʯС��");
	set("long",
"����һ������ͨ��ʯС����������Ͷ����涼��ͨ����ׯ��·������\n"
"�ǳ����·��\n"
);

	set("recordable_room",1);
	set("outdoors","playertown");
	set("exits",([
		"north" : __DIR__"road6",
		"east" : __DIR__"xuemeiting",
	]));
	
	setup();
	
	// replace_program(ROOM);
	
}
