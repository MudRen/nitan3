inherit ROOM;

void create()
{
      set("short", "С·");
      set("long", @LONG
�����Ĵ�������Ľ��硣һ�������ĵ�С��·����������
�������ũ������·�����˺��٣����ҴҸ�·��
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "south" : __DIR__"qsjie1",
          "east"  : __DIR__"xiaolu1",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -360);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}