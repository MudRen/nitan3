inherit ROOM;

void create()
{
	set("short", "���᷿");
        set("long", @LONG
�����ǿ�����������ߵ�һ���᷿���ǹ��������Ŀ�������ס�ġ��᷿����
���ż��Ŵ󴲣��������ӡ����й�����ͣ�ʹ�˸���˯�⡣
LONG );
	set("exits", ([
		"west" : "/d/beijing/kangfu_zoulang2",
	]));

       set("no_fight",1);
       set("no_steal",1);
       set("sleep_room",1);
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}