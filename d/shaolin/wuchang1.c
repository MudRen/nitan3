inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡��
�������Ų���ľ�ˡ�ʮ����ɮ��������ϰ���ա�������һ����
ɮ����
LONG );
	set("exits", ([
		"south" : __DIR__"zoulang2",
		"west" : __DIR__"banruo5",
		"east" : __DIR__"wuchang",
		"north" : __DIR__"zoulang6",
	]));
	set("outdoors", "shaolin");
	set("objects",([
                "/clone/npc/mu-ren" : 4
        ]));
	setup();
	replace_program(ROOM);
}

