// Updated by Lonely


inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
        set_name(HIR"�һ�����"NOR, ({ "dragon" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 200);
        set("long", 
"����һ��ȫ���죬�����֮��Ļ����������������
��ȫ��ɢ���ų��ɫ�Ļ��档\n");
        
        set("str", 248);
        set("con", 252);
        set("dex", 222);

        set("dodge", 999);
        set("force", 999);
        set("unarmed", 999);
        set("parry", 999);
        set("max_qi", 99999);
        set("max_jing", 99999);
        set("max_neili", 901000);
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance_combat", random(30)+10);
        set("chat_msg_combat", ({
                (: big_blowing :)
        }) );

        set("combat_exp", 901100000+random(600110000));
        set("bellicosity", 30000 );
        
        set_temp("apply/attack", 1560+random(400));
        set_temp("apply/damage",1500+random(400));
        set_temp("apply/armor", 1500+random(400));

        setup();
} 
int big_blowing()
{
        remove_call_out("hurting");
        message_vision( HIR "\n\n�һ��������������һ������ȫ��תΪ�ʺ�Ļ�ɫ�����������ʹ��˼�������\n\n" NOR,
                        this_object());
        call_out("hurting", random(1)+1);


        return 1;
}

int hurting()
{
        int i;
        int dam;
        object *inv;
        message_vision( HIR "\n\n�һ������³�һ�ɳ�ɷٽ�Ļ��森����������ƺ�����ȼ���ţ�����\n\n",this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
                dam = random(1000)+1000;
                if(dam <0) dam = 0;
                inv[i]->receive_wound("qi",dam);
                COMBAT_D->report_status(inv[i],1);
        }
        return 1;
}

void die()
{
        object obj, env;
        object killer;
        int exp;
        string userexp;
        int i;
        
        if (! query("have_reborn"))
        {
                set("have_reborn", 1);
                recover();
                return;
        }
                env = environment(this_object());
        if (objectp(killer=this_object()->query_last_damage_from()))
        {
                userexp=killer->query("combat_exp");
                exp=((int)killer->query("literate")*4)+random(10000)+40000+atoi(count_div(userexp,60000));

                if (!killer->query_temp("m_success/����"))
                {
                        killer->set_temp("m_success/����",1);
                        killer->add("combat_exp",exp);
                        killer->add("potential",200000);
                        message("channel:chat", HBMAG"��������硿"+killer->query("name")+"�ɹ���ɱ���˶������⿪�˷�ӡ!�õ����������Ǳ�ܼ���ʯ.\n"NOR,users());
                
                message_vision(MAG "һ���������������ҫ��$N��\n" NOR, killer);
                message_vision(HIR "һ�Ż����͵����ڣ�һ������˵����лл���ǽ⿪�˵��߸���ӡ����Щ��ʯ����Ϊл��ɣ�����\n" NOR, this_object());           
                
                for (i = 0; i < 7; i++)
                {
                        obj = new("/clone/enchase/REDjewel" + (1 + random(3)));
                        obj->move(env, 1);
                        obj = new("/clone/enchase/rune0" + (1 + random(9)));
                        obj->move(env, 1);
                }
                
                message_vision(HIY "�����ȥ����ͻȻ���ֵ����кܶණ�����������⡣\n" NOR, this_object());
                }
        }
                env->set("exits/north", "/d/jyszhuang/mishi2");
        message_vision("$N����һ������ȥ��\n", this_object());
        destruct(this_object());
} 


