inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���������������������
�����̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ�
���֡���ʱ���п������߷ɳ۶���������һ·���������ϵ�
�˸������ž�װ���¼��������еĻ���������ŵ�����������
��ЩЩϰ��Ľ����ˡ���·��������������������֡�
LONG);
	set("exits", ([
		"south" : "/d/city/beimen",
		"north" : __DIR__"yidao1",
	]));
	set("outdoors", "nanyang");
	set("coor/x", 0);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

