//keeper.c
//updated by rama

inherit NPC;
#include <ansi.h>

int ask_hbd(object me, object ob);

void create()
{
        set_name("�Ϻ�", ({ "old man", "old", "man" }) );
        set("gender", "����" );
        set("age", 63);
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("attitude", "peaceful");
        set("inquiry",([  
                "�ڰ׵�" : (: ask_hbd :),  
                               ]) );  
        setup();
        carry_object("/d/beijing/npc/obj/cloth")->wear();
}

int ask_hbd(object me, object ob) 
{ 
     me=this_player(); 
     ob=this_object(); 
     ob=this_object(); 
     if (me->query("bunch/bunch_name")!="�ڰ׵�" && (int)me->query("shen") <= 0 ) 
     { 
           command("whisper "+me->query("id")+" �ֵ�����������Ǻڰ׵��İɣ��������ɣ�");
           tell_object(me,HIB"�Ϻ����㵽�˺�Ժ���ƿ�һ��ʯ�壬��˳��ʯ��������ȥ��\n"NOR);
           message("vision", me->name() + "�����Ϻ�����ææ�����ˡ�\n", 
                              environment(me), ({me}) ); 
           me->move("/d/beijing/hbd_bjzb");
           return 1; 
     } 
     if( good_bunch(me) || (int)me->query("shen") > 0 ) 
     { 
           command("say �͹٣��Ҳ����������˼��\n"); 
           return 1; 
     } 

     tell_object(me,"�Ϻ�˵��������Ȼ�Ǳ����ֵܣ����������ɣ���\n");
     me->move("/d/beijing/hbd_bjzb"); 
     return 1; 
} 

