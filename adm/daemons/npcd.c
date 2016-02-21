// npcd.c

#pragma optimize
#pragma save_binary

#include <command.h>
#include <npc/name.h>
#include <npc/chinese.c>
#include <npc/japanese.c>
#include <npc/european.c>
#include <npc/masia.c>
#include <npc/indian.c>

#define HUANG_SHANG             "/kungfu/class/ultra/huang"
#define DUGU_QIUBAI             "/kungfu/class/ultra/dugu"
#define KUIHUA_TAIJIAN          "/kungfu/class/ultra/kuihua"
#define NANHAI_SHENNI           "/kungfu/class/ultra/shenni"

mapping levels = ([
//      combat_exp   skill_level
        "50000"      : 60,                // level 1
        "100000"     : 80,                // level 2
        "200000"     : 100,               // level 3
        "400000"     : 125,               // level 4
        "800000"     : 150,               // level 5
        "1200000"    : 175,               // level 6
        "1600000"    : 200,               // level 7
        "2000000"    : 225,               // level 8
        "2500000"    : 250,               // level 9
        "2700000"    : 275,               // level 10
        "3000000"    : 300,               // level 11
        "5000000"    : 350,               // level 12
        "7500000"    : 400,               // level 13
        "9000000"    : 450,               // level 14
        "15000000"   : 500,               // level 15
        "50000000"   : 600,               // level 16
        "100000000"  : 700,               // level 17
        "200000000"  : 800,               // level 18
        "400000000"  : 900,               // level 19
        "600000000"  : 1000,              // level 20
        "800000000"  : 1100,              // level 21
        // "1500000000" : 1500,              // level 22
        "3000000000" : 2000,              // level 23
        "5000000000" : 3000,              // level 24
        "8000000000" : 4000,              // level 25
]);

