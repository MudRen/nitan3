// yuanyuantai
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ԲԵ̨");
        set("long", @LONG
ɽ�����Ѷ��ϣ���ǰ������һ�鲻���ƽ�أ����߱���������������������
��ǰʯ��������֪��������Ƭ�յ�ԭ��������ԲԵ̨������νǧ����Եһ��ǣ��
ԲԵ̨������ָԲ������Ե�ĵط����������ܣ�ֻ��������´�������·壬���
���ˣ���ɫ���ˣ����ļ�Ȥ��
LONG );
	set("exits", ([
		"north" : "/d/hangzhou/yuelao-ci",
        "east" : "/d/hangzhou/qixi-tai",
        "south" : "/d/hangzhou/shandao2",
	]));
	set("objects", ([
		"/d/hangzhou/npc/shusheng.c": 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
