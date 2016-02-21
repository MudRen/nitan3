// Room: /city/leitai.c
// Date: Feb.27 1998 by Java
// Update by Doing
// Modified by Haiyan

#include <ansi.h>

inherit ROOM;
string look_tiaofu();

void create()
{
        set("short", "��̨");
        set("long", @LONG
����һ�����ɼ�������̨����׳��ʵ��ľ������һƬƽ̨���Ľǵ�֧���ϸ�
�����ĸ�����������Ĺ��ڶ�������ؿ���̨�ϵ�������䡣��������һ������
(tiaofu)������д��һЩ������
LONG );
        set("outdoors", "city");
        set("item_desc", ([
                "tiaofu" : (: look_tiaofu :),
        ]));

        set("exits", ([
                "down" : "/d/city/wudao1",
        ]));
        set("objects", ([
                "/adm/npc/referee": 1,
        ]));
	set("coor/x", -60);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_lclose", "lclose");
        add_action("do_lopen", "lopen");
        add_action("do_invite", "invite");
        add_action("do_jiangli", "jiangli");
}

string look_tiaofu()
{
        object ob;

        ob = query("close_by");
        if (! objectp(ob))
                return "����̨�������ɿ��ţ�������Ȥ���б�"
                       "�䣬ʧ�������������Ų�����\n\n"
                       "ע����ʦ����" HIY "lopen" NOR "/"
                       HIY "lclose" NOR "����Źر���̨��\n";

        return "����̨���ڱ�" + ob->name(1) + "��ʱ�رգ�"
               "��֯���䣬�����˵���Ҫ������\n"
               "��ʦ����" HIY "invite" NOR "��������������̨��"
               "����̨��ʹ��" HIY "pass" NOR "����\n"
               "ָ��ĳ����̨���䣬��" HIY "kickout" NOR
               "��ĳ����̨��\n";
}

int refuse(object ob)
{
        return 1;
        if (! wizardp(ob) && query("close_by"))
                return 1;

        return 0;
}

int do_lclose(string arg)
{
        object me,ob;

        me = this_player();
        if (wiz_level(me) < 3)
                return notify_fail("��û���ʸ�ر���̨��\n");

        if (arg != "here")
                return notify_fail("�����Ҫ�ر���̨��������(lclose here)��\n");

        if (objectp(query("close_by")))
                return notify_fail("�����̨�Ѿ���" +
                                   query("close_by")->name(1) +
                                   "�ر����ڱ����ˡ�\n");

        set("close_by", me);
        message("vision", HIW "������ʢ�᡿" + me->name(1) +
                "�ر�����̨����ʼ���б���ʢ�ᡣ\n" NOR,
                all_interactive());

        foreach (ob in all_inventory(this_object())) 
        {
                if (userp(ob) && !wizardp(ob))
                {
                        ob->move("/d/city/wudao1");
                        if (living(ob))
                                tell_object(ob,"��ƽ�Ӷ���˵����̨���ر��ˣ���������̨�ȴ��ɣ�\n");
                }
        }

        set("biwu_room",1);
        return 1;
}

int do_lopen(string arg)
{
        object me;

        me = this_player();
        if (wiz_level(me) < 3)
                return notify_fail("��û���ʸ����̨��\n");

        if (! objectp(query("close_by")))
                return notify_fail("�����̨Ŀǰ��û�б��رա�\n");

        if (query("close_by")->name(1) != me->name())
                return notify_fail("ֻ�������ֱ��������ʦ���ܴ���̨��\n");

        if (arg != "here")
                return notify_fail("�����Ҫ����̨��������(lopen here)��\n");

        delete("close_by");
        message("vision", HIW "������ʢ�᡿" + me->name(1) +
                "�����˱��䣬���¿�������̨��\n" NOR, all_interactive());

        delete("biwu_room");
        return 1;
}

object *broadcast_to()
{
        if (! objectp(query("close_by")))
                return 0;

        return ({ find_object("/d/city/wudao1"),
                  find_object("/d/city/wudao2"),
                  find_object("/d/city/wudao3"),
                  find_object("/d/city/wudao4"), });
}

