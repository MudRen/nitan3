inherit ROOM;

void create()
{
        set("short", "���ͷ�");
        set("long", @LONG
һ���ţ�ֻ�����������ֳֽ䵶��Χ��һ����Ů��ƴ����ɱ��ֻ�Ǹ�����Ů
��������Ʒ��ס�ˣ��۲��������ǰ���Ů��ͷ����ð��˿˿��������Ȼ�Ѿ�
��ȫ������ֻһ���۰���֧����ȥ�������ԵֵС����ϰ߰ߵ�㶼��Ѫ����
LONG );
        set("exits", ([
                "west" : "/d/beijing/kediandayuan",
        ]));
        set("objects", ([
                "/d/beijing/npc/dubi" : 1,
                "/d/beijing/npc/lama" : 6,
        ]));
	set("coor/x", 30);
	set("coor/y", 340);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
