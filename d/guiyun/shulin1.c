inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����
ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ
��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���
LONG );
        set("outdoors", "guiyun");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"shulin2",
		"northwest" : "/d/city/jiaowai4",
	]));
	set("coor/x", -250);
	set("coor/y", -130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}