// ��ջ�๤���ػ���kezhan.c

// Updated by Lonely



// ��׼����(�ϰ�)

//     |

// ���乤��(С��) -+- ɨ�� ----+

//                 |           +-- �������� -- ��� +

//                 +- ϴ���� --+                    |

//                                 ��ȡ����(С��) --+



#include <ansi.h>



#define NAME            "kezhan"        // ��������

#define BONUS           10 + random(30) // ��������

#define MAX_NUM         20              // ���������Ϊ 0 ʱ�����

#define MIN_EXP         0               // ���پ���

#define MAX_EXP         100000          // ��ྭ�飬Ϊ 0 ʱ�����



// �ṩ���ⲿ����

public int    query_work(object me);

public int    request_work(object me, object ob);

public int    start_work(object me);

public int    finish_work(object me, object ob, object obj);

public string assign_work(object me);



// �������󴴽�

void create() { seteuid(getuid()); }



private int fail_msg(string arg) 

{ 

        write(arg);

        return 1; 

}



private string query_zone(object arg)

{

        string zone;

        

        if (sscanf(file_name(arg), "/d/%s/%*s", zone) == 2)

                return zone;

        return "work";

}



// ��ѯ me ������״̬

public int query_work(object me) { return me->query_temp("work/" + NAME + "/state"); }



// ��������me Ϊ�����ߣ�ob Ϊ��������

public int request_work(object me, object ob)

{

        // ���ɹ����ߵļ��

        if (playerp(ob) || ob->query("work/name") != NAME)

                return fail_msg(ob->name() + "������Ǻ�ɵЦ��\n");



        if (MAX_NUM > 0 && ob->query("work/working") >= MAX_NUM)

                return fail_msg(ob->name() + "һ��ü��������������"

                                "���ﲻȱ���֣�������ٵ�ʱ��������"

                                "����\n");

        // ���ܹ����ߵļ��

        if (ob->query("combat_exp") < MIN_EXP)

                return fail_msg(ob->name() + "Ƴ��" + me->name() +

                                "һ�۵�������ƾ��Ҳ�ɵ������⹤����"

                                "��\n");

        if (MAX_EXP > 0 && me->query("combat_exp") > MAX_EXP && ! wizardp(me))

                return fail_msg(ob->name() + "������Ц���������С"

                                "�¾Ͳ����鷳�������ˡ���\n");



        switch(query_work(me))

        {

        // 0 Ϊ�������˹���

        case 0:

                message_vision(CYN "$N" NOR CYN "һ��ͷ��$n" NOR CYN 

                               "�������ţ��ðɣ���ȥ����������ʲô����"

                               "�����ġ���\n", ob, me);

                // �趨������˹�����״̬

                me->set_temp("work/" + NAME + "/state", 1);

                me->set_temp("work/" + NAME + "/zone", query_zone(environment(ob)));



                break;

        // 1 Ϊ����ˣ���δ��ʽ��ʼ����

        case 1:

                message_vision(CYN "$N" NOR CYN "�ɻ�Ķ�$n" NOR CYN

                               "�������ף��㲻���Ѿ����˹���ô��������"

                               "ȥ����\n", ob, me);

                break;

        // 2 Ϊ���ڽ��й���

        case 2:

                message_vision(CYN "$N" NOR CYN "����üͷ��$n" NOR CYN

                               "�������㲻��������������ȥ��������"

                               "�������콱������\n", ob, me);

                break;

        // 3 Ϊ���������Ѿ���ɣ�����ȡ����

        case 3:

                message_vision(CYN "$N" NOR CYN "��ë��Ĩ��Ĩ�֣���$n"

                               NOR CYN "�������ƹ�ģ��ҵ��¶������ˣ�"

                               "��......��\n", me, ob);

                finish_work(me, ob, 0);

                break;

        default:

                return 0;

        }

        return 1;

}



// ����״̬����һ������Ĺ�����֧�����������������֧��������Ϣ

