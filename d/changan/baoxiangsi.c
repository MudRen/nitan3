//Room: baoxiangsi.c

inherit ROOM;

void create ()
{
        set ("short", "������");
        set("long", @LONG
�����¹�ģ��󣬷����ǧ����Ժ�������������������ﾡ�Ǹ߸�ʯ�ڣ���
�������Ʋ�һ�ᣬ��Ȼ�ֲ�����ʱ�ĵ�·��������һ�����ʯ���ƺ���������
������ٺٶ�Ц��
LONG );
        set("exits", 
        ([ //sizeof() == 2
        	"north" : "/d/changan/qinglong1",
        	"south" : "/d/changan/baodian",
        ]));
        set("objects", 
        ([ //sizeof() == 2
        	"/d/changan/npc/monk" : 2,
        ]));

        set("coor/x", -410);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
