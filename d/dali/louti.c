//Room: /d/dali/louti.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","¥��");
        set("long", @LONG
�����ͨ����¥��ӭ��ի����¥�ݣ�¥�ݸ�����ʮ�༶�����������ʺ��ë
ձ��¥������վ��һЩ������ʿ��¥�����ǹ����Ϣ�ĵط���
LONG );
	set("objects", ([
	   "/d/dali/npc/weishi": 3,
	   CLASS_D("dali")+"/gaoshengtai": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "up"      : "/d/dali/zoulang1",
	    "south"   : "/d/dali/dating",
	]));
	setup();
	replace_program(ROOM);
}

