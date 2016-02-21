// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "localtime.h"

inherit ROOM;

string day_event()
{ 
        return NATURE_D->outdoor_room_event();
}

void create()
{
	set("short", "�۳�̨");
      set("long", @LONG
����һ�����е��ƾɵĸ�̨��ǰ����һ���޼ʵĴ󺣡�ԶԶ��ȥ��
���������޲�������һ�ߴ�һ�����߹����������������죬�Ժ������
ӿ��������ɽ�����֮������̨�£����κ��˺ݺݴ���̨���ϡ����ʱ��
�����㲻�ȣ�ҡҡ��׹���������ϱ�ɫ��Ϊ�����֮�����������
LONG );

        set("exits", ([
                "southdown" : __DIR__"beach",
        ]));

	set("outdoors", "taohua");
	set("guanchao", 1);
	setup();
}

string long() 
{
        string msg;

        msg  = "����һ�����е��ƾɵĸ�̨��ǰ����һ���޼ʵĴ󺣡�";

	if (day_event() == "event_dawn" || day_event() == "event_evening")
	{
                msg += "ԶԶ��ȥ�󺣺��������޲�������һ�ߴ�һ�����߹����������������죬�Ժ�";
                msg += "������ӿ��������ɽ�����֮������̨�£����κ��˺ݺݴ���̨���ϡ����ʱ�о�";
	        msg += "���㲻�ȣ�ҡҡ��׹���������ϱ�ɫ��Ϊ�����֮�����������";

	} else 
	{
                msg += "��Ǹ߶�Զ������������һ�̣������޲��������ǡ�����ƾ��Ծ�����";
                msg += "����ɡ������˾���������һ������ֻ���ظ�֮��������ӯ����Ʈ";
                msg += "Ʈ���ƺ���Ҫ�˷��ȥ��";
        }

        return sort_string(msg, 64, 4); 
}
