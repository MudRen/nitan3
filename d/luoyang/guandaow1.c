inherit ROOM;

void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ��������ֱ����������Ĵ�ٵ����������˶���������������
�����ٵ����ǿ�㣬����ݵ���ʮ���ۡ�����ֱ�ﳤ���Ķ��ţ�������
�߲�Զ���Ƕ��������ųǵ����Ǳ��ˡ�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"eastup" : __DIR__"wbridge",
  		"west" : __DIR__"guandaow2",
	]));

	set("coor/x", -250);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
