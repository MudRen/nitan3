// suti1.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
�յ���ʫ���ն��������ֿ�������ʱ�ú���Ͳ����ɵġ��ն�������ʫ����
���£�������Ǯ���غ��ˣ����ʿŮ�����ᡣ���ź���캺�ϣ���ɽʼ������ͨ��
������ʮ�����ɣ�����ϯ����̿ա����������Ǵ�����ϱ��ǿ���š��������
�յ������ɱ����ϵĵ�һ������һ�����������ŵ���һ����������
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/road6",
            "south"     : "/d/hangzhou/suti2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
