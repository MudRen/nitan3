inherit ROOM;

void create()
{
	set("short", "С��");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ�����
�󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡����߾��Ǵ�֮��
�ˡ�
LONG );
	set("exits", ([
		"east"  : "/d/beijing/haigang",
		"south" : "/d/shaolin/ruzhou",
		"north" : "/d/beijing/road9",
	]));
	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));
 	set("outdoors", "beijing");
	set("coor/x", 0);
	set("coor/y", 140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}



