inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ�����
�󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG );
	set("exits", ([
		"northwest" : "/d/beijing/road6",
		"east" : "/d/beijing/road4",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke" : 1,
	]));
 	set("outdoors", "beijing");
	set("coor/x", 50);
	set("coor/y", 250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}