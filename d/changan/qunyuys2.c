//Room: qunyuys2.c

inherit ROOM;

void create()
{
        set("short", "Ⱥ��¥����");
        set("long", @LONG
һ�����ҡ����з���һ�Ŵ󴲣����������廨�Ľ�������ͷ������������£�
�������������һ��Ϸˮԧ�죬��ɫ���ã�����������ϵ���һ�����򣬺�
������һ��������һֻ��ױ���ӡ���ǰ���������廨��Ь��һ���еģ�һ��Ů�ģ�
���Ŷ��á�
LONG );
        set("exits", ([ /* sizeof() == 1 */
        	"north" : "/d/changan/qunyulou2",
        ]));
        set("objects", ([
        	"/d/changan/npc/luyi" : 1,
        ]) );

	set("coor/x", -390);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
