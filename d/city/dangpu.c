// Room: /city/dangpu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
����һ�ҹټҿ��ĵ��̣������Ŷ���Ķĳ��������ŵ��������������ļ�Ժ
����Ժ����Щ��ͷ����Ŀ�Ŀͺ��ο���Ȼ������ĳ����ˡ�һ����߸ߵĹ�̨
���������ǰ������������Ѿ���ģ���ˣ���ϡ�ǡ�ͯ�����ۡ������֡���̨��
���ſ����� (paizi)�������ŵ����ϰ壬һ˫������С�۾��������´������㡣
LONG );
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "��ƽ����\n
sell        �� 
buy         ��
pawn        ��
redeem      ��
value       ����
",
	]));
	set("objects", ([
		"/d/city/npc/tang" : 1,
	]));
	set("exits", ([
		"west" : "/d/city/nandajie1",
	]));

	set("coor/x", 10);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}