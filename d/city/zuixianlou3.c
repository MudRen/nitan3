// Room: /city/zuixianlou3.c
// YZC 1995/12/04

inherit ROOM;

void create()
{
        set("short", "����¥��¥");
        set("long", @LONG
��������¥��һ�����;��������ޱȣ��Ͷ�¥������ǡ�ɷ��ȣ���ֱ���㲻
�����š�����ԭ���ɾ����������Ҳ����̣��һ����Ϳ����ˮ�ʵ����أ�������
ƨ���ݡ���λС���������׵Ķ����ݽǣ�ɪɪ���������ϻ��в�����Ѫ����
LONG );
        set("objects", ([
                "/d/city/npc/tao1" : 1,
                "/d/city/npc/tao2" : 1,
                "/d/city/npc/tao3" : 1,
                "/d/city/npc/tao4" : 1,
                "/d/city/npc/tao5" : 1,
                "/d/city/npc/tao6" : 1,
        ]));
        set("exits", ([
                "down" : "/d/city/zuixianlou2",
        ]));
//	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 20);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}