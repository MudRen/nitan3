// Room: jiudian.c

inherit ROOM;
void create()
{
	set("short", "�سǾ�¥");
        set("long", @LONG
����һ����������������Ĵ��¥����˵���ϵ���������ȴҲ���ɲ�������
�������Ϲ���һ�������ң���д�š��سǾ�¥���ĸ�������֡�¥�������ξ���
���п������κ��ݣ�ʮ���Ǹ��̴�֡�����һ�Ұ����ϵ꣬�������ڵ���λ�ƹ�
�Ѿ��ǵ��Ĵ�����˵���ᶽ�����е㲻�����ȴҲ����������¥���ս�����
���Ͻ���һ������ͨ��¥������������������Գ�������֡�
LONG );
	set("exits", ([
		"southwest" : "/d/city3/eastroad1",
                "east" : "/d/city3/chufang",
	]));
        set("objects", ([
                "/d/city3/npc/tanghua" : 1,
                "/d/city3/npc/xiaoer2" : 1,
        ]) );
	set("coor/x", -400);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

