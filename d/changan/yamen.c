//Room: yamen.c

inherit ROOM;

void create ()
{
        set ("short", "���Ŵ���");
        set("long", @LONG
���ǳ����ǵ����Ŵ��ţ�Ҳ�ǳ�������ߵ��������������︺���������
����С�顣������͵��������С�������ǷŻ�ɱ�˵�ǿ���������������ܵ�Ӧ��
�Ĵ�����ǽ������һ�Ÿ�ʾ(gaoshi)
LONG );
        set("item_desc", ([
        	"gaoshi": ""
        ]) );
        set("exits", 
        ([ //sizeof() == 2
        	"south" : "/d/changan/yamen-datang",
        	"north" : "/d/changan/qinglong3",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/yayi" : 4,
        ]));

        set("coor/x", -390);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
