// Copyright (C) 2005, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// ��Ҫ���������ҪΪ�����ĸ�����
// c_name(e_name) ���е����;�������
// pfm_attack_msg ���з�������
// pfm_succeed_msg ���д�������
// pfm_fail_msg ����ʧ������

#include <ansi.h>
#include <command.h>
#define  SYN "\""
#define  SYC ".c"
#define  NEED_LVL   1600

#define  PERFORM_MODEL_LIAN  "/clone/meskill/perform_model_lian.h"
#define  PERFORM_MODEL_DAN   "/clone/meskill/perform_model_dan.h"
#define  PERFORM_MODEL_HUN   "/clone/meskill/perform_model_hun.h"

inherit F_CLEAN_UP;

mapping valid_types = ([
        "unarmed":      "ȭ��",
        "sword":        "����",
        // "arrow":        "����",
        "axe":          "����",
        "blade":        "����",
        "staff":        "�ȷ�",
        "hammer":       "����",
        "club" :        "����",
        // "dodge":        "�Ṧ",
        "whip":         "�޷�",
        "finger":       "ָ��",
        "hand":         "�ַ�",
        "cuff":         "ȭ��",
        "claw":         "צ��",
        "strike":       "�Ʒ�",
]);

string *weapon_types = ({
        "sword", "arrow", "axe",
        "blade", "staff", "hammer",
        "club", "whip" , "spin",
});

string *msga = ({ 
        "ڤڤ֮�У�$NͻȻ����",
        "$N�ʾ���֭���ƺ�����",
        "$N��̨һƬ����������",
        "$N��˼��ǰ����ʱ�ĵ��εΣ��ƺ�����",
        "ͻȻ��$N�Ժ����һ�֣�����",
        "$N�����Ȼ�������",
});

string *msgb = ({ 
        "������֮ͨ������������һ����",
        "����һһӡ֤֮����������������������",
        "�ƺ������ںϹ�ͨ����ʱ����һ���ϲ��",
        "�����໥ȡ�����̣�����һ��ȫ�µľ��硣",
        "�������ʹ�����ƺ����Խ��������������ޡ�",
        "�����������������໥�ֲ����в��㣬������������ľ��С�"
});

string *banned_name = ({
        "��", "��", "��", "��", "��", "��",
        "��", "ү", "��", "��",
        "ʺ", "��", "��",
});

string get_skill_name(object me, string skill);

void get_perform_model(string arg, object me, string base_skill, string skill);
void get_perform_name(string arg, object me, string base_skill, string skill, string model);
void get_perform_msg1(object me, string base_skill, string skill, string model, string c_name, string e_name, string msg);
void get_perform_msg2(object me, string base_skill, string skill, string model, string c_name, string e_name, string pfm_attack_msg, string msg);
void get_perform_msg3(object me, string base_skill, string skill, string model, string c_name, string e_name, string pfm_attack_msg, string pfm_succeed_msg, string msg);
void decide_input_perform(string arg, object me, string base_skill, string skill, string model, string c_name, string e_name, string pfm_attack_msg, string pfm_succeed_msg, string pfm_fail_msg);
void finish_write_perform(object me, string base_skill, string skill, string model, string c_name, string e_name, string pfm_attack_msg, string pfm_succeed_msg, string pfm_fail_msg);

