#include <ansi.h>
#include <room.h>
inherit RIVER;

void create()
{
  	set ("short", "���ݶ�");
  	set ("long", @LONG
����ͨ�����ݳǵĶɿڣ�ǰ����ǹ������� (river)����
�����������۾����������ɴ���������������ͨ�����ݴ��ž�
ֱ�߾������ݸ��ˡ�
LONG);
        set("arrive_room", "/d/zhongzhou/yangzhoudu");
  	set("exits", ([
  		"south" : __DIR__"dukoulu",
	]));
        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

  	set("outdoors", "zhongzhou");
        set("coor/x", -230);
	set("coor/y", 90);
	set("coor/z", 0);
	setup();
        replace_program(RIVER);
}
