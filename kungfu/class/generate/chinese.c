// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chan_cler �й���ս�� 
   
inherit NPC; 

private void from_wudang(); 
private void from_shaolin(); 
private void from_huashan(); 
private void from_ouyang(); 
private void from_gaibang(); 
private void from_taohua(); 
private void from_gumu(); 
private void from_xingxiu(); 
private void from_xueshan(); 
private void from_xuedao(); 
private void from_xiaoyao(); 
private void from_shenlong(); 
private void from_emei();
private void from_quanzhen(); 
private void from_mingjiao();
private void from_lingjiu(); 
private void from_murong(); 
private void from_duanshi(); 
private void from_hujia(); 

/*  
function *init_family = ({ (: from_wudang :),   (: from_shaolin :),   (: from_huashan :), 
                           (: from_ouyang :),   (: from_gaibang :),   (: from_taohua :), 
                           (: from_gumu :),     (: from_xingxiu :),   (: from_xueshan :), 
                           (: from_xuedao :),   (: from_xiaoyao :),   (: from_shenlong :), 
                           (: from_emei :),     (: from_quanzhen :),  (: from_mingjiao :), 
                           (: from_lingjiu :),  (: from_murong :),    (: from_duanshi :),
                           (: from_hujia :),                      
                        }); 

void create() 
{ 
        NPC_D->generate_cn_name(this_object()); 
        set("long", "һ���ˡ�\n"); 
        set("gender", "����"); 
        set("age", 20); 
        set("str", 20); 
        set("int", 20); 
        set("con", 20); 
        set("dex", 20); 
        
        // the follow 5 setting has no use       
        set("max_qi", 100); 
        set("max_jing", 100); 
        set("neili", 100); 
        set("max_neili", 100); 
        set("jiali", 100); 
        
        set("combat_exp", 3000000); 
        
        setup(); 
        
        evaluate(init_family[random(sizeof(init_family))]); 
} 
*/

// external functions
public void setup_family(string family);

mapping init_family = ([
        "������"   : (: from_shaolin :),
        "�䵱��"   : (: from_wudang :),
        "ؤ��"     : (: from_gaibang :),
        "��ɽ��"   : (: from_huashan :),
        "ѩɽ��"   : (: from_xueshan :),
        "�һ���"   : (: from_taohua :),
        "��Ĺ��"   : (: from_gumu :),
        "ȫ���"   : (: from_quanzhen :),
        "������"   : (: from_xingxiu :),
        "������"   : (: from_emei :),
        "Ѫ����"   : (: from_xuedao :),
        "��ң��"   : (: from_xiaoyao :),
        "����"     : (: from_mingjiao :),
        "���չ�"   : (: from_lingjiu :),
        "������"   : (: from_shenlong :),
        "�������" : (: from_hujia :),
        "ŷ������" : (: from_ouyang :),
        "Ľ������" : (: from_murong :),
        "���ϻ���" : (: from_duanshi :),
]);


void create()
{
        string *fams;

        NPC_D->generate_cn_name(this_object());
        set("long", "һ���ˡ�\n");
        set("gender", "����");
        set("age", 20);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        // the follow 5 setting has no use      
        set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 100);

        set("combat_exp", 3000000);

        setup();

        fams = keys(init_family);
        setup_family(fams[random(sizeof(fams))]);
}

void setup_family(string family)
{
        function f;
        mapping skills;
        string skill;

//      family = FAMILY_D->query_family_name(family);
        if (! functionp(f = init_family[family]))
                return;

        if (mapp(skills = query_skills()))
        {
                // remove all skill
                foreach (skill in keys(skills))
                        delete_skill(skill);

        }

        // set family information
        /*
        set("family/family_name", family);
        set("family/generation", 0);
        */
        create_family(family, 0, "����"); 

        evaluate(f);
}
        
private void from_wudang()
{
        set("scale", 200);
        set("from", ({
                "��˵���˳����䵱�����䵱�ɵĸ��֣�Ȼ�����䲻�޵£���ϧ����ϧ��",
                "���Ŵ��˱����䵱ɽ��һũ�򣬶���ĿȾ����Ȼ���ͳɷǷ��书��",
                "��˵�������䵱��ͽ�����그��ɱ���������󣬲�����շ�����ԭ��",
        }));

        set_skill("force", 1);
        set_skill("taiji-shengong", 1);
        set_skill("parry", 1);
        set_skill("dodge", 1);
        set_skill("tiyunzong", 1);
        set_skill("sword", 1);
        set_skill("taiji-jian", 1);
        set_skill("cuff", 1);
        set_skill("taiji-quan", 1);

        map_skill("parry", "taiji-jian");
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("sword", "taiji-jian");
        map_skill("cuff", "taiji-quan");

        prepare_skill("cuff", "taiji-quan");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "unarmed.ji" :),
                (: exert_function, "recover" :),
        }) );

        set("class", "taoist");

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}
           
