// xiang.c 

#include <ansi.h> 

inherit ITEM;
inherit F_NOCLONE; 
inherit F_OBSAVE; 

#define TO_STORE(x, y) (["name" : ob->query("name"), "id" : ob->query("id"), "file" : base_name(ob), "amount" : x, "sign" : y])

nosave mapping *store;
nosave mapping *data_dbase;
nosave mapping *temp_dbase;
mixed *query_store() { return store; }
mixed *query_data_dbase() { return data_dbase; }
mixed *query_temp_dbase() { return temp_dbase; }

int do_store(string arg);
int do_take(string arg);
int store_item(object me, object obj, int amount);
int store_data(object me, object ob, int sn);
int delete_data_dbase() { data_dbase = ({}); }
int delete_temp_dbase() { temp_dbase = ({}); }

int is_item_make() { return 1; } 
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
        set_name(HIY "���δ��Ͱ�" NOR, ({ "cruise ob", "cruise" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {          
                set("long", "һ�����ܱ�Ե���������ع⻷�����δ��Ͱ�����˵"
                            "���Խ����������ƵĴ棨store����ȥ,����"
                            "��ʧ��������ʲôʱ�򶼿���ȡ��take����"
                            "������ؼ��ǻ�����ʹ��������Ʒ���ε�����վ��");
                                
                set("unit", "��");
                set("no_sell", 1);
        }
        setup();
        ::restore();       
}

string extra_long()
{
        mixed ob_name_real_len;
        string msg, ob_name;

        if (! store || sizeof(store) < 1)
                return "Ŀǰû�д���κ���Ʒ�����ΰ��\n";     

        msg = HIW "\nĿǰ���ŵ���Ʒ�У�\n���  ��Ʒ                                      ����\n"
                  "����������������������������������������������������������������\n" NOR;
              
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
        msg += HIW "����������������������������������������������������������������\n" NOR;
  
        store -= ({ 0 });
        if (sizeof(data_dbase))
                data_dbase -= ({ 0 });
        if (sizeof(temp_dbase))
                temp_dbase -= ({ 0 });
        return msg;
}

void init() 
{
        add_action("do_store", ({ "store", "cun" }));
        add_action("do_take",  ({ "take",  "qu"  }));    
}

int do_take(string arg)
{
        object me, ob;
        int i, j, sn, amount, amount1;
        mapping data;
        string *ks;
                
        me = this_player();

        if (! arg || sscanf(arg, "%d %d", sn, amount) != 2) 
                return notify_fail("��ʽ�������� take ��� ���� ��ȡ����Ʒ��\n");

        if (amount < 1 || amount > 2000) 
                return notify_fail("ÿ��ȡ��Ʒ����������С��һͬʱҲ���ܴ�����ǧ��\n");
                
        if (sn < 1) return notify_fail("��Ҫȡ�ڼ�����Ʒ��\n");
        
        if (! store || sizeof(store) < 1 || sn > sizeof(store)) 
                return notify_fail("������δ��Ͱ���û�д��������Ʒ��\n");        
                
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
                                
                message_vision("$N�����δ��Ͱ���ȡ��һ" +
                                ob->query("unit") + ob->query("name") + "��\n", me);
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

        message_vision("$N�����δ��Ͱ���ȡ��" + chinese_number(amount) + 
                        ob->query("unit") + ob->query("name") + "��\n", me);
                                
        if (store[sn-1]["amount"] == 0) 
        {
                store[sn-1] = 0;
                store -= ({ 0 });
        }
        save();
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

        if (store && sizeof(store) > 500)
                return notify_fail("���δ��Ͱ����ֻ�ܴ�����ٸ����ӣ��������δ��Ͱ��Ѿ����ˡ�\n");
                
        if (arg == "all") 
        {
                inv = all_inventory(me);
                inv -= ({ this_object() });
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
                                ob2->move(me, 1);
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
                tell_object(me, "���ΰ�������" + ob->query("name") + "�������Լ����ƴ���\n");
                return 0;
        }

        if (member_array(ITEM + ".c", deep_inherit_list(ob)) == -1 &&
            member_array(COMBINED_ITEM + ".c", deep_inherit_list(ob)) == -1)
        {
                tell_object(me, "���ΰ�������" + ob->query("name") + "�������Լ����ƴ���\n");
                return 0;
        }

        if (member_array(MONEY+ ".c", deep_inherit_list(ob)) != -1)
        {
                tell_object(me, "���ΰ�������" + ob->query("name") + "��Ҫ��Ǯ�Ļ���ȥǮׯ�ɡ�\n");
                return 0;
        }
                                
        if (base_name(ob) == "/clone/misc/corpse" ||
            base_name(ob) == "/clone/misc/head" ||
            base_name(ob) == "/clone/misc/part" ||
            ob->query("task_ob") ||
            ob->query("unique") ||
            ob->query("maze_item") ||
            ob->query("id") == "pass" ||
            ob->query("id") == "key")
        {
                tell_object(me, "���ΰ�������" + ob->query("name") + "�������Լ����ƴ���\n");
                return 0;
        }

        if (ob->is_character() ||
            ob->is_item_make() ||
            ! clonep(ob)) 
        {
                tell_object(me, "���ΰ�������" + ob->query("name") + "�������Լ����ƴ���\n");
                return 0;
        }
                    
        if (sscanf(base_name(ob), "/data/%*s") &&
            ! ob->is_enchase_ob())        
        {
                tell_object(me, "���ΰ�������" + ob->query("name") + "�������Լ����ƴ���\n");
                return 0;
        }

        switch((string)ob->query("equipped")) 
        {
        case "worn":
                tell_object(me, ob->name() + "���������������ܴ�š�\n");
                return 1;
        case "wielded":
                tell_object(me, ob->name() + "�����Ƚ��װ�����ܴ�š�\n");
                return 1;
        }

        if (sizeof(all_inventory(ob))) 
        {
                tell_object(me, "�����Ȱ�" + ob->query("name") + "����Ķ������ó�����\n");
                return 1;
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
                        store += ({TO_STORE(amount, sn)});
                        store_data(me, ob, sn);
                        save();
                
                        message_vision("$N����" + chinese_number(amount) + ob->query("unit") + 
                                        ob->query("name") + "�����δ��Ͱ��\n", me);             
                        destruct(ob);
                        destruct(obj);
                        return 1;
                } 
        }
      
        for (i = 0; i < n; i++) 
        {
                if (store[i]["id"] == ob->query("id") && 
                    store[i]["name"] == ob->query("name") && 
                    store[i]["file"] == base_name(ob)) 
                {
                        store[i]["amount"] += amount;
                        
                        message_vision("$N����" + (amount > 1 ? "һ" : chinese_number(amount)) +
                                        ob->query("unit") + ob->query("name") + "�����δ��Ͱ��\n", me);                               
                        destruct(ob);
                        save();
                        return 1;
                }
        }

        store += ({TO_STORE(amount, 0)});
        save();

        message_vision("$N����" + (amount > 1 ? "һ" : chinese_number(amount)) +
                        ob->query("unit") + ob->query("name") + "�����δ��Ͱ��\n", me);           

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

int receive_summon(object me)
{
        object env;

        if ((env = environment()) && env == me)
        {
                write(name() + "����������������ٻ���ʲô����\n");
                return 1;
        }

        if (env == environment(me))
        {
                message_vision(HIG "ֻ�����ϵ�" + name() +
                               HIG "����һ����â����Ծ��$N" HIW
                               "�����У�\n\n" NOR, me);
        } else
        {
                if (env)
                {
                        if (env->is_character() && environment(env))
                                        env = environment(env);

                        message("vision", HIG "ͻȻ" + name() + HIG "����һ��"
                                HIG "��â��ʧ�ˣ�\n\n" NOR, env);

                        if (interactive(env = environment()))
                        {
                                tell_object(env, HIM + name() +
                                                 HIM "��Ȼ�����ȥ�ˣ�\n" NOR);
                        }
                }

                message_vision(HIG "һ����â������ֻ��$N"
                               HIG "���ж���һ��$n" HIG "��\n\n" NOR,
                               me, this_object());
        }

        move(me, 1);
        if (environment() != me)
                return 1;

        return 1;
}

int hide_anywhere(object me)
{
        if (me->query("jingli") < 100)
        {
                tell_object(me, "����ͼ��" + name() +
                            "��ȥ�����Ǿ������ã����Է�������������\n");
                return 0;
        }
        me->add("jingli", -100);

        message_vision(HIM "$N" HIM "����һ��" + name() +
                       HIM "����Ȼ�����ټ���\n", me);
        save();
        destruct(this_object());
        return 1;
}

int remove()
{
        save();
}

// ���ܴ������ݵĽӿں���
int receive_dbase_data(mixed data)
{
        if (! mapp(data) || sizeof(data) < 1)
                return 0;                

        if (data["store"])
                store = data["store"];
        
        if (data["data_dbase"])
                data_dbase = data["data_dbase"];
        
        if (data["temp_dbase"])
                temp_dbase = data["temp_dbase"];
                
        return 1;
}

// ���б������ݵĽӿں���
mixed save_dbase_data()
{
        mapping data;
        object  user;

        data = ([ ]);
  
        if (! store)
                store = ({});      
        if (! data_dbase)
                data_dbase = ({}); 
        if (! temp_dbase)
                temp_dbase = ({}); 
                                
        if (sizeof(store) > 0)
                data += ([ "store" : store ]);

        if (sizeof(data_dbase) > 0)
                data += ([ "data_dbase" : data_dbase ]);
                
        if (sizeof(temp_dbase) > 0)
                data += ([ "temp_dbase" : temp_dbase ]);

        return data;
}
