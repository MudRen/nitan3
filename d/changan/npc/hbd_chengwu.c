//hbd_chen.c

#include <ansi.h>

inherit NPC;

#define PLACE "ca"
#define TYPE  "bad"
#define WAIT_TIME 60

mapping bunch_bad = ([ 
        "bunch_name" : "�ڰ׵�",
        "id"   : "hbd",
        "place": "ca",        // �ܻ�
        "boss" : "����",
        "place_name" : "����", // �ֻ�
        "type" : "bad",
]);

void create()
{
        set_name("����", ({ "chen wu", "chen" }));
        set("gender", "����");
        set("age", 28);
        set("long", "������" + bunch_bad["bunch_name"] + "����" + bunch_bad["place_name"] + "�ķ�̳���졣\n");
        set("nickname",HIB"��"HIW"��"HIR"ɲ��"NOR);
        set("title",HIB"��"HIW"��"NOR"����̳��"NOR);
        set("per",22);
        set("combat_exp", 800000);
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
#include <boss_bad.h>
