#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ĺ�Ժ");
        set("long", @LONG
�ĺ�Ժ�Ǳ�����ӵĵ��ͣ�������ͬ�е�����ĺ�Ժ�����Ѿ�����һ�κܳ�
�õ���ʷ�ˡ��ĺ�Ժ�Ĵ����ƾɲ���������ԭ�����ŵ���ɫ���޷����ϣ����ϻ�
����һ�����ƵĶ��ӣ��ּ�ģ�����壬����Ҳ���޷���Щ���������⡻ʲô�ġ�
��տ���ĺ�Ժ�Ĵ��ţ�Ժ�ڵľ�������ֵ��������´������㣬û�»��ǳ���
�뿪�ɡ�
LONG );
       set("exits", ([
		"east" : "/d/beijing/yangliu1",
	]));
	set("objects", ([
		"/d/beijing/npc/jumin1" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -70);
	set("coor/y", 250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

