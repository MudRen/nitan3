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
                "west" : "/d/beijing/liandan_lin1",
        ]));

        set("no_clean_up", 0); 
	set("coor/x", -80);
	set("coor/y", 290);
	set("coor/z", 0);
	setup();       
}

#include "liandan_lin.h"