
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
��ԭ����һ����ɽ�������������������ɽ����ȫ�ǰ�����ѩ��ɽ
������ȴ�����Դ���ľ��һʱ�ڴ�Ŀ�ɣ���ҡ��ۡ�ֻ������С����ౣ�
���б���ײ�������ٲ�����֯��һƬ������
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "north" : __DIR__"huijiang5",
                "west" : __DIR__"lake6",
        ]));
	set("no_new_clean_up", 0);
	set("outdoors", "room46");

	setup();
	replace_program(ROOM);
}
