// Daemon : /adm/daemons/gambled.c
// ����ϵͳ
// By jjgod for hell. 00/05/07.
// Update by Lonely

#include <ansi.h>

inherit F_SAVE;

#define DATA_FILE               DATA_DIR "gambled"
#define INITING                 "initing"
#define OPENING                 "opening"
#define STOPPED                 "stopped"
#define FINISHING               "finishing"

mapping item_data = ([
 "ʮǿ���ھ�Ԥ��" : ([ "long" : "���籭��Χ��֮ʮǿ�����Ͼ�Ҫ��ʼ"
                                "�ˣ���������ʮǿ��˭�ܳ��ߣ��й�"
                                "���ܷ�˳��������ޣ��ܷ���οֺ�"
                                "����֢������������Ϊ���Գ��ߵĶ�"
                                "������ע�ɣ�",
                       "end_time" : 1210996409,
                       "status"   : OPENING,
                       "min_money" : 10000, 
                       "number" : 3,
                       "subject" : ([ "�й���" : 10, 
                                      "������" : 20, 
                                      "�¹���" : 50, 
                                      "Ӣ����" : 70, 
                                      "������" : 80, 
                                      "������" : 100, ]),
                     ]), 
]);

mapping user_data = ([
"wind" : ([ "ʮǿ���ھ�Ԥ��" : ([ "team" : ({ "�й���", "������",
                                               "������", }),
                                   "money" : 80000, ]),
           ]),
]);

public void change_status(string name, string status);
public string query_status(string name);
public mapping query_item(string name);
private void change_name(string arg, object me, string name);
private void change_long(object me, string arg, string long);
private void change_date(string arg, object me, string name);
private void change_number(string arg, object me, string name);
private void change_money(string arg, object me, string name);
private void change_team_type(string arg, object me, string name);
private void get_name_end(string arg, object me);
/****************************************************************
 *                                                              *
 *            �йر�����ϵͳ(About this Gamble system)          *
 *                                                              *
 *     ������ϵͳ����ȫ�Զ���ʽ������ʦ�ֶ��趨һ����Ŀ�Ժ�ֻ *
 * Ҫ�ȴ����������󽫱���������룬�Ϳ������һ����������Ϸ�Ĺ� *
 * �̡�                                                         *
 *                                                              *
 *     ��һ��Ŀ�����������������£�                             *
 *                                                              *
 *     1��������Ŀ���ݣ���ʱΪ����̬(Initing)��                 *
 *     2����ʼ����Ͷע����ʱΪ����̬(Opening)��                 *
 *     3��ֹͣ����Ͷע����ʱΪֹ̬ͣ(Stopped)��                 *
 *     4�����������Ŀ����ʱΪ����̬(Finishing)��               *
 *                                                              *
 *     ����ʱ�ĵ��ýṹ���£�                                   *
 *                                                              *
 *                          ����ϵͳ������                      *
 *        +----------+----------+----------+----------+         *
 *     ������Ŀ   �޸���Ŀ   �鿴Ͷע   ������Ŀ   �˳�ϵͳ     *
 *        |          |          |          |          |         *
 *     ��������   ѡ����Ŀ   ѡ�����   ѡ����Ŀ     �˳�       *
 *        |          |          |          |                    *
 *     ��������   �޸�����   ��ѯ���   ɾ�����                *
 *        |          |          |          |                    *
 *     ����ʱ��   �޸����      |          |                    *
 *        |          |          |          |                    *
 *     ����Ͷע      |          |          |                    *
 *        |          |          |          |                    *
 *     Ͷע����      |          |          |                    *
 *        |          |          |          |                    *
 *     �������------+----------+-------���ؽ���                *
 *                                                              *
 * �������ݣ�                                                   *
 *                                                              *
 *     item_data ӳ�䣺��Ŀ����                                 *
 *     user_data ӳ�䣺�û�����                                 *
 *                                                              *
 * �����б�                                                   *
 *                                                              *
 *     ���ⲿ���õģ�                                           *
 *     public void start_manage()  ������������               *
 *     public void printf_over()   : ���ý������               *
 *     public void do_chip()       ������Ͷע����               *
 *     public void change_status() ���޸���Ŀ״̬               *
 *     public string query_status()����ѯ��Ŀ״̬               *
 *     public mapping query_item() ����ȡ��Ŀ����               *
 *     public mapping query_data() ��������м�¼               *
 *                                                              *
 *     �ڲ�˽�еģ�                                             *
 *     private void write_prompt()      ����ʾ�������          *
 *     private void end_manage()        ���˳��������          *
 *     private void get_type()          ��ѡ��������          *
 *     private void get_name()          ��������Ŀ����          *
 *     private void select_change_type()��ѡ���޸����          *
 *     private void get_long()          ��������Ŀ����          *
 *     private void get_team_number()   �������������          *
 *     private void get_team_info()     �������������          *
 *     private void get_date_off()      ���������ʱ��          *
 *     private void get_chip_number()   ������Ͷע����          *
 *     private void get_name_todel()    ��ѡ��ɾ����Ŀ          *
 *     private void get_user()          ��ѡ���ѯ���          *
 *     private void get_user_info()     ����������Ϣ          *
 *                                                              *
 *     ���⣬���� heart_beat ��ʱ�ж�һ����Ŀ�Ƿ�Ӧ��ֹͣ��Ŀǰ *
 * �� heart_beat �趨ֵΪ 30��������ʱ�侫ȷ��Ϊ +- 60s��       *
 *                                                              *
 ****************************************************************/
 