private void from_shaolin()
{
        set("scale", 150);
        set("from", ({
                "��˵���˳������֣������ֵ��׼Ҹ��֣���ȴû�а��ȱ�֮�ģ�����",
                "���Ŵ���͵ʦ�����֣�������һ�������׵ı��졣",
                "��˵���������ֵĻ�ͷ�ӣ�͵ѧ���պ󱻷��֣���Ȼ����"
                + "��ĦԺ���ϳ��������벻�����շ�����ԭ��",
                "��˵���˵��그�����ֵĽ��ɣ��������£��벻�����Ӷ���"
                + "�Ժ��Ȼ�س�������"
        }));

        set_skill("force", 1);
        set_skill("hunyuan-yiqi", 1);
        set_skill("parry", 1);
        set_skill("dodge", 1);
        set_skill("shaolin-shenfa", 1);
        set_skill("sword", 1);
        set_skill("damo-jian", 1);
        set_skill("finger", 1);
        set_skill("nianhua-zhi", 1);
        set_skill("strike", 1);
        set_skill("sanhua-zhang", 1);

        map_skill("parry", "damo-jian");
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("sword", "damo-jian");
        map_skill("finger", "nianhua-zhi");
        map_skill("strike", "sanhua-zhang");

        prepare_skill("finger", "nianhua-zhi");
        prepare_skill("strike", "sanhua-zhang");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sanjue" :),
                (: perform_action, "strike.sanhua" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set("class", "bonze");

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
 
private void from_huashan()
{
        set("scale", 130);
        set("from", ({
                "��˵���˳��Ի�ɽ���޶����������м���Ȼ�������벻�������ֳ�ͷ��",
                "���Ŵ��˱��ǻ�ɽ���ϣ�����֮��ԶͶ��أ���֪�ιʷ�����ԭ��",
                "��˵���˱��Ǳ����Ե׵���ɽȥ�ģ�͵ѧ�����Ժ�û�ر���"
                + "�����ٵؿ��ޣ��������ڵó�������",
        }));

        set_skill("force", 1);
        set_skill("zixia-shengong", 1);
        set_skill("parry", 1);
        set_skill("dodge", 1);
        set_skill("huashan-shenfa", 1);
        set_skill("sword", 1);
        set_skill("huashan-jianfa", 1);

        map_skill("parry", "huashan-jianfa");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("sword", "huashan-jianfa");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.wudui" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set("class", "fighter");

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

private void from_ouyang() 
{ 
        set("scale", 130); 
        set("from", ({ 
                "��˵����ԭ�ǵ���������ʦŷ������ֳ�����֪�ι�ʧ�٣���" 
                + "�վ�Ȼ�ֳ����ˡ�", 
                "���Ŵ���͵ѧ���������ɽׯŷ�����ҵ��书��������ŷ��" 
                + "�淢�ִ�����ˣ����˴��˶��ߣ���Ȼ����գ�����˼�飡", 
        })); 
        
        set_skill("force", 1); 
        set_skill("hamagong", 1); 
        set_skill("parry", 1); 
        set_skill("dodge", 1); 
        set_skill("chanchu-bufa", 1); 
        set_skill("staff", 1); 
        set_skill("lingshe-zhangfa", 1); 
        set_skill("cuff", 1); 
        set_skill("lingshe-quan", 1); 
        set_skill("finger", 1); 
        set_skill("shedu-qiqiao", 1); 
        set_skill("literate", 1); 
        set_skill("martial-cognize", 1); 
        
        map_skill("force", "hamagong"); 
        map_skill("parry", "lingshe-zhangfa"); 
        map_skill("dodge", "chanchu-bufa"); 
        map_skill("staff", "lingshe-zhangfa"); 
        map_skill("cuff", "lingshe-quan"); 
        map_skill("finger", "shedu-qiqiao"); 
              
        prepare_skill("cuff", "lingshe-quan"); 
        prepare_skill("finger", "shedu-qiqiao"); 
        
        set("chat_chance_combat", 100); 
        set("chat_msg_combat", ({ 
                (: perform_action, "staff.lingshe" :), 
                (: perform_action, "staff.wyji" :), 
                (: perform_action, "cuff.rou" :), 
                (: exert_function, "powerup" :), 
                (: exert_function, "recover" :), 
        }) ); 
        
        carry_object("/clone/weapon/gangzhang")->wield(); 
        carry_object("/clone/cloth/cloth")->wear(); 
} 
        
private void from_gaibang()
{
        set("scale", 130);
        set("from", ({
                "��˵����ԭ��ؤ�ﳤ�ϣ��书�߾���������������Ů�Ӷ���"
                + "������⣬�������ֽ�����������Ѫ���ȷ硣"
        }));

        set_skill("force", 1);
        set_skill("huntian-qigong", 1);
        set_skill("parry", 1);
        set_skill("dodge", 1);
        set_skill("xiaoyaoyou", 1);
        set_skill("staff", 1);
        set_skill("dagou-bang", 1);
        set_skill("strike", 1);
        set_skill("xianglong-zhang", 1);

        map_skill("force", "huntian-qigong");
        map_skill("parry", "dagou-bang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("staff", "dagou-bang");
        map_skill("strike", "xianglong-zhang");

        prepare_skill("strike", "dragon-strike");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
        }) );

        set("class", "begger");

        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
         
private void from_taohua()
{
        set("scale", 135);
        set("from", ({
                "��˵���˺��һ�������ҩʦ��Щ��ϵ��",
        }));

        set_skill("force", 1);
        set_skill("bihai-chaosheng", 1);
        set_skill("parry", 1);
        set_skill("dodge", 1);
        set_skill("suibo-zhuliu", 1);
        set_skill("sword", 1);
        set_skill("yuxiao-jianfa", 1);
        set_skill("strike", 1);
        set_skill("luoying-shenzhang", 1);
        set_skill("unarmed", 1);
        set_skill("xuanfeng-tui", 1);
        set_skill("hand", 1);
        set_skill("lanhua-shou", 1);
        set_skill("finger", 1);
        set_skill("tanzhi-shentong", 1);

	map_skill("force", "bihai-chaosheng");
	map_skill("dodge", "suibo-zhuliu");
	map_skill("strike", "luoying-shenzhang");
	map_skill("hand", "lanhua-shou");
	map_skill("finger", "tanzhi-shentong");
	map_skill("throwing", "tanzhi-shentong");
	map_skill("unarmed", "xuanfeng-tui");
	map_skill("parry", "yuxiao-jianfa");
	map_skill("sword", "yuxiao-jianfa");

	prepare_skill("strike", "luoying-shenzhang");
	prepare_skill("unarmed", "xuanfeng-tui");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: perform_action, "sword.qing" :),
                (: perform_action, "sword.tianwai" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "finger.jinglei" :),
                (: exert_function, "recover" :),
        }) );

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
          
