
inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
��ããɽ����һƬ��ѩ�����²������ˣ�ɽ�ƽ�����ѩ���ú��ģ�
ת������ɽ�꣬ɽ�������վ�����ľ������ɽʯ��ᾣ��������ǲ��㡣
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "eastup" : __DIR__"kunlun4",
                "northwest" : __DIR__"kunlun7",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "kunlun");

	setup();
	replace_program(ROOM);
}
