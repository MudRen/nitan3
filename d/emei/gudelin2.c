inherit ROOM;

void create()
{
      set("short", "�ŵ���");
      set("long", @LONG
����һƬ���ܵ��ľ�֣�������ͦ���Σ�֦Ҷ����������
����ӵ�𣬾�˵�������꣬Ҫ�ǲ���Ϥ���κ�������·������
��һƬ�յأ���ֻ�ľ׮�ų�÷��ģ����
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "south"     : __DIR__"bailongdong",
          "southeast" : __DIR__"gudelin1",
          "southwest" : __DIR__"gudelin1",
          "northeast" : __DIR__"gudelin1",
          "northwest" : __DIR__"gudelin1",
      ]));
      set("no_clean_up", 0);
      set("coor/x", -480);
	set("coor/y", -230);
	set("coor/z", 80);
	set("coor/x", -480);
	set("coor/y", -230);
	set("coor/z", 80);
	setup();
      replace_program(ROOM);
}
