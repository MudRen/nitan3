#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ذ��Ŷ��ֹ㳡");
        set("long", @LONG
�����ǵذ��ŵĶ��ֵĹ㳡���ذ��Ŷ����������ͷ���죬����Ҳ�������
�����ضΣ��Ǿ��Ǳ��ߵĽ�ͨҪ�����㳡�����ַǷ���С�����ؽֽ������Լ���
�������Ҳ����������һЩ��å��졣�ϱ��Ǿ��ǵ�����������������ڵء�
�����ǵذ��Ź㳡�����߽Ӿ�����������������֡�
LONG );
       set("exits", ([
		"north" : "/d/beijing/dong_2",
		"south" : "/d/beijing/dong_1",
		"east" : "/d/beijing/wang_9",
		"west" : "/d/beijing/dianmen",
	]));
	set("objects", ([
		"/d/beijing/npc/liumang" : 1,
		"/d/beijing/npc/kid1" : 1,
		"/d/beijing/npc/girl2" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -20);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
