inherit ROOM;

void create()
{
        set("short", "ϷԺ��̨");
        set("long", @LONG
�����ǳ���ϷԺ�ĺ�̨����̨����ȴ��ɨ�úܸɾ�������Ϸ�����ں�̨��
ױ�����������ˣ����ú���ֵ��������㡣
LONG );
        set("exits", ([
                "south" : "/d/beijing/xiyuan",
        ]));
        set("objects", ([
                "/d/beijing/npc/q" : 10,
        ]));

        setup();
        replace_program(ROOM);
}


