#include <ansi.h>
inherit ITEM;
int is_enchase_ob() { return 1; }
void create()
{
        set_name(MAG "稀世宝石" NOR, ({ "MAG jewel3","jewel3" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "一颗紫光闪闪的精美宝石，给人以不同寻常的感觉。\n" NOR);
                set("unit", "块");
                set("value", 120000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
                    
                set("enchase/type", "all");   // 可镶嵌的道具类型"all"或"sword"或"blade"或"cloth"等
                set("enchase/cur_firm", 90);  // 抗磨损度
                set("enchase/wspe_data",      // 兵器上附加属性汇总
                   ([
                        ////////////////////     兵防共有属性


                        "con" : 3,           // 增加身法

                        ////////////////////     兵器特有属性

                        "perferm_ap"    : 3,  // 绝招命中：+5%
                        "suck_eff_jing" : 10, // 伤敌精力上限
                        "suck_jingli"   : 10, // 吸取精力
                        "suck_neili"    : 10, // 吸取内力

                   ]));

                set("enchase/aspe_data",       // 防具上附加属性汇总
                   ([
                        ////////////////////     兵防共有属性

                        "con" : 3,           // 增加身法

                        ////////////////////     防具特有属性

                        "defense": 30,       // 防御等级：+30
                        "armor"  : 30,       // 防御能力：+30
                        "perform_dp"    : 3,  // 绝招防御：+3%
                        "reduce_damage" : 15, // 化解伤害：15%
                        "reduce_busy"   : 15, // 化解忙乱：15%

                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


