// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
���������ݶķ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ������ķ�����
��������������ů�ͻ��֣������л�����ϵ�֬�۵���������Ǯ�û�������һ��
������ö������������伸��û���κ�һ�������ܱȵ��ϡ���ķ�ʵ���Ǹ�����
�޵ĵط�����ʱ����Ϊ��ʽ�����ݳ޵��ˣ�׼���Ÿ�ʽ�����ݳ޵����ܡ�
LONG );
	set("item_desc", ([
		"paizi" : "��¥�Ĺ��������ڲ��Խ׶Ρ�\n",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/pang" : 1,
	]));
        set("no_fight",0);
	set("exits", ([
		"west" : "/d/city/daxiao",
		"up"   : "/d/city/duchang2",
		"east" : "/d/city/nandajie1",
	]));
	set("coor/x", -10);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
}
