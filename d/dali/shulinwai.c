//Room: /d/dali/shulinwai.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
        set("long", @LONG
��������һƬ��ɭɭ��������ǰ��������ȥ����������Ķ�����ľ�����Ҿ�
����������Լ�ɼ���ЩС·��������������ϸ�۲죬��������Ȼ�Ǹ�������Թ���
���а������а��ԣ����Ŷݼף��˵ķ�ͬС�ɣ�ǧ��ҪðȻ��ȥ��
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : "/d/dali/heilongling",
            "south"      : __DIR__"maze1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

