//Room: weapon-shop.c

#include <ansi.h>

inherit ROOM;

void create ()
{
        set ("short", "������");
        set("long", @LONG
�����Ǳ����ꡣ���ﵽ�����������������ۻ����ҡ��������ϰ��Ÿ��ֱ�����
ʮ�˰�������Ӧ�о��У�������ȫ���������ϰ���Ľ�����ҵĴ��ˡ���ǽ�ϻ�д
��һ��ʫ(poem)��
LONG );
        set("exits", 
        ([ //sizeof() == 1
        	"north" : "/d/changan/qixiang6",
        ]));
        set("item_desc", ([
        	"poem": HIR @TEXT
        ��ˮ���������䣬׳ʿһȥ��������
        ƴ����ƾ���߽�������Ψ�и����գ�
TEXT NOR
        ]) );
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/murong-hao" : 1,
        ]));

	set("no_clean_up", 0);
        set("coor/x", -370);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
