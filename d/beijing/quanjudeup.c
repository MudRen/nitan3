inherit ROOM;

void create()
{
	set("short", "ȫ�۵¾�¥��¥");
        set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������߳Ժȱ���
���ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ����������������������ȫ�۵¿�Ѽ����
վ��¥���������ǣ�ֻ�����Ŀ�������
LONG );
	set("exits", ([
		"down"   : "/d/beijing/quanjude",
	]));
	set("objects", ([
		"/d/beijing/npc/cheng" : 1,
	]));

	set("coor/x", 0);
	set("coor/y", 320);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
