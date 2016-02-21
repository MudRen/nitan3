// Copyright (C) 2003-2004, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit NPC;

mixed ask_gift();

void create()
{
        set_name(HIM "������ʹ" NOR, ({ "gift angel", "liwu tianshi" }));
        set("long", @LONG
������ʹ��������̶�����ڼ����﷢�ŵ���ʹ��
LONG);
        set("gender", "Ů��" );
        set("age", 18);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("combat_exp", 12000000);

        set("inquiry", ([        
                "����" : (: ask_gift :),  
                "gift" : (: ask_gift :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}

mixed ask_gift()
{
        object ob, me = this_player();
        string *lines, file, gift;
        int time1, time2;
        
        file = read_file(CONFIG_DIR + "gift");
        if (! stringp(file)) 
        {
                command("say ��ϧ������û�д��������������أ�");
                return 1;
        }
        
        lines = explode(file, "\n");
        file = lines[sizeof(lines) -1];
        
        if (sscanf(file, "%s %d to %d", gift, time1, time2) != 3)
        {
                command("say ��֣�������ô�����ˣ��ѵ������������֣���");
                return 1;
        }
        
        if ((int)me->query("gifter/" + time1))
        {
                command("say �Ǻǡ���������Ĳ����ˣ����Ѿ������������˰���");
                return 1;
        }
        
        if (time() < time1 || time() > time2)
        {
                command("say �Բ��������Ĳ���ʱ������������������ͷ��ҵģ�");
                return 1;
        }
        
        if (! ob = new(gift)) 
        {
                 command("say ��֣������д����⣬��Ͽ�����񱨸�ɣ�");  
                 return 1;
        } else
        {
                me->set("gifter/" + time1, 1);
                ob->move(me, 1); 
                                      
                message_vision(HIW "$N" HIW "���һָ��ͻȻ�����һ��" HIM "��" HIY "��" HIR "ϼ" HIC "��" HIW "����$n��ת˲���ţ�\n" NOR, 
                               this_object(), me);
                               
                tell_object(me, HIG "�����Ϻ������һ�����gift������쿴����ʲô����ɡ�\n" NOR);
                return 1;
        }
}
