#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�������㳡");
        set("long", @LONG
�������찲���ұߵĶ������ֹ㳡�������ĳ������������ͷ���죬����
�����������ַ����ĵضΣ����ǽ�ͨҪ����Ҳ�Ǿ��ǰ����ǵľ۵�, �㳡�ϳ�ˮ
���������ַǷ���С�����ؽֽ������Լ��Ļ��һЩ���ֺ��е��˳���������
�������������������߸ߴ��ʵ�Ĺų�ǽ����������찲�Ź㳡�ˡ�����
���Ƕ�������֡�
LONG );
       set("exits", ([
		"east" : "/d/beijing/caroad_e1",
		"west" : "/d/beijing/tiananmen",
	]));
	set("objects", ([
		"/d/beijing/npc/shusheng1" : 2,
		"/d/beijing/npc/xianren" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -20);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

