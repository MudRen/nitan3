inherit ROOM;

void create()
{
	set("short", "���ӹŵ�");
	set("long", @LONG
���뽭�����ǲ�����ɽ���������Ĺȣ����ղ�����⡣��
��ɽ�ж������޳�û�޳�����·������һ��������ŵ�һ����
���˱Ƕ�����
LONG);
	set("exits", ([
		"northwest" : "/d/henshan/hsroad2",
		"eastup"    : __DIR__"fzroad6",
	]));
        set("objects", ([
                // "/clone/quarry/laohu" : 1,
		"/d/fuzhou/npc/huananhu" : 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 40);
	set("coor/y", -110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

