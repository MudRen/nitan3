// Room: southroad1.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�ϴ��");
        set("long", @LONG
�������ϴ���ϣ����ż�ʵ����ʯ����档�����Ե����ֶ��ˡ�����������
����֣�����һֱ�߶����ϴ�֡����Ϸ������������֣������и��͵꣬����
����: �����䡣
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "northeast"  : "/d/city3/eastroad3",
	    "southeast"  : "/d/city3/kedian",
	    "west"       : "/d/city3/southroad2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -420);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
