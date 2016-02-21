// workd.c

/********************************************************
  ���������ػ�

����˫��ʹ�������� QUEST_D �Ĺ���������ƣ����еļ򵥹���
�����������������ִ�о��幤���� npc ���߷����ϣ����Ǳ���
�� /adm/daemons/work/ Ŀ¼���Ըù���Ӣ�������ĳ����У� ��
���ջ������Ϊ /adm/daemons/work/kezhan.c���������Է���ȫ
�ֵĹ����޸ĺͼ򻯵���(����ͬ�๤���Ͳ�Ҫ����һ�δ���)��

ϵͳ(globals.h)�ṩ�ĺ궨�壺

#define WORK_DIR     "/adm/daemons/work/"

WORK_D �ṩ�Ĳ��� API��

int    request_work(object who, object ob, string name);
string assign_work(object who, string name);
int    query_work(object who, string name);
int    start_work(object who, string name);
int    finish_work(object who, object ob, string name, mixed m);

WORK_OB �����ṩ�Ľӿڣ�

int    request_work(object me, object ob);
int    query_work(object who);
string assign_work(object who);
int    start_work(object me);
int    finish_work(object me, object ob);

********************************************************/

#include <ansi.h>

public int request_work(object who, object ob, string name)
{
        if (! playerp(who) || playerp(ob))
                return 0;

        if (! can_talk_with(ob, who))
                return 0;

        if (! file_size(WORK_DIR + name + ".c"))
                return 0;
                
        return (WORK_DIR + name + ".c")->request_work(who, ob);
}

public string assign_work(object who, string name)
{
        if (! playerp(who) || ! interactive(who))
                return 0;

        if (! file_size(WORK_DIR + name + ".c"))
                return 0;
                
        return (WORK_DIR + name + ".c")->assign_work(who);
}

public int query_work(object who, string name)
{
        if (! playerp(who) || ! interactive(who))
                return 0;

        if (! file_size(WORK_DIR + name + ".c"))
                return 0;
                
        return (WORK_DIR + name + ".c")->query_work(who);
}

public int start_work(object who, string name)
{
        if (! playerp(who) || ! interactive(who))
                return 0;

        if (! file_size(WORK_DIR + name + ".c"))
                return 0;
                
        return (WORK_DIR + name + ".c")->start_work(who);
}

public varargs int finish_work(object who, object ob, string name, mixed m)
{
        if (! playerp(who) || playerp(ob))
                return 0;

        if (! can_talk_with(ob, who))
                return 0;

        if (! file_size(WORK_DIR + name + ".c"))
                return 0;

        if (m)
                return (WORK_DIR + name + ".c")->finish_work(who, ob, m);
        else return (WORK_DIR + name + ".c")->finish_work(who, ob);
}

public string query_all_work()
{
        string *wlist;
        string info;
        string work;
        mixed *winfo;

        wlist = get_dir(WORK_DIR + "*.c");
        if (! arrayp(wlist) || ! sizeof(wlist))
                return "Ŀǰϵͳ��û���κι�����\n";

        info = HIC "Ŀǰϵͳ���� " HIW + sizeof(wlist) + HIC " �����\n" NOR
               HIW "������������������������������;��驤����߾��驤\n" NOR;
        foreach(work in wlist)
        {
                winfo = (WORK_DIR + work + ".c")->query_info();
                info += sprintf(WHT "%-10s" CYN " %-10d %-10d %-10d %-10d\n" NOR,
                                winfo[0], winfo[1], winfo[2], winfo[3], winfo[4]);
        }
        info += HIW "��������������������������������������������������" NOR;
        return info;
}
