//Room: xiaojiuguan.c

inherit ROOM;

void create ()
{
        set ("short", "С�ƹ�");
        set("long", @LONG
����һ��С�ƹݣ����Ӳ����Ǻܿ�����ˮҲ�ǳ��������������۵ģ�����
ȴ��Ȼ�����������ˣ�Ҳ��֪�����������ȾƵģ�������������λ���ڹ�̨��
����ϰ��
LONG );
        set("exits", 
        ([ //sizeof() == 1
		"north" : "/d/changan/liande-nankou",
        ]));
        set("objects", 
        ([ //sizeof() == 1
		"/d/changan/npc/ruhua" : 1,
        ]));

	set("no_clean_up", 0);
        set("coor/x", -360);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
