#include <ansi.h>
inherit ROOM;

void message_competition(string msg);
void create()
{
        set("short", "��������");
        set("long", @LONG
�˴�ԭ��һ��������Ƶ��ͱڣ���֪�������˴��ͱڵİ���Ӳ�ǿ���һ��ջ
������ջ������һ��ʮ���ɵ�����ʯ����ʯ������һ�ɣ�������һ������ʯ����
���������µĺ��ӡ� 
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                "southdown" : __DIR__"liyubei",
                // "northup" : "/adm/npc/huashanjueding",
                "1" : "/adm/npc/biwu1",
                "2" : "/adm/npc/biwu2",
                "3" : "/adm/npc/biwu3",
                "4" : "/adm/npc/biwu4",
        ]));

        set("outdoors", "huashan" );

        set("no_fight", 1);
        setup();
}

void message_competition(string msg)
{
        CHANNEL_D->do_channel(this_object(), "rumor", msg);
}

int valid_leave(object me, string dir)
{
        int i;
        object *inv;
        int age = (int)me->query("age");

        if (dir == "southdown" || (dir == "northup" && !me->query_condition("killer")))
                return 1;
                
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
        {
                if (me->query_condition("killer"))
                        return notify_fail("ɱ���߲����Խ�����䳡������\n");
                if (! wizardp(me) &&
                    inv[i]->query("weapon_prop/damage") > 100)
                        return notify_fail("������Я����������������䳡������\n");
                if (! wizardp(me) &&
                    inv[i]->query("armor_prop/armor") > 100)
                        return notify_fail("������Я����������������䳡������\n");
        }

        if (wizardp(me)
        ||  (dir == "1" && age < 19) 
        ||  (dir == "2" && (age >= 19 && age < 31)) 
        ||  (dir == "3" && ( age >= 31 && age < 41)) 
        ||  (dir == "4" && age >= 41)) 
        {
                /*
                message_competition((ultrap(me) ? "����ʦ" : "") +
                            me->name(1) + "���뻪ɽ���������ִ��᳡��");
                */
                return 1;
        }
        if (dir == "northup")
        {
                /*
                message_competition((ultrap(me) ? "����ʦ" : "") +
                            me->name(1) + "���뻪ɽ���������ִ��᳡��");
                */
                if (me->query_condition("killer"))
                        return notify_fail("ɱ���߲����Խ�����䳡������\n");
                return 1;
        }
        return notify_fail("�㲻���Ե��Ǳ߱��䣡��\n");
}


