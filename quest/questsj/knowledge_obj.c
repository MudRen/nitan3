// Created by Smallfish For HUAXIA@2004    2004/04/24

#include <ansi.h>

mapping knowledge_obj = ([
        "/d/xueshan/obj/fojing2":36,                  //ѩɽ����
        "/d/xiaoyao/obj/lbook4":1,                    //��ʱ�޴���ȡ
        "/d/xiaoyao/npc/obj/lbook4":1,                //��ʱ�޴���ȡ
        "/d/shaolin/obj/fojing21":30,                 //���ֲؾ�¥
        "/d/shaolin/obj/fojing20":30,                 //���ֲؾ�¥
        "/d/shaolin/obj/fojing11":30,                 //���ֲؾ�¥
        "/d/shaolin/obj/fojing10":30,                 //���ֲؾ�¥
        "/d/quanzhen/npc/obj/daodejing-ii":30,        //�����������־��
        "/d/quanzhen/npc/obj/daodejing-i":33,         //�ƾ�����
        "/d/emei/obj/fojing21":28,                    //���Ҳؾ��󡢶��Ҳؾ�¥
        "/d/emei/obj/fojing20":28,                    //���Ҳؾ��󡢶��Ҳؾ�¥
        "/d/emei/obj/fojing11":28,                    //���Ҳؾ��󡢶��Ҳؾ�¥
        "/d/emei/obj/fojing10":28,                    //���Ҳؾ��󡢶��Ҳؾ�¥
        "/d/emei/obj/fojing":33,                      //���ʦ̫
        "/d/city/npc/obj/lbook3":1,                   //��ʱ�޴���ȡ
        "/d/changan/npc/obj/book":40,                 //��Ա��
        "/clone/book/zhengpu":36,                     //ŷ����
        "/clone/book/yljing2":1,                      //��ʱ�޴���ȡ
        "/clone/book/yljing1":1,                      //��ʱ�޴���ȡ
        "/clone/book/yljing":1,                       //��ʱ�޴���ȡ
        "/clone/book/yijing3":30,                     //�һ����鷿
        "/clone/book/yijing2":30,                     //�һ����鷿
        "/clone/book/yijing1":30,                     //�һ����鷿
        "/clone/book/yijing0":30,                     //�һ����鷿
        "/clone/book/xiaopu":36,                      //��ҩʦ
        "/clone/book/taohua":36,                      //��ҩʦ
        "/clone/book/qin":36,                         //�����
        "/clone/book/mizong_book":33,                 //ѩɽ�ؾ���
        "/clone/book/lbook4":33,                      //����
        "/clone/book/lbook3":18,                      //���乺��
        "/clone/book/lbook2":10,                      //���乺��
        "/clone/book/lbook1":7,                       //���乺��
        "/clone/book/laozi8":28,                      //�䵱�ؾ���ȫ��ؾ���
        "/clone/book/laozi2":28,                      //�䵱�ؾ���ȫ��ؾ���
        "/clone/book/laozi18":28,                     //�䵱�ؾ���ȫ��ؾ���
        "/clone/book/laozi16":28,                     //�䵱�ؾ���ȫ��ؾ���
        "/clone/book/laozi13":28,                     //�䵱�ؾ���ȫ��ؾ���
        "/clone/book/laozi1":28,                      //�䵱�ؾ���ȫ��ؾ���
        "/clone/book/daodejing":1,                    //��ʱ�޴���ȡ
        "/clone/book/daodejing-ii":33,                //�������
        "/clone/book/daodejing-i":26,                 //����������䵱�ؾ���ȫ��ؾ���
        "/clone/book/book-paper":26,                  //����С�ݡ������ٻ�ʩˮ�󡢹���
        "/clone/book/bagua1":30,                      //�һ����鷿
        "/clone/book/bagua0":30,                      //�һ����鷿
]);

int check_value(string filename)
{
        if (undefinedp(knowledge_obj[filename])) return 0;
        return knowledge_obj[filename];
}
