inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","Τ������");
        set("long", @LONG
������ǵ�����һ�購��������������Ϊ��һ��¹��������Τ��ү�ľ�լ��
�������һ�������ûʵĸߴ��������������ǰ��������������ͷ�ߴ��ʯ
ʨ�ӡ����Ϻ���һ����ң������Ǵ�ѧʿ����ͼ�ױ���д�ġ�¹���������ĸ���
�ʴ��֡���ǰվ�Ÿ�Τ����������
LONG );
	set("exits", ([
		"west" : "/d/beijing/weifu_zoulang1",
		"east" : "/d/beijing/wang_1",
	]));
	set("objects", ([
		"/d/beijing/npc/lilishi" : 1,
	]));
	set("coor/x", -20);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("li lishi", environment(me))) && dir == "west")
		return notify_fail("�������ȵ������ҹ䣬��ү���첻���͡�\n\n");
	return ::valid_leave(me, dir);
}
