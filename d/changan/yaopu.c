//Room: yaopu.c

#include <ansi.h>

inherit ROOM;

void create ()
{
        set ("short", "�ش���ҩ��");
        set("long", @LONG
���ǳ�����һ�Ҹոտ��Ų��õ�ҩ�̣��ഫԭ�����ϰ��ǽ����������ص�ҽ
���е���ҽ���ֶο�֪һ����ҩ���еİ���Ҳʮ�ֿ��������α��ڿ�Ļ�Ʋ���
�ɸɾ�����ǽ�Ϲ����˱���������л��(bian)��
LONG );
        set("item_desc", (["bian" : HIW" ���ֻش� \n\n"NOR, ]));
        set("exits", 
        ([ //sizeof() == 1
                "south" : "/d/changan/qixiang6",
        ]));
        set("objects", 
        ([ //sizeof() == 1
                "/d/changan/npc/doctor" : 1,
        ]));

	set("no_clean_up", 0);
        set("coor/x", -370);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
