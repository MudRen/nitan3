inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ڵ����������������һ�����ӣ��Լ�һ����
�ܣ�����Ϸ��źܶ��鼮�������ŵ��Ӷ���ĵط���
LONG);
	set("exits", ([
		"east" : __DIR__"dayuan",
		
	]));

	set("coor/x", -480);
	set("coor/y", -180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