int main(object me, string arg)
{
        mapping creates;
        string  skill, perform, base_skill;
        string  *types, *performs, *skills;
        object  weapon, where;
        mapping skills_map;
        string  msg, dir, *mut_skills = ({});
        int     i, j;
        int     flag = 0;
        
        seteuid(getuid());
        where = environment(me);
        
        if( !arg ) {
                if( !mapp( creates = me->query("create") ) )
                        return notify_fail("��Ŀǰ��û���κ��Դ����С�\n");
                        
                skills = keys(creates);   
 
                msg = WHT "��Ŀǰ���Դ����书����������£�\n" NOR;               
                for( i = 0; i < sizeof(skills); i++ ) {  
                        msg += HIC "\n" + skills[i] + " ��";          
                        performs = keys(creates[skills[i]]);
                        for( j = 0; j < sizeof(performs); j++ ) {
                                msg += performs[j];
                                msg += (j == (sizeof(performs) -1) ? NOR :  WHT " - " HIC);
	                }
                }
	        
                msg += "\n\n";
	        tell_object(me, msg);

                return 1;
        }

        if( sscanf(arg, "%s %s d", skill, perform) == 2 ) {	                
                object ob;
	        if( !me->query("create/" + skill) )
		        return notify_fail("û���Դ������书���У���ȷ��������书Ӣ�����ơ�\n");
                
                if( !me->query("create/" + skill + "/" + perform) )
                        return notify_fail("û���Դ������书���У���ȷ������ľ���Ӣ�����ơ�\n");
                
                tell_object(me, HIR "��ɾ�����Դ�" + to_chinese(skill) + "����" + to_chinese(perform) + "(" + perform + ")��\n" NOR);                        	                
	        CHINESE_D->remove_translate(perform);	                
                dir = SKILL_D(skill);
                if (dir[strlen(dir) - 1] != '/')
                        dir += "/";              
                if (SKILL_D(skill)->valid_enable("force"))
                        dir += "perform/";                             
                if (ob = get_object(dir + perform + SYC))
                        destruct(ob);
	        rm( dir + perform + SYC );	                
	        me->delete("can_perform/" + skill + "/" + perform);
	        me->delete("create/" + skill + "/" + perform);
	        if( !mapp(me->query("create/" + skill)) || 
                        sizeof(me->query("create/" + skill)) < 1)
	                me->delete("create/" + skill);
	                
                if( !mapp(me->query("create") ) || 
                        sizeof(me->query("create")) < 1)
                        me->delete("create");
	                return 1;
        }
                
        if( me->is_busy() )
                return notify_fail("�㻹����æ����ͷ������˵�ɣ�\n");	 
    
        if( where->query("pigging") )
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
		
        if( !where->query("no_fight") )
                return notify_fail("������չأ���̫��ȫ�ɣ�\n");

        if( !where->query("sleep_room") )
                return notify_fail("�����һ���ܹ���Ϣ�ĵط��չء�\n");
                
        if( !ultrap(me))
                return notify_fail("�㻹û�е�����ʦ�ľ��磬���Ǻú�ѧϰ�����ɡ�\n");

        if( count_lt(count_sub(me->query("potential"), me->query("learned_points")), 1000000) )
                return notify_fail("���Ǳ�ܲ�����û���չ����С�\n");

        if( (int)me->query("qi") * 100 / me->query("max_qi") < 90 )
		return notify_fail("�����ڵ���̫���ˣ��޷����ıչء�\n");

        if( (int)me->query("jing") * 100 / me->query("max_jing") < 90 )
		return notify_fail("�����ڵľ�̫���ˣ��޷����ıչء�\n");

        if( (int)me->query("max_neili") < 4000 )
                return notify_fail("������������в��㣬����Ŀǰ������"
				   "���г�ʱ��ıչ�������\n");

        if( (int)me->query("neili") * 100 / me->query("max_neili") < 90 )
	        return notify_fail("�����ڵ�����̫���ˣ��޷����ıչء�\n");

        if( !mapp(skills_map = me->query_skills() ) || sizeof(skills_map) < 1 )
                return notify_fail("�㻹����ȥѧ�㹦�������ɡ�\n");

        if( undefinedp(skills_map[arg]) || skills_map[arg] < 1 )
                return notify_fail("����������" + to_chinese(arg) + "�����ᣬ�Ӻ�̸��\n");

        if( me->query_skill("martial-cognize", 1) < NEED_LVL )
                return notify_fail("�����ѧ��������Ϊ���������\n");

        if( skills_map[arg] < NEED_LVL )
                return notify_fail("���" + to_chinese(arg) + "����Ϊ���������\n");
                                
        if( SKILL_D(arg)->type() != "martial" )
                return notify_fail("���޷�Ϊ�����书������С�\n");

        dir = SKILL_D(arg) + "/";

        if( file_size(dir) != -2 )
                return notify_fail("���޷�Ϊ�����书������С�\n");
                        
        /*
        if( SKILL_D(arg)->is_invent_skill() ) {
                if( me->query("jieti/times") < 2 )
                        return notify_fail("��Ŀǰ���޷�Ϊ�����Դ��书������С�\n"); 
        }  
        */
 
        types = keys(valid_types);	
        for( i = 0; i < sizeof(types); i++ ) 
	{
                if( SKILL_D(arg)->valid_enable(types[i]) ) 
		        continue;
		        
                types[i] = 0;
	}
	
        types -= ({ 0 });
        
        // if( sizeof(types) != 1 )
        if( sizeof(types) < 1)
                return notify_fail("��Ŀǰ���޷�Ϊ�����Դ��书������С�\n"); 
               
        base_skill = types[0];
        skill = arg;
        
        if( objectp( weapon = me->query_temp("weapon") ) ) {
                if( member_array(base_skill, weapon_types) == -1 ) {
                        if (sizeof(types) == 1)
                                return notify_fail("�������ֲ����Դ�" + to_chinese(skill) + "�ľ��С�\n");
                        else {
                                for (i = 1; i < sizeof(types); i++) {
                                        base_skill = types[i];
                                        if( member_array(base_skill, weapon_types) != -1 ) {
                                                flag = 1; // ���ñ���
                                                break;
                                        }
                                }
                                if( flag != 1 ) return notify_fail("�������ֲ����Դ�" + to_chinese(skill) + "�ľ��С�\n");
                        }
                }
                if( member_array(base_skill, weapon_types) != -1 ) {
                        if( weapon->query("skill_type") != base_skill ) {
                                if (sizeof(types) == 1)
                                        return notify_fail("����ʹ�õ��������ԣ��޷��Դ�" + to_chinese(skill) + "�ľ��С�\n");
                                else {
                                        for (i = 1; i < sizeof(types); i++) {
                                                base_skill = types[i];  
                                                if( weapon->query("skill_type") == base_skill ) {
                                                        flag = 2;
                                                        break;
                                                }
                                        }
                                        if( flag != 2 )
                                                return notify_fail("����ʹ�õ��������ԣ��޷��Դ�" + to_chinese(skill) + "�ľ��С�\n");
                                }
                        }
                }
                        
        } else 
        if( member_array(base_skill, weapon_types) != -1 ) {
                if (sizeof(types) == 1)
                        return notify_fail("����������������ܿ�ʼ�Դ�" + to_chinese(skill) + "�ľ��С�\n");
                else {
                        for (i = 1; i < sizeof(types); i++) {
                                base_skill = types[i]; 
                                if( member_array(base_skill, weapon_types) == -1 ) {
                                        flag = 3;
                                        break;
                                }
                        }
                        if( flag != 3 ) return notify_fail("����������������ܿ�ʼ�Դ�" + to_chinese(skill) + "�ľ��С�\n");
                }
        }                                

        skills = keys(skills_map);

        foreach( string sk_tmp in skills ) {
                if( SKILL_D(sk_tmp)->valid_enable(base_skill) ) {
                        mut_skills += ({ sk_tmp });
                }
        }

        if( sizeof(mut_skills) < 3 )
                return notify_fail("���" + valid_types[base_skill] + "��Ϊ�������㲩����ȥ��ѧϰѧϰ��\n");

        mut_skills = filter_array(mut_skills, (: $(skills_map)[$1] >= NEED_LVL :));

        if( sizeof(mut_skills) < 3 )
                return notify_fail("����" + valid_types[base_skill] + "�������Ϊ���������\n");
        
        if (sizeof(me->query("create/" + skill)) >= 3)
                return notify_fail("���" + to_chinese(skill) + 
                                   "���������Ѿ����˼��ޣ��޷����Դ��¾��С�\n");
        me->delete_temp("create");
                                
                
        message_vision("$N��ϥ���£���ʼ��˼ڤ�룬ר�ĵ��Դ�" + to_chinese(skill) + "���С�\n", me);              

        me->set_temp("create/skill", skill);
        me->set_temp("create/base_skill", base_skill); 
        me->set_temp("create/mut_skills", mut_skills);        
        
        me->set_short_desc("����ȫ���ע���Դ�" + to_chinese(skill) + "���С�");

        me->start_busy(bind((:call_other, __FILE__, "inventing" :), me),
                       bind((:call_other, __FILE__, "halt_inventing" :), me));

        CHANNEL_D->do_channel(this_object(), "rumor",
                              sprintf("%s(%s)��ʼ�չ��Դ�%s��\n",
                              me->name(1), me->query("id"), to_chinese(skill) + "�¾���"));
        return 1;
}

