inherit ROOM;
#include <ansi.h>

void create()
{
        set("short","�ʹ�����");
        set("long", @LONG
������ǻʹ������ţ��ɸߵ������ų����ţ����Ͻ�ɫ��í���������⡣
��������վ�����������������������ͣ�Ĵ����Ź��������ˡ����õ�����ֱ��
��Ρ����ΰ�Ĺų�ǽ�ϣ�ʹ�ó�ǽ�Ϸ����Ͻ��ǡ�����˸������Եø����ҫ�ۡ�
���Ϸ��Ľ�ˮ�ſ��Դ�Խ���Ǻӵ��ﷱ�����찲�Ź㳡��[2;37;0m
LONG );
	set("exits", ([
		"south" : "/d/beijing/qiao",
		"north" : "/d/beijing/hg",
	]));
	set("objects", ([
		"/d/beijing/npc/bing2" : 2,
		"/d/beijing/npc/yuqian1" : 1,
	]));
	set("no_fight", 0);
	set("coor/x", -30);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        object ob;
        if (objectp(ob = present("guan bing", environment(me))) && dir == "north")
                return notify_fail(ob->name() + "������ס������˵�����ʹ��صأ�����Ѱ�����ճ��롣\n\n");
        if (objectp(ob = present("shi wei", environment(me))) && dir == "north")
                return notify_fail(ob->name() + "������ס������˵�����ʹ��صأ�����Ѱ�����ճ��롣\n\n");
        return ::valid_leave(me, dir);
}
