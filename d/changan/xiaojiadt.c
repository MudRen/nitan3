//Room: xiaojiadt.c

inherit ROOM;

void create()
{
        set("short", "���Ҵ���");
        set("long", @LONG
�����������أ����г���һ������֮�⣬���Ǽ��޼Ҿߣ����ް��裬ֻ��
ǽ�Ϲ���һ���޴�Ĺ��ʻ�������һ����ǣ�ɽ��ˮ�ƣ�����׺��̨ͤ¥��԰
����������ǽ��ϵ�һ�����ǡ�
LONG );
        set("exits", ([ /* sizeof() == 3 */
        	"west" : "/d/changan/xiaojia-qianyuan",
        	"north" : "/d/changan/xiaojia-pianting",
        	"south" : "/d/changan/xiaojia-sleep"
        ]));
        set("objects", ([
        	"/d/changan/npc/yuanwai" : 1,
        ]) );

        set("NONPC",1);
	set("coor/x", -340);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
