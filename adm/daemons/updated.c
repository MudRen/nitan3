// updated.c
// write by Doing Lu for user management
// because a user may does much association with others,
// so I must assure all the data keep consistant

#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <room.h>
//#include <rmtree.c>

inherit F_SAVE;

#define MAZE_DIR        "/data/maze/" 

// data need save
mixed title_base;
nosave mixed max_exp = 50000000;

string query_save_file() { return DATA_DIR "pinfo"; }

void remove_title(object ob);
void set_title(object ob);
object global_find_player(string user);
void global_destruct_player(object ob, int raw);
// mixed query_max_exp() { return max_exp; }
mixed query_max_exp() { return "2000000000"; }

void create()
{
        seteuid(getuid());
        restore();

        if (arrayp(title_base))
                title_base = filter_array(title_base, (: arrayp($1) && sizeof($1) == 2 :));
        else
                title_base = 0;
}

#define LUBAN           "/adm/npc/luban"
#define RING_DIR        "/data/item/ring/"

// check the user's data when login
void check_user(object ob)
{
        mapping my;
        mapping skill_status;
        string *sname;
        mixed combat_exp;
        int level;
        int i;
        mapping party;
        //object budai;

        my = ob->query_entire_dbase();

        if (ob->query("family/generation") == 0)
                ob->delete("family");

        if (ob->query("gender") == "����")
                ob->set("class", "eunach");

        if ((int)ob->query("combat/today/which_day") != time() / 86400)
                ob->delete("combat/today");

        if (ob->query("couple") && ! ob->query("static/marry"))
                ob->set("static/marry", 1);
        /*
        if (ob->query("family/family_name") == "ؤ��" &&
            ob->query("family/beggarlvl"))
        {
                budai = new("/d/gaibang/obj/budai");
                budai->set_amount((int)ob->query("family/beggarlvl"));
                budai->move(ob);
                budai->wear();
        }
        */
        if (mapp(party = my["party"]) && stringp(party["party_name"]))
                party["party_name"] = filter_color(party["party_name"]);

        // ��¼����
        NAME_D->map_name(ob->query("name"), ob->query("id"));

        // �����������м�ʱ��
        reset_eval_cost();

        // ����ƺ�
        set_title(ob);

        if (ob->query("have_meirong_dan") && !ob->query_temp("meirong_dan_used"))
        {
                ob->add_temp("apply/per",ob->query("have_meirong_dan"));
                ob->set_temp("meirong_dan_used",1);
        }

        if (undefinedp(my["eff_jing"]))  my["eff_jing"] = my["max_jing"];
        if (undefinedp(my["eff_qi"])) my["eff_qi"] = my["max_qi"];
        if (my["eff_jing"] > my["max_jing"]) my["eff_jing"] = my["max_jing"];
        if (my["eff_qi"] > my["max_qi"]) my["eff_qi"] = my["max_qi"];
        if (my["jing"] > my["eff_jing"]) my["jing"] = my["eff_jing"];
        if (my["jing"] > my["eff_jing"]) my["jing"] = my["eff_jing"];
        if (my["neili"] > my["max_neili"] * 2) my["neili"] = my["max_neili"] * 2;

        combat_exp = ob->query("combat_exp");
        if (! wizardp(ob) && count_gt(combat_exp, max_exp))
                max_exp = combat_exp;

        if (! mapp(skill_status = ob->query_skillc()))
                return;
        sname  = keys(skill_status);

        for (i = 0; i < sizeof(sname); i++)
        {
                if (ob->query("zhuanshi") || ob->query("jieti"))
                        continue;

                level = skill_status[sname[i]];
                if( !find_object(SKILL_D(sname[i])) && !load_object(SKILL_D(sname[i])) )
                {
                        tell_object(ob, "No such skill:" + sname[i] + "\n");
                        continue;
                }

                if (SKILL_D(sname[i])->type() == "martial")
                {
                        while (level &&
                               count_gt(count_div(count_mul(count_mul((level -1), (level -1)), (level -1)), 10), combat_exp))
                               level--;

                        ob->set_skill(sname[i], level);
                }
        }

        /*
        if ((level = ob->query_skill("zuoyou-hubo", 1)) > 0)
                ob->add_temp("apply/parry", -level / 4);
        */
        SKILLS_D->add_id_into_skills(ob);
}

