// Room: /d/suzhou/zhishuang.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ˬ��");
        set("long", @LONG
��ǧ��ʯ���������ˬ�������������ڻ������������棬��ɽ�ϵ����
�㡣����ȡ����ɽˬ������Ϧ������֮�⡣�ɳơ�С��̨�����Ǻ�ӿ�嶥������
ƽ̨�����������Ұ��Զ��Ⱥ�����ƣ������������硺ʨ�ӻ�ͷ������һ����
���＾�ڹ۳�Ⱥ����Ĳ�ӥ��εΪ׳�ۡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : "/d/suzhou/qianrenshi",
	]));
	set("objects", ([
		"/d/suzhou/npc/lady1" :1,
	]));
	set("coor/x", 180);
	set("coor/y", -180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

