inherit ROOM;

void create()
{
	set("short", "˽��");
	set("long", @LONG
������һ�ҵ�˽�ӣ�����������һ����Ⱦ��һλׯ���������������
��̫ʦ���Ͻ�ѧ��������������������ѧ��ѧ����һ�Ź��ⰻȻ���鰸��
����������ǰ�棬���ϰ��ż��������˵���װ�鼮��
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"south" : __DIR__"eroad2",
  		"north" : __DIR__"mianbi",
	]));
        set("objects", ([
        ]));
	set("coor/x", -150);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
