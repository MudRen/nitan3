// Room: /u/zqb/tiezhang/lx.c

inherit ROOM;

void create()
{
	set("short", "��Ϫ");
	set("long", @LONG
������������һ��С����Ȼ�˵صش�ƫƧ��������������������Ȼ��
�ࡣ������һ�乩����Ϣ����С�͵ꡣ���Ϸ���ʮ�ﴦ�����Ǵ˴�������
��צɽ��
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"hunanroad2",
	]));
        set("objects", ([
                CLASS_D("misc") + "/qiuqianren" : 1,
        ]));
	set("coor/x", -310);
	set("coor/y", -170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
