inherit ROOM;

void create()
{
      set("short", "������");
      set("long", @LONG
�����ǡ������š������ӲӵĽ𶥾�����ǰ�ˡ�
LONG);
      set("exits", ([
          "northdown": __DIR__"toutiangate",
          "southup"  : __DIR__"santiangate",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -350);
	set("coor/y", -400);
	set("coor/z", 160);
	setup();
      replace_program(ROOM);
}