// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <room.h>

inherit ROOM;
// inherit HARBOR;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
������ɽ��һ����ۣ��������Ҵ�(chuan)���������ż�������
����ˣ��˴��ɶɹ��󺣵��ﴫ˵�е��һ����������Ǽ��˳ǣ�������һ
���޼ʵĴ󺣡�
LONG );
        set("outdoors", "taohua");
        set("exits", ([
                "west" : "/d/jiaxing/nanhu1",
        ]));

        set("item_desc", ([
                "chuan" : "����һ�Һ����������˶ɺ������Ǵ�����ƽʱҲ���������㡣\n",
        ]));

        set("navigate/locx", 0);
        set("navigate/locy", -200);

        set("cost", 2);

        setup();
}

