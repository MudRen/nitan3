inherit ROOM;
#include <ansi.h>;

void create ()
{
        set("short", "�ĵ�");
        set("long", @LONG
���������ݳǱ������һ����ΪƧ����С·����Ȼ�����
��Զ��ƽʱȴ�����������������·�����Ӳݴ��������ܲ�
��ϱڣ�һ�ɻ����޼ʵķϳǾ���
LONG);
        set("outdoors", "lanzhou");
        set("exits", ([
                "west" : "/d/shenfeng/guandao1",
                "east" : __DIR__"nroad1",
        ]));

        set("coor/x", -520);
	set("coor/y", 150);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

