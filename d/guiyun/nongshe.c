// Room: nongshe.c
// By Dumbness, 2003-4-28 21:34

inherit ROOM;

void create()
{
        set("short", "����ũ��");
        set("long", @LONG
�������һ����ͨ���˼ҡ�һλ����б���������Ľ������ʱ����ʹ
�������������ͨ��С�ݣ�ƽ����������ˣ�������������һ��������С����
�ܵ�ʱ��ȴͻȻ�о��е�Ŀ��͸������������������й�Ī���Ŀ־塣
LONG );
	set("outdoors", "guiyun"); 
	set("exits", ([
		"southwest" : __DIR__"zhulin",
	]));
	set("objects", ([ 
		__DIR__"npc/laoren" : 1, 
	])); 
	set("coor/x", -190);
	set("coor/y", -130);
	set("coor/z", 0);
	setup(); 
	replace_program(ROOM); 
}