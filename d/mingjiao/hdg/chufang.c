// ���� chufang.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "����");
        set("long", @LONG
����һ����ĳ�����һ��Сͯ����æµ������������������������
�˴������εĲ��㣬�������Сͯ�����ջ����������˰��챾���Ͷ���
���Ӳ��ɵع�������������
LONG );

        set("no_fight", 1);

        set("exits", ([ 
            "north" : __DIR__"huapu4",
            "south" : __DIR__"xfang2",
            "east" : __DIR__"caotang",
        ]));

        set("objects",([
            __DIR__"npc/xtong3" : 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        object *ob = deep_inventory(me);
        int i = sizeof(ob);
        if((dir != "west")){
          while (i--)
          if(ob[i]->id("rice") || ob[i]->id("miantang") || ob[i]->id("qingcai"))
             return notify_fail(CYN"С�׺���һ�����Ա������˻�Ҫ����ѽ��\n"NOR);                
        }
        return ::valid_leave(me, dir);
}
