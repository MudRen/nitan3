inherit ROOM;

void create()
{
	set("short", "���������");
        set("long", @LONG
������Ǿ�����Ϊ��������������֡�������������æ�Ľֵ��ϣ��ֵ��ϳ�
ˮ�������������������ַǷ����ϱ��Ǿ��ǵĽ�ͨҪ���������֡�������һ����
����У���������ﴫ��һ����ʿ�������������������ǳ�������ͨ�����ţ�����
�����ž��Ǳ����ǵ������ˡ�
LONG );
       set("exits", ([
		"north" : "/d/beijing/wang_5",
		"south" : "/d/beijing/wang_1",
		"east" : "/d/beijing/wang_4",
		"west" : "/d/beijing/xiaochang",
	]));
	set("objects", ([
		"/d/beijing/npc/bing1" : 1,
	]));

	set("coor/x", -10);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
       set("outdoors", "beijing");
	replace_program(ROOM);
}
