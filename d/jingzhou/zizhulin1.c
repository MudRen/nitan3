#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ǰͻȻһ���������������һ������������ɵĻ�
԰(yuan)��ǰ������Ʈ�������㣬�������񻷱���˵������
ʫ�黭�⡣��Լ������������Щ���ܡ�
LONG);
        set("outdoors", "jingzhou");

	set("exits", ([
		"north" : __DIR__"zizhulin",
		"enter" : __DIR__"xiaoyuan",
	]));
        set("item_desc", ([
                "yuan": HIM "\n���￴����һ���ֻ��ĺõط�������Լ��������"
                        "����������\n�Ļ��ܣ��������������ɡ�\n" NOR
        ]) );
	set("coor/x", -450);
	set("coor/y", -250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

