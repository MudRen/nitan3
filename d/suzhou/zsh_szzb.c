//zsh_szzb.c
#include <ansi.h>

inherit ROOM;

#define PLACE "sz"
#define TYPE  "good"

int sort_by_id(mapping quest1, mapping quest2);

void create()
{
        set("short", MAG"������"NOR);
        set("long", @LONG
����һ�俴��ȥ��Щ�Źֵķ��䣬�����Ŵ�������ɫ������һ������Ī���
�о������ж���һλ׳�����ӣ�����ȥ��һ������ʫ�����ʿ�������ǽ������
һ������(paizi)���������Ա����������ѡ������ȥ��ɡ�
LONG );

        set("objects", ([ 
                __DIR__"npc/boss-song"   : 1,
        ]));

        set("no_fight",1);

        set("exits", ([ 
                "south" : __DIR__"zsh_szdamen",
        ]));

        set("coor/x", 180);
	set("coor/y", -220);
	set("coor/z", 0);
	setup();
}
#include <bang_good.h>

