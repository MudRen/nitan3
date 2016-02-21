// tyroad6.c ���ɽ·
// by Marz 

inherit ROOM;

#include "feng.h"

string* npcs = ({
        "tufei2",
        "guest",
        "xiao_tufei",
        "guest",
        "xiao_louluo",
        "guest",
});

void create()
{
	int i = random(sizeof(npcs));

	set("short", "���ɽ·");
        set("long", @LONG
������һ�����������ɽ·�ϣ�һ�����ͱڣ�һ�������¡��߸ߵ�������(f
eng)�����������У���Լ�ɼ����������ԵĽ���ͺ����˶���ϸ������Լ��Ľ�
�£�����̧ͷ��һ�ۣ�Ω��һ��С��ˤ��ȥ������ǿ�˳û���٣������޲�����
������ֻ�����·��
LONG );
	set("outdoors", "wudang");
	set("exits", ([
		"westup" : "/d/wudang/tyroad5",
		"southdown" : "/d/wudang/tyroad7",
	]));
	set("item_desc", ([
		"feng" : (:look_feng:),
	]));
	set("objects", ([
		"/d/wudang/npc/"+npcs[i] : 1
	]));
//	set("no_clean_up", 0);
	set("coor/x", -320);
	set("coor/y", -300);
	set("coor/z", 50);
	setup();
}

void init()
{
        add_action("look_feng", "look");
}