private void from_gumu()
{
        object ob;

        set("scale", 130);
        set("from", ({
                "��˵�������ֳ�Ӣ�ĵ��ӣ��������ʦ���ˡ�",
                "���˾�˵�ǹ�Ĺ���ˣ�����Ī������ԨԴ��",
        }));

        set_skill("force", 1);
        set_skill("yunv-xinfa", 1);
        set_skill("parry", 1);
        set_skill("dodge", 1);
        set_skill("yunv-shenfa", 1);
        set_skill("unarmed", 1);
        set_skill("meinv-quan", 1);
        set_skill("strike", 1);
        set_skill("fireice-strike", 1);
        set_skill("tianluo-diwang", 1);
        set_skill("throwing", 1);
        set_skill("yufeng-zhen", 1);
        set_skill("sword", 1);
        set_skill("yunv-jian", 1);
        set_skill("quanzhen-jian", 1);

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");
        map_skill("strike", "tianluo-diwang");
        map_skill("throwing", "yufeng-zhen");

        prepare_skill("unarmed", "meinv-quan");
        prepare_skill("strike", "tianluo-diwang");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: perform_action, "strike.wang" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "unarmed.you" :),
                (: perform_action, "throwing.wuying" :),
        }) );

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        ob = carry_object("/d/gumu/obj/yfzhen");
        ob->set_amount(300);
        set_temp("handing", ob);
}

