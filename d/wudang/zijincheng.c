inherit ROOM;

void create()
{
        set("short", "�Ͻ��");
        set("long", @LONG
�����ػ������Ͻ��ǽ���ܳ������ǽ�ɻ���ʯ��ɽ
�����ɣ����������ž����پ��ڣ�����Ϊ����·�ڣ�����׳�ۡ�
LONG);
        set("exits", ([
                "north" : __DIR__"jinding",
                "south" : __DIR__"jindian",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
	set("coor/x", -350);
	set("coor/y", -430);
	set("coor/z", 180);
	setup();
        replace_program(ROOM);
}