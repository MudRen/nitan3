inherit ROOM;

void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ��������ֱ����������Ĵ�ٵ�������ݵ���ʮ���ۡ�����
ͨ���Դ������ǣ�������Զ���Ƕ��������ųǵ��ϳ��š�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"nandoor",
  		"south" : __DIR__"guandaos2",
	]));

	set("coor/x", -170);
	set("coor/y", -60);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
