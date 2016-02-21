// ��������ػ����̣�defend.c

#include <ansi.h>

#define MAX_NUM         15

void startup();
void start_quest();

string *familys = ({ 
        "�䵱��", "��ɽ����", "ȫ���", "��Ĺ��",
        "���չ�", "�һ���", "�������", "���ϻ���", 
        "������", "ؤ��", "������", "��ң��", 
        "����", "��ɽ����","��������",
        "������", "Ѫ����", "������", "ŷ������", 
        "������", "Ľ������", "�������", });
        
// ������󴴽�
void create()
{
        seteuid(getuid());
        if (! clonep() && find_object(QUEST_D)) startup();
}

void heart_beat()
{
        if (! find_object(QUEST_D))
                return;

        // ������ԣ�ÿ������(4����)����һ��QUEST
        start_quest();
}


// �����ػ����̻����������
void startup()
{
        // ����
        if (! find_object(QUEST_D))
                return;

        if (! query_heart_beat())
                CHANNEL_D->do_channel(find_object(QUEST_D),
                                      "sys", "����(DEFEND)�����ˡ�");

        // ƽ��ÿ�ķ��Ӳ���һ������
        set_heart_beat(110 + random(10));
}

// ֹͣ����������
void stop()
{
        set_heart_beat(0);
}

void start_quest()
{
       // int i, num; 
       int num;
        object *users;          // Ŀǰ���������������
        object *obs;            // Ŀǰ���е�DEFEND����
        string family_name;     // ����������������
        object qob;             // �������

        // �������п��ܱ���������ɣ�ȥ��Ŀǰ������ģ�
        obs = children("/clone/quest/defend");
        if (arrayp(obs) && sizeof(obs) > 0)
                familys -= obs->query("quest_dfamily");

        // ѡȡһ����ǰ׼�����������
        if (sizeof(familys) < 1)
                return;               
                
        family_name = familys[random(sizeof(familys))];
        
        // ��ȡ��������������ݵ�ʱ��������������������
        users = filter_array(users(), (: interactive($1) 
                                         && stringp($1->query("family/family_name")) 
                                         && $1->query("family/family_name") == $(family_name) :));
                                         /* 
                                         && mapp($1->query_temp("defend_quest"))
                                         && ! $1->query_temp("defend_quest/finish") :));
                                         */
        // ����Ϊ��������������� 1-2 ��
        num = sizeof(users) * (2 + random(2));
        
        // �����������������������ֹ��ɽ��Ұ�ĵ��ˣ�
        if (num > MAX_NUM) num = MAX_NUM;
        // ���һ�����Ҳ���
        if (num <= 0) return;
        
        // ��ʼ�������һЩ��Ϣ�������ص㣩
        qob = new("/clone/quest/defend");
        qob->set("quest_dfamily", family_name);

        CHANNEL_D->do_channel(find_object(QUEST_D),
                              "sys", "����(DEFEND)��" + family_name +
                              HIR "����" + num + HIR "�����˴�����һ������");

        // ���������Լ����г�ʼ��
        qob->init_quest(num, family_name);
}

