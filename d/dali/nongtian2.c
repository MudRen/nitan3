//Room: /d/dali/nongtian2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ũ��");
        set("long", @LONG
����һС����ͨ��ˮ��أ���گ��ů��ʪ���Թ�����������ֲˮ��Ϊ������
�����Ǵ�������ټ���ƽԭ���Σ���Ҫ�Ը���Ϊ���İ����˿�����һЩ��ũ�
��ػ��ֳ�С�飬һЩ��������������������ˮţ�������е�·����ũ���򶫶�
ȥ��
LONG );
	set("objects", ([
	   "/d/dali/npc/nongfu2": 1,
	   "/d/dali/npc/cow": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"   : "/d/dali/luojiadian",
	    "east"   : "/d/dali/nongtian3",
	    "south"  : "/d/dali/langan1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

