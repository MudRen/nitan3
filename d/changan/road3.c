// Room:/d/changan/road3.c

inherit  ROOM;

void  create()
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ�򺯹ȹأ�������
ֱ�ﳤ���ǡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" :  "/d/changan/road4",
		"east" :  "/d/changan/zhongnan",
	]));
	set("outdoors", "changan");
	set("coor/x", -330);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
