// dealer.c ����
// Written by Lonely

#pragma save_binary

#include <ansi.h>
#include <command.h>
#include <dbase.h>
#include <name.h>
#include <config.h>

class goods {
        string name;
        string id;
        string type;
        string file;
        string unit;
        int amount;
        int value;
        int number;
}

nosave int uptime;
nosave int no_trade = 0;
nosave int load_goods = 0;

protected class goods *all_goods = ({});
protected void init_goods();
protected varargs int add_good_all(string file, int price, int amount);

/*
void setup()
{
        init_goods();
        ::setup();
        if (! uptime)
                uptime = time();
}

void init()
{
	add_action("do_buy", ({ "mai", "buy" }) );
	add_action("do_list", "list");
}
*/

protected void init_goods()
{
        string *gds, name;
        mixed items;
        int price;
        //int i, number;
        int i;

        no_trade = 1;
        all_goods = ({});

        items = query("vendor_goods");        
        if (! arrayp(items) && ! mapp(items) || ! sizeof(items))
        {
                no_trade = 0;
                load_goods = 1;                
                return;
        }

        gds = mapp(items) ? keys(items) : items;
        for (i = 0; i < sizeof(gds); i++)
        {
                name = gds[i];
                price = mapp(items) && items[gds[i]] > 0 ? items[gds[i]] : 0;
                add_good_all(name, price);
        }

        no_trade = 0;
        load_goods = 1;
}

protected varargs int add_good_all(string file, int price, int amount)
{
        object ob;
        class goods item;
        string type;

        if (! stringp(file))
                return 0;

        if (amount > 0 && sizeof(all_goods))
        {
                foreach(item in all_goods)
                {
                        if (item->file != file)
                                continue;

                        item->amount = amount;
                        return 1;
                }
        }

        call_other(file, "???");
        if (! objectp(find_object(file)))
        {
                log_file("log", sprintf("No found vendor good:%s\n", file));
                return 0;
        }

        /*
        ob = new(file);
        if (! ob)
        {
                log_file("log", sprintf("No found vendor good:%s\n", file));
                return 0;
        }
        */
        ob = find_object(file);

        if (ob->is_weapon_ob())
                type = "����";
        else if (ob->is_armor_ob())
                type = "����";
        else if (ob->is_liquid())
                type = "����";
        else if (ob->is_food())
                type = "ʳ��";
        else if (ob->is_container())
                type = "����";
        else if (ob->is_book())
                type = "�鼮";
        else
                type = "����";


        item = new(class goods);

        item->name = ob->query("name");
        item->id = ob->query("id");
        item->type = type;
        item->file = file;
        item->unit = ob->query("base_unit") ? ob->query("base_unit")
                                            : ob->query("unit");
        item->amount =  amount ? amount : -1;
        item->value = price ? price :
                        (ob->query("base_value") ? ob->query("base_value"):
                                                   ob->query("value"));
        item->number = sizeof(all_goods) + 1;

        all_goods += ({ item });
        // destruct(ob);
        return 1;
}

string is_vendor_good(string arg)
{
        //mixed items;
        //object ob;
        int i, n;

        n = sizeof(all_goods);
        if (! n) return "";

        for(i=0;i<n;i++)
        {
                if ((all_goods[i]->file)->id(arg)
                ||  all_goods[i]->file == arg
                ||  filter_color(all_goods[i]->name) == arg
                ||  sprintf("%d", all_goods[i]->number) == arg)
                {
                        if (all_goods[i]->amount != -1)
                                return "";

                        return all_goods[i]->file;
                }
        }

        return "";
}

void add_carry_good()
{
        mixed obs;
        int i, j;
        int amount;
        
        if (obs = all_inventory())
        {
                obs = unique_array(obs, (: base_name($1) :));

                for (i = 0; i < sizeof(obs); i++)
                {
                        for (j = 0; j < sizeof(obs[i]);  j++)
                        {
                                if (obs[i][j]->query("equipped") ||
                                    obs[i][j]->query("money_id") ||
                                    obs[i][j]->is_character())
                                        continue;

                                if (is_vendor_good(base_name(obs[i][j])) != "")
                                        continue;

                                amount = obs[i][j]->query_amount() ? obs[i][j]->query_amount()
                                                                   : sizeof(obs[i]);
                                add_good_all(base_name(obs[i][j]), 0, amount);
                        }
                }
        }
}
        