private void from_xingxiu()
{
        set("scale", 130);
        set("from", ({
                "��˵�����������ɵ��ӣ���Ϊ���������ɣ�ֻ���ӳ������ɡ�",
        }));

        set_skill("force", 1);
        set_skill("huagong-dafa", 1);
        set_skill("guixi-gong", 1);
        set_skill("throwing", 1);
        set_skill("feixing-shu", 1);
        set_skill("dodge", 1);
        set_skill("zhaixinggong", 1);
        set_skill("strike", 1);
        set_skill("chousui-zhang", 1);
        set_skill("claw", 1);
        set_skill("sanyin-wugongzhao", 1);
        set_skill("whip", 1);
        set_skill("chanhun-suo", 1);
        set_skill("parry", 1);
        set_skill("staff", 1);
        set_skill("poison", 1);
        set_skill("tianshan-zhang", 1);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("claw", "sanyin-wugongzhao");
        map_skill("whip", "chanhun-suo");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("strike", "chousui-zhang");
        prepare_skill("claw", "sanyin-wugongzhao");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "staff.fugu" :),
                (: perform_action, "staff.xue" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.huolang" :),
                (: perform_action, "strike.huoqiu" :),
                (: perform_action, "strike.huoyan" :),
                (: perform_action, "claw.zhua" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

private void from_xueshan()
{
        set("scale", 135);
        set("from", ({
                "��˵������ѩɽ�ɵĸ��֣�������ԭ�������޼ɣ��书�����˵á�",
        }));

        set_skill("force", 1);
        set_skill("longxiang-gong", 1);
        set_skill("mizong-neigong", 1);
        set_skill("dodge", 1);
        set_skill("shenkong-xing", 1);
        set_skill("cuff", 1);
        set_skill("yujiamu-quan", 1);
        set_skill("hand", 1);
        set_skill("dashou-yin", 1);
        set_skill("parry", 1);
        set_skill("staff", 1);
        set_skill("xiangmo-chu", 1);
        set_skill("lamaism", 1);
        set_skill("hammer", 1);
        set_skill("riyue-lun", 1);

        map_skill("force", "longxiang-gong");
        map_skill("dodge", "shenkong-xing");
        map_skill("cuff", "yujiamu-quan");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "xiangmo-chu");
        map_skill("hammer", "riyue-lun");

        prepare_skill("hand", "dashou-yin");
        prepare_skill("cuff", "yujiamu-quan");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "hammer.poli" :),
                (: perform_action, "hammer.wulun" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "cuff.chen" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        set("class", "bonze");

        carry_object("/d/xueshan/obj/yinlun")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

private void from_xuedao() 
{ 
        set("scale", 135); 
        set("from", ({ 
                "��˵���˺�����Ѫ��������ʦ�ֵܣ�һ����ĺ�������", 
        })); 
        
        set_skill("force", 1); 
        set_skill("xuehai-mogong", 1); 
        set_skill("blade", 1); 
        set_skill("dodge", 1); 
        set_skill("shenkong-xing", 1); 
        set_skill("hand", 1); 
        set_skill("dashou-yin", 1); 
        set_skill("cuff", 1); 
        set_skill("yujiamu-quan", 1); 
        set_skill("parry", 1); 
        set_skill("lamaism", 1); 
        set_skill("literate", 1); 
        set_skill("martial-cognize", 1); 
        
        map_skill("force", "xuehai-mogong"); 
        map_skill("dodge", "shenkong-xing"); 
        map_skill("hand", "dashou-yin"); 
        map_skill("cuff", "yujiamu-quan"); 
        map_skill("parry", "xuedao-dafa"); 
        map_skill("blade", "xuedao-dafa"); 
        map_skill("sword", "mingwang-jian"); 
        
        prepare_skill("cuff", "yujiamu-quan"); 
        prepare_skill("hand", "dashou-yin"); 
        
        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({ 
                (: perform_action, "blade.ying" :), 
                (: perform_action, "blade.chi" :), 
                (: perform_action, "blade.xue" :), 
                (: perform_action, "blade.shi" :), 
                (: perform_action, "hand.yin" :), 
                (: perform_action, "cuff.jiang" :), 
                (: exert_function, "recover" :), 
                (: exert_function, "resurrect" :), 
                (: exert_function, "powerup" :), 
        })); 
        
        set("class", "bonze"); 
        
        carry_object("/clone/weapon/gangdao")->wield(); 
        carry_object("/clone/misc/cloth")->wear(); 
} 
        
private void from_xiaoyao() 
{ 
        set("scale", 135); 
        set("from", ({ 
                "��˵���˺���ң�������ӱ���ͬ�ŵ��ӣ�������֪�ιʷ����ɳ�", 
        })); 
        
        set_skill("force", 1); 
        set_skill("beiming-shengong", 1); 
        set_skill("dodge", 1); 
        set_skill("feiyan-zoubi", 1); 
        set_skill("liuyang-zhang", 1); 
        set_skill("parry", 1); 
        set_skill("sword", 1); 
        set_skill("liuyue-jian", 1); 
        set_skill("zhemei-shou", 1); 
        set_skill("hand", 1); 
        set_skill("strike", 1); 
        set_skill("literate", 1); 
        set_skill("martial-cognize", 1); 
        
        map_skill("force", "beiming-shengong"); 
        map_skill("dodge", "feiyan-zoubi"); 
        map_skill("hand", "zhemei-shou"); 
        map_skill("strike", "liuyang-zhang"); 
        map_skill("parry", "liuyue-jian"); 
        map_skill("sword", "liuyue-jian"); 
        
        prepare_skill("hand","zhemei-shou"); 
        prepare_skill("strike","liuyang-zhang"); 
        
        set("class", "taoist"); 
        
        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({ 
                (: perform_action, "sword.liu" :), 
                (: perform_action, "sword.sheng" :), 
                (: perform_action, "hand.zhe" :), 
                (: perform_action, "hand.hai" :), 
                (: perform_action, "strike.zhong" :), 
                (: perform_action, "strike.huan" :), 
                (: exert_function, "recover" :), 
                (: exert_function, "shield" :), 
                (: exert_function, "powerup" :), 
        })); 
        
        carry_object("/clone/weapon/changjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear(); 
} 
        
private void from_shenlong() 
{ 
        set("scale", 135); 
        set("from", ({ 
                "��˵��������������������״����ӣ������г������̣�����������", 
        })); 
        
        set_skill("force", 1); 
        set_skill("shenlong-xinfa", 1); 
        set_skill("dodge", 1); 
        set_skill("yixingbu", 1); 
        set_skill("hand", 1); 
        set_skill("shenlong-bashi", 1); 
        set_skill("strike", 1); 
        set_skill("huagu-mianzhang", 1); 
        set_skill("parry", 1); 
        set_skill("staff", 1); 
        set_skill("sword", 1); 
        set_skill("shedao-qigong", 1); 
        set_skill("literate", 1); 
        set_skill("martial-cognize", 1); 
        
        map_skill("force", "shenlong-xinfa"); 
        map_skill("dodge", "yixingbu"); 
        map_skill("hand", "shenlong-bashi"); 
        map_skill("strike", "huagu-mianzhang"); 
        map_skill("parry", "shedao-qigong"); 
        map_skill("staff", "shedao-qigong"); 
        
        prepare_skill("strike", "huagu-mianzhang"); 
        prepare_skill("hand", "shenlong-bashi"); 
        
        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({ 
                (: perform_action, "strike.hua" :), 
                (: perform_action, "hand.xian" :), 
                (: exert_function, "powerup" :), 
                (: exert_function, "recover" :), 
        })); 
        
        carry_object("/clone/misc/cloth")->wear(); 
} 

