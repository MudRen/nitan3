// /d/playertown/road1.c ��ʯС��
// Build 1999.12.10 bmw

inherit BUILD_ROOM;

void create()
{
	set("short","��ש·");
	set("long",
"����һ���ǳ�ƽ������ש�̳ɵ�С·����Χ��һСƬ�յأ���ɫ����\n"
"�����ʺϽ�����\n"
);

	set("recordable_room",1);
	set("outdoors","playertown");	
	set("exits",([
		"north" : __DIR__"road12",
		"east" : __DIR__"road9",
		"south" : __DIR__"road1",
	]));
	setup();
	// replace_program(ROOM);
}
