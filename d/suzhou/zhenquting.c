// Room: /d/suzhou/zhenquting.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��Ȥͤ");
        set("long", @LONG
ͤ�ڸ߸�����������д�ġ���Ȥ����һ�顣ͤ��װ�ξ��½�̻Ի͡����ܡ�
Χ����ȹ���ϵ�̵��������ͼ��Ω��ΩФ���ڴ˿��Ի���ȫ԰��ɫ��
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : "/d/suzhou/wenmeige",
		"northwest" : "/d/suzhou/yanyutang",
	]));
	set("coor/x", 230);
	set("coor/y", -240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

