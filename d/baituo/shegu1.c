// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
#include "room.h"

inherit ROOM;

string look_mist();

void create()
{
        set("short", "�߹�");
        set("long", 
"�߹���ŷ�����������ն���ܾ�����Ϣ���������ߣ�����������˴����ǽ���"
"ŷ�������߹ȵ�Ҫ�壬�޴��������ɽ�ڣ��������Ŵ��˵��߿ڡ���ǰʮ�����ڵ�"
"���ش�ݲ�����");

        set("exits", ([ 
                "south"     : __DIR__"road2",
                "northdown" : __DIR__"shegu2",
        ]));

        set("item_desc", ([
                "mist" : (: look_mist :),
                "��"   : (: look_mist :),
                "����" : (: look_mist :),
        ]));

        set("defense", 1);
        set("outdoors","baituo");
        set("shegu", 1);
        setup();
}

string long()
{
        string msg;

        msg = query("long");
        
        if( query("defense") )
                msg  += 
"����ð���������(mist)�����������ȿڣ������൱���졣ɽ��"
"����Χȴ�Ǳ̲�����ż����Щ����������ڴ˷������ȵ���һ������ȳ�����"
"С����";        
                else 
        msg  += 
"ɽ�ȵ���Χȴ�Ǳ̲�����ż����Щ����������ڴ˷������ȵ�"
"��һ������ȳ�����С����";

        return sort_string(msg, 64, 4);
}

string look_mist()
{
        string desc;
        if( query("defense") ) 
        {
                desc =  RED"һƬѪ��ɫ�����������ϴ���������ð��������֮�У����Ե�ʮ�ֹ��ܡ�\n"NOR;
                if( this_player()->query("family/family_name") == "ŷ������" ) 
                desc += "ŷ������ׯ�ڵ��½����ܽѣ�ŷ���潫�߳��еľ綾�������ڽ��У�\n"
                        "����Ⱥ�ߺ����Ķ�����Ϊ���ϣ��Է���д����߹ȣ������������������صء�\n";
                return desc;
        }
        else return "���������ȿڵĺ���������ȫ��ʧ�ˡ�\n";
}

int valid_leave(object me, string dir)
{
        int i, w;

        if (dir == "northdown") 
        {
                if (me->query_skill("poison",1)<100)
                        return notify_fail("�߹��˾綾֮�أ��������ö��ⶾ֮�����ҽ��룿\n"); 
                if ( !me->query("baituo/shegu_permit") && query("defense")) 
                        return notify_fail("�㿴��������ǰ�ĺ�����΢�߽��������ȳ��˱ǣ��о�����Щ��ѣ��\n�������Ǽ�Ϊ�����Ķ�������ǿ��ͨ����\n");

                if ( me->query("family/family_name") == "ŷ������" 
                && !me->query("baituo/shegu_permit") )
                        return notify_fail("������һ�룬����δ��ׯ��ŷ������ɣ����Ǳ��ô��߹ȵúá�\n");
                if ( me->query("baituo/shegu_permit") && query("defense") )
                        message_vision("$N����춶������߽����߹ȡ�\n", me);
        }
        return ::valid_leave(me,dir);
}

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}
