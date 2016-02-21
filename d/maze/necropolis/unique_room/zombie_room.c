
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", HIC"�ҷظ�"NOR);
        set("long", @LONG
�ҷظڣ�
LONG);
        
        set("maze", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("no_clean_up", 1);
        set("outdoors", "necropolis");
        
        set("objects",([
	        "/d/maze/necropolis/npc/zombie": 5,   
	        "/d/maze/necropolis/npc/zombie_blood": 2,    
	        "/d/maze/necropolis/npc/zombie_power": 2,  
	        "/d/maze/necropolis/npc/zombie_lord": 1,  
        ]));
        setup();
        // replace_program(ROOM);
}
