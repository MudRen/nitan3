//Room: /d/dali/tusimentang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
�����Լ�����һЩ������������Ȳ֣����������������ж��׶�����޵�Χ
ǽ�����彨���ǹ�ģ�������������������ϵ�����Ъɽ������ʽ����������
ʮ�ߣ�����ʮ���壬����ʮ�ߡ���¥�������ټ���Сͷ�����ص㣬Ҳ�������ҡ�
LONG );
	set("exits",([ /* sizeof() == 1 */
	    "north"  : "/d/dali/tusihouting",
	    "up"     : "/d/dali/tusiyishi",
	    "out"    : "/d/dali/tusifu",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

