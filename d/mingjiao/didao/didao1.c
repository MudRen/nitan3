// Code of ShenZhou
// Room: didao1.c �ص�
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
�����Ǻ������ڵĵص������������ģ�ֻ�м�����Ѳ���ǽ�ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"up": "/d/mingjiao/didao/didao",
		"east": "/d/mingjiao/didao/didao_e",
		"west": "/d/mingjiao/didao/didao_w",
		"north": "/d/mingjiao/didao/didao_n",
		"south": "/d/mingjiao/didao/didao_s",
]));
	
	set("cost", 1);

	setup();
//	replace_program(ROOM);
}
