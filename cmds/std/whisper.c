// whisper.c

#include <ansi.h>

inherit F_CLEAN_UP;

int reply_whisper(object me, object who, string msg);
int ultra_whisper(object me, object who, string msg);
protected void special_bonus(object me, mixed arg);
protected void money_bonus(object me, mixed arg);

int main(object me, string arg)
{
       int r;
	string dest, msg;
	object ob;

	if (! arg)
		return notify_fail("��Ҫ��˭����Щʲô��\n");

	if (sscanf(arg, "%s about %s", dest, msg) != 2)
		if (sscanf(arg, "%s %s", dest, msg) != 2)
			return notify_fail("��Ҫ��˭����Щʲô��\n");

	ob = present(dest, environment(me));
	if (! ob || ! ob->is_character())
		return notify_fail("��Ҫ��˭���\n");

        if (me->ban_say(1))
                return 0;

        if (me->query("doing") == "scheme")
        {
                if (me->query("jing") < 100)
                        return notify_fail("�����ڵľ��񲻼ã���һ����ɡ�\n");
                me->add("jing", -50);
        }

	write(WHT "����" + ob->name() + WHT "�Ķ�������˵����" +
	      msg + "\n" NOR);
	tell_room(environment(me), me->name() + "��" + ob->name()
		+ "����С����˵��Щ����\n", ({ me, ob }));
	if (! userp(ob)) 
        {
              r = 0;
              if (me->query("bunch_quest") && me->query("bunch_quest/type") == "������")
                      r = reply_whisper(me, ob, msg);
              if (! r)
                      if ((me->query("quest_dg") && me->query("quest_dg")["type"] == "��") ||
                          (me->query("quest_kh") && me->query("quest_kh")["type"] == "��") ||
                          (me->query("quest_hs") && me->query("quest_hs")["type"] == "��") ||
                          (me->query("quest_sn") && me->query("quest_sn")["type"] == "��"))
                              r = ultra_whisper(me, ob, msg);

              if (! r)
                      ob->relay_whisper(me, msg);
       }
	else
		tell_object(ob, WHT + me->name() +
				WHT "����Ķ�������˵����" + msg + "\n" NOR);
	return 1;
}

int reply_whisper(object me, object who, string msg)
{
        mapping bunch_quest,b;

        int exp;
        int pot;
        int score;
        int weiwang;

        bunch_quest = me->query("bunch_quest");

        //��������
        if (bunch_quest["target"] != base_name(who))
                return 0;

        //������
        if (msg != bunch_quest["send_msg"])
                return 0;

        message_sort("$N��ɫ���أ�һ������һ�߶�$nʹ���ĵ�ͷ������λ" +
                     RANK_D->query_respect(me) +
                     "����л��ѻ���������\n", who, me);

        // ����
        me->add("total_hatred",-2);
        if (me->query("total_hatred") < 0) me->set("total_hatred",0);

        exp = bunch_quest["bonus"];
        exp += random(exp/2);
        exp += atoi(count_div(me->query("combat_exp"), 5000));
        pot = exp/(2 + random(2));
        score = 5 + random(10);
        weiwang = 5 + random(10);

        b = ([ "exp" : exp,
               "pot" : pot,
               "score" : score,
               "weiwang" : weiwang,
               "prompt": "�ڰѿ��Ŵ���" + who->name() +
                         HIG "�Ĺ����У���������" ]);

        QUEST_D->delay_bonus(me, b);

        me->delete("bunch_quest");
        me->add_temp("finish_bunch_times",1);

        return 1;
}

