//Room: /d/dali/zhulou3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����¥");
        set("long", @LONG
����һ����ͨ��ʽ��̨����¥������³�������ģ�������������¥��ռ�ع�
��ö࣬Ҳ�ر�ߴ��������㣬�������Ჿ�ļ�����ݡ��˴��²�Ҳ��������
��ɨ�øɸɾ�������������ֱͨ�ϲ㡣
LONG );
	set("exits",([ /* sizeof() == 1 */
	    "south"  : "/d/dali/luwang",
	    "up"     : "/d/dali/zhulou4",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

