// Room: /d/playtown/miao.c
// Build 199.12.10 bmw

inherit ROOM;

void create()
{
	set("short", "�ع���");
	set("long",
"�㲽��ع���һ�۱㿴��һ��������Ĺع��񣬰˳߸ߵ�������\n"
"�������ޱȡ����°���Ϊ�˼�����λ���߸����Ĺؽ������ط����м���\n"
"���������˵���԰��顣ֻ���ع���ǰ��һ���㰸�������м�����ȽȽ\n"
"Ʈ�����������ǰ����һ������(putuan)�������и��������������۾���\n"
"���ﲻ֪���ں���ʲô��\n"
);

	set("item_desc",([
		"putuan":"����һ��С���ţ�ר�����¹��á�\n",
	]));
	
	set("exits", ([
		"west"  : __DIR__"road7",
		"east"  : __DIR__"road18",
		"north"  : __DIR__"biwuchang",
		"south"  : __DIR__"liaotianshi",
	]));
	setup();
	replace_program(ROOM);
}
