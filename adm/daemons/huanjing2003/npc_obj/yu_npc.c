//                ��׼��������ʾ��                                   |
// �þ���Ϸ��NPC  ��֮���ȵ�NPC
// by naihe  2002-10-26  ��ï��

#include <ansi.h>

inherit NPC;

string *songs1=({
    "ʱ���Ѿ�Զȥ",
    "ֻ�м�����ǻ�",
    "�Ի���Զ�纣ʯ����",
    "����ȥ�Ĺ���  �����͵�̾Ϣ",
    "���ֺ����ܹ�����׷�ǣ�",
    "������ö���",
    "�纣����˼֮��",
    "��������������������ĵط�",
    "���ǵĹ���",
    "������Զ��֮ʱ��  ��֮����",
});

string *songs2=({
    "���ض����ϵĹ���",
    "������������  һֱ����",
    "�����Ƿ���˵��",
    "��֮���ȵĹ��£�����",
    "ңԶ�����  �����ĸ���ʢ�Ĺ���",
    "���Ƿִ��ڴ�ص��ķ�",
    "��֮�����ܹ���������ɰ���",
    "��֮���������ޱȵ�ǿ׳����",
    "��֮�������Ͷ����ģ��Ƹ�����",
    "����֮���ȡ������������������",
    "Ҳ�����������������˹�â��",
    "���ǵľ���  ������",
    "�����ǻ������ܼ�",
    "�����ػ��纣����",
    "��������鲼���",
    "���������ɶ��ϲԡ�",
    "�װ������Ѱ�",
    "���Ը����Ѱ��ʧȴ�ı���",
    "����ʰ��Զȥ���ȵ�",
    "����֮�⣿",
});

string me_guodu,ask_arg,baowu_name,baowu_dir,baowu_other1,baowu_other2,
me_guodu=""MAG"��֮����"NOR"",baowu_name="��Ө֮��",baowu_other1="����֮��",
baowu_other2="����֮��",ask_arg=baowu_name,baowu_dir=__DIR__"yu_obj";

string *me_mark=({"yu","mh xin","lq shou"});

#include "fyld_npc.h"