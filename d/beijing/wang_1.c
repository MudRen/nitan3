inherit ROOM;

void create()
{
	set("short", "���������");
        set("long", @LONG
������Ǿ�����Ϊ��������������֡�������������æ�Ľֵ��ϣ��ֵ��ϳ�
ˮ�������������������ַǷ����ϱ��Ǿ��ǵĽ�ͨҪ���������֡�������һ����
���ûʵĽ��������ǵ������ϵĵ�һ�購����Τ��ү�ĸ�ۡ�����߲�Զ�Ǿ��ǵ�
�̳����ǳ�͢�����շ��ĳ�����
LONG );
       set("exits", ([
		"north" : "/d/beijing/wang_3",
		"south" : "/d/beijing/caroad_e1",
		"east" : "/d/beijing/wang_2",
		"west" : "/d/beijing/weifu_men",
	]));
	set("objects", ([
		"/d/beijing/npc/youren" : 1,
	]));

	set("coor/x", -10);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
       set("outdoors", "beijing");
	replace_program(ROOM);
}

