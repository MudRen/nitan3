//Room: /d/dali/chahua5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨԰");
        set("long", @LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����վ�ڲ軨԰�У�����
���使�����εĲ軨���㲻���࿴�����ۡ�������һ��С���������������ů
�紵������������
LONG );
	set("objects", ([
	   "/d/dali/obj/chahua11": 1,
	   "/d/dali/obj/chahua12": 1,
	   "/d/dali/obj/chahua13": 1,
	   "/d/dali/npc/huanu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northwest"  : "/d/dali/chahua3",
	    "southwest"  : "/d/dali/chahua4",
	]));
	setup();
	replace_program(ROOM);
}

