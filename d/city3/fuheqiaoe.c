// Room: fuheqiaoe.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
        set("long", @LONG
�����ǳɶ������⸮���š��ɶ��Թž��Ǵ����׸������Ӻ��ϺӼгǶ�����
��Ϊ��Ȼ�Ļ��Ǻӡ������Ĵ�����Ͽ��������֮�գ�����������֮�̣��ɶ�ȴ
��֮���������سɹ�֮���������������£�����߳��ˡ�
LONG );
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */
            "east"  : "/d/city3/road2",
            "west"  : "/d/city3/eastgate",
	]));
	set("no_clean_up", 0);
	set("coor/x", -390);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

