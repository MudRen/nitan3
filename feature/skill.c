// skill.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>
#include <dbase.h>

mapping skills;
mapping learned;
mapping skill_map;
mapping skill_prepare;
mapping wprepare;

mapping query_SKILL()
{
	mapping m = ([]);
	m["skills"] = skills;
	m["learned"] = learned;
	m["skill_map"] = skill_map;
	m["skill_prepare"] = skill_prepare;
	m["wprepare"] = wprepare;
	return m;
}

int set_SKILL(mapping m)
{
        if (! mapp(m)) return 0;
	skills = m["skills"];
	learned = m["learned"];
	skill_map = m["skill_map"];
	skill_prepare = m["skill_prepare"];
	wprepare = m["wprepare"];
	return 1;
}

mapping query_skillc() { return skills; }
mapping query_skills() 
{ 
        int i, a, s;
        mapping askills;
        string *sk;
        
        a = query_temp("apply/add_skilllevel");
        if (! a) return skills; 
                
        askills = ([]);
        if (mapp(skills))
                sk = keys(skills);
        if (arrayp(sk) && sizeof(sk))
        for (i = 0; i<sizeof(sk); i++)
        {
                s = skills[sk[i]] + a;
                askills += ([ sk[i] : s ]);
        }

        return askills;
}

mapping query_learned() { return learned; }
varargs void map_skill(string skill, string mapped_to);

string *query_skills_name()
{
        if (mapp(skills))
	        return keys(skills);
        else
	        return 0;
}

