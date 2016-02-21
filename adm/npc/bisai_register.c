#include <ansi.h>
inherit NPC;

void zhuce_yhh(string yhh, object me);
void confirm_reg_code(string reg_code,string yhh,object me);
void csh_yh(object me);

string query_save_file()
{
        string id;

        id = query("id");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "/npc/%s", id);
}

int save()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file + __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

int restore()
{
        string file;
        if( stringp(file = this_object()->query_save_file()) && file_size(file + __SAVE_EXTENSION__) > 0 )
                return restore_object(file);
        return 0;
}

void create()
{
        set_name("������", ({ "zhuchi ren","ren" }));
        set("gender", "����");
        set("age", random(20) + 20);
	set("title", HIC "�����н�����" NOR);
	set("nickname", HIY "��ƽ ���� ����" NOR);
        set("str", 25);
	 set("con", 25);
	 set("spi", 25);
	 set("dex", 25);
	 set("int", 25);
	set("per",25);
        set("long", "����һ���ܾ����ܸɵ��ˡ�\n");
        set("combat_exp", 1000000);
	set("class", "fighter");
        set("attitude", "herosim");
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
	 set("max_qi", 1200);
	 set("max_jing", 1200);
        set("max_neili", 2000);
        set("neili",2000);
        set("jiali", 150);
	set("max_jingli", 2000);
	set("jingli", 2000);
        set("shop_id","beijing");

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        restore();
}


void init()
{
	object ob = this_player();
	if(query("start_baoming"))
	{
		add_action("do_zhuce","zhuce");
	}
	if (ob && wiz_level(ob) > 4)
	{
		add_action("do_start","start");
		add_action("do_end","end");
		add_action("do_finish","finish");
	}
}

void die()
{	
        return;
}

void unconcious()
{
        die();
}

int do_start()
{
        int i,times;
        string *str,*line;
        mapping per_baoming,all_baoming;

	if (query("start_baoming"))
		return notify_fail("���������Ѿ������ˡ�\n");

        if (file_size("/data/npc/" + "baoming_list")<0)
                return notify_fail("�����������ļ������ڣ�\n");

        str = explode(read_file("/data/npc/" + "baoming_list"),"\n");
        all_baoming = ([]);
        for (i = 0;i < sizeof(str);i ++)
        {
                per_baoming = ([]);
                line = explode(str[i],"|");
                if (sizeof(line) != 2) 
			return notify_fail("�����������ļ�����\n");
                per_baoming["yhh"] = line[0];
                per_baoming["reg_code"] = line[1];
                all_baoming += ([ line[0] : per_baoming ]);
        }
	
	delete("init_baoming");
	delete("finish_baoming");
	set("init_baoming",all_baoming);
	set("start_baoming",1);
	set("on_bisai",1);
	times = (int)query("bisai_times") + 1; 
	set("bisai_times",times);

	save();
	tell_object(this_player(),"������ʼ���ɹ������ڿ��ű�����\n");
	message("bisai",HIR "���������顿" NOR+WHT "�μӵ�" + chinese_number(times) + "���н�������������ڿ�ʼע��(zhuce)����ID���ص㣺������ʦ����ҡ�\n" NOR,users() ); 
        return 1;
		
}

int do_end()
{
        int i;
        string str;
	mapping finish_baoming;
	string *baoming_yh;

	if (!query("start_baoming"))
		return notify_fail("�������̲�δ���š�\n");

        str = "";
	finish_baoming = query("finish_baoming");
	if (!mapp(finish_baoming)) finish_baoming = ([]);
	baoming_yh = keys(finish_baoming);

        for (i = 0;i < sizeof(baoming_yh);i ++)
        {
                str += finish_baoming[baoming_yh[i]]["yhh"] + "|";
		str += finish_baoming[baoming_yh[i]]["id"] + "|";
		str += finish_baoming[baoming_yh[i]]["name"];
                if (i + 1 != sizeof(baoming_yh))
                        str += "\n";
        }
        write_file("/data/npc/" + "list",str,1);
	
	set("start_baoming",0);
	save();
	tell_object(this_player(),"�ɹ��رձ�����\n");
        return 1;	
}

int do_finish()
{
	int times;
	set("on_bisai",0);
	save();
	tell_object(this_player(),"�����������������\n");
	return 1;
}