// ���������ļ�
void create()
{
        seteuid(getuid());
        restore();
}

// ���ش����ļ�λ��
string query_save_file()
{
        return DATA_FILE;
}

void remove()
{
        save();
}

void mud_shutdown()
{
        save();
}

// ��ʾ��
private void write_prompt(object me)
{
        write("�����㣺" WHT "A" NOR "�������µ���Ŀ " WHT "B" NOR "���޸ľɵ���Ŀ "
              WHT "C" NOR "���鿴���Ͷע \n" WHT "        D" NOR "������һ����Ŀ " WHT
              "E" NOR "��ɾ��һ����Ŀ " WHT "F" NOR "���˳�����ϵͳ \n");
        write("��ѡ��");
        input_to("get_type", me);

}

// �˳�����
private void end_manage()
{
        write("\n�������˲��ʹ���\n");
        write(HIW "������������������������������������������������������������������������\n" NOR);
        return;
}

// �������ϵͳ
public void start_manage(object me)
{
        write(HIW "������������������������������������������������������������������������\n" NOR);
        write("\t\t\t  " + MUD_NAME + "���ʹ������\n\n");
        write_prompt(me);
        return;
}

// ѡ���������
private void get_type(string arg, object me)
{
        string *users, msg = "", *items;
        int i, j;
        
        switch (arg)
        {
        case "a": 
        case "A":
                items = keys(item_data);
                msg = "Ŀǰ����Ŀ�У�\n\n";
                
                for (i = 0; i < sizeof(items); i++)
                {
                        msg += WHT + (i+1) + NOR "��" + items[i] + "\n";
                }
                
                if (! sizeof(items)) msg = "";
                
                write(msg);
                write("\n�����㴴���µĲ�����Ŀ��\n");
                write("�������½�����Ŀ���ƣ�");
                input_to("get_name", me);
                return;
        case "b": 
        case "B": 
                items = keys(item_data);
                
                if (! sizeof(items))
                {
                        write("\nĿǰû�п��޸���Ŀ��\n\n");
                        
                        write("��ѯ��ϡ�\n");
                        write_prompt(me);
                        return;
                }
                
                msg = "Ŀǰ����Ŀ�У�\n\n";
                
                for (i = 0; i < sizeof(items); i++)
                {
                        msg += WHT + (i+1) + NOR "��" + items[i] + "\n";
                }
                write(msg);
                write("\n�������޸ľɵĲ�����Ŀ��\n");
                write("��������Ҫ�޸ĵ���Ŀ���ƣ�");
                input_to("get_name", me);
                return;
        case "c": 
        case "C": 
                users = keys(user_data);
                
                write("������鿴���Ͷע�����\n");
                
                if (! sizeof(users))
                {
                        write("\nĿǰû���κ����Ͷע��\n\n");
                        
                        write("��ѯ��ϡ�\n");
                        write_prompt(me);
                        return;
                }
                
                write("ĿǰͶע������У�\n\n");
                msg = WHT "";
                
                for (i = 0; i < sizeof(users); i++ )
                {
                        msg += sprintf("%10s", users[i]);
                        j++;
                        if (! (j % 5)) msg += "\n";
                }
                write(msg + NOR);
                write("\n\nһ���� " WHT + i + NOR " ������Ѿ�Ͷע��\n");
                write("\n��ѡ�������鿴����ң�");
                input_to("get_user", me);
                return;
        case "d": 
        case "D": 
                write("��������һ��������Ŀ��\n");
                
                items = keys(item_data);
                // �������Ѿ�ֹͣ����Ŀ����
                items = filter_array(items, (: query_status($1) == OPENING :));
                
                if (! sizeof(items))
                {
                        write("\nĿǰû�п��޸���Ŀ��\n\n");
                        
                        write("��ѯ��ϡ�\n");
                        write_prompt(me);
                        return;
                }
                
                msg = "Ŀǰ����Ŀ�У�\n\n";
                
                for (i = 0; i < sizeof(items); i++)
                {
                        msg += WHT + (i+1) + NOR "��" + items[i] + "\n";
                }
                write(msg);
                write("\n��������Ҫ��������Ŀ���ƣ�");
                input_to("get_name_end", me);
                return;
        case "e": 
        case "E": 
                write("�����ɾ��һ��������Ŀ��\n");
                
                items = keys(item_data);
                
                if (! sizeof(items))
                {
                        write("\nĿǰû�п��޸���Ŀ��\n\n");
                        
                        write("��ѯ��ϡ�\n");
                        write_prompt(me);
                        return;
                }

                msg = "Ŀǰ����Ŀ�У�\n\n";
                
                for (i = 0; i < sizeof(items); i++)
                {
                        msg += WHT + (i+1) + NOR "��" + items[i] + "\n";
                }
                write(msg);
                write("\n��������Ҫɾ������Ŀ��ţ�");
                input_to("get_name_todel", me);
                return;
        default: 
                end_manage();
                return;
        }
        
}

