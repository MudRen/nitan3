// Created by Smallfish For HUAXIA@2004    2004/04/24

#include <ansi.h>

mapping sword_obj = ([
        "/d/yanziwu/npc/obj/changjian":30,            //���졢����
        "/d/xiangyang/npc/obj/mujian":5,              //ľ������
        "/d/xiakedao/obj/baihongjian":5,              //���͵�ʯ��
        "/d/wudang/quest/obj/ghost_sword":10,         //�䵱����֦
        "/d/wanjiegu/npc/obj/tie-gan":35,             //������
        "/d/village/obj/zhujian":5,                   //���������⡢���͵������⡢����С�����䵱������
        "/d/village/npc/obj/youlong":35,              //������
        "/d/tulong/tulong/obj/ling1":32,              //����ʹ
        "/d/tulong/obj/yitianjian":35,                //����
        "/d/tulong/obj/duan1":0,                      //���˵����콣
        "/d/taohua/obj/yuxiao":35,                    //��ҩʦ
        "/d/taohua/obj/taojian":18,                   //�һ���������
        "/d/shaolin/obj/zhujian":18,                  //���ֱ�����
        "/d/shaolin/obj/changjian":10,                //����һЩ���С�������ʦ��ȡ
        "/d/quanzhou/pig/obj/cleansword":1,           //��ʱ�޴���ȡ
        "/d/quanzhou/obj/xiuhua":5,                   //���ƹ���
        "/d/quanzhou/npc/obj/xiuhua":1,               //��ʱ�޴���ȡ
        "/d/quanzhen/npc/obj/gangjian":22,            //ȫ���������书���佫��������
        "/d/mingjiao/obj/changjian":1,                //��ʱ�޴���ȡ
        "/d/meizhuang/obj/sea-wood":32,               //����СԺ
        "/d/meizhuang/obj/qin":1,                     //��ʱ�޴���ȡ
        "/d/jinshe/obj/jinshe-jian":32,               //���߶�
        "/d/huashan/obj/longquan":30,                 //��ɽ����
        "/d/huashan/npc/obj/green_water_sword":35,    //����ɺ
        "/d/heimuya/obj/yuxiao":35,                   //��������
        "/d/heimuya/npc/obj/zhen":1,                  //��ʱ�޴���ȡ
        "/d/heimuya/npc/obj/changjian":30,            //ɣ�����ӯӯ
        "/d/hangzhou/honghua/obj/shortsword":35,      //����ͩ
        "/d/gumu/npc/obj/shunvjian":35,               //С��Ů
        "/d/gumu/npc/obj/junzijian":35,               //С��Ů
        "/d/fuzhou/obj/xiuhua":5,                     //�ܶ�
        "/d/fuzhou/npc/obj/xiuhua":1,                 //��ʱ�޴���ȡ
        "/d/emei/obj/zhujian":25,                     //���Ҵ����
        "/d/emei/obj/skysword":1,                     //��ʱ�޴���ȡ
        "/d/emei/obj/ruanjian":35,                    //����ʦ̫
        "/d/city/obj/gangjian":18,                    //������ʿ��������
        "/d/city/obj/duanjian":12,                    //�൱��
        "/d/city/obj/changjian":10,                   //�൱��
        "/d/city/obj/branch1":18,                     //�߹�
        "/d/city/obj/branch":18,                      //�߹�
        "/d/city/npc/obj/gangjian":10,                //�൱��
        "/d/city/npc/obj/duanjian":1,                 //��ʱ�޴���ȡ
        "/d/city/npc/obj/changjian":15,               //���񻷡����ᡢʷ������÷ׯ��Ժ
        "/d/changan/npc/obj/sword":12,                //Ⱥ��¥���ڡ�����»
        "/d/changan/npc/obj/changjian":10,            //Ľ�ݺ����佫
        "/d/beijing/npc/obj/sword5":20,               //�����ٱ�
        "/d/beijing/npc/obj/sword4":15,               //�����ٱ������Ŷ��졢��ǰ����������Ӫ�������ſ��ꡢ������
        "/d/beijing/npc/obj/sword3":35,               //������
        "/d/beijing/npc/obj/sword2":20,               //��ɮ
        "/d/beijing/npc/obj/sword1":30,               //�����
        "/d/beijing/npc/obj/bishou":35,               //����
        "/d/beijing/npc/obj/baojian":1,               //��ʱ�޴���ȡ
        "/clone/weapon/zhujian":5,                    //�ܶ�
        "/clone/weapon/xiyang-sword":10,              //�ձ����
        "/clone/weapon/green_sword":35,               //������
        "/clone/weapon/gangjian":5,                   //�ܶ�
        "/clone/weapon/duanjian":1,                   //��ʱ�޴���ȡ
        "/clone/weapon/changjian":5,                  //�ܶ�
        "/clone/book/shenghuo-ling":35,               //���޼�
        "/kungfu/class/dali/obj/tiedi":35,            //����̩
]);

int check_value(string filename)
{
        if (undefinedp(sword_obj[filename])) return 0;
        return sword_obj[filename];
}
