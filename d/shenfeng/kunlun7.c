// Room: /d/gaochang/room63.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
��һ����ľ������ɽʯ��ᾣ��������ǲ��㣬ɽ�ϻ�ѩ���񣬵�·��
᫣��������Ƿ�����ת������ɽ�£�����һ�������֡�����������������
���������֦�½��ᣬһ�����֣�����ɽ����¡�����ɽ�壬��ʱ���ۣ�
�������Ķ��ǡ�
LONG );
	set("no_new_clean_up", 0);
	set("outdoors", "kunlun");
	set("exits", ([ /* sizeof() == 2 */
                "southeast" : __DIR__"kunlun6",
                "northeast" : "/d/kunlun/klshanlu",

        ]));

	setup();
	replace_program(ROOM);
}
