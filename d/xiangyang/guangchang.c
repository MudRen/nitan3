// Room: /d/xiangyang/guangchang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����㳡");
        set("long", @LONG
����������������㳡��������ʯ���档����ͨ�������ţ�����ͨ��׻��ţ�
����ֱ����ȸ�ţ�ԶԶ����ɿ�����������������ʹ���š��������ɹŴ���Ŵ�
�����������ٸ�Ϊ��ֹ�ɹż�ϸ���ӽ������Ѿ������������ڴ˾ۼ���ֻ��һ��
�ٱ��ڴ�����Ѳ�ߣ��㻹�ǿ��뿪�ɡ�
LONG );
        set("outdoors", "xiangyang");
	set("item_desc", ([
		"dong" : "\n",
	]));

	set("exits", ([
		"east"  : "/d/xiangyang/eastjie1",
		"west"  : "/d/xiangyang/westjie1",
		"south" : "/d/xiangyang/southjie1",
		"north" : "/d/xiangyang/anfupailou",
	]));
	set("objects", ([
		"/d/xiangyang/npc/pian" : 1,
		"/d/xiangyang/npc/bing" : 1,
                "/clone/npc/walker"  : 1, 
	]));
	set("coor/x", -290);
	set("coor/y", -90);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

