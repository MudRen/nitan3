// Room: /d/suzhou/nandajie2.c
// Date: May 31, 98  Java

inherit BUILD_ROOM;

void create()
{
	set("short", "�ϴ��");
        set("long", @LONG
������һ�������Ľֵ��ϣ����ϱ���ͷ���졣����ͨ�����ϴ�ֵ����ĵضΣ�
����������������������԰�������棬�����ݳǵ��ϳ��š���ν�������ã�����
�պ������Ե�ȷ�����������������������˼丣�ء�
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"east"  : "/d/suzhou/tingyu",
		"west"  : "/d/suzhou/liuyuan",
		"north" : "/d/suzhou/nandajie1",
		"south" : "/d/suzhou/nanmen",
	]));
        set("max_room", 5);
	set("coor/x", 200);
	set("coor/y", -240);
	set("coor/z", 0);
	setup();
}