int inventing(object me)
{
        int     max, i;
        string  pot;
        string  base_skill, skill, *mut_skills, *skills_tmp,
                msg = "", *msgs = ({});
        
        pot = me->query("potential");
        if( count_le(pot, me->query("learned_points")) )
        {
                tell_object(me, "���Ǳ�ܺľ���ȴһ������ʧ����վ�ˡ�\n");
                message_vision("$N����˫Ŀ����������һ������վ��������\n", me);
                me->set_short_desc(0);
                return 0;
        }

        if( count_gt(me->add("learned_points", 5000 + random(10000)), pot))
                me->set("learned_points", pot);

        if( random(5) != 0) return 1;

        skill = me->query_temp("create/skill");
        base_skill = me->query_temp("create/base_skill");
        mut_skills = me->query_temp("create/mut_skills");

        if( random(20000) < me->query("int") ) {
                string *chinese_skills = ({});

                foreach(string mut_skill in mut_skills) {
                        chinese_skills += ({ to_chinese(mut_skill)});
                }
                
                message_sort("��Ȼ��$N�����Թ�������ʽ���ں�" + 
                                sprintf( HIG"%s" NOR "�Լ�" HIG "%s"NOR, 
                                implode(chinese_skills[0..sizeof(chinese_skills)-2], NOR "��" HIG), 
                                chinese_skills[sizeof(chinese_skills)-1])
                                + "��" + chinese_number(sizeof(mut_skills)) + "���书֮����Ϊ"
                                + to_chinese(skill) + "�����µľ���\n", me);

                me->clear_written();
                me->set_short_desc(0);   
                me->delete_temp("create");
                tell_object(me, HIW "\n�κ�ʱ������ ~q �����ֹ�Դ����С�\n" NOR);
                tell_object(me, HIW "\n\n������Ϊ" + to_chinese(skill) + "�Դ��µľ��С�\n" NOR
                                "�����Ϊ�������ѡ�񴴽���������\n\n" NOR);                
	        tell_object(me, "\t1> ����һ��Ϊ���еľ���\n");
	        tell_object(me, "\t2> ����һ��Ϊ���еľ���\n");
	        tell_object(me, "\t3> ����һ��Ϊ����еľ���\n");   	        
	        tell_object(me, "\t3> ������ѡ��1-3��");       
                    
                input_to( (: get_perform_model :), me, base_skill, skill );
                return 0;
        }

        skills_tmp = copy(mut_skills);

        max = 2 + random(sizeof(mut_skills)-2);
        if ( max > 5 ) max = 5;

        if( max < sizeof(mut_skills) ) {
                for( i = max; i < sizeof(mut_skills); i++ ) {
                        skills_tmp -= ({ skills_tmp[random(sizeof(skills_tmp))] });
                }
        }

        foreach(string sk_tmp in skills_tmp) {
                msgs += ({ get_skill_name(me, sk_tmp) });
        }

        msg = msga[random(sizeof(msga))] + sprintf("%s" NOR "�Լ�%s", 
              implode(msgs[0..sizeof(msgs)-2], NOR "��"), msgs[sizeof(msgs)-1])
              + NOR + msgb[random(sizeof(msgb))] + "\n"NOR;

        message_sort(msg, me);

        return 1;
}

