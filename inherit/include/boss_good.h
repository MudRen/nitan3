// boss_good.h

void init()
{
  
        add_action("do_join","join");
        add_action("do_disengage","disengage");
        add_action("do_choose","choose");
        add_action("do_giveup","giveup");
}

int do_join()
{
        string msg, bname;
        object me, ob;
       
        me = this_player();
        ob = this_object();

        if (me->is_busy())
                return notify_fail("����æ���ء�\n");

        if (good_bunch(me))
        {
                bname = me->query("bunch/bunch_name");
                if (bname == bunch_good["bunch_name"])
                {
                        if (me->query("shen") < 0)
                        {
                                message_vision("$N����$n��Ȼ��ŭ�������޼��ﶼ������֮ʿ�������ݵ���������а��֮ͽ��\n", ob, me);
                                me->delete("bunch");
                                me->set("last_leave_bunch",time());
                                msg = "��˵" + me->name(1) + "��" + ob->name(1) + "�����" + bname;
                                CHANNEL_D->do_channel(this_object(), "rumor", msg);
                                return notify_fail("�㱻" + ob->name() + "��������" + bname + "��\n");
                        }
                        return notify_fail("���Ѿ�����" + bname + "�ĳ�Ա�ˣ���ͷ�ˣ�\n");
                }
                return notify_fail("��������" + bname + "�ĳ�Ա��Ҫ������" + bunch_good["bunch_name"] + "����������(disengage)ԭ���İ�ᡣ\n");
        }
       
        if (bad_bunch(me) || me->query("shen") < 0)
        {
                message_vision("$N�������µ���ϸ������$n����ɫԽ��Խ�ѿ���\n", ob, me);
                command("say " + "����" + bunch_good["bunch_name"] + "��������֮ʿ�������ݵ���������а��֮ͽ��");
                return notify_fail("����" + ob->name() + "������ӭ�㣡\n");
        }

        if (count_lt(me->query("combat_exp"), 100000))
        {
                command("joke " + me->query("id"));
                command("say ��λ" + RANK_D->query_respect(me) + "�������ն����������������֣������ʺϴ�������");
                return notify_fail("����" + ob->name() + "�����������̫���˵㡣\n");
        }

        if (count_ge(me->query("combat_exp"), 2000000))
        {
                command("joke " + me->query("id"));
                command("say ��λ" + RANK_D->query_respect(me) + "���������Ѿ��ܲ���Ӧ�ð�־��ŵĸ���ԶһЩ�ˡ�");
                return notify_fail("����" + ob->name() + "����������̫���ˡ�\n");
        }

        if (time() - (int)me->query("last_leave_bunch") < 120)
                return notify_fail(ob->name() + "������˵����˵���Ǹ������˱�İ������İɣ��ҵ��ٹ۲�۲��㣬�������������ɣ�\n");

        me->set("bunch", bunch_good);
        me->delete("last_leave_bunch");
        message_vision("$N��ϥ���£�����$n���������ĺ�������������\n", me, ob);
        message_vision("$N΢΢һЦ������$n���˵�ͷ��������$nվ��������\n", ob, me);
        tell_object(me, "��ϲ���Ϊ" + bunch_good["bunch_name"] + "��һԱ��\n");
        msg = "��˵" + me->name(1) + "������" + bunch_good["bunch_name"]+"��";
        CHANNEL_D->do_channel(this_object(), "rumor", msg);
        return 1;
}

