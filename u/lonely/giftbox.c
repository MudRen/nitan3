// giftbox.c ��Ʒ��

inherit ITEM;
#include <ansi.h>;

// int is_container() { return 1; }
int query_autoload() { return 1; }   

void create()
{
        set_name(HIR"��Ʒ��"NOR, ({ "giftbox", "box" }));
        set_weight(500);
        set_max_encumbrance(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����Ʒ�С�����װ����ʦ���������\n\n    "HIR"������֣���\n\n"NOR);
                set("value", 0);
        }
}

void init()
{
        add_action("do_dakai", "dakai");
        add_action("do_dakai", "chaikai");
}

int do_dakai(string arg)
{
        mapping all_skills;   
        string  *skills;
        int     i;             
        object  me = this_player();

        if (! arg || arg == "")
                return notify_fail("��Ҫ��ʲô�أ�\n");
                
        if (arg == "box" || arg == "giftbox")
        {         
                tell_object(me,
HIW"\n"+
"     ������������������ "HIR"���ڿ���"HIW" ������������������\n"+
"     ��  ���������� Happy  New  Year ����������  ��\n"+
"     ��  ��                                  ��  ��\n"+
"     ��  ��                                  ��  ��\n");
                if(strlen(me->query("name")) == 2) tell_object(me,
HIW"     ��  ��  �װ���"+me->query("name")+"��                      ��  ��\n");
                if(strlen(me->query("name")) == 4) tell_object(me,
HIW"     ��  ��  �װ���"+me->query("name")+"��                    ��  ��\n");
                if(strlen(me->query("name")) == 6) tell_object(me,
HIW"     ��  ��  �װ���"+me->query("name")+"��                  ��  ��\n");
                if(strlen(me->query("name")) == 8) tell_object(me,
HIW"     ��  ��  �װ���"+me->query("name")+"��                ��  ��\n");
                if(strlen(me->query("name")) == 10) tell_object(me,
HIW"     ��  ��  �װ���"+me->query("name")+"��              ��  ��\n");
        tell_object(me,
HIW"     ��  ��      Ը�������ļ������µ�һ��    ��  ��\n"+
"     ��  ��  ����������֡�ƽ����          ��  ��\n"+
"     ��  ��                                  ��  ��\n"+
"     ��  ��             *  *"HIR"r"HIW"*  *            ��  ��\n"+
"     ��  ��          * *"HIR"a"HIW"* "HIG"^"HIY"Y"HIG"^"HIW" *"HIR"i"HIW"* *         ��  ��\n"+
"     ��  ��         *"HIM"m"HIW"*"HIG"^"HIY"Y"HIG"^"HIW"*"HIG"^\\^"HIW"*"HIG"^"HIY"Y"HIG"^"HIW"*"RED"s"HIW"*        ��  ��\n"+
"     ��  ��         "HIG"^"HIY"Y"HIG"^"HIW"*"HIG"\\"HIW"*"RED"e"HIW"*"HIG"/"HIW"*"HIG"l"HIW"*"HIG"/"HIW"*"HIG"^"HIY"Y"HIG"^"HIW"        ��  ��\n"+
"     ��  ��         *"HIG"\\"HIW"*"CYN"t"HIW"*"HIG"|"HIY"Y"HIG"^\\^"HIY"Y"HIG"|"HIW"*"HIG"l"HIW"*"HIG"/"HIW"*        ��  ��\n"+
"     ��  ��        *"MAG"s"HIW"*"HIG"|"HIY"Y"HIG"^\\\\^/^//^"HIY"Y"HIG"|"HIW"*"HIR"a"HIW"*       ��  ��\n"+
"     ��  ��        "GRN"^"YEL"Y"GRN"^\\\\_^\\\\\\//^_//^"YEL"Y"GRN"^"HIW"       ��  ��\n"+
"     ��  ��        "GRN"^\\_^\\_\\_\\//_/_/^_/^"HIW"       ��  ��\n"+
"     ��  ��         "GRN"^^\\_^\\_\\\\/_/^_/^^"HIW"        ��  ��\n"+
"     ��  ��           "GRN"^^\\_ \\// _/^^"HIW"          ��  ��\n"+
"     ��  ��               "GRN"\\_\\_/"HIW"              ��  ��\n"+
"     ��  ��                "GRN"/|\\"HIW"               ��  ��\n"+
"     ��  ��               "GRN"/\\\\/\\"HIW"              ��  ��\n"+
"     ��  ��                                  ��  ��\n"+
"     ��  ��                  "RED"��̶��ʦ�鹧��"HIW"  ��  ��\n"+
HIW"     ��  ��������������������������������������  ��\n"+
"     ����������������������������������������������\n"+
"\n" NOR);
                if (me->query("gifter/200804"))
                {
                        destruct(this_object());
                        return 1;
                }

/*
                all_skills = me->query_skills();
                if (sizeof(all_skills) > 0)
                {
                        skills = keys(all_skills);
                        for (i = 0; i < sizeof(skills); i++)
                                me->add_skill(skills[i], 21);
                }
                me->add("kar", 1);              
                me->add_skill("martial-cognize", 50);
                me->add_skill("literate", 100);
*/
                me->set("gifter/200804", 1);
                me->add("potential", 10000000);
                tell_object(me, HIM "������̶��ʦ���ף���£������Լ�������������������������\n" NOR);
                destruct(this_object());
        }      
        return 1;
}

