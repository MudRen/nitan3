// Room: /d/suzhou/yanyutang.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
��������ȫ԰��������ʱϵ԰����ʹ���������Ϊ���ŷ�������ȡ�ڡ�ʫ��
������ʽ���������ö����䡻���˴�����Ϊԧ������״���߳����������ڳ��踻
�����¡�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : "/d/suzhou/shizilin",
		"southeast" : "/d/suzhou/zhenquting",
	]));
	set("objects", ([
		"/d/suzhou/npc/lady3" : 2,
	]));
	set("coor/x", 220);
	set("coor/y", -230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

