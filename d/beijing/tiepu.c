#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
�������ڶ��ֵ�һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һ
Ƭͨ�죬��һ�߽�ȥ�͸е�������ȡ������̵�ǽ�Ƕ��������깤��δ�깤�Ĳ�
����������������ذ�ס����׵��һλ������ͷ�󺹻�����������ר����־��
�ڴ�����
LONG );
       set("exits", ([
		"north" : "/d/beijing/yong_2",
	]));
	set("objects", ([
		"/d/beijing/npc/tiehuoji" : 1,
		"/d/beijing/npc/tiejiang" : 1,
	]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}

