//Room: dangpu.c

inherit ROOM;

void create ()
{
        set ("short", "���ǵ���");
        set("long", @LONG
���ǳ�����������һ�ҵ����ˡ�������������ƽ���ơ��ſڹ���һ������
 (paizi)��һ�����߸ߵĹ�̨���������ǰ����̨�������ƹ�ķ��ϰ壬������
�˽�����һ˫�������۾��������´������㡣
LONG );
        set("exits", ([ /* sizeof() == 1 */
        	"north" : "/d/changan/qixiang3",
        ]));
        set("item_desc", ([
                "paizi" : "��ƽ����\n
sell        �� 
buy         ��
pawn        ��
expiate     ��
value       ����
",
        ]));

        set("objects", ([ /* sizeof() == 1 */
        	"/d/changan/npc/wanxi" : 1,
        ]));

        set("no_fight", 1);
        set("coor/x", -410);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
