#include <ansi.h>
#include <room.h>
inherit RIVER;

void create()
{
  	set ("short", "���ݶ�");
  	set ("long", @LONG
������ͨ�����ݳǵĶɿڣ���ǰ��Ĺ������� (river)��
�����������۾����������ɴ��������������Ͼ������ݸ�����
��ͣ��ЩС��������һ��С·ͨ�����ݵ����š�
LONG);

        set("arrive_room", "/d/zhongzhou/zhongzhoudu");
  	set("exits", ([
  		"north" : "/d/city/ximen",
                "west" : "/d/city/xiaofang",
	]));
        set("objects", ([
                CLASS_D("misc") + "/shipopo" : 1,
        ]));
        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

  	set("outdoors", "city");
        set("coor/x", -10);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(RIVER);
}
