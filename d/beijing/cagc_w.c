#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�������㳡");
        set("long", @LONG
�������찲����ߵ��������ֹ㳡�������ĳ������������ͷ���죬����
�����������ַ����ĵضΣ����ǽ�ͨҪ����Ҳ�Ǿ��ǰ����ǵľ۵�, �㳡�ϳ�ˮ
���������ַǷ���С�����ؽֽ������Լ��Ļ��һЩ���ֺ��е��˳���������
�������������������߸ߴ��ʵ�Ĺų�ǽ����������찲�Ź㳡�ˡ�����
���ǿ�������������֡�
LONG );
       set("exits", ([
		"west" : "/d/beijing/caroad_w2",
		"east" : "/d/beijing/tiananmen",
	]));
	set("objects", ([
		"/d/beijing/npc/girl4" : 1,
		"/d/beijing/npc/girl2" : 1,
		"/d/beijing/npc/shusheng2" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -40);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