varargs int do_list(string arg)
{
        string output, desc;
        //int amount;
        class goods item;
        object me, ob;
       // mixed obs; 
       // int i, j, number;
        
        me = this_player();

        if (no_trade)
                return notify_fail("���������̿⣬���һ��������\n");

        if (! wizardp(me) && me->query_condition("killer"))
                return notify_fail(CYN "���̲���ɱ�˷������⣡\n" NOR);

        if (me->is_busy())
        {
                write("������æ���ء�\n");
                return 1;
        }

        // ����ͬ������һ������ dealer �������
        if (arg && ! id(arg) &&
            arg != query("name"))
                return 0;
                
        if (! load_goods)
        {
                init_goods();
                if (! uptime)
                        uptime = time();
        }       
        
        add_carry_good();
        if (! sizeof(all_goods))
        {
                write(sprintf("Ŀǰ%sû�п������Ķ�����\n", query("name")));
                return 1;
        }

        output = this_object()->name() + "Ŀǰ����������Ʒ��\n";
        /*
        output += sprintf("%5s%-30s%-10s%-10s\n","�� ��", "    ��  Ʒ","  ��  ��","       ��  ��");
        output += "----------------------------------------------------------------\n";
        */
        foreach (item in all_goods)
        {
                if (item->amount > 0)
                {
                        ob = present(item->id, this_object());
                        if (! ob)
                                item->amount = 0;
                }
                if (item->amount < 0)
                        desc = "������Ӧ";
                else if (item->amount == 0)
                        desc = "��ʱȱ��";
                else if (item->amount < 11)
                        desc = sprintf("��ʣ%2d%2s", item->amount, item->unit);
                else if (item->amount < 31)
                        desc = sprintf("��ʣ%2d%2s", item->amount, item->unit);
                else
                        desc = "��Դ����";

                output += sprintf("(%3d)%" + sprintf("%d", (30 + color_len(item->name))) +
                                  "-s��ÿ%s%s" CYN "(�ֻ�%s)\n" NOR,
                                  item->number,
                                  item->name + "(" + item->id + ")",
                                  item->unit,
                                  MONEY_D->price_str(item->value), desc);
        }
        
        write(output);
        return 1;
}

