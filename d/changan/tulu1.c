// Room:/d/changan/tulu2.c

inherit ROOM;

void create()
{
	set("short", "��·");
        set("long", @LONG
����һ�����������·������̫���ϱ�ԶԶ����ȥ���Կ��õ�Ρ��ĳ���
��ǽ����Ȼ�����볤������Զ�����Ǿ������ܵ����������������ɧ�ţ������
�̲���ïʢ��
LONG );
	set("exits",  ([  /*  sizeof()  ==  2  */
		"northeast": "/d/changan/tulu2",
		"south"    : "/d/changan/bei-chengmen",
	]));
	set("outdoors", "changan");
	set("coor/x", -400);
	set("coor/y", 60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
