// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ�����ƹ�
�����������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ���صĶ�����
̯������һ������(zhaopai)��
LONG );
	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
		"north" : "/d/city/dongdajie1",
		"up"    : "/d/city/garments",
	]));
    set("no_fight",1);
    set("no_steal",1);
	set("objects", ([
		"/d/city/npc/yang": 1,
	]));
	set("coor/x", 10);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
