inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǡ����չ�����Ѻ���˵ĵط������й��߻谵����ζ
���š��������ﾲ���ĵģ��ƺ������ӵ���������������
��ǰ�ᾲ����ࡣ
LONG);
        set("exits", ([
                "east" : __DIR__"men1",
        ]));
        set("objects",([
                "/d/lingjiu/npc/wulaoda" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
