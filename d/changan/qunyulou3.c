//Room: qunyulou3.c

inherit ROOM;

void create()
{
        set("short", "Ⱥ��¥��¥");
        set("long", @LONG
Ⱥ��¥��¥������һ������ߵ�С¥��������ĳһλ�����ͬ��������֮����
�����ѱ�Ⱥ��¥���ؽ����¡�ֻ��һ������ȭ���������Ů�˵Ľ�Ц����ʱ��
�ӷ����д�����
LONG );
        set("exits", ([ /* sizeof() == 5 */
        	"north" : "/d/changan/qunyuys5",
        	"south" : "/d/changan/qunyuys6",
        	"west"  : "/d/changan/qunyuys7",
        	"east"  : "/d/changan/qunyuys8",
        	"down"  : "/d/changan/qunyulou2",
        ]));

	set("coor/x", -390);
	set("coor/y", 20);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
