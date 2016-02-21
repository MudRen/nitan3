// by Lonely 2005.1
// updated by Lonely 2007.11.2
// xiang.c 

#include <ansi.h> 

inherit ITEM;
inherit F_SAVE;

#define TO_STORE(x, y) (["name" : ob->query("name"), "id" : ob->query("id"), "file" : base_name(ob), "amount" : x, "sign" : y])

nosave int load;
mapping *store;
mapping *data_dbase;
mapping *temp_dbase;

int do_store(string arg);
int do_take(string arg);
int do_lock(string arg);
int do_open(string arg);
int get_passwd(string pass, object ob);
int confirm(string yn, object me);
int set_passwd(string pass, object ob);
int store_item(object me, object obj, int amount);
int store_data(object me, object ob, int sn);

int clean_up() { return 1; }

mixed *store_signs()
{
        string *sn = ({});
        
        if (! store || sizeof(store) < 1)
                return sn;
                
        for (int i = 0; i < sizeof(store); i++) 
                sn += ({ store[i]["sign"] });
        
        return sn;
}

void create()
{
        set_name(HIM "�۱���" NOR, ({ "ju baoxiang", "baoxiang", "xiang" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {          
                set("long", sort_string(HIW "һ�����ܱ�Ե���������ع⻷�����ӣ���˵"
                                "���Խ����������ƵĴ棨store����ȥ,����"
                                "��ʧ��������ʲôʱ�򶼿���ȡ��take����"
                                "����������ʹ����������lock��������" NOR, 38, 0));
                                
                set("value", 100);              
                set("unit", "��");
                set("no_get", 1);
        }
        setup();
}

string extra_long()
{
        mixed ob_name_real_len;
        string msg, ob_name;
        
        if (query("open") || wizardp(this_player()))
        {
                if (! store || sizeof(store) < 1)
                        return "Ŀǰû�д���κ���Ʒ�������\n";     

                msg = HIW "\nĿǰ���ŵ���Ʒ�У�\n���  ��Ʒ                                      ����\n"
                          "��������������������������������������������������������������������\n" NOR;
              
                for (int i = 0; i < sizeof(store); i++) 
                {
                        ob_name = filter_color(store[i]["name"] + "(" + store[i]["id"] + ")"); 
                        ob_name_real_len = color_len(store[i]["name"] + "(" + store[i]["id"] + ")");
                        msg += sprintf("[%2d]  %-" + (36 + ob_name_real_len) + "s     %5d\n", 
                                        i + 1, store[i]["name"] + "(" + store[i]["id"] + ")",  
                                        store[i]["amount"]);
                        if (store[i]["amount"] == 0)
                                store[i] = 0;
                }
                msg += HIW "��������������������������������������������������������������������\n" NOR;
  
                store -= ({ 0 });
        if (sizeof(data_dbase))
                data_dbase -= ({ 0 });
        if (sizeof(temp_dbase))
                temp_dbase -= ({ 0 });
                return msg;
        } else
        {
                if (query("closed"))
                        msg = HIW "����Ŀǰ�ǹ��ŵģ��ƺ�������������������Ҫ�ȴ�"
                        "����open�����Ӳſ��Բ鿴��look�����������Ʒ��" NOR;
                else
                        msg = HIW "����Ŀǰ�ǹ��ŵģ�����û����������������Ҫ�ȴ�"
                        "����open�����Ӳſ��Բ鿴��look�����������Ʒ��" NOR;

                return sort_string(msg, 38, 0);
        }
}

void init() 
{
        string owner;
        object env; 

        if (! load) 
        {       
                env = environment(this_object());  
                if (stringp(owner = env->query("room_owner_id"))) 
                        set("owner", owner);
                        
                restore();
                load = 1;                    
        }
        
        add_action("do_store", ({ "store", "cun" }));
        add_action("do_take",  ({ "take",  "qu"  }));
        add_action("do_lock",  ({ "lock",  "suo" }));        
        add_action("do_open",  ({ "open",  "kai" }));        
}

int do_open(string arg)
{
        string f, pass, new_pass, st_pass;
        object me;
        int st_stat;

        me = this_player();

        if (! id(arg))
                return notify_fail("��Ҫ���ʲô��\n");
                
        if (query("closed") && this_object()->query("owner") != me)
        {
                write("�����Ѿ����˰����������뿪�����룺");
                input_to((: get_passwd :), me);    
                return 1;
        }
        
        set("open", 1);
        set("closed", 0);
        save();
        write(HIG "�����Ѿ��ɹ��򿪣������� look �鿴������װ�Ķ�����\n" NOR);
        return 1;
}

int get_passwd(string pass, object ob)
{               
        if (crypt(pass, query("passwd")) == query("passwd")) 
        {
                set("open", 1);
                set("closed", 0);
                save();
                write(HIG "�����Ѿ��ɹ������������� look �鿴������װ�Ķ�����\n" NOR);
                return 1;
        } else 
        { 
                write("���������˶���������ԣ�\n");
                return 1;
        }
}

int do_lock(string arg)
{
        string f, pass, new_pass, st_pass;
        object me;
        int st_stat;

        me = this_player();

        if (! id(arg))
                return notify_fail("��Ҫ������ʲô��\n");
        
        if (query("closed") && ! query("open"))
                return notify_fail("�����Ѿ����˰�����\n");
                        
        set("open", 0);
        
        if (this_object()->query("owner") != me->query("id"))
        {
                if (query("passwd"))
                        set("closed", 1);
                save();
                        
                write("������Ӻ���" + (query("passwd") ? "�������˰�����" : "��") + "\n");
                return 1;
        }   
        
        write("�����Ѿ����ϣ�����Ҫ�����Ӹ��������𣿣�" HIR "y" HIG "/" HIY "n" HIG "��\n" NOR);
        input_to((: confirm :), me);
        return 1; 
}

int confirm(string yn, object me)
{
        if (upper_case(yn) == "Y") 
        {                 
                write(HIW "���趨���Ӱ��������룺" NOR);
                input_to((: set_passwd :), me);
                
                return 1;
        } else 
        {
                if (query("passwd"))
                {
                        set("closed", 1);
                        save();
                        return 1;
                }
                write(HIG "��ѡ���˷����Ӱ�����\n" NOR);
                return 1;
        }
}

int set_passwd(string pass, object ob)
{ 
        write("\n");

        if (strlen(pass) < 5)
        {
                write("��������ĳ�������Ҫ�����Ԫ�����������İ������룺\n");
                input_to((: set_passwd :), ob);
                return 1;
        }
        
        set("closed", 1);             
        set("passwd", crypt(pass, 0));
        save();
        write(HIG "�����Ѿ��ɹ����ϣ����ס���趨�����룡\n" NOR);
        return 1;
}

int do_take(string arg)
{
        object me, ob;
        int i, j, sn, amount, amount1;
        mapping data;
        string *ks;

        me = this_player();

        if (query("open") != 1 && ! wizardp(me)) 
                return notify_fail("�����Ѿ����������Ƚ�����\n");

        if (! arg || sscanf(arg, "%d %d", sn, amount) != 2) 
                return notify_fail("��ʽ�������� take ��� ���� ��ȡ����Ʒ��\n");

        if (amount < 1 || amount > 2000) 
                return notify_fail("ÿ��ȡ��Ʒ����������С��һͬʱҲ���ܴ�����ǧ��\n");
                
        if (sn < 1) return notify_fail("��Ҫȡ�ڼ�����Ʒ��\n");
        
        if (! store || sizeof(store) < 1 || sn > sizeof(store)) 
                return notify_fail("���������û�д��������Ʒ��\n");        
                
        if (amount > store[sn-1]["amount"]) 
                // return notify_fail("������Ʒ��û����ô�����\n");
                amount = store[sn-1]["amount"];

        if (! (ob = new(store[sn-1]["file"])))
        {
                store[sn-1] = 0; 
                store -= ({ 0 }); 
                tell_object(me, "�޷�ȡ������Ʒ��ϵͳ�Զ����֮��\n"); 
                return 1;
        }

        if (me->query_encumbrance() + ob->query_weight() * amount > me->query_max_encumbrance()) 
        {
                tell_object(me, "��ĸ��ز������޷�һ��ȡ����ô����Ʒ��\n");
                destruct(ob);
                return 1;
        }

        store[sn-1]["amount"] -= amount;
        
        if (ob->query_amount()) 
        {
                if (store[sn-1]["amount"] == 0) 
                {
                        store[sn-1] = 0;
                        store -= ({ 0 });
                }
                ob->set_amount(amount);
                ob->move(me, 1);
                save();                                
                message_vision("$N��������ȡ��һ" + ob->query("unit") + ob->query("name") + "��\n", me);
                return 1;
        }
        
        destruct(ob);        
        amount1 = amount;
                             
        while (amount1--) 
        {
                reset_eval_cost();
                ob = new(store[sn-1]["file"]);
                if (store[sn-1]["sign"] == 0)
                {
                        ob->move(me, 1);
                        continue;
                }
                
                if (data_dbase && sizeof(data_dbase) > 0)
                {
                        for (i = 0; i < sizeof(data_dbase); i++)
                        {
                                if (data_dbase[i]["sign"] == store[sn-1]["sign"])
                                {
                                        data = data_dbase[i];
                                        ks = keys(data);
                                        for (j = 0; j < sizeof(ks); j++) 
                                        {
                                                if (ks[j] == "sign") continue;                            
                                                ob->set(ks[j], data[ks[j]]);
                                        }                                        
                                        data_dbase[i] = 0;
                                }
                        }
                        data_dbase -= ({ 0 });
                }
                if (temp_dbase && sizeof(temp_dbase) > 0)
                {
                        for (i = 0; i < sizeof(temp_dbase); i++)
                        {
                                if (temp_dbase[i]["sign"] == store[sn-1]["sign"])
                                {
                                        data = temp_dbase[i];
                                        ks = keys(data);
                                        for (j = 0; j < sizeof(ks); j++) 
                                        {
                                                if (ks[j] == "sign") continue;                            
                                                ob->set_temp(ks[j], data[ks[j]]);
                                        }
                                        temp_dbase[i] = 0;
                                }
                        }
                        temp_dbase -= ({ 0 });  
                }   
                
                if(ob->query("id") != store[sn-1]["id"] || 
                   ob->query("name") !=  store[sn-1]["name"]) 
                { 
                        amount1++;
                        destruct(ob);
                        continue;
                }                           
                ob->move(me, 1);
        }
        
        if (store[sn-1]["amount"] == 0) 
        {
                store[sn-1] = 0;
                store -= ({ 0 });
        }
        save();
        message_vision("$N��������ȡ��" + chinese_number(amount) + 
                        ob->query("unit") + ob->query("name") + "��\n", me);
        return 1;
}

int do_store(string arg)
{
        int i, amount;
        string item;
        object me, ob1, ob2, *inv;

        me = this_player();

        if (! arg) return notify_fail("��Ҫ���ʲô������\n");
        
        if (me->is_busy()) return notify_fail("������æ���أ�\n");

        if (query("open") != 1 && ! wizardp(me)) 
                return notify_fail("�����Ǻ��ϵģ����ȴ򿪣�open�����ٷ�����Ʒ��\n");

        if (store && sizeof(store) > 200)
                return notify_fail("�������ֻ�ܴ������ٸ����ӣ����������Ѿ����ˡ�\n");
 
        if (arg == "all") 
        {
                inv = all_inventory(me);
                for(i = 0; i < sizeof(inv); i++) 
                {
                        reset_eval_cost();
                        do_store(inv[i]->query("id"));
                }
                return 1;
        } else                       
        if (sscanf(arg, "%d %s", amount, item) == 2)
        {
                if(! objectp(ob1 = present(item, me)))
                        return notify_fail("������û������������\n");
                       
                if (! ob1->query_amount())
                        return notify_fail(ob1->name() + "���ܱ��ֿ���š�\n");

                if (amount < 1)
                        return notify_fail("�涫��������������һ����\n");

                if (amount > ob1->query_amount())
                        return notify_fail("��û����ô���" + ob1->name() + "��\n");

                if (amount == (int)ob1->query_amount())
                        return store_item(me, ob1, amount);
                else 
                {
                        ob1->set_amount((int)ob1->query_amount() - amount);
                        ob2 = new(base_name(ob1));
                        ob2->set_amount(amount);
                        if(! store_item(me, ob2, amount)) 
                        {
                                ob2->move(me);
                                return 0;
                        }
                        return 1;
                }
        }       
        
        if(! objectp(ob1 = present(arg, me)))
                return notify_fail("������û������������\n");

        if (ob1->query_amount()) 
                return do_store(ob1->query_amount() + " " + arg);

        store_item(me, ob1, 1);
        return 1;
}

int store_item(object me, object ob, int amount)
{
        object obj;
        int i, n, sn;

        if (! objectp(ob)) 
        {
                error("no this object!\n");
                return 0;
        }
        
        if (inherits(F_SILENTDEST, ob))
        {
                tell_object(me, "���Ӳ�����" + ob->query("name") + "�������Լ����ƴ���\n");
                return 0;
        }

        if (member_array(ITEM + ".c", deep_inherit_list(ob)) == -1 &&
            member_array(COMBINED_ITEM + ".c", deep_inherit_list(ob)) == -1)
        {
                tell_object(me, "���Ӳ�����" + ob->query("name") + "�������Լ����ƴ���\n");
                return 0;
        }

        if (member_array(MONEY+ ".c", deep_inherit_list(ob)) != -1)
        {
                tell_object(me, "���Ӳ�����" + ob->query("name") + "��Ҫ��Ǯ�Ļ���ȥǮׯ�ɡ�\n");
                return 0;
        }

        if (base_name(ob) == "/clone/misc/corpse" ||
            base_name(ob) == "/clone/misc/head" ||
            base_name(ob) == "/clone/misc/part" ||
            sscanf(base_name(ob), "/data/%*s") ||
            ob->is_character() ||
            ob->query("task_ob") ||
            ob->is_item_make() ||
            ob->query("id") == "pass" ||
            ob->query("id") == "key" ||
            ob->query("unique") ||
            ! clonep(ob)) {
                tell_object(me, "���Ӳ�����" + ob->query("name") + "�������Լ����ƴ���\n");
                return 0;
        }

        switch((string)ob->query("equipped")) 
        {
        case "worn":
                tell_object(me, ob->name() + "���������������ܴ�š�\n");
                return 0;
        case "wielded":
                tell_object(me, ob->name() + "�����Ƚ��װ�����ܴ�š�\n");
                return 0;
        }
        
        if (sizeof(all_inventory(ob))) 
        {
                tell_object(me, "�����Ȱ�" + ob->query("name") + "����Ķ������ó����ٴ�š�\n");
                return 0;
        }
        
        if (! store) store = ({});
        
        n = sizeof(store);

        if (! ob->query_amount()) 
        { 
                obj = new(base_name(ob));
                if (! compare_mapping(ob->query_entire_temp_dbase(), obj->query_entire_temp_dbase()) || 
                    ! compare_mapping(ob->query_entire_dbase(), obj->query_entire_dbase()))
                {                        
                        while(1) 
                        { 
                                sn = time() + random(99999999);
                                if (member_array(sn, store_signs()) == -1)
                                        break; 
                        }
                        store += ({ TO_STORE(amount, sn)});
                        store_data(me, ob, sn);
                        save();               
                        message_vision("$N����" + chinese_number(amount) + ob->query("unit") + 
                                        ob->query("name") + "�������\n", me);             
                        destruct(ob);
                        destruct(obj);
                        return 1;  
                }
                destruct(obj);  
        }
              
        for (i = 0; i < n; i++) 
        {
                if (store[i]["id"] == ob->query("id") && 
                    store[i]["name"] == ob->query("name") && 
                    store[i]["file"] == base_name(ob)) 
                {
                        store[i]["amount"] += amount;
                        
                        message_vision("$N����" + (amount > 1 ? "һ" : chinese_number(amount)) +
                                        ob->query("unit") + ob->query("name") + "�������\n", me);                               
                        destruct(ob);
                        save();
                        return 1;
                }
        }

        store += ({TO_STORE(amount, 0)});
        save();

        message_vision("$N����" + (amount > 1 ? "һ" : chinese_number(amount)) +
                        ob->query("unit") + ob->query("name") + "�������\n", me);           

        destruct(ob);
        return 1;
}

int store_data(object me, object ob, int sn)
{
        mapping data;

        if (! data_dbase) 
                data_dbase = ({});
        data = ob->query_entire_dbase();
        data += ([ "sign" : sn ]);
        data_dbase += ({ data });
        
        if (! temp_dbase)
                temp_dbase = ({});
                
        data = ob->query_entire_temp_dbase();
        
        if (! data) return 1;
        
        data += ([ "sign" : sn ]);        
        temp_dbase += ({ data });
        
        return 1;
}

int remove() { save(); }

string query_save_file() 
{
        string id;

        if (! stringp(id = query("owner")) ) return 0;
        return DATA_DIR + "room/" + id + "/" + "xiang";
}
