
inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����Ĺ�ľ������Щ������ʹ��ֲ���ǰ���ĵ�·��һ��С�ľͱ���
֦�ҵ����ֽţ���ǰ���ֲ�֪ͨ������㲻������������֮�ġ�
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "westup" : __DIR__"kunlun4",
                "northdown" : __DIR__"kunlun2",
                ]));
	set("no_new_clean_up", 0);
	set("outdoors", "kunlun");

	setup();
	replace_program(ROOM);
}
