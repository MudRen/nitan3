#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����ĳ�");
        set("long", @LONG
������Ǳ����������ĺ����ĳ������ܵĶķ��ﴫ����ߺ������ĶĲ�����
����ĳ���ģ���㲻�Ϻܴ�, ���ĵ�����ȴ����ȫ, ����Ҳ�ǳ��ܵ��������, 
���ϵĸ��и�ɫ���˼�����һ��, ���������ĸ����ӵ�, Ҳ����ö��������
�������õ��彣�ĵĽ�������, Ҳ�е���ॵ�����å��Ʀ���йٸ�������, Ҳ��
���ӵķ��ˡ�
LONG );
       set("exits", ([
		"south" : "/d/beijing/yong_1",
	]));
	set("objects", ([
		"/d/beijing/npc/duke" : 2,
		"/d/beijing/npc/liumang" : 1,
		"/d/beijing/npc/haoke1" : 1,
		"/d/beijing/npc/dipi" : 1,
	]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}