int halt_inventing(object me)
{
        me->set_short_desc(0);
        me->delete_temp("create");
        tell_object(me, HIG "����ֹ���Դ����С�\n" NOR);
        message_vision(HIY "$N" HIY "����վ�������������ʧ����\n\n" NOR, me);
        return 1;
}

string get_skill_name(object me, string skill)
{
        mapping actions;
        string  skill_name, action;
        int     a, b;

        if( !find_object(SKILL_D(skill)) && !load_object(SKILL_D(skill)) )
                return HIG + to_chinese(skill);

        if( !mapp( actions = SKILL_D(skill)->query_action(me, me->query_temp("weapon")) ) )
                return HIG + to_chinese(skill);

        if( !undefinedp(actions["skill_name"]) )
                return HIG + actions["skill_name"];

        if( undefinedp(actions["action"]) )
                return HIG + to_chinese(skill);

        action = actions["action"];

        if( strsrch(action, "��") != -1 && strsrch(action, "��") != -1 ) {
                a = strsrch(action, "��");
                b = strsrch(action, "��");
                skill_name = action[a..b+1];
                return HIG + to_chinese(skill) + NOR + (random(2)?"��һ��"YEL:"�е�"YEL) + skill_name + NOR;
        } else if( strsrch(action, "��") != -1 && strsrch(action, "��") != -1 ) {
                a = strsrch(action, "��");
                b = strsrch(action, "��");
                skill_name = action[a..b+1];
                return HIG + to_chinese(skill) + NOR + (random(2)?"��һ��"YEL:"�е�"YEL) + skill_name + NOR;
        } else if( strsrch(action, "��") != -1 && strsrch(action, "��") != -1 ) {
                a = strsrch(action, "��");
                b = strsrch(action, "��");
                skill_name = action[a..b+1];
                return HIG + to_chinese(skill) + NOR + (random(2)?"��һ��"YEL:"�е�"YEL) + skill_name + NOR;
        } else return HIG + to_chinese(skill);
}

