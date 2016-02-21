// Code of ShenZhou
// maze1.c

inherit ROOM;

int do_find(string);

void create()
{
	set("short", "������");
	set("long", @LONG
��������һƬ��ɭɭ��������ǰ��������ȥ����������Ķ�����ľ��
���Ҿ�����������Լ�ɼ���ЩС·��������������ϸ�۲죬��������Ȼ��
��������Թ������а������а��ԣ����Ŷݼף��˵ķ�ͬС�ɣ�ǧ��Ҫ
ðȻ��ȥ��
LONG );
	set("exits", ([
		"south" : __DIR__"maze2.c",
                "north" : __DIR__"shulinwai",
		]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir=="south") {
                if (! userp(me)) return 0;
		me->set_temp("mark/maze��", 1);
		me->set_temp("mark/mazeľ", 1);
		me->set_temp("mark/mazeˮ", 1);
		me->set_temp("mark/maze��", 1);
		me->set_temp("mark/maze��", 1);
		me->set_temp("mazepath", 11111 + random(88889));
	}

	return ::valid_leave(me, dir);
}
