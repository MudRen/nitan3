inherit ROOM;

void create()
{
	set("short", "���������");
        set("long", @LONG
������Ǿ�����Ϊ��������������֡�������������æ�Ľֵ��ϣ��ֵ��ϳ�
ˮ�������������������ַǷ����ϱ��Ǿ��ǵĽ�ͨҪ���������֡��򱱿��Եذ�
�Ŷ���֡�
LONG );
       set("exits", ([
		"north" : "/d/beijing/wang_7",
		"south" : "/d/beijing/wang_3",
		"east" : "/d/beijing/wang_6",
	]));

	set("coor/x", -10);
	set("coor/y", 290);
	set("coor/z", 0);
	setup();
       set("outdoors", "beijing");
	replace_program(ROOM);
}
