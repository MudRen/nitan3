// /kungfu/class/xueshan/lingzhi.c  ��������
// by secret

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "xueshan.h"

void create()
{
        set_name("��������", ({ "lingzhi shangren", "shangren", "lingzhi" }));
        set("long",@LONG
���������Ǵ������е�λ�ϸߵ����
��һ����ɫ���ģ�ͷ��ɮñ��
LONG
        );
        set("nickname",HIR"����ӡ"NOR);
        set("title",HIY "������" NOR);
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 25);
        set("int", 27);
        set("con", 28);
        set("dex", 26);
        set("max_qi", 2500);
        set("max_jing", 1200);
        set("neili", 2800);
        set("max_neili", 2800);
        set("jiali", 30);
        set("level", 10);
        set("combat_exp", 350000);

        set_skill("mizong-neigong", 60);
        set_skill("literate", 60);
        set_skill("force", 100);
        set_skill("xiaowuxiang", 100);
        set_skill("dodge", 100);
        set_skill("shenkong-xing", 80);
        set_skill("parry", 80);
        set_skill("staff", 60);
        set_skill("xiangmo-chu", 80 );
        set_skill("hand", 80);
        set_skill("dashou-yin", 80);
        set_skill("hammer",50);
        set_skill("riyue-lun",50);
        set_skill("unarmed", 110);
        set_skill("yujiamu-quan", 100);
        set_skill("martial-cognize", 60);
        set_skill("lamaism", 100);


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "yujiamu-quan");
        map_skill("staff", "xiangmo-chu");
        map_skill("hammer", "riyue-lun");
        map_skill("hand", "dashou-yin");

        prepare_skill("hand", "dashou-yin");

        create_family("������", 4, "������");
        set("class", "bonze");

        set("master_ob", 2);
	setup();

        carry_object("/d/xueshan/obj/c-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

        add_money("silver",50);

}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((string)ob->query("gender") != "����")
	{
                command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        if ((string)ob->query("class") != "bonze")
	{
                command("say �ҷ��ŵ����������ࡣ");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        if ((string)ob->query("family/family_name") != "������")
	{
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ȷǱ��µ��ӣ�������ذɣ�");
                return;
                  }

        if ((int)ob->query_skill("lamaism", 1) < 40)
	{
                command("say ���Ҵ����£���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }

        command("say �ʹ���һЩ�书�ɣ�");
        command("recruit " + ob->query("id"));

        ob->set("title", YEL "����" NOR);
}

