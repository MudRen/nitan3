//Room: /d/dali/wfdating.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������������");
        set("long", @LONG
���˴��������ۿ��Ǵ�����ֻ������һ�飬���ң�д�š������ʯ���ĸ���
�֣��������š���î���ʡ��ĸ�С�֣���������������ֻ���һʱҲ����������
�ࡣ�������������������˰칫֮�����������ʷ���������һ��ʯ��ͨ����
լ��
LONG );
	set("objects",([
	    "/d/dali/npc/jiading": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"   : "/d/dali/zhangfang",
	    "east"   : "/d/dali/shijing",
	    "north"  : "/d/dali/zonglichu",
	    "out"    : "/d/dali/wangfugate",
	]));
	setup();
	replace_program(ROOM);
}

