// /d/xiangyang/outwroad1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ����������ҴҶ�
�����������ͨ�������ǣ�����һ��С·ͨ��һ��ɽ��������һ��С�ӡ�
LONG );
        set("outdoors", "����");

	set("exits", ([
              "southeast" : __DIR__"westgate1",
	]));

	setup();
	replace_program(ROOM);
}

