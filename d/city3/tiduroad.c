// Room: tiduroad1.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�ᶽ��");
        set("long", @LONG
�ᶽ�־�����Ϊͨ���ᶽ������������һ���������˺��٣�������ľ͸���
�����ˡ��ᶽ���˺����������벻���ģ����˺ö�����������������������ﶼ
��������̤�롣
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "south"  : "/d/city3/southroad2",
	    "north"  : "/d/city3/guangchang",
	]));
	set("objects", ([
	    "/d/city/npc/bing" : 3,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -430);
	set("coor/y", -190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
