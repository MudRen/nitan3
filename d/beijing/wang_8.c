inherit ROOM;

void create()
{
	set("short", "���������");
        set("long", @LONG
������Ǿ�����Ϊ��������������֡�������������æ�Ľֵ��ϣ��ֵ��ϳ�
ˮ�������������������ַǷ����ϱ߽Ӿ��ǵĽ�ͨҪ���������֣�����ͨ���ذ�
�Ŷ���֡��Ӷ��ߴ���һ�����ӵ������������Ǿ�������������Ժ��
LONG );
       set("exits", ([
		"north" : "/d/beijing/wang_10",
		"south" : "/d/beijing/wang_6",
		"east" : "/d/beijing/yihongyuan",
		"west" : "/d/beijing/wang_7",
	]));

	set("objects", ([
		"/d/beijing/npc/richman1" : 1,
	]));

	set("coor/x", 0);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
       set("outdoors", "beijing");
	replace_program(ROOM);
}
