//Room: /d/dali/langan3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
һ�������ĸ�����ӣ��˼��²�û��ţ��ȴ����ϯΧ��һ����ɣ�ϵ�С
���ݣ���������̡�¥�ϴ��������ɴ�����������
LONG );
	set("objects",([
	    "/d/dali/npc/yangcannu" : 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"   : "/d/dali/nongtian5",
	    "up"     : "/d/dali/langan4",
	]));
	setup();
	replace_program(ROOM);
}

