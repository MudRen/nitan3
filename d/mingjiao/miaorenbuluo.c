//miaorenbuluo.c

inherit ROOM;

void create()
{
        set("short", "���˲���");
        set("long", @LONG
����ǰͻȻһ����ԭ�����߽���һ�����˲��䡣������Χ���ڻ�ѱߣ���ɫ
�ϣ���������ĳ�ּ�����ʽ��������ʿ������ľ�ۣ����������дʡ�ͻȻ����
�Ǻ��������㡣
LONG );
 	set("exits",([
	      "north" : __DIR__"westroad2",
	]));
	set("objects",([
		__DIR__"npc/miaozuwushi":4,	
	]));
	setup();
	replace_program(ROOM);
}
