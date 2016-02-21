// Created by Lonely
// qi changfa �ݳ���

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("�ݳ���", ({ "qi changfa", "qi", "changfa" }));
        set_living_name("qi changfa");
        set("title", "��ʬ���Ŵ���");
        set("nickname", HIR"���˲��õ���"HIC"Ը"HIR"���Ϲ�"NOR);
        set("shen_type", 1);

        set("gender", "����");
        set("age", 45);
        set("long",
                "���ϰ�����Ǳ�����ƣ���ν�����겻���ţ����Ź����ꡣ\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("higgling", 400);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                /*
                __DIR__"obj/bingcansi",    
                __DIR__"obj/xuantie",    
                __DIR__"obj/butian",    
                __DIR__"obj/chiwusha",    
                __DIR__"obj/gongdanmu",    
                __DIR__"obj/hanbing",    
                __DIR__"obj/hantie",    
                __DIR__"obj/heizhenshi",    
                __DIR__"obj/jingangsha",    
                __DIR__"obj/jixuecao",    
                __DIR__"obj/shuims",    
                __DIR__"obj/tiancs",    
                __DIR__"obj/wujins",    
                __DIR__"obj/xiandan",    
                __DIR__"obj/jiuhua",    
                __DIR__"obj/shenliwan",    
                __DIR__"obj/baoming",    
                __DIR__"obj/zjbchan",    
                __DIR__"obj/xisuidan",    
                */
                "/d/item/obj/tanxiangm",
                "/d/item/obj/zitanm",
                "/d/item/obj/hhtanm",
                "/d/item/obj/fenghuangm",
                "/d/item/obj/wangtianm",
                "/d/item/obj/fenghuangm",
                "/d/item/obj/hhtanm",
                "/d/item/obj/hongshongm",
                "/d/item/obj/longyanm",
                "/d/item/obj/mhshongm",
                "/d/item/obj/tanxiangm",
                "/d/item/obj/wangtianm",
                "/d/item/obj/wlshongm",
                "/d/item/obj/zitanm",
                "/d/item/obj/lanbaos",
                "/d/item/obj/hupos",
                "/d/item/obj/huiy",
                "/d/item/obj/jingweis",
                "/d/item/obj/thuangs",
                "/d/item/obj/heilvy",
                "/d/item/obj/ziyawus",
                "/d/item/obj/qicais",
                "/d/item/obj/donglings",
        }));
        
        setup();
        carry_object("/clone/cloth/jinduan")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int recognize_apprentice(object me, string skill) 
{
        if (skill == "higgling") 
                return 1; 
        else return 0;
}
