//Cracked by Kafei
//�һ������飬literate 100lv�������̱�����200lv�����Ǳ�learn���ܶࡣ
//������player��̡�(literate > 200 ���һ�����)
//maco 1999/5/9

#include <ansi.h>
inherit ITEM;
string* names = ({
        "�����ߡ�",
        "�����ǡ�",
        "��ʫ����",
        "�������㾭��",
});

string* longs = ({
        "����һ����صĹ��飬���ּ��࣬ȴ����ע�⡣\n",
        "����һ���ƾɵĹ��飬��Щ�ּ��Ѿ�ģ�����壬������⡣\n",
        "����һ�ᱡƤ���飬д����ӬͷС�֣����׿��������\n",
});
void create()
{
        set_name(names[random(sizeof(names))], ({"book","jing","book"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 4000);
                set("no_sell",1);
             set("long",longs[random(sizeof(longs))]);
        }
}
void init()
{
        add_action("do_qingjiao", "qingjiao");
}

int do_qingjiao(string arg)
{
        object me, ob;
        int jing_cost,grade;

        me = this_player();
        jing_cost = 150 / (int)me->query("int") + 1;
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
        if( me->is_fighting() )
                return notify_fail("�Ȱ��ⳡ�ܴ���ɡ�\n");
        if( !arg )
                return notify_fail("�������˭��\n");
        if(!objectp(ob = present(arg, environment(this_player()))))
                return notify_fail("����û������ˡ�\n");
        if (me == ob)
                return notify_fail("�Լ�����Լ���\n");
        if( !ob->is_character() || ob->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
        if( !living(ob) )
                return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");
        if ((int)me->query("potential",1) < 2)
                return notify_fail("���Ǳ�ܲ��㣬�޷�����κζ�����\n");

        if(me->query_skill("literate",1) < 100 )
                return notify_fail("ƾ�����ڵ�ѧʶ�����޷���⾭���ϵ�֪ʶ��\n");
        if(ob->query_skill("literate",1) < 200 )
                return notify_fail("��"+ ob->name() +"��ѧʶ����������ָ���㡣\n");
	if(me->query_skill("literate",1) > 300 )
                return notify_fail("���ѧʶ�Ѿ��൱�������Ȿ����������֮����\n");
        
        if (me->query("family/family_name")!="�һ���" || 
        ob->query("family/family_name")!="�һ���")
        {
        printf("����%s��̾����ϵ�����֮����Ȼ���Է��ƺ�����Ϊ����͡�\n", ob->name());
        }
        else if (me->query_skill("literate") >= ob->query_skill("literate"))
        {
        printf("%s��ѧ���Ѿ��޷���ָ����ʲ���ˡ�\n", ob->name());
        }

         else if((int)me->query("jing") > jing_cost )
        {
                printf("����%s��̾����ϵ�����֮��������˼�����к��塣\n", ob->name());
		if ((int)me->query_skill("literate",1) < 200) {
                me->add("potential", -2);
                me->improve_skill("literate", (random(10) + (int)me->query("int")*2/3));	}
                
                else {
                me->add("potential", -2);
                me->improve_skill("literate", (random(10) + (int)me->query("int")/3));
			}
                }
        
        else
        {
                jing_cost = me->query("jing");
                write("������̫���ˣ�û�а취ר���ж����顣\n");
        }
        me->receive_damage("jing", jing_cost );
        return 1;
}
