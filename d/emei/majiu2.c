#include <room.h>
inherit TRANS_ROOM;

void create()
{
      set("short","���");
      set("long",@LONG
���ǲ���ߵ���ǣ����깩Ӧ���ʲ��ϡ�����ǻ����ǣ
����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ
�ź򵽿�����·������жѷ������Ѳ��ϣ������п���ۡ���
�������µ���ľ���϶���һ����ľ��(paizi)��
LONG);
      set("outdoors", "emei");
      set("exits",([
                "south" : __DIR__"huayanding",
      ]));
      set("no_fight", 1);
      set("objects", ([
                "/clone/horse/zaohongma": 1,
                "/clone/horse/huangbiaoma": 1,
                "/clone/horse/ziliuma": 1,
                "/clone/npc/mafu": 1,
      ]));
	set("coor/x", -520);
	set("coor/y", -230);
	set("coor/z", 120);
	setup();
      replace_program(TRANS_ROOM);
}