private void from_lingjiu() 
{  
        set("scale", 130);
        set("from", ({   
                "���������չ�����ͽ����������������", 
        }));

        set_skill("force", 1);
        set_skill("bahuang-gong", 1);
        set_skill("dodge", 1);
        set_skill("yueying-wubu", 1);
        set_skill("strike", 1);
        set_skill("liuyang-zhang", 1);
        set_skill("hand", 1);
        set_skill("zhemei-shou", 1);
        set_skill("sword", 1);
        set_skill("tianyu-qijian", 1);

        map_skill("force", "bahuang-gong"); 
        map_skill("dodge", "yueying-wubu"); 
        map_skill("strike", "liuyang-zhang"); 
        map_skill("hand", "zhemei-shou"); 
        map_skill("sword", "tianyu-qijian"); 
        map_skill("parry", "tianyu-qijian"); 

        prepare_skill("strike", "liuyang-zhang");
        prepare_skill("hand", "zhemei-shou"); 

        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({  
                (: exert_function, "recover" :),  
                (: exert_function, "powerup" :),  
                (: perform_action, "hand.zhe" :), 
                (: perform_action, "sword.san" :), 
        }));

        carry_object("/clone/weapon/changjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear();
}  

private void from_mingjiao()
{ 
        set("scale", 130);
        set("from", ({  
                "���������̵���ͽ��",  
        }));

        set_skill("force", 1);
        set_skill("shenghuo-shengong", 1);
        set_skill("dodge", 1);
        set_skill("qingfu-shenfa", 1);
        set_skill("claw", 1);
        set_skill("yingzhua-shou", 1);
        set_skill("shenghuo-ling", 1);
        set_skill("parry", 1);  
        set_skill("sword", 1);
        set_skill("parry", 1);

        map_skill("parry", "shenghuo-ling"); 
        map_skill("sword", "shenghuo-ling"); 
        map_skill("dodge", "qingfu-shenfa"); 
        map_skill("force", "shenghuo-shengong"); 
        map_skill("claw", "yingzhua-shou"); 

        prepare_skill("claw", "yingzhua-shou"); 

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({  
                  (: perform_action, "sword.guanghua" :),  
                  (: perform_action, "claw.xue" :),  
                  (: exert_function, "recover" :), 
        }));

        carry_object("/clone/weapon/changjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear(); 
}

