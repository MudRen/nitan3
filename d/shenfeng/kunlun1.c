
inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
ɽ�������･�����ߣ���Χ�ľ�����Ũ�����������֡�Ũ���е�ˮ��
������͸��������ѣ����������������ܡ��⡭�������˼�ͨ�����õ�
·������ͨ������֮�ţ�
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "westup" : __DIR__"kunlun2",
                "southdown" : __DIR__"conglin2",
        ]));
	set("no_new_clean_up", 0);
	set("outdoors", "kunlun");

	setup();
	replace_program(ROOM);
}
