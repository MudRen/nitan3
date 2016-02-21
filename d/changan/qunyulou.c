//Room: qunyulou.c

#include <ansi.h>

inherit ROOM;

int check_container(object ob);

void create()
{
        set("short", "Ⱥ��¥");
        set("long", 
"Ⱥ��¥�ǳ���������һָ�Ĵ��Ժ�����ﲻ����ͨ�������ĵط�������㲻\n" 
"�Ǹ���һ���Ĳ���������㲻���۰�һ���İ������ţ�����㲻���������壬��\n" 
"���������Ҳ���롣¥�й͵Ĵ��ֱ���������������ţ�������ͷ�����ļ�����\n" 
"��������ƿ���ȥ���������Ÿ�ʾ(gaoshi)һ�ţ��ָ߹�����������\n" 
HIR"             ��"HIG"              ��\n\n"NOR
HIR"             ��"HIG"              ɫ\n\n"NOR
HIR"             ʴ"HIG"              ��\n\n"NOR
HIR"             ��"HIG"              ��\n"NOR  	
        );
        set("exits", ([ /* sizeof() == 2 */
        	"north" : "/d/changan/qixiang4",
        	"south" : "/d/changan/qunyulou1",
        ]));
        set("item_desc", ([
        	"gaoshi": HIY @TEXT
�涨:
���������Դ�������¥��
�����������£��������Ը���
TEXT NOR
        ]) );
        set("objects", ([
        	"/d/changan/npc/dashou" : 4,
        ]) );

        set("NONPC",1);
        set("coor/x", -390);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{    
        object ob;
        object *inv;
        int i;
        if (dir == "south" &&
            objectp(ob = present("da shou", this_object())) &&
            living(ob))
        {
                if (wizardp(me))
                        return ::valid_leave(me, dir);

                if ((string)me->query("gender")=="Ů��")
        	        return notify_fail(ob->name() +
                               "һ��ץס���㣬˵��:�����ﲻ��Ů��"
                               "�����ĵط�������ȥ����\n");
                inv = all_inventory(me);
                for(i = 0; i < sizeof(inv); i++)
                {
                        if ((int)inv[i]->query("weapon_prop"))
        	                return notify_fail(ob->name() +
                                                   "һ��ץס���㣬˵������������������"
                                                   "��صĵط�����׼���������롣��\n");
                }
        }
        return 1;
}
