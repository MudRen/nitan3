// Room: /city/qianzhuang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
Ǯ�ҿ���Ǯׯ������ԭ�����������ֺź�������õ�Ǯׯ�ˣ����м������
��ʷ����ȫ�����ض��зֺš������е���Ʊ�������ã�ͨ�д��ϱ���Ǯׯ����
��һ���˶�ߵĺ�ľ��̨����̨�������һ������ (paizi)������С�۾���Ǯ��
�������ڹ�̨���濴�����ʱ����ƺ���û��ע�⵽�������
LONG );
	set("exits", ([
		"east" : "/d/city/beidajie1",
	]));
	set("item_desc", ([
		"paizi" : @TEXT
     ��Ǯׯ�ṩ���·���
      ��Ǯ        deposit����cun
      ȡǮ        withdraw����qu
      Ǯ�Ҷһ�    convert����duihuan
      ����        check����chazhang
      ת��        transfer����zhuanzhang
TEXT
	]) );

	set("objects", ([
		"/d/city/npc/qian" : 1
	]));
        set("no_fight", 1);
	set("coor/x", -10);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
