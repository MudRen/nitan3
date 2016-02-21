// Room: /guiyun/dating.c
// Date: Nov.18 1998 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǹ���ׯ�������������޽������Զ������������Ϊ�¾ɣ�
����ɨ��ʮ�ָɾ�������Ҳ��Ϊ���㣬��ȫû�г����լ������֮
�����ıڹ���һЩ�����黭��Ʒ����Ϊ�ϳ�֮�����Ե������۹ⲻ
�������д������֡�
LONG );
//      set("outdoors", "guiyun");
//	set("no_clean_up", 0);

	set("exits", ([
		"north" : __DIR__"huating",
		"south" : __DIR__"qianyuan",
		"east"  : __DIR__"shufang",
	]));
	set("objects", ([
		__DIR__"npc/kezhene" : 1,
		__DIR__"npc/zhucong" : 1,
		__DIR__"npc/hanbaoju" : 1,
		__DIR__"npc/nanxiren" : 1,
		__DIR__"npc/zhangasheng" : 1,
		__DIR__"npc/quanjinfa" : 1,
		__DIR__"npc/hanxiaoyin" : 1,
	]));
	setup();
	// replace_program(ROOM);
}

void init()
{
        object me = this_player();
        int score, skill, age;

        if (me->query("age") >= 30 || random(me->query("kar")) < 15)
                return;
                
        if (me->query("family/master_id") != "lu chengfeng" &&   
            me->query("family/master_id") != "qu lingfeng")
                return;


        age = me->query("age") - 13;
        skill = (me->query_skill("force") + me->query_skill("dodge") +
                me->query_skill("strike") + me->query_skill("qimen-wuxing")) / 4;
        skill *= atoi(count_div(me->query("combat_exp"), 1000));
        score = skill / age;

        if (score < 1000) 
                return;
        
        remove_call_out("recruit_ob");
        call_out("recruit_ob", 50, me);
        
        tell_object(me, CYN "���������е�Ź֣��ƺ����˸��棿\n" NOR);
}

void recruit_ob(object me)
{
        object ob, *obj;
        int i, j = 0;

        if (! me) return;

        obj = all_inventory(environment(me));
        
        for(i = 0; i < sizeof(obj); i++)
        {
                if (playerp(obj[i]))
                j++;
        }
        
        if (j > 1) return;

        ob = new(CLASS_D("taohua/huang"));
        if (! me->is_busy())
                me->start_busy(1);
        ob->move(environment(me));

        message_sort("$Nǰ��ͻȻ������һ�ˣ���ĸ��ݣ�����ɫ���ۣ���ɫ�Ź�֮�������������ƺ�����"
                       "΢΢ת��������֮�⣬����ڱǣ����Խ�Ӳ��ľʯ��ֱ��һ������ͷװ�ڻ��˵������ϡ�\n\n", me);
                       
        message_sort("$Nһ��֮�£���ʱһ�������ӱ�����ֱ��������Ŀ�������������ഥ���㶼�����ٿ�����ʱ��"
                       "ͷת����������Ȼ������Ī���������ʦүү�������д��ŵ��һ������� æ��ǰ����������"
                       "�����ĸ�ͷ��˵���������ߵ��ʦ�档����ҩʦ���������ˣ����������������ȴ������ץס$N��"
                       "��һ�ᣬ���Ʊ���$N��ͷ���¡�����\n", me);
        message_sort("$Nһ�����������ϸ�룬�Ͻ����μ�����ʹ��һ�С������ڿա���������ͬΪ�������������Ʈ��һ�����ࡣ\n\n", me);
        message_sort("��ҩʦ΢һ㶣�����һ������" + RANK_D->query_rude(me) + "ȴ�м������ʣ��Ҿͳ�ȫ��ɡ�\n\n", me);
        
        message_sort("$N��Ҫ��$nΪ���ӡ�\n", ob, me);
        tell_object(me, YEL "�����Ը���" + ob->name() + "Ϊʦ������ apprentice ָ�\n" NOR);
        me->set_temp("huang_recr", 1);
        
        remove_call_out("finish_recr");
        call_out("finish_recr", 30, me, ob);
}

void finish_recr(object me, object ob)
{
        if (! objectp(me) || ! objectp(ob))
                return;
                
        if (me->query("family/master_id") != "huang yaoshi")
        {
                message_vision("$N��Цһ����" + RANK_D->query_rude(me) + "��Ȼ�м��ֳ����ӡ�˵��ƮȻ��ȥ��\n", ob);
                me->delete_temp("huang_recr");
                destruct(ob);
        }
        return;
}
