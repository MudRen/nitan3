//Room: /d/dali/zoulang1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
����һ�����������ȣ�ͨ��������˵����ҡ����˶�¥��ëձ�Ѿ����ɴ��ף�
����ľ���ϻ���л�����棬�����Щ��ʱ�˵��ֻ���ÿ���߰˲�������һ����
̨���������̴�ͭ�������γ�����֮����һ��
LONG );
	set("exits",([ /* sizeof() == 1 */
	    "down"      : "/d/dali/louti",
	    "west"      : "/d/dali/zoulang2",
	    "east"      : "/d/dali/zoulang3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