int do_disengage()
{
        string msg;
        object me, ob;
       
        me = this_player();
        ob = this_object();

        if (me->is_busy())
                return notify_fail("����æ���ء�\n");

        if (! good_bunch(me) || me->query("bunch/bunch_name") != bunch_good["bunch_name"])
        {
                command("yi " + me->query("id"));
                command("say ��λ" + RANK_D->query_respect(me) + "���㲢����" + bunch_good["bunch_name"] + "�ĳ�Ա����");
                return notify_fail("����" + ob->name() + "��������ͷ��ˮ��\n");
        }

        if (me->query("bunch/boss") != bunch_good["boss"])
                return notify_fail("��������"+bunch_good["bunch_name"]+"������Ľ�����" + me->query("bunch/boss") + "ȥ�ɡ�\n");

        me->delete("bunch");
        me->set("last_leave_bunch", time());

        if (me->query("shen") < 0)
        {
                message_vision("$N����$n��Ȼ��ŭ������ô��ô���������Ұ���û�����������ֵܣ�\n",ob,me);
                tell_object(me,"�㱻" + ob->name() + "��������" + bunch_good["bunch_name"] + "��\n");
                msg = "��˵" + me->name(1) + "��" + ob->name(1) + "�����" + bunch_good["bunch_name"]+"��";
                CHANNEL_D->do_channel(this_object(), "rumor", msg);
        } else
        {
                message_vision("$N����$n̾�������Ǻðգ����Լ����أ�\n",ob,me);
                tell_object(me,"���������" + bunch_good["bunch_name"] + "��\n");
        }
        return 1;
}

int do_choose(string bh)
{
        string msg;
        mapping bunch_quest;
        object me, obj, ob;

        me = this_player();
        obj = this_object();

        if (me->is_busy())
                return notify_fail("����æ���ء�\n");

       //����Ǻڵ��ģ��͸���
        if (bad_bunch(me))
        {
                message_vision("$N�������µ���ϸ������$n����ɫԽ��Խ�ѿ���\n", obj, me);
                command("say " + "����" + bunch_good["bunch_name"] + "��������֮ʿ�������ݵ���������а��֮ͽ��");
                return notify_fail("����" + obj->name() + "������ӭ�㣡\n");
        }

        //������Ǳ����ģ�������ȡ����
        if (! good_bunch(me) || me->query("bunch/bunch_name") != bunch_good["bunch_name"])
        {
                command("yi " + me->query("id"));
                command("say ��λ" + RANK_D->query_respect(me) + "���㲢����" + bunch_good["bunch_name"] + "�ĳ�Ա����");
                return notify_fail("����" + obj->name() + "��������ͷ��ˮ��\n");
        }


        //����Ǳ���ᣬ���Ǳ����-����ô����Ǳ�����¼�ĳ�Ա�����俪�������򣬽������
        if (me->query("shen") < 0)
        {
                message_vision("$N����$n��Ȼ��ŭ������ô��ô���������Ұ���û�����������ֵܣ�\n",obj,me);
                if (me->query("bunch/boss") == bunch_good["boss"])
                {
                        message_vision("$N����$nŭ�ȵ�����������" + bunch_good["bunch_name"] + "��ǽ���Ц����\n",obj,me);
                        me->delete("bunch_quest");
                        me->delete("bunch");
                        me->set("last_leave_bunch",time());
                        msg = "��˵" + me->name(1) + "��" + obj->name(1) + "�����" + bunch_good["bunch_name"];
                        CHANNEL_D->do_channel(this_object(), "rumor", msg);
                        return notify_fail("�㱻" + obj->name() + "��������" + bunch_good["bunch_name"] + "��\n");
                } else
                {
                        message_vision("$N����$nŭ�ȣ��������ҿ����\n",obj,me);
                        return notify_fail("��û�д�" + obj->name() + "������ȡ���κ����񣬷�������һ�ٳ��\n");
                }
        }

        //����Ѿ�������������ʹ��һ��
        if (me->query("bunch_quest"))
                return notify_fail(obj->name() + "�����Ŀ�����˵����ղ��������û����ɣ���ʲô��\n");

        if (count_ge(me->query("combat_exp"), 2000000))
        {
                command("joke " + me->query("id"));
                command("say ��λ" + RANK_D->query_respect(me) + "����������ô���ˣ�����ô������˼����������С���顣");
                return notify_fail("����" + obj->name() + "������ȼ�̫���ˡ�\n");
        }

        //���û�������ţ�����ʾָ��
        if (! bh)
               return notify_fail(obj->name() + "��ֵĿ����㣬������ȡʲô����ָ���ǣ�choose <���>��\n");
 
        //�����׷ɱ��������Ҫ��ȡ����
        if (bh[0..1] == "zs")
                return notify_fail(obj->name() + "΢΢һЦ����Ȼ��׷ɱ�������ȡ���񣿸Ͻ�ȥ��ɰɣ�\n");

        //�����Ѳ�ǣ�������Ƿ����ı��ذ��
        if (bh == "xc" && me->query("bunch/place") != bunch_good["place"])
                return notify_fail(obj->name() + "������˰���˵��Ѳ���������飬�ұ��ǵ��ֵܾͿ���ʤ�Σ����������ˣ�\n");

        //������NPC��BUSY���򲻸�����
        if (obj->is_busy())
                return notify_fail(obj->name() + "��æ���أ�����΢��һ�¡�\n");

        //��������Ҹշ�����������Ҫ�ȴ�
       if (time() - (int)me->query("last_bunch_quest") < (int)me->query("need_wait_time"))
                return notify_fail("��ɲ��������Ⱥú÷�ʡһ�£�Ȼ��������ȡ����\n");

        me->start_busy(1);

        //���ñ�ŵ������Ƿ����
        bunch_quest = PARTY_QUEST_D->query_city_quest(PLACE, TYPE, bh);

        if (! bunch_quest)
                return notify_fail(obj->name() + "�������ӿ��˿�������˵��Ŀǰû��" + bh + "�������\n");

        //�����Ѳ���������鵱���Ƿ��Ѿ�������Ѳ��
        if (bunch_quest["id"] == "xc" && ! bunch_quest["enable"])
                return notify_fail(obj->name() + "΢΢Ц��˵�������Ѿ����ֵ�ȥѲ���ˣ���͵ȸ���ɣ�\n");

        //�����񣬲��ҽ���������б���ɾ�� 
        obj->start_busy(1);
        PARTY_QUEST_D->delete_city_quest(PLACE,TYPE,bh);
        me->set("bunch_quest",bunch_quest);
        message_vision("$N����$n���˵�ͷ����ô�������ͽ������ˣ��ú�ȥ�ɣ�\n",obj,me);
        if (bunch_quest["id"] == "xc")
        {
                ob = new("/d/city/npc/obj/yaopai");
                ob->move(me);
                message_vision("$N��һ��" + ob->name() + "�ݸ���$n��\n",obj,me);

        }
        tell_object(me,"��ӵ������ǣ�\n" + bunch_quest["msg"] + "\n");
        return 1;
}