public string assign_work(object me)

{

        string msg;

        int i;

        object dish, besom;



        switch (random(2))

        {

        // ϴ����

        case 0:

                i = 2 + random(3);

                dish = new("/clone/work/dish");

                dish->set_amount(i);

                dish->move(me);

                msg = "����������" + chinese_number(i) + "������(dish)��"

                      "�����ϴϴ(wash)���������ء�";

                me->set_temp("work/" + NAME + "/type", "wash");

                me->set_temp("work/" + NAME + "/wash", i);

                break;

        // ɨ��

        case 1:

                besom = new("/clone/work/besom");

                besom->move(me);

                msg = "������ĵ�(floor)Ҳ������ˣ�����������ܸ�ɨɨ"

                      "(sweep)���ֽ�����Щ��";

                me->set_temp("work/" + NAME + "/type", "sweep");

                break;

        }

        me->set_temp("work/" + NAME + "/state", 2);

        return msg;

}



// ��ʼ����������������ϵ��趨������������

public int start_work(object me)

{

        string type;

        object ob;

        string *place;



        if (! mapp(me->query_temp("work/" + NAME)))

                return fail_msg("�����ڲ�û���쵽����ѽ��Ϲ���ڸ�ɶ��"

                                "��\n");

        

        if (! stringp(type = me->query_temp("work/" + NAME + "/type")) ||

            type != "wash" && type != "sweep")

                return fail_msg("�ƺ�ʲô�ط�����һ�����⣬�㲢û�б�"

                                "���䵽����Ĺ������͡�\n");



        if (me->is_busy())

                return fail_msg("��æ������������ٹ����ɡ�\n");



        switch (type)

        {

        case "wash":

                if (! objectp(ob = present("dirty dish", me)))

                        return fail_msg("��������Ѿ�û���������ˡ�\n");



                if (! environment(me)->query("resource/water"))

                        return fail_msg("����û��ˮ����ôϴ�أ�\n");



                if (me->query("qi") < 30 || me->query("eff_qi") < 50 ||

                    me->query("jing") < 20 || me->query("eff_jing") < 50)

                        return fail_msg("����ЪЪ��ϴ�ɣ��ɱ�ϴ����ϴ��"

                                        "��������\n");



                me->set_temp("work/" + NAME + "/step", 1);

                me->start_busy(bind((: call_other, __FILE__, "continue_working" :), me),

                               bind((: call_other, __FILE__, "halt_working" :), me));



                tell_object(me, "�㿪ʼ������\n");

                return 1;

                

        case "sweep":

                if (! objectp(ob = present("besom", me)))

                        return fail_msg("������϶�û��ɨ�ѣ���ôɨ��\n");



                // ֻ���ڿ�ջɨ��

                if (! environment(me)->query("hotel") ||

                    me->query_temp("work/" + NAME + "/zone") != query_zone(environment(me)))

                        return fail_msg("����ɲ��ǵ�С������ɨ�ĵط�ѽ��\n");



                if (arrayp(place = me->query_temp("work/" + NAME + "/place")) &&

                    member_array(file_name(environment(me)), place) != -1)

                        return fail_msg("����ط����Ѿ�ɨ���ˣ��������ظ�һ�Ρ�\n");



                if (me->query("qi") < 30 || me->query("eff_qi") < 30 ||

                    me->query("jing") < 20 || me->query("eff_jing") < 30)

                        return fail_msg("����ЪЪ��ɨ�ɣ��ɱ�ɨ��ϴ����������\n");



                me->set_temp("work/" + NAME + "/step", 1);

                me->start_busy(bind((: call_other, __FILE__, "continue_working" :), me),

                               bind((: call_other, __FILE__, "halt_working" :), me));



                tell_object(me, "�㿪ʼ������\n");

                return 1;

        }

        return 0;

}



// ���ڹ���

int continue_working(object me)

