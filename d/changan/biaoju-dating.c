//Room: biaoju-dating.c

inherit ROOM;

void create()
{
        set("short", "�����ھִ���");
        set("long", @LONG
�����еĳ��裬ȫ��ʮ�־��µ���̴ľ�Ҿߣ��������Ⱦ޴�İ�ߡ���磬��
�����˸�ɫ�������ɼ��������İ���ͼ�����Ǻ����Ĺ������һ��Ƥ���Σ�
��������һ����ò���͵ĺ��ӡ�
LONG );
        set("exits", ([
        	"north" : "/d/changan/biaoju-dayuan",
        ]));
        set("objects", ([
                "/quest/job/wang" : 1,
                 "/d/changan/npc/zong-biaotou" : 1,
        ]) );
        set("no_fight",1);

        set("coor/x", -380);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