// ѡ��������Ŀ����
private void get_name(string arg, object me)
{
        string *teams, msg = "", team;
        int i, num;
        mapping item;
        
        if (arg == "")
        {
                end_manage();
                return;
        }
        // �޸ľ���Ŀ
        if (mapp(item_data[arg]) && sizeof(item_data[arg]) >= 5)
        {
                teams = keys(item_data[arg]["subject"]);
                
                for (i = 0; i < sizeof(teams); i++)
                {
                        team = teams[i];
                        msg += sprintf("%10s��" WHT "1 : %d\n" NOR , team, item_data[arg]["subject"][team]);
                }
                
                change_status(arg, INITING);
                write("\n1�����ƣ�" WHT + arg + NOR "\n"
                      "2��������\n\n" WHT + sort_msg(item_data[arg]["long"]) + NOR "\n\n"
                      "3������ʱ�䣺" WHT + CHINESE_D->chinese_time(5, ctime(item_data[arg]["end_time"])) + 
                      (item_data[arg]["end_time"] > time() ? "" : HIR "(�ѽ���)") + NOR "\n"
                      "4����Ͷע������" WHT + item_data[arg]["number"] + " ��\n" NOR 
                      "5����СͶע����" WHT + item_data[arg]["min_money"] + " ���ƽ�\n" NOR 
                      "6�����鼰���ʣ�\n\n" + msg + "\n" );
                write("��ѡ����Ҫ�޸ĵ���Ŀ��");
                input_to("select_change_type", me, arg);
                return;
        }
        else if (sscanf(arg, "%d", num) == 1  &&
                 mapp(item = item_data[keys(item_data)[num - 1]]) && sizeof(item) >= 5)
        {
                teams = keys(item["subject"]);
                arg = keys(item_data)[num - 1];
                
                for (i = 0; i < sizeof(teams); i++)
                {
                        team = teams[i];
                        msg += sprintf("%10s��" WHT "1 : %d\n" NOR , team, item["subject"][team]);
                }
                
                change_status(arg, INITING);
                write("\n1�����ƣ�" WHT + arg + NOR "\n"
                      "2��������\n\n" WHT + sort_msg(item["long"]) + NOR "\n\n"
                      "3������ʱ�䣺" WHT + CHINESE_D->chinese_time(5, ctime(item["end_time"])) +  
                      (item["end_time"] > time() ? "" : HIR "(�ѽ���)") + NOR "\n"
                      "4����Ͷע������" WHT + item["number"] + " ��\n" NOR 
                      "5����СͶע����" WHT + item["min_money"] + " ���ƽ�\n" NOR
                      "6�����鼰���ʣ�\n\n" + msg + "\n" );
                write("��ѡ����Ҫ�޸ĵ���Ŀ��");
                input_to("select_change_type", me, arg);
                return;
        }
        // ��������Ŀ
        else
        {
                item_data[arg] = ([ ]);
                change_status(arg, INITING);
                save();
                write("\n��������Ŀ����ϸ������\n");
                me->edit((: call_other, __FILE__, "get_long", me, arg :));
                return;
        }
}

