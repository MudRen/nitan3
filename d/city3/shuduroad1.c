// Room: shuduroad1.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�񶼴��");
        set("long", @LONG
�������񶼴���������Ϳ��Ե��ᶽ���ˡ������ĳ����������������ȥ
�Ĺٲ�����ɣ���һЩ�ٱ���·��Ѳ�ڡ���е�һ��㺦�£����ڹս�����
����
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "east"  : "/d/city3/eastroad2",
	    "west"  : "/d/city3/guangchang",
            "south" : "/d/city3/fomiao",
	]));
	set("objects", ([
	    "/d/city/npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -420);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
