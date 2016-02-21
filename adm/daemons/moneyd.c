// moneyd.c  Ǯ�Ĺ���

// by Xiang@XKX (95/12/22)
// Update by Doing for Hell
// Update by Lonely for NiTan3

#pragma optimize
#pragma save_binary

string money_str(mixed amount)
{
        // returns a chinese string of `amount` of money
        string output;

#ifdef LONELY_IMPROVED
        if (count_ge(amount, 10000)) {
                output = chinese_number(atoi(count_div(amount, 10000))) + "���ƽ�";
                amount = count_sub(amount, count_mul(count_div(amount, 10000), 10000));
                amount = atoi(amount);
        }
        else
                output = "";  
        
        if (stringp(amount))
                amount = atoi(amount);
#else
        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "���ƽ�";
                amount %= 10000;
        }
        else
                output = "";
#endif
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "������";
                amount %= 100;
        }
        if (amount)
                return output + chinese_number(amount) + "��ͭǮ";
        return output;
}

string price_str(int amount)
{
        // returns a chinese string of `amount` of money
        string output;

        if (amount < 1)
                amount = 1;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "���ƽ�";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                if (output != "")
                        output += "��" + chinese_number(amount / 100) + "������";
                else
                        output = chinese_number(amount / 100) + "������";
                amount %= 100;
        }
        if (amount)
                if (output != "")
                        return output + "��" + chinese_number(amount) + "��ͭ��";
                else
                        return chinese_number(amount) + "��ͭ��";
        return output;
}

void pay_player(object who, mixed amount)
{
        int v;
        object ob;

        seteuid(getuid());
        if (intp(amount) && amount < 1)
                amount = 1;

        if (stringp(amount) && count_lt(amount, 0))
                amount = 1;

        /*
        if (v = atoi(count_div(amount, 10000000)))
        {
                ob = new(SAND_OB);
                ob->set_amount(v);
                ob->move(who, 1);
                amount = atoi(count_sub(amount, count_mul(v, 10000000)));
        }

        if (v = atoi(count_div(amount, 100000)))
        {
                ob = new(CASH_OB);
                ob->set_amount(v);
                ob->move(who, 1);
                amount = atoi(count_sub(amount, count_mul(v, 100000)));
        }

        */
        if (v = atoi(count_div(amount, 10000)))
        {
                ob = new(GOLD_OB);
                ob->set_amount(v);
                ob->move(who, 1);
                amount = atoi(count_sub(amount, count_mul(v, 10000)));
        }

        if (v = atoi(count_div(amount, 100)))
        {
                ob = new(SILVER_OB);
                ob->set_amount(v);
                ob->move(who, 1);
                amount = atoi(count_sub(amount, count_mul(v, 100)));
        }
        if (v = atoi(count_div(amount, 1)))
        {
                ob = new(COIN_OB);
                ob->set_amount(v);
                ob->move(who, 1);
        }
}

int player_pay(object who, mixed amount)
{
        object z_ob, t_ob, g_ob, s_ob, c_ob;
        int zc, tc, gc, sc, cc;
        mixed v, left, value;

        seteuid(getuid());

        if (intp(amount) && amount < 0)
                return 0;

        if (stringp(amount) && count_lt(amount, 0))
                return 0;

        if (z_ob = present("thousand-gold", who))
                zc = z_ob->query_amount();
        else
                zc = 0;
        if (t_ob = present("cash_money", who))
                tc = t_ob->query_amount();
        else
                tc = 0;
        if (g_ob = present("gold_money", who))
                gc = g_ob->query_amount();
        else
                gc = 0;
        if (s_ob = present("silver_money", who))
                sc = s_ob->query_amount();
        else
                sc = 0;
        if (c_ob = present("coin_money", who))
                cc = c_ob->query_amount();
        else
                cc = 0;
        
        v = count_add(cc, count_mul(sc, 100));
        v = count_add(v, count_mul(gc, 10000));
        v = count_add(v, count_mul(tc, 100000));
        v = count_add(v, count_mul(zc, 10000000));
        
        /*
        if (count_lt(amount, 10000000) && count_lt(v, amount))
        {
                if (present("thousand-gold", who))
                        return 2;
                else
                        return 0;
        }
        */
        if (count_lt(v, amount)) 
        {
                value = count_div(count_mul(amount, 101), 100);
                if (count_lt(who->query("balance"), value))
                        return 0;
                
                who->set("balance", count_sub(who->query("balance"), value));
                return 1;
        }
        else {
                left = count_sub(v, amount);
                
                if (zc)
                {
                        zc = atoi(count_div(left, 10000000));
                        left = atoi(count_sub(left, count_mul(zc, 10000000)));
                }
                if (tc)
                {
                        tc = atoi(count_div(left, 100000));
                        left = atoi(count_sub(left, count_mul(tc, 100000)));
                }
                gc = atoi(count_div(left, 10000));
                left = atoi(count_sub(left, count_mul(gc, 10000)));
                sc = left / 100;
                cc = left % 100;

                if (z_ob)
                        z_ob->set_amount(zc);

                if (t_ob)
                        t_ob->set_amount(tc);

                if (g_ob)
                        g_ob->set_amount(gc);
                else if (gc) {
                        g_ob = new(GOLD_OB);
                        g_ob->set_amount(gc);
                        g_ob->move(who, 1);
                }
                if (s_ob)
                        s_ob->set_amount(sc);
                else if (sc) {
                        s_ob = new(SILVER_OB);
                        s_ob->set_amount(sc);
                        s_ob->move(who, 1);
                }
                if (c_ob)
                        c_ob->set_amount(cc);
                else if (cc) {
                        c_ob = new(COIN_OB);
                        c_ob->set_amount(cc);
                        c_ob->move(who, 1);
                }

                return 1;
        }
}

mixed player_carry(object ob)
{
        object sand_ob;
        object cash_ob;
        object gold_ob;
        object silver_ob;
        object coin_ob;
        mixed gold;

        sand_ob = present("thousand-gold", ob);
        cash_ob = present("cash_money", ob);
        gold_ob = present("gold_money", ob);
        silver_ob = present("silver_money", ob);
        coin_ob = present("coin_money", ob);
   
#ifdef LONELY_IMPROVED  
        gold = count_div(ob->query("balance"), 10000);       
        if (sand_ob)
                gold = count_add(gold, count_mul(sand_ob->query_amount(), 1000));
        if (cash_ob) 
                gold = count_add(gold, count_mul(cash_ob->query_amount(), 10));
        if (gold_ob)
                gold = count_add(gold, gold_ob->query_amount());
        if (silver_ob)
                gold = count_add(gold, count_div(silver_ob->query_amount(), 100));
        if (coin_ob)
                gold = count_add(gold, count_div(coin_ob->query_amount(), 10000));
#else
        gold = ob->query("balance") / 10000;      
        if (sand_ob) gold += sand_ob->query_amount() * 1000;
        if (cash_ob) gold += cash_ob->query_amount() * 10;
        if (gold_ob) gold += gold_ob->query_amount();
        if (silver_ob) gold += silver_ob->query_amount() / 100;
        if (coin_ob)   gold += coin_ob->query_amount() / 10000;
#endif
        return gold;
}


