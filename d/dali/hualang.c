//Room: /d/dali/hualang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
�����Ǵ�����ʹ��Ļ��ȣ������µ������滨��ݣ������������������
��԰�����������ŷ���������ƫ�
LONG );
	set("objects", ([
	   "/d/dali/npc/gongnu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"  : "/d/dali/yuhuayuan",
	    "north"  : "/d/dali/zhengdian",
	    "east"   : "/d/dali/piandian",
	    "west"   : "/d/dali/yushanfang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


