// Created by Smallfish For HUAXIA@2004    2004/04/24

#include <ansi.h>

mapping miji_obj = ([
        "/d/yanziwu/obj/dodgebook":30,                //������
        "/d/gaibang/obj/staff_book":33,               //���о�
        "/d/changan/npc/obj/book_unarmed":7,          //���
        "/d/changan/npc/obj/book_blade":7,            //���
        "/clone/book/zixia_book":1,                   //��ʱ�޴���ȡ
        "/clone/book/zijin_book":33,                  //ͯ����
        "/clone/book/zihui-book":33,                  //Ľ�ݲ�
        "/clone/book/zhemei_book2":30,                //��������
        "/clone/book/zhemei_book1":30,                //��������
        "/clone/book/zhanyi":30,                      //Ѫ����
        "/clone/book/zhangfapu":33,                   //�ﲻ��
        "/clone/book/yunvjing2":30,                   //�ֳ�Ӣ
        "/clone/book/yunvjing1":30,                   //С��Ů
        "/clone/book/yunu_book":30,                   //��ɽ����
        "/clone/book/yljianpu":1,                     //��ʱ�޴���ȡ
        "/clone/book/yljian":1,                       //��ʱ�޴���ȡ
        "/clone/book/ylbian":1,                       //��ʱ�޴���ȡ
        "/clone/book/yijinjing":33,                   //������
        "/clone/book/xx-book":30,                     //÷ׯ�η�
        "/clone/book/xuanfeng_book":30,               //��ҩʦ
        "/clone/book/wuji4":33,                       //���ֲؾ�¥��¥
        "/clone/book/wuji3":30,                       //���ֲؾ�¥��¥
        "/clone/book/wuji2":30,                       //���ֲؾ�¥��¥
        "/clone/book/wuji1":30,                       //���ֲؾ�¥��¥
        "/clone/book/throw_book":33,                  //ժ����
        "/clone/book/sword_book2":30,                 //��ɽ�鷿
        "/clone/book/sword_book":33,                  //��С��
        "/clone/book/sun_book":1,                     //��ʱ�޴���ȡ
        "/clone/book/strike_book":33,                 //����
        "/clone/book/staff_book":33,                  //ؤ�����ң����������ڵأ�
        "/clone/book/skin":28,                        //ѩɽ�ؾ���
        "/clone/book/six_book":33,                    //������ʦ
        "/clone/book/shoufa":36,                      //½����
        "/clone/book/shenghuo-ling":33,               //���޼�
        "/clone/book/qunxing-tu":1,                   //��ʱ�޴���ȡ
        "/clone/book/quanpu":1,                       //��ʱ�޴���ȡ
        "/clone/book/qijianpu":30,                    //��������
        "/clone/book/qiankun_book":30,                //��������
        "/clone/book/pixie_book":60,                  //��ɽɽ��
        "/clone/book/parry_book":7,                   //����ϰ幺��
        "/clone/book/liuyang_book2":30,               //��������
        "/clone/book/liuyang_book1":30,               //��������
        "/clone/book/jiuyin2":30,                     //��Ĺ��������ҩʦ
        "/clone/book/jiuyin1":30,                     //��Ĺ����
        "/clone/book/jiuyang-book":33,                //���عȵ�
        "/clone/book/jinyantu":33,                    //����
        "/clone/book/jinshe3":26,                     //��ɽɽ��
        "/clone/book/jinshe2":26,                     //��ɽɽ��
        "/clone/book/jinshe1":26,                     //��ɽɽ��
        "/clone/book/hujia-book":33,                  //���
        "/clone/book/hand_book":33,                   //������
        "/clone/book/force_book":30,                  //��Զ��
        "/clone/book/dujing_2":30,                    //������
        "/clone/book/douzhuan-book":30,               //Ľ�ݲ�
        "/clone/book/bufa":36,                        //½����
        "/clone/book/book-stone":20,                  //���ֱ��֡�������С�ݡ����͵��鷿��ѩɽ�ؾ��������ٻ�ʩˮ��
        "/clone/book/book-silk":26,                   //���ִ��۱�����͵��鷿��ѩɽ�ؾ��������ٻ�ʩˮ��
        "/clone/book/book-iron":18,                   //����ɮ������С�ݡ����͵��鷿��ѩɽ�ؾ��������ٻ�ʩˮ��
        "/clone/book/book-bamboo":18,                 //��Ħ��������С�ݡ����͵��鷿��ѩɽ�ؾ��������ٻ�ʩˮ��
        "/clone/book/bojuan":1,                       //��ʱ�޴���ȡ
        "/clone/book/blade-book":36,                  //���
        "/clone/book/18niou":30,                      //������
        "/clone/book/18muou":30,                      //������
]);

int check_value(string filename)
{
        if (undefinedp(miji_obj[filename])) return 0;
        return miji_obj[filename];
}
