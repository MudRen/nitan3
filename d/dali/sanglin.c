//Room: /d/dali/sanglin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɣ��");
        set("long", @LONG
һ��Ƭɣ���������ڵ�ɽ�Ļ���ɽ���ϡ����ϡ���˿�ǰ��������Ҫ��ҵ��
���ĸ�Ů����֯˿����֯�Լ����ŵĶ�ȹ��Ҳ�������ٽ����佻��Щ������Ʒ��
һȺ���Ĺ��������ּ�æ�Ų�ժɣҶ��
LONG );
	set("objects", ([
	   "/d/dali/npc/caisangnu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northdown"  : "/d/dali/yangzong",
	]));
	setup();
	replace_program(ROOM);
}

