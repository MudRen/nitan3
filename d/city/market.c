// Room: /city/market.c
// YZC 1995/12/04
#include <ansi.h> 
#include <room.h>
inherit ROOM;

int is_chat_room() { return 1;}

void create(){
	set("short", "����");
	set("long", @LONG
���������ݼ��У��������������������ܶ�С����ϲ�������ﾭ�̣���Ȼ��
���ֶ������������ճ���Ʒ����������Ҳ����һЩ��ϡ֮��������۹�ã�
���Դ����︶��������Ǯ�õ��Լ���Ҫ�Ķ�����
LONG );

        set("outdoors", "city");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room","1");
        set("valid_startroom","1");

        set("objects", ([ 
                "/d/city/npc/qi"     : 1, 
                "/adm/npc/beastseller" : 1,
        ])); 

	set("exits", ([
                "north" : "/d/city/dongdajie3",
	]));
	set("coor/x", 30);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}