private void select_change_type(string arg, object me, string name)
{
        switch (arg)
        {
        case "1":
                write("\n������޸������Ŀ�����ơ�\n");
                write("�����ĳ�ʲô�أ�");
                input_to("change_name", me, name);
                return;
        case "2":
                write("\n������޸������Ŀ�ĳ�������\n");
                write("�����ĳ�ʲô�أ�");
                me->edit((: call_other, __FILE__, "change_long", me, name :));
                return; 
        case "3": 
                write("\n������޸������Ŀ�Ľ���ʱ�䡣\n");
                write("�����Ŀ���ڶ�����������");
                input_to("change_date", me, name);
                return; 
        case "4": 
                write("\n������޸������Ŀ�Ŀ�Ͷע��������\n");
                write("�����Ŀ�����Ͷע������Ϊ��");
                input_to("change_number", me, name);
                return; 
        case "5": 
                write("\n������޸������Ŀ����СͶע����\n");
                write("�����ĳɶ����أ�");
                input_to("change_money", me, name);
                return;
        case "6": 
                write("\n������޸������Ŀ�Ķ������ݡ�\n");
                write("��Ҫ��ô�޸ģ�[" WHT "1" NOR "���޸� " WHT "2" NOR "��ɾ��]");
                input_to("change_team_type", me, name);
                return;
        default: 
                change_status(name, OPENING);
                write("\n��������޸ġ�\n\n");
                write("�޸���ϡ�\n");
                write_prompt(me);
                return;
        }
}

// �޸���Ŀ������
private void change_name(string arg, object me, string name)
{
        mapping item;
        
        if (arg == "")
        {
                change_status(name, OPENING);
                end_manage();
                return;
        }
        if (mapp(item_data[arg]))
        {
                change_status(name, OPENING);
                write("\n����һ���Ѵ��ڵ���Ŀ���������޸ġ�\n\n");
                write("��ص��˲��ʹ��������档\n");
                write_prompt(me);
                return;
        }
        item = item_data[name];
        item_data[arg] = item;
        map_delete(item_data, name);
        change_status(arg, OPENING);
        save();
        
        log_file("gamble", sprintf("%s change the item %s's name to %s on %s.\n", me->query("id"),
                           name, arg, ctime(time())));

        write("\n��Ŀ " WHT + name + NOR + " �������Ѿ����ɹ���Ϊ�� " WHT + arg + NOR + "��\n\n");
        write("�޸���ϣ���ص��˹���ϵͳ�����档\n");
        write_prompt(me);
        return;
}

// ������Ŀ�ĳ�����
private void change_long(object me, string arg, string long)
{
        if (long == "")
        {
                change_status(arg, OPENING);
                end_manage();
                return;
        }

        item_data[arg]["long"] = replace_string(long, "\n", "");
        change_status(arg, OPENING);
        save();
                
        write("\n��Ŀ" WHT + arg + NOR "�������Ѿ����ɹ���Ϊ��\n " WHT + sort_msg(long) + NOR "\n\n");
        write("�޸���ϣ���ص��˹���ϵͳ�����档\n");
        write_prompt(me);
        return;
}

private void change_date(string arg, object me, string name)
{
        int day, time;
        
        if (arg == "")
        {
                change_status(name, OPENING);
                end_manage();
                return;
        }
        
        if (! sscanf(arg, "%d", day) || day <= 0)
        {
                write("\n�Ƿ��ĸ�ʽ�����������롣\n\n");
                
                write("���������Ŀ���ڶ���������Ͷע��[��ʽ��" WHT "5" NOR "]");
                input_to("change_date", me, name);
                return;
        }
        
        time = time() + 86400 * day;       
        item_data[name]["end_time"] = time;
        change_status(name, OPENING);
        save();
                
        write("\n��Ŀ" WHT + name + NOR "�Ľ���ʱ���Ѿ����ɹ���Ϊ�� " WHT + chinese_number(day) + NOR " �����ҽ�����\n\n");
        write("�޸���ϣ���ص��˹���ϵͳ�����档\n");
        write_prompt(me);
        return;
}

private void change_number(string arg, object me, string name)
{
        int number;
        
        if (arg == "")
        {
                change_status(name, OPENING);       
                end_manage();
                return;
        }
        
        if (! sscanf(arg, "%d", number) || number <= 0)
        {
                write("\n�Ƿ��ĸ�ʽ�����������롣\n\n");
                
                write("�������������ѡ��Ķ�����Ŀ��");
                input_to("change_number", me, name);
                return;
        }
        
        item_data[name]["number"] = number;
        change_status(name, OPENING);
        save();
        
        write("\n��Ŀ " WHT + name + NOR + " ��Ͷע�������Ѿ����ɹ���Ϊ�� " WHT + chinese_number(number) + NOR + "����\n\n");
        write("�޸���ϣ���ص��˹���ϵͳ�����档\n");
        write_prompt(me);
        return;
}

