#include <room.h>
inherit TRANS_ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����ǳ����ǵ���ǣ����깩Ӧ���ʲ��ϡ��������ڸ�ԣ
�����̼����࣬�������Ƕ�������տ���������ι��������
ϴˢ�ø�Ǭ������һֱ�ź򵽿�����·����������µ���ľ��
�϶��ſ���ľ�� (paizi)������жѷ������Ѳ��ϡ�
LONG);
        set("outdoors", "changan");
        set("no_fight", 1);
        set("no_beg", 1);
        set("no_clean_up", 0);
        set("resource/water", 1);        

        set("objects", ([
                "/clone/horse/zaohongma" : 1,
                "/clone/horse/huangbiaoma" : 1,
                "/clone/horse/ziliuma" : 1,
                "/clone/npc/mafu" : 1,
        ]));

        set("exits",([
                "south" : __DIR__"huarui1",
                "up"    : "/clone/shop/changan_shop",
               "north" : __DIR__"business",
        ]));
        set("coor/x", -430);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(TRANS_ROOM);
}

