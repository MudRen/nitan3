inherit F_CLEAN_UP;



#include <ansi.h>



mixed random_gift();



nosave mixed *story = ({

        "ĳ�����ڴ����У���Ȼ��һͷҰ��������˹�������",

        "ĳ�˴����һ����Ұ��Ӧ�������� ĳ�˽�Ұ��Ƥë����ɾ���������һ�ѻ�������",

        "һ����󡭡�",

        "����ʹ�����ۣ����㰡����",

        "����ʹ���ǰ����ߣ����ǹ�ȥ���ơ�",

        "ĳ��һ�߿���Ұ���⣬һ�������Ŵ�����ɢ����������ζ��",

        "��ʱֻ�����������˹���������һ��˵�������������㰡����",

        "ĳ����æ˵��������λ������������һͬ�԰ɣ�������ô��һ����һ����Ҳ�Բ��ꡣ��",

        "����ʹ�������������ĵ��������������Ǿͳ԰ɣ���",

        "����ʹ�����ã����������Ǿ��ó����Ȱɡ�����",

        "ĳ��˵��������λӢ������������ܺ��𣿡�",

        "����ʹ������Ʋ�����ͨ�ľƣ���������֮�˺���������������������������Ȱ�㻹�ǲ�Ҫ�ȵúá���",

        "����ʹ�����ԣ���Ҫ�ȵúã���",

        "ĳ��ʵ�ڿɿʵ����������������ƺ�«�������������",

        "����ʹ������������",

        "����ʹ������������",

        "��һ�����ĳ�˸о����������������ڲ�����壬��æ�˹����⡭��",

        (: random_gift :),

});



void create()

{

        seteuid(getuid());

}



string prompt() { return HIR "������������" NOR; }



mixed query_story_message(int step)

{

        return step < sizeof(story) ? story[step] : 0;

}



mixed random_gift()

{

        object *obs;

        object ob;

        string msg;

        int max_neili;



        obs = filter_array(all_interactive(), (: ! wizardp($1) &&

                                                 environment($1) &&

                                                 environment($1)->query("outdoors") &&
                                                 ! $1->query("env/no_story") &&

                                                 ! $1->query("doing") :));

        if (! sizeof(obs))

                return 0;



        ob = obs[random(sizeof(obs))];

        

        if (ob->query("gift/max_neili") || random(5) 

            || ob->query("character") != "��������"

            || ob->query("max_neili") < 3000)

        {

                msg = HIR + ob->name(1) + "һ���ҽУ����˹�ȥ��" NOR;

                ob->unconcious();

 

        } else

        {

                msg = HIY "��������" + ob->name(1) +

                      HIY "�˹���ϣ�ֻ����������ˬ������������" NOR;

                ob->improve_neili(500);
                ob->set("gift/max_neili", 1);

        }

        return msg;

}

