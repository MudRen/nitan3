//Room: /d/dali/center.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���Ĺ㳡");
        set("long", @LONG
������Ǵ���ǵ����ģ���ɫʯ���̳ɵĴ�����ķ����ӡ��㳡�����Σ�
һȦΧ�Ķ���С�������ˣ��Ϳ����ֵġ�������������Ⱥ��Ҳ�ٲ��˼����ܽ���
֮�ˣ�һЩ����ԭ����δ�ŵ�������һЩ���뽭��֮���˷ܲ��ѡ�
LONG );
	set("objects", ([
	   "/d/dali/npc/jianghuyiren": 1,
                "/clone/npc/walker"  : 1, 
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 4 */
	    "north"  : "/d/dali/taihejiekou",
	    "south"  : "/d/dali/shizilukou",
	    "east"   : "/d/dali/taiheju",
	]));
	setup();
	replace_program(ROOM);
}

