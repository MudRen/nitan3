// yuanyuantai
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "Ȫ��С��");
        set("long", @LONG
�ƹ���Ȫ����ǰ����һ�����ѵ�����������խխ��ɽ�������ߣ����������
����ľ��ͷ������ӳ�Ļ������Դ���֬��ζ��ʪ����������ɢ���ţ�΢�紵����
�ֲ���ҡ��ʱ��ʱ������������������г���Ƭɽ�ȵ����ľ��š�
LONG );
	set("exits", ([
		"north" : "/d/hangzhou/shandao1",
		"south" : "/d/hangzhou/yuquan",
	]));
	
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
