inherit ROOM;

void create()
{
	set("short", "Τ������");
        set("long", @LONG
�������¹�������Ĵ������൱�Ŀ����������ܵ�ǽ���������˸�������
���漣���������������������ߣ����ϵ��������Ա߻�վ��һ���ϸ���һ����ʮ
������������ӣ������ӹ�����񣬲�ס�Ŀ��ԡ�����������Τ��ү���鷿����
�����߷ֱ��������᷿��
LONG );
	set("exits", ([
		"north" : "/d/beijing/weifu_shufang",
		"south" : "/d/beijing/weifu_zoulang2",
		"west" : "/d/beijing/weifu_fangw",
		"east" : "/d/beijing/weifu_fange",
	]));
	set("objects", ([
		"/d/beijing/npc/guixinshu" : 1,
		"/d/beijing/npc/guierniang" : 1,
		"/d/beijing/npc/guizhong" : 1,
		"/d/beijing/npc/liudahong" : 1,
	]));
	set("outdoors", "beijing");
       set("coor/x", -30);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

