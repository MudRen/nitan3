// yanxiadong.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ϼ��");
        set("long", @LONG
��˵վ��ɽͷ���峿�ۿ�ɽ�����ƴ��̣��������������ϼ����ɫ��������
�ơ���ϼ�������������о����ġ��������͡��������������������ڵ���Ȼ��Ѩ
���и�����ʯ�̡���������ɽ��·��������ȥ������
LONG );
        set("exits", ([
                "west"     : "/d/hangzhou/shanlu5",
                "eastdown" : "/d/hangzhou/shuiledong",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
