// Created by Smallfish For HUAXIA@2004    2004/04/24

#include <ansi.h>

mapping blade_obj = ([
        "/d/xueshan/obj/xblade1":1,             //��ʱ�޴���ȡ
        "/d/xueshan/obj/xblade":30,             //Ѫ�����桢��������
        "/d/xiaoyao/obj/blade":25,              //��ң������
        "/d/xiaoyao/npc/obj/blade":30,          //��ң������
        "/d/xiangyang/npc/obj/mudao":5,         //ľ������
        "/d/xiakedao/obj/knife":5,              //���͵���һ������
        "/d/xiakedao/obj/gangdao":5,            //���͵���һ������
        "/d/shaolin/obj/mudao":25,              //����������
        "/d/shaolin/obj/jiedao":10,             //�ܶ�
        "/d/quanzhou/npc/obj/wodao":24,         //���ܣ�������
        "/d/quanzhen/npc/obj/gangdao":18,       //ȫ���������书��ٱ����ĸ���
        "/d/mingjiao/obj/jiedao":1,             //��ʱ�޴���ȡ
        "/d/mingjiao/obj/gangdao":1,            //��ʱ�޴���ȡ
        "/d/heimuya/npc/obj/dadao":25,          //�ֲ����Ʋ������Ϲ��ơ�ͯ����
        "/d/guiyun/npc/obj/jiandao":36,         //�Ű���
        "/d/guanwai/obj/lengyue":36,            //���
        "/d/guanwai/obj/cwbdao":40,             //���
        "/d/foshan/npc/obj/caidao":36,          //����ɩ
        "/d/dali/npc/obj/mandao":36,            //��������
        "/d/dali/npc/obj/kandao":26,            //�����ˣ��������������ˣ�������
        "/d/city/obj/gangdao":5,                //�ܶ�
        "/d/city/npc/obj/gangdao":5,            //�ܶ�
        "/d/changan/npc/obj/gangdao":5,         //�ܶ�
        "/d/changan/npc/obj/blade":5,           //�ܶ�
        "/d/beijing/npc/obj/blade3":10,         //�����ٱ����൱�ࣩ
        "/d/beijing/npc/obj/blade2":5,          //�������ͣ��ĸ����������У���������������
        "/d/beijing/npc/obj/blade1":5,          //�ܶ�
        "/d/baituo/obj/dadao":18,               //����ɽ�������������ɽ����һ��ɽ��ͷ
        "/d/baituo/obj/chaidao":30,             //�Է��ϲ�
        "/d/baituo/npc/obj/dadao":1,            //��ʱ�޴���ȡ
        "/d/baituo/npc/obj/chaidao":1,          //��ʱ�޴���ȡ
        "/clone/weapon/wandao":7,               //���Թ���:12������
        "/clone/weapon/tudao":8,                //���Թ���:20������
        "/clone/weapon/mudao":5,                //�ܶ�
        "/clone/weapon/jpn-dao":10,             //�ձ����
        "/clone/weapon/jiedao":1,               //��ʱ�޴���ȡ
        "/clone/weapon/gangdao":5,              //�ܶ�
        "/clone/weapon/dadao":36,               //����
        "/clone/weapon/blade":5,                //�ܶ�
]);

int check_value(string filename)
{
        if (undefinedp(blade_obj[filename])) return 0;
        return blade_obj[filename];
}
