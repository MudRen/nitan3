#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�������");
        set("long", @LONG
�����Ǳ����ǵذ��ŵ����֡��ֵ�����������������֣������������ﲻ����
������ƥ�������С���������й�����ˣ��Ͼ��Ͽ��Ŀ����������ŵ��ӵ�����
�Լ�������ˣ�ŵ���ͯ������һ����æ���ֵ�ʢ�����󡣴�����һֱ�������Ե�
�ﵱ����һ�����ݵĸ�ۡ�����Ͼ�����������ֿ���ͨ��������
LONG );
       set("exits", ([
		"north" : "/d/beijing/di_3",
		"east" : "/d/beijing/di_2",
		"south" : "/d/beijing/bei_4",
	]));
	set("objects", ([
		"/d/beijing/npc/youren" : 1,
		"/d/beijing/npc/shusheng2" : 1,
		"/d/beijing/npc/kid1" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -50);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