void get_perform_model(string arg, object me, string base_skill, string skill)
{
        string model;
        int n;
        
        if( arg == "" || arg == "~q" )
        {
                tell_object(me, "��������Դ����С�\n"); 
                return;
        }
                
        n = to_int(atoi(arg));
        if (n < 1 || n > 3)
        {
                tell_object(me, "�Բ�����ֻ��ѡ��1-3�����»س�ֱ��ѡ�����ա�\n\n");
	        tell_object(me, "\t1> ����һ��Ϊ���еľ���\n");
	        tell_object(me, "\t2> ����һ��Ϊ���еľ���\n");
	        tell_object(me, "\t3> ����һ��Ϊ����еľ���\n");   
	        tell_object(me, "\t3> ������ѡ��1-3��");       
                input_to((: get_perform_model :), me, base_skill, skill);
                return;
        }
        
 	switch(n)
	{
	case 1:
		model = "������";
	        break;
	case 2:
                model = "������";
		break;
	case 3:
                model = "�������";
		break;
	}

        tell_object(me, HIW "\n\n\n������Ϊ" + to_chinese(skill) + "�Դ�����" + model + "�ľ��С�\n" NOR
                        "�����Ϊ�������ȡһ������\n\n"
                        HIY "��ʽ��" HIC "<Ӣ����> <������>\n\n" NOR
                        HIW "����ɧ���Ի��ŵ����֣����򽫻ᱻɾ����\n" NOR
                        "�����룺");
        input_to( (: get_perform_name :), me, base_skill, skill, model );
}

