#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�������");
        set("long", @LONG
�����Ǳ����ǵذ��ŵ����֡��ֵ�����������������֣������������ﲻ����
������ƥ�������С���������й�����ˣ��Ͼ��Ͽ��Ŀ����������ŵ��ӵ�����
�Լ�������ˣ�ŵ���ͯ������һ����æ���ֵ�ʢ�����󡣱����ǵذ������ֵĹ�
�����ϱ߾������ϣ���ʱ�йٱ�����������ԭ��������Ǿ��ǵ��������������
�������ڵء�
LONG );
       set("exits", ([
		"north" : "/d/beijing/di_xigc",
		"west" : "/d/beijing/di_1",
		"south" : "/d/beijing/xichang_men",
	]));
	set("objects", ([
		"/d/beijing/npc/bing3" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -40);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