int do_buy(string arg)
{
        mapping room_obmap; 
        string  bunch;
        object *obs;
        object  ob;
        object  room;
        object  me;
        mixed   value;
        int     amount;
        int     val_factor;
        int     i, j, n;
        int     much;
        string  my_id;
        string  start_room;
        
        if (! arg)
                return notify_fail("������ʲô��\n");

        if ((me = this_player())->is_busy())
        {
                write("������æ���أ�\n");
                return 1;
        }

        if (no_trade)
                return notify_fail("���������̿⣬���һ��������\n");

        if (query_temp("busy"))
        {
                write(CYN + name() + "���ͷ�������û��������"
                      "����æ��ô����\n" NOR);
                return 1;
        }
        
        if (sscanf(arg,"%s from %s", arg, my_id) == 2)
        {
                if (! id(my_id) && my_id != query("name"))
                        return 0;
        }                

        if (! query("carried_items"))
        {
                if (stringp(start_room = query("startroom")) &&
                    (room = find_object(start_room)) != environment())
                {
                        // I am not in start room.
                        message_vision("$N���һ���������ã�����ô�ܵ�������ˣ���\n"
                                       "˵��ͷҲ���صļ���ææ�������ˡ�\n", this_object());
                        if (! objectp(room) ||
                            ! mapp(room_obmap = room->query_temp("objects")) ||
                            member_array(this_object(), values(room_obmap)) == -1)
                        {
                                destruct(this_object());
                        } else
                                this_object()->move(room);
                        return 1;
                }
        }

        if (sizeof(filter_array(all_inventory(me), 
                                (: ! $1->query("equipped") :))) >= MAX_ITEM_CARRIED)
        {
                write("�����ϵĶ���̫���ˣ��ȴ���һ���������ɡ�\n");
                return 1;
        }

        if (sscanf(arg, "%d %s", amount, arg) != 2)
                // not indicate the amount of the items
                amount = 1;

        if (amount < 1)
        {
                write(CYN + name() + "�ɻ���ʵ�����û���������򷨣��㵽�����򼸸���λ�أ���\n" NOR);
                return 1;
        }
        
        if (amount > 100)
        {
                write(CYN + name() + "æ��������������һ�������һ�ٸ���λ����\n" NOR);
                return 1;
        }

        if (! load_goods)
        {
                init_goods();
                if (! uptime)
                        uptime = time();
        }
        
        add_carry_good();
        n = sizeof(all_goods);
        if (! n)
        {
                write(sprintf("Ŀǰ%sû�п������Ķ�����\n", query("name")));
                return 1;
        }
        
        val_factor = 10;
        for(i = 0; i < n; i++)
        {
                if ((all_goods[i]->file)->id(arg)
                ||  filter_color(all_goods[i]->name) == arg
                ||  sprintf("%d", all_goods[i]->number) == arg)
                {
                        if (! (all_goods[i]->amount))
                        {
                                command(sprintf("say �Բ���Ŀǰ��%s" CYN "ȱ��������һ��ʱ��������",
                                        all_goods[i]->name));
                                return 1;
                        }

                        if (all_goods[i]->amount > 0)
                        {
                                val_factor = 12;
                                ob = present(all_goods[i]->id, this_object());
                                if (! ob)
                                {
                                        all_goods[i]->amount = 0;
                                        command(sprintf("say �Բ���Ŀǰ��%s" CYN "��ʧ������һ��ʱ��������",
                                                all_goods[i]->name));
                                        return 1;
                                }
                                if (amount > all_goods[i]->amount)
                                        amount = all_goods[i]->amount;
                        }
                        break;
                }
        }

        if (i >= n)
	{
		write("������ʲô��\n");
		return 1;
	}
        
        value = count_mul(amount, all_goods[i]->value);
        value = count_div(count_mul(value, val_factor), 10);
        
        /*
        if (value > 1000000000 || value * val_factor / val_factor != value)
        {
                write(CYN + name() + CYN "��ʧɫ������ô��һ�����⣿��"
                      "�ɲ�������\n" NOR);
                return 1;
        }
        */
        
        if (me->query_skill("higgling", 1) > 99)
        {
                if (me->query_skill("higgling", 1) > 399)
                        value = count_div(count_mul(value, 7), 10);
                else
                if (me->query_skill("higgling", 1) > 199)
                        value = count_div(count_mul(value, 8), 10);
                else
                if (me->query_skill("higgling", 1) > 99)
                        value = count_div(count_mul(value, 9), 10);
        } else
        if (stringp(bunch = me->query("bunch/bunch_name")) &&
            bunch == (string)this_object()->query("bunch/bunch_name"))
                value = count_div(count_mul(value, 8), 10);
        // ���˵����ҲŲɹ�ʱ���ܰ����Ż�
        else
        if (SHOP_D->is_owner(me->query("id")))
                value = count_div(count_mul(value, 8), 10);

        if (count_le(value, 0))
                value = 1;

        switch (MONEY_D->player_pay(me, value))
        {
        case 0:
                write(CYN + name() + "��Ц��������⵰��һ�ߴ���ȥ����\n" NOR);
                return 1;
        case 2:
                write(CYN + name() + "��ü������������û����"
                      "Ǯ������Ʊ�ҿ��Ҳ�������\n" NOR);
                return 1;
        case 3:
                write(CYN + name() + "��ü������������û����"
                      "Ǯ������ʯ�ҿ��Ҳ�������\n" NOR);
                return 1;
        default:
                set_temp("busy", 1);

                if (me->query_skill("higgling", 1) > 99 || SHOP_D->is_owner(me->query("id")))
                {
                        switch (random(3))
                        {
                        case 0:
                                command("say ��Ȼ��Ҷ����������ģ��͸������۰ɡ�");
                                break;
                        case 1:
                                command("say Ҳ�գ���Ȼ�Ǵ��ϰ��ˣ��ͱ��˵�������ɡ�");
                                break;
                        default:
                                command("say �Ǻǡ����ϰ������ɹ�ô����ô�͸������۰ɡ�");
                                break;
                        }
                }  else
                if (stringp(bunch = me->query("bunch/bunch_name")) &&
                    bunch == (string)this_object()->query("bunch/bunch_name"))
                        command("say ��Ȼ��Ҷ���ͬ���ֵܣ��͸������۰ɡ�");

                much = atoi(count_div(value, 5));
                if (much <= 0) much = 1;

                if (stringp(bunch == (string)this_object()->query("bunch/bunch_name")) &&
                    bunch != me->query("bunch/bunch_name"))
                        BUNCH_D->add_bunch_info(bunch, "npc_money", much);

                if (ob)
                {
                        object old_ob;
                        if (ob->query_amount())
                        {
                                ob = new(base_name(old_ob = ob));
                                ob->set_amount(amount);
                                old_ob->add_amount(-amount);
                                ob->move(me, 1);
                        } else
                        {
                                obs = all_inventory();
                                obs = filter_array(obs, (: base_name($1) == base_name($(ob)) :));
                                n = 0;
                                for (j = 0; j < sizeof(obs); j++)
                                {
                                        n++;
                                        if (n > amount)
                                                break;

                                        obs[j]->move(me, 1);
                                }
                        }
                } else
                {
                        ob = new(all_goods[i]->file);
                        if (! ob)
                        {
                                write("����������⣬������ʦ�����\n");
                                log_file("log", sprintf("No found vendor good:%s\n", all_goods[i]->file));
                                return 1;
                        }
                        
                        if (ob->query_amount())
                        {
                                ob->set_amount(amount);
                                ob->move(me, 1);
                       
                        } else
                        {
                                ob->move(me, 1);
                                for (j = 0; j < amount-1; j++)
                                {
                                        ob = new(all_goods[i]->file);                                       
                                        ob->move(me, 1);
                                }
	                }
                                
                }

                all_goods[i]->amount -= amount;                
                message_vision(sprintf("$N��$n����������%s%s%s%s��\n",
                        all_goods[i]->amount == 0 ? "���" : "",
                        chinese_number(amount),
                        all_goods[i]->unit,
                        all_goods[i]->name), me, this_object());
        }

        remove_call_out("enough_rest");
        call_out("enough_rest", 1);

        return 1;
}

