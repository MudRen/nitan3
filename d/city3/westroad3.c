// Room: westroad3.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
        set("long", @LONG
�㲻֪�����ؾ������˳ɶ������ǣ����������������Եø������塣��ʯ��
����ֻ����������ļ����ˣ����������й䡣����������֣�������������һ��
��֣��������и��ô��ҩ�꣬��һЩ�������˳��õ�ҩ�����ŵ��ӳ�������ҩ��
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "south"      : "/d/city3/westroad2",
	    "northeast"  : "/d/city3/northroad1",
	    "northwest"  : "/d/city3/yaodian",
	]));
	set("objects", ([
	    "/d/huashan/npc/haoke": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -450);
	set("coor/y", -170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
