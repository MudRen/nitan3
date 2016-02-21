// Room: /d/suzhou/baodaiqiao.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
�����ź�������ݵ��˺�֮�ϣ�����������������������Ϊ���š����������
�����������������ű��г����С��ߺ�ȡ������ţ��������������ַǷ�������
�����ڱ̲�֮�ϣ���Ӧ���ԣ�����ཿ���������������µ�һ������֮�ء�
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"northeast" : "/d/suzhou/dongdajie1",
		"northwest" : "/d/suzhou/xidajie1",
		"north"     : "/d/suzhou/canlangting",
		"south"     : "/d/suzhou/nandajie1",
                "west"     : "/d/suzhou/yingbin-lou1.c",
	]));
	set("objects", ([
		"/d/suzhou/npc/seller": 1,
		// "/adm/npc/jiaoshi" : 1,
                "/clone/npc/walker"  : 1, 
	]));
	set("coor/x", 200);
	set("coor/y", -220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

