inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������ɽ���У���һ��ʯ����Ϫ�����������ǾŶɽ�����
��������֮ˮ���ڴ˽��㾰ɫ���ѡ������������С�Ե꣬��
�����ˣ����СסЪЪ�����������Ͼ��Ƕ��͵�ʮ�����ˡ�
LONG);
        set("exits", ([
                "northup"    : __DIR__"taizipo",
                "southup"    : __DIR__"shibapan",
                "east"       : __DIR__"shop",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", -250);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}