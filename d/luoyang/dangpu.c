inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������������һ�ҵ����ˣ�������������ƽ�ųơ�����������
�����ġ������֣�ʹ��һĿ��Ȼ�������ſں����һ��������ߵĹ�̨��
�������ڵ�һ�е��˸�����ʵʵ���������һ������ (paizi)���������
��Щ��ͷ����ԣ���˳����ĵط���
LONG);
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("exits", ([
  		"down" : __DIR__"cunchu",
  		"east" : __DIR__"sroad1",
	]));
        set("item_desc", ([
                "paizi" : "��ƽ����\n
sell        �� 
buy         ��
redeem      ��
value       ����
",
        ]));
        set("objects", ([
                __DIR__"npc/qi" : 1,
        ]));
	set("coor/x", -180);
	set("coor/y", 20);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
