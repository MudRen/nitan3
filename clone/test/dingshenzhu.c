inherit ITEM;
#include <ansi.h>
int do_apply(string);
void setup() {}
void create()
{
	set_name(GRN "������" NOR, ({"dingshen zhu", "zhu"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ϡ���鱦����������\n");
		//set("no_drop","������������ף��������ӣ� \n");
		set("value", 0);
               // set("no_sell", 1);
		
	}

	setup();
}
void init()
{
   add_action("do_apply", "apply");
   }
int do_apply(string arg)
{
   object me=this_player(); 
   if (!id(arg))
		return notify_fail("����ʹ��ʲô��\n");
		me->set("jing",(int)me->query("max_jing")*3);
		me->set("qi",(int)me->query("max_qi")*3);
		me->set("neili",(int)me->query("max_neili")*3);
		me->set("eff_qi", (int)me->query("max_qi"));
		me->set("eff_jing", (int)me->query("max_jing"));
		message_vision(HIG"$N������һ��"+query("name")+HIG"��һ������֮��ֱ͸���ֻ���þ���������Ѫ��ӯ����������ԴԴ��������ƣ��һɨ����! \n" NOR, me);
		return 1;
		}
int query_autoload()
{
        return 1;
}