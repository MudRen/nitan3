inherit ROOM;

void create()
{
	set("short", "��ǹ��");
	set("long", @LONG
����ǹ�����������ʱ������ǹ�����¡���������������
����Ⱥѻ����Ϊ��������˵��ǹ�����ѻ������񽫣�����
�����ַ�������������ֳ��Խ��Խ�ࡣ
LONG);
	set("exits", ([
                "west"  : __DIR__"jxnanmen",
		"north" : __DIR__"nanhu",
        ]));
        set("coor/x", 90);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        set("objects", ([
                "/d/quanzhou/npc/wuya": 4
        ]));
        replace_program(ROOM);
}
