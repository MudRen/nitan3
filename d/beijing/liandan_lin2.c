#include <ansi.h> 
inherit ROOM;
int do_cai(string arg);

void create()
{
        set("short", "��������");
        set("long", @LONG
����һƬï�ܵ����֡��ܶ�ü�ʮ�ɸߵĴ�������һ�飬��һ�Ѱ������ɡ��
�����¶����ڱε���Ȼ�޹⡣�����л���ʱ������������Ȼ���������졣
LONG );
        set("exits", ([
                "north" : "/d/beijing/ximenwai",
                "south" : "/d/beijing/liandan_lin6",
                "east" : "/d/beijing/liandan_lin7",
        ]));

        set("outdoors", "beijing");
        set("no_clean_up", 0); 
	set("coor/x", -90);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();       
}

#include "liandan_lin.h"