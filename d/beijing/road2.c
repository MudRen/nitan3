inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ�����
�󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·���������ϵ��˸������ž�װ���¼��������еĻ�������
���ŵ�������������Щϰ��Ľ����ˡ���·��������������������֡�
LONG );
	set("exits", ([
		"northwest" : "/d/beijing/road1",
		"southeast" : "/d/beijing/road3",
	]));
	set("objects",([
		"/d/taishan/npc/tangzi" : 2,
	]));
	set("outdoors", "beijing");
	set("coor/x", 50);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


