inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǻ��������֣����·�˴Ҵ��򶫶��У��ϱ�����һ
����ǣ�������һ��װ�κܵ��ŵĵ��̣��������Ŵ������˷�
�塣
LONG);
        set("outdoors", "henshan");

	set("exits", ([
	        "east"   : __DIR__"hengyang1",
	        "west"   : __DIR__"hsroad4",
	        "south"  : __DIR__"majiu",
	        "north"  : __DIR__"lingyinge",
	]));

	set("coor/x", -20);
	set("coor/y", -110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

