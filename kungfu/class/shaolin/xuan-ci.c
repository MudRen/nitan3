// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// xuan-ci.c ���ȴ�ʦ

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

#define	IS_XUAN_CI	1

#include "xuan.h"

void create()
{
	set_name("���ȴ�ʦ", ({
		"xuanci dashi",
		"xuanci",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿������ġ�\n"
		"������������ͣ���ȴ�����⣬Ŀ�̴�Ц���Ե��������㡣\n"
	);

	set("nickname", "�����·���");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 2800);
	set("max_jing", 1400);
	set("neili", 3800);
	set("max_neili", 3800);
	set("jiali", 50);
	set("level", 20);
	set("combat_exp", 1450000);
	set("score", 500000);

	set_skill("force", 170);
	set_skill("hunyuan-yiqi", 170);
	set_skill("dodge", 160);
	set_skill("shaolin-shenfa", 160);
	set_skill("finger", 170);
	set_skill("strike", 170);
	set_skill("hand", 160);
	set_skill("claw", 160);
	set_skill("parry", 160);
	set_skill("nianhua-zhi", 170);
	set_skill("sanhua-zhang", 170);
	set_skill("fengyun-shou", 160);
	set_skill("longzhua-gong", 160);
	set_skill("buddhism", 160);
	set_skill("literate", 160);
	set_skill("medical", 180);
	set_skill("shaolin-yishu", 180);
	set_skill("martial-cognize", 120);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	create_family("������", 36, "����");

	set("master_ob",4);
	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����" :
        case "����" :
        case "����" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;
        
        case "һέ�ɽ�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shaolin-shenfa/du",
                           "name"    : "һέ�ɽ�",
                           "sk1"     : "shaolin-shenfa",
                           "lv1"     : 100,
                           "sk2"     : "dodge",
                           "lv2"     : 100,                           
                           "gongxian": 1000, ]));
                break;

        case "�޺���ħ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/luohan-quan/xiangmo",
                           "name"    : "�޺���ħ",
                           "sk1"     : "luohan-quan",
                           "lv1"     : 100,
                           "sk2"     : "buddhism",
                           "lv2"     : 100,                           
                           "gongxian": 200, ]));
                break;
                
        case "������ͨ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jingang-quan/jingang",
                           "name"    : "������ͨ",
                           "sk1"     : "jingang-quan",
                           "lv1"     : 100,
                           "sk2"     : "buddhism",
                           "lv2"     : 100,                           
                           "gongxian": 600, ]));
                break;

        case "�黨��Ѩ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/nianhua-zhi/fuxue",
                           "name"    : "�黨��Ѩ",
                           "sk1"     : "nianhua-zhi",
                           "lv1"     : 150,
                           "sk2"     : "force",
                           "lv2"     : 150,                           
                           "gongxian": 600, ]));
                break;

        case "��ħһָ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yizhi-chan/jingmo",
                           "name"    : "��ħһָ",
                           "sk1"     : "yizhi-chan",
                           "lv1"     : 150,
                           "sk2"     : "force",
                           "lv2"     : 150,                           
                           "gongxian": 600, ]));
                break;

        case "ָ�㽭ɽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yizhi-chan/dian",
                           "name"    : "ָ�㽭ɽ",
                           "sk1"     : "yizhi-chan",
                           "lv1"     : 150,
                           "sk2"     : "force",
                           "lv2"     : 150,                           
                           "gongxian": 600, ]));
                break;

        case "��ɫ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/wuxiang-zhi/wuse",
                           "name"    : "��ɫ����",
                           "sk1"     : "wuxiang-zhi",
                           "lv1"     : 120,
                           "sk2"     : "force",
                           "lv2"     : 120,                           
                           "gongxian": 400, ]));
                break;

        case "��������ָ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xiuluo-zhi/jueming",
                           "name"    : "��������ָ",
                           "sk1"     : "xiuluo-zhi",
                           "lv1"     : 150,
                           "sk2"     : "force",
                           "lv2"     : 150,                           
                           "gongxian": 800, ]));
                break;

        case "��շ�ħ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jingang-zhi/fumo",
                           "name"    : "��շ�ħ��",
                           "sk1"     : "jingang-zhi",
                           "lv1"     : 150,
                           "sk2"     : "buddhism",
                           "lv2"     : 200,                           
                           "gongxian": 600, ]));
                break;

        case "�������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/duoluoye-zhi/jimie",
                           "name"    : "�������",
                           "sk1"     : "duoluoye-zhi",
                           "lv1"     : 150,
                           "sk2"     : "buddhism",
                           "lv2"     : 200,                           
                           "gongxian": 1000, ]));
                break;

        case "��ħ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/banruo-zhang/feng",
                           "name"    : "��ħ",
                           "sk1"     : "banruo-zhang",
                           "lv1"     : 100,
                           "sk2"     : "buddhism",
                           "lv2"     : 100,                           
                           "gongxian": 300, ]));
                break;

        case "��Ůɢ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/sanhua-zhang/san",
                           "name"    : "��Ůɢ��",
                           "sk1"     : "sanhua-zhang",
                           "lv1"     : 120,
                           "sk2"     : "force",
                           "lv2"     : 120,                           
                           "gongxian": 500, ]));
                break;

        case "Ⱥɽ��Ӱ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xumishan-zhang/ying",
                           "name"    : "Ⱥɽ��Ӱ",
                           "sk1"     : "xumishan-zhang",
                           "lv1"     : 120,
                           "sk2"     : "force",
                           "lv2"     : 120,                           
                           "gongxian": 500, ]));
                break;

        case "����˷�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenzhang-bada/bafang",
                           "name"    : "����˷�",
                           "sk1"     : "shenzhang-bada",
                           "lv1"     : 120,
                           "sk2"     : "force",
                           "lv2"     : 120,                           
                           "gongxian": 500, ]));
                break;

        case "����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/fengyun-shou/qinna",
                           "name"    : "����",
                           "sk1"     : "fengyun-shou",
                           "lv1"     : 120,
                           "sk2"     : "force",
                           "lv2"     : 120,                           
                           "gongxian": 400, ]));
                break;

        case "ǧҶ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/qianye-shou/qianye",
                           "name"    : "ǧҶ����",
                           "sk1"     : "qianye-shou",
                           "lv1"     : 120,
                           "sk2"     : "force",
                           "lv2"     : 120,                           
                           "gongxian": 400, ]));
                break;

        case "����ץ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/longzhua-gong/zhua",
                           "name"    : "����ץ",
                           "sk1"     : "longzhua-gong",
                           "lv1"     : 150,
                           "sk2"     : "force",
                           "lv2"     : 150,                           
                           "gongxian": 1000, ]));
                break;

        case "������ħ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yingzhua-gong/chumo",
                           "name"    : "������ħ",
                           "sk1"     : "yingzhua-gong",
                           "lv1"     : 150,
                           "sk2"     : "force",
                           "lv2"     : 150,                           
                           "gongxian": 600, ]));
                break;

        case "���Ľ�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/fumo-jian/foxin",
                           "name"    : "���Ľ�",
                           "sk1"     : "fumo-jian",
                           "lv1"     : 150,
                           "sk2"     : "force",
                           "lv2"     : 150,                           
                           "gongxian": 700, ]));
                break;

        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/xiuluo-dao/suoming",
                           "name"    : "��������",
                           "sk1"     : "xiuluo-dao",
                           "lv1"     : 150,
                           "sk2"     : "force",
                           "lv2"     : 150,                           
                           "gongxian": 500, ]));
                break;

        case "����ιӥ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/cibei-dao/sheshen",
                           "name"    : "����ιӥ",
                           "sk1"     : "cibei-dao",
                           "lv1"     : 150,
                           "sk2"     : "force",
                           "lv2"     : 150,                           
                           "gongxian": 400, ]));
                break;

        case "�޳��廯" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/wuchang-zhang/wuchang",
                           "name"    : "�޳��廯",
                           "sk1"     : "wuchang-zhang",
                           "lv1"     : 150,
                           "sk2"     : "force",
                           "lv2"     : 150,                           
                           "gongxian": 400, ]));
                break;

        case "�������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/pudu-zhang/zhao",
                           "name"    : "�������",
                           "sk1"     : "pudu-zhang",
                           "lv1"     : 150,
                           "sk2"     : "force",
                           "lv2"     : 150, 
                           "sk3"     : "buddhism",
                           "lv3"     : 200,                          
                           "gongxian": 400, ]));
                break;

        case "�������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/zui-gun/zuida",
                           "name"    : "�������",
                           "sk1"     : "zui-gun",
                           "lv1"     : 150,
                           "sk2"     : "force",
                           "lv2"     : 150,                      
                           "gongxian": 400, ]));
                break;

        case "Τ�ӷ�ħ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/weituo-gun/fumo",
                           "name"    : "Τ�ӷ�ħ",
                           "sk1"     : "weituo-gun",
                           "lv1"     : 150,
                           "sk2"     : "buddhism",
                           "lv2"     : 150,                      
                           "gongxian": 400, ]));
                break;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        default:
                return 0;
        }
}