void get_perform_name(string arg, object me, string base_skill, string skill, string model)
{
        string  c_name, e_name, file;
        int     i;
                       
        if( arg == "" || arg == "~q" )
        {
                tell_object(me, "��������Դ����С�\n"); 
                return;
        }

        if( sscanf(arg, "%s %s", arg, c_name) != 2 )
        {
                tell_object(me, "�Բ������ã�<Ӣ����> <������> �ĸ�ʽ���롣\n���������룺");
                input_to((: get_perform_name :), me, base_skill, skill, model);
                return;
        }
        
        if ((strlen(arg) < 3) || (strlen(arg) > 10))
        {
                tell_object(me, "�Բ���Ӣ���������� 3 �� 10 ��Ӣ����ĸ��\n���������룺");
                input_to((: get_perform_name :), me, base_skill, skill, model);
                return;
        }

        while (i--)
        {
                if (arg[i] < 'a' || arg[i] > 'z' )
                {
                        tell_object(me, "�Բ���Ӣ����ֻ����Ӣ����ĸ��\n���������룺");
                        input_to((: get_perform_name :), me, base_skill, skill, model);
                        return;
                }
        }
        
        e_name = arg;

        file = SKILL_D(skill);
        if( file[strlen(file) - 1] != '/' )
                file += "/";               
        if( SKILL_D(skill)->valid_enable("force") )
                file += "perform/";                       
        file += e_name;
        if( file_size(file + SYC) > 0 || get_object(file) ) {
                        tell_object(me, "�Բ����Ѿ���("+ arg +")���־����ļ����ڡ�\n���������룺");
                        input_to((: get_perform_name :), me, base_skill, skill, model);
                        return;
        }

        if (c_name && me->query_temp("big5"))
                c_name = LANGUAGE_D->toGB(c_name);
                
        if( !is_chinese(c_name) ) {
                        tell_object(me, "�Բ������á����ġ�����������\n���������룺");
                        input_to((: get_perform_name :), me, base_skill, skill, model);
                        return;
        }

        if (member_array(c_name, banned_name) % 2 == 0)
        {
                tell_object(me, "�Բ����������ƻ���������˵����š�\n���������룺");
                input_to((: get_perform_name :), me, base_skill, skill, model);
                return;
        }

        if( strlen(c_name) > 20 ) {
                tell_object(me, "�Բ��������õ�������̫������ѡһ����տһ������֡�\n���������룺");
                input_to((: get_perform_name :), me, base_skill, skill, model);
                return;
        }
        
        tell_object(me, HIW "\n\n\n���ɹ�Ϊ" + to_chinese(skill) + "�¾������úþ�����" 
                        HIW + c_name + "(" + e_name + ")" HIW "��\n" NOR);
                        
        tell_object(me, HIC "\nע������: $N ������ $n ������� $w ����������� \n\n" NOR);
        tell_object(me, HIC "���磺(ȭ����) \n" NOR);
        tell_object(me, HIM "$N" HIM "һ��ŭ������ս���ľ����˼�����˫ȭ��ʱЯ���������֮���͹���$n" HIM "��\n" NOR);
        tell_object(me, HIC "���磺(������)\n" NOR); 
        tell_object(me, HIM "$N" HIM "����$w�������ˣ�����˺�ѿ�����ƬƬѩ��Ʈ�䣬��δ�����ȼ���$n" HIM "üë�������˱�����˪��\n\n" NOR);
        tell_object(me, HIC "�����뷢��ʱ�����������Ȳ�����200�����֣�\n" NOR);                         
        me->edit(bind((: call_other, __FILE__, "get_perform_msg1", me, base_skill, skill, model, c_name, e_name :), me));
}

void get_perform_msg1(object me, string base_skill, string skill, string model, string c_name, string e_name, string msg)
{
        string pfm_attack_msg;
                        
        if( !stringp( msg ) || msg == "" ) {
                tell_object(me, "�����书���в�����û�о���������\n");
                me->edit(bind((: call_other, __FILE__, "get_perform_msg1", me, base_skill, skill, model, c_name, e_name :), me));
                return;
        }
        else {
                if( strlen(msg) > 400 ) {
                        tell_object(me, "���趨������̫���ˣ����趨һ�������������\n");
                        me->edit(bind((: call_other, __FILE__, "get_perform_msg1", me, base_skill, skill, model, c_name, e_name :), me));
                        return;
                }
        }

        msg = replace_string(msg, "\"", "");
        msg = replace_string(msg, "\n", "");
        msg = replace_string(msg, "$w", "����");
        msg = replace_string(msg, "��", "$N");
        msg = filter_color(msg);
                     
        pfm_attack_msg = msg;
                              
        tell_object(me, HIC "\nOK\n" NOR); 
        tell_object(me, HIC "\nע������: $N ������ $n ������� $w ����������� \n\n" NOR);
        tell_object(me, HIC "���磺(ȭ����) \n" NOR);
        tell_object(me, HIM "���$n" HIM "���ܲ�����$N" HIM "��ȭ���ƾ���ʱ͸����룬������Ѫ���磬����������\n" NOR);
        tell_object(me, HIC "���磺(������)\n" NOR); 
        tell_object(me, HIM "ֻ��$n" HIM "һ���ҽУ��ؿڸ�����һ���޴�Ŀ��ӣ���Ѫ��ӿ�����\n\n" NOR);
        tell_object(me, HIC "��������д���ʱ�����������Ȳ�����100�����֣�\n" NOR);    
        me->edit(bind((: call_other, __FILE__, "get_perform_msg2", me, base_skill, skill, model, c_name, e_name, pfm_attack_msg :), me));
}

