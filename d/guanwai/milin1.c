// /guanwai/milin1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬï�ܵ����֣����ҵ���������б��ɽ���ϡ�ÿ��������������
����ϸ���ߴ�ʮ���ɡ�����֦��Ҷ�ܣ��������ȫ��ס����������Ե���Щ
�谵����ľ֮�䳤�źܶ��ľ�Ӳݣ�ʹ���ߺܼ��ѣ���˵�˲ξ���������Щ
�Ӳ�֮�С�
LONG );
	set("exits", ([
		"west"    : __DIR__"baihe",
		"eastup"  : __DIR__"milin2",
	]));
        set("resource/quarry", ([
                "/clone/quarry/hu" :  40,
                "/clone/quarry/hu2" :  3,
                "/clone/quarry/lang" :  50,
                "/clone/quarry/xiong" :  50,
                "/clone/quarry/lu" :  50,
                "/clone/quarry/bao" :  30,
                "/clone/quarry/song" :  50,
                "/clone/quarry/diao" :  50,
                "/clone/quarry/jizi" :  50,
                "/clone/quarry/pao" :  50,
                "/clone/quarry/laohu" :  50,
                "/clone/quarry/laohu2" :  50,
        ]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
