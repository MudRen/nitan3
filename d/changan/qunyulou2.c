//Room: qunyulou2.c

inherit ROOM;

void create()
{
        set("short", "Ⱥ��¥��¥");
        set("long", @LONG
Ⱥ��¥��¥������һ������ߵ�С¥��������ĳһλ�����ͬ��������֮����
�����ѱ�Ⱥ��¥���ؽ����¡�ֻ��һ������ȭ���������Ů�˵Ľ�Ц����ʱ��
�ӷ����д�����
LONG );
        set("exits", ([ /* sizeof() == 6 */
        	"north" : "/d/changan/qunyuys1",
        	"south" : "/d/changan/qunyuys2",
        	"west"  : "/d/changan/qunyuys3",
        	"east"  : "/d/changan/qunyuys4",
        	"down"  : "/d/changan/qunyulou1",
        	"up"    : "/d/changan/qunyulou3",
        ]));

	set("coor/x", -390);
	set("coor/y", 20);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
