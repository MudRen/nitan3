// liangong3.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
        set("long", @LONG
�������һЩͭ�ˣ����Ǳ�ľ�˸��ӽ�ʵ��Ҳ�Ͳ����׻������Ҳ�Ǹ�����
���ϳ˾��յĵط�������һֱ�ߴ�������������������Ժ��
LONG );
	set("exits", ([
		"south" : "/d/dali/liangong2",
	]));
	set("objects", ([
                "/clone/npc/tong-ren": 3,
	]));
        setup();
	replace_program(ROOM);
}
