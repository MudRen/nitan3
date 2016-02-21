
#include <ansi.h>

inherit NPC;

#define PLACE "dl"     //����
#define TYPE  "bad"    //�׵�
#define WAIT_TIME 60    //��ɲ�������ķ�ʡʱ��

mapping bunch_bad = ([
        "bunch_name" : "С����",
        "id"   : "xdh",
        "place": "dl",
        "boss" : "����",
        "place_name" : "����",
        "type" : "bad",
]);

void create()
{
        set_name("����", ({ "long wu", "long" }));
        set("gender", "����");
        set("age", 29);
        set("long", "�����Ǳ��صĵ�ͷ����֯" + bunch_bad["bunch_name"] + "��ͷ�ӡ�\n");
        set("nickname",HIY"���׶�"NOR);
        set("title","С�������ֶ�ͷ��");
        set("per",20);
        set("combat_exp", 1000000);
        set("shen_type", -1);

        set("attitude", "peaceful");
        
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver",2);
}

#include "boss_bad.h"

