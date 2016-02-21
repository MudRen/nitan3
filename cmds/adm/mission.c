// by Lonely(06/20/2002) 

#include <ansi.h>
inherit F_CLEAN_UP;

int check_mission(string mission, object me);
int main(object me, string arg)
{
        int i, flag = 0;
        string mission, wname, wmin, file;
        string *wmission;
        
        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        if(! arg || sscanf(arg, "%s %s", arg, mission) != 2)
                return notify_fail("ָ���ʽ��mission <ʹ����> (Ŀǰ����)\n");

        if (member_array(arg, SECURITY_D->query_wizlist()) == -1)
                return notify_fail("��������ʦ��\n");

        if (! check_mission(mission, me)) 
                return 1;

        mission = trans_color(mission, 1);
        mission = filter_color(mission);

        file = read_file("/adm/etc/wizmission");
        
        if (file)
                wmission = explode(file, "\n");
        else
                wmission = ({ });
        for(i = 0; i < sizeof(wmission); i++)
        {
                if(wmission[i][0] == '#' || 
                   sscanf(wmission[i], "%s %s", wname, wmin) !=2)
                        continue;
                if(wname == arg)
                {
                        wmission[i] = sprintf("%s %s\n", wname, mission);
                        flag = 1;
                        break;
                }
        }
        for(file = "", i = 0; i < sizeof(wmission); i++)
                file += wmission[i] + "\n";
        if(! flag)
                write_file("/adm/etc/wizmission", arg + " " + mission + "\n", 0);
        else
                write_file("/adm/etc/wizmission", file, 1);
        message_vision("$N�� " HIW + arg + NOR " �Ĺ��������Ϊ " HIW + mission + NOR " ��\n", me);
        return 1;
}

int check_mission(string mission, object me)
{
        int i;
        i = strlen(mission);

        if ((strlen(mission) < 4) || (strlen(mission) > 20)) 
        {
                tell_object(me, "�����붨�ڶ���ʮ���֡�\n");
                return 0;
        }

        /*
        while (i--) 
        {
                if (mission[i]<=' ') 
                {
                        tell_object(me, "�Բ��������в����ÿ����ַ���\n");
                        return 0;
                }
                if (i%2 == 0 && ! is_chinese(mission[i..<0])) 
                {
                        tell_object(me, "���á����ġ��涨����\n");
                        return 0;
                }
        }
        */
        return 1;
}
        
int help(object me)
{
        write(@HELP
ָ���ʽ : mission <ĳ��> (Ŀǰ����)
�����ı���ʦ��ǰ���������˵�������� wizlist ʹ�á�
HELP
        );
        return 1;
}


