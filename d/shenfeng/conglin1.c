
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����������һ����·�����۵�ͨ��һ����ɭ��Ĵ��֣���·��᫿�
����������紵��������ʪ�ĳ�����
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "westup" : __DIR__"conglin2",
                "east" : __DIR__"lake6",
        ]));
	set("no_new_clean_up", 0);
	set("outdoors", "room48");

	setup();
	replace_program(ROOM);
}
