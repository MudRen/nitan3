#include <ansi.h>
inherit ROOM;
int is_chat_room()      { return 1;}
void create()
{
       set("short", HIY "��̶��ͷ�" NOR);
        set("long", HIY "\n\n"
"��Ҷ���Ϸ�����������⼰��Ϸ��չ�����������POST�����лл��Һ�����\n\n" NOR);

        set("exits", ([
                "out" : "/d/city/kedian",
                "sea" : "/inherit/room/hanghai_room.c",
                "up"  : "/adm/daemons/huanjing2003/room_door_hj",
        ]));
                set("no_fight", 1);
                set("no_sleep_room",1);
        set("coor/x", 0);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        "/clone/board/advice_b"->foo();

}



