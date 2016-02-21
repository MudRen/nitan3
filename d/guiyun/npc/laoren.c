// ���ĸ�����
// laoren.c
// By Dumbness, 2003-4-29 13:40

inherit NPC;

int check_legal_name(string arg, int maxlen);

void create()
{
        set_name("��������", ({ "laoren" }));
        set("shen_type", 1);

        set("str", 50);
        set("gender", "����");
        set("age", 35);
        set("long","���ݳ�����������ˣ��������˻۴���ͥ������������ֻ��ϧ��й�����������Ǵ��\n���˴˿��淺�Ͻ𣬸��ײ���������ʹ���쳣��\n");
        set("combat_exp", 1500);
        set("attitude", "friendly");
        set("inquiry", ([
                "����" : "������������ߣ���Ҳ�����������������Ǵ�����޻ƽ��������⿪��ڡ�",
        ]));
        
        setup();
        carry_object("/clone/cloth/cloth")->wear(); 
}

void init()
{
        object ob;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_name","��");
}

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say("��������ʹ��������ţ���ͻȻ�������Ǳ����ǵ��۾���ͻȻ����һ����\n");
                break;
        case 1 :
                say("��������˵����������λ" + RANK_D->query_respect(ob) + 
                        "���������������������\n");
                break;
        }
}

int accept_object(object who, object ob)
{
        
        if (wizardp(who) || ((ob->query("money_id") && ob->value() >= 100000000)) )
        {
                who->set_temp("fee_paid",1);
                tell_object(who, "��������̾��һ����˵�����������£�������Ǵ����ɿ�������ˡ������Ϸ�����ȡ��ʲô���������֡�\n");
                tell_object(who, "����룺�� �µ��������֡�\n");
                return 1;
        }
        else if (ob->query("money_id") && ob->value() < 100000000) 
        {
                tell_object(who, "�������˺ٺ�һЦ��˵��������л��λ" + RANK_D->query_respect(ob) +"���������Ǯ���Ϸ�ʱ���޶࣬\n");
                tell_object(who, "�������֮������Ρ���\n");
                return 1;
        }
        return 0;
}

int do_name(string target)
{
        object me;
        string old_name,old_purename;
        string fname;
        string result;

        me = this_player();
        old_name = me->name(1);
        old_purename = me->query("purename");

        if( !me->query_temp("fee_paid") ) 
                return notify_fail("������������Ŀ�����һ�ۣ�������м�ı��顣\n");

        if( !target ) 
                return notify_fail("���������Ի󲻽��˵��������������µ�����ѽ��\n");

        if( old_purename == target )
                return notify_fail("����������ֵض���˵��������Ǯ�ǲ�������̫�����ˣ�\n");

        if (! check_legal_name(target, 4))
                return 1;
                
        fname = me->query("surname");
        if (! stringp(fname)) fname = "";
        fname += target;

        result = NAME_D->change_name(me, fname, 0);
        if (stringp(result))
        {
                me->add_temp("fake_name", 1);
                if (me->query_temp("fake_name") > 50)
                {
                        me->delete_temp("fake_name");
                        me->delete_temp("fee_paid");
                        write("�������˶�ݺݵĶ����㣺����ǲ�Ϸ����ˡ���");
                        return 1;
                }
                write(result + "\n");
                write("�����¸����ɡ�\n");
                return 1;
        }
        me->set("purename", target);
        CHANNEL_D->do_channel(this_object(),"rumor",old_name + "�����ڿ�ʼ����Ϊ" + me->name(1) + " �ˡ�");
        log_file("static/changename",sprintf("%s(%s)��%s����Ϊ%s��\n",
                                              old_name,
                                              me->query("id"),
                                              log_time(),
                                              me->name(1)));
        me->delete_temp("fake_name");
        me->delete_temp("fee_paid");

        return 1;
}

int check_legal_name(string name, int maxlen)
{
        int i;
        string *banned_name = ({
            "��", "��", "��", "��", "��", "��", 
            "��ʦ","����","����","���","С��","����", "����", "��Ӱ",
            "ϵͳ","����","�ϵ�","����","����","����","�ʵ�",
            "��","�ְ�","����","����","����","��","����","����","����","����","�ϰ�",
            "��","����","����","����","����","��","����","����","����","����",
            "ү","үү","��ү","��ү","��ү","����","��ү",
            "��","��","����","����","����","����",
            "ʺ","��","��","��","��",
        });
        
        i = strlen(name);

        if ((strlen(name) < 2) || (strlen(name) > maxlen))
        {
                write("�Բ������������������̫����̫�̡�\n");
                return 0;
        }

        if (! is_chinese(name))
        {
                write("�Բ��������á����ġ�ȡ���֡�\n");
                return 0;
        }

        if (member_array(name, banned_name) != -1)
        {
                write("�Բ���������������������˵����š�\n");
                return 0;
        }

        return 1;
}

