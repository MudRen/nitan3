#include <room.h>
inherit TRANS_ROOM;

void create()
{
      set("short", "���");
        set("long", @LONG
���������ݿ͵�����ǣ����깩Ӧ���ʲ��ϡ�������紾�ӣ�����ǻ��
��ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿�����
·����������µ���ľ���϶���һ����ľ�� (paizi��������жѷ������Ѳ��ϡ�
LONG );
      set("outdoors", "city");
      set("no_fight", 1);
      set("objects", ([
              "/clone/horse/zaohongma": 1,
              "/clone/horse/huangbiaoma": 1,
              "/clone/horse/ziliuma": 1,
              "/clone/npc/mafu": 1,
      ]));
      set("exits",([
              "west" : __DIR__"kedian",
              "up"   : "/clone/shop/yangzhou_shop",
                "north" : __DIR__"business",
      ]));
	set("coor/x", 20);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
      replace_program(TRANS_ROOM);
}