int do_invite(string arg)
{
        int i;
        object *inv;
        object me;
        object ob;

        me = this_player();
        if (! wizardp(me))
                return notify_fail("�㲻����ʦ��û���ʸ������˼�������\n");

        if (! query("close_by"))
                return notify_fail("������̨��û�йرգ������ص�������ˡ�\n");

        if (query("close_by")->name(1) != me->name())
                return notify_fail("ֻ�������ֱ��������ʦ��������ѡ����̨��\n");

        if (! arg ||
            ! objectp(ob = find_player(arg)))
                return notify_fail("������˭������\n");

        if (environment(ob) == this_object())
                return notify_fail("�ţ����ڲ����Ѿ���������ô��\n");

        if (wizardp(ob))
                return notify_fail("�˼��Լ��������Լ�����������������ġ�\n");

        if (! living(ob))
                return notify_fail("�ô����Ū���˼Ұɣ�\n");

        if (mapp(ob->query_condition()))
                return notify_fail("�Բ��𣬶Է�������״�����ã�������̨��\n");

        if (ob->query("eff_qi") < ob->query("max_qi") ) 
               return notify_fail("�Բ��𣬶Է�����Ѫ�����ˣ�������̨��\n");

        if (ob->query("eff_jing") < ob->query("max_jing"))
               return notify_fail("�Բ��𣬶Է��ľ��������ˣ�������̨��\n");

        inv = deep_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
        {
                if (! userp(inv[i])) continue;
                return notify_fail("�Է����ϱ��Ÿ�������أ�������̨��\n");
        }

        message("vision", HIW + me->name() + "һ����Х��" + ob->name() +
                          "���㻹�����������\n" NOR, all_interactive());
        message_vision("ֻ��$N����ææ�����˿�ȥ��\n", ob);
        message("vision", "ֻ��һ�����ڣ�" + ob->name() + "Ӧ��Ծ��̨�����ý�֮����\n",
                this_object());

        ob->move(this_object());
        tell_object(ob, HIY "��һ��Ŀѣ������һ������ŷ����Լ��Ѿ�����" +
                    environment(ob)->short() + HIY "��\n");
        return 1;
}

int do_jiangli(string arg)
{
        object me = this_player();
        object ob, obv;
        string player, msg;
        string *par;
        int *mc;
        mapping winner;
        int place, gift;

        if (wiz_level(me) < 3)
                return notify_fail("��û���ʸ�����˽�����\n");

        if (! objectp(query("close_by")))
                return notify_fail("������̨��û�������ٿ������ᣬ��" +
                                   "���ܸ����˽�����\n");

        if (query("close_by")->name(1) != me->name())
                return notify_fail("�㲢�������ֱ��������ʦ��" +
                                   "���ܸ����˽�����\n");

        if (! arg || sscanf(arg, "%s %d %d", player, place, gift) != 3)
        {
                msg = "ָ���ʽ��jiangli <ID> <����> <��Ʒ>��\n\n";
                msg += "Example: jiangli haiyan 2 5\n\n";
                msg += "��Ʒ�������£�\n";
                msg += "0 - �������嵤\n";
                msg += "1 - ��ת��\n";
                msg += "2 - ������¶\n";
                msg += "3 - ������\n";
                msg += "4 - �ɵ�\n";
                msg += "5 - ϴ�赤\n";
                msg += "6 - ������\n";
                msg += "7 - ����ɵ�\n";
                msg += "8 - ����ʯ\n";
                msg += "9 - ����˿\n\n";
                me->start_more(msg);
                return 1;
        }

        if ( place < 1 || place > 5)
                return notify_fail("��ֻ�ܽ���ǰ������\n");

        if (! objectp(ob = present(player, this_object())))
                return notify_fail("��Ҫ����˭��\n");

        if (! me->query("winner"))  winner = ([]);
        else
        {
                winner = me->query("winner");
                mc = keys(winner);
                par = values(winner);

                if (member_array(place, mc) != -1)
                       return notify_fail("��" + chinese_number(place) +
                                          "���Ѿ������ˡ�\n");

                if (member_array(player, par) != -1)
                       return notify_fail(player + "�Ѿ�ȡ�������ˡ�\n");
        }

        switch(gift)
        {
             case 0:
                obv = new("/clone/gift/xuanhuang");
                break;
             case 1:
                obv = new("/clone/gift/jiuzhuan");
                break;
             case 2:
                obv = new("/clone/misc/tianxiang");
                break;
             case 3:
                obv = new("/d/shaolin/obj/puti-zi");
                break;
             case 4:
                obv = new("/clone/gift/xiandan");
                break;
             case 5:
                obv = new("/clone/gift/xisuidan");
                break;
             case 6:
                obv = new("/clone/gift/shenliwan");
                break;
             case 7:
                obv = new("/clone/gift/unknowdan");
                break;
             case 8:
                obv = new("/d/item/obj/butian");
                break;
             case 9:
                obv = new("/d/item/obj/tiancs");
                break;
        }

        message("vision", HIW "������ʢ�᡿��ϲ" + ob->query("name") + "(" +
                ob->query("id") + ")��ñ�������� ��" +
                chinese_number(place) + "����\n" NOR,
                all_interactive());
        message_vision("$N�ڻ������˰��죬����һ" + obv->query("unit") +
                       obv->name() + "������$n��\n", me, ob);

        winner += ([ place : ob->query("id") ]);
        me->set("winner", winner);
        obv->move(ob);
        return 1;
}
