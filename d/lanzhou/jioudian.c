inherit ROOM;

void create()
{
        set("short", "ӭ��Ƶ�");
        set("long", @LONG
��Բ����������������ӭ���¥����˵�����˲�֪������
��������������˶�ӭ���¥�Ļ�����޲����ڡ���վ�ھƵ�
�ڣ����������ص���ζ����������Ʈ����
LONG);
        set("exits", ([
                "north" : __DIR__"xiaojisi",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer3" : 1,
        ]));

        set("coor/x", -520);
	set("coor/y", 90);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
