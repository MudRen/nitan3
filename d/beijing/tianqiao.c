#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
��������һ���ź�綫�������ţ��������������У��������ӻ������Ϸ��
�ܽ����������˵Ⱦ۾ӵ����ڡ������Ĵ�����ϱ���ͷ���졣���Ϸ���ֱ������
�Ե��ﱱ���������ʤ��̳��������һ������Ŀյأ�����������ֵĳ����ֹ�
���ˡ������ŵĶ�����������ֱ������˾��ǵ����ڶ��ֺͻ���·��
LONG );
	set("exits", ([
		"south" : "/d/beijing/tiantan_n",
		"north" : "/d/beijing/cagc_s",
		"east" : "/d/beijing/yong_1",
		"west" : "/d/beijing/fu_2",
	]));
	set("objects", ([
                "/d/beijing/npc/maiyi3" : 1,
		"/d/beijing/npc/xianren" : 2,
		"/d/beijing/npc/xiaofan" : 1,
                "/d/beijing/npc/old3" : 1,
		"/d/beijing/npc/boy2" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", 30);
	set("coor/y", 320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

