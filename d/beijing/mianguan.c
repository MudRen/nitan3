inherit ROOM;

void create()
{
	set("short", "���");
        set("long", @LONG
�����ǻ���·��ͷ��һ��С��ݣ������ʹ����ˤ����ӵ�����档��ݵ���
��ͻ���������ǵ���ͷ��������Ҳ���ҳ�һ����
LONG );
	set("exits", ([
		"north" : "/d/beijing/fu_1",
	]));
	set("objects", ([
		"/d/beijing/npc/zhanggui":1,
		"/d/beijing/npc/mianhuoji":1,
		"/d/beijing/npc/jiao1":3,
		"/d/beijing/npc/jiao2":1,
	]));
	set("coor/x", 10);
	set("coor/y", 310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
