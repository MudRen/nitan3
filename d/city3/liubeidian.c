// Room: liubeidian.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "������");
        set("long", @LONG
���������������������й��ź����ҵۣ��߿���������ȴû�ù��
��ν "��������" �İ����ɡ�����������ı��������ȵ��ܺ�Ӣ��ͬ�룬���˲�
ʤ���ꡣ
    �������������Ƶȵ��佫�Ⱥͽ���Ϊ�׵��ĳ��ȡ�
LONG );
	set("exits", ([
		"south"   : "/d/city3/wuhoucigate",
		"northup" : "/d/city3/wuhouci",
	]));
	set("no_clean_up", 0);
	set("coor/x", -450);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
