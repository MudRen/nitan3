inherit ROOM;

void create()
{
	set("short", "���������");
        set("long", @LONG
������Ǿ�����Ϊ��������������֡�������������æ�Ľֵ��ϣ��ֵ��ϳ�
ˮ�������������������ַǷ����ϱ��Ǿ��ǵĽ�ͨҪ���������֡�������������
��һ�������ûʵĽ��������ǵ������ϵĵ�һ�購����Τ��ү�ĸ�ۡ�����߾���
���ǵ��̳����ǳ�͢�����շ��ĳ�����
LONG );
       set("exits", ([
		"north" : "/d/beijing/wang_4",
		"south" : "/d/beijing/caroad_e2",
		"east" : "/d/beijing/xingchang",
		"west" : "/d/beijing/wang_1",
	]));
	set("objects", ([
		"/d/beijing/npc/shusheng1" : 1,
	]));

	setup();
       set("outdoors", "beijing");
	replace_program(ROOM);
}

