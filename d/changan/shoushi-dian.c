//Room: shoushi-dain.c

inherit ROOM;

void create()
{
        set("short", "���ε�");
        set("long", @LONG
һ�����εꡣ���ε��ڷ���һ���������ӣ������ϰ��м�̴ֻ��ľ�У�����
��ȫ���ŵģ�������ֽ�������������ȫ���������ۻ����ң����ε���ϰ�����
�����
LONG );
        set("exits", ([ /* sizeof() == 1 */
        	"south" : "/d/changan/qixiang5",
        ]));
        set("objects", ([
        	"/d/changan/npc/chen-laoban" : 1,
        ]) );

	set("coor/x", -380);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
