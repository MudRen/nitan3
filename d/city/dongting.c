// Room: /city/dongting.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
���������Ŷ�������֪���д����˵����ڡ����а���һ��ɼľԲ���ͼ�����
�ӣ�������һ�׾��µ����˴�����ǽ�Ϲ���һ�����ã��������ͻ���ɽ������֪
�����ֱʡ�
LONG );
	set("exits", ([
		"west" : "/d/city/ymzhengting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
