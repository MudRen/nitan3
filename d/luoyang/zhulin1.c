inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ǽ��⣬�ô��һƬ����ԣ�ӭ��ҡҷ��������Ȼ����
������������������϶�����ȴ���������ڸ��٣���������һƬ������
�������������������Ȼ���������硣
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"xiaoxiang4",
  		"north" : __DIR__"zhulin2",
	]));

	set("coor/x", -140);
	set("coor/y", -20);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
