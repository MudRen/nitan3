// Room: westroad1.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
        set("long", @LONG
�������ڳɶ�����������ϣ�����һ���������Ĵ�·��������һֱ���졣
·�����������������ò����֡�С��С������������ЩС�����������ɼ�������
�Ÿ�ͷ��������䡣
    ���ϱ�ȴ�Ե��ر��徲�������Ǹ��������ڣ����Ϸ���ͨ���ϴ�֡�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "southwest"  : "/d/city3/qingyanggong",
	    "southeast"  : "/d/city3/southroad3",
	    "north"      : "/d/city3/westroad2",
	]));
	set("objects", ([
	    "/d/village/npc/seller": 1,
	    "/d/city/npc/liumang"  : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -450);
	set("coor/y", -190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
