inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
���������ݳǵĶ�����ϣ��������������������Ľ�ͨҪ
�������۵���������ԭ��Ҫ����������Ը��ص���������
�������㲻ʱ�����Կ���һЩ������������˴����նӴҴ���
����ȥ�����߾������ݳǵ�����㳡�����Զ��������㳡��
���֣��ϱ���һ��������
LONG);
        set("outdoors", "lanzhou");
        set("exits", ([
                "north" : __DIR__"caisicang",
                "west" : __DIR__"guangchang",
                "east" : __DIR__"dongmen",
        ]));
        set("objects", ([
                "/d/beijing/npc/girl1" : 1,
        ]));
        set("coor/x", -500);
	set("coor/y", 110);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