{

        string msg;

        int finish;

        int b;



        if (! me->query_temp("work/" + NAME + "/step"))

                me->set_temp("work/" + NAME + "/step", 1);



        if (! living(me))

        {

                me->delete_temp("work/" + NAME + "/step");

                return 0;

        }



        finish = 0;

        me->receive_damage("jing", 1);

        me->receive_damage("qi", 2);

        

        switch (me->query_temp("work/" + NAME + "/type"))

        {

        case "wash":

                switch (me->query_temp("work/" + NAME + "/step"))

                {

                case 1:

                        msg = "$Nץ��һ�������ӣ�����ˮ�衣";

                        break;

                case 2:

                        msg = "$N�������ﵹ��һЩ���Һ��";

                        break;

                case 3:

                        msg = "$N�����������ӣ���������Ĩ������ʼ��Ĩ��";

                        break;

                case 4:

                case 6:

                        msg = "$NС������Ĳ�Ĩ���ӡ�";

                        break;

                case 5:

                        msg = "$N��Ĩ��պ�˵�ˮ��������ϸ��ϴ���ӡ�";

                        break;

                case 7:

                        msg = "$N���ϲ�Ĩ�����ӣ������ϵ��۹�������ȥ��";

                        break;

                default:

                        msg = "$Nϴ���Ժ󣬽�����͸�ɣ���Ĩ��һĨ�������Ա����ɡ�";

                        finish = 1;

                        break;

                }

                break;

        case "sweep":

                switch (me->query_temp("work/" + NAME + "/step"))

                {

                case 1:

                        msg = "$Nץ���ֱߵ�ɨ�ѣ��������ס�";

                        break;

                case 2:

                        msg = "$N���������˵�ˮ��";

                        break;

                case 3:

                        msg = "$N�����ĻӶ�ɨ�ѣ���ʼ��ɨ���ϵ�������";

                        break;

                case 4:

                case 6:

                        msg = "$N��ͷ��ɨ���ϵĻҳ���";

                        break;

                case 5:

                        msg = "$N����űߵ�������������ϸ��ɨ�ء�";

                        break;

                case 7:

                        msg = "$N����ɨ���ŵ��棬���潥����ù�ɼ��ˡ�";

                        break;

                default:

                        msg = "$Nɨ���Ժ󣬽����е�����������𣬷���ɨ�ѡ�";

                        finish = 1;

                        break;

                }

                break;

        }

        msg += "\n";



        if (finish)

        {

                object dish, cdish;



                me->delete_temp("work/" + NAME + "/step");



                b = BONUS;

                // ��������

                if (me->query("combat_exp") > 200000)

                {

                        // ����̫�ߣ���������

                        b = b / 2 + 1;

                        if (me->query("combat_exp") > 400000)

                        {

                                // �ٴ���������

                                b = b / 2 + 1;

                        }

                }

                me->add("combat_exp", b);

                me->improve_potential((b + 2) / 3);



                if (me->query_temp("work/" + NAME + "/type") == "wash")

                {

                        if (objectp(dish = present("dirty dish", me)))

                        {

                                dish->add_amount(-1);

                                me->add_temp("work/" + NAME + "/washed", 1);

                                if (! objectp(cdish = present("clear dish", me)))

                                {

                                        cdish = new("/clone/work/cdish");

                                        cdish->move(me);

                                }

                                else 

                                        cdish->add_amount(1);

                        }

                        // ϴ�������е�����

                        if (me->query_temp("work/" + NAME + "/washed") ==

                            me->query_temp("work/" + NAME + "/wash"))

                                me->set_temp("work/" + NAME + "/state", 3);

                        msg += "��ϴ����һ���ɾ������ӡ�\n";

                }

                else

                {

                        me->add_temp("work/" + NAME + "/place",

                                    ({ file_name(environment(me)) }));

                        me->set_temp("work/" + NAME + "/state", 3);

                        msg += "�������ط�ɨ�ɾ��ˡ�\n";

                }

        }



        msg = replace_string(msg, "$N", "��");

        tell_object(me, msg);



        if (finish)

        {

                if (b > 0)

                {

                        tell_object(me, HIC "\n������" +

                                    chinese_number(b) +

                                    "�㾭���" +

                                    chinese_number((b + 2) / 3) +

                                    "��Ǳ�ܡ�\n\n" NOR);

                }

                return 0;

        }



        me->add_temp("work/" + NAME + "/step", 1);

        return 1;

}



