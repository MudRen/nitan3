// Room: /city/kedian4.c 
// SMALLFISH 1995/12/04 
 
#include <ansi.h> 
#include <room.h>  

inherit ROOM;

int is_chat_room() { return 1; }  

void create() 
{
        set("short", "������");
        set("long",@LONG
���������ݿ͵긽��Ĳ������ã����������������͵�ס��Ъ�ţ�����ѡ
���ڴ˵㼸������������ɫ��С�ˣ��������ȵĻƾ�С�ü���������ɢ�����ƣ
�ۡ�������δ���ò�ʱ�䣬����ټ������ڿյ����ģ����̺���˵ĵ�С��Ҳ��
֪�㵽��ȥ�ˡ���ǽ����һ�����԰壬������������д���������������µ���
����
LONG );

        set("no_fight", 1);
        set("no_drift", 1);
        set("no_steal", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1); 
        set("exits", ([
                "north"   : "/d/city/kedian",
        ]));
        set("objects", ([
                // "/adm/npc/huangdaxian" : 1,
        ]));

	set("coor/x", 10);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();

}