void destruct_it(object ob)
{
        if (! ob || environment(ob))
                return;
        destruct(ob);
}

void enough_rest()
{
        delete_temp("busy");
}

int do_look(string arg)
{
        string who;
        object ob, me;
        int i, n;

        if ((me = this_player())->is_busy())
        {
                write("������æ���أ�\n");
                return 1;
        }

        if (! arg || arg == "")
        {
                write("���뿴ʲô��\n");
                return 1;
        }

        // ����ͬ������һ������ dealer �������
        if (sscanf(arg,"%s from %s", arg, who) == 2)
        {
                if (! id(who) && who != query("name"))
                        return 0;
        }

        if (! load_goods)
        {
                init_goods();
                if (! uptime)
                        uptime = time();
        }
        
        add_carry_good();
        n = sizeof(all_goods);
        if (! n)
        {
                write(sprintf("Ŀǰ%sû�п������Ķ�����\n", query("name")));
                return 1;
        }

        for (i = 0; i < n; i++)
        {
                if (all_goods[i]->amount > 0)
                {
                        ob = present(all_goods[i]->id, this_object());
                        if (! ob)
                                all_goods[i]->amount = 0;
                }
                
                if (all_goods[i]->amount == 0)
                        continue;
                        
                if((all_goods[i]->file)->id(arg)
                || filter_color(all_goods[i]->name) == arg
                || sprintf("%d",all_goods[i]->number) == arg)
                {
                        ob = get_object(all_goods[i]->file);
                        LOOK_CMD->look_item(me, ob);
                        // destruct(ob);
                        return 1;
                }
        }
        
        if (i >= n)
        {
                write("���뿴ʲô��\n");
                return 1;
        }
}

int do_value(string arg)
{
        object ob;
        int value;
        mixed ns;

        if (! arg || ! (ob = present(arg, this_player())))
        {
                return notify_fail("��Ҫ��ʲô�ļۣ�\n");
        }
        
        if (ob->query("money_id"))
        {
                write(CYN + name() + "������û�ù�Ǯ����\n" NOR);
                return 1;
        }

        if (ob->is_character())
        {
                write(CYN + name() + "��������Ҳ�������ۣ�\n" NOR);
                return 1;
        }

        if (ob->query_amount())
                value = ob->query("base_value");
        else
                value = ob->query("value");

        if (ob->query("consistence"))
                value = value * ob->query("consistence") / 100;

        if (value < 1)
                write(CYN + name() + "����" + ob->query("name") +
                      CYN "һ�Ĳ�ֵ��\n" NOR);
        else
        if (ob->query("no_drop") || (ns = ob->query("no_sell")))
        {
                if (stringp(ns))
                {
                        write(CYN + name() + "����" + ns + "\n" NOR);
                        return 1;
                }
                write(CYN + name() + "�������ⶫ���е�Ź֣��ҿɲ��ù��ۡ���\n" NOR);
        } else
                write(CYN + name() + "������" + ob->query("name") + CYN "ֵ" +
                        MONEY_D->price_str(value * 50 / 100) + "����\n" NOR);
        return 1;
}

