inherit ROOM;

void create()
{
	set("short", "���������");
        set("long", @LONG
������Ǿ�����Ϊ��������������֡�������������æ�Ľֵ��ϣ��ֵ��ϳ�
ˮ�������������������ַǷ����ϱ߽Ӿ��ǵĽ�ͨҪ���������֣������Ƿ�����
�ذ��Ŷ���ֹ㳡�����������ض���ֿ��Ե�������
LONG );
       set("exits", ([
		"north" : "/d/beijing/dong_3",
		"south" : "/d/beijing/wang_7",
		"east" : "/d/beijing/wang_10",
		"west" : "/d/beijing/di_donggc",
	]));

	set("objects", ([
		"/d/beijing/npc/haoke1" : 1,
	]));

	set("coor/x", -10);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
       set("outdoors", "beijing");
	replace_program(ROOM);
}
