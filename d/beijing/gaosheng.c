#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�������");
        set("long", @LONG
һ����ģ��С�Ĳ�ݣ���ǰ��������š��������������֡���ս���������
��һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ���ſ��������˿��ˣ����
��̸Ц����ͷ�Ӷ����販ʿҡͷ���Ե�˵���飬���̵Ļ��æ����ͣ����Ҫ��
���������ƹʺ�ҥ�ԣ������Ǹ������ڡ�
LONG );
       set("exits", ([
		"north" : "/d/beijing/caroad_w2",
	]));
	set("objects", ([
		"/d/beijing/npc/chaboshi" : 1,
		"/d/beijing/npc/teahuoji" : 1,
		"/d/beijing/npc/chake" : 2,
		"/d/beijing/npc/old2" : 1,
	]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}

