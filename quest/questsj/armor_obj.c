// Created by Smallfish For HUAXIA@2004    2004/04/24

#include <ansi.h>

mapping armor_obj = ([
        "/d/yanziwu/npc/obj/goldring":30,     //���졢����
        "/d/wanjiegu/npc/obj/jade-belt":1,    //��ʱ�޴���ȡ
        "/d/wanjiegu/npc/obj/belt":1,         //��ʱ�޴���ȡ
        "/d/tulong/yitian/npc/obj/gong":20,   //�������
        "/d/taohua/obj/ruanwei":30,           //���ء���ܽ
        "/d/shaolin/obj/zhitao":18,           //�������ġ�������ʦ��ȡ
        "/d/shaolin/obj/yaodai":1,            //��ʱ�޴���ȡ
        "/d/shaolin/obj/tieshou":26,          //����ɮ��һ��������
        "/d/shaolin/obj/shoutao":18,          //�������ġ�������ʦ��ȡ
        "/d/shaolin/obj/huyao":18,            //�������ġ�������ʦ��ȡ
        "/d/shaolin/obj/huwan":18,            //�������ġ�������ʦ��ȡ
        "/d/quanzhen/npc/obj/tiejia":22,      //ȫ���������书���佫��������
        "/d/mingjiao/obj/zhitao":1,           //��ʱ�޴���ȡ
        "/d/mingjiao/obj/yaodai":1,           //��ʱ�޴���ȡ
        "/d/mingjiao/obj/tieshou":1,          //��ʱ�޴���ȡ
        "/d/mingjiao/obj/shoutao":1,          //��ʱ�޴���ȡ
        "/d/mingjiao/obj/huyao":1,            //��ʱ�޴���ȡ
        "/d/mingjiao/obj/huwan":1,            //��ʱ�޴���ȡ
        "/d/heimuya/npc/obj/jin":36,          //��ӯӯ
        "/d/emei/obj/yaodai":33,              //���Ҵ����
        "/d/dali/npc/obj/tiejia":23,          //�����佫��һ�������
        "/d/city/obj/zhitao":1,               //��ʱ�޴���ȡ
        "/d/city/obj/tieshou":1,              //��ʱ�޴���ȡ
        "/d/city/obj/tiejia":1,               //��ʱ�޴���ȡ
        "/d/city/obj/surcoat":5,              //�ܶ�
        "/d/city/obj/shoutao":1,              //��ʱ�޴���ȡ
        "/d/city/obj/shield":1,               //��ʱ�޴���ȡ
        "/d/city/obj/huyao":1,                //��ʱ�޴���ȡ
        "/d/city/obj/huwan":1,                //��ʱ�޴���ȡ
        "/d/city/obj/goldring":8,             //���ݡ�Ȫ���ӻ��̳°��Ź���
        "/d/city/npc/obj/zhitao":10,          //���������������˹���
        "/d/city/npc/obj/tieshou":5,          //���������������˹���
        "/d/city/npc/obj/tiejia":5,           //�ܶ�
        "/d/city/npc/obj/surcoat":5,          //���������������˹���
        "/d/city/npc/obj/shoutao":1,          //���������������˹���
        "/d/city/npc/obj/shield":8,           //���������������˹���
        "/d/city/npc/obj/huyao":6,            //���������������˹���
        "/d/city/npc/obj/huwan":6,            //���������������˹���
        "/d/city/npc/obj/goldring":33,        //����
        "/d/city/npc/cloth/jade-belt":3,      //���Ṻ��
        "/d/city/npc/cloth/belt":8,           //���Ṻ��
        "/d/changan/npc/obj/zuanjie":18,      //���ϰ幺��
        "/d/changan/npc/obj/zhanjia":22,      //�в���
        "/d/changan/npc/obj/yinjie":7,        //���ϰ幺��
        "/d/changan/npc/obj/wrists":8,        //�𸴻�����
        "/d/changan/npc/obj/shield":7,        //����ʵ����
        "/d/changan/npc/obj/ring":6,          //�𸴻�����
        "/d/changan/npc/obj/jinjie":15,       //���ϰ幺��
        "/d/changan/npc/obj/baojie":15,       //���ϰ幺��
        "/d/changan/npc/obj/baijie":15,       //���ϰ幺��
        "/d/beijing/npc/obj/baojia":36,       //����
        "/clone/weapon/tiejia":1,             //��ʱ�޴���ȡ
        "/clone/cloth/yaodai":30,             //�¼��塢����ͬ
        "/clone/cloth/tiejia":5,              //�ܶ�
        "/clone/book/book-iron":18,           //����ɮ������С�ݡ����͵��鷿��ѩɽ�ؾ��������ٻ�ʩˮ��
]);

int check_value(string filename)
{
        if (undefinedp(armor_obj[filename])) return 0;
        return armor_obj[filename];
}
