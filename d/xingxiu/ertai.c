// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "��̨");
        set("long", @LONG
�ļ��ľ�ɫ��������һɽ֮�С�ɽ���ϣ���ѩ�����������϶���ɽ�����
�ɴ�أ���ɫŨ�أ�ɽ���ϣ�ɽ����������ֵ���ģ�������ѩ��ֱ��������Ϫ��
���ѩ���ڣ����ⰻȻ����̨�Ա�����һʯ�����˳����˶���
LONG );
	set("exits", ([
                "west" : "/d/xingxiu/guozi",
                "eastdown" : "/d/xingxiu/wuchang3",
		"north" : "/d/xingxiu/xrdong",
        ]));
	set("cost", 2);
     set("fjing", 1);
	set("outdoors", "tianshan");
	set("objects", ([
		"/d/xingxiu/obj/xuesang" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
