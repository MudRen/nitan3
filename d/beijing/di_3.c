#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�������");
        set("long", @LONG
�����Ǳ����ǵذ��ŵ����֡��ֵ�����������������֣������������ﲻ����
������ƥ�������С���������й�����ˣ��Ͼ��Ͽ��Ŀ����������ŵ��ӵ�����
�Լ�������ˣ�ŵ���ͯ������һ����æ���ֵ�ʢ�����󡣴�����һֱ�������Ե�
�ﵱ����һ�����ݵĸ�ۡ�����Ͼ�����������ֿ���ͨ��������������������
�ĵذ������ֹ㳡��
LONG );
       set("exits", ([
		"north" : "/d/beijing/di_4",
		"south" : "/d/beijing/di_1",
		"east" : "/d/beijing/di_xigc",
	]));
	set("objects", ([
		"/d/beijing/npc/tiaofu" : 1,
		"/d/beijing/npc/dipi" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -50);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
