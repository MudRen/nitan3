inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ڵĶ��������������һ�����ӣ��Լ�һ����
�ܣ�����Ϸ��źܶ��鼮��ǽ�Ϲ��ż����ֻ��������������
�ŵ��������ĵط���
LONG);
	set("exits", ([
		"west" : __DIR__"dayuan",		
	]));

	set("coor/x", -460);
	set("coor/y", -180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

