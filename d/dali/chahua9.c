//Room: /d/dali/chahua9.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨԰");
        set("long", @LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����վ�ڲ軨԰����ߴ���
��ͷ��ȥ����԰��ɫ������Ŀ�¡�����̨ͤ¥�󣬴������ȡ�
LONG );
	set("objects", ([
	   "/d/dali/obj/chahua7": 1,
	   "/d/dali/npc/muwanqing": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "southdown"  : "/d/dali/chahua7",
	]));
	setup();
	replace_program(ROOM);
}

