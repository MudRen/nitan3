// Room: /city/xixiang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���ǲ���С��Ĺ뷿��һ���������������һ����齷���ǽ�ǣ�����ϸɴ��
С����������ϣ��������һ��˼��ģ����������ͻȻ�������������ˡ�
LONG );
	set("exits", ([
		"east" : "/d/city/houyuan",
	]));
	set("objects", ([
		"/d/city/npc/yingying" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