void get_perform_msg2(object me, string base_skill, string skill, string model, string c_name, string e_name, string pfm_attack_msg, string msg)
{
        string pfm_succeed_msg;
        
        if( !stringp( msg ) || msg == "" ) {
                tell_object(me, "�����书���в�����û�о���������\n");
                me->edit(bind((: call_other, __FILE__, "get_perform_msg2", me, base_skill, skill, model, c_name, e_name, pfm_attack_msg :), me));
                return;
        }
        else {
                if( strlen(msg) > 200 ) {
                        tell_object(me, "���趨������̫���ˣ����趨һ�������������\n");
                        me->edit(bind((: call_other, __FILE__, "get_perform_msg2", me, base_skill, skill, model, c_name, e_name, pfm_attack_msg :), me));
                        return;
                }
        }
 
        msg = replace_string(msg, "\"", "");
        msg = replace_string(msg, "\n", "");
        msg = replace_string(msg, "$w", "����");
        msg = replace_string(msg, "��", "$N");
        msg = filter_color(msg);
               
        pfm_succeed_msg = msg;
                              
        tell_object(me, HIC "\nOK\n" NOR);   
        tell_object(me, HIC "\nע������: $P ������ $p ������� $w ����������� \n" NOR);
        tell_object(me, HIC "���磺(ȭ����) \n" NOR);
        tell_object(me, HIM "����$p" HIM "ʶ����$P" HIM "��һ�У�ббһԾ�ܿ���\n" NOR);
        tell_object(me, HIC "���磺(������)\n" NOR); 
        tell_object(me, HIM "$p" HIM "���Ʋ�������ˣ����ձܹ�$P" HIM "�����ɱ�У����������У������ѿ���һ������ӣ�\n\n" NOR);        
        tell_object(me, HIC "���������ʧ��ʱ�����������Ȳ�����100�����֣�\n" NOR);   
        me->edit(bind((: call_other, __FILE__, "get_perform_msg3", me, base_skill, skill, model, c_name, e_name, pfm_attack_msg, pfm_succeed_msg :), me));
}

void get_perform_msg3(object me, string base_skill, string skill, string model, string c_name, string e_name, string pfm_attack_msg, string pfm_succeed_msg, string msg)
{
        string pfm_fail_msg;
        
        if( !stringp( msg ) || msg == "" ) {
                tell_object(me, "�����书���в�����û�о���������\n");
                me->edit(bind((: call_other, __FILE__, "get_perform_msg3", me, base_skill, skill, model, c_name, e_name, pfm_attack_msg, pfm_succeed_msg :), me));
                return;
        }
        else {
                if( strlen(msg) > 200 ) {
                        tell_object(me, "���趨������̫���ˣ����趨һ�������������\n");
                        me->edit(bind((: call_other, __FILE__, "get_perform_msg3", me, base_skill, skill, model, c_name, e_name, pfm_attack_msg, pfm_succeed_msg :), me));
                        return;
                }
        }

        msg = replace_string(msg, "\"", "");
        msg = replace_string(msg, "\n", "");
        msg = replace_string(msg, "$w", "����");
        msg = replace_string(msg, "��", "$N");
        msg = filter_color(msg);
                
        pfm_fail_msg = msg;                            
        
        tell_object(me, HIW "\n��ɹ���Ϊ" + to_chinese(skill) + "�´��ľ����������������Ϣ��\n\n" NOR
                        HIC "�������ͣ�" NOR HIC + model + "\n" NOR
                        HIC "�������ƣ�" NOR HIC + c_name + "\n" NOR
                        HIC "Ӣ�����ƣ�" NOR HIC + e_name + "\n" NOR
                        HIC "����������" NOR HIC + pfm_attack_msg + "\n" NOR
                        HIC "����������" NOR HIC + pfm_succeed_msg + "\n" NOR
                        HIC "ʧ��������" NOR HIC + pfm_fail_msg + "\n" NOR
                        HIW "��ȷ����(Y/N)" NOR);
                                
        input_to( (: decide_input_perform :), me, base_skill, skill, model, c_name, e_name, pfm_attack_msg, pfm_succeed_msg, pfm_fail_msg );
}