int do_zhuce()
{
	int times;
	object ob = this_object();
	object me = this_player();

	if (!ob->query("start_baoming"))
		return notify_fail("�Բ������ڲ���ע�����IDʱ�䡣\n");

	times = ob->query("bisai_times");
	if (me->query("on_bisai") == times)
		return notify_fail("���Ѿ��Ǳ����н������Ĳ������ˡ�\n");

	tell_object(me,"����������н��������ֲ��û��ţ�");
	input_to("zhuce_yhh", me);
	return 1;
}

void zhuce_yhh(string yhh, object me)
{
	mapping baoming_list;
	string *baoming_yh;

	baoming_list = query("init_baoming");
	baoming_yh = keys(baoming_list);

	if (member_array(yhh,baoming_yh) == -1)
	{
		tell_object(me,"�û��Ŵ���\n");
		return;
	}

	baoming_list = query("finish_baoming");
	if (!mapp(baoming_list)) baoming_list = ([]);
	baoming_yh = keys(baoming_list);

	if (member_array(yhh,baoming_yh) != -1)
	{
		tell_object(me,"���û����Ѿ�ע���˲���ID��\n");
		return;
	}

	tell_object(me,"��������Ĳ������룺");
	input_to("confirm_reg_code", yhh, me);
}

void confirm_reg_code(string reg_code,string yhh,object me)
{
	mapping baoming_list,the_baoming;
	string the_reg_code;

	if (strlen(reg_code) != 8)
	{
		tell_object(me,"��Ĳ��������������\n");
		return;
	}

	baoming_list = query("init_baoming");
	the_reg_code = baoming_list[yhh]["reg_code"];
me->set("test",the_reg_code);
	if (reg_code != the_reg_code)
	{
		tell_object(me,"���������������\n");
		return;
	}

	the_baoming = ([]);
	the_baoming["yhh"] = yhh;
	the_baoming["id"] = me->query("id");
	the_baoming["name"] = me->query("name");
	
	baoming_list = query("finish_baoming");
	if (!mapp(baoming_list)) baoming_list = ([]);
	baoming_list += ([ yhh : the_baoming ]);
	set("finish_baoming",baoming_list);
	save();

	csh_yh(me);
	return;
}

void csh_yh(object me)
{
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname;
        int i, temp, times;
	mapping my = me->query_entire_dbase();

	my["str"] = 20;
	my["int"] = 20;
	my["con"] = 20;
	my["dex"] = 20;
	my["per"] = 20;
	my["kar"] = 20;
	me->delete("character");
	me->delete("can_not_change");
	me->delete("family");
	me->delete("betrayer");
	me->delete("balance");
	me->delete("combat");
	me->delete("can_perform");
	me->delete("opinion");
	me->delete("jieti");
	me->delete("detach");
	me->delete("tianmo_jieti");
	me->delete("breakup");
	me->delete("animaout");
	me->delete("no_newbie");
	me->delete("can_learn");
	me->delete("canewhua");
	me->set("newbie",1);
	my["pk_score"] = 0;
	my["magic_points"] = 0;
	my["experience"] = 0;
	my["combat_exp"] = 0;
	my["learned_points"] = 0;
	my["potential"] = 99;
	my["born_family"] = "û��";
	my["title"] = "��ͨ����";
	my["mud_age"] = 0;
	my["jing"] = my["eff_jing"] = my["max_jing"] = 100;
	my["qi"] = my["eff_qi"] = my["max_qi"] = 100;
	my["jingli"] = my["max_jingli"] = 0;
	my["neili"] = my["max_neili"] = 0;
	my["shen"] = 0;
	my["score"] = 0;
	my["weiwang"] = 0;
	my["jiali"] = 0;

        if (mapp(skill_status = me->query_skills()))
        {
                skill_status = me->query_skills();
                sname = keys(skill_status);
                temp = sizeof(skill_status);
                for (i = 0; i < temp; i++)
			me->delete_skill(sname[i]);
        }

        if (mapp(map_status = me->query_skill_map()))
        {
                mname = keys(map_status);
                temp = sizeof(map_status);
                for (i = 0; i < temp; i++)
                        me->map_skill(mname[i]);
        }
	
        if (mapp(prepare_status = me->query_skill_prepare()))
        {
                pname = keys(prepare_status);
                temp = sizeof(prepare_status);
                for(i = 0; i < temp; i++)
                        me->prepare_skill(pname[i]);
        }

	me->set("nickname",HIC"����ѡ��"NOR);
	times = this_object()->query("bisai_times");
	me->set("on_bisai",times);
	me->reset_action();
	tell_object(me,"��������Ѿ����³�ʼ��������㷢���д���ĵط���������������ʦ��\n");
	return;
}
