// liangong2.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
        set("long", @LONG
�������һЩͭ�ˣ����Ǳ�ľ�˸��ӽ�ʵ��Ҳ�Ͳ����׻������Ҳ�Ǹ�����
���ϳ˾��յĵط��������ߴ�������������������Ժ��
LONG );
	set("exits", ([
		"south" : "/d/dali/liangong",
		"north" : "/d/dali/liangong3",
	]));
	set("objects", ([
                "/clone/npc/tong-ren": 4,
	]));
        setup();
	replace_program(ROOM);
}
