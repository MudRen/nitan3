inherit ROOM;
void create()
{
        set("short", "��ʯ·" );
        set("long", @LONG
����һ������ʯ�̳ɵ�·����Ȼ��Щ������ȴ�ܿ�������
����ȥ���ǳ����ˡ�
LONG);
        set("exits", ([
  		"north" :__DIR__"jznanmen",
  		"south" :__DIR__"nanshilu1",
	]));
        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        set("coor/x", -450);
	set("coor/y", -250);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}

