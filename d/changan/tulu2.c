// Room:/d/changan/tulu2.c

inherit ROOM;

void create()
{
	set("short", "��·");
        set("long", @LONG
����һ�����������·������̫������һ����į�ĸо���·������ɢɢ��
�ֲ��ż�ƬС��أ�żȻҲ�ܿ��ü�һЩ���̡�����һƬ�Ļļš�
LONG );
	set("exits",  ([  /*  sizeof()  ==  2  */
		"northup"   : "/d/changan/tulu3",
		"southwest" : "/d/changan/tulu1",
                "west" : __DIR__"lzroad",
	]));
	set("outdoors", "changan");
	set("coor/x", -390);
	set("coor/y", 70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
