#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ذ������ֹ㳡");
        set("long", @LONG
�����ǵذ��ŵ����ֵĹ㳡���ذ��Ŷ����������ͷ���죬����Ҳ�������
�����ضΣ��Ǿ��Ǳ��ߵĽ�ͨҪ�����㳡�����ַǷ���С�����ؽֽ������Լ���
�������Ҳ����������һЩ��å��졣�ϱ��Ǿ��ǵ�����������������ڵء�
���߾��ǵذ��Ź㳡�ˡ�
LONG );
       set("exits", ([
		"north" : "/d/beijing/di_5",
		"south" : "/d/beijing/di_2",
		"east" : "/d/beijing/dianmen",
		"west" : "/d/beijing/di_3",
	]));
	set("objects", ([
		"/d/beijing/npc/xianren" : 1,
		"/d/beijing/npc/hunhun" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -40);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
