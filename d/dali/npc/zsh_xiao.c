//zsh_xiao.c

#include <ansi.h>

inherit NPC;

#define PLACE "dl"     //����ֻ�
#define TYPE  "good"    //�׵�
#define WAIT_TIME 60    //��ɲ�������ķ�ʡʱ��

mapping bunch_good = ([ 
        "bunch_name" : "������",
        "id"   : "zsh",
        "place": "dl",      //�ܻ�
        "boss" : "����Х",
        "place_name" : "����", //�ֻ�
        "type" : "good",
]);

void create()
{
        set_name("����Х", ({ "gongsun xiao", "xiao" }));
        set("gender", "����");
        set("age", 60);
        set("long", "������" + bunch_good["bunch_name"] + "����" + bunch_good["place_name"] + "�ķֻ�᳤��\n");
        set("nickname",HIY"��ʵ���"NOR);
        set("title",GRN"���������ֻ�᳤"NOR);
        set("per",25);
        set("combat_exp", 800000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver",2);
}
#include <boss_good.h>

