inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������һ�������ϣ������Ǵ�������һ��¥������
¥�ϴ������������
LONG );
        set("exits", ([
                "northup" : __DIR__"cangjingge",
                "east"    : __DIR__"sanqingdian",
                "westup"  : __DIR__"caolianfang",
        ]));
	set("coor/x", -380);
	set("coor/y", -300);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}