// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{       
        set("short", "ţ�Ҵ�");
        set("long", @LONG
Ǯ�����ƺƽ�ˮ������ҹҹ�������ݵĴ��ٰ�ţ�Ҵ���ƹ���������
��������һ����ʮ���ڰ�����Ҷ���ƻ��հ�졣��ǰ����Ұ�ݸ���ʼ��
�ƣ������˼��������������������Χ��һ�Ѵ�������ŮŮ��ʮ����С
�������Ծ۾����������һ������������˵�����嶫ͷ����һ���ƾ�����
���ǾƵ�ģ����
LONG );

        set("exits", ([ /* sizeof() == 2 */
                "east" : __DIR__"jiudian",
                "west" : __DIR__"qiantang",  
        ]));

        set("objects", ([
                __DIR__"npc/yang" : 1,
                __DIR__"npc/guo" : 1,
         ]));
         
         set("outdoors", "hangzhou");

         setup();

         replace_program(ROOM);
}
