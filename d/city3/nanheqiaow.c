// Room: nanheqiaow.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short","�Ϻ���");
        set("long", @LONG
�����ǳɶ��������Ϻ��š����Ӻ��ϺӼг��������ǻ�������츮֮������
��֮�ء���ˮ���±�͸�������������ţ���������佻�Ϫ�ˡ�
LONG );
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */
            "west"  : "/d/city3/path1",
            "east"  : "/d/city3/westgate",
	]));
	set("no_clean_up", 0);
	set("coor/x", -470);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

