inherit ROOM;

void create()
{
      set("short", "����������");
      set("long", @LONG
�����Ƕ��һ��������ȡ���������ͨ����������ͨ���㳡��
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "south" : __DIR__"hcawest2",
          "east"  : __DIR__"hcaguangchang", 
      ]));
      set("coor/x", -570);
	set("coor/y", -330);
	set("coor/z", 220);
	setup();
      replace_program(ROOM);
}
