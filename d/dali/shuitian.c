//Room: /d/dali/shuitian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ˮ��");
        set("long", @LONG
����һƬ����ƽ�ص�ũ������﹡��ȫ������ˮ��û�ţ�һЩ���Ჿ�ĸ�
Ů���Ž�������������������ˮ���㣬��Ȼû�н��������������ر�Ĺ�ȣ�
ÿ������������Ȼ��ˮ������
LONG );
	set("objects", ([
	   "/d/dali/npc/cow": 1,
	   "/d/dali/npc/nongfu1": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : "/d/dali/luwang",
	]));
	setup();
	replace_program(ROOM);
}

