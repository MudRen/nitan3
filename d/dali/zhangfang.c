//Room: /d/dali/zhangfang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ʷ�");
        set("long", @LONG
�����������������ʷ�������ÿ������׳��룬�������ģ�ȫ�����ﾭ�֣�
�����Ҷ����˵�нٺ�ʹͣ����ڶ����鷳��ࡣ����ȴ����û�������
LONG );
	set("objects", ([
	   "/d/dali/npc/huo": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "east"  : "/d/dali/wfdating",
	]));
	setup();
	replace_program(ROOM);
}