private void from_quanzhen() 
{ 
        set("scale", 150); 
        set("from", ({ 
               "��˵���˳���ȫ�棬��ȫ���ɸ��֡�", 
               "��˵�������������ĵ��ӣ��������ʦ���ˡ�", 
        }));

        set_skill("force", 1); 
        set_skill("xiantian-gong", 1); 
        set_skill("jinyan-gong", 1); 
        set_skill("dodge", 1); 
        set_skill("strike", 1); 
        set_skill("finger", 1); 
        set_skill("sword", 1); 
        set_skill("quanzhen-jian", 1); 
        set_skill("haotian-zhang", 1); 
        set_skill("zhongnan-zhi", 1); 
        set_skill("parry", 1); 

        map_skill("force", "xiantian-gong"); 
        map_skill("dodge", "jinyan-gong"); 
        map_skill("strike", "haotian-zhang"); 
        map_skill("finger", "zhongnan-zhi"); 
        map_skill("sword", "quanzhen-jian"); 
        map_skill("parry", "quanzhen-jian"); 

        prepare_skill("finger", "zhongnan-zhi"); 
        prepare_skill("strike", "haotian-zhang"); 

        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({ 
                (: exert_function, "powerup" :), 
                (: exert_function, "recover" :), 
                (: perform_action, "sword.ding" :), 
                (: perform_action, "sword.chan" :), 
                (: perform_action, "strike.ju" :), 
                (: perform_action, "finger.zhongnan" :), 
        }));

        carry_object("/clone/weapon/changjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear(); 
}

