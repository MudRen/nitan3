inherit ROOM;

void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ��������ֱ����������Ĵ�ٵ�������ݵ���ʮ���ۡ��ϱ�
��Զ�Ƕ��������ųǵı��ţ�����ֱ�Ͽ��Ե��ﻪɽ��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"guandaon2",
  		"south" : __DIR__"nbridge",
	]));

	set("coor/x", -170);
	set("coor/y", 70);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
