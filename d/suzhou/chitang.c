// Date: May 31, 98  Java

inherit BUILD_ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
һ�س�ˮӳ�����������С������Ȼˮ�У����۵�ʯ���ϼ������ٻ����
������Կ�����Ϫ¥����¥�����ص�С������ӳ�ڻ�ľɽʯ֮�䡣������ɽ��
�䣬�������������գ������ڡ���ľ����������������㣬������Ƣ�����£�ˮ
��������ʯ���أ��㲻��Ϊ�˾�����̾���ѡ�
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"northeast" : "/d/suzhou/gumujiaohe",
	]));
        set("max_room", 4);
	set("objects", ([
		"/d/suzhou/npc/lady1" : 1,
	]));
	set("coor/x", 160);
	set("coor/y", -250);
	set("coor/z", 0);
	setup();
}

