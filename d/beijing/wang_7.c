inherit ROOM;

void create()
{
	set("short", "���������");
        set("long", @LONG
������Ǿ�����Ϊ��������������֡�������������æ�Ľֵ��ϣ��ֵ��ϳ�
ˮ�������������������ַǷ����ϱ߽Ӿ��ǵĽ�ͨҪ���������֣�����ͨ���ذ�
�Ŷ���֡�
LONG );
       set("exits", ([
		"north" : "/d/beijing/wang_9",
		"south" : "/d/beijing/wang_5",
		"east" : "/d/beijing/wang_8",
		"west" : "/d/beijing/dong_1",
	]));

	set("objects", ([
		"/d/beijing/npc/girl3" : 1,
	]));

	set("coor/x", -10);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
       set("outdoors", "beijing");
	replace_program(ROOM);
}
