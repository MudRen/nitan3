// Room: southroad2.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�ϴ��");
        set("long", @LONG
�������ڳɶ������ϴ���ϣ�����һ���������Ĵ�·��һֱ���������졣
·�����������������ò����֡�һЩС��С������������ЩС���������������ţ�
����һ����������ᶽ�֣���һ����֪��Ϊɶ���ᰲ���ˡ�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "north"  : "/d/city3/tiduroad",
	    "south"  : "/d/city3/southgate",
	    "east"   : "/d/city3/southroad1",
	    "west"   : "/d/city3/southroad3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -430);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
