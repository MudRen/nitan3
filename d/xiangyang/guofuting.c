// Room: /d/xiangyang/guofuting.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��������");
        set("long", @LONG
�����ǹ����Ŀ��������䲻��ȴ���õ�ͦ���¡������������ķ���������
����÷���������ֻ��ܣ��������ҵ��Ǵ����ﶬ���������е���һ�Ű���������
�϶˷���һ�ײ�ߣ����԰ڷ�������̴���Σ��Եü�Ϊ���ӡ����Ǹ��ڷ���һ��
ĵ�������ƺ����������һ˿ů�⡣������ǽ�����蹩�����ɵĻ���������һ
����������顺���Һ�ɽ����
LONG );
	set("exits", ([
		"south" : "/d/xiangyang/guofuyuan",
		"north" : "/d/xiangyang/guofuhuayuan",
	]));
	set("objects", ([
                "/quest/quest5/guo" : 1,
	]));
	set("coor/x", -300);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

