inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һƬï�ܵ����֣����ҵ���������б��ɽ���ϡ�ÿ��
�����������ı���ϸ���ߴ�ʮ���ɡ�����֦��Ҷ�ܣ��������
ȫ��ס����������Ե���Щ�谵����ľ֮�䳤�źܶ��ľ�Ӳ�
ʹ���ߺܼ��ѣ���˵�˲ξ���������Щ�Ӳ�֮�С�
LONG);
        set("exits", ([
                "westdown" : __DIR__"milin1",
                "southup"  : __DIR__"milin3",
        ]));
        set("resource/quarry", ([
                "/clone/quarry/hu" :  40,
                "/clone/quarry/hu2" :  3,
                "/clone/quarry/lang" :  50,
                "/clone/quarry/xiong" :  50,
                "/clone/quarry/lu" :  50,
                "/clone/quarry/bao" :  30,
                "/clone/quarry/song" :  50,
        ]));
        set("objects", ([
                // "/clone/quarry/laohu2" : 1,
		"/d/guanwai/npc/dongbeihu": 1,
        ]));
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}
