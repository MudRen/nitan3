//Room: /d/dali/qingzhulin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
        set("long", @LONG
һ��Ƭï�ܵ�������������ɽ�����ӳ�ȥ���˼��������ۣ������أ�����
¬¹���̨�ĸ�Ů��ǰ����ժ����Ϊʳ������Ҳ����Щ��������������Ͳ�ͱ�֯
��������¨��
LONG );
	set("objects", ([
	   "/d/dali/npc/caisunren": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"   : "/d/dali/wuding",
	]));
	setup();
	replace_program(ROOM);
}

