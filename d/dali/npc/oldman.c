
//updated by rama

inherit NPC;
#include <ansi.h>

int ask_xdh(object me, object ob);

void create()
{
        set_name("��������",({ "old man", "old", "man" }) ); 
        set("gender", "����" );
        set("age", 72);
        set("long", 
"һ���������Ŵ�����ֵ�������������ſڣ�˦�����ĸ����ƴ��������Ҷ�����ŵ�
���������������ǣ���Ҳ������ڡ�\n");
        set_temp("apply/defense", 5);
        set("combat_exp", 700);
        set("shen_type", 1);
        set("per", 13);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        set("inquiry",([  
                "С����" : (: ask_xdh :),  
                               ]) );  
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

int ask_xdh(object me, object ob) 
{ 
     me=this_player(); 
     ob=this_object(); 
     ob=this_object(); 
     if (me->query("bunch/bunch_name")!="С����" && (int)me->query("shen") <= 0 ) 
     { 
           command("whisper "+me->query("id")+" �ֵ������������С����İɣ��������ɣ�");
           tell_object(me,HIB"�������Ŵ��㵽�˺�Ժ���ƿ�һ��ʯ�壬��˳��ʯ��������ȥ��\n"NOR);
           message("vision", me->name() + "���Ű������ż���ææ�����ˡ�\n", 
                              environment(me), ({me}) ); 
           me->move("/d/dali/xdh_dlfb");
           return 1; 
     } 
     if( good_bunch(me) || (int)me->query("shen") > 0 ) 
     { 
           command("say �͹٣��Ҳ����������˼��\n"); 
           return 1; 
     } 

     tell_object(me,"��������˵��������Ȼ�Ǳ����ֵܣ����������ɣ���\n");
     me->move("/d/dali/xdh_dlfb"); 
     return 1; 
} 

