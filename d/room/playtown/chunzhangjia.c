// Room: /d/playtown/chunzhangjia.c �峤��
// Build 199.12.10 bmw

inherit ROOM;

void create()
{
	set("short", "�峤��");
	set("long",
"���߽�����������������������˵ľ���������ͬ����������������\n"
"������࣬���Ű���ɫ��ͩľ���ν�һ�Ų輸�����м䣬�������һ����\n"
"��Ĳ�����һ������(duilian)����ʱ���ƾã����ѿ���̫��������\n"
"�Ǻ����Ȼʮ�����ۣ���Ȼд������Դ��������\n"
);

//      set("no_clean_up", 0);
	set("item_desc",([
		"duilian"	:	"�����Ѿ�����̫����ˣ�ֻģģ�������ϵ��弸���֡�\n",
	]));
	
	set("exits", ([
		"east"  : __DIR__"road1",
		"west"  : "/d/room/xiaoyuan",
	]));
	setup();
	replace_program(ROOM);
}
