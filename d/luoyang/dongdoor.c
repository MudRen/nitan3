inherit ROOM;

void create()
{
	set("short", "�ڳǶ���");
	set("long", @LONG
�����ڳǶ��Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭͷ��
��С���������Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ����ء���������
������׽��֮��Ĺٸ�ͨ����һ����ֱ����ʯ���������������죬��
ȥ���������ڳ��ˣ���һ�Ÿ߸߿�������ǻ��Ǻӡ�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"ebridge",
  		"west" : __DIR__"eroad5",
	]));
        set("objects", ([
                "/d/kaifeng/npc/guanbing" : 4,
                "/d/beijing/npc/ducha" : 1,
                "/clone/npc/walker" : 1,
        ]));

	set("coor/x", -110);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