int do_giveup()
{
        string msg;
        object me, obj;

        me = this_player();
        obj = this_object();

        if (me->is_busy())
                return notify_fail("����æ���ء�\n");

        if (bad_bunch(me))
        {
                message_vision("$N�������µ���ϸ������$n����ɫԽ��Խ�ѿ���\n",obj,me);
                command("say " + "������а����ʿ�ĵ�����������ʲô�����Ҳ��ӣ�");
                return notify_fail("����" + obj->name() + "������ӭ�㣡\n");
        }

       //������Ǳ����ģ������
       if (! good_bunch(me) || me->query("bunch/bunch_name") != bunch_good["bunch_name"])
       {
               command("yi " + me->query("id"));
               command("say ��λ" + RANK_D->query_respect(me) + "���㲢����" + bunch_good["bunch_name"] + "�ĳ�Ա����");
               return notify_fail("����" + obj->name() + "��������ͷ��ˮ��\n");
       }

       //����Ǳ���ᣬ���Ǳ����-����ô����Ǳ�����¼�ĳ�Ա�����俪�������򣬽������
       if (me->query("shen") < 0)
       {
               message_vision("$N����$n��Ȼ��ŭ������ô��ô���������Ұ���û�����������ֵܣ�\n",obj,me);
               if (me->query("bunch/boss") == bunch_good["boss"])
               {
                       message_vision("$N����$nŭ�ȵ�����������" + bunch_good["bunch_name"] + "��ǽ���Ц����\n",obj,me);
                       me->delete("bunch_quest");
                       me->delete("bunch");
                       me->set("last_leave_bunch",time());
                       msg = "��˵" + me->name(1) + "��" + obj->name(1) + "�����" + bunch_good["bunch_name"];
                       CHANNEL_D->do_channel(this_object(), "rumor", msg);
                       return notify_fail("�㱻" + obj->name() + "��������" + bunch_good["bunch_name"] + "��\n");
               } else
               {
                       message_vision("$N����$nŭ�ȣ��������ҿ����\n",obj,me);
                       return notify_fail("�㱻" + obj->name() + "�ݺݵ�ʹ����һ����\n");
               }
       }

       if (!me->query("bunch_quest"))
               return notify_fail(obj->name() + "��ֵĿ�����˵�������ڲ�û�������������ǲ����еķ����ˣ�\n");

       me->delete("bunch_quest");
       message_vision("$N����$nһ������̾�����ƺ�������Ϊʲô$nΪ����˵Ĳ��ɲġ�\n",obj,me);
       tell_object(me,obj->name() + "�������һ�ۣ����С���鶼��ɲ��ˣ�һ��ȥ�ú÷�ʡ��ʡ��\n");

       //��¼����ʱ��
       me->set("last_bunch_quest",time());

       //������û�������������Ĵ�����¼�����ۼӸ������Ҫ�ȴ���ʱ�䣬���WAIT_TIME�룬���򣬵ȴ�3��
       if (!me->query_temp("finish_bang_times"))
              me->set("need_wait_time",me->query("need_wait_time") + 3);
       else me->set("need_wait_time",3);

       if (me->query("need_wait_time") > WAIT_TIME) me->set("need_wait_time",WAIT_TIME);

       //��������������Ĵ���
       me->delete_temp("finish_bang_times");
       return 1;
}
/*
int accept_object(object me,object ob)
{
       int exp,pot,score,weiwang;
       mapping bunch_quest,bonus;
       object who,env;
       string *place,the_place,msg;

       who = this_object();
       if (base_name(ob) != "/d/city/npc/obj/yaopai")
       {
               msg = who->name() + "��м�ذ�" + ob->query("name") + "�׻����㣺ʲô�ö���Ҳ���ң�\n";
               tell_object(me,msg);
               return 0;
       }
       if (!me->query("bunch_quest"))
       {
               msg = who->name() + "������˵�ͷ��û��˵ʲô����\n";
               tell_object(me,msg);
               return 1;
       }

       bunch_quest = me->query("bunch_quest");

       if (bunch_quest["id"] != "xc" || bunch_quest["bunch_name"] != "Ѳ���ݳ�")
       {       
               msg = who->name() + "������˵�ͷ��û��˵ʲô����\n";
               tell_object(me,msg);
               return 1;
       }

       place = bunch_quest["place"];

       if (sizeof(place))
       {
               the_place = place[random(sizeof(place))];
               env = get_object(the_place);
               msg = who->name() + "�����Ķ���˵��";
               msg += fail_xc_msg1[random(sizeof(fail_xc_msg1))];
               msg = replace_string(msg,"place",env->short());
               msg += fail_xc_msg2[random(sizeof(fail_xc_msg2))];
               tell_object(me,msg + "\n");
               return 0;
       }

       message_vision("$N���˵�������$n�ļ�򣺸ɵĺã�\n",who,me);

       me->add("pk_score",-2);
       if (me->query("pk_score") < 0) me->set("pk_score",0);

       exp = bunch_quest["bonus"]; 
       pot = exp/(2+random(2)); 
       weiwang = 5 + random(10); 
       score = 5 + random(10); 
       me->delete("bunch_quest"); 
       me->add_temp("finish_bang_times",1);
       bonus = ([ "exp" : exp, 
                  "pot" : pot, 
                  "score" : score, 
                  "weiwang" : weiwang, 
                  "prompt": "��Ѳ���ݳǵĹ����У���������" 
               ]);
       QUEST_D->delay_bonus(me, bonus);
       destruct(ob);
       return 1;
}
*/
