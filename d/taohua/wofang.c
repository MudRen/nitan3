// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�Է�");
        set("long", @LONG
���߽���һ���Է���һ���������޵������˱Ƕ������ٽ��黭������
ǽ�ϡ�����ɴ�֣������⡣С������Ҥ����ƿ�ڵ��һ�����ʢ��������
һ�Ŵ�����ͷ���������Ʊ���
LONG );
        set("exits", ([
                "north" :__DIR__"hyjuchu",
        ]));
        set("objects", ([
                __DIR__"npc/binu" : 2,
        ]) );
        
        setup();
        (CLASS_D("taohua") + "/rong")->come_here();
}

