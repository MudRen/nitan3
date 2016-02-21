// Room: /d/xiangyang/eastgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��������");
        set("long", @LONG
�����������ǵĶ����ţ�ֻ�������Ϸ����š������š��������֡����Ÿ���
�ɣ���Լ�������࣬�����ĳ�����������ȭͷ���С���������Ŷ���Լ���ɣ�
��Լÿ������ʱ���ͻ��ٱ����ء��������ɹ��Ŵ��ַ������ǣ�����������൱
���ܣ�����һЩ�ٱ��������̲�Ҫ�������ǵ��ˡ�
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"west"  : "/d/xiangyang/eastgate1",
                "east"  : "/d/city2/yidao",
                "northeast"  : "/d/zhongzhou/toyy",
	]));
	set("objects", ([
		"/d/xiangyang/npc/pi"   : 1,
		"/d/xiangyang/npc/bing" : 2,
	]));
	set("coor/x", -240);
	set("coor/y", -90);
	set("coor/z", 0);
	setup();
}


int valid_leave(object me,string dir)
{
       if( dir == "east" && !wizardp(me) 
           && !me->query_temp("warquest") )
       return notify_fail("��Ӫ�صأ������˵ȣ��������ڣ�\n");

       return ::valid_leave(me,dir);
}
