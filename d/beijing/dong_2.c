#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ض����");
        set("long", @LONG
�����Ǳ����ǵذ��ŵĶ��֡��ֵ�����������������֣������������ﲻ����
������ƥ�������С���������й�����ˣ��Ͼ��Ͽ��Ŀ����������ŵ��ӵ�����
�Լ�������ˣ�ŵ���ͯ������һ����æ���ֵ�ʢ�����󡣱����Ǿ��ǹ��Ӽ����
�ڵء��ϱ��ǵذ��ŵĶ��ֹ㳡��
LONG );
       set("exits", ([
		"north" : "/d/beijing/guozijian",
		"south" : "/d/beijing/di_donggc",
		"east" : "/d/beijing/dong_3",
		"west" : "/d/beijing/di_dajie1",
	]));
	set("objects", ([
		"/d/beijing/npc/bing2" : 1,
		"/d/beijing/npc/taijian" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -20);
	set("coor/y", 320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
