#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ذ��Ŵ��");
        set("long", @LONG
�����Ǳ����ǵĵذ��Ŵ�֡��ֵ�����������������֣������������ﲻ����
������ƥ�������С���������й�����ˣ��Ͼ��Ͽ��Ŀ����������ŵ��ӵ�����
�Լ�������ˣ�ŵ���ͯ������һ����æ���ֵ�ʢ�����󡣱��߹��ذ��ŵ��ﾩ��
�ĳǽ����ϱ������ֵĵذ��Ź㳡��
LONG );
       set("exits", ([
		"north" : "/d/beijing/di_anmen",
		"south" : "/d/beijing/di_dajie1",
	]));
	set("objects", ([
		"/d/beijing/npc/dipi" : 1,
		"/d/beijing/npc/tiaofu" : 2,
	]));

	set("outdoors", "beijing");
	set("coor/x", -30);
	set("coor/y", 330);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
