// Room: westroad2.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
        set("long", @LONG
һ����ʯ�̳ɵĴ��ͨ���ϱ���·���������ﲻ����ֻ�����治Զ���Ĺ���
����һ����ª��̯�ӣ�̯��һ�ǵ������ڷ���ҡ���ţ�����д�š������������
��ȻҲΧ��һ���ˡ��������������ˣ��������񶼴����
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "south" : "/d/city3/westroad1",
	    "east"  : "/d/city3/shuduroad2",
	    "west"  : "/d/city3/westgate",
	    "north" : "/d/city3/westroad3",
	]));
	set("objects", ([
	    "/d/taishan/npc/tangzi": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -450);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