int do_sell(string arg)
{
        object me;
        object ob;
        object nob;
        string my_id;
        int amount;
        int value;
        int res;
        int max_count;
        mixed ns;

        if (! arg)
                return notify_fail("��Ҫ��ʲô��\n");

        if (sscanf(arg,"%s to %s", arg, my_id) == 2)
        {
                if (! id(my_id) && my_id != query("name"))
                        return 0;
        }        

        if (sscanf(arg, "%d %s", amount, arg) != 2)
                // not indicate the amount of the goods
                amount = 1;

        if (amount < 1) 
        {
                write(CYN + name() + "�ɻ���ʵ�����û���������򷨣��㵽�����򼸼��أ���\n" NOR);
                return 1; 
        }
        
        me = this_player();
        if (! (ob = present(arg, me)))
        {
                write("������û�����ֶ�������\n");
                return 1;
        }

        max_count = ob->query_amount();
        if (! max_count)
        {
                // not combined object
                if (amount > 1)
                {
                        write(ob->name() + "���ֶ������ܲ�������\n");
                        return 1;
                }
                max_count = 1;
        } else
        {
                // is combined object
                if (amount > max_count)
                {
                        write("������û����ô��" + ob->name() + "��\n");
                        return 1;
                }
        }

        if (ob->query("money_id"))
        {
                write(CYN + name() + "������������������������Ǯ��������\n" NOR);
                return 1;
        }

        if (ob->is_character())
        {
                write(CYN + name() + "�������ߣ���������������"
                      "�⣬��������Щ����\n" NOR);
                return 1;
        }

        if (ob->query("unique") || ob->query("no_pawn") || ob->query("replica_ob"))
        {
                write(CYN + name() + "ҡҡͷ�����������ֶ�����"
                      "��ʶ��������Ҫ����\n" NOR);
                return 1;
        }

        if (ob->query("no_drop") ||
            (ns = ob->query("no_sell")))
        {
                if (stringp(ns))
                {
                        command("say " + ns);
                        return 1;
                }
                write(CYN + name() + "ҡҡͷ�����������ֶ�����"
                      "��ʶ��������Ҫ����\n" NOR);
                return 1;
        }

        if (is_vendor_good(base_name(ob)) != "") 
        {
                write(CYN + name() + "Ц��������������ò��ã���\n" NOR);
                return 1;
        }

        if (ob->query("food_supply"))
        {
                write(CYN + name() + "��м�������ٺ٣�ʣ��ʣ������"
                      "���Լ��ðɡ���\n" NOR);
                return 1;
        }
        
        if (ob->query("shaolin"))
        {
                write(CYN + name() + "��������С�ĵ��Ӻ�С����"
                      "�����������������\n" NOR); 
                return 1;
        }

        if (ob->query("mingjiao"))
        {
                write(CYN + name() + "æҡͷ������С��ֻ��һ���Դ�����"
                      "������ħ�̵Ķ�������\n" NOR);
                return 1;
        }

        if (ob->query("consistence"))
                value = value * ob->query("consistence") / 100;

        if (max_count > 1)
        {
                if (ob->query("base_value") * amount / amount != ob->query("base_value"))
                {
                        write(CYN + name() + CYN "��ʧɫ������ô��һ�����⣿��"
                              "�ɲ�������\n" NOR);
                        return 1;
                }
                value = ob->query("base_value") * amount;
        }
        else
                value = ob->query("value");

        if (value < 2)
                write(CYN + name() + "����һ�ӣ�����" + ob->query("name") +
                      CYN "һ�Ĳ�ֵ��\n" NOR);
        else
	{
                if (max_count == amount)
                        res = ob->move(this_object());
                else
                {
                        nob = new(base_name(ob));
                        nob->set_amount(amount);
                        if (res = nob->move(this_object()))
                                ob->add_amount(-amount);
                        else
                                destruct(nob);
                }

                if (res)
                {
                        message_vision("$N������һ" + ob->query("unit") +
                                       ob->query("name") + "��$n��\n",
				       this_player(), this_object());
                        MONEY_D->pay_player(this_player(), (value / 2));
			ob->sold();
                } else
                        write(CYN + name() + "ҡҡͷ���������Բ���"
                              "�����ڲ��ջ��ˡ���\n" NOR);
        }
        return 1;
}

