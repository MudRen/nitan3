#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�������");
        set("long", @LONG
�����Ǳ����ǵذ��ŵ����֡��ֵ�����������������֣������������ﲻ����
������ƥ�������С���������й�����ˣ��Ͼ��Ͽ��Ŀ����������ŵ��ӵ�����
�Լ�������ˣ�ŵ���ͯ������һ����æ���ֵ�ʢ�����󡣱�����һ�������ûʵ�
��լ���Ǿ��ǵ�����һ�󳼣�������Ϊ�����޵�һ��ʿ�������ݵĸ�ۡ�����Ͼ�
����������ֿ���ͨ�����������������ı���֡�
LONG );
       set("exits", ([
		"north" : "/d/beijing/aofu_men",
		"south" : "/d/beijing/di_3",
		"east" : "/d/beijing/di_5",
		"west" : "/d/beijing/shi_3",
	]));
	set("objects", ([
		"/d/beijing/npc/boy2" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -50);
	set("coor/y", 320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
