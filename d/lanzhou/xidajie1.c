inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ
�Ҵң�����˶���������ȥ��������һ�����ֵĹ㳡���ϱ�Զ
Զ����һ��������¡��С�Ƶ꣬���Ը��ص����ǽ���������
LONG);
        set("outdoors", "lanzhou");
        set("exits", ([
                "east" : __DIR__"guangchang",
                "west" : __DIR__"ximen",
                "south" : __DIR__"xiaojisi",
        ]));
        set("coor/x", -520);
	set("coor/y", 110);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
