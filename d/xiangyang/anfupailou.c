// Room: /d/xiangyang/anfupailou.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��������¥");
        set("long", @LONG
�����ǰ���ʹ��ǰ��һ����¥���ߴ���ɣ��ɻ����Ƴɣ��Ͷ���Ľ�������
�������������������ҫ�»ư���ӳ����̻Իͣ�����ĿΪ֮ѣ���о�����Ρ��
ׯ�ϡ���̧ͷ��ȥ��������¥���ĸ�����֡�����ʹ��������¥��վ����������
��ǹ���α�����������ÿһ������������ˡ�������ǰ�������Ժ�ˡ��������
����������㳡��
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"south" : "/d/xiangyang/guangchang",
		"north" : "/d/xiangyang/anfugate",
	]));
	set("coor/x", -290);
	set("coor/y", -80);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
