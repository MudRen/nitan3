//Room: /d/dali/luojiadian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��٤��");
        set("long", @LONG
�����ǵ�صĶ��ϣ���ôЩ������٤����۾ӵĵط���ôЩ���������ġ���
��ϲ��ƽԭ��ˮ������ˮ��ƽԭ���ӣ���Ϊ���须���������������֣���ȱ��ס�
��٤��һ�����䣬��٤���Ǹ��൱������ӣ�����������������θ���
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northwest"  : "/d/dali/yanchi3",
	    "southwest"  : "/d/dali/yanan1",
	    "east"       : "/d/dali/nongtian2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

