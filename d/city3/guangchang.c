// Room: guangchang.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�񶼹㳡");
        set("long", @LONG
�����ǳɶ��ᶽ��ǰ�㳡���ÿտ��ĵط���ֻ��ϡϡ���伸��û����ɵ���
�ˡ���������ᶽ���ˣ��ϱ����ᶽ�֡��㳡��Χ����һȦ���������������԰�
��ʯ�㳡����ɹ�ù���ð�̡�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "east"  : "/d/city3/shuduroad1",
	    "west"  : "/d/city3/shuduroad2",
	    "south" : "/d/city3/tiduroad",
	    "north" : "/d/city3/tidugate",
	]));
//	set("no_clean_up", 0);
	set("objects", ([
	    "/d/city/npc/wujiang" : 2,
                "/clone/npc/walker"  : 1, 
	]));
	set("coor/x", -430);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
