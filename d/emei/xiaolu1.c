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
          "west"      : __DIR__"xiaolu2",
          "northeast" : __DIR__"wdroad",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -350);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}