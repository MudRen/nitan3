// Code of ShenZhou
// wsky, 5/7/00
inherit ROOM;

#include <ansi.h>
#include "xx_job.h";

void setup_npc(object me, object ob);

void create()
{
        set("short", "��������");
        set("long", @LONG
���������޺��Աߵ�ɭ�֣��ߴ���������������еĹ��߶�����ס�ˡ�����
�������ǲ�֦��Ҷ��ÿ̤��һ�����ᷢ��֨֨�����죬Զ����ʱ����һ����������
ʹ��ë���Ȼ��
LONG );

        set("exits", ([ 	
             "north" : "/d/xingxiu/forest2",
	     "northwest" : "/d/xingxiu/forest3",
             "northeast" : "/d/xingxiu/forest4",   
	     "south" : "/d/xingxiu/xxh5",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "xingxiuhai");

        set("cost", 2);
        setup();
        

}


