//Room: /d/dali/nongtian3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ũ��");
        set("long", @LONG
�����Ѿ���ƽԭ�ľ�ͷ����������վ���ɽ���ˣ�һЩ��ũ�����٤������
�ķ������ǵطֲ���ɽ���£�һЩ�����������������������·���ϵ�ɽ����
�Ѷ�ȥ��
LONG );
	set("objects", ([
	   "/d/dali/npc/nongfu2": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : "/d/dali/nongtian2",
	    "southeast" : "/d/dali/shanlu7",
	]));
	setup();
	replace_program(ROOM);
}

