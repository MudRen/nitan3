// checkquest.c
// Smallfish@Huaxia

#include <ansi.h>
 
inherit F_CLEAN_UP;
string time_period(int timep);

int main(object who, string arg)
{
        object me,ob;
        mapping q,quest;
        string master,msg;
        int tag_fam = 0;
        int flag_zs = 0;
        int flag_bh = 0;

        if (! SECURITY_D->valid_grant(who, "(wizard)"))
                return 0;

        if (!arg) return notify_fail("ָ���ʽ��checkquest <ID>\n");
        if (!(me = find_player(arg))) return notify_fail(arg + "����˲������߰���\n");

        write(HIY + "������" + HIW + me->name(1) + "(" + me->query("id") + ")" + NOR + "\n\n");

        write(HIR + "�������ϵͳ��\n" + NOR);
        if (me->query_temp("finish_bunch_times"))
                write(sprintf("ͷ����������������Ѿ���������� %d ����\n",
                       me->query_temp("finish_bunch_times")));

        msg = "";
    	 if(mapp(quest = me->query("bunch_quest")))
	 {
                flag_bh = 1;
                msg = quest["type"] + "��" + quest["msg"];
                write("��ղ��������\n"+msg+"\n");
	 }

        if (!flag_bh) write("��Ŀǰû�дӰ�����������\n");

        write(HIR + "\n��������ϵͳ��\n" + NOR);
        if (me->query("quest_count"))
                write(sprintf("ʦ����������������Ѿ���������� %d ����\n",
                       me->query("quest_count")));
 
        if (mapp(q =  me->query("quest")))
        {
	         switch (q["type"])
                { 
        	  case "kill":
              	  write(q["master_name"] + "�Ը�����" + CHINESE_D->chinese_monthday(q["limit"]) +
                      "֮ǰ����" HIR + q["name"] + NOR "����ͷ����" + q["family"] + "���\n" +
                      "��˵����ǰ����������" + q["place"] + "��û��\n");
                      tag_fam = 1;
                      break;
                case "letter":
                      write(q["master_name"] + "�Ը�����" + CHINESE_D->chinese_monthday(q["limit"]) +
                      "֮ǰ���ż��͵�" HIC + q["name"] + NOR "���У�ȡ��ִ���\n" +
                      "���Ų���ǰ����������" + q["place"] + "��\n");
                      tag_fam = 1;
                      break;
                }
        }
        if (!tag_fam) write("������û�����κ���������\n");
        
        write(HIR + "\n��ʦ����ϵͳ��\n" + NOR);

	 if(me->query_temp("questdg_times"))
    	         write("������ܽ��������������������� "+me->query_temp("questdg_times")+" ���ˡ�\n");
	 if(me->query_temp("questkh_times"))
    	         write("����̫�ཻ�������������������� "+me->query_temp("questkh_times")+" ���ˡ�\n");
        if(me->query_temp("questsn_times"))
    	         write("�Ϻ����ύ�������������������� "+me->query_temp("questsn_times")+" ���ˡ�\n");;
        if(me->query_temp("quesths_times"))
	         write("���ѽ��������������������� "+me->query_temp("quesths_times")+" ���ˡ�\n");

        msg = "";
        // �������
	 if(mapp(quest = me->query("quest_dg")))
	 {
                flag_zs = 1;
                msg = quest["dgmsg"];
                write("��ղ��������"+msg+"\n");
	 }

	 msg = "";
        // ��������
        if(mapp(quest = me->query("quest_kh")))
	 {
                flag_zs = 1;
	      	  msg = quest["khmsg"];
                if (quest["desc"] == "��")
         	          if(quest["time"] < time())
         	 	           msg += "\n���Ѿ������˹涨ʱ���ˣ�";
         	 	   else
   	      		           msg += "\n�㻹��"+time_period(quest["time"]-time())+"��ʱ�䡣";
                write("��ղ��������"+msg+"\n");
	 }

        msg = "";
        // ����
	 if(mapp(quest = me->query("quest_hs")))
	 {
                flag_zs = 1;
                msg = quest["msg"];
                if (quest["type"] == "��")
                {
         	 	           msg += "\n���Ѿ������" + quest["ok"] + "����";
   	      		           msg += "\n�㻹��Ҫ��" + (quest["want"] - quest["ok"]) + "����";
                }
                write("��ղ��������"+msg+"\n");
	 }

        msg = "";
        // �Ϻ�����
	 if(mapp(quest = me->query("quest_sn")))
	 {
                flag_zs = 1;
                msg = quest["msg"];
                if (quest["type"] == "��")
                {
         	 	           msg += "\n���Ѿ������" + quest["ok"] + "����";
   	      		           msg += "\n�㻹��Ҫ��" + (quest["want"] - quest["ok"]) + "����";
                }
                write("��ղ��������"+msg+"\n");
	 }

	if (!flag_zs) write("��Ŀǰû�д��κ���ʦ���������\n");
        return 1;
}

string time_period(int timep)
{
   int t, d, h, m, s;
   string time;
   t = timep;
   s = t % 60;             t /= 60;
   m = t % 60;             t /= 60;
   h = t % 24;             t /= 24;
   d = t;
 
   if(d) time = chinese_number(d) + "��";
   else time = "";
 
   if(h) time += chinese_number(h) + "Сʱ";
   if(m) time += chinese_number(m) + "��";
   time += chinese_number(s) + "��";
   return time;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : checkquest  <ID>
���ָ�����������ѯĳ����Ҵ��������ɵ����Ż�
���ҳ�����ȡ�����Լ�����ʦ������ȡ������

HELP );
        return 1;
}
