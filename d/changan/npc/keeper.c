//keeper.c
//updated by rama

inherit NPC;
#include <ansi.h>

int ask_hbd(object me, object ob);
void create()
{
        set_name("��ף", ({ "keeper" }) );
        set("gender", "����" );
        set("age", 60);
        set("long", "������˿�������ʮ�����ˣ�����ȴ�ܺá�\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("inquiry",([ 
                      "�ڰ׵�" : (: ask_hbd :), 
                 ]) ); 


        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) 
        {
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! ob || ! present(ob, environment(this_object()))) 
                return;

        say("��ף˵������λ" + RANK_D->query_respect(ob) +
            "��������Ǯ�ɡ�\n");
}
int ask_hbd(object me, object ob) 
{ 
     me=this_player(); 
     ob=this_object(); 

     if (me->query("bunch/bunch_name")!="�ڰ׵�" && (int)me->query("shen") <= 0 ) 
     { 
           command("whisper "+me->query("id")+" �ֵ�����������Ǻڰ׵��İɣ��������ɣ�");
           tell_object(me,HIB"��ף�����Ƶ�������棬����һ��С�ţ���˳��С��������ȥ��\n"NOR);
           message("vision", me->name() + "������ף����ææ�����ˡ�\n", 
                              environment(me), ({me}) ); 
           me->move("/d/changan/hbd_cafb");
           return 1; 
     } 
     if (good_bunch(me) || (int)me->query("shen") > 0) 
     { 
           command("say ʩ�����Ҳ����������˼��\n"); 
           return 1; 
     } 

     tell_object(me,"��ף˵��������Ȼ�Ǳ����ֵܣ����������ɣ���\n");
     me->move("/d/changan/hbd_cafb"); 
     return 1; 
} 

