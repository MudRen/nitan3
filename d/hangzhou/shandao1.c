// yuanyuantai
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ɽ��");
        set("long", @LONG
����������һ�����ѵ�ɽ���ϣ����߷�ï����ľɢ�������������˵���Ϣ��
Ϫ���ڹ��������ʣ�ˮ��������á�����������ɽ����ɫ����Ӱ���ף���ӳ�ɻ���
LONG );
	set("exits", ([
		"north" : "/d/hangzhou/shandao2",
		"west" : "/d/hangzhou/wenxin-quan",
		"south" : "/d/hangzhou/quanbian-xiaojing",
	]));
	
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
