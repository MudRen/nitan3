// Room: /d/xiangyang/guofuyuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������Ժ");
        set("long", @LONG
�����ǹ����Ĵ�Ժ������һ�¿����İ����ձڣ����顺���ı������ĸ����֣�
������һɫ����ש�̵أ��������˼��ô������м�����������Ժ����ɨ��������
�����Ŀ���,��
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : "/d/xiangyang/guofugate",
		"north" : "/d/xiangyang/guofuting",
	]));
	set("coor/x", -300);
	set("coor/y", -70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

