inherit ROOM;

void create()
{
        set("short", "�ڵ�");
        set("long", @LONG
�����Ǵ����µ��ڵҲ�������˼��͵ĵط��������µ�
�����ˡ���Ϊ�ɹŹ�ʦ�Ľ��ַ���������һ����ɮ��Ҳ������
��������������ʦ����פ�����º󣬴����·�����Զ����
LONG);
        set("exits", ([
                "east"  : __DIR__"zoulang3",
                "west"  : __DIR__"zoulang4",
                "north" : __DIR__"houdian",
        ]));

        set("objects", ([
                CLASS_D("xueshan") + "/fawang" : 1
        ]));

        setup();
        replace_program(ROOM);
}
