inherit ITEM;
#include <ansi.h>
int do_apply(string);
void setup() {}
void create()
{
	set_name(GRN "定神珠" NOR, ({"dingshen zhu", "zhu"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗稀世珠宝，能宁神静气\n");
		//set("no_drop","定神珠得来不易，哪能乱扔！ \n");
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
		return notify_fail("你想使用什么？\n");
		me->set("jing",(int)me->query("max_jing")*3);
		me->set("qi",(int)me->query("max_qi")*3);
		me->set("neili",(int)me->query("max_neili")*3);
		me->set("eff_qi", (int)me->query("max_qi"));
		me->set("eff_jing", (int)me->query("max_jing"));
		message_vision(HIG"$N抚摸了一下"+query("name")+HIG"，一股清香之气直透丹田，只觉得精神健旺，气血充盈，体内真力源源滋生，将疲乏一扫而空! \n" NOR, me);
		return 1;
		}
int query_autoload()
{
        return 1;
}