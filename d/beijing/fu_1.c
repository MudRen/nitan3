#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����·");
        set("long", @LONG
�����Ǿ��ǵĻ���·�������ӷ����š�ֻҪ����������Ǯ����������ͻ���
��������к����κ��㲻֪�����£����������һ�£�������֪�����˾Ų���ʮ��
�ϱ���һ��СС����ݣ������洫��һ���������
LONG );
	set("exits", ([
		"south" : "/d/beijing/mianguan",
		"east" : "/d/beijing/fu_2",
	]));

	set("outdoors", "beijing");
	set("coor/x", 10);
	set("coor/y", 320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
