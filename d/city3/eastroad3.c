// Room: eastroad3.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
        set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档����һ����ֱ�Ĵ�������߿�
��ͨ�������ţ����ϱ�ͨ���ϴ�֣����Ϸ���������������¥�ˡ��������Ǵ���
�����������˳ɶ��ֲ���
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "southeast"  : "/d/city3/wangjianglou",
	    "southwest"  : "/d/city3/southroad1",
	    "north"      : "/d/city3/eastroad2",
            "east"      : "/d/city3/xym_cdfb",
	]));
//	set("no_clean_up", 0);
	set("coor/x", -410);
	set("coor/y", -190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
