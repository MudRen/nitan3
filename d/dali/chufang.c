//Room: /d/dali/chufang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
�������������ĳ����������и������ӣ���Χ����ż���Բ�ʣ������Ƕμ�
�����ò͵ĵط���
LONG );
	set("objects", ([
	    "/d/dali/obj/xueli"       : 4,
	    "/d/dali/npc/obj/puercha" : 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "east"  : "/d/dali/tingfang",
	]));
	setup();
	replace_program(ROOM);
}

