// Room: /d/playtown/biwuchang.c ���䳡
// Build 199.12.10 bmw

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long",
"������Ҵ���Ĵ�������͹��еĵط���ʱ����������������໥��\n"
"�裬�������Ϊ������һ�����ص�ԭ��ɣ��������Ǻܴ�û��ʲô�磬һ\n"
"���СС�Ķ��������ﶼ�������������Զ�ĵط�����һ��Сʯ����bei��\n"
",�ƺ�����ܾá�\n"
);
	set("outdoors", "playertown");
	set("exits", ([
		"south"  : __DIR__"miao",
	]));
	setup();
	replace_program(ROOM);
}
