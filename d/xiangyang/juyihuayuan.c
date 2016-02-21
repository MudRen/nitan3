// Room: /d/xiangyang/juyihuayuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��԰");
        set("long", @LONG
���Ǿ���ݵĴ�԰��԰�����Ÿ��ָ����Ļ��ݣ���紵���������ŵ��ɹ�
���㡣԰�ڶ����������һ���᷿��������һ����ˮ��ˮ�ϼ������ȣ�ֱͨ����
�֡������ǹ��ڳ��������Ϸ�����һ����Ʒ����
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"      : "/d/xiangyang/juyifemale",
		"west"      : "/d/xiangyang/juyimale",
		"south"     : "/d/xiangyang/juyichufang",
		"north"     : "/d/xiangyang/juyilang",
		"southeast" : "/d/xiangyang/juyiwupin",
	]));
	set("objects", ([
		"/d/xiangyang/npc/guofu" : 1,
	]));
	set("coor/x", -320);
	set("coor/y", -110);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (me->query("gender") != "����" && dir == "west") 
		return notify_fail("��Ů�б��뵽����ס��\n");

	if (me->query("gender") != "Ů��" && dir == "east") 
		return notify_fail("��Ů�б��뵽����ס��\n");

	return ::valid_leave(me, dir);
}
