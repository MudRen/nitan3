// Room: northroad2.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
        set("long", @LONG
����һ������ֺ�ᶫ�������򱱱ߣ��ǳ��ǵı��š��ų� "������" ����
��ɽ�����Ǵ������ȥ������ص�����������ȴ�������Ҵң�С�������޲���
�����伣����Ϊ�ϱ�һ����ɫ����Ľ��������������������ŷ�ɫ��Ĵ������š�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "east"   : "/d/city3/northroad3",
	    "west"   : "/d/city3/northroad1",
	    "south"  : "/d/city3/tanggate",
	    "north"  : "/d/city3/northgate",
	]));
	set("no_clean_up", 0);
	set("coor/x", -430);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	me = this_player();
	if (dir == "south")
	return notify_fail("��һ̧�㣬���ֵ����ж���æ�����˻ء�\n");
	else  return 1;
}