int ultra_whisper(object me, object who, string msg)
{
        mapping quest;
        int level;
        int i;
        int exp;
        int pot;
        int score;
        int weiwang;
        int mar;
	int quest_count;
        string the_quest;
	mixed special = 0;
        mixed money = 0;

        quest = me->query("quest_dg");
        the_quest = "�������";
        if (!quest || quest["type"] != "��")
        {
                quest = me->query("quest_kh");
                the_quest = "����̫��";
        }
        if (!quest || quest["type"] != "��")
        {
                quest = me->query("quest_hs");
                the_quest = "����";
        }
        if (!quest || quest["type"] != "��")
        {
                quest = me->query("quest_sn");
                the_quest = "�Ϻ�����";
        }

        if (!quest) return 0;

        if (userp(who)) return 0;

        //��������
        if (quest["name"] != who->name(1))
                return 0;

        //������
        if (msg != quest["answer"])
                return 0;

        message_sort("$N��ɫ���أ�һ������һ�߶�$nʹ���ĵ�ͷ������λ" +
                     RANK_D->query_respect(me) +
                     "����л��ѿ����������\n", who, me);

        // ����
        level = quest["level"]+1;
        if (the_quest == "�������")
        {
                if((i=me->query("questdg_times")) < 8)   i = 15-i;
                else i = 1;
        }
        if (the_quest == "����̫��")
        {
                if((i=me->query("questkh_times")) < 15)   i = 15-i;
                else i = 1;
        }
        if (the_quest == "�Ϻ�����")
        {
                if((i=me->query("questsn_times")) < 15)   i = 15-i;
                else i = 1;
        }
        if (the_quest == "����")
        {
                if((i=me->query("quesths_times")) < 15)   i = 15-i;
                else i = 1;
        }

        exp = level*100 + quest["bonus"]*5;
        exp += random(exp/2);
        exp /= i;
        pot = exp/(2+random(2));
        score = random(exp/20);
        weiwang = random(exp/15);
        mar = 10 + random(40);

        QUEST_D->bonus(me, ([ "exp" : exp, "pot" : pot, "mar" : mar,
                              "weiwang" : weiwang, "score" : score ]), 1);

        if (the_quest == "�������")
        {
                me->add("questdg_times",1);
                quest_count = me->query("questdg_times")%500;
                me->delete("quest_dg");
        }
        if (the_quest == "����̫��")
        {
                me->add("questkh_times",1);
                quest_count = me->query("questkh_times")%500;
                me->delete("quest_kh");
        }
        if (the_quest == "����")
        {
                me->add("quesths_times",1);
                quest_count = me->query("quesths_times")%500;
                me->delete("quest_hs");
        }
        if (the_quest == "�Ϻ�����")
        {
                me->add("questsn_times",1);
                quest_count = me->query("questsn_times")%500;
                me->delete("quest_sn");
        }

        if (quest_count == 50)
		special = 1;
	else if (quest_count == 100)
		special = "/clone/gift/puti-zi";
        else if (quest_count == 150)
                money = 1;
        else if (quest_count == 200)
                money = 1;
        else if (quest_count == 250)
                money = 1;
   	else if (quest_count == 300)
		special = "/clone/misc/tianxiang";
   	else if (quest_count == 350)
		special = "/clone/misc/tianxiang";
   	else if (quest_count == 400)
                special = "/clone/misc/jiuzhuan";
	else if (quest_count == 450)
		special = "/clone/gift/jiuzhuan";
   	else if (quest_count == 0)
                special = "/clone/gift/xuanhuang";

	if (special) special_bonus(me, special);
        if (money) money_bonus(me,money);
            		
        me->add("total_hatred",-5);
        if (me->query("total_hatred") < 0) me->set("total_hatred",0);
        return 1;
}

protected void special_bonus(object me, mixed arg)
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
        });
        object ob;

        if (stringp(arg))
                ob = new(arg);
        else
                ob = new(ob_list[random(sizeof(ob_list))]);
        ob->move(me, 1);
        tell_object(me, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

void money_bonus(object me, mixed arg)
{
        string *ob_list = ({
                "/clone/gift/jinkuai",
                "/clone/gift/jintiao",
                "/clone/gift/xiaoyuanbao",
                "/clone/gift/dayuanbao",
                "/clone/gift/jinding",
        });
        object ob;

        if (stringp(arg))
                ob = new(arg);
        else
                ob = new(ob_list[random(sizeof(ob_list))]);

        ob->move(me,1);

        tell_object(me, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

int help(object me)
{
	write( @TEXT
ָ���ʽ��whisper <ĳ��> about <ѶϢ>

���ָ�����������ͬһ�����е��˶������ NPC ���ڡ�
���е�about����ʡ�ԡ�
TEXT );
	return 1;
}

