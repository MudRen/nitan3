//Room: /d/dali/garments.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","Ѧ�ǳ�����");
        set("long", @LONG
����һ�����ֺŵĹ���ׯ����������˸�ʽ����������񡢾˿������
Ƥ������춷��л������ȹ��ˮ��ɫ�ް�������ɫ�Ż���������һ���㡣
LONG );
	set("objects", ([
	   "/d/dali/npc/xueboss": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "south" : "/d/dali/taiheeast",
	]));
	setup();
	replace_program(ROOM);
}