private void change_money(string arg, object me, string name)
{
        int money;
        
        if (arg == "")
        {
                change_status(name, OPENING);
                end_manage();
                return;
        }
        
        if (! sscanf(arg, "%d", money) || money <= 0)
        {
                write("\n�Ƿ��ĸ�ʽ�����������롣\n\n");
                
                write("��������Ŀ������Ͷע�ƽ�����[��ʽ��" WHT "10000" NOR "]");
                input_to("get_least_money", me, name);
                return;
        }
        
        item_data[name]["min_money"] = money;
        change_status(name, OPENING);
        save();

        write("\n��Ŀ " WHT + name + NOR + " ����СͶע���Ѿ����ɹ���Ϊ�� " WHT + chinese_number(money) + NOR + "��\n\n");
        write("�޸���ϣ���ص��˹���ϵͳ�����档\n");
        write_prompt(me);
        return;
}

// ѡ���޸Ķ������������
private void change_team_type(string arg, object me, string name)
{
        if (arg == "")
        {
                change_status(name, OPENING);
                end_manage();
                return;
        }
        if (arg == "1")
        {
                write("\n������޸���Ŀ" + name + "�Ķ������ݡ�\n");
                input_to("change_team_info", me, name);
                return;
        }
        else 
        {
                write("\n�����ɾ����Ŀ" + name + "��һ���������ݡ�\n");
                input_to("del_team_info", me, name);
                return;
        }
}

// ������Ŀ�ĳ�����
private void get_long(object me, string arg, string long)
{
        if (long == "")
        {
                end_manage();
                return;
        }

        item_data[arg]["long"] = replace_string(long, "\n", "");
        save();
        
        write("\n��������Ŀ�����Ķ�����Ŀ��");
        input_to("get_team_number", me, arg);
        
        return;
}

// ������Ŀ�Ķ�����
private void get_team_number(string arg, object me, string name)
{
        int times;
        
        if (arg == "")
        {
                end_manage();
                return;
        }
        
        sscanf(arg, "%d", times);
        
        if (times > 20 || times <= 0)
        {
                write("�Բ��������Ŀ�ǲ��Ϸ��ġ�\n");
                
                write("��������Ŀ�����Ķ�����Ŀ��");
                input_to("get_team_number", me, name);
                
                return;
        }
        
        // ��ʼ������ӳ��
        item_data[name]["subject"] = ([ ]);
        save();
        
        write("\n�������һ����������Ƽ�����[��ʽ��" WHT "�й���:30" NOR "]��");
        input_to("get_team_info", me, name, times);
        
        return;
}

// �������һ���������Ϣ
private void get_team_info(string arg, object me, string name, int times)
{
        string team;
        int bonus;
        
        if (arg == "")
        {
                end_manage();
                return;
        }
        
        if (sscanf(arg, "%s:%d", team, bonus) != 2)
        {
                write("��ʽ�������������롣\n");
                write("�������һ����������Ƽ�����[��ʽ��" WHT "�й���:30" NOR "]��");
                input_to("get_team_info", me, name, times);
        
                return;
        }
        
        // ��ֹ�����ظ�����
        if (item_data[name]["subject"][team])
        {
                write("��������Ѿ�������ˡ�\n");
                write("��������һ����������Ƽ�����[��ʽ��" WHT "�й���:30" NOR "]��");
                input_to("get_team_info", me, name, times);
        
                return;
        }
        
        item_data[name]["subject"][team] = bonus; 
        
        // ������еĶ��鶼��������
        if (times == sizeof(item_data[name]["subject"]))
        {
                write("\n���������Ŀ���ڶ���������Ͷע��[��ʽ��" WHT "5" NOR "]");
                input_to("get_date_off", me, name);
                return;
        }
        
        write("Ŀǰ��ʣ�£�" + (times - sizeof(item_data[name]["subject"])) + "���ӡ�\n");
        
        item_data[name]["subject"][team] = bonus;
        save();
        
        write("\n��������һ����������Ƽ�����[��ʽ��" WHT "�й���:30" NOR "]��");
        input_to("get_team_info", me, name, times);
        
        return;
}

// ���������ʱ��
private void get_date_off(string arg, object me, string name)
{
        int day, time;
        
        if (arg == "")
        {
                end_manage();
                return;
        }
        
        if (! sscanf(arg, "%d", day) || day <= 0)
        {
                write("\n�Ƿ��ĸ�ʽ�����������롣\n\n");
                
                write("���������Ŀ���ڶ���������Ͷע��[��ʽ��" WHT "5" NOR "]");
                input_to("get_date_off", me, name);
                return;
        }
        
        time = time() + 86400 * day;
        
        item_data[name]["end_time"] = time;
        save();
        
        write("\n��Ŀ" WHT + name + NOR "���� " WHT + CHINESE_D->chinese_time(5, ctime(time)) +
              NOR " ���ҽ�����\n\n");
              
        write("��������Ŀ������Ͷע�ƽ�����[��ʽ��" WHT "10000" NOR "]");
        input_to("get_least_money", me, name);
        return;
}

