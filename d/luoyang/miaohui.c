inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�����������ǵ���ᣬֻҪ����������Ǯ����������ͻ��ܵ������
�к����κ��㲻֪�����£������������һ�£�������֪�����˾Ų���ʮ��
����������л��ɣ�����ģ�����ߵģ����յģ���ҩ�ģ���ˣ�ģ���ζ
С�ԣ�Ӧ�о��С�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"wanju",
  		"south" : __DIR__"eroad4",
	]));
        set("objects", ([
                "/d/beijing/npc/xianren" : 2,
        ]));
	set("coor/x", -130);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