int do_pawn(string arg)
{
        object me;
        object ob;
       // object nob;
        string my_id;
        int amount;
        int value;
       // int res;
        int max_count;
	mixed max_pawn_goods_num;
	int have_pawn_num;
	mapping all_pawn;
        mixed ns;

        if (! arg)
                return notify_fail("��Ҫ��ʲô��\n");

	if (sscanf(arg, "%s to %s", arg, my_id) == 2 && ! id(my_id))
		return 0;

        if (sscanf(arg, "%d %s", amount, arg) != 2)
                // not indicate the amount of the goods
                amount = 1;

        if (amount < 1) 
        {
                write(CYN + name() + "�ɻ���ʵ�����û�������ֵ������㵽���뵱�����أ���\n" NOR);
                return 1; 
        }
        
        me = this_player();
        if (! (ob = present(arg, me)))
        {
                write("������û�����ֶ�������\n");
                return 1;
        }

        max_count = ob->query_amount();
        if (! max_count)
        {
                // not combined object
                if (amount > 1)
                {
                        write(ob->name() + "���ֶ������ܲ�������\n");
                        return 1;
                }
                max_count = 1;
        } else
        {
                // is combined object
                if (amount > max_count)
                {
                        write("������û����ô��" + ob->name() + "��\n");
                        return 1;
                }
        }

	max_pawn_goods_num = count_div(me->query("combat_exp"), 500000);
	sscanf(max_pawn_goods_num, "%d", max_pawn_goods_num);

        // if (max_pawn_goods_num > 0)
		max_pawn_goods_num += 4;

	if (max_pawn_goods_num > 20)
		max_pawn_goods_num = 20;

	have_pawn_num = (int)me->query("pawn_goods_num");
	if (amount + have_pawn_num > max_pawn_goods_num)
	{
		write(CYN + name() + "ҡͷ�����������ڵĵ�λ�����ֻ���ڱ��Ŵ�" + 
                            chinese_number(max_pawn_goods_num) + "����Ʒ��" + 
                            (have_pawn_num?"���Ѿ�����" + chinese_number(have_pawn_num) + "����Ʒ��":"") +
                            "�������ջذɣ�\n" NOR);
		return 1;
	}

        if (ob->is_no_clone() || ob->query("unique"))
	{
                write(CYN + name() + "ҡҡͷ�����������С�Ų����գ�\n" NOR);
		return 1;
	}

        if (ob->is_item_make())
	{
		write(CYN + name() + "ҡҡͷ��������Լ��������Ʒ������������\n" NOR);
		return 1;
	}

        if (ob->query("money_id"))
        {
                write(CYN + name() + "�����������������뵱��Ǯ������\n" NOR);
                return 1;
        }

        if (ob->is_character())
        {
                write(CYN + name() + "�����ߣ���������������"
                      "�⣬�������˿ڣ�\n" NOR);
                return 1;
        }

        if (ob->query("no_drop") ||
            (ns = ob->query("no_sell")))
        {
                if (stringp(ns))
                {
                        command("say " + ns);
                        return 1;
                }
                write(CYN + name() + "ҡҡͷ���������ֶ�����"
                      "��ʶ��������Ҫ��\n" NOR);
                return 1;
        }

	if (ob->query("only_do_effect"))
	{
		write (CYN + name() + "��Ц��������ҩƷ����֪���Ƿ��Ѿ����ʣ�С��Ҳû�������棬���ջذɣ�\n" NOR);
		return 1;
	}

        if (ob->query("food_supply"))
        {
                write(CYN + name() + "��м�����ٺ٣�ʣ��ʣ������"
                      "���Լ��ðɡ�\n" NOR);
                return 1;
        }
        
        if (ob->query("shaolin"))
        {
                write(CYN + name() + "������С�ĵ��Ӻ�С����"
                      "���������������\n" NOR); 
                return 1;
        }

        if (ob->query("mingjiao"))
        {
                write(CYN + name() + "æҡͷ����С��ֻ��һ���Դ�����"
                      "������ħ�̵Ķ�����\n" NOR);
                return 1;
        }

        if (max_count > 1)
                value = ob->query("base_value") * amount;
        else
                value = ob->query("value");
        if (value < 2)
                write(CYN + name() + "����һ�ӣ�����" + ob->query("name") +
                      CYN "һ�Ĳ�ֵ��\n" NOR);
        else
        {
                message_vision("$N������һ" + ob->query("unit") +
                               ob->query("name") + "��$n��\n",
                               this_player(), this_object());
                MONEY_D->pay_player(this_player(), value * 30 / 100);

                all_pawn = me->query("pawn_goods");
                if (! all_pawn) all_pawn = ([ ]);

                all_pawn[base_name(ob)] += amount;

                me->set("pawn_goods", all_pawn);
                me->add("pawn_goods_num", amount);
                                        
                if (max_count == amount) 
                        destruct(ob);                     
                else ob->add_amount(-amount);
        }
        return 1;
}

