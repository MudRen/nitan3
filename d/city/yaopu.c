// Room: /city/yaopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С��
����ɢ�������ġ���ҽƽһָ���ڲ輸�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�һ��
С���վ�ڹ�̨���к��Ź˿͡���̨������һ�ŷ��ƵĹ��(guanggao)��
LONG );
	set("item_desc", ([
		"guanggao" : "�����������ҩƷ��
�ۻƣ�\tʮ������
������ҩ���ϰ����顣\n",
	]));
	set("objects", ([
		"/d/city/npc/ping" : 1,
		"/d/city/npc/huoji" : 1,
	]));
        set("no_fight", 1);    
        set("no_sleep_room", 1);
	set("exits", ([
                 "up" : "/d/city/chanfang",
		"south" : "/d/city/dongdajie2",
	]));
	set("coor/x", 20);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
