inherit ROOM;

void create()
{
	set("short", "��������");
        set("long", @LONG
������ǿ��������Ĵ������൱�Ŀ����������ܵ�ǽ���������˸�������
���漣����������һ�����Ż���ӣ�����Ц�ݵ����ӣ��Ǿ��ǵ�����ϵĳ購��
�����ˡ����Ե���λ�ֱ�����������ǰ�������������Ͽ���Ʒλ�ƺ����͡�����
��������һ�����ȣ�����ͨ���������������ڡ�
LONG );
	set("exits", ([
		"north" : "/d/beijing/kangfu_zoulang2",
		"south" : "/d/beijing/kangfu_zoulang1",
	]));
	set("objects", ([
		"/d/beijing/npc/kangqinwang" : 1,
		"/d/beijing/npc/zhangkang" : 1,
		"/d/beijing/npc/zhaoqi" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -30);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