void set_skill(string skill, int val)
{
        if (! find_object(SKILL_D(skill)) &&
            ! load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if (! mapp(skills)) skills = ([ skill: val ]);
        else skills[skill] = val;
}

void add_skill(string skill, int val)
{
        if (! find_object(SKILL_D(skill)) &&
            ! load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if (! mapp(skills)) skills = ([ skill: val ]);
        else
        {
                if (undefinedp(skills[skill]))
                        skills[skill] = val;
                else
                        skills[skill] += val;
        }
}

int delete_skill(string skill)
{
        int i;
        string *sk;

        if (mapp(skill_map))
        {
                map_delete(skill_map, skill);
                sk = keys(skill_map);
                for (i = 0; i < sizeof(sk); i++)
                {
                        if (skill_map[sk[i]] == skill)
                                map_skill(sk[i], 0);
                }
        }

        if (mapp(skills))
        {
                map_delete(skills, skill);
                if (mapp(learned))
                {
                        map_delete(learned, skill);
                        return undefinedp(learned[skill]);
                }
                return undefinedp(skills[skill]);
        }
        return 0;
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
        if (! mapped_to && mapp(skill_map))
        {
                if ( skill_prepare ) map_delete(skill_prepare, skill);
                map_delete(skill_map, skill);
                return;
        }

        if (! find_object(SKILL_D(skill)) &&
            ! load_object(SKILL_D(skill)) )
            error("F_SKILL: No such skill (" + skill + ")\n");

        if (! mapp(skills) || undefinedp(skills[mapped_to]))
                return;
                
        if (skill_prepare) map_delete(skill_prepare, skill);
        if (! mapp(skill_map)) skill_map = ([ skill: mapped_to ]);
        else skill_map[skill] = mapped_to;
}

// This function 'prepare' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the prepared skill <skill>.
varargs void prepare_skill(string skill, string mapped_to)
{
        if (! mapped_to && mapp(skill_prepare))
        {
                map_delete(skill_prepare, skill);
                return;
        }

        if (! find_object(SKILL_D(skill)) &&
            ! load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if (! mapp(skills) || undefinedp(skills[mapped_to]))
                return;
                
        if (! mapp(skill_prepare)) skill_prepare = ([ skill: mapped_to ]);
        else skill_prepare[skill] = mapped_to;
}

varargs void prepare_wskill(string skill, string mapped_to)
{
        if (! mapped_to && mapp(wprepare))
        {
                map_delete(wprepare, skill);
                return;
        }

        if (! find_object(SKILL_D(skill)) &&
            ! load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if (! mapp(skills) || undefinedp(skills[mapped_to]))
                return;
                
        if (! mapp(wprepare)) wprepare = ([ skill: mapped_to ]);
        else wprepare[skill] = mapped_to;
}


string query_skill_mapped(string skill)
{
        if (mapp(skill_map) && ! undefinedp(skill_map[skill]))
                return skill_map[skill];
        return 0;
}

string query_skill_prepared(string skill)
{
        if (mapp(skill_prepare) && !undefinedp(skill_prepare[skill]))
                return skill_prepare[skill];
        return 0;
}

string query_wprepared(string skill)
{
        if (mapp(wprepare) && !undefinedp(wprepare[skill]))
                return wprepare[skill];
        return 0;
}

varargs int query_skillo(string skill, int raw)
{
        if (! raw)
        {
                int s;
                
                s = query_temp("apply/" + skill);
                if (mapp(skills))
                {
                        s += skills[skill] / 2;
                        if (mapp(skill_map))
                                s += skills[skill_map[skill]];
                }
                return s;
        }
        if (mapp(skills) && ! undefinedp(skills[skill]))
        {
                int a;

                a = skills[skill];
                return a;
        }
        return 0;
}

varargs int query_skill(string skill, int raw)
{
        if (! raw)
        {
                int s;
                
                s = query_temp("apply/" + skill);
                s += query_temp("apply/add_skilllevel"); 
                if (mapp(skills))
                {
                        s += skills[skill] / 2;
                        if (mapp(skill_map))
                                s += skills[skill_map[skill]];
                }
                return s;
        }
        if (mapp(skills) && ! undefinedp(skills[skill]))
        {
                int a;

                a = skills[skill];
                a += query_temp("apply/add_skilllevel");
                return a;
        }
        return 0;
}

mapping query_skill_map()
{
        return skill_map;
}

mapping query_skill_prepare()
{
        return skill_prepare;
}

mapping query_wprepare()
{
       return wprepare;  
}

int skill_death_penalty()
{
        string *sk;
        int i;

        if (wizardp(this_object()) || ! mapp(skills)) return 0;

        sk = keys(skills);
        if (! mapp(learned))
                for(i = 0; i<sizeof(sk); i++)
                {
                        skills[sk[i]]--;
                        if (skills[sk[i]] < 1) map_delete(skills, sk[i]);
                }
        else
                for(i = 0; i<sizeof(sk); i++)
                {
                        if ((int)learned[sk[i]] > (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2)
                                map_delete(learned, sk[i]);
                        else
                        {
                                skills[sk[i]]--;
                                if (skills[sk[i]] < 0) map_delete(skills, sk[i]);
                        }
                }

        skill_map = 0;
        skill_prepare = 0;

        return 1;
}

int skill_expell_penalty()
{
        int i;
        string *skname;

        if (! mapp(skills)) 
        return 1;

        skname = keys(skills);
        for (i = 0; i < sizeof(skname); i++)
        {
                if (file_size(SKILL_D(skname[i]) + ".c") < 0)
                {
                        delete_skill(skname[i]);
                        continue;
                }

                // �Դ����书������
                if (SKILL_D(skname[i])->is_invent_skill()) 
                        continue;

                if (SKILL_D(skname[i])->type() != "martial" ||
                    skname[i] == "martial-cognize")
                        continue;

                if (SKILL_D(skname[i])->valid_enable("parry") ||
                    SKILL_D(skname[i])->valid_enable("dodge") ||
                    SKILL_D(skname[i])->valid_enable("throwing") ||
                    SKILL_D(skname[i])->valid_enable("force"))
                {
                        delete_skill(skname[i]);
                        continue;
                }

                if (query_skillo(skname[i], 1) >= 100)
                        set_skill(skname[i], 100);
        }

        skill_map = 0;
        skill_prepare = 0;
}

int can_improve_skill(string skill)
{
        int lvl;
        mixed exp;

        if (! find_object(SKILL_D(skill)) &&
            ! load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");

        switch (SKILL_D(skill)->type())
        {
        case "knowledge":
                // ֪ʶ�༼��
                return 1;

        case "technic":
                // �����༼��
                return 1;

        case "martial":
        case "poison":
                lvl = query_skill(skill, 1);
                exp = this_object()->query("combat_exp");
                if (count_gt(count_div(count_mul(count_mul(lvl, lvl), lvl), 10), exp))
                        return 0;
                return 1;

        default:
                return 1;
        }
}

varargs void improve_skill(string skill, int amount, int weak_mode)
{
        //int spi;
        int lvl;
        int mlvl;
        string type;

        if (! find_object(SKILL_D(skill)) &&
            ! load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if (! mapp(skills)) skills = ([]);
        if (undefinedp(skills[skill])) skills[skill] = 0;

        type = SKILL_D(skill)->type();

        switch (type)
        {
        case "martial":
                if (intp(mlvl = skills["martial-cognize"]) &&
                    skill != "martial-cognize")
                        // martial-cognize does extra bonus for martial skills
                        amount += amount * (mlvl/5) / 100;
                break;

        case "knowledge":
                if (intp(mlvl = skills["culture-cognize"]) &&
                    skill != "culture-cognize")
                        // culture-cognize does extra bonus for culture skills
                        amount += amount * (mlvl/5) / 100;
                break;

        case "technic":
                if (intp(mlvl = skills["technic-cognize"]) &&
                    skill != "technic-cognize")
                        // culture-cognize does extra bonus for culture skills
                        amount += amount * (mlvl/5) / 100;
                break;
        }

        // adjust the point improved
        lvl = skills[skill];
        amount = 1 + amount * 100 / (lvl + 100);

        if (! mapp(learned)) learned = ([ skill : amount ]);
        else (int)learned[skill] += amount;

        if ((! weak_mode || !userp(this_object())) &&
            learned[skill] > (skills[skill] + 1) * (skills[skill] + 1))
        {
                skills[skill]++;
                learned[skill] = 0;
                tell_object(this_object(), HIC "��ġ�" + to_chinese(skill) +
                            "�������ˣ�\n" NOR);
                SKILL_D(skill)->skill_improved(this_object());
        }
}

