inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ԭ�������������������̣������ǵľ���������Ҫ�һ���ȡ��
ʱ����ֱ��������������ԭ����������¡�ģ�����ȴ��һ������ǰ��
��Ϊ������ϰ岻��ô�ĵ����˹ٸ����������������
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"north" : __DIR__"eroad4",
	]));
        set("objects", ([
                "/d/kaifeng/npc/guanbing" : 2,
        ]));
	set("coor/x", -130);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