// clear the user's data
// when catalog parameter equal to "all", I will remove all
// the informatino of this user. This may be used when the
// user was purged.
string clear_user_data(string user, string cat)
{
        object login_ob;
        object ob;
        string couple_id;
        string path, file_name;
        string *dirs;
        object temp;
        string brothers;
        string bro_id;
        string *ks;
        mapping bro;
        int flag;
        int i;

        // only root uid can does it
        if (previous_object() &&
            getuid(previous_object()) != ROOT_UID &&
            geteuid(previous_object()) != "lonely" &&
            geteuid(previous_object()) != user)
                return "����Ȩ�������ҵ����ݡ�\n";

        // find the user's body
        seteuid(getuid());
        login_ob = 0;
        ob = find_player(user);
        if (! ob)
        {
                login_ob = new(LOGIN_OB);
                login_ob->set("id", user);
                ob = LOGIN_D->make_body(login_ob);
                if (! ob)
                {
                        catch(destruct(login_ob));
                        return "��ʱ�޷�������Ҷ���\n";
                }

                if (! ob->restore())
                {
                        catch(destruct(login_ob));
                        catch(destruct(ob));
                        return "û�������ҡ�\n";
                }

                ob->setup();
        }

        // no catalog? treat it as "all"
        if (! cat) cat = "all";
        flag = 0;

        // remove name information
        if (cat == "name" || cat == "all")
                NAME_D->remove_name(ob->query("name"), ob->query("id"));

        // remove room information
        if ((cat == "room" || cat == "all") &&
            mapp(ob->query("private_room")))
        {
                // Demolish the room of the user
                LUBAN->demolish_room(ob);
                flag++;
        }

        // remove marriage information
        if ((cat == "couple" || cat == "all") &&
            mapp(ob->query("couple")))
        {
                // clear the couple infomation

                // remove the ring
                file_name = RING_DIR + ob->query("id");
                if (file_size(file_name + ".c") > 0)
                {
                        if (temp = find_object(file_name))
                        {
                                if (environment(temp))
                                {
                                        message("vision", HIM + temp->name() +
                                                HIM "��Ȼ����һ�����̣������ˣ�\n" NOR,
                                                environment(temp));
                                }
                        }
                        DBASE_D->clear_object(file_name);
                }

                couple_id = ob->query("couple/couple_id");
                ob->delete("couple");
                ob->delete("can_summon/wedding ring");
                if (! sizeof(ob->query("can_summon")))
                        ob->delete("can_summon");
                flag++;
                if (couple_id) clear_user_data(couple_id, "couple");
        }

        // remove item information
        if (cat == "item" || cat == "all")
        {
                object item;
                mapping sum;

                // clear the all item
                path = ITEM_DIR + ob->query("id")[0..0] + "/";
                dirs = get_dir(path + ob->query("id") + "-*");
                for (i = 0; i < sizeof(dirs); i++)
                {
                        file_name = path + dirs[i];
                        if ((item = find_object(file_name)) &&
                            environment(item))
                        {
                                message("vision", HIM + item->name() +
                                        "��Ȼ����һ�����̣������ˣ�\n" NOR,
                                        environment(item));
                        }

                        // rememberd by doing, for keep the item'sdata in dbased
                        DBASE_D->clear_object(file_name);
                        rm(file_name);
                }

                if (mapp(sum = ob->query("can_summon")))
                {
                        // clear summon information
                        ks = keys(sum);
                        for (i = 0; i < sizeof(ks); i++)
                                if (sscanf(sum[ks[i]], path + ob->query("id") + "-%*s") == 1)
                                        map_delete(sum, ks[i]);

                        if (! sizeof(sum))
                                ob->delete("can_summon");
                }
        }

        if (cat == "maze" || cat == "all")
        {
                rmtree( MAZE_DIR + ob->query("id") + "/" );
        }

        // remove cruise information
        if (cat == "cruise" || cat == "all")
        {
                // clear the all item
                file_name = ITEM_DIR + "curise/" + ob->query("id");
                if (file_size(file_name + ".c") > 0)
                {
                        if (temp = find_object(file_name))
                        {
                                if (environment(temp))
                                {
                                        message("vision", HIM + temp->name() +
                                                HIM "��Ȼ����һ�����̣������ˣ�\n" NOR,
                                                environment(temp));
                                }
                        }
                        DBASE_D->clear_object(file_name);
                        rm(file_name + ".c");
                }
                ob->delete("can_summon/cruise ob");
                if (! sizeof(ob->query("can_summon")))
                        ob->delete("can_summon");
        }

        // remove beast information
        if (cat == "beast" || cat == "all")
        {
                mapping whi;

                file_name = DATA_DIR + "beast/" + ob->query("id") + "-beast";
                if (file_size(file_name + ".c") > 0)
                {
                        if (temp = find_object(file_name))
                        {
                                if (environment(temp))
                                {
                                        message("vision", HIM + temp->name() +
                                                HIM "��Ȼ����һ�����̣������ˣ�\n" NOR,
                                                environment(temp));
                                }
                        }
                        DBASE_D->clear_object(file_name);
                        rm(file_name + ".c");
                }
                if (mapp(whi = ob->query("can_whistle")))
                {
                        // clear summon information
                        ks = keys(whi);
                        for (i = 0; i < sizeof(ks); i++)
                                if (whi[ks[i]] == file_name)
                                        ob->delete("can_whistle/" + ks[i]);

                        if (! sizeof(ob->query("can_whistle")))
                                ob->delete("can_whistle");
                }

        }

        // remove invent information
        if (cat == "invent" || cat == "all")
        {
                mapping invents;
                string  *meskill;

                if (mapp(invents = ob->query("invent")))
                {
                        meskill = keys(invents);
                        for (i = 0; i < sizeof(meskill); i++)
                        {
                                CHINESE_D->remove_translate(invents[meskill[i]]);
                                SKILLS_D->remove_skill_from_skills(ob, invents[meskill[i]]);
                                ob->delete_skill(invents[meskill[i]]);
                                rm( SKILL_D(invents[meskill[i]]) + ".c" );
                                rmtree( SKILL_D(invents[meskill[i]]) + "/" );
                        }

                        ob->delete("invent");
                }
        }

        // remove create information
        if (cat == "create" || cat == "all")
        {
                mapping creates;
                string  *skills, *perform;
                string  dir;
                object  pob;

                if (mapp(creates = ob->query("create")))
                {
                        skills = keys(creates);
                        for (i = 0; i < sizeof(skills); i++)
                        {
                                dir = SKILL_D(skills[i]);
                                if (dir[strlen(dir) - 1] != '/')
                                        dir += "/";
                                if (SKILL_D(skills[i])->valid_enable("force"))
                                        dir += "perform/";
                                perform = keys(creates[skills[i]]);
                                foreach (string pfm in perform)
                                {
                                        if (pob = get_object(dir + pfm))
                                                destruct(pob);
                                        rm(dir + pfm + ".c");
                                        ob->delete("can_perform/" + skills[i] + "/" + pfm);
                                }
                                if (sizeof(get_dir(dir)) < 1)
                                        rmdir(dir);
                        }
                        ob->delete("create");
                }
        }

        // remove board information
        if (cat == "board" || cat == "all")
        {
                object *rooms;
                rooms = filter_array(children(CHAT_ROOM),
                                     (: clonep($1) && $1->query("owner_id") == $(user) :));
                for (i = 0; i < sizeof(rooms); i++)
                        destruct(rooms[i]);
                file_name = DATA_DIR + "board/chatroom_" + user + __SAVE_EXTENSION__;
                rm(file_name);
        }

        // remove haterd information
        if (cat == "hatred" || cat == "all")
        {
                // remove the hatred information about the
                // familys & leagues to this player
                FAMILY_D->remove_hatred(ob->query("id"));
                LEAGUE_D->remove_hatred(ob->query("id"));
                BUNCH_D->remove_hatred(ob->query("id"));
        }

        // remove brothers information
        if (mapp(bro = ob->query("brothers")) &&
            (sscanf(cat, "brothers:%s", brothers) == 1 || cat == "all"))
        {
                // remove all the brothers information
                if (cat == "all") brothers = "all";

                // here, I remove the brothers information of
                // ob, when brothers equal to "all", then I
                // will remove all brothers for this ob, Does it
                // cause a BUG? I won't, because the ID "all"
                // can not be registered for this MUD.
                if (brothers == "all")
                {
                        foreach (bro_id in keys(bro))
                                // remove my brother's data for me
                                clear_user_data(bro_id, "brothers:" + ob->query("id"));

                        ob->delete("brothers");
                } else
                if (! undefinedp(bro[brothers]) != -1)
                {
                        // remove this brother
                        map_delete(bro, brothers);
                        if (sizeof(bro) < 1)
                                ob->delete("brothers");
                        else
                                ob->set("brothers", bro);
                }
                flag++;
        }

        // remove league information
        if (cat == "league" || cat == "all")
        {
                // remove the user's league info
                LEAGUE_D->remove_member_from_league(ob);
                ob->delete("league");
        }

        // remove bunch information
        if (cat == "bunch" || cat == "all")
        {
                // remove the user's banghui info
                BUNCH_D->remove_member_from_bunch(ob);
                ob->delete("bunch");
                flag++; 
        }

        if (cat == "skill" || cat == "all")
                SKILLS_D->remove_id_from_skills(ob);

        // remove title information
        if (cat == "title" || cat == "all")
                remove_title(ob);

        // remove granted information
        if (cat == "grant" || cat == "all")
                SECURITY_D->remove_grant(ob, "*");

        // save the data of the user
        if (flag) ob->save();

        // Destrut the object if create temporate
        if (login_ob)
        {
                catch(destruct(login_ob));
                catch(destruct(ob));
        }

        return "�ɹ���\n";
}

