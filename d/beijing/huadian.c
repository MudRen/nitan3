#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ʻ���");
        set("long", @LONG
����һ��СС�ĵ��棬��˵������ϰ��Ǹ���ʮ�������ͷ�ӣ��������ʱ
������ȴ��һλ��������С�����ʱ������ϸ�ĵ�Ϊ�ͻ���ѡ���䣬̬�ȷ�
������, ���ϵ�����С������ʢ������������Ц�ݡ���ʱ��Ҳ��ո�Ȥ��������
����������
LONG );
       set("exits", ([
		"south" : "/d/beijing/yong_2",
	]));
	set("objects", ([
		"/d/beijing/npc/huanv" : 1,
	]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}

