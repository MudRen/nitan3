inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǹ��ݳ��������������һ���ưܵ�լ�ӡ�������
һ���ӻ��̣�ר��Ů�˼��õĶ��������˲����Խ�ȥ��
LONG );

	set("exits", ([
                "east"  : __DIR__"shiqiao",
                "north" : __DIR__"laozhai",
                "west"  : __DIR__"zahuopu",
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 130);
	set("coor/y", -130);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
