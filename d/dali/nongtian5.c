//Room: /d/dali/nongtian5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ũ��");
        set("long", @LONG
����һС����ͨ��ˮ�������Ϫ�����������ʮ�ַ��㡣Χ��ũ�����һ
ƬƬɣ�֣������˲�ɣ�����ϣ���֯�൱���µ�˿֯Ʒ������������ӡ�
LONG );
	set("objects", ([
	   "/d/dali/npc/nongfu2": 1,
	   "/d/dali/npc/cow": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"  : "/d/dali/buxiongbu",
	    "east"   : "/d/dali/langan3",
	]));
	setup();
	replace_program(ROOM);
}

