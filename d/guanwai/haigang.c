inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ���޼ʵĴ󺣣�����������ԼԼ�ܿ�����һ�Ҵ�������������
Լ�������������������������ĳ�ˮ���������ǵ����𵺵�Ψһ��·�ˡ�
LONG);
        set("exits", ([
                "west" : "/d/guanwai/baihe2",
        ]));
        set("objects", ([
                __DIR__"npc/chuanfu2" : 1,
        ]));
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}
