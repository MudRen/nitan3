inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�����˿��֮·���ӹŴ���������й��������������о�
�ú��Ļ�������һ����Ҫ��½��ͨ���������ڻ���·�ϣ�·��
������������ͩ���������˲��Ǻֻܶ࣬��һЩ���������յ�
�����������ϴҴ��߹���ż���������������ڴ���԰��˸�С
̯��������������ԼԼ���Կ������ݳǡ�
LONG);
        set("outdoors", "lanzhou");

        set("exits", ([
                "south"     : __DIR__"nroad1",
                "northwest" : __DIR__"nroad3",
        ]));
        set("objects", ([
                "/d/beijing/npc/youke" : 2,
        ]));
        set("coor/x", -510);
	set("coor/y", 160);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
