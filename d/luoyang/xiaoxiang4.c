inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
�������ǵ�һ������ʯ������С��ǳ�Ƨ�������¹��꣬·�濴��
�������ɾ��ġ�ǰ����һ��Ƭ��Ϊï�ܵ������֡�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"xiaoxiang3",
  		"north" : __DIR__"zhulin1",
	]));

	set("coor/x", -140);
	set("coor/y", -30);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