mapping place = ([
        "������"   : ({ "/d/luoyang/xidoor", "/d/luoyang/beidoor",
                        "/d/luoyang/dongdoor", "/d/luoyang/nandoor",
                        "/d/luoyang/juyi", "/d/luoyang/nantou",
                        "/d/luoyang/suanming", "/d/luoyang/laofang",
                        "/d/luoyang/center", "/d/luoyang/nantou2", }),
        "�����"   : ({ "/d/kaifeng/road4", "/d/kaifeng/zhuque",
                        "/d/kaifeng/yanqing", "/d/kaifeng/huiguan",
                        "/d/kaifeng/nanying", "/d/kaifeng/fangsheng", }),
        "���ݳ�"   : ({ "/d/zhongzhou/shizhongxin", "/d/zhongzhou/nanmeng",
                        "/d/zhongzhou/beimen", "/d/zhongzhou/chenglou",
                        "/d/zhongzhou/yanlingdong1", "/d/zhongzhou/inpomiao", }),
        "������"   : ({ "/d/kunming/nandajie2", "/d/kunming/yunnan1",
                        "/d/kunming/xiaoximen", "/d/kunming/xiaolu", }),
        "���ݳ�"   : ({ "/d/jingzhou/guangchang", "/d/jingzhou/jznanmen",
                        "/d/jingzhou/wenquan", "/d/jingzhou/zizhulin", }),
        "���ݳ�"   : ({ "/d/lanzhou/guangchang", "/d/lanzhou/nroad1",
                        "/d/lanzhou/nanmen", "/d/lanzhou/ximen", }),                                                
        "��ɽ����" : ({ "/d/huashan/pingxinshi", "/d/village/square",
                        "/d/village/wexit", }),
        "���ݳ�"   : ({ "/d/city/beimen", "/d/city/nanmen",
                        "/d/city/ximen", "/d/city/dongmen", }),
	"������"   : ({ "/d/changan/dong-chengmen", "/d/changan/nan-chengmen",
			"/d/changan/xi-chengmen", "/d/changan/bei-chengmen",
                        "/d/changan/qinglong2", "/d/changan/baihu2", }),
        "�书��"   : ({ "/d/quanzhen/xijie", "/d/quanzhen/nanjie", }),
        "��ɽһ��" : ({ "/d/foshan/street1", "/d/foshan/southgate", }),
        "�Ϻ�һ��" : ({ "/d/xiakedao/xkroad4" }),
        "����һ��" : ({ "/d/shaolin/ruzhou" }),
        "��ɽһ��" : ({ "/d/songshan/tianzhongge", "/d/shaolin/shijie1",
			"/d/shaolin/shijie8", }),
	"����ɽ"   : ({ "/d/quanzhen/shanlu1", "/d/quanzhen/shijie1",
			"/d/quanzhen/shijie9", "/d/quanzhen/cuipinggu",
			"/d/quanzhen/baishulin3", "/d/gumu/taiyi1",
                        "/d/gumu/shenheyuan", "/d/quanzhen/banshanting", }),
        "�ɶ���"   : ({ "/d/city3/southroad1", "/d/city3/qingyanggong",
                        "/d/city3/northroad2", }),
        "���޺�"   : ({ "/d/xingxiu/tianroad2", }),
	"��ɽ"     : ({ "/d/lingjiu/yan", }),
        "���ݳ�"   : ({ "/d/suzhou/xidajie2", "/d/suzhou/dongdajie2",
			"/d/suzhou/road5", "/d/suzhou/road1",
                        "/d/suzhou/gumujiaohe", "/d/suzhou/zhenquting", }),
        "���ݳ�"   : ({ "/d/hangzhou/suti2", "/d/hangzhou/jujingyuan",
			"/d/hangzhou/liuzhuang", "/d/hangzhou/road19",
                        "/d/hangzhou/huangniling", "/d/hangzhou/qinglindong", }),
        "������"   : ({ "/d/xiangyang/westjie2", "/d/xiangyang/southjie2",
			"/d/xiangyang/xiaorong1", "/d/xiangyang/zhonglie",
                        "/d/xiangyang/guangchang", "/d/xiangyang/dingzi", }),
        "Ȫ�ݳ�"   : ({ "/d/quanzhou/zhongxin", }),
        "���ݳ�"   : ({ "/d/fuzhou/ximendajie", "/d/fuzhou/dongxiaojie",
                        "/d/fuzhou/nanmen", }),
        "����"     : ({ "/d/lingzhou/xidajie", "/d/lingzhou/nanmen",
                        "/d/lingzhou/dongdajie", }),
	"����"     : ({ "/d/guanwai/baihe", "/d/guanwai/road8",
			"/d/guanwai/xuedi1", "/d/guanwai/beicheng",
                        "/d/guanwai/shanshenmiao" }),
        "����"     : ({ "/d/xingxiu/shamo5", "/d/baituo/gebi",
                        "/d/xueshan/shenghu", "/d/xueshan/hubian4",
                        "/d/xuedao/sroad3", "/d/xuedao/nroad6",
                        "/d/xingxiu/nanjiang2" }),
        "����һ��" : ({ "/d/dali/northgate", "/d/dali/southgate",
                        "/d/dali/shanlu2", "/d/dali/buxiongbu",
                        "/d/dali/jinzhihe", "/d/dali/xiaodao1",
                        "/d/dali/tianweijing", "/d/dali/wuding",
                        "/d/dali/luwang", "/d/dali/gudao",
                        "/d/dali/biluoxueshan", "/d/dali/zhenxiong",
                        "/d/dali/yixibu", "/d/dali/cangshanzhong",
                        "/d/dali/wumeng", "/d/dali/hongsheng", }),
]);

// return the character(ob) 's level, 0 is lowest
int check_level(object ob)
{
        int *exp;
        int i;

        exp = sort_array(keys(levels), 1);
        for (i = 0; i < sizeof(exp); i++)
                if (count_lt(ob->query("combat_exp"), exp[i])) break;
        return i;
}

int sort_level(string f1, string f2) 
{
        return levels[f1] - levels[f2];
}

// set the the level of the npc's skill
void init_npc_skill(object ob, int lvl)
{
        int sk_lvl;
        string *ks;
        int i;
        mixed exp;

        if (lvl < 1) lvl = 1;
        if (lvl >= sizeof(levels)) lvl = sizeof(levels) - 1;

        exp = sort_array(keys(levels), (: sort_level :))[lvl - 1];
        ob->set("combat_exp", exp);
        sk_lvl = levels[exp];
        if (! ob->query_skills())
                return;
        ks = keys(ob->query_skills());
        for (i = 0; i < sizeof(ks); i++)
                ob->set_skill(ks[i], sk_lvl);
}

string *nations = ({ "�й�", "�ձ�", "���", "����", "����", "�ɹ�",
                     "����˹", "Ӣ����", "������", "������", "������",
                     "����ʱ", "������˹̹", "��ɳ��˹̹", "���ȱ��˹̹" });

