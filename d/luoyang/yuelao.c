inherit ROOM;

void create()
{
	set("short", "һ��ǣ");
	set("long", @LONG
���������ط���һ��ǣ��������ר�����˵޽��Լ�ͽ����Լ�ĵط���
�����������еķ򸾶���������ϲ����Ե�ģ�������������Ҳ�����Ľ��
�����������ˡ�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"north" : __DIR__"eroad2",
	]));
        set("objects", ([
                __DIR__"npc/hongniang" : 1,
        ]));
	set("coor/x", -150);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
