// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit NPC;

int ask_tianmo();

void create()
{
        set_name("����", ({ "gui san", "san", "gui" }));
        set("gender", "����");
        set("age", 65);
        set("long", HIB"���������صĹ�����\n"NOR);
        set("combat_exp", 30000);
        set("shen_type", -1000);
        set("max_neili", 500);
        set("neili", 500);
        set_skill("force", 40);
        set("per",7);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("inquiry", ([
                "��ħ��" : (: ask_tianmo:),
        ]) );
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
int ask_tianmo()
{
        command("say �ٺ�,û�뵽��,��СС�����ȻҲ֪������ħ�������£��ã�ֻҪС�ֵܰ����һ�\n         �ҵĴ��ұ�"HIG"������(hanyu xiao)"CYN"�Ϸ�ʹ���ȥ����ħ��!\n"NOR);
        this_player()->set_temp("search", 1);
        return 1;
}
int accept_object(object me, object obj)
{
        if ( (string)obj->query("id") == "hanyu xiao")  
        {
                command("bow "+me->query("id"));
                command("say �������úúã��Ϸ���ʹ���ȥ�ҡ���ħ������");
                me->set_temp("search",0);
                call_out("create_exit",1); 
                return 1;
        }
}

void create_exit() 
{ 
        object where,ob; 
        ob=this_object(); 
        where = environment(ob); 
        write("��������ǽ�ϵĻ�������Сľ�壬¶��һ�������󶴡�\n\n", ); 
        where->set("exits/enter", "/d/city/didao"); 
} 