int do_redeemp (string target) 
// ����Ժ����ң��С�Ů�� 
{ 
        object me,ob,dest; 
     
        me=this_player(); 
        ob=this_object(); 
        if(!target || target=="") 
                return notify_fail(ob->query("name")+"������Ķ��������ʵ�����Ҫ��ʲô�ˣ�\n");
 
        if(!objectp(dest=find_player(target))) 
        //find_player() - ������Ѱ��һ����� 
                return notify_fail(HIR+"���("+target+")Ŀǰ�ƺ��������ϣ�\n"+NOR);
 
        if( !dest->query("selled")) 
        // �Ƿ�Ҫ��condition������ʱ�䳤��û�����꣬���Զ�����Ů�����мˣ� 
                return notify_fail(ob->query("name")+"��������ɱ����ݺ��ˣ�����ô��Ƿ���Ѻ����أ�\n");
 
        switch (MONEY_D->player_pay(me, dest->query("per") * 700)) 
        // switch (me->pay_money(dest->query("per") * 700, 0)) 
        { 
                case 0: 
                        return notify_fail("ûǮ�������ˣ��Ų����Ұ�������ˣ�\n"); 
                case 2: 
                        return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n"); 
                default: 
                        message_vision(HIG+"$N��$n���������"+dest->query("name")+"��\n"+NOR, me, ob); 
                        dest->move(environment(ob)); 
                        dest->set("startroom",base_name(environment(ob))); 
                        dest->delete("selled"); 
                        message("vision", HIY+"ֻ����ವ�һ����һ���������˵ļһ���컨���ϵ���������\n"+NOR, 
                                environment(dest), dest); 
                        tell_object(dest, "�㱻"+HIC+me->query("name")+NOR+"���˳�����\n"); 
        } 
        return 1; 
} 

