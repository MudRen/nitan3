// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// sloughd.c ������̶Ұ��������ػ�����

#include <ansi.h>

#pragma optimize
#pragma save_binary

// �����ṩ���ⲿ���õĽӿں���
varargs public void   bonus(object who, mapping b, int flag);
public void   delay_bonus(object who, mapping b);

#define ONE_DAY                 (86400 / 365)
#define MAX_QUEST_LEVEL         3

mapping place = ([
        "��������": ({
                        "/d/beijing/cagc_e","/d/beijing/caroad_e1",
                        "/d/beijing/caroad_e2","/d/beijing/zahuo",
                        "/d/beijing/yancao","/d/beijing/xingchang",
                        "/d/beijing/wang_4","/d/beijing/chaoyang_dao1",
                        "/d/beijing/chaoyang_dao2","/d/beijing/chaoyangmen",
                        "/d/beijing/wang_6","/d/beijing/wang_8",
                        "/d/beijing/xiyuan","/d/beijing/xiyuanup",
                        "/d/beijing/wang_10","/d/beijing/wang_9",
                        "/d/beijing/wang_1","/d/beijing/wang_3",
                        "/d/beijing/wang_5","/d/beijing/wang_7",
                        "/d/beijing/wang_8","/d/beijing/quanjude",
                        "/d/beijing/quanjudeup","/d/beijing/dong_1",
                        "/d/beijing/dong_3","/d/beijing/dongchang_men",
                        "/d/beijing/dongchang","/d/beijing/xiaochang",
                        "/d/beijing/weifu_men","/d/beijing/weifu_zoulang1",
                        "/d/beijing/weifu_dayuan","/d/beijing/weifu_zoulang2",
                        "/d/beijing/weifu_dating","/d/beijing/weifu_shufang",
                        "/d/beijing/dong_2","/d/beijing/guozijian",
                        "/d/beijing/wang_2",
                     }),
        "��������" : ({
                        "/d/beijing/niaoshi","/d/beijing/xi_1",
                        "/d/beijing/caroad_w1","/d/beijing/yangliu1",
                        "/d/beijing/yangliu2","/d/beijing/yangliu3",
                        "/d/beijing/qingmu_men","/d/beijing/qingmu_dayuan",
                        "/d/beijing/qingmu_fang3","/d/beijing/qingmu_fang1",
                        "/d/beijing/caroad_w1","/d/beijing/caroad_w2",
                        "/d/beijing/cagc_w","/d/beijing/tiananmen",
                        "/d/beijing/cagc_s","/d/beijing/tianqiao",
                        "/d/beijing/yong_1","/d/beijing/duchang",
                        "/d/beijing/huiying","/d/beijing/huiyingup",
                        "/d/beijing/yong_2","/d/beijing/tiepu",
                        "/d/beijing/yong_3","/d/beijing/fu_2",
                        "/d/beijing/fukedian","/d/beijing/kediandayuan",
                        "/d/beijing/hai_men","/d/beijing/hai_dayuan",
                        "/d/beijing/hai_fang","/d/beijing/hai_huating",
                        "/d/beijing/hai_dating","/d/beijing/hai_houyuan",
                        "/d/beijing/mianguan","/d/beijing/fu_1",
                        "/d/beijing/tiantan_n","/d/beijing/tiantan",
                        "/d/beijing/yongdingdao","/d/beijing/yongdingmen",
                        "/d/beijing/qiao","/d/beijing/hgmen_s",
                        "/d/beijing/gaosheng","/d/beijing/xi_2",
                        "/d/beijing/huichuntang","/d/beijing/bei_2",
                        "/d/beijing/kangfu_men","/d/beijing/kangfu_dayuan",
                        "/d/beijing/kangfu_zoulang1","/d/beijing/kangfu_dating",
                        "/d/beijing/kangfu_zoulang2","/d/beijing/kangfu_xifang",
                        "/d/beijing/kangfu_dongfang","/d/beijing/kangfu_shufang",
                        "/d/beijing/bei_2","/d/beijing/bei_4",
                        "/d/beijing/di_1","/d/beijing/di_3",
                        "/d/beijing/di_4","/d/beijing/aofu_men",
                        "/d/beijing/aofu_zoulang1","/d/beijing/aofu_dayuan",
                        "/d/beijing/aofu_dating","/d/beijing/aofu_zoulang2",
                        "/d/beijing/aofu_houyuan","/d/beijing/aofu_zoulang3",
                        "/d/beijing/aofu_shufang","/d/beijing/aofu_naofang",
                        "/d/beijing/caishi","/d/beijing/ximenkou",
                        "/d/beijing/shi_1","/d/beijing/guandao_1",
                        "/d/beijing/guandao_2","/d/beijing/huangling",
                        "/d/beijing/shi_3","/d/beijing/di_xigc",
                        "/d/beijing/di_2","/d/beijing/dianmen",
                        "/d/beijing/di_dajie1","/d/beijing/di_5",
                        "/d/beijing/di_dajie2","/d/beijing/di_anmen",
                        "/d/beijing/qingmu_dating",
                     }),
        "���ݳ�"   : ({ 
                        "/d/city/zuixianlou2","/d/city/zuixianlou3",
                        "/d/city/zuixianlou","/d/city/beidajie2",
                        "/d/city/beimen","/d/city/beidajie1",
                        "/d/city/qianzhuang","/d/city/guangchang",
                        "/d/city/xidajie1","/d/city/yamen",
                        "/d/city/xidajie2","/d/city/wuguan",
                        "/d/city/ximen","/d/city/dongdajie1",
                        "/d/city/zahuopu","/d/city/dongdajie2",
                        "/d/city/yaopu","/d/city/datiepu",
                        "/d/city/dongmen",
                     }),
	 "������"   : ({
                        "/d/changan/huanggong","/d/changan/bridge1",
                        "/d/changan/baihu2","/d/changan/beian-dadao",
                        "/d/changan/beian-daokou","/d/changan/bingying1",
                        "/d/changan/bingying2","/d/changan/bei-chengmen",
                        "/d/changan/qixiang3","/d/changan/qixiang2",
                        "/d/changan/tea-shop","/d/changan/fruit-shop",
                        "/d/changan/qixiang1","/d/changan/jiulou",
                        "/d/changan/jiulou2","/d/changan/yongtai-beikou",
                        "/d/changan/zhubaohang","/d/changan/yongtai-dadao1",
                        "/d/changan/yongtai-dadao2","/d/changan/yongtai-dadao3",
                        "/d/changan/huiwenge","/d/changan/xian-daokou",
                        "/d/changan/xi-chengmen","/d/changan/bingying3",
                        "/d/changan/yongtai-dadao4","/d/changan/miao",
                        "/d/changan/yongtai-dadao5","/d/changan/yongtai-nankou",
                        "/d/changan/baozipu","/d/changan/huarui1",
                        "/d/changan/nanan-daokou","/d/changan/huarui2",
                        "/d/changan/mianguan","/d/changan/huarui3",
                        "/d/changan/huadian","/d/changan/bingying5",
                        "/d/changan/bingying4","/d/changan/nan-chengmen",
                        "/d/changan/huarui4","/d/changan/xiaojinghu",
                        "/d/changan/huarui4","/d/changan/huarui5",
                        "/d/changan/zahuopu","/d/changan/huarui5",
                        "/d/changan/huarui6","/d/changan/tuchangguan",
                        "/d/changan/liande-nankou","/d/changan/xiaojiuguan",
                        "/d/changan/liande-dadao5","/d/changan/xiaojia-qianyuan",
                        "/d/changan/liande-dadao4","/d/changan/dongan-daokou",
                        "/d/changan/dong-chengmen","/d/changan/bingying6",
                        "/d/changan/liande-dadao3","/d/changan/liande-dadao2",
                        "/d/changan/liande-dadao1","/d/changan/liande-beikou",
                        "/d/changan/xiyuan","/d/changan/qixiang6",
                        "/d/changan/yaopu","/d/changan/weapon-shop",
                        "/d/changan/qixiang5","/d/changan/shoushi-dian",
                        "/d/changan/biaoju-damen","/d/changan/qixiang4",
                        "/d/changan/bank","/d/changan/qunyulou",
                        "/d/changan/baihu1","/d/changan/fufeng1",
                        "/d/changan/fufeng2","/d/changan/fufeng3",
                        "/d/changan/fufeng4","/d/changan/xian-dadao",
                        "/d/changan/fufeng5","/d/changan/qinglong1",
                        "/d/changan/baoxiangsi","/d/changan/qinglong2",
                        "/d/changan/bridge2","/d/changan/qinglong2",
                        "/d/changan/nanan-dadao","/d/changan/qinglong3",
                        "/d/changan/yamen","/d/changan/fengxu5",
                        "/d/changan/fengxu4","/d/changan/lingyange",
                        "/d/changan/fengxu3","/d/changan/fengxu2",
                        "/d/changan/dongan-dadao","/d/changan/fengxu1",
                        "/d/changan/baihu3","/d/changan/guozijian",
                     }),
        "�ɶ���"   : ({
                        "/d/city3/guangchang","/d/city3/tidugate",
                        "/d/city3/shuduroad2","/d/city3/shuduroad1",
                        "/d/city3/eastroad2","/d/city3/eastroad1",
                        "/d/city3/northroad3","/d/city3/northroad2",
                        "/d/city3/northgate","/d/city3/northroad1",
                        "/d/city3/bingqidian","/d/city3/westroad3",
                        "/d/city3/yaodian","/d/city3/westroad2",
                        "/d/city3/westgate","/d/city3/westroad1",
                        "/d/city3/qingyanggong","/d/city3/southroad3",
                        "/d/city3/wuhoucigate","/d/city3/liubeidian",
                        "/d/city3/wuhouci","/d/city3/southroad2",
                        "/d/city3/southgate","/d/city3/tiduroad",
                        "/d/city3/southroad1","/d/city3/eastroad3",
                        "/d/city3/wangjianglou","/d/city3/eastroad2",
                        "/d/city3/eastroad1","/d/city3/jiudian",
                        "/d/city3/wuguan",
                     }),
        "���ݳ�"   : ({
                        "/d/suzhou/beimen","/d/suzhou/beidajie2",
                        "/d/suzhou/zijinan","/d/suzhou/jiudian",
                        "/d/suzhou/beidajie1","/d/suzhou/xiyuan",
                        "/d/suzhou/canlangting","/d/suzhou/dongdajie1",
                        "/d/suzhou/hutong1","/d/suzhou/leitai",
                        "/d/suzhou/hutong2","/d/suzhou/hutong3",
                        "/d/suzhou/dongdajie2","/d/suzhou/dongmen",
                        "/d/suzhou/yaopu","/d/suzhou/datiepu",
                        "/d/suzhou/baodaiqiao","/d/suzhou/nandajie1",
                        "/d/suzhou/jubaozhai","/d/suzhou/shizilin",
                        "/d/suzhou/yanyutang","/d/suzhou/zhenquting",
                        "/d/suzhou/wenmeige","/d/suzhou/lixuetang",
                        "/d/suzhou/zhipoxuan","/d/suzhou/shuyuan",
                        "/d/suzhou/chaguan","/d/suzhou/nandajie2",
                        "/d/suzhou/liuyuan","/d/suzhou/hehuating",
                        "/d/suzhou/gumujiaohe","/d/suzhou/chitang",
                        "/d/suzhou/nanmen","/d/suzhou/tingyu",
                        "/d/suzhou/xidajie1","/d/suzhou/bingying",
                        "/d/suzhou/yunhematou","/d/suzhou/xidajie2",
                        "/d/suzhou/xuanmiao","/d/suzhou/shuchang",
                        "/d/suzhou/ximen",
                     }),
        "���ݳ�"   : ({
                        "/d/hangzhou/suti2", "/d/hangzhou/jujingyuan",
                        "/d/hangzhou/liuzhuang", "/d/hangzhou/road19",
                        "/d/hangzhou/huangniling", "/d/hangzhou/qinglindong",
                        "/d/hangzhou/road5","/d/hangzhou/liuhe2",
                        "/d/hangzhou/dadao1","/d/hangzhou/xilingqiao",
                        "/d/hangzhou/road9","/d/hangzhou/baoshishan",
                        "/d/hangzhou/yuelang","/d/hangzhou/liuzhuang1",
                        "/d/hangzhou/huagang","/d/hangzhou/hupaoquan", 
                        "/d/hangzhou/yuhuangsd","/d/hangzhou/yuhuangshan",
                        "/d/hangzhou/shanlu6","/d/hangzhou/shanlu7",
                        "/d/hangzhou/yuhuangsj","/d/hangzhou/road18",
                        "/d/hangzhou/road20","/d/hangzhou/suti7",
                        "/d/hangzhou/suti7","/d/hangzhou/suti6",
                        "/d/hangzhou/suti5","/d/hangzhou/suti4",
                        "/d/hangzhou/suti3","/d/hangzhou/suti2",
                        "/d/hangzhou/road7","/d/hangzhou/road8",
                        "/d/hangzhou/road9","/d/hangzhou/road10",
                        "/d/hangzhou/road11","/d/hangzhou/road12",
                        "/d/hangzhou/road13","/d/hangzhou/road14",
                        "/d/hangzhou/road15","/d/hangzhou/road16",
                        "/d/hangzhou/xizhaoshan","/d/hangzhou/road17",
                        "/d/hangzhou/road18","/d/hangzhou/qingbomen",
                        "/d/hangzhou/jujingyuan","/d/hangzhou/liulangqiao",
                        "/d/hangzhou/qiantang","/d/hangzhou/liuheta",
                        "/d/hangzhou/yuquan","/d/hangzhou/dadao1",
                        "/d/hangzhou/dadao2","/d/hangzhou/dalu1",
                        "/d/hangzhou/liuzhuang2","/d/hangzhou/liuzhuang",
                        "/d/hangzhou/road1", "/d/hangzhou/road2",
                        "/d/hangzhou/road4", "/d/hangzhou/road3",
                        "/d/hangzhou/hongchunqiao","/d/hangzhou/jiulou",
                        "/d/hangzhou/duanqiao","/d/hangzhou/baiti",
                        "/d/hangzhou/pinghuqiuyue","/d/hangzhou/fangheting",
                        "/d/hangzhou/gushan","/d/hangzhou/gushanpingtai",
                        "/d/meizhuang/shijie","/d/meizhuang/xiaolu",
                        "/d/meizhuang/gate","/d/hangzhou/shanlu8",
                        "/d/hangzhou/chufang","/d/hangzhou/tiejiangpu",
                        "/d/hangzhou/yaodian","/d/hangzhou/jingcisi",
                        "/d/hangzhou/jingci","/d/hangzhou/shanlu1",
                        "/d/hangzhou/shanlu2","/d/hangzhou/shanlu3",
                        "/d/hangzhou/fajingsi","/d/hangzhou/fajinsi",
                        "/d/hangzhou/faxisi","/d/hangzhou/shanlu4",
                        "/d/hangzhou/shanlu5","/d/hangzhou/shanlu6",
                        "/d/hangzhou/shanlu7","/d/hangzhou/tulu1",
                        "/d/hangzhou/yanxiadong","/d/hangzhou/maojiabu",
                        "/d/hangzhou/maojiabu","/d/hangzhou/huangniling",
                        "/d/hangzhou/shuiledong","/d/hangzhou/manjuelong",
                     }),
        "������"   : ({
                        "/d/xiangyang/westjie2", "/d/xiangyang/southjie2",
                        "/d/xiangyang/xiaorong1", "/d/xiangyang/zhonglie",
                        "/d/xiangyang/guangchang", "/d/xiangyang/dingzi",
                        "/d/xiangyang/westgate2","/d/xiangyang/northgate1",
                        "/d/xiangyang/eastgate1","/d/xiangyang/southgate2",
                        "/d/xiangyang/walls2","/d/xiangyang/walle3",
                        "/d/xiangyang/walln4","/d/xiangyang/juyilang", 
                        "/d/xiangyang/northgate2","/d/xiangyang/northjie",
                        "/d/xiangyang/bingying1","/d/xiangyang/chaguan",
                        "/d/xiangyang/northroad2","/d/xiangyang/xiaorong2",
                        "/d/xiangyang/xiaorong1","/d/xiangyang/jiekou2",
                        "/d/xiangyang/eastroad2","/d/xiangyang/eastroad1",
                        "/d/xiangyang/biaoju","/d/xiangyang/eastjie2",
                        "/d/xiangyang/eastjie3","/d/xiangyang/bingying2",
                        "/d/xiangyang/eastgate2","/d/xiangyang/walle1",
                        "/d/xiangyang/walle5","/d/xiangyang/walle7",
                        "/d/xiangyang/walle2","/d/xiangyang/walle4",
                        "/d/xiangyang/walle6","/d/xiangyang/walle8",
                        "/d/xiangyang/mujiang","/d/xiangyang/eastjie2",
                        "/d/xiangyang/eastjie3","/d/xiangyang/jiedao",
                        "/d/xiangyang/minju2","/d/xiangyang/eastjie1",
                        "/d/xiangyang/jiangjungate","/d/xiangyang/yaopu",
                        "/d/xiangyang/anfugate","/d/xiangyang/anfupailou",
                        "/d/xiangyang/southjie1","/d/xiangyang/southjie2",
                        "/d/xiangyang/southjie3","/d/xiangyang/xuetang",
                        "/d/xiangyang/qianzhuang","/d/xiangyang/southgate1",
                        "/d/xiangyang/nixianglou","/d/xiangyang/duchang",
                        "/d/xiangyang/tiejiangpu","/d/xiangyang/bingying3",
                        "/d/xiangyang/walls1","/d/xiangyang/walls3",
                        "/d/xiangyang/walls5","/d/xiangyang/walls7",
                        "/d/xiangyang/walls4","/d/xiangyang/walls6",
                        "/d/xiangyang/walls8","/d/xiangyang/westjie1",
                        "/d/xiangyang/westjie2","/d/xiangyang/westjie3",
                        "/d/xiangyang/guofugate","/d/xiangyang/guofuyuan",
                        "/d/xiangyang/guofuting","/d/xiangyang/guofuhuayuan",
                        "/d/xiangyang/guofukefang","/d/xiangyang/guofuwoshi",
                        "/d/xiangyang/guofushufang","/d/xiangyang/dangpu",
                        "/d/xiangyang/juyiyuan","/d/xiangyang/juyilianwu2",
                        "/d/xiangyang/juyilianwu1","/d/xiangyang/juyilang",
                        "/d/xiangyang/juyihuayuan","/d/xiangyang/juyimale",
                        "/d/xiangyang/juyifemale","/d/xiangyang/juyichufang",
                        "/d/xiangyang/juyiwupin","/d/xiangyang/dajiaochang",
                        "/d/xiangyang/bingying4","/d/xiangyang/westgate1",
                        "/d/xiangyang/wallw1","/d/xiangyang/wallw2",
                        "/d/xiangyang/wallw3","/d/xiangyang/wallw4",
                        "/d/xiangyang/wallw5","/d/xiangyang/wallw6",
                        "/d/xiangyang/wallw7","/d/xiangyang/wallw8",
                        "/d/xiangyang/westroad1","/d/xiangyang/westroad2",
                        "/d/xiangyang/shudian","/d/xiangyang/hutong1",
                        "/d/xiangyang/hutong2","/d/xiangyang/xinluofang",
                        "/d/xiangyang/jiekou1","/d/xiangyang/northgate2",
                        "/d/xiangyang/walln1","/d/xiangyang/walln2",
                        "/d/xiangyang/walln3","/d/xiangyang/walln5",
                        "/d/xiangyang/walln6","/d/xiangyang/walln7",
                        "/d/xiangyang/walln8",
                     }),
        "����һ��" : ({
                        "/d/dali/northgate", "/d/dali/southgate",
                        "/d/dali/shanlu2", "/d/dali/buxiongbu",
                        "/d/dali/jinzhihe", "/d/dali/xiaodao1",
                        "/d/dali/tianweijing", "/d/dali/wuding",
                        "/d/dali/luwang", "/d/dali/gudao",
                        "/d/dali/biluoxueshan", "/d/dali/zhenxiong",
                        "/d/dali/yixibu", "/d/dali/cangshanzhong",
                        "/d/dali/wumeng", "/d/dali/hongsheng", 
                        "/d/dali/tusifu","/d/dali/tusimentang",
                        "/d/dali/tusiyishi","/d/dali/dahejiewest",
                        "/d/dali/dahejieeast","/d/dali/baiyiziguan",
                        "/d/dali/baiyiminju","/d/dali/center",
                        "/d/dali/taihejiekou","/d/dali/sheguta",
                        "/d/dali/qingchi","/d/dali/taiheeast",
                        "/d/dali/stoneshop","/d/dali/garments",
                        "/d/dali/yaoshop","/d/dali/paifang",
                        "/d/dali/yujie","/d/dali/gongmen",
                        "/d/dali/qiandian","/d/dali/yuhuayuan",
                        "/d/dali/hualang","/d/dali/yushanfang",
                        "/d/dali/piandian","/d/dali/chahuashan1",
                        "/d/dali/chahuashan2","/d/dali/chahuashan3",
                        "/d/dali/chahuashan4","/d/dali/chahuashan5",
                        "/d/dali/chahuashan6","/d/dali/dadieshui",
                        "/d/dali/qingxi","/d/dali/xiaodao1",
                        "/d/dali/hudiequan","/d/dali/yuxuguanqian",
                     }),
                     
]);

