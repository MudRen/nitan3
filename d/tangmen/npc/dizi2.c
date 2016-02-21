inherit SMITH; 
#include <ansi.h>;

void create()
{
        set_name("�Ʊ���", ({ "tang bingbing", "tang", "bingbing" }) );
        set("title",HIC "���Ű���ר����   ����" NOR);
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��������ר����������С���ӣ��洫�İ���ר����ĸ����ˡ�\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("no_get", "1");
        set("vendor_goods", ({
                "/d/tangmen/obj/fhshi",
                "/d/tangmen/obj/tiejili",
                "/d/tangmen/obj/feidao",
                "/d/tangmen/obj/qinglianzi",
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob; 
       // mapping myfam; 

        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) 
        {
                case 0:
                        say( HIC"�Ʊ���Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "������������\n"NOR);
                        break;
                case 1:
                        say( HIG"�Ʊ������˴��֣�˵������λ" + RANK_D->query_respect(ob)
                                + "�������ʲô����\n"NOR);
                        break;
        }
}

