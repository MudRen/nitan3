// pinghuqiuyue.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ƽ������");
        set("long", @LONG
ƽ������������ˮ�������������ȣ�ֱ�ڲ��ʡ����С������ƽ���ƾ�����
ʱ�º����������������д������ҹʱ��µ��յ�������ɫ���������߱��Ƿ�
��ͤ�����������ǰ׵̡����߾��ǹ�ɽ��
LONG );
        set("exits", ([
            "west"      : "/d/hangzhou/gushan",
            "northwest" : "/d/hangzhou/fangheting",
            "northeast" : "/d/hangzhou/baiti",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
