// Created by Smallfish For HUAXIA@2004    2004/04/24

#include <ansi.h>

mapping staff_obj = ([
        "/d/xueshan/obj/senggun":18,                  //ѩɽ����ɮ�������ײ�
        "/d/xueshan/obj/mugun":22,                    //ѩɽ�ⷿ
        "/d/xueshan/obj/fachu":25,                    //ѩɽ��������ĸ���
        "/d/xiangyang/npc/obj/mugun":5,               //����ľ������
        "/d/village/npc/obj/stick":5,                 //����С��������С�����书��С��
        "/d/tulong/yitian/npc/obj/tiezhang":20,       //��ɮ
        "/d/tulong/yitian/npc/obj/spear":10,          //�ɹŹٱ�����ʮ�����
        "/d/tulong/tulong/npc/obj/flag":25,           //����ɽ�����ĸ�����
        "/d/shaolin/obj/qimeigun":16,                 //�μš����顢�۽����ߡ��������ߡ�������ʦ��Ҫ
        "/d/shaolin/obj/chanzhang":12,                //���Ʋֹ�ʦ�����𡢳������ۿ����ߡ��������ߡ����Ѵ�ʦ��������ʦ��Ҫ
        "/d/quanzhou/npc/obj/huoqiang":35,            //��ë��
        "/d/quanzhen/npc/obj/stick":5,                //ȫ��С��
        "/d/mingjiao/obj/qimeigun":35,                //�Ų���
        "/d/mingjiao/obj/langyabang":30,              //�⾢�ݡ�ׯ�
        "/d/mingjiao/obj/chanzhang":1,                //��ʱ�޴���ȡ
        "/d/huanghe/npc/obj/tieqiao":30,              //��ʯ�ˣ�������
        "/d/huanghe/npc/obj/fork":35,                 //��ͨ��
        "/d/heimuya/npc/obj/shutonggun":32,           //�ų˷硢�ų���
        "/d/heimuya/npc/obj/leizhendang":35,          //�Ժ�
        "/d/heimuya/npc/obj/gangzhang":35,            //�Ϲ���
        "/d/hangzhou/obj/shuzhi":15,                  //����ɽ·�����ݻ���ɽ���ƺ�����
        "/d/hangzhou/honghua/obj/tiejiang":30,        //���ĸ���ɳͨ��
        "/d/guiyun/npc/obj/gancheng":35,              //ȫ��
        "/d/guiyun/npc/obj/biandan":8,                //��ϣ�ʡ������Ṻ��
        "/d/foshan/obj/shuzhi":18,                    //��ɽ�ּ��
        "/d/city/obj/zhubang":5,                      //�����ּ�С�ݡ�����С���������͵�������
        "/d/city/obj/shuzhi":10,                      //�ö�ط�����
        "/d/city/obj/branch4":16,                     //�߹�
        "/d/city/obj/branch3":16,                     //�߹�
        "/d/city/obj/branch2":16,                     //�߹�
        "/d/city/npc/obj/zhubang":1,                  //��ʱ�޴���ȡ
        "/d/changan/npc/obj/shawei":22,               //�������ۣ��ĸ���
        "/d/changan/npc/obj/gangzhang":1,             //��ʱ�޴���ȡ
        "/d/baituo/obj/shezhang":25,                  //���������⡢ŷ����
        "/d/baituo/obj/lingshezhang":10,              //��ŷ����Ҫ�����޶��
        "/d/baituo/npc/obj/shezhang":1,               //��ʱ�޴���ȡ
        "/clone/weapon/zhubang":10,                   //�������Խ�̨��������
        "/clone/weapon/xiangmo-chu":35,               //�����
        "/clone/weapon/tiegun":5,                     //��������
        "/clone/weapon/qimeigun":1,                   //��ʱ�޴���ȡ
        "/clone/weapon/gshezhang":1,                  //��ʱ�޴���ȡ
        "/clone/weapon/gshezhan":15,                  //��ŷ����Ҫ
        "/clone/weapon/gangzhang":15,                 //�ܶ����NPC����
        "/clone/weapon/changqiang":12,                //�Ƚ϶�
        "/clone/misc/bone":5,                         //�˹�ͷ
        "/kungfu/class/gaibang/yuzhu_zhang":35,       //���߹�
        "/kungfu/class/gaibang/obj/yuzhu_zhang":1,    //��ʱ�޴���ȡ
        "/kungfu/class/dali/obj/diaogan":35,          //������
]);

int check_value(string filename)
{
        if (undefinedp(staff_obj[filename])) return 0;
        return staff_obj[filename];
}
