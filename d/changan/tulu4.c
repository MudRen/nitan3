// Room:/d/changan/tulu4.c

inherit ROOM;

void create()
{
	set("short", "��·");
        set("long", @LONG
����һ�����������·������̫��·�ϵ�����Ҳ���࣬����ǵش�ƫԶ��
Ե�ʣ�����û��ʲô���̡�
LONG );
	set("exits",  ([  /*  sizeof()  ==  2  */
		"northdown" : "/d/huanghe/yongdeng",
		"southwest" : "/d/changan/tulu3",
	]));
	set("outdoors", "changan");
	set("coor/x", -380);
	set("coor/y", 90);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
