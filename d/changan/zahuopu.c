//Room: zahuopu.c

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
        set("long", @LONG
һ�����ֺŵ��ӻ��̡�����������Ӫ�������ڳ�������һ���Ѿ�����һЩС
�������������������ν��ף����Ǵ��װ��棬�ϰ����ճ�������Ҫ�Ķ���һ����
���١��ټ�����������ƹ����������ӻ��̵����⿴��һ���һ��á�
LONG );
	set("exits", ([
		"south" : "/d/changan/huarui5",
	]));
	set("objects", ([
        	"/d/changan/npc/liu": 1,
	]));

	set("no_clean_up", 0);
	set("coor/x", -380);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

