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
		"north" : "/d/beijing/wang_6",
		"south" : "/d/beijing/wang_2",
		"east" : "/d/beijing/chaoyang_dao1",
		"west" : "/d/beijing/wang_3",
	]));

	set("coor/x", 0);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
       set("outdoors", "beijing");
	replace_program(ROOM);
}
