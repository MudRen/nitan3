#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�찲�Ź㳡");
        set("long", @LONG
��������찲�Ź㳡����ɫ�ĳ�ǽ������ׯ������֮�У�������ͨ����ˮ��
���ǻʹ��Ͻ����ˡ�ԶԶ��ȥ���Ͻ��ǵ������淢�Ե���ΰ�ߴ�һ�����Ǻ���
�Ƕ�����һ����ֱ����ʯ�����ᶫ���������Ƕ������ֹ㳡����������������
�㳡���ϱ��ǿ��������ĳ����ֹ㳡�����Ͼ���������һֱ��������̳�������š�
LONG );
	set("exits", ([
		"south" : "/d/beijing/cagc_s",
		"north" : "/d/beijing/qiao",
	       "west" : "/d/beijing/cagc_w",
              "east" : "/d/beijing/cagc_e",
	]));
	set("objects", ([
		"/d/beijing/npc/maiyi2" : 1,
		"/d/beijing/npc/bing1" : 2,
		"/d/beijing/npc/old2" : 1,
		"/d/beijing/npc/kid1" : 1,
                "/clone/npc/walker"  : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -30);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

