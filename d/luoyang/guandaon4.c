inherit ROOM;

void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ��������ֱ����������Ĵ�ٵ�������ݵ���ʮ���ۡ��ϱ�
�Ƕ��������ųǣ�����ֱ�Ͽ��Ե��ﻪɽ��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "northeast" : "/d/kaifeng/ximen",
  		"south" : __DIR__"guandaon3",
	]));

	set("coor/x", -170);
	set("coor/y", 100);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
