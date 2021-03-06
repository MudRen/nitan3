// master.c

#include <dbase.h>
#include <login.h>

int is_master() { return 1; }

int query_auto_perform() { return 2; }

int prevent_learn(object me, string skill)
{
        mapping fam;

        if (! me->is_apprentice_of(this_object()) &&
            mapp(fam = me->query("family")) &&
            fam["family_name"] == query("family/family_name") &&
            fam["generation"] > query("family/generation"))
        {
                command("say 虽然你是我门下的弟子，可是并非我的嫡传弟"
                        "子... 还是去找你师父学吧。");
                return 1;
        }

        return 0;
}

void attempt_detach(object me)
{
        if (! me->is_apprentice_of(this_object()))
        {
                command("say 边去，找你师傅。");
                return;
        }

        command("sigh");
        
        if (! me->query("zhuanshi"))
        {
                command("say 走吧走吧！你走吧！把你学到的武功留下！");

                me->skill_expell_penalty();
                me->unconcious();

                message_vision("$N将手掌粘在$n的背后，喃喃自语，"
                               "不知道在说些什么。\n", this_object(), me);
                me->add("detach/" + me->query("family/family_name"), 1);
        }
        command("say 走吧走吧！你现在可以走吧！");
        me->delete("family");
        me->delete("quest");
        me->delete("quest_count");
        me->set("title", "普通百姓");
}


nomask void master_accept_kill(object me)
{
        object *inv;

        inv = all_inventory(environment());
        for(int i = 0; i < sizeof(inv); i++) 
        {
                if (! inv[i]->is_character()
                || inv[i] == this_object()
                || inv[i] == me
                || userp(inv[i])
                || inv[i]->query("family/family_name") != this_object()->query("family/family_name"))
                        continue;
                else 
                {
                        message_vision(sprintf("$N朝$n着喊道：“你%s，真是活的不耐烦了！！”\n\n",
                                (me->is_apprentice_of(this_object()))?
                                "胆敢欺师灭祖":((me->query("family/family_name") == this_object()->query("family/family_name"))?
                                "连同门师傅都要杀":"敢动本门师傅" )),inv[i],me );
                        inv[i]->kill_ob(me);
                        me->kill_ob(inv[i]);
                }
        }
        return;
}

