// Room: northroad3.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
        set("long", @LONG
�����ڱ���ֵ���ʯ���ϣ������������ַǷ���ԭ�������Ǿ��ǽ�ţ��ݣ�
��˵ÿ����ʦ���о����཭�����ﶼĽ��ǰ���������������˲������ơ�
�������Ƕ���֣�һֱ�������Ǳ���֡�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "west"       : "/d/city3/northroad2",
	    "southeast"  : "/d/city3/eastroad1",
	    "northeast"  : "/d/city3/wuguan",
	]));
	set("objects", ([
	    "/d/huashan/npc/haoke" : 2,
	    "/d/taishan/npc/jian-ke" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -420);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
