inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�����˿��֮·���ӹŴ���������й��������������о�
�ú��Ļ�������һ����Ҫ��½��ͨ���������ڻ���·�ϣ�·��
��������һЩ��ͩ���������˺��٣�ż���м����������յ���
���������ϴҴ���ȥ��·�����߶��ǻ���������ȥ�ܻ�������
������������ˮ����ǰ�������һ���ӡ�
LONG);
        set("outdoors", "lanzhou");
        set("exits", ([
                "southeast" : __DIR__"nroad3",
                "north"     : __DIR__"river-nan",
        ]));
        set("objects", ([
                "/d/beijing/npc/haoke1" : 1,
        ]));
        set("coor/x", -530);
	set("coor/y", 180);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

