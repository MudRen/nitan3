// jiulou.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "¥��¥");
        set("long", @LONG
����¥��¥����Բ�������˲�֪�������ʽ�����Ǻ���һ�������κ�����
�Ƕ�һ���������ﳢ�������������ֺ��ļ����˸�ʽ�˵ȡ���С��������ȥ��
æ���к����ˡ�ǽ�Ϲ��ż۸�����(paizi)��
LONG );
        set("exits", ([
            "west"      : "/d/hangzhou/road10",
            "east"      :"/d/hangzhou/chufang",
            "up"        : "/d/hangzhou/loveroom",
        ]));
        set("objects", ([
            "/d/hangzhou/npc/xiaoer2" : 1,
        ]));
        set("item_desc", ([
                "paizi" : @LONG
�ٹ��Ͱ�(baozi)               ��ÿ����ʮ��ͭ��
������(pork)                  ��ÿ����������
����Ϻ��(shrimp)              ��ÿ����ʮ��ͭ��
��ƿ(jiuping)                 ��ÿ��ʮ��������
��������(fish)                ��ÿ��һ�������ֶ�ʮ��ͭ��
�л�ͯ��(chicken)             ��ÿֻһ�������ֶ�ʮ��ͭ��
��������(Guihua geng)       ��ÿ��һ�������ֶ�ʮ��ͭ��
LONG ]));
        setup();
        replace_program(ROOM);
}