// ��;ֹͣ����

int halt_working(object me)

{

        if (me->query_temp("work/" + NAME + "/type") == "wash")

                message_vision("$N�����е�Ĩ�����Ӷ���һ�ԣ�Ĩ��Ĩ������"

                               "̫����̫���ˣ�ЪЪ�ٸɡ�\n", me);

        else

                message_vision("$Nͣ���֣�������ߵ�ɨ���ϣ�Ĩ��Ĩ������"

                               "̫����̫���ˣ�ЪЪ�ٸɡ�\n", me);



        me->delete_temp("work/" + NAME + "/step");

        return 1;

}



// ������������ȡ����

public int finish_work(object me, object ob, object obj)

{

        mapping m;

        object coin;



        if (! objectp(obj) || environment(obj) != me)

                return fail_msg(ob->name() + "���ͷ�����������ˣ��Ǿ�"

                                "��ѹ��߻�����С��ȥѽ����\n");



        if (! (m = me->query_temp("work"))) 

                return 0;

        

        if (! mapp(m) || m[NAME]["state"] != 3)

        {

                write(CYN + ob->name() + "�ɻ�������㻹û�����أ�����"

                      "Ҫ��������\n" NOR);

                return 0;

        }



        switch (m[NAME]["type"])

        {

        case "wash":

                if (obj->query("id") != "dish")

                {

                        write(CYN + ob->name() + "ɨ��һ��" + obj->name() +

                              "�����������ҽ���ϴ�����ӣ���\n" NOR);

                        return 0;

                }

                if (obj->query_amount() != m[NAME]["wash"])

                {

                        write(CYN + ob->name() + "������" + obj->name() +

                              "�����������ӵ���Ŀ����ѽ����������ˣ���\n" NOR);

                        return 0;

                }

                // ��Ǯ����

                write(sort_msg(CYN + ob->name() + "���˿�" + obj->name() +

                               "�����ͷ�������ţ���������������Ĺ�Ǯ��"

                               "�պ��ˡ���\n" NOR));

                coin = new("/clone/money/coin");

                coin->set_amount(BONUS * m[NAME]["wash"] * 2);

                coin->move(me, 1);

                break;



        case "sweep":

                if (obj->query("id") != "besom")

                {

                        write(CYN + ob->name() + "ɨ��һ��" + obj->name() +

                              "�����������Ҹ����ɨ�ѣ���\n" NOR);

                        return 0;

                }

                if (! arrayp(m[NAME]["place"]) || ! sizeof(m[NAME]["place"]))

                {

                        write(CYN + ob->name() + "�ɴ��۾����������������"

                              "��Ҳûɨѽ����\n" NOR);

                        return 0;

                }

                // ��Ǯ����

                write(sort_msg(CYN + ob->name() + "����" + obj->name() +

                               "�����ͷ�������ţ���������������Ĺ�Ǯ��"

                               "�պ��ˡ���\n" NOR));

                coin = new("/clone/money/coin");

                coin->set_amount(BONUS * sizeof(m[NAME]["place"]) * 2);

                coin->move(me, 1);

                break;



        default:

                write(CYN + ob->name() + "ץ��ץ�Դ���������ɵ�����ʲ"

                      "ô�أ�����ô��֪��ѽ����\n" NOR);

                return 0;

        }

        // �����������Ϣ

        me->delete_temp("work");

        return 1;

}



mixed *query_info() { return ({ NAME, BONUS, MAX_NUM, MIN_EXP, MAX_EXP }); }

