inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
�������������ǽ��������е�һ��С�ᣬ���߽�С�ᣬֻ�����μ�齣�
��һ�������ƣ�ǽ������һ��ī�񣬱����ݺᣬī�����죬����ɭɭ֮�⡣
���Ϸ���һ�����٣�һ�ܶ��
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"zhulin3",
	]));
        set("objects", ([
                __DIR__"npc/lvzhu" : 1,
        ]));
	set("coor/x", -130);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
