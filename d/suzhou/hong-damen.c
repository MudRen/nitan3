//Room: /d/suzhou/hong-damen.c
// by llm 99/06/12

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����ׯ����");
   set("long",
"��ǰ��һ��������ΰ�Ĵ�ׯͥ�����ȸߴ���ǽ���ߣ�����Щ��ʹ�\n"
"���Ƶ�ζ����ֻ�Ǵ����������Ĳ������롢ʨ�ޣ�����Ц���е�ϲ��ͯ��\n"
"ͯŮ�����Ҵ��ų���������������룬��������һ��޴����ľ����\n"
HIR"            ��    ��    ׯ\n"NOR
"\n");
	set("exits", ([
		"west" : "/d/suzhou/canlangting",
                "east" : "/d/suzhou/hong-zoulang",
   ]) );


   set("objects", ([
//   	"/d/suzhou/npc/meipo" : 1,
      ]) );
   set("coor/x", 210);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
   replace_program(ROOM);
}


