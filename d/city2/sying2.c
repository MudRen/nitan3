#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"������Ӫ"NOR);
        set("long", @LONG
������ǡ����Ρ�������Ӫ��Ӫ�ڵ���ҫ�ۣ��������������εĲ���Ϊ��
�Ը��ɹ��˵��������ϧ���ؽ�Ƹ�뽭�����ֽ�ϰ�������õ�������һƬ
Ƭ�����ض��������˾�̾���ѡ�
LONG
);
        set("train", "infantry");
        set("no_magic", "1");
        set("exits", ([ /* sizeof() == 5 */   
               "east" :   __DIR__"sying1",
        ]));    

        set("objects", ([

        ]));
    
        setup();
        replace_program(ROOM);
}

