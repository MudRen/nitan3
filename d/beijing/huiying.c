#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ӣ��¥");
        set("long", @LONG
��Ӣ��¥�����������У�Ҳ����С���������ˡ���¥����������ڣ�װ����
�繬��������������������صķ������顣��С����������æ�ò��ɿ�����
�Ӵ�����ǻ�����Ŀ��ˡ�¥�����νྻ�����п������κ��ݣ�ʮ���Ǹ��̴�֡�
LONG );
       set("exits", ([
		"north" : "/d/beijing/yong_1",
		"up" : "/d/beijing/huiyingup",
	]));
	set("objects", ([
		"/d/beijing/npc/xiaoer2" : 1,
	]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}

