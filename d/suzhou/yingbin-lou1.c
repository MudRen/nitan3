// Room: /suzhou/jiulou1.c
// YZC 1995/12/04 llm 99/07

inherit ROOM;

void create()
{
	set("short", "ӭ��¥");
        set("long", @LONG
��Բ�������ڣ�ӭ��¥��������ν�ǲ�С��������ŵ���ʿ�ſ�ҲΪ������
��ʫ�����²����������Ķ�����¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ�����
�ӣ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����ר�žٰ챸������ϲ���á�
LONG );

	set("exits", ([
		"east" : "/d/suzhou/baodaiqiao",
		"up" : "/d/suzhou/xifu-tang",
	]));

	set("objects", ([
      "/d/suzhou/npc/xiaoer" : 1,
	]));

	set("coor/x", 190);
	set("coor/y", -220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
