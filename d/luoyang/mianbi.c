inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��������������ͷ���Щ�����Ͽ�ʱ�����������ĺ��ӵģ������ֺ�
��С�����Һ����ȣ�û���κζ���������վ�Ų��ܰ��κ����ƣ������ӵ�
�������ܷ���С���ӿ�Ҫ�úóԳԿ�ͷ�ˡ�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"south" : __DIR__"sishu",
	]));
        set("objects", ([
        ]));
	set("coor/x", -150);
	set("coor/y", 20);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
