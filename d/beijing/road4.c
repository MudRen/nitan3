inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ�����
�󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡���������������
�����Ͼ��ǡ��ϱ�ͨ�����ݳǡ�
LONG );
	set("exits", ([
		"north" : "/d/beijing/road3",
		"west" : "/d/beijing/road7",
		"south" : "/d/beijing/road8",
	]));
	set("objects",([
		"/d/taishan/npc/jian-ke" : 1,
	]));
 	set("outdoors", "beijing");
	set("coor/x", 60);
	set("coor/y", 250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
