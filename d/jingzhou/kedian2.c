inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ�
���Ĵ�����һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ���������
��¥�µ��ƹ񴦸���Ǯ������˯����
LONG);
	set("exits", ([
		"down" : __DIR__"kedian",
		"enter" : __DIR__"kedian3",
	]));	
	set("coor/x", -450);
	set("coor/y", -190);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

