//Room: mianguan.c

inherit ROOM;

void create ()
{
        set ("short", "���");
        set("long", @LONG
��˵�����ʮ����ǰ���������ˣ����Ҳ��۹η����꣬���۹�����ڣ�����
�ݴ�δ��Ϣ��һ�졣���Գ����ҹ���񶼷��ĵúܣ���Ϊ����ؼ����Ų����ţ�
���ٻ����������ŵ���������һ���������ڵ�ţ���档
LONG );
        //set("item_desc", ([" *** " : " *** ", ]));
        set("exits", 
        ([ //sizeof() == 1
        	"south" : "/d/changan/huarui2",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/laozhang" : 1,
        ]));

	set("no_clean_up", 0);
        set("coor/x", -420);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
