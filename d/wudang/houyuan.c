inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ�Ժ������������������һ��Բ�ε��Ŷ�����
��С·ͨ����ɽ��
LONG);
        set("exits", ([
                "south" : __DIR__"xiaolu1",
                "north" : __DIR__"sanqingdian",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/yu" : 1
        ]));
	set("coor/x", -370);
	set("coor/y", -310);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}