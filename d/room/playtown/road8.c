// /d/playertown/road1.c ��ʯС��
// Build 1999.12.10 bmw

inherit BUILD_ROOM;

void create()
{
	set("short","�����");
	set("long",
"������һ��������С���ϣ�����һ������ڣ�������һ����ʯС����\n"
"����Ͷ�������������ש�̳ɵ�·��\n"
);

	set("outdoors","playertown");
	set("no_clean_up",0);
	
	set("exits",([
		"northwest" : __DIR__"road9",
		"northeast" : __DIR__"road10",
		"south"	: __DIR__"road7",
		"west"	: __DIR__"road17",
	]));
	
	setup();
	
	// replace_program(ROOM);
	
}
