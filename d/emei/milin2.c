inherit ROOM;

void create()
{
      set("short","����");
      set("long",@LONG
���Ǻ�ɭɭ��һƬ���֣��ľ���죬Ũ�����ա���������
�Ǳ����£������ּ�������һ�����
LONG);
      set("exits", ([
          "eastdown"  : __DIR__"fhs",
          "westup"    : __DIR__"jietuopo",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
	set("coor/x", -390);
	set("coor/y", -230);
	set("coor/z", 20);
	setup();
      replace_program(ROOM);
}