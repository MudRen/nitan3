//Room: huadian.c

inherit ROOM;

void create ()
{
        set ("short", "����");
        set("long", @LONG
��û���ţ�����Ѿ��ŵ�һ�����µĻ��㡣���и���������������Ŀ������
�������֡����Ͳ��ָߵ͹�����������������Ц����ӭ�������е�С���Ӷ�
ϲ�����������������ѡһЩ�������ʻ��͸����ϵĹ��
LONG );
        set("exits", 
        ([ //sizeof() == 1
                "south" : "/d/changan/huarui3",
        ]));
        set("objects", 
        ([ //sizeof() == 1
                "/d/changan/npc/girl" : 1,
        ]));

        set("coor/x", -410);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
