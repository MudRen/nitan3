inherit ROOM;

void create()
{
        set("short", "����ͷ");
        set("long", @LONG
����ͷ�����ﳤ����ˡ��κ�¥Ρ��߾��ͷ��¥�ϡ��۽������
���ҾӸ����£�ֱ���󺣡��Գκ�¥����һʯ���𼶶�������󺣣�վ��ʯ
���ն�¥ƽ̨������������һɫ���ޱ��޼ʣ�������ǧ��
LONG );
        set("exits", ([
                "northwest" : __DIR__"shanhaiguan",
                "southwest" : "/d/beijing/road3",
                "north" : "/d/yanmen/gate",
        ]));

        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}