void place_npc(object ob, object who)
{
        string *kp;
        string p;
        string startroom;
        object pos;

        kp = keys(place);

        // select the exact position
        for (;;)
        {
                p = kp[random(sizeof(kp))];
                startroom = place[p][random(sizeof(place[p]))];
                if (! objectp(pos = get_object(startroom)))
                {
                        log_file("log", sprintf("error to place npc to %s:%s\n",
                                                p, startroom));
                        continue;
                }
                break;
        }

        // move to the position
        ob->move(pos);
        ob->set("place", p);
        ob->set("startroom", startroom);
        ob->set_temp("quester", who->query("id"));
        ob->set_temp("moved", ({ }));
        message_vision("$N���˹�����\n", ob);
}

private void special_bonus(object me, object who, mixed arg)
{
        string *ob_list = ({
                "/clone/gift/xiandan",
                "/clone/gift/shenliwan",
                "/clone/gift/unknowdan",
                "/clone/gift/xisuidan",
                "/d/item/obj/hantie",
                "/d/item/obj/wujins",
                "/d/item/obj/butian",
                "/d/item/obj/tiancs",
                "/clone/gift/jinkuai",
        });
        object ob;

        message_vision("$n��$N΢΢һЦ�������ɵò���������"
                       "�ˣ������������е㶫���������ȥ�ɡ�\n",
                       who, me);

        if (stringp(arg))
                ob = new(arg);
        else
                ob = new(ob_list[random(sizeof(ob_list))]);
        ob->move(who, 1);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

varargs public void bonus(object who, mapping b, int flag)
{
        int exp;                // �����ľ���
        int pot;                // ������Ǳ��
        int mar;                // ������ʵս���
        int shen;               // ��������
        int score;              // �����Ľ�������
        int weiwang;            // �����Ľ�������
        int pot_limit;          // Ǳ�ܵĽ���
        int mar_limit;          // ʵս���Ľ���
        int percent;            // ��������Ч�ٷֱ�
        string msg;             // ������������Ϣ

        // ��ý����İٷֱ�
        percent = b["percent"];
        if (percent < 1 || percent > 100)
                percent = 100;

        exp = b["exp"] * percent / 100;
        pot = b["pot"] * percent / 100;
        mar = b["mar"] * percent / 100;
        shen = b["shen"] * percent / 100;
        score = b["score"] * percent / 100;
        weiwang = b["weiwang"] * percent / 100;

        if (! flag)
        {
                pot_limit = who->query_potential_limit() - who->query("potential");
                if (pot > pot_limit) pot = pot_limit;
                if (pot < 1) pot = 0;

                mar_limit = who->query_experience_limit() - who->query("experience");
                if (mar > mar_limit) mar = mar_limit;
                if (mar < 1) mar = 0;
        } else
        {
                if (who->query_potential_limit() < who->query("potential"))
                        pot = 1 + random(2);

                if (who->query_experience_limit() < who->query("experience"))
                        mar = 1;
        }

        // ������ʾ��Ϣ
        if (stringp(msg = b["prompt"]))
                msg = HIG + msg + HIG "��������";
        else
                msg = HIG "ͨ����ζ�����������";

        if (exp > 0) msg += chinese_number(exp) + "�㾭�顢";
        if (pot > 0) msg += chinese_number(pot) + "��Ǳ�ܡ�";
        if (mar > 0) msg += chinese_number(mar) + "��ʵս��ᡢ";
        if (shen > 0) msg += chinese_number(shen) + "������";
        if (shen < 0) msg += chinese_number(-shen) + "�㸺��";
        if (score > 0) msg += chinese_number(score) + "�㽭��������";
        if (weiwang > 0) msg += chinese_number(weiwang) + "��������";

        msg += "�����õ���������\n" NOR;
        tell_object(who, sort_msg(msg));

        // bonus
        who->add("combat_exp", exp);
        who->add("potential", pot);
        who->add("experience", mar);
        who->add("shen", shen);
        who->add("score", score);
        who->add("weiwang", weiwang);
}

// �ӳٽ�������ʱ�����������ʱ��Ӧ������ĳЩ�¼������Ժ�
// �����ڸ��¼�����ʱ���뽱����������д�������Խ������ɵ�
// �ط����¼����ڷ�����ʱ�򣬵���Ҫ����ҿ����������¼�����
// �Ժ󡣱���ɱ�ˣ���������ʱ����뽱�����������ģ�������ϣ
// ������ڿ���NPC ��������Ϣ�Ժ�ſ�����������Ϣ����ʱ���
// ��delay_bonus�ˡ�
public void delay_bonus(object who, mapping b)
{
        who->start_call_out((: call_other, __FILE__,
                               "bonus", who, b :), 1);
}

// ��ȡ����
// ���Ŀǰ����Э�����ˣ�������ȡ����
int ask_quest(object me, object who)
{
        object ob;              // �����ص�ĳЩ���������
        mapping q;              // WHO������
        object aob;             // WHOĿǰ����Э���Ķ���
        int exp;                // WHO�ľ���
        int t;                  // ��������ʱ��ı���
        int level;              // QUEST�ĵȼ�
        string place;

        message_vision("$n��$N�����й�����������\n", me, who);

        if (who->query("combat_exp") < 2000000)
        {
                message_vision("$N�ɴ��۾�����$n�������������δ�ɣ����ǲ���Ӵ��\n",
                               me, who);
                return 1;
        }  
                      
        q = who->query("slough");
        if (mapp(q))
        {
                if (q["task"])
                {
                        message_vision("$Nһ��ŭ�ݶ�$n�����㲻��Ҫ�˸������𣿲���ɾ���Щ"
                                       "Ǯ�������Һ�����ˣ�\n", me, who);
                        return 1;
                }
        }

        if (me->query("eff_qi") * 2 < me->query("max_qi") ||
            me->query("qi") * 2 < me->query("max_qi"))
        {
                message_vision("$N�����ؿڣ�һ���ǳ�ʹ������ӣ������"
                               "����Ȼû������ȥ��\n", me);
                return 1;
        }

        if (objectp(aob = who->query_temp("quest/assist")))
        {
                message_vision("$N���˿�$n������������˵�㲻�ǰ�" +
                               aob->name(1) + "ȥ��ô���Ȱ�����"
                               "��˵�ɣ���\n", me, who);
                return 1;
        }

        level = who->query_temp("slough/next_level");
        if (level < 0 || level > MAX_QUEST_LEVEL)
                level = 0;

        ob = new(CLASS_D("generate") + "/slough_killer.c");
        place_npc(ob, who);
        NPC_D->set_from_me(ob, who, 100);
        ob->add_temp("apply/attack", ob->query_skill("force") *
				     (level - 1) / 15);
        ob->add_temp("apply/defense", ob->query_skill("force") *
			              (level - 1) / 15);
        ob->add_temp("apply/damage", 5 + level * 7);
        ob->add_temp("apply/unarmed_damage", 5 + level * 7);
        ob->add_temp("apply/armor", 10 + level * 15);
        ob->set_temp("quester", who->query("id"));
                   
        // NPC_D->random_move(ob);
        place = ob->query("place");

        message("vision", me->name() + "С���Ķ�" + who->name() +
                "�Ը���ʲô��" + who->name() +
                "һ������һ�߲�ס�ĵ�ͷ��\n",
                environment(who), ({ who }));

        tell_object(who, sort_msg(HIC + me->name() + "����˵�����ѵ���" +
                "����������ĳ����Ϸ���ջ�Ϥ��" + place + "һ����һ��" +
                "ɱ�˿�ħΪ���������ȥ����һ������������ҵ����ϣ����" +
                "�˵����ֺ����" + ob->query("name") + "(" + ob->query("id") + 
                ")" + "�����������ɵ�ϸŪ��������̻���������ң�\n" NOR)); 
                                
        who->set("slough/task", 1);  
        switch (level)
        {
        case 0:
                message_vision("$N���˶٣��ֶ�$n�������������"
                        "���װ�úܣ���Ҫ�ǻ��첻���ǿɲ��󻰡���\n",
                        me, who);
                break;
        case 1:
                break;
        case 2:
                message_vision("$N���˿�$n�ֵ�����������������Щ"
                        "�Ѱ죬��Ҫ�ǲ����Ҿ������˰ɡ���\n",
                        me, who);
                break;
        case 3:
                message_vision("$N̾�˿�����֣�صĶ�$n���������"
                        "�������յý����㲻Ҫ��ǿ�Լ������о����ˡ���\n",
                        me, who);
                break;
        }
  
        who->set("slough/check", 1);            
        who->set("slough/name", ob->name());
        who->set("slough/id", ob->query("id"));
        who->set("slough/level", level);
        who->set("slough/place", place);
        t = time();
        who->set("slough/time", t);
        t = time() / ONE_DAY;
        t += 8;
        t = t * ONE_DAY - 1;
        who->set("slough/limit", t);
        message("vision", me->name() + "��$N��������˵�����������Ҫ��" +
                     CHINESE_D->chinese_monthday(t) + "֮ǰ��ɣ���\n", who);
        who->start_busy(1);
        return 1;
}

int do_answer(object me, object ob, string arg)
{
        object killer;
        object gold;
        int amount;
        
        if (! ob->query("slough/inquiry"))
        {
                message_vision(HIY "$N��$nŭ������������ȥ��������ĥ��ʲô��\n" NOR, me, ob); 
                return 1;
        } 
        
        if (! arg || arg == "")
        { 
                tell_object(ob, "���� answer <����> �ش�\n");
                return 1;
        }               

        if (! objectp(killer = find_living(ob->query("slough/id"))))
        {
                message_vision(
                        HIW "$NΪ�ѵض�$n˵�����������ˣ��������˺���ʧ���ˣ�\n" NOR, me, ob);
                ob->delete("slough/inquiry");
                ob->delete("slough/check"); 
                return 1;
        }

        if (arg != killer->query("family/family_name"))
        {
                message_vision(HIW "$N��ɫһ����$n��������˵��������ʲô" + arg + "���������ȥ��鿴����\n" NOR, 
                        me, ob);
                ob->delete("slough/inquiry");
                return 1;
        } else
        {
                message_sort(HIW "$N��¶΢Ц��$n��ͷ���������������������" +
                        arg + "���������һ������" + "�ҵõ���Ϣ˵" +
                        killer->query("name") + "���ӵ���" + killer->query("place") +
                        "�������������ף��������̸�ȥ�������ɣ�\n" NOR, me, ob);

                amount = 20 + random(10);
                gold = new("/clone/money/silver");
                gold->set_amount(amount);
                gold->move(ob);
      
                message_sort(
                        MAG "$N���˶٣����Ŷ�$n���������ˣ���һ·���࣬����Ҳȥ�˲��ٰɣ�"
                        "������" + sprintf("%d����������ȫ������Щ���Ͱɣ��ɱ�����ѽ����\n" NOR +
                        WHT "$N˵�꣬ת�������鷿���ó�һЩ��������$n��\n" NOR, amount),
                        me, ob); 

                ob->delete("slough/inquiry");
                ob->delete("slough/check"); 
                ob->set("slough/chased", 1); 
                ob->set("slough/place", killer->query("place"));
                killer->start_kill(ob);   
                return 1;
        }
}

int accept_object(object me, object who, object ob)
{
        mapping q;              // WHO������
        string msg;             // ����˵����Ϣ
        object dob;             // ���ε��˵���
        int bonus;              // ����(��������1������)
        int t;                  // ��������ʱ��ı���
        int exp;                // ��õľ���
        int pot;                // ��õ�Ǳ��
        int mar;                // ��õ�ʵս���
        int weiwang;            // ��õ�����
        int score;              // ��õĽ�������
        int lvl;                // ����ĵȼ�
        int quest_level;        // QUEST�ĵȼ�
        int quest_count;        // ����QUEST����Ŀ
        int timeover;           // ��־����ʱ�ˣ�
        int added;              // �������ʱ�������ֵĵ��˻��������
	mixed special = 0;      // �Ƿ������⽱��
        int money = 40 + random(20);
        object obj;
        
        q = who->query("slough");

        if (ob->query("money_id"))
        {
                if(! who->query("slough/task"))
                {
                        message_vision("$N�ӹ�" + ob->name() + "���ǺǴ�Ц����$n�������ҿɾͲ������ˡ�\n", 
                                me, who);
                }

                if (ob->value() < 100 * money) 
                {
                        message_sort(
                                "$Nһ˫�������۾�ֱ����$n�����Ǯ�ɲ����ҵĿ�����"
                                "����ҲҪ" + sprintf(HIR " %d " NOR "��" HIY "����" NOR "����\n",
                                money), me, who);
                                
                        return 0;
                } else
                {                                                      
                        message_sort(
                                "$N�ӹ�" + ob->name() + "���ǺǴ�Ц����$n����"
                                "û�й�ϵ���´μ���Ŭ����\n", me, who);
                                
                        destruct(ob);        
                        who->delete("slough_count");
	                who->delete_temp("slough/next_level");     
                        who->start_busy(1);

                        obj = find_living(q["id"]);
                        who->delete("slough");
                        if (! obj || obj->query_temp("quester") != who->query("id"))
                                return 1;

                        if (environment(obj))
                                message_vision("$N���˿����ܣ�����ææ���ߵ��ˡ�\n", obj);    
                                               
                        destruct(obj);
                }
                return 1;
                
        } else
        {
                if (! mapp(q) || ! ob->is_corpse() && ! ob->is_head())
                        return 0;
        
                if (! stringp(ob->query("owner_id")))
                {
                        message_vision("$N���ű��ӿ��˿�" + ob->name() + "����"
                                       "����ʲô�����ģ���������ߡ���\n", me);
                        return 0;
                }
        
                if (ob->query("owner_id") != q["id"])
                        return 0;

                msg = "$N�ӹ�" + ob->name() + "���ǺǴ�Ц����$n������";
                msg += "�ɵúã�Ư����";
                msg += "��\n";
                t = time();
                if (who->query("slough/succeed"))
                {
                        msg += "$N������������û�뵽���׿Խ���֣��ɹ��Ľ���˵��صİ��գ���\n";
                        timeover = 0;
                } else                        
                if (who->query_temp("quest/escape_times"))
                {
                        msg += "$N������������û�뵽������ôǿ����ʵ��δ���ϵ������࣬���࣡��\n";
                        timeover = 0;
                } else
                if (t > q["limit"])
                {
                        msg += "$Nҡҡͷ���ֵ�������ϧ����������" +
                               CHINESE_D->chinese_monthday(t) + "ǰ��������"
                               "�ˣ������������������°ɡ���\n";
                        timeover = 1;
                } else
                {
                        if (t - q["time"] < ONE_DAY)
                        {
                                msg += "$N���ͷ��������ܲ�����ô��������"
                                        "���úøɣ���\n";
                        } else
                                msg += "$N���ͷ��������β��������ˡ���\n";

                        timeover = 0;
                }

                // bonusΪ1��ʾ����������Ϊ2��ʾ�۳�һ�롣
                bonus = (ob->query("killed_by") == who->query("id")) &&
                        (ob->query("defeated_by") == who ||
                         ! ob->query("defeated_by") &&
                           ob->query("defeated_by_who") == who->name(1));
                if (ob->query("assist") == who)
                {
                        dob = ob->query("defeated_by");
                        msg += "$N��ο�Ķ�$n������������ܹ��õ�" +
                               (dob ? dob->name(1) : "ͬ��ʦ�ֵ�") +
                               "�İ�æ��Ҳ�����ף��Ժ�˴�Ҫ�����Ӧ����\n";
                        bonus = 2;
                } else
                if (bonus)
                        bonus = 1;

                destruct(ob);
                lvl = NPC_D->check_level(who);
                exp = 500 + random(200) + lvl * 20;
                pot = 150 + random(50) + lvl * 20;
                weiwang = 20 + random(30) + lvl * 2;
                score = 20 + random(30) + lvl * 2;
                quest_count = who->query("slough_count") + 1;

                // add temped for keep compactible with old version
                if (who->query_temp("slough/total_count"))
                {
                        quest_count = who->query_temp("slough/total_count") + 1;
                        who->delete_temp("slough/total_count");
                }

                // ����������ɵĴ�����������
                if (quest_count >= 500)
                {
                        // ��������˳���500�ε�����
                        exp += 80 + random(quest_count / 20 + 1);
                        pot += 45 + random(quest_count / 25 + 1);
                        mar = 50 + random(20);
                        weiwang += 8 + random(20);
                        score += 4 + random(15);
                } else
                if (quest_count >= 200)
                {
                        // ��������˳���200�ε�����
                        exp += 70 + random(quest_count / 20 + 1);
                        pot += 40 + random(quest_count / 25 + 1);
                        mar = 20 + random(10);
                        weiwang += 5 + random(15);
                        score += 3 + random(10);
                } else
                if (quest_count >= 100)
                {
                        // ��������˳���100�ε�����
                        exp += 50 + random(quest_count / 20 + 1);
                        pot += 30 + random(quest_count / 25 + 1);
                        weiwang += 3 + random(10);
                        score += 2 + random(10);
                } else
                if (quest_count >= 10)
                {
                        // ��������˳���10�ε�����
                        exp += 45 + random(quest_count / 20 + 1);
                        pot += 25 + random(quest_count / 25 + 1);
                        weiwang += 1 + random(5);
                        score += 1 + random(5);
                }

                switch (quest_level = q["level"])
                {
                case 0:
                        exp = exp / 2 + 1;
                        pot = pot / 2 + 1;
                        weiwang = weiwang / 3 + 1;
                        score = score / 4 + 1;
                        msg += "$N����$n����˵���������аɣ��´��Ҹ�����ѵ�����񡣡�\n";
                        break;
                case 1:
                        msg += "$N��$n�ֵ��������������ҿ����и�Щ���θ����ˡ���\n";
                        break;
                case 2:
                        exp += exp / 4;
                        pot += pot / 4;
                        weiwang += weiwang / 4;
                        score += score / 4;
                        msg += "$N��$nЦ���������ǲ�����������̶�Ľý��ߡ���\n";
                        break;
                case 3:
                        exp += exp / 2;
                        pot += pot / 2;
                        weiwang += weiwang / 2;
                        score += score / 2;
                        msg += "$N����������ǳ������㽫���ɾ�һ�����ɹ�������\n";
                        break;
                }

                if (quest_count == 50)
                {
                        msg += "$N������Ц����������������ģ������ϰ�"
                               "��������ɵ�ƯƯ�������ܺã��ܺá���\n";
			special = 1;
                } else
                if (quest_count == 100)
                {
                        msg += "$N��ϲ��������������ʵ��������"
                               "������ɵúܺá���\n";
			special = "/clone/gift/puti-zi";
                } else
                if (quest_count == 200)
                {
                        msg += "$N̾���������ǳ���������ǰ�ˣ��벻����������"
                               "��������һ��©�����ף����ף���\n";
			special = "/clone/gift/tianxiang";
                } else
                if (quest_count >= 500)
                {
                        msg += "$N����̾�˿������������벻������������ٴ�"
                               "������һʧ�֣�������̶���Ǻ�����˰�����\n";
			special = "/clone/gift/jiuzhuan";
                        quest_count = 0;
                } else
                if ((quest_count % 10) == 0)
                {
                        msg += "$Nϲ���������ǲ�������Ȼ����" +
                               chinese_number(quest_count) +
                               "�ζ�û��ʧ�֣��ɵĺã���\n";
                }

                quest_level = q["level"];
                quest_level++;
                if (quest_level > MAX_QUEST_LEVEL)
                        quest_level = 1;

                who->set("slough_count", quest_count);
                who->set_temp("slough/next_level", quest_level);
        }

        if ((added = (int)who->query_temp("slough/help_count")) > 0)
        {
                msg += HIY "$N" HIY "�ֵ�������ε��˷��°��֣���������"
                       "��Ӧ�䣬������񣬿�ϲ���ɺأ���\n" NOR;
                who->delete_temp("slough/help_count");
        }
        added += (int)who->query_temp("quest/escape_times") * 2;
        who->delete_temp("quest/escape_times");
        // ����NPC�İ��ֺ����ߵĴ�����������
        if (added)
        {
                exp += exp * added / 2;
                pot += pot * added / 2;
        }

        message_vision(msg, me, who);
        who->delete("slough");
        if (! bonus) return 1;

        exp /= bonus;
        pot /= bonus;
        mar /= bonus;
        weiwang /= bonus;
        score /= bonus;
        // bouns
        if (timeover)
        {
                exp /= 2;
                pot /= 3;
                mar /= 2;
                weiwang /= 4;
                score /= 4;
        } else
        {
                // 0.01% to get a special object
                if (random(2000) == 1 || special)
			special_bonus(me, who, special);
        }

        bonus(who, ([ "exp" : exp, "pot" : pot, "mar" : mar,
                      "weiwang" : weiwang, "score" : score ]), 1);
        return 1;
}
