//Room: bridge2.c

inherit ROOM;

void create ()
{
        set ("short", "��ˮ��");
        set("long", @LONG
��ˮ����һ��ֱͨ�ʹ��Ĵ�ʯ�ţ������������ۣ�����ù��񹤣���
�ư��磬ʹ������һ�򵱹����Ī�еĸо���������һ���峺���ס����ѵش���
��С�ӣ���ˮ��ʱײ��ʯ�ϣ��������ȵ���ˮ�����ö��������ű�ͨ��ʻʹ���
�����������֡�
LONG );
        set("exits", 
        ([ //sizeof() == 2
		"south" : "/d/changan/qinglong2",
        	"north" : "/d/changan/huanggong",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/yulinjun" : 2,
        	"/d/changan/npc/tongling2" : 1,
        ]));

        set("outdoors", "changan");
        set("coor/x", -400);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
