//Room: /d/dali/piandian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ƫ��");
        set("long", @LONG
�����Ǵ�����ʹ���ƫ�����ʵ۳�������Ӽ��ĸ��󳼣��������Եÿ�
�յ����ģ������ǳ��ȡ�
LONG );
	set("exits",([ /* sizeof() == 1 */
	    "west"  : "/d/dali/hualang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

