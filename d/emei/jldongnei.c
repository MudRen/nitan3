inherit ROOM;

void create()
{
        set("short", "���϶�");
        set("long", @LONG
����Ƕ��ҵ�һ�󶴣���������ޱȣ������Ѳ⡣��һ��
�������㷢�����в�涴�����Թ�������Ī�⣬�ƺ�����޵ס�
��������������Ȯ����֮�������˾���䣬��������Ⱥӿ����
��Ϩ��档���ǿ���뿪�ɡ�
LONG);
        set("objects", ([
           "/d/emei/npc/poorman" : 2,
           "/d/emei/npc/little_monkey" : 3,
                "/clone/quarry/fu" : 3,
        ]));
        set("exits", ([
                "south" : __DIR__"jiulaodong",
        ]));

        set("coor/x", -520);
	set("coor/y", -240);
	set("coor/z", 130);
	set("coor/x", -520);
	set("coor/y", -240);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}
