// Room: /d/xiangyang/kedian.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������ջ");
        set("long", @LONG
����һ�ҶԽ�����ʿ��˵���������Ŀ�ջ�����ǵ�������һ�㶼ס�����
һ�Ǳ��ˣ��������������ϵ�������顣�������������˵���ʮ�Σ�����������
���Ǿ����������Ǵ���������˳��ݷ�һ�¹���������֮ʿ��
LONG );
        set("no_sleep_room",1);
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("valid_startroom", 1);

	set("exits", ([
		"east" : "/d/xiangyang/westroad1",
	]));
	set("objects", ([
		"/d/xiangyang/npc/wudunru" : 1,
	]));
	set("coor/x", -330);
	set("coor/y", -70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
