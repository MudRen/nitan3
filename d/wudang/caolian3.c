#include <room.h>
inherit ROOM;

void create()
{
      set("short", "���������");
      set("long", @LONG
��������˴󵶳�����ɳ�����ȵȣ����䵱�����ճ�����
�ĵط���
LONG);

      set("exits", ([
            	"east"   : __DIR__"caolianfang",
      ]));
      set("for_family", "�䵱��");
	set("coor/x", -400);
	set("coor/y", -300);
	set("coor/z", 100);
	setup();
      replace_program(ROOM);
}