//Room: /d/dali/zhulou4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
        set("long", @LONG
������¥���в������Ჿ�������ã����г��Ϸ�Ҫ�ձ��ڴ˾������ڴ��£�
Ҳ�ڴ˽Ӵ������ͣ�����������ٸ�������ʹ�ߡ������Ա����ͼ�ڱڻ���
����Ƥëװ���ıڡ�
LONG );
	set("objects", ([
	   "/d/dali/npc/zuzhang": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "up"    : "/d/dali/zhulou5",
	    "down"  : "/d/dali/zhulou3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