void decide_input_perform(string arg, object me, string base_skill, string skill, string model, string c_name, 
                          string e_name, string pfm_attack_msg, string pfm_succeed_msg, string pfm_fail_msg)
{
        object ob;
        string dir;
                
        if( arg == "y" || arg == "Y" ) {
                if( objectp( ob = get_object(SKILL_D(skill) + "/" + e_name) ) ) {
                        tell_object(me, "BUG������ϵ��ʦ��\n");
                        return;
                }
                finish_write_perform(me, base_skill, skill, model, c_name, e_name, pfm_attack_msg, pfm_succeed_msg, pfm_fail_msg);

                log_file("create", sprintf("%s(%s) create perform %s(%s) (%s)\n",
                                           me->query("name"),
                                           me->query("id"),
                                           c_name,
                                           e_name,
                                           ctime(time())));
                
                dir = SKILL_D(skill);
                if (dir[strlen(dir) - 1] != '/')
                        dir += "/";
                
                if (SKILL_D(skill)->valid_enable("force"))
                        dir += "perform/";
                
                if( get_object(dir + e_name) ) {
                        CHANNEL_D->do_channel(this_object(), "rumor",
                                           sprintf("%s(%s)����ƽ��ѧ�ں����գ�Ϊ" NOR HIW + "��" + to_chinese(skill) + "��" NOR
                                           HIM "�����µľ���" NOR HIC + "��" + c_name + "��" NOR + HIM "��" , 
                                           me->name(1), me->query("id")));
                        
                        me->force_me("chat* admire2 " + me->query("id"));
                        
                        CHINESE_D->add_translate(e_name, c_name);                        
                                        
                        SKILLS_D->set("create/" + skill, 1);
                        me->set("create/" + skill + "/" + e_name, 1);
                        me->set("can_perform/" + skill + "/" + e_name, 1);
                        me->save();
                }

        } else {
                tell_object(me, HIW "\n\n\n��Ϊ" + to_chinese(skill) + "�Դ������µľ��С�\n" NOR
                                "���������ѡ��Ϊ�������ѡ�񴴽���������\n\n" NOR);      
	        tell_object(me, "\t1> ����һ��Ϊ���еľ���\n");
	        tell_object(me, "\t2> ����һ��Ϊ���еľ���\n");
	        tell_object(me, "\t3> ����һ��Ϊ����еľ���\n");   
	        tell_object(me, "\t3> ������ѡ��1-3��");       
 
                input_to((: get_perform_model :), me, base_skill, skill);
        }                       
}

void finish_write_perform(object me, string base_skill, string skill, string model, string c_name, 
                          string e_name, string pfm_attack_msg, string pfm_succeed_msg, string pfm_fail_msg)
{
        string result, header1, header2;
        string dir;
        
        result  = "";
        header1 = "";
        header2 = "";
     
        header1 += "// This is player's own perform (Write by Lonely@nt2)\n";
        header1 += "// Create by " + me->query("name") + "(" + capitalize(geteuid(me)) + ") at " + ctime(time()) + "\n";
        header1 += "// " + c_name + "(" + e_name + ")\n"; 

        if( model == "������" ) 
                header2 = read_file(PERFORM_MODEL_LIAN);
        else if( model == "������" )
                header2 = read_file(PERFORM_MODEL_DAN);
        else
                header2 = read_file(PERFORM_MODEL_HUN);          
 
        header2 = replace_string(header2, "<������>", c_name);
        header2 = replace_string(header2, "<PFM��������>", pfm_attack_msg); 
        header2 = replace_string(header2, "<PFM��������>", pfm_succeed_msg); 
        header2 = replace_string(header2, "<PFMʧ������>", pfm_fail_msg);
        header2 = replace_string(header2, "E_NAME", e_name);
        header2 = replace_string(header2, "BASE_SKILL", base_skill);
        header2 = replace_string(header2, "SKILL", skill);
        
        result = header1 + header2;
        
        dir = SKILL_D(skill);
        if (dir[strlen(dir) - 1] != '/')
                dir += "/";
                
        if (SKILL_D(skill)->valid_enable("force"))
                dir += "perform/";
                
        assure_file(dir); 
        write_file(dir + e_name + SYC, result, 1);
        write(HIC "���д����ɹ����Ժ���ʹ�� " + HIY "perform " + e_name +  HIC " ʹ�øþ��С�\n" NOR );
}

int help(object me)
{
        write(@HELP
			                 
ָ���ʽ: create                           �鿴�Լ��Դ��书���е����
          create <�书����>                Ϊ���书�Դ��µľ���
          create <�书����> <��������> d   ɾ�����书���Ѵ��书֮����

HELP );
        return 1;
}
