#include <ansi.h>
inherit ROOM;

string look_notice();
void create()
{
        set("short", "元老组");
        set("long", @LONG
你眼前是一片绿色的大草坪,草坪的中央是一块大石台。石台的旁边放置着
一块石碑(notice)和一块小木牌(paizi)，石碑的后面一面大旗(flag)迎风招展!!!!!!!
LONG
    );
        set("item_desc", ([ /* sizeof() == 1 */
                "大鼓" : "这是一只牛皮制成的巨鼓，武林人士在华山论剑时敲响(knock)它开始比武。",
                "flag" : " 自 古 英 雄 出 少 年 \n",
                "notice" : (: look_notice :),
        ]));
        
        set("exits", ([ /* sizeof() == 2 */
                "out" : "/d/huashan/houzhiwangyu",
        ]));
        
        set("no_fight", 1);
        set("objects",([
                "/clone/misc/drum4" : 1,
        ]));
        setup();
}

void init()
{
        //object me = this_player();
       // int age = (int)me->query("age");

/*
        if (! wizardp(me) && age < 40)
        {
                tell_object(me,"大会主持告诉你：你不可以在这个场地比武！请选择你年龄相应的场地！！\n");
                me->move("/d/huashan/houzhiwangyu");
                return;
        }
*/
        add_action("get_weapon", ({ "na", "qu", })); 
        add_action("discmds", ({
                "respitate", "exert", "array", "ansuan", "touxi", "persuade", 
                "teach", "exert", "exercise", "study", "learn", "sleep", "kill",
                "steal", "cast", "conjure", "expell", "fight", "hit", "perform", 
                "prcatice", "scribe", "surrender", "sha", "recall", "quit", "exit"}));
        // call_out("do_recover", 1, me);
}
void do_recover(object me)
{
        if (! me || environment(me) != this_object()) return;
                me->delete("no_get");
        if (! living(me)) me->revive();
        me->set("eff_jing", me->query("max_jing"));
        me->set("jing", me->query("max_jing"));
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("max_qi"));
        if (me->query("neili") < me->query("max_neili"))
                me->set("neili", me->query("max_neili"));
        if (me->query("jingli") < me->query("max_jingli"))
                me->set("jingli", me->query("max_jingli"));
        me->clear_condition();
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
        me->start_busy(0);
}

int discmds()
{
        tell_object(this_player(), "现在你还是专心看比武吧！\n");

        return 1;
}

/*
int get_weapon(string arg)
{
        object me, ob;
        
        me = this_player();
        
        if (! arg) return notify_fail("你要拿取什么物品？\n");
        
        switch (arg) 
        {
        case "cloth":
                ob = new("/clone/cloth/cloth");
                break;
        case "sword":
                ob = new("/clone/weapon/changjian");
                break;
        case "blade":
                ob = new("/clone/weapon/blade");
                break;
        case "staff":
                ob = new("/clone/weapon/zhubang");
                break;
        case "whip":
                ob = new("/clone/weapon/changbian");
                break;
        case "hammer":
                ob = new("/clone/weapon/hammer");
                break;
        default:  
                return notify_fail("你要拿取什么物品？\n"); 
                break;
        }
        
        ob->move(me);
        
        tell_object(me, "你从架上拿下了你需要的物品。\n");
        return 1;
}
*/
        
string look_notice()
{
        object who;
        string *name_list, file;
        int i, j = 0, k;
        
        who = this_player();
        file = read_file("/log/static/lunjian4");
        if (! file)
                return "目前没有任何比武记录。\n";
        name_list = explode(file, "\n");
        for (i = 0; i < sizeof(name_list); i++) 
        {
                if (name_list[i] == "seperator") 
                {
                        j++;
                        k = 0;
                        printf("\n第" + chinese_number(j) + "届(元老组)华山论剑结果：\n");
                        continue;
                }
                k++;
                printf(GRN "第" + chinese_number(k) + "名：%-50s\n" NOR, name_list[i]);
        }
        return "\n";
}

