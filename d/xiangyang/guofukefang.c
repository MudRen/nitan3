// Room: /d/xiangyang/guofukefang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
        set("long", @LONG
�����ǹ��������ǵ�ס�������������һ��ƽ�����ŵ��������߸���һ�Ŵ���
���ϵı��챻�����������롣��ͷ���Եĵط�����һ�����ӣ��Ա߻�����һ����
�ӡ���������ط����ķ��ı����Ա߻����ż����顣���ϰ���һ��ĵ������һ˿
�������Ʒ��С���Ϊ�����ǵ���Ĵ�Ӣ�ۣ����Խ������в��ٺ���ÿ�궼���ݷ�
����
LONG );
	set("no_clean_up", 0);
	set("sleep_room", 1);
	set("exits", ([
		"east" : "/d/xiangyang/guofuhuayuan",
	]));
	set("coor/x", -310);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

