#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","��ˮ��");
        set("long", @LONG
һ������Ĺ��ţ�������Ͻ��ǵĻ��Ǻ�������ͨ����ˮ�����߱����Ͻ�
�ǵ������ˣ���������ɭ�ϣ���ʵ�ĳ�ǽ�߸ߵ������š��ŵ��������������찲
�Ź㳡�����������������ӵ������������������е��������ﲻ�������ַǷ���
LONG );
	set("exits", ([
		"south" : "/d/beijing/tiananmen",
		"north" : "/d/beijing/hgmen_s",
	]));
	set("objects", ([
		"/d/beijing/npc/bing1" : 2,
		"/d/beijing/npc/xiaofan" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -30);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