// generate a npc with nation & skill level
object create_npc(string nation, int lvl)
{
        object ob;

        switch (nation)
        {
        case "�й�":
                ob = new(CLASS_D("generate") + "/chinese");
                NPC_D->generate_cn_name(ob);
                break;
        case "�ձ�":
                ob = new(CLASS_D("generate") + "/japanese");
                NPC_D->generate_jp_name(ob);
                break;
        case "Ӣ����":
        case "������":
        case "������":
        case "������":
        case "����ʱ":
        case "����":
                ob = new(CLASS_D("generate") + "/european");
                NPC_D->generate_e_name(ob);
                break;
        case "����":
                ob = new(CLASS_D("generate") + "/indian");
                NPC_D->generate_in_name(ob);
                break;
        case "������ģ":
        case "���":
        case "����˹":
        case "������˹̹":
        case "��ɳ��˹̹":
        case "���ȱ��˹̹":
        case "�ɹ�":
                return 0;
        }

        ob->set("nation", nation);
        init_npc_skill(ob, lvl);

        return ob;
}

// generate challenger
object create_challenger()
{
        string *n;
        object *ob;
        int max_level;
        int i;
	int lvl;

        ob = all_interactive();
        max_level = 0;
        for (i = 0; i < sizeof(ob); i++)
                if (! wizardp(ob[i]) && max_level < check_level(ob[i]))
                        max_level = check_level(ob[i]);

        max_level++;
	lvl = 1 + random(max_level);
	if (lvl < 3) lvl = max_level;

        n = ({ "�ձ�", "�ձ�", "�ձ�",
               "����",
	       "Ӣ����", "������", "������", "������", "����ʱ", "����", });
        return create_npc(n[random(sizeof(n))], lvl);
}

// set the basic parameter from me
void set_from_me(object tob, object fob, int scale)
{
        mapping my, hp_status;

        hp_status = fob->query_entire_dbase();
        my = tob->query_entire_dbase();

        if (! scale)
        {
                if (undefinedp(my["scale"]))
                        my["scale"] = 100;
                scale = my["scale"];
        }

        my["str"] = hp_status["str"] * scale / 100;
        my["int"] = hp_status["int"] * scale / 100;
        my["con"] = hp_status["con"] * scale / 100;
        my["dex"] = hp_status["dex"] * scale / 100;

        my["max_qi"]     = hp_status["max_qi"]   * scale / 100;
        my["eff_qi"]     = my["max_qi"];
        my["qi"]         = my["max_qi"];
        my["max_jing"]   = hp_status["max_jing"] * scale / 100;
        my["eff_jing"]   = my["max_jing"];
        my["jing"]       = my["max_jing"];
        my["max_neili"]  = hp_status["max_neili"]* scale * 2 / 300;
        my["jiali"]      = tob->query_skill("force") / 3;
        if (my["max_neili"] > 50000)
                // max_neili not more then 9k
                my["max_neili"] = 50000;
        my["neili"]      = my["max_neili"] * 2;

        tob->set_from_me(fob, scale);
}

// select a random place
string random_place(string *not_place)
{
        string *kp;

        kp = keys(place);

        // exclude some place
        if (arrayp(not_place))
                kp -= not_place;

        // select a random place
        return kp[random(sizeof(kp))];
}

// place npc
void place_npc(object ob, string *not_place, string *in_place)
{
        string *kp;
        string p;
        string startroom;
        object pos;

        // select the place
        if (! arrayp(in_place))
                kp = keys(place);
        else
                kp = in_place;

        // exclude some place
        if (arrayp(not_place))
                kp -= not_place;

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
        ob->set_temp("moved", ({ }));
        message_vision("$N���˹�����\n", ob);
}

#define MAX_MOVED       5

