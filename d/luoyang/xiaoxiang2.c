inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
����һ����ʯС·��·������ʯ���̳ɣ��ո��¹��꣬·����Ǹɾ���
С���ھ����ĵģ�ֻ�������Լ��ĽŲ�����ż���紵����֦����ɳɳ����
����
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"juyi",
  		"west" : __DIR__"xiaoxiang",
	]));
        set("objects", ([
                "/d/beijing/npc/kid1" : 1,
        ]));

	set("coor/x", -150);
	set("coor/y", 40);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}