// ��������Ͷע��
private void get_least_money(string arg, object me, string name)
{
        int money;
        
        if (arg == "")
        {
                end_manage();
                return;
        }
        
        if (! sscanf(arg, "%d", money) || money <= 0)
        {
                write("\n�Ƿ��ĸ�ʽ�����������롣\n\n");
                
                write("��������Ŀ������Ͷע�ƽ�����[��ʽ��" WHT "10000" NOR "]");
                input_to("get_least_money", me, name);
                return;
        }
        
        item_data[name]["min_money"] = money;
        save();
        
        write("\n��Ŀ" WHT + name + NOR "����СͶע���� " WHT + money +
              NOR " ���ƽ�\n\n");
        
        write("�������������ѡ��Ķ�����Ŀ��");
        input_to("get_chip_number", me, name);
        return;
}

// �����������ѡ��Ķ�����Ŀ
private void get_chip_number(string arg, object me, string name)
{
        int number;
        
        if (arg == "")
        {
                end_manage();
                return;
        }
        
        if (! sscanf(arg, "%d", number) 
            || number <= 0
            || number >= sizeof(item_data[name]["subject"]))
        {
                write("\n�Ƿ��ĸ�ʽ�����������롣\n\n");
                
                write("�������������ѡ��Ķ�����Ŀ��");
                input_to("get_chip_number", me, name);
                return;
        }
        
        item_data[name]["number"] = number;
        save();
        
        write("��Ŀ" WHT + name + NOR "�������ѡ��Ķ�����Ŀ�� " WHT + chinese_number(number) +
              NOR " ����\n\n");
              
        // ȫ�����ݱ༭���
        change_status(name, OPENING);
        save();
        
        log_file("gamble", sprintf("%s create a gamble item called %s on %s.\n", me->query("id"),
                           name, ctime(time())));

        write("ȫ�����ݱ༭������ϡ�\n");
        
        write("��ص��Ĺ���ϵͳ�����档\n"); 
        write_prompt(me);        
        return;
}

// ɾ��һ����Ŀ
private void get_name_todel(string arg, object me)
{
        int number;
        string *names;
        
        if (arg == "")
        {
                end_manage();
                return;
        }
        
        if (! sscanf(arg, "%d", number) || number <= 0)
        {
                write("\n�Ƿ��ĸ�ʽ�����������롣\n\n");
                
                write("��������Ҫɾ������Ŀ��ţ�");
                input_to("get_name_todel", me);
                return;
        }
        
        names = keys(item_data);
        if (! mapp(item_data[names[number - 1]]))
        {
                write("\nû�������Ŀ��\n\n");
                
                write("��������Ҫɾ������Ŀ��ţ�");
                input_to("get_name_todel", me);
                return;
        }
        
        write("��Ŀ" WHT + names[number - 1] + NOR "���ɹ�ɾ���ˡ�\n\n");
        map_delete(item_data, names[number - 1]);
        log_file("gamble", sprintf("%s delete a gamble item called %s on %s.\n", me->query("id"),
                           names[number - 1], ctime(time())));
        save();
        
        write("��ص��Ĺ���ϵͳ�����档\n"); 
        write_prompt(me);        
        return;
}

// ���Ͷע����
public void do_chip(object me)
{
        string *items = keys(item_data);
        string msg = "Ŀǰ����Ͷע����Ŀ�У�\n\n";
        int i;
        
        write(HIW "��������������������������������������������������������\n" NOR);
        write("\t\t  ��" HIW + MUD_NAME + "���ʹ�˾" NOR "��\n\n");
        
        if (! sizeof(items))
        {
                write("û�пɹ���ע����Ŀ��\n");
                write(HIW "��������������������������������������������������������\n" NOR);
                return;
        }
        
        for (i = 0; i < sizeof(items); i++)
        {
                // ���û�п���
                if (query_status(items[i]) != OPENING)
                        continue;
                msg += WHT + (i+1) + NOR "��" + items[i] + "\n";
        }
        write(msg);
        write("\n��ѡ����Ҫ���벩�ʵ���Ŀ[" WHT "Enter" NOR " �˳�]��");
        input_to("select_name_tochip", me);
        
        return;
}

// ѡ��Ͷע����Ŀ
private void select_name_tochip(string arg, object me)
{
        string name, *teams, msg = "";
        int i;
        mapping item;
        string id = me->query("id");
                
        if (arg == "")
        {
                write("\n�������Ͷע��\n");
                write(HIW "����������������������������������������������������\n" NOR);
                return;
        }

        if (! sscanf(arg, "%d", i) || i <= 0)
        {
                write("\n�㷢���ˣ���ô���ܻ��������Ŀ��\n");
                write("��ѡ����Ҫ���벩�ʵ���Ŀ[" WHT "Enter" NOR " �˳�]��");
                input_to("select_name_tochip", me);
        
                return;
        }
        
        name = keys(item_data)[i - 1];
        
        if (! mapp(item = item_data[name]))
        {
                write("\nû���գ���ȷʵû�������Ŀѽ��\n");
                write("��ѡ����Ҫ���벩�ʵ���Ŀ[" WHT "Enter" NOR " �˳�]��");
                input_to("select_name_tochip", me);
        
                return;
        }
 
        if (mapp(user_data[id]) &&
            sizeof(user_data[id][name]) >= 2)
        {
                teams = user_data[id][name]["team"];
                for (i = 0; i < sizeof(teams); i++)
                {
                        msg += sprintf("%10s��" WHT "1 : %d\n" NOR , teams[i], item["subject"][teams[i]]);
                }                
                write("\n�����Ŀ�㲻���Ѿ�Ͷע���𣿿ɲ��ܷ���Ŷ��\n");
                write("\n1�����ƣ�" WHT + name + NOR "\n"
                        "2��������\n\n" WHT + sort_msg(item["long"]) + NOR "\n\n"
                        "3������ʱ�䣺" WHT + CHINESE_D->chinese_time(5, ctime(item["end_time"])) + 
                        (item["end_time"] > time() ? "" : HIR "(�ѽ���)") + NOR "\n"
                        "4����Ͷע������" WHT + item["number"] + " ��\n" NOR 
                        "5����Ͷע�ƽ�" WHT + user_data[id][name]["money"] + " ���ƽ�\n" NOR
                        "6�����鼰���ʣ�\n\n" + msg + "\n" );

                write("��ѡ����Ҫ���벩�ʵ���Ŀ[" WHT "Enter" NOR " �˳�]��");
                input_to("select_name_tochip", me);
                return; 
        }
                
        if (item["status"] != OPENING)
        {
                write("\n�����Ŀ��û���Ż������Ѿ�ֹͣ�ˣ��㻹�ǻ�һ���ɡ�\n");
                write("��ѡ����Ҫ���벩�ʵ���Ŀ[" WHT "Enter" NOR " �˳�]��");
                input_to("select_name_tochip", me);
        
                return;
        }
        
        /*
        // Ͷע�Ƿֿ���һ��һ�ӵ�Ͷ
        if (mapp(user_data[id]) && 
            arrayp(teams = user_data[id][name]["team"]) && 
            sizeof(teams) >= item_data[name]["number"])
        {
                write("����ע�Ķ����Ѿ�������ˡ�\n");
                return;
        }
        */                  
        
        teams = keys(item["subject"]);
                
        for (i = 0; i < sizeof(teams); i++)
        {
                msg += sprintf("%10s��" WHT "1 : %d\n" NOR , teams[i], item["subject"][teams[i]]);
        }

        write("\n1�����ƣ�" WHT + name + NOR "\n"
                        "2��������\n\n" WHT + sort_msg(item["long"]) + NOR "\n\n"
                        "3������ʱ�䣺" WHT + CHINESE_D->chinese_time(5, ctime(item["end_time"])) + 
                        (item["end_time"] > time() ? "" : HIR "(�ѽ���)") + NOR "\n"
                        "4����Ͷע������" WHT + item["number"] + " ��\n" NOR 
                        "5����СͶע����" WHT + item["min_money"] + " ���ƽ�\n" NOR
                        "6�����鼰���ʣ�\n\n" + msg + "\n" );

        write("��������ҪͶע�Ķ���[����á�" WHT "," NOR "������]��");

        input_to("select_team_tochip", me, name);

        return;
}

// ѡ��Ͷע�Ķ���
protected void select_team_tochip(string arg, object me, string name)
{
        string *teams, *all_teams;
        int i, n;
        
        if (arg == "")
        {
                write("\n�������Ͷע��\n");
                write(HIW "����������������������������������������������������\n" NOR);
                return;
        }

        if (! item_data[name])
        {
                write(name + "\n");
                write("Non data.\n");
                return;
        }

        if (! arrayp(teams = explode(arg, ",")) ||
            ! n = sizeof(teams))
        {
                write("\n�����ʽ�������������롣\n");
                write("��������ҪͶע�Ķ���[����á�" WHT "," NOR "������]��");
                input_to("select_team_tochip", me, name);
                return;
        }
        
        all_teams = keys(item_data[name]["subject"]);
        if (n != item_data[name]["number"])
        {
                write("\n����Ķ�����Ŀ�����ϡ�\n");
                write("������������ҪͶע�Ķ���[����á�" WHT "," NOR "������]��");
                input_to("select_team_tochip", me, name);
                return;
        }
        
        for (i = 0; i < n; i++)
        {
                if (member_array(teams[i], all_teams) == -1)
                {
                        write("\n������鲻���������Ŀ��\n");
                        write("������������ҪͶע�Ķ���[����á�" WHT "," NOR "������]��");
                        input_to("select_team_tochip", me, name);
                        return;
                }
        }
        
        user_data += ([ me->query("id") : ([ name : ([ "team" : teams ]) ]) ]);
        
        write("\n��ѡ����ע�Ķ�����" WHT + implode(teams, NOR "��" WHT) + NOR + "��\n\n");
        write("\n��������Ҫ��ע�Ļƽ�");
        input_to("get_money_tochip", me, name);
        
        return;
}

