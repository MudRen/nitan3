// Created by Smallfish For HUAXIA@2004    2004/04/24

#include <ansi.h>

mapping head_obj = ([
        "/d/yanziwu/npc/obj/necklace":30,             //���졢����
        "/d/xueshan/obj/sengmao":10,                  //ɮñ
        "/d/xueshan/obj/rtlian":34,                   //����
        "/d/xueshan/obj/klguan":34,                   //����
        "/d/xiakedao/obj/xuantie":1,                  //���͵�һ������
        "/d/xiakedao/obj/lingpai1":1,                 //���͵�һ������
        "/d/xiakedao/obj/lingpai":1,                  //���͵�һ������
        "/d/wanjiegu/npc/obj/xiu-scarf":33,           //����
        "/d/wanjiegu/npc/obj/scarf":1,                //��ʱ�޴���ȡ
        "/d/wanjiegu/npc/obj/hat":1,                  //��ʱ�޴���ȡ
        "/d/taohuacun/obj/rose":1,                    //��ʱ�޴���ȡ
        "/d/taohua/obj/shudai":30,                    //���ء���ܽ
        "/d/taohua/obj/jindai":1,                     //��ʱ�޴���ȡ
        "/d/shenlong/obj/sg_mianzhao":1,              //��ʱ�޴���ȡ
        "/d/shaolin/obj/weibo":22,                    //������ʦ
        "/d/shaolin/obj/toukui":22,                   //������ʦ
        "/d/mingjiao/obj/weibo":1,                    //��ʱ�޴���ȡ
        "/d/mingjiao/obj/toukui":1,                   //��ʱ�޴���ȡ
        "/d/heimuya/npc/obj/zhenzhu":33,              //�Ϲ���
        "/d/hangzhou/npc/obj/xuannv-lingfu":9,        //ٻ��
        "/d/hangzhou/npc/obj/tongxin-jie":9,          //ٻ��
        "/d/hangzhou/npc/obj/sansheng-youyue":15,     //ٻ��
        "/d/hangzhou/npc/obj/huangtong-suo":9,        //ٻ��
        "/d/hangzhou/honghua/obj/cuiyu":33,           //����ͩ
        "/d/foshan/obj/hua3":25,                      //��ɽ�ּ��
        "/d/foshan/obj/hua2":25,                      //��ɽ�ּ��
        "/d/foshan/obj/hua1":25,                      //��ɽ�ּ��
        "/d/dali/obj/chahua9":25,                     //�軨԰
        "/d/dali/obj/chahua8":25,                     //�軨԰
        "/d/dali/obj/chahua7":25,                     //�軨԰
        "/d/dali/obj/chahua6":25,                     //�軨԰
        "/d/dali/obj/chahua5":25,                     //�軨԰
        "/d/dali/obj/chahua4":25,                     //�軨԰
        "/d/dali/obj/chahua3":25,                     //�軨԰
        "/d/dali/obj/chahua2":25,                     //�軨԰
        "/d/dali/obj/chahua13":25,                    //�軨԰
        "/d/dali/obj/chahua12":25,                    //�軨԰
        "/d/dali/obj/chahua11":25,                    //�軨԰
        "/d/dali/obj/chahua10":25,                    //�軨԰
        "/d/dali/obj/chahua1":25,                     //�軨԰
        "/d/dali/npc/obj/ttoujin":22,                 //̨�����֣���������̨���̷������������������
        "/d/dali/npc/obj/lace":36,                    //����˾
        "/d/city/obj/yrose":5,                        //����������
        "/d/city/obj/toukui":1,                       //��ʱ�޴���ȡ
        "/d/city/obj/rrose":5,                        //����������
        "/d/city/obj/necklace":8,                     //�°��Ź���С��
        "/d/city/obj/cycle":1,                        //��ʱ�޴���ȡ
        "/d/city/npc/obj/toukui":5,                   //���������������˹���
        "/d/city/npc/obj/necklace":30,                //��ݺݺ������
        "/d/city/npc/obj/cycle":5,                    //���������������˹���
        "/d/city/npc/cloth/xiu-scarf":5,              //���Ṻ��
        "/d/city/npc/cloth/scarf":5,                  //���Ṻ��
        "/d/city/npc/cloth/hat":5,                    //���Ṻ��
        "/d/changan/npc/obj/zi-luolan":5,             //�������ﹺ��
        "/d/changan/npc/obj/yupei":36,                //��Ա��
        "/d/changan/npc/obj/neck":9,                  //�𸴻�����
        "/d/changan/npc/obj/lan-tiane":5,             //�������ﹺ��
        "/d/changan/npc/obj/huang-meigui":5,          //�������ﹺ��
        "/d/changan/npc/obj/hong-meigui":5,           //�������ﹺ��
        "/d/changan/npc/obj/hei-mudan":5,             //�������ﹺ��
        "/d/changan/npc/obj/bai-chahua":5,            //�������ﹺ��
        "/d/beijing/npc/obj/hat":36,                  //������Ů
        "/clone/gift/mjade":27000,
        "/clone/gift/mdiamond":27000,
        "/clone/gift/mcrystal":27000,
        "/clone/gift/magate":27000,
        "/clone/gift/fjade":9000,
        "/clone/gift/fdiamond":9000,
        "/clone/gift/fcrystal":9000,
        "/clone/gift/fagate":9000,
        "/clone/gift/diamond":3000,
        "/clone/gift/crystal":3000,
        "/clone/gift/jade":3000,
        "/clone/gift/agate":3000,
        "/clone/gift/cjade":1000,
        "/clone/gift/cdiamond":1000,
        "/clone/gift/ccrystal":1000,
        "/clone/gift/cagate":1000,
]);

int check_value(string filename)
{
        if (undefinedp(head_obj[filename])) return 0;
        return head_obj[filename];
}
