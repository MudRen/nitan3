// tyroad5.c ���ɽ·
// by Marz 

inherit ROOM;

#include "feng.h"

void create()
{
	set("short", "���ɽ·");
        set("long", @LONG
������һ�������խ��ɽ·�ϣ�һ�����ͱڣ�һ�������£��߸ߵ�������(f
eng)����������Լ�ɼ������ԵĽ���ͺ����˶���ϸ�ض����Լ��Ľ��£�����̧
ͷ��һ�ۣ�Ω��һ��С��ˤ��ȥ������ǿ�˳û���٣������޲�����������ֻ��
����·��
LONG );
	set("outdoors", "wudang");
	set("exits", ([
		"northup" : "/d/wudang/tyroad4",
		"eastdown" : "/d/wudang/tyroad6",
	]));
	set("item_desc", ([
		"feng" : (:look_feng:),
	]));
	set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -300);
	set("coor/z", 60);
	setup();
}

void init()
{
        add_action("look_feng", "look");
}