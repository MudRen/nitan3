inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������ƽ��һ��ɽ������������һ��խխ��ľ�ź���
���ϣ�ֻ��һ�˾�����
LONG);
        set("exits", ([
                "north" : __DIR__"chaotiangong",
                "south" : __DIR__"toutiangate",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
	set("coor/x", -350);
	set("coor/y", -380);
	set("coor/z", 150);
	setup();
        replace_program(ROOM);
}