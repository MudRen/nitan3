inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�����˿��֮·���ӹŴ���������й��������������о�
�ú��Ļ�������һ����Ҫ��½��ͨ����������һ����������ϣ�
·��������������ͩ�������������ǳ���æ����ʱ����������
�յ��������˴ҴҶ�������౾�����ڴ�����԰���һЩС��
̯�������������������--���ݡ�
LONG);
        set("outdoors", "lanzhou");
        set("exits", ([
                "west"  : __DIR__"road",
                "south" : __DIR__"beimen",
                "north" : __DIR__"nroad2",
        ]));
        set("objects", ([
                "/d/xingxiu/npc/trader" : 1,
                "/clone/npc/walker" : 1,
        ]));
        set("coor/x", -510);
	set("coor/y", 150);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

