// Room: /d/suzhou/xiyuan.c
// Date: May,31 1998 Java

inherit ROOM;

void create()
{
	set("short","Ϸ԰��");
        set("long", @LONG
����һ�����ݳ��ﶦ��������Ϸ԰��Ϸ԰��������������ī����һӦ��ȫ��
����һ����Ϸ̨��̨�����ڳ��š�����������̨�²�ʱ�ش���Ʊ���ǵĽ�Ծ����
��������Ҳ�̲�ס������������Ϸ������һ�½�ǡ�
LONG );
//	set("no_clean_up", 0);
	set("objects", ([
		"/d/suzhou/npc/piaoyou": 3,
	]));
	set("exits",([ /* sizeof() == 1 */
		"northeast" : "/d/suzhou/beidajie1",
		"north"     : "/d/suzhou/majiu",
	]));
	set("coor/x", 190);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
