// Created by Smallfish For HUAXIA@2004    2004/04/24

#include <ansi.h>

mapping hammer_obj = ([
        "/d/xueshan/obj/yinlun":1,            //��ʱ�޴���ȡ
        "/d/xueshan/obj/lubo":36,             //����
        "/d/xueshan/obj/jinlun":1,            //��ʱ�޴���ȡ
        "/d/xueshan/obj/falun":20,            //ѩɽ�ⷿ���������֮��
        "/d/xueshan/obj/faling":18,           //��������(�ĸ�)������
        "/d/xingxiu/obj/yaochu":26,           //��ũ���ӡ���ҩ�ˣ�������
        "/d/xiakedao/obj/zhutou":1,           //���͵���һ������
        "/d/xiakedao/obj/forleg":1,           //���͵���һ������
        "/d/xiakedao/obj/backleg":1,          //���͵���һ������
        "/d/xiakedao/npc/obj/jitui":1,        //���͵���һ������
        "/d/wudang/obj/shitou":20,            //�䵱С·
        "/d/wanjiegu/npc/obj/muyu":34,        //��ü��ʦ
        "/d/village/npc/obj/hothammer":33,    //������
        "/d/village/npc/obj/hammer":5,        //����������
        "/d/tulong/yitian/npc/obj/tongbo":18, //��ɮ
        "/d/tulong/tulong/obj/stone":5,       //��̲
        "/d/tulong/tulong/npc/obj/hammer":36, //������
        "/d/shaolin/obj/muchui":25,           //���ֶ��������
        "/d/quanzhen/npc/obj/jitui":5,        //����
        "/d/mingjiao/obj/shigu":22,           //���̲��������
        "/d/mingjiao/obj/mutang":22,          //ɽ������������������ʿ�ĸ�
        "/d/heimuya/obj/zijinchui":1,         //��ʱ�޴���ȡ
        "/d/heimuya/npc/obj/zijinchui":33,    //ͯ����
        "/d/hangzhou/obj/shitou":20,          //���ݱ�ʯɽ
        "/d/guanwai/npc/obj/tongren":33,      //��һ��
        "/d/guanwai/npc/obj/tiepipa":33,      //������
        "/d/foshan/obj/shikuai":12,           //��ɽ�ּ��
        "/d/dali/npc/obj/yaoqin":30,          //�����Ů��������
        "/d/city3/npc/obj/jitui":5,           //���Թ���
        "/d/city/obj/stone":20,               //�߹�
        "/d/city/obj/shitou":15,              //���ݳ�������
        "/d/city/obj/jitui":5,                //���Թ���
        "/d/city/obj/hammer":1,               //��ʱ�޴���ȡ
        "/d/city/obj/bone":26,                //��ͽֱ�
        "/d/city/npc/obj/jitui":5,            //���Թ���
        "/d/city/npc/obj/hammer":1,           //��ʱ�޴���ȡ
        "/d/changan/npc/obj/jitui":5,         //���Թ���
        "/d/changan/npc/obj/hammer":26,       //Ľ�ݺ����ź⡢��Ⱥ
        "/d/beijing/npc/obj/hammer":25,       //��������
        "/clone/weapon/hammer":5,             //�ܶ�
        "/clone/weapon/falun":5,              //�ܶ�
        "/clone/food/jitui":5,                //���Թ���
]);

int check_value(string filename)
{
        if (undefinedp(hammer_obj[filename])) return 0;
        return hammer_obj[filename];
}
