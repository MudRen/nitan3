// Room: wuhoucigate.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "���������");
        set("long", @LONG
����ԭ����������������˽��˳�������������ԭ�������ǰ����
�츣������������������ȥ������Ϊ���Т֮�ס���������Ű������ǧ��
���£�����ͷ���Բ�ȥ�ס�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
		"northeast" : "/d/city3/southroad3",
		"north"     : "/d/city3/liubeidian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -450);
	set("coor/y", -210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
