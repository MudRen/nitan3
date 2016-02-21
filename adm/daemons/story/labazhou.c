 // story:labazhou ������
 // Plzw 2004-08-29

#include <ansi.h>

nosave string char_id;
nosave string char_name;
nosave string fam_name;
nosave string ann_name;
nosave string ann_id;

mixed give_pai();
int   rob_pai();
object   select_characters();

nosave mixed *story = ({
        "����һ��Ķ��졣",
        "ҹ��$N���ڴ�����Ҫ��Ϣ��",
        "��������һ������˵���������͵����Ʒ���ʹ�ߣ�ǰ���ݼ�$F��$N����",
        "$N�����ȥ��ֻ��Ժ���ﲢ��վ��һ��һ�������ˡ�",
        "$Nһ����һ��һ�����ˣ�������������ݶ�λ�������͵������Ʒ���ʹ��ô����",
        "�������������ǡ����¿���$F��$N�����Ƿ����͵�����֮�����ֳ�ͭ��ǰ����������¸��ֵ����𣬺�һ�������ࡣ��",
        "$N��Ĭ���",
        "...",
        "�������������²�˵�����Ǿ����ˡ���",
        "�����ӻ���ȡ��һ��ͭ�ƣ�Ц������������ˣ���������׼ʱ��Լ��",
        "$N֪�������Ʒ���ʹ�ߵ�����������֮�£��ӹ�ͭ�Ƶ�����������л�󵺷�������������ǰ�ϵ�����",
        "��������������һЦ��ת����ʧ��ҹĻ�С�",
        "...",
        (: give_pai :),
        "$AN��Ц���������⵨С����֮�ˣ��е�ȥô�����罫�������ң��ҵ���ȥ���͵���ʶ��ʶ����",
        "$N���룺��Ȼ����»��������������ˣ��Լ�����Ҳ����ȥ�������ø�������",
        "$N��ͭ�Ƶ��ϵ�������Ȼ��̨��ȥ����ȥ���ǣ���",
        "$AN�ӹ�ͭ�ƹ�����Ц������һ������Ȼ��ʧ��ҹĻ�С�",
        (: rob_pai :),
});

void create()
{
        seteuid(getuid());

        if (! objectp(select_characters()))
        {
                STORY_D->remove_story("labazhou");
                destruct(this_object());
                return;
        } 
}

string prompt() { return HIG "������������" NOR; }

object select_characters()
{
        object *obs;
        object ob;

        obs = filter_array(all_interactive(),
                           (: living($1) &&
                                  $1->query("family") &&   
                              /*     
                              $1->query("weiwang") >= 50000 &&
                              $1->query("score") >= 50000 &&
                              $1->query_skill("force", 1) >= 100 &&
                              $1->query_skill("dodge", 1) >= 100 &&
                              $1->query_skill("parry", 1) >= 100 &&
                              */
                              count_ge($1->query("combat_exp"), 100000) &&
                              !wizardp($1) &&
                              !$1->query("story/labazhou") :));
        if (! sizeof(obs))
                return 0;

        ob = obs[random(sizeof(obs))];
        char_id = ob->query("id");
        char_name = ob->name(1);
        fam_name = ob->query("family/family_name");

                obs = filter_array(all_interactive(), 
                                                        (: living($1) &&
                                                        $1->query("weiwang") >= 50000 &&
                                                        $1->query("score") >= 50000 &&
                                                        /*
                                                        $1->query_skill("force", 1) >= 150 &&
                                                        $1->query_skill("dodge", 1) >= 150 &&
                                                        $1->query_skill("parry", 1) >= 150 &&
                                                        */
                                                        count_ge($1->query("combat_exp"), 100000) &&
                                                        !wizardp($1) &&
                                                        !$1->query("story/labazhou") :));
        if (! sizeof (obs))
                return ob;
        ob = obs[random(sizeof(obs))];
        ann_id = ob->query("id");
        ann_name = ob->name(1);
        return ob;
}

mixed query_story_message(int step)
{
        mixed msg;

        if (step >= sizeof(story))
                return 0;

        msg = story[step];
        if (stringp(msg))
        {
                msg = replace_string(msg, "$N", char_name);
                msg = replace_string(msg, "$ID", char_id);
                msg = replace_string(msg, "$F", fam_name);
                msg = replace_string(msg, "$AN", ann_name);
                msg = replace_string(msg, "$AID", ann_id);
        }
        return msg;
}

mixed give_pai()
{
        object ob;
        object pai;

        ob = find_player(char_id);
        if (! ob) return 1;
                
                if (random(4) > 0)
                {
                        
                ob->set("story/labazhou", 1);
                CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + ob->name(1) +
                                      "�յ�����ľ������������ȥ���͵��������ࡣ");
                // ���������ƣ������ǳͶ�
                if (ob->query("shen") >= 0)
                        pai = new("/d/xiakedao/obj/tongpai1");
                else
                        pai = new("/d/xiakedao/obj/tongpai2");
                                
                pai->move(ob, 1);
                STORY_D->remove_story("labazhou");
                return 0;
            }
            // 25%�ļ��ʱ���
            if (ann_id != char_id)
                return "һ����Ӱ�ӹ���һ�����صĻ���" + char_name + "�ı��ģ�" + char_name + "���һ�����³�һ����Ѫ��";
            
}

int rob_pai()
{
        object ob, rob;
        object pai;
                
        ob = find_player(char_id);
        rob = find_player(ann_id);
        if ((! ob) || (! rob)) return 1;
                
        rob->set("story/labazhou", 1);
        CHANNEL_D->do_channel(this_object(), "rumor",
                              "��˵" + rob->name(1) + "��" + ob->name(1) + "���ж�����"
                              "���Ʒ������ơ�");
        STORY_D->remove_story("labazhou");
        if (rob)
        {
                // ���������ƣ������ǳͶ�
                if (rob->query("shen") >= 0)
                        pai = new("/d/xiakedao/obj/tongpai1");
                else
                        pai = new("/d/xiakedao/obj/tongpai2");
                if (pai) pai->move(rob, 1);
        }
        return 0;
}


