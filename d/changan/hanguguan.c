//  Room:  /d/city4/hanguguan.c

inherit  ROOM;

void  create  ()
{
	set("short",  "���ȹ�");
	set("long",  @LONG
������ǹź��ȹء���������ɽ���������򣬹����ڹ��С�����ǿ��һ��֮
�أ��ƹض������������Զ�������ɨ���£�������Ϊ����ˣ����ɹ����˿��أ�
��������ʤ֮������������������Ҳ���ڴ�����������¾���ǧ�����£�������
�ж�������
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  "/d/changan/road1",
		"west"  :  "/d/changan/road2",
		"south" :  "/d/xiangyang/caodi3",
	]));
	set("outdoors", "changan");
	set("coor/x", -300);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
