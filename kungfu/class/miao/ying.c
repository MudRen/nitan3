#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����Ӣ", ({ "zhong zhaoying", "zhong", "zhaoying", "ying" }));
        set("long", @LONG
�������������۵��϶�����Ӣ��ֻ��������
ɫ���鲼�·�����ñ��Ь���·�����¶��ëͷ��
���Ǹ����˸�ĸ��Т�ӷ�ɫ����ɫ�Ұף�����
�ֱ��ִ󣬱ǿ׳��죬���źں��ӡ�
LONG );
        set("nickname", HIR "��������" NOR);
        set("title", "���������ֵ�");
        set("gender", "����");
        set("age", 43);
        set("attitude", "peaceful");
        set("str", 23);
        set("int", 27);
        set("con", 25);
        set("dex", 24);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 2600);
        set("max_neili", 2600);
        set("jiali", 80);
        set("combat_exp", 800000);
        set("score", 3000);

        set_skill("force", 140);
        set_skill("mizong-neigong", 140);
        set_skill("dodge", 140);
        set_skill("feiyan-zoubi", 140);
        set_skill("parry", 140);
        set_skill("cuff", 140);
        set_skill("hujia-quan", 140);
        set_skill("staff", 140);
        set_skill("fengmo-zhang", 140);
        set_skill("literate", 100);
        set_skill("martial-cognize", 140);

        map_skill("force", "xueshan-neigong");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("cuff", "hujia-quan");
        map_skill("staff", "fengmo-zhang");
        map_skill("parry", "fengmo-zhang");

        prepare_skill("cuff", "hujia-quan");

        create_family("��������", 6, "����");

        setup();

        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 15);
}

void attempt_apprentice(object ob)
{
        command("hmm");
        command("say �߿����Ҳ���ͽ��");
}

