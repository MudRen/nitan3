//Room: /d/dali/nianhuasi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�黨��");
        set("long", @LONG
ɽ·Խ��Խ��Ƨ��ת���ĸ�ɽ�꣬����һ��СС�Ĺ���ǰ��������д�š���
���¡����֡�����Ǵ�����̡����������⣬������ʮ��С���԰ټƣ�������
�黨�¡��ش�ƫƧ��������𣬼������Ӵ���֮�ˣ����Ҳ��֪����
LONG );
	set("objects", ([
	   "/d/dali/npc/pochen": 1,
	   "/d/dali/npc/poyi": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "enter"      : "/d/dali/nianhua1",
	    "southdown"  : "/d/dali/shanlu2",
	]));
	setup();
	replace_program(ROOM);
}