int do_redeem(string arg) 
{
        mixed  goods;
       // object *obs;
	object me;
        object ob;
        int i;
        int amount;
        int value;
        mapping count;
        mapping price;
        mapping unit;
	mapping all_pawn;
        string short_name;
        string prefix;
        string *dk;
        string ob_file;
	string my_id;
        string msg;
        string *gks;

	me = this_player();

	if (!arg)
	{
	        count   = ([]);
        	unit    = ([]);
        	price   = ([]);
    
        	goods = me->query("pawn_goods");

		if (!mapp(goods) || !sizeof(goods))
			return notify_fail(name() + "���˷��ʲ������㲢û���ڱ��ŵ��κ���Ʒ��\n");

                gks = keys(goods);

                for (i = 0; i < sizeof(gks); i++)
                {
                        object gob;
                        call_other(gks[i], "???");
                        if (! objectp(find_object(gks[i])))
                        {
                                log_file("log", sprintf("No found pawn good:%s\n", gks[i]));
                                continue;
                        }
                        gob = find_object(gks[i]);

                        short_name = gob->name(1) + "(" + gob->query("id") + ")";
                        if (gob->query("base_unit"))
                                prefix = "base_";
                        else
                                prefix = "";
	                unit  += ([ short_name : gob->query(prefix + "unit") ]);
                        price += ([ short_name : gob->query(prefix + "value") ]);
	                count += ([ short_name : goods[gks[i]] ]);
                }

	        msg = name() + "���˷��ʲ��������ڱ���Ŀǰ�䵱��������Ʒ��\n";
	        dk = sort_array(keys(unit), 1);
	        for (i = 0; i < sizeof(dk); i++)
	        {
	                int p;
	                p = price[dk[i]];
	                msg += sprintf("%" + sprintf("%d", (30 + color_len(dk[i]))) +
                               "-s��ÿ%s���%s" CYN "(����%s)\n" NOR, dk[i], unit[dk[i]], MONEY_D->price_str(p),
                               chinese_number(count[dk[i]]) + unit[dk[i]]);
        	}
		msg += name() + "�ٺ�һЦ���ܹ�" + chinese_number((int)me->query("pawn_goods_num")) + "����Ʒ��\n";
	        write(msg);
	        return 1;
	} else
	{
              if(me->is_busy())
	                return notify_fail("ʲô�¶��õ���æ����˵�ɣ�\n");

		if (sscanf(arg, "%s from %s", arg, my_id) == 2 && ! id(my_id))
			return 0;

	        if (sizeof(all_inventory(me)) >= MAX_ITEM_CARRIED)
	        {
        	        write("�����ϵĶ���̫���ˣ��ȴ���һ���������ɡ�\n");
                	return 1;
        	}

	        if (sscanf(arg, "%d %s", amount, arg) != 2)
        	        // not indicate the amount of the goods
                	amount = 1;

                if (amount < 1) 
                {
                        write(CYN + name() + "�ɻ���ʵ�����û���������귨���㵽�����꼸���أ���\n" NOR);
                        return 1; 
                }
                
	        if (amount > 10)
        	{
                	write(CYN + name() + "æ������������һ�������ʮ����\n" NOR);
                	return 1;
        	}

	        goods = me->query("pawn_goods");
	        if (!goods) goods = ([]);

	        gks = keys(goods);
	        if (arrayp(gks))
	                for (i = 0; i < sizeof(gks); i++) 
        	        {
                	        if (gks[i]->id(arg)) 
                        	        ob_file = gks[i];
                        	else if (filter_color(gks[i]->name(1)) == arg) 
                                	ob_file = gks[i];
                	}

	        if (!ob_file)
        	{
        	        write(name() + "ҡͷ�����㲢û���ڱ��ŵ��������\n");
	                return 1;
	        }

		if (amount > goods[ob_file])
		{
        	        write(name() + "ҡͷ�������ڱ��ŵ���" + arg + "һ����" + chinese_number(goods[ob_file]) + "����\n");
	                return 1;
		}

                ob = new(ob_file);

	        if (amount > 1 && ! ob->query_amount())
        	{
                	write(ob->name() + "ֻ��һ" + ob->query("unit") +
                      		"һ" + ob->query("unit") + "����\n");
                	return 1;
        	}

                if (amount > 1) ob->set_amount(amount);

                call_out("destruct_it", 0, ob);

		if (ob->query("money_id"))
        	{
			write(CYN + name() + "��Ц������������Ҫ��"
                      		"Ǯ������˼��\n" NOR);
                	return 1;
        	}

	        if (query_temp("busy"))
        	{
                	write(CYN + name() + "���ͷ�����û��������"
                      		"����æ��ô��\n" NOR);
                	return 1;
        	}

	        value = ob->query("value");


	        switch (MONEY_D->player_pay(me, value))
        	{
        	case 0:
                	write(CYN + name() + "��Ц������⵰��һ�ߴ���ȥ��\n" NOR);
                	return 1;
        	case 2:
                	write(CYN + name() + "��ü����������û����"
                      		"Ǯ������Ʊ�ҿ��Ҳ�����\n" NOR);
                	return 1;
        	default:
                	set_temp("busy", 1);
	                if (ob->query_amount())
                        	message_vision("$N��$n���������" + ob->short() + "��\n",
			               this_player(), this_object());
                	else
	                        message_vision("$N��$n���������һ" + ob->query("unit") + 
                	               ob->query("name") + "��\n",
			               this_player(), this_object());
	                ob->move(this_player(), 1);
		        all_pawn = me->query("pawn_goods");
		        all_pawn[base_name(ob)] -= amount;
	                if (all_pawn[base_name(ob)] <= 0) 
        	        {
                	        map_delete(all_pawn,base_name(ob));
                	}
		        me->set("pawn_goods",all_pawn);
		        me->add("pawn_goods_num",-amount);
        	}
	        this_player()->start_busy(1);
	        remove_call_out("enough_rest");
        	call_out("enough_rest", 1 + random(3));

	        return 1;
	}
}       

int do_check(string arg) { return do_redeem(0); }

void reset()
{
        int i, t;
        object *obs;

        t = time();
        if (! uptime)
                uptime = t;

        if (t - uptime >= 3600)
        {
                uptime = t;
                init_goods();
        }

        obs = all_inventory();
        for (i = 0; i < sizeof(obs); i++)
                if (i >= 100 || obs[i]->query_weight() >= 1000000)
                        destruct(obs[i]);
}
