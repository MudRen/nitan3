//Room: /d/dali/shanjian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����ɽ��");
        set("long", @LONG
�������Ȼ���ʣ�һ�����������Ϸɽ�������ɽ����������̸�����
���˾���ͽ��ͨ������ˮ�����ɾ���·������ͣ��������Ͳװˮ��ʡ��������
�����֣���Ҷ��ɽ��ɳɳ���졣��Щ���Ĵ���Զ������ɽ������������Ϊʳ��
LONG );
	set("objects", ([
	   "/d/dali/npc/caisunren1": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northdown"  : "/d/dali/milin",
	    "southdown"  : "/d/dali/banshan",
	]));
	setup();
	replace_program(ROOM);
}

