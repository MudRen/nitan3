inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����֮������������Ϊ���󣬶����������������ǳ�����࣬������
�����ġ���ҵ��̵����˶����辶���ڴ˿���һ��������ר���꣬������
����¡����˵����������ɫʱ���е���ɫ��ֻ�Ժ죬�ƣ�����ԭɫΪ����
�ֹ����ƶ��ɣ��ʼ�������
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"east" : __DIR__"nroad1",
	]));
        set("objects", ([
                __DIR__"npc/qin" : 1,
        ]));
	set("coor/x", -180);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
