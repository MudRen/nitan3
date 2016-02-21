// quest.c

#include <ansi.h>
 
int main(object me, string arg)
{
        int status = me->query("to_pvp/status");
        string str, master = me->query("family/master_name");

        if( !me->query("to_pvp") )
                return 0;

        if( !status )
        {
                if( me->query("to_pvp/time") < time() )
                {
                        me->delete("to_pvp");
                        return notify_fail(master+"��̾�������ѵ������о�û������ɱ������������������");
                }
                if( arg == "cancel" )
                {
                        me->delete("to_pvp");
                        return notify_fail(master+"ŭ�������ߣ�������˵�С֮�ˣ����ܳɴ�����������\n");
                }
                if( arg == "ok" )
                {
                        me->set("to_pvp/status",1);
                        me->set("to_pvp/time",time() + 600);
                        return notify_fail("��ŭ���������д�����˶����������������ڴ����ϣ�����ȥɱ�˴������汾�ɳ�������\n");
                }
                str =  sprintf("�㽫Ҫ����ȥɱ�ı��ų��%s(%s)��\n", 
                        me->query("to_pvp/name"), me->query("to_pvp/id"));
                str += sprintf("�㻹��%s���������������\n",
                        CHINESE_D->chinese_number(me->query("to_pvp/time") - time()));
                str += "�����Ҫ�������������롰qt ok��\n";
                write(str);
                return 1;
        }
        else
        {
                if( me->query("to_pvp/time") < time() )
                {
                        me->delete("to_pvp");
                        return notify_fail(master+"����ɱ��С������Ȼ������ô�õ�ʱ�仹ûɱ�����ҿ�Ҳ���������ˣ�����Һúõ�ѧ�հɣ����������ˣ��ߣ�������");
                }
                str =  sprintf("��Ҫɱ�ı��ų����%s(%s)��\n", 
                        me->query("to_pvp/name"), me->query("to_pvp/id"));
                str += sprintf("����Ҫ��%sǰ������������\n",
                        CHINESE_D->chinese_date(me->query("to_pvp/time")));
                write(str);
                return 1;
        }
        return 0;
}

