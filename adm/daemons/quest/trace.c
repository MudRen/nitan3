// ��������ػ����̣�trace.c

#include <ansi.h>

void startup();

// ������󴴽�
void create()
{
        seteuid(getuid());
        if (! clonep() && find_object(QUEST_D)) startup();
}

void start_quest()
{
        object qob;

        if (sizeof(children("/clone/quest/trace")) > 20)
                // ϵͳ�����8��Ѱ�����������
                return;

        qob = new("/clone/quest/trace");
        qob->init_quest();
        CHANNEL_D->do_channel(find_object(QUEST_D),
                              "sys", "����(TRACE)"
                              HIR "������һ������");
}

void heart_beat()
{
        if (! find_object(QUEST_D))
                return;

        // ������ԣ�ÿ����������һ��QUEST
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
                                      "sys", "����(TRACE)�����ˡ�");

        // ƽ��ÿ�ķ��Ӳ���һ������
        set_heart_beat(10 + random(10));
}

// ֹͣ����������
void stop()
{
        set_heart_beat(0);
}