// random move
void random_move(object ob)
{
        mapping exits;
        string *moved;
        string dir;
        string *dirs;
        int i;

        moved = ob->query_temp("moved");
        if (! moved) moved = ({ });
        if (sizeof(moved) >= MAX_MOVED)
        {
                // out of range, move back
                dir = GO_CMD->query_reverse(moved[sizeof(moved) - 1]);
        } else
        {
                exits = environment(ob)->query("exits");
                dirs = keys(exits);
                if (pointerp(dirs) && member_array("enter", dirs) != -1)
                        dirs -= ({ "enter" }); 
                for (i = 0; i < 12; i++)
                {
                	if (! sizeof(dirs))
                		return;
                        dir = dirs[random(sizeof(dirs))];
                        /*
                        if (dir != "south" && dir != "north" && dir != "west" &&
                            dir != "east" && dir != "up" && dir != "northup" &&
                            dir != "eastup" && dir != "westup" && dir != "southup" &&
                            dir != "down" && dir != "northdown" && dir != "eastdown" &&
                            dir != "westdown" && dir != "southdown" && dir != "northeast" &&
                            dir != "southeast" && dir != "northwest" && dir != "southwest")
                                dirs -= ({ dir });
                        */

                        if (stringp(GO_CMD->query_reverse(dir)) &&
                            get_object(exits[dir]) &&
                            ! exits[dir]->query("room_id") &&
                            ! exits[dir]->query("no_fight"))
                                break;
                                
                        if (pointerp(dirs) && member_array(dir, dirs) != -1) 
                                dirs -= ({ dir });
                }
        }

        if (sizeof(moved) &&
            GO_CMD->query_reverse(dir) == moved[sizeof(moved) - 1])
        {
                // move back
                moved = moved[0..<2];
        } else
                moved += ({ dir });
        ob->set_temp("moved", moved);

        GO_CMD->main(ob, dir);
}

// get all ultra master
object *query_ultra_master()
{
        return ({ get_object(HUANG_SHANG),
                  get_object(DUGU_QIUBAI),
                  get_object(KUIHUA_TAIJIAN),
                  get_object(NANHAI_SHENNI) });
}

//���������ڲ��ҵص��б�Ĵ���
void check_all_place()
{
        int i,j;
        string *all_city,*the_place;
        object env;

	all_city = keys(place);
        for (i = 0;i < sizeof(all_city);i++)
        {
                the_place = place[all_city[i]];
                for (j = 0;j<sizeof(the_place);j++)
                        if (!objectp(env = get_object(the_place[j])))
                                log_file("static/party_quest",sprintf("������������¼��%s\n",the_place[j]));
        }
}

void copy_skill(object src, object des, int skill_multi, int status_multi)
{
       // int num , max_skl , i;
       int max_skl,i;
        mixed dexp;
        int exper;
        mapping skl , hp_status , skl_p;
        string *sname,*sname_p;

        hp_status = src->query_entire_dbase();
        des->set("max_qi",    status_multi*hp_status["max_qi"]/100);
        des->set("eff_qi",    status_multi*hp_status["max_qi"]/100);
        des->set("qi",        status_multi*hp_status["max_qi"]/100);
        des->set("max_jing",  status_multi*hp_status["max_jing"]/100);
        des->set("eff_jing",  status_multi*hp_status["max_jing"]/100);
        des->set("jing",      status_multi*hp_status["max_jing"]/100);
        des->set("max_neili", status_multi*hp_status["max_neili"]/100);
        des->set("neili",     status_multi*hp_status["max_neili"]/100);
        des->set("jiali",     50);
        des->set("combat_exp",count_add(count_div(status_multi*hp_status["combat_exp"], 100), 5000));
        
       	dexp = count_div(des->query("combat_exp"), 100);             
       	sscanf(dexp, "%d", exper);               
     	max_skl = to_int(pow(to_float(exper), 1.0 / 3)) * 10 + 1;

        // max_skl = ceil( pow( to_float(exper)*10.0, 0.333333) );

        skl = des->query_skills();
                
        skl_p = src->query_skills();
        if (max_skl < 80) max_skl = 80;

        if (! sizeof(skl_p))
        {
                sname  = sort_array( keys(skl), (: strcmp :) );
                for (i = 0; i < sizeof(skl); i++)
                {
                        des->set_skill(sname[i],max_skl);
                }
        }else{
                sname_p  = sort_array( keys(skl_p), (: strcmp :) );

                for (i = 0; i < sizeof(skl_p); i++)
                {
                        if (skl_p[sname_p[i]] > max_skl) 
                                max_skl = skl_p[sname_p[i]];
                }
                // max_skl -= 20;

                if (max_skl < 80) max_skl = 80;

                sname  = sort_array( keys(skl), (: strcmp :) );
                for (i = 0; i < sizeof(skl); i++)
                {
                        des->set_skill(sname[i], skill_multi * max_skl/100);
                }
        }
        return;
}
