// lingshan.c
// Modified by Dumbness, 2003-5-24 0:57

#include <localtime.h>
#include <ansi.h>;
inherit ROOM;

void create()
{
        mixed *local;
        local = localtime(time());

        set("short", "��ɽ");
        set("long", @LONG
������𲽣����ϸ߲���������ʱ��ѩ����ɽ��һ��ѩ�߸�����һ�������
������ͻȻϮ����ԭ������ʻ�ͦ�����⺮���У�����ѩ���������˴�ɫ�����
�Ǳ����� "��ɽõ��" ��ѩ����ѩ�������������������Ϻ�������ƶ�ı�ɽѩ
���ϣ�ÿ��ʢ�Ŀ�����һֱ���������η��ѩ����ʹ��ѩ���׷��У���Ȼ�°�
�Ű꣬���ͬѩ�����ޣ������뾥ͬ�ݶ����䡣
LONG );
        set("exits", ([
                "down" : "/d/xingxiu/tianchi",
        ]));
        
        if( ( local[LT_MON] >= 4 && local[LT_MON] <= 9 ) && (random(5) == 1) ) 
        {
        
                set("objects", ([
                        DRUG_D("xuelian") : 1,
                ]));
        }

        set("outdoors", "tianshan");
        setup();
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i, flag, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++)
                if ((string)inv[i]->query("id")=="xuelian")
                        j++;

        if( random((int)me->query_skill("dodge")) <= 30
                || ( j > 0 ) )
        {
                me->receive_damage("qi", 100);
                me->receive_wound("qi",  100);
                message_vision(HIR"$Nһ��С�Ľ���һ����... ��...��\n"NOR, me);
                me->move("/d/xingxiu/tianchi");
                tell_object(me, HIR"��ӷ嶥���һ�»���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
                message("vision", HIR"ֻ��" + me->query("name") + "���һ�´ӷ嶥��ֱ������������������ء�\n"NOR, environment(me), me);
                if ( j > 0 )
                        for (i=0; i < sizeof(inv); i++) 
                        {
                                if ( !userp(inv[i]) &&
                                        !inv[i]->query_autoload() && 
                                        !inv[i]->query("armor_prop/armor") ) 
                                {
                                        destruct(inv[i]);
                                        flag += 1;
                                }
                        }
                if ( flag ) tell_object(me, "�����ϵĶ�������ͨ��ͨ��������ء�\n");
        }
        return ::valid_leave(me, dir);
}


