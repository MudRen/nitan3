// Room: caotang.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "�Ÿ�����");
        set("long", @LONG
�����ǶŸ���Ԣ�ɶ��Ĺʾӡ���������ˮ���ӣ�С�Ź�����������ӳ���Ե�
��ׯ�����£����ӵ��ţ��ֲ�ʧ����ף��������ʡ�
LONG );
        set("outdoors", "chengdu");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : "/d/city3/path2",
	]));
	set("coor/x", -480);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
