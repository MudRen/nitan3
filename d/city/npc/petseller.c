#include <ansi.h>
inherit NPC;

int check_legal_name(string arg);
int check_legal_id(string arg);

void create()
{
        set_name("����", ({ "pian pian" }) );
        set("gender", "Ů��" );
        set("age", 22);
        set("long",@LONG
�������ţ���޸�һС������������������Ϳ�ʹÿ�챳һ��С���������Ҫ
ϲ������Ļ�������Ҳ��(yang)һֻ���档
LONG );
        set("title",HIW"����С��"NOR);
        set("combat_exp", 5);
        set("chat_chance", 15);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/cloth/cloth")->wear();

}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_yang", "yang");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "����˵������λ" + RANK_D->query_respect(ob)
                                + "��Ҫ��СèС��ô��\n");
                        break;
                case 1:
                        say( "����˵������λ" + RANK_D->query_respect(ob)
                                + "����̫�����ˣ��Ҳ������㡣\n");
                        break;
        }
}

int do_yang(string arg)
{
        string ctype, cname, ccolor, cid, ownername, result;
        object ob, me, gold;
        string id,filename;
        object newpet;

        me = this_player();
        id = me->query("id");
        ownername = me->name(1);
        
        if(!arg || sscanf(arg,"%s %s %s %s",ctype,ccolor,cname,cid ) != 4)
        {
                write(@LONG
ָ���ʽ��yang <type> <color> <name> <english name>
�������ĳ��������У�
        С����dog       Сè��cat       С��pig       Сӥ��hawk
        С�monkey    СѼ��duck      С����hen
�����ѡ����ɫ�У�
        $RED$ - ��ɫ    $HIR$ - ����ɫ  $YEL$ - ����ɫ
        $GRN$ - ��ɫ    $HIG$ - ����ɫ  $BLU$ - ����ɫ
        $HIY$ - ��ɫ    $MAG$ - ǳ��ɫ  $HIM$ - �ۺ�ɫ
        $HIB$ - ��ɫ    $HIC$ - ����ɫ  $CYN$ - ����ɫ
        $HIW$ - ��ɫ    $WHT$ - ǳ��ɫ  $NOR$ - ������ɫ
����������йصĽ�����help pet�ο���ص�˵����
LONG );                
                return 1;
        }
        if(me->is_busy())
                return notify_fail("����һ��������û����ɡ�\n");
        if(file_size( me->query_save_file() + ".pet.o") > 0)
                return notify_fail("���Ѿ�ӵ�����İ��ĳ����ˡ�\n");
        gold = present("gold_money", this_player());
        if(!gold)
                return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < 100)
                return notify_fail("������û���������ӡ�\n");
        if((int)me->query("score") < 500)
                return notify_fail("������۲�����\n");
                
        if( (ownername != cname) && (stringp(result = NAME_D->invalid_new_name(cname))) )
        {
                write("�Բ���" + result);
                write(HIR"��ֹʹ��������������ͬ��ӽ��ĳ�����������ѭRULES�ж����ֵ���ع涨��"NOR+"\n");
                return 1;
        }
            
        if( !check_legal_name(cname))
                return notify_fail("");
        if( !check_legal_id(cid))
                return notify_fail("");

        if( ccolor != "$NOR$" &&
            ccolor != "$RED$" &&
            ccolor != "$GRN$" &&
            ccolor != "$YEL$" &&
            ccolor != "$BLU$" &&
            ccolor != "$MAG$" &&
            ccolor != "$CYN$" &&
            ccolor != "$WHT$" &&
            ccolor != "$HIR$" &&
            ccolor != "$HIG$" &&
            ccolor != "$HIY$" &&
            ccolor != "$HIB$" &&
            ccolor != "$HIM$" &&
            ccolor != "$HIC$" &&
            ccolor != "$HIW$" 
        )
        return
                notify_fail("��֪��Ҫʲô��ɫ��\n");
        cname = ccolor + cname;
        if(ccolor != "$NOR$")
        {
                cname = replace_string(cname, "$RED$", RED);
                cname = replace_string(cname, "$GRN$", GRN);
                cname = replace_string(cname, "$YEL$", YEL);
                cname = replace_string(cname, "$BLU$", BLU);
                cname = replace_string(cname, "$MAG$", MAG);
                cname = replace_string(cname, "$CYN$", CYN);
                cname = replace_string(cname, "$WHT$", WHT);
                cname = replace_string(cname, "$HIR$", HIR);
                cname = replace_string(cname, "$HIG$", HIG);
                cname = replace_string(cname, "$HIY$", HIY);
                cname = replace_string(cname, "$HIB$", HIB);
                cname = replace_string(cname, "$HIM$", HIM);
                cname = replace_string(cname, "$HIC$", HIC);
                cname = replace_string(cname, "$HIW$", HIW);
                cname += NOR;
        }
        seteuid(ROOT_UID);
        newpet = new("/clone/misc/pet");        
        switch( ctype ) {
                case "dog":
                        newpet->set("title","С��");
                        newpet->set("int",5+random(10));
                        break;
                case "cat":
                        newpet->set("title","Сè");
                        newpet->set("per",5+random(10));
                        break;
                case "pig":
                        newpet->set("title","С��");
                        newpet->set("str",5+random(10));
                        break;
                case "monkey":
                        newpet->set("title","С��");
                        newpet->set("dex",5+random(10));
                        break;
                case "duck":
                        newpet->set("title","СѼ");
                        newpet->set("con",5+random(10));
                        break;
                case "hen":
                        newpet->set("title","С��");
                        newpet->set("con",5+random(10));
                        break;
                case "hawk":
                        newpet->set("title","Сӥ");
                        newpet->set("dex",5+random(2));
                        break;
                default:
                        return notify_fail("����û����Ҫ�Ķ�����\n");
        }
        newpet->set("owner",me->query("id"));
        newpet->set("possessed",me);
        newpet->set("name",cname);
        newpet->set("id",cid);
        newpet->set("long", "һֻ"+ownername+"����"+newpet->query("title")+"��");
        newpet->save();
        destruct(newpet);
        gold->add_amount(-100);
        me->add("score",-500);
        me->start_busy(1);
        command("say �����Ŵ�һ������(whistle)�����С�����ͻ��ܹ����ģ�");
        seteuid(getuid());
        return 1;
}

int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 10 ) ) {
                write("�Բ����������ֱ�����һ����������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������ֱ��������ġ�\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_id(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 3) || (strlen(name) > 20 ) ) {
                write("�Բ���Ӣ�����ֱ�����������ʮ���֡�\n");
                return 0;
        }

        return 1;
}

