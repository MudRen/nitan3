// Room: /city/wudao4.c
// Date: Feb.28 1998 by Java

#include <ansi.h>

inherit "/d/city/underlt";

void create()
{
        set("short", "�����");
        set("long", @LONG
���������滷ɽ��ֻ�б����������ڵ�һƺɽ��ƽ�ء�ɽ��ɽ�������λ���
���죬ɽ���µ�ƽ���̲������м�����˸���̨������һ���ȥ���������
�����α����ȫ��������������ı��䳡��������������ı��䳡�������ǳ���
��ı��䳡��
LONG );
        set("outdoors", "city");
        set("exits", ([
                "north"       : "/d/city/ximenroad",
                "west"        : "/d/city/wudao1",
//                "east"        : "/d/city/wudao2",
//                "south"       : "/d/city/wudao3",
        ]));
        set("no_fight", 1);
	set("coor/x", -50);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        "/clone/board/wudao_b"->foo();
        init_here();
        replace_program("/d/city/underlt");
}
