inherit ROOM;

void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ��������ֱ����������Ĵ�ٵ�������ݵ���ʮ���ۡ�����
ͨ�򺯹ȹؿ��Դ����ݳǣ�������Զ���Ƕ��������ųǵĶ��Ǳ��ˡ�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"westup" : __DIR__"ebridge",
  		"east" : __DIR__"guandaoe2",
	]));

	set("coor/x", -90);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
