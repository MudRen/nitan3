inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
���������ݳǵ�һ��С���С��ϱ���һ���ϾƵ꣬��ʱ��
��һ������㡣�������������������Ľ�ͨҪ�������۵�����
������ԭ��Ҫ����������Ը��ص����������������㲻ʱ��
�Կ���һЩ�˴��������������߾�����
LONG);
        set("no_sleep_room",1);
        set("outdoors", "lanzhou");
        set("exits", ([
                "south"  : __DIR__"jioudian",
                "north"  : __DIR__"xidajie1",
        ]));
        set("objects", ([
                "/d/beijing/npc/dipi" : 1,
                "/d/beijing/npc/hunhun" : 1,
        ]));
        set("coor/x", -520);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