protected void get_money_tochip(string arg, object me, string name)
{
        string id;
        int money;
        
        if (arg == "")
        {
                end_manage();
                return;
        }
        
        if (! sscanf(arg, "%d", money) || money <= 0)
        {
                write("\n�Ƿ��ĸ�ʽ�����������롣\n\n");
                
                write("����������Ͷע�ƽ�����[��ʽ��" WHT "10000" NOR "]");
                input_to("get_money_tochip", me, name);
                return;
        }
        
        id = me->query("id");
        
        if (count_lt(money, item_data[name]["min_money"]))
        {
                write("������Ҫ��ע" + chinese_number(item_data[name]["min_money"]) + "���ƽ�ɡ�\n");
                input_to("get_money_tochip", me, name);
                return;
        }
        
        if (count_le(me->query("balance"), count_mul(money, 10000)))
        {
                write("\n�����еĴ�����㣬���������롣\n\n");                                 
                write("����������Ͷע�ƽ�����[��ʽ��" WHT "10000" NOR "]");
                input_to("get_money_tochip", me, name);
                return;
        }
        
        me->set("balance", count_sub(me->query("balance"), count_mul(money, 10000)));
        user_data[id][name] += ([ "money" : money ]);                               
        save();
        
        write("Ͷע�ɹ���\n");
        return;
}

// ѡ���ѯ�����
private void get_user(string arg, object me)
{
        mapping user;
        
        if (arg == "")
        {
                end_manage();
                return;
        }
        if (! mapp(user = user_data[arg]))
        {
                write("û�����Ͷע�û���\n");
                write("��ѡ�������鿴����ң�");
                input_to("get_user", me);
                return;
        }
        write("�û� " + WHT + arg + NOR " �μ�Ͷע����Ŀ�У�\n\n" WHT + implode(keys(user), NOR "/" WHT) + NOR "\n");
        
        write("\n��ѡ�����鿴����Ŀ��");
        input_to("get_user_info", me, arg);
        
        return;
}

// �����ҵľ�����Ϣ
private void get_user_info(string arg, object me, string id)
{
        mapping user;
        
        if (arg == "")
        {
                end_manage();
                return;
        }
        if (! mapp(user = user_data[id][arg]))
        {
                write("û�������Ŀ��\n");
                write("��ѡ�����鿴����Ŀ��");
                input_to("get_user_info", me, arg);
                return;
        }
        write("\nͶע�ߣ�" + WHT + id + NOR + "\n");
        write("��Ŀ����" + WHT + arg + NOR + "\n");
        write("Ͷע����" + WHT + user_data[id][arg]["money"] + NOR " ���ƽ�" + NOR + "\n");
        write("Ͷע���飺" WHT + implode(user_data[id][arg]["team"], NOR " & " WHT) + NOR + "\n\n");
        
        write("��ѯ��ϣ���ص��Ĺ���ϵͳ�����档\n"); 
        write_prompt(me); 
        return;
}

private void get_name_end(string arg, object me)
{
        if (arg == "")
        {
                end_manage();
                return;
        }
              
        change_status(arg, STOPPED);        
        write("�޸���ϣ���ص��Ĺ���ϵͳ�����档\n"); 
        write_prompt(me); 
        return;
}

// �ı���Ŀ��״̬
public void change_status(string name, string status)
{
        if (mapp(item_data[name]))
        {
                item_data[name]["status"] = status;
                save();
                return;
        }
        else return;
}

// ��ѯ��Ŀ��״̬
public string query_status(string name)
{
        if (! stringp(name) || name == ""
            || ! mapp(item_data[name]))
        {
                return INITING;
        }
        else
        {
                return item_data[name]["status"];
        }
}

// ����һ����Ŀ����(�Թ������ݵ���)
public mapping query_item(string name)
{
        if (mapp(item_data[name]))
                return item_data[name];
}

// �����������ݿ�
varargs public mapping query_data(int raw)
{
        if (raw)
                return user_data;
        return item_data;
}
