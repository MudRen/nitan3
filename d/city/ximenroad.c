// Room: /city/ximenroad.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
    	set("short", "���Ŵ��");
        set("long", @LONG
������������������������ͨ�����ǣ��򶫾��������ˡ��ϱߣ��¿��˸�
�����᳡��ÿ������֮�ڣ��������У��㲻����ȥ��ʶһ�µ���ĳ������
���߾��Ǵ������������������ݷֲ��ˡ�
LONG );
        set("outdoors", "city");
	set("exits", ([
		"east"  : "/d/city/ximen",
                "west"  : "/d/luoyang/guandaoe4",
		"south" : "/d/city/wudao4",
                "north" : "/d/city/xym_yzdamen",
	]));
        set("objects", ([
            "/d/village/npc/boy" : 3,
        ]));
	set("coor/x", -50);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	//object obj;
	if (dir == "south") me->set_temp("view_leitai",1);
        return ::valid_leave(me, dir);
}

