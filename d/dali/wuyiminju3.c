//Room: /d/dali/wuyiminju3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�������");
        set("long", @LONG
����һ��������ķ��ݡ��˼���������������ɽ�ƿ������ſ�������İ��
��ʯ�󷿣�װ����Ϊ���ף������Ǿ��ĵ��Ƶģ������ա��¡������Ⱦ�����ͼ����
�����������������ļ�����ݡ�
LONG );
	set("exits",([ /* sizeof() == 1 */
	    "enter"  : "/d/dali/jisidawu1",
	    "east"   : "/d/dali/zhenxiong",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

