#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ذ���");
        set("long", @LONG
���������Ͻ��ǵذ��ţ��ߴ�ĳ������Ϸ����š��ذ��š��������֣���ʵ
��̵Ĺų�ǽ�߸������š��������������վ�ż�����������ϸ�ļ��������
�Ϸ��ɵذ��Ŵ��ͨ�����ǵ����ġ�
LONG );
	set("exits", ([
		"south" : "/d/beijing/di_dajie2",
	]));
	set("objects", ([
		"/d/beijing/npc/ducha" : 1,
		"/d/beijing/npc/bing2" : 1,
		"/d/beijing/npc/bing3" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -30);
	set("coor/y", 340);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
