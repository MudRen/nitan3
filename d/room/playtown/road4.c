// /d/playertown/road4.c ��ʯС��
// Build 1999.12.10 bmw

inherit BUILD_ROOM;

void create()
{
	set("short","��ʯС��");
	set("long",
"�����С������Ĵ�֣�������һƬ���֣��紵����ʱ��ɳɳ������ɷ�Ƕ���������\n"
"���˿���������Լ���Կ�һ�����ɫ�����������ֽ����������Ĳ�Զ����һ��Сͤ��\n"
);

	set("outdoors","playertown");
              set("recordable_room",1); 
	set("exits",([
		"west"	:	__DIR__"road3",
		"east"	:	__DIR__"road6",
	]));
	
	setup();
	
	// replace_program(ROOM);
	
}
