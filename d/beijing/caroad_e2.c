#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
        set("long", @LONG
���ֵĶ�����������Ͻ��ǵĽ�ͨҪ������������ʯ���������ͷ���죬
�ֵ������˲��ϣ�������ʢ�������Զ��������������ԶԶ����������һ�¶�
�ߴ��ʵ�Ĺų�ǽ�������������찲�Ź㳡�ˡ������Ǿ�����Ϊ�������ֵ�����
����֡����ϱߴ���һ��Ũ�ҵ��̲���ζ��ԭ��������һ���̲ݵꡣ������һ��
�ӻ��̡�
LONG );
       set("exits", ([
		"north" : "/d/beijing/wang_2",
		"south" : "/d/beijing/yancao",
		"east" : "/d/beijing/zahuo",
		"west" : "/d/beijing/caroad_e1",
	]));
	set("objects", ([
		"/d/beijing/npc/old1" : 1,
		"/d/beijing/npc/hunhun" : 1,
	]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}

