// qiantang.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Ǯ������");
        set("long", @LONG
Ǯ������ÿ�����ʮ���ǹ۳��ĺ����ӡ�������ʮ�˳���׳�������ޡ�����
ˮ��ʱ��Զ�������Ὥ�������ģ�����ب��ɽ����������������ɲ�Ǽ䣬����
���ڣ��������꣬�������ţ������ڣ����С�������ת�ۣ����Լݳ��硣����
�����ɽ��˪ѩ�С���׳�����ơ���������ɽ�㵽����������
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/road17",
            "westup"    : "/d/hangzhou/liuheta",
            "east"      : __DIR__"village",            
        ]));
        set("objects", ([
            "/d/hangzhou/npc/jian-ke" : 1,
        ]));
        set("outdoors", "hangzhou");
        setup();
}
