// xiongsan.c ���� 

inherit BUNCHER;
inherit F_DEALER;
#include <ansi.h>
mixed ask_back();
void create()
{
        set_name("����", ({ "xiong san", "xiong" }));
        set("title", HIY"�ܼ��±����ϰ�"NOR);
        set("gender", "����");
        set("age", 45);
        set("long",
                "���ϰ��˵�Ǻ��һ�����Щ��ϵ��������������ݿ��˼��±��ꡣ\n");
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/city/npc/obj/yuebing/bj-yuebing",
                "/d/city/npc/obj/yuebing/bp-yuebing",
                "/d/city/npc/obj/yuebing/cy-yuebing",
                "/d/city/npc/obj/yuebing/gs-yuebing",
                "/d/city/npc/obj/yuebing/hw-yuebing",
                "/d/city/npc/obj/yuebing/nl-yuebing",
                "/d/city/npc/obj/yuebing/yn-yuebing",
        }));
        set("inquiry", ([
                "�һ�ʢ��" : (: ask_back :),
        ]));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

mixed ask_back()
{
        object me;

        me = this_player();
        if (me->query("family/family_name") != "�һ���")
        {
                message_vision("$N�Թ��Եĸɻ����û������$n��˵ʲô��\n",
                               this_object(), me);
                return -1;
        }

        message_sort("$N��Ȼ̧��ͷ�����������´�����һ��"
                     "��$n���۽�΢΢һ�������̷������е�"
                     "��ƣ����������һֻ�׵�˵������"
                     "������ֻ�׵���һ����ɡ�\n", 
                     this_object(), me);

        tell_object(me, HIW "�����ϰ׵���˺ܾã�Խ���󺣣���Ȼ��ǰһ����"
                    "���Ѿ��������һ�����\n" NOR);
        me->move("/d/taohua/jingshe");
        return -1;
}
