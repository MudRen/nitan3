// tyroad7.c ���ɽ·
// by Marz 

inherit ROOM;

#include "feng.h"

void create()
{
	set("short", "���ɽ·");
        set("long", @LONG
������һ�����������ɽ·�ϣ�һ�����ͱڣ�һ�������¡��߸ߵ�������(f
eng)�����������У���Լ�ɼ����������ԵĽ���ͺ����˶���ϸ������Լ��Ľ�
�£�����̧ͷ��һ�ۣ�Ω��һ��С��ˤ��ȥ������ǿ�˳û���٣������޲�����
������ֻ�����·��
LONG );
	set("outdoors", "wudang");
	set("exits", ([
		"northup" : "/d/wudang/tyroad6",
		"eastdown" : "/d/wudang/tyroad8",
	]));
	set("item_desc", ([
		"feng" : (:look_feng:),
	]));
	set("no_clean_up", 0);
	set("coor/x", -320);
	set("coor/y", -310);
	set("coor/z", 40);
	setup();
}
 
void init()
{
        add_action("look_feng", "look");
}