//Room: /d/dali/langan1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
��������������ľ�Ծ����ϣ����Ǹ�������������������̡��乹�����
����¥�����濪�ţ����ݿ����£��ϸ��糵��״���в�ס�ˣ��������²㣬һ��
Ϊţ��Ȧ��
LONG );
	set("objects",([
	    "/d/dali/npc/shanyang" : 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"   : "/d/dali/nongtian2",
	    "up"      : "/d/dali/langan2",
	]));
	setup();
	replace_program(ROOM);
}