private void from_emei()
{
        //object ob;

        set("scale", 130);
        set("from", ({ 
               "��˵���������ʦ̫�ĵ��ӣ��������ʦ���ˡ�", 
               "�������ʦ̫�ĵ��ӣ����ĺ������ĵ��ӡ�", 
        })); 

       set_skill("force", 1); 
       set_skill("linji-zhuang", 1); 
       set_skill("parry", 1); 
       set_skill("dodge", 1); 
       set_skill("zhutian-bu", 1); 
       set_skill("sword", 1); 
       set_skill("huifeng-jian", 1); 
       set_skill("finger", 1); 
       set_skill("tiangang-zhi", 1); 
       set_skill("strike", 1); 
       set_skill("jinding-zhang", 1); 

       map_skill("force", "linji-zhuang"); 
       map_skill("dodge", "zhutian-bu"); 
       map_skill("sword", "huifeng-jian"); 
       map_skill("parry", "huifeng-jian"); 
       map_skill("finger", "tiangang-zhi"); 
       map_skill("strike", "jinding-zhang"); 

       prepare_skill("strike", "jinding-zhang"); 
       prepare_skill("finger", "tiangang-zhi"); 

       set("chat_chance_combat", 80);
       set("chat_msg_combat", ({ 
                 (: perform_action, "sword.mie" :), 
                 (: perform_action, "finger.lingkong" :), 
                 (: exert_function, "recover" :), 
                 (: exert_function, "powerup" :), 
        })); 

        set("class", "taoism"); 

        carry_object("/clone/weapon/changjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear(); 
} 

private void from_murong() 
{ 
       // object ob;

        set("scale", 130);
        set("from", ({  
               "��˵������Ľ���ɵ��ӣ����ڱ���ʦ�ţ���������������",  
        }));  

        set_skill("force", 1);
        set_skill("shenyuan-gong", 1);
        set_skill("dodge", 1);
        set_skill("beidou-xianzong", 1);
        set_skill("parry", 1);
        set_skill("douzhuan-xingyi", 1);
        set_skill("sword", 1);
        set_skill("murong-jianfa", 1);
        set_skill("cuff", 1);
        set_skill("qixing-quan", 1);
        set_skill("finger", 1);
        set_skill("canhe-zhi", 1);

        map_skill("force", "shenyuan-gong");  
        map_skill("dodge", "beidou-xianzong");  
        map_skill("parry", "douzhuan-xingyi");  
        map_skill("sword", "murong-jianfa");  
        map_skill("cuff", "qixing-quan");  
        map_skill("finger", "canhe-zhi");  

        prepare_skill("cuff", "qixing-quan");
        prepare_skill("finger", "canhe-zhi");

        set("chat_chance_combat", 80);  
        set("chat_msg_combat", ({  
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.qixing" :),  
                (: perform_action, "finger.lian" :),  
        })); 

        carry_object("/clone/weapon/changjian")->wield();  
        carry_object("/clone/misc/cloth")->wear();  
}

private void from_hujia()
{  
       // object ob; 

       set("scale", 130); 
       set("from", ({   
              "��˵�����Ǻ��ҵ��ӣ�����ʦ�ţ������С�",   
       }));

       set_skill("force", 1); 
       set_skill("lengyue-shengong", 1); 
       set_skill("dodge", 1); 
       set_skill("sixiang-bufa", 1); 
       set_skill("cuff", 1); 
       set_skill("hujia-quan", 1); 
       set_skill("strike", 1); 
       set_skill("tianchang-zhang", 1); 
       set_skill("blade", 1); 
       set_skill("hujia-daofa", 1); 
       set_skill("parry", 1); 

       map_skill("force", "lengyue-shengong");   
       map_skill("dodge", "sixiang-bufa");   
       map_skill("cuff", "hujia-quan");   
       map_skill("strike", "tianchang-zhang");   
       map_skill("blade", "hujia-daofa");   
       map_skill("parry", "hujia-daofa");   

       prepare_skill("cuff", "hujia-quan"); 
       prepare_skill("strike", "tianchang-zhang"); 

       set("chat_chance_combat", 80);  
       set("chat_msg_combat", ({   
               (: perform_action, "blade.bafang" :),  
               (: perform_action, "cuff.kuai" :),  
               (: exert_function, "recover" :),  
               (: exert_function, "powerup" :),  
       }));

       carry_object("/clone/weapon/gangdao")->wield();  
       carry_object("/clone/misc/cloth")->wear();   
} 

private void from_duanshi()
{
        set("scale", 135); 
        set("from", ({ 
               "��˵���˺Ͷμ���Щ��ϵ��", 
        }));

        set_skill("force", 1); 
        set_skill("kurong-changong", 1); 
        set_skill("sword", 1); 
        set_skill("duanjia-jian", 1); 
        set_skill("parry", 1); 
        set_skill("dodge", 1); 
        set_skill("cuff", 1); 
        set_skill("tiannan-bufa", 1); 
        set_skill("jinyu-quan", 1); 
        set_skill("strike", 1); 
        set_skill("wuluo-zhang", 1); 
        set_skill("yiyang-zhi", 1); 
        set_skill("finger", 1); 

        map_skill("force", "kurong-changong");    
        map_skill("sword", "duanjian-jian");    
        map_skill("cuff", "jinyu-quan");    
        map_skill("strike", "wuluo-zhang");    
        map_skill("finger", "yiyang-zhi");    
        map_skill("dodge", "tiannan-bufa");    
        map_skill("parry", "duanjian-jian");    

        prepare_skill("finger", "yiyang-zhi");     

        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({   
                (: exert_function, "powerup" :), 
                (: exert_function, "recover" :), 
                (: perform_action, "sword.jing" :), 
                (: perform_action, "finger.qiankun" :), 
        }));

        carry_object("/clone/weapon/changjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear();   
} 