// remove an user
string remove_user(string user)
{
       // int sec;
        object ob;
        string result;
        string flogin, fuser;

        if (user == "lonely") return "���󲻿���Ү��";

        // destruct the user object
        if (ob = find_player(user))
        {
                if (ob->query_temp("link_ob"))
                        catch(destruct(ob->query_temp("link_ob")));
                catch(destruct(ob));
        }

        // Remove the user from wizlist if the user was wizard
        SECURITY_D->set_status(user, "(player)");

        flogin = "login/" + user[0..0] + "/" + user + __SAVE_EXTENSION__;
        fuser  = "user/"  + user[0..0] + "/" + user + __SAVE_EXTENSION__;
        assure_file(TEMP_DIR + flogin);
        assure_file(TEMP_DIR + fuser);

        // clear the data of user first
        result = clear_user_data(user, "all");

#ifdef DB_SAVE
        if (! DATABASE_D->query_db_status())
                DATABASE_D->connect_to_database();
        DATABASE_D->db_remove_player(user);

        if (TX_SAVE)
        {
                cp(DATA_DIR + flogin, TEMP_DIR + flogin);
                cp(DATA_DIR + fuser,  TEMP_DIR + fuser);
                // remove the file of the user
                rm(DATA_DIR + "login/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
                rm(DATA_DIR + "user/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
        }
#else
        cp(DATA_DIR + flogin, TEMP_DIR + flogin);
        cp(DATA_DIR + fuser,  TEMP_DIR + fuser);
        // remove the file of the user
        rm(DATA_DIR + "login/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
        rm(DATA_DIR + "user/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
#endif
}

// user born
void born_player(object me)
{
        mixed files;
        int i;
        string special;
        string msg;

        msg = HIG "�����������ļ����У�" NOR;

        // �鿴���е����⼼���ļ�
        files = get_dir("/kungfu/special/");
        me->delete("special_skill");

        if (sizeof(files))
        {
                // �������еļ����ļ�
                for (i = 0; i < sizeof(files); i++)
                        sscanf(files[i], "%s.c", files[i]);

                // ȥ��ת�����еļ���
                files -= ({ "bian", "dispel", "drift", "ghost",
                            "light", "lucky", "lun", "jin", "sheng",
                            "shuang", "yuan", });

                // ������ò < 20 ����פ��
                if (me->query("per") < 20)
                        files -= ({ "youth" });

                // ��õ�һ���
                special = files[random(sizeof(files))];
                me->set("special_skill/" + special, 1);
                msg += SPECIAL_D(special)->name();

                files -= ({ special });
                if (sizeof(files) && random(100) == 1)
                {
                        // ��õڶ����
                        special = files[random(sizeof(files))];
                        me->set("special_skill/" + special, 1);
                        msg += HIG "��" NOR + SPECIAL_D(special)->name();
                }
                msg += HIG "��\n" NOR;
                me->start_call_out((: call_other, __FILE__,
                                      "notice_player", me, msg :), 0);
        }
}

// user zhuan
void zhuan_player(object me)
{
        mixed files;
        string special;
        string msg;
        string *skills;
        mapping all_skills;
        int i;

        if (me->query("gender") == "����")
                me->set("gender", "����");

        me->set("score", 0);
        me->set("shen", 0);
        me->set("mud_age", 0);
        me->set("age", 5);
        me->set("birthday", time());
        me->delete("weiwang");
        me->delete("meili");
        me->delete("contribution");
        me->delete("balance");
        me->delete("total_hatred");

        me->set("combat_exp", 10000000);
        me->set("potential", 1000000);
        me->set("learned_points", 0);
        me->set("experience", 100000);
        me->set("learned_experience", 0);
        me->set("magic_points", 20000);
        me->set("level", 100);

        me->set("max_neili", 5000);
        me->set("max_qi", 2000);
        me->set("max_jing", 1000);
        me->set("max_jingli", 2000);
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("eff_qi"));
        me->set("eff_jing", me->query("max_jing"));
        me->set("jing", me->query("eff_jing"));
        me->set("eff_jingli", me->query("max_jingli"));

        me->delete("couple");                // ��ͥ��¼
        me->delete("sex");                   // ������¼
        me->delete("brothers");              // ����ֵ�
        me->delete("bunch");                 // ���ɼ�¼
        me->delete("league");                // ͬ�˼�¼
        me->delete("family");                // ���ɼ�¼
        me->delete("class");                 // �ƺż�¼
        me->delete("detach");                // ��ʦ��¼
        me->delete("betrayer");              // ��ʦ��¼
        me->delete("long");                  // ��������
        me->set("title", "��ͨ����");        // ���˳ƺ�
        me->set("character", "��ʿ��˫");    // ת���Ը�
        me->delete("combat");                // PK  ��¼
        me->delete("animaout");              // ԪӤ����
        me->delete("breakup");               // �ζ�����
        me->delete("can_learn");             // ���¼�¼
        me->delete("can_make");              // ��ҩ��¼
        me->delete("degree");                // �ٸ�ְλ
        me->delete("degree_jungong");        // ������¼
        me->delete("env");                   // �����趨
        me->delete("gift");                  // �Ե���¼
        me->delete("guo_shoucheng");         // �سǼ�¼
        me->delete("opinion");               // ���ۼ�¼
        me->delete("opinions");              // ��ʦ���
        me->delete("out_family");            // ��ʦ����
        me->delete("pawns");                 // �䵱��¼
        me->delete("quest_count");           // ��������
        me->delete("map");                   // ��ͼ��־
        me->delete("rumor");                 // �¼���¼
        me->delete("schedule");              // �ƻ���¼
        me->delete("see_feng");              // ��������
        me->delete("skybook");               // �����¼
        me->delete("sl");                    // �����书
        me->delete("sl_gifts");              // �����书
        me->delete("luohan_winner");
        me->delete("story");                 // �еĹ���
        me->delete("ultra_count");           // ��ʦ����
        me->delete("ultraquest");            // ��ʦ����
        me->delete("DiZangPass");            // ת������
        me->delete("HellZhenPass");          // ת������
        me->delete("SkyPass");               // ת������
        me->delete("over_quest");            // ת������

        all_skills = me->query_skills();
        skills = keys(all_skills);

        for (i = 0; i < sizeof(skills); i++)
                me->set_skill(skills[i], 400);

        me->set_skill("martial-cognize", 1000);
        me->set_skill("count", 1000);
        me->set_skill("mathematics", 1000);
        me->set_skill("literate", 1000);
        me->set("zhuanshi", 1);

        if (me->is_ghost()) me->reincarnate();
        me->reset_action();

        msg = HIG "���õ�ת�������У�" NOR;

        // �鿴���е����⼼���ļ�
        files = ({ "bian", "dispel", "drift", "ghost",
                   "jin", "sheng", "yuan",
                });

        // ��õ�һ���
        special = files[random(sizeof(files))];
        me->set("special_skill/" + special, 1);
        msg += SPECIAL_D(special)->name();

        message("channel:rumor", HIB "��ת��������" + me->query("name") +
                "���ת������--" + SPECIAL_D(special)->name() + HIB "��\n" NOR, users());

        files -= ({ special });

        special = files[random(sizeof(files))];
        me->set("special_skill/" + special, 1);
        msg += HIG "��" NOR + SPECIAL_D(special)->name();

        message("channel:rumor", HIB "��ת��������" + me->query("name") +
                "���ת������--" + SPECIAL_D(special)->name() + HIB "��\n" NOR, users());

        files -= ({ special });

        special = files[random(sizeof(files))];
        me->set("special_skill/" + special, 1);
        msg += HIG "��" NOR + SPECIAL_D(special)->name();

        message("channel:rumor", HIB "��ת��������" + me->query("name") +
                "���ת������--" + SPECIAL_D(special)->name() + HIB "��\n" NOR, users());

        files -= ({ special });

        if (sizeof(files) && random(21) == 1)
        {
                        // ��õ������
                special = files[random(sizeof(files))];
                me->set("special_skill/" + special, 1);
                msg += HIG "��" NOR + SPECIAL_D(special)->name();

                message("channel:rumor", HIB "��ת��������" + me->query("name") +
                        "���ת������--" + SPECIAL_D(special)->name() + HIB "��\n" NOR, users());
        }

        me->set("special_skill/clever", 1);
        me->set("special_skill/lucky", 1);
        me->set("special_skill/light", 1);
        me->set("special_skill/lun", 1);
        me->set("special_skill/shuang", 1);

        msg += HIG "��" NOR + HIM "�츳��ӱ" NOR + HIY "���Ǹ���" NOR + HIW "�޼��W�" NOR +
               HIG "��" NOR + HIR "�����ֻ�" NOR + HIG "��" NOR + HIY "��ʿ��˫" NOR;

        msg += HIG "��\n" NOR;

        message("channel:rumor", HIB "��ת��������" + me->query("name") +
                "���ת������--" + HIM "�츳��ӱ" NOR + HIB "��\n" NOR, users());

        message("channel:rumor", HIB "��ת��������" + me->query("name") +
                "���ת������--" + HIY "���Ǹ���" NOR + HIB "��\n" NOR, users());

        message("channel:rumor", HIB "��ת��������" + me->query("name") +
                "���ת������--" + HIW "�޼��W�" NOR + HIB "��\n" NOR, users());

        message("channel:rumor", HIB "��ת��������" + me->query("name") +
                "���ת������--" + HIR "�����ֻ�" NOR + HIB "��\n" NOR, users());

        message("channel:rumor", HIB "��ת��������" + me->query("name") +
                "���ת������--" + HIY "��ʿ��˫" NOR + HIB "��\n" NOR, users());

        message("channel:rumor", HIB "��ת����������ϲ" + me->query("name") +
                "�õ�����ħ������ӣ�Ԫ��ת��������\n" NOR, users());

        me->start_call_out((: call_other, __FILE__,
                           "notice_player", me, msg :), 0);
}

// notice user a piece of message, delay call by born user
void notice_player(object me, string msg)
{
        tell_object(me, msg);
}

// query title dbase
mixed query_title_base()
{
        if (! is_root(previous_object()))
                return 0;

        return title_base;
}

// set title dbase
mixed set_title_base(mixed ts)
{
        if (! is_root(previous_object()))
                return 0;

        title_base = ts;
}

// ���ĳ����ҵ� title
void remove_title(object ob)
{
        int i;

        if (! arrayp(title_base) || ! ob->query("granted_title"))
                return;

        ob->delete_temp("title");
        ob->delete("granted_title");

        for (i = 0; i < sizeof(title_base); i++)
        {
                // �������е� title
                if (title_base[i][1] == ob->query("id"))
                        // ȥ��title
                        title_base[i][1] = 0;
        }
        save();
        return;
}

// ����ĳ����ҵ� title
void set_title(object ob)
{
        string id;
        int i;

        if (! arrayp(title_base) || ! ob->query("granted_title"))
                return;

        id = ob->query("id");
        for (i = 0; i < sizeof(title_base); i++)
                if (title_base[i][1] == id)
                {
                        // ����title
                        ob->set_temp("title", title_base[i][0]);
                        return;
                }

        // ����û���û�з���ĳƺ�
        ob->delete("granted_title");
}

// Ѱ�һ����ĳһ�����
// �������������Ҫ������Щ�����ߵ���ң������ʹ�øú���
// �������ҵ��벢�ҽ����޸ģ���ע�⣺�޸�����Ժ�������
// ������ң�����ʹ�� global_destruct_player �������������
// ��û�е������������������ҵĶ�ʱ�����Զ�������ҡ�
object global_find_player(string user)
{
        object ob;
        object login_ob;

        ob = find_player(user);
        if (! ob)
        {
                login_ob = new(LOGIN_OB);
                login_ob->set("id", user);
                ob = LOGIN_D->make_body(login_ob);
                if (! ob)
                {
                        catch(destruct(login_ob));
                        return 0;
                }

                evaluate(bind((: seteuid(getuid()) :), ob));

                if (! ob->restore())
                {
                        catch(destruct(login_ob));
                        catch(destruct(ob));
                        return 0;
                }

                ob->set_temp("temp_loaded", 1);
                ob->start_call_out(bind((: call_other, __FILE__, "global_destruct_player", ob, 0 :), ob), 0);
                catch(destruct(login_ob));
        }

        return ob;
}

// ����һ���� UPDATE_D ��������
void global_destruct_player(object ob, int raw)
{
        if (objectp(ob) && ob->query_temp("temp_loaded"))
        {
                if (raw) ob->save();
                destruct(ob);
        }
}
