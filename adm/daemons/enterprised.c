
#include <ansi.h>
#include <dbase.h>

inherit F_DBASE;

#define DATA_PATH       "/data/enterprise.o"
#define MRTGDATA        "/data/stock/"

#define STOCK_MAX_VALUE         1000.0
#define STOCK_MIN_VALUE         1.0
#define STOCK_DEFAULT_VALUE     50.0
#define STOCK_DEFAULT_AMOUNT    5000

mapping enterprises;
mapping special_stockvalue;
mapping serial_number;

int range_random(int i, int j)
{
        return random(i<j?j-i+1:i-j+1)+((i<j)?i:j);
}

string query_serial_number(string key)
{
        if( !stringp(key) )
                return 0;
        
        serial_number[key] = count_add(serial_number[key], 1);
        
        save_object(DATA_PATH);

        return serial_number[key];
}

int enterprise_exists(string id)
{
        return !undefinedp(enterprises[id]);
}

string query_enterprise_color_id(string id)
{
        if( undefinedp(enterprises[id]) ) return 0;

        return enterprises[id]["color_id"];
}


// �ش����ĸ���ҵ����
string in_enterprise(string id)
{
        string enterprise_id, member_id;
        mapping enterprise_data, member_data;

        foreach( enterprise_id, enterprise_data in enterprises )
                foreach( member_id, member_data in enterprise_data["member"] )
                        if( id == member_id )
                                return enterprise_id;

        return 0;
}

// ע����ҵ��Ա
void register_member(string enterprise_id, string member_id)
{
        mapping member_data = allocate_mapping(0);

        member_data["jointime"] = time();

        enterprises[enterprise_id]["member"][member_id] = member_data;

        save_object(DATA_PATH);
}

// ע����ҵ��Ա
void unregister_member(string unregister_id)
{
        string enterprise_id, member_id;
        mapping enterprise_data, member_data;

        foreach(enterprise_id, enterprise_data in enterprises)
        {
                foreach(member_id, member_data in enterprise_data["member"])
                {
                        if( unregister_id == member_id )
                                map_delete(enterprises[enterprise_id]["member"], unregister_id);
                }
        }

        save_object(DATA_PATH);
}

// �趨��ҵ��Ѷ
mixed set_enterprise_info(string id, string prop, mixed info)
{
        if( undefinedp(enterprises[id]) ) return 0;

        return enterprises[id][prop] = info;
}

// ��ѯ��ҵ��Ѷ
varargs mixed query_enterprise_info(string id, string prop)
{
        if( undefinedp(enterprises[id]) ) return 0;

        if( undefinedp(prop) )
                return enterprises[id];

        return enterprises[id][prop];
}

// ɾ����ҵ��Ѷ
void delete_enterprise_info(string id, string prop)
{
        if( undefinedp(enterprises[id]) ) return 0;

        map_delete(enterprises[id], prop);
}

// ע����ҵ
void register_enterprise(string id, string color_id, string president)
{
        enterprises[id] = allocate_mapping(0);

        enterprises[id]["president"] = president;
        enterprises[id]["color_id"] = color_id;
        enterprises[id]["member"] = allocate_mapping(0);
        enterprises[id]["registertime"] = time();
        enterprises[id]["stockvalue"] = STOCK_DEFAULT_VALUE;
        enterprises[id]["stockpredictvalue"] = STOCK_DEFAULT_VALUE;
        enterprises[id]["stockamount"] = STOCK_DEFAULT_AMOUNT;
        enterprises[id]["available_stockamount"] = STOCK_DEFAULT_AMOUNT;

        register_member(id, president);

        save_object(DATA_PATH);
}
///////////////////////////////////////////////////////////////////////////////////////////
// ע����ҵ
void unregister_enterprise(string enterprise_id)
{
        object member_ob;
        string member_id;
        mapping member_data;

        if( undefinedp(enterprises[enterprise_id]) ) return;

        foreach(member_id, member_data in enterprises[enterprise_id]["member"])
        {
                member_ob = UPDATE_D->global_find_player(member_id);

                if( objectp(member_ob) )
                {
                        member_ob->delete("enterprise");

                        UPDATE_D->global_destruct_player(member_ob, 1); 
                }                
        }

        map_delete(enterprises, enterprise_id);

        save_object(DATA_PATH);
}

// ����Ƿ�Ϊ�ܲ�
int is_president(string enterprise_id, string id)
{
        if( undefinedp(enterprises[enterprise_id]) ) return 0;

        return enterprises[enterprise_id]["president"] == id;
}

string query_president(string enterprise_id)
{
        if( undefinedp(enterprises[enterprise_id]) ) return 0;

        return enterprises[enterprise_id]["president"];
}

// ����Ƿ�Ϊ��Ա
int is_member(string enterprise_id, string id)
{
        if( undefinedp(enterprises[enterprise_id]) ) return 0;

        return !undefinedp(enterprises[enterprise_id]["member"][id]);
}

// ����Ͷ��
string change_invest(string enterprise_id, string id, mixed money)
{
        string result;

        if( undefinedp(enterprises[enterprise_id]) || 
            undefinedp(enterprises[enterprise_id]["member"][id]) ) return 0;

        result = count_add(enterprises[enterprise_id]["member"][id]["invest"], money);

        enterprises[enterprise_id]["member"][id]["invest"] = result;

        return result;
}

// �����ʲ�
string change_assets(string enterprise_id, mixed money)
{
        string result;

        if( undefinedp(enterprises[enterprise_id]) ) return 0;

        result = count_add(enterprises[enterprise_id]["assets"], money);

        if( count_lt(result, 0) ) return 0;

        enterprises[enterprise_id]["assets"] = result;

        //if( wizardp(enterprises[enterprise_id]["president"]) )
        //      enterprises[enterprise_id]["assets"] = "0";

        return result;
}

//
// ��������Ƿ���ͬһ����ҵ��
int same_enterprise(string member_id1, string member_id2)
{
        if( !member_id1 || !member_id2 )
                return 0;

        foreach(string enterprise_id, mapping enterprise_data in enterprises)
        {
                if( !undefinedp(enterprise_data["member"][member_id1]) &&
                        !undefinedp(enterprise_data["member"][member_id2]) )
                        return 1;
        }

        return 0;
}

string query_money(string enterprise_id)
{
        if( undefinedp(enterprises[enterprise_id]) ) return 0;

        return enterprises[enterprise_id]["assets"];
}

mapping query_enterprises()
{
        return copy(enterprises);
}

string query_enterprise_assets(string enterprise_id)
{
        string totalassets;

        if( undefinedp(enterprises[enterprise_id]) ) return 0;

        // ÿСʱ��һ�� cache
        if( enterprises[enterprise_id]["assets_cache_time"] + 3600 < time() )
        {
                enterprises[enterprise_id]["assets_cache"] = query("ENTERPRISE/"+enterprise_id);
                enterprises[enterprise_id]["assets_cache_time"] = time();
        }

        totalassets = count_add(enterprises[enterprise_id]["assets"], enterprises[enterprise_id]["assets_cache"]);

        //foreach(string id, mapping data in enterprises[enterprise_id]["member"])
                //totalassets = count_add(totalassets, MONEY_D->query_lazy_assets(id));

        return totalassets;
}


//
// �ش����г�Ա�����ʲ�
/////////////////////////////////////////////////////////////
string query_enterprise_allmembers_assets(string enterprise_id)
{
        string totalassets;

        if( undefinedp(enterprises[enterprise_id]) ) return 0;

        foreach(string id, mapping data in enterprises[enterprise_id]["member"])
                totalassets = count_add(totalassets, MONEY_D->query_lazy_assets(id));

        return totalassets;
}

string *query_all_enterprises()
{
        return sort_array(keys(enterprises), (: count_lt(query_enterprise_allmembers_assets($1), 
                                                         query_enterprise_allmembers_assets($2)) ? 1 : -1 :));
}

int save()
{
        return save_object(DATA_PATH);
}

int remove()
{
        return save();
}

void fix_enterprise_database()
{
//      foreach(string enterprise_id, mapping data1 in enterprises)
}

void add_enterprise_to_mrtg(string enterprise_id, int enterprise_id_number, float new_stockvalue)
{
/*
        mapping info = ([
                "Directory":"stock/"+enterprise_id_number,
                "Target":"`cat \""LIBRARY_PATH+MRTGDATA+enterprise_id_number+"\"`",
                "YLegend":"Value",
                "LegendI":"�ɼ�",
                "LegendO":"",
                "Legend1":"��ҵ��������",
                "Legend2":"",
                "ShortLegend":"Ԫ",
                "MaxBytes":50,
                "MaxAbs":1500,
                "Options":"gauge, growright, nopercent, noinfo",
                "Title": enterprise_id+"��ҵ��������",
                "PageTop":enterprise_id+"��ҵ��������"
        ]);
*/
}


void set_special_stockvalue(string reason, int value)
{
        if( !mapp(special_stockvalue) )
                special_stockvalue = allocate_mapping(0);

        special_stockvalue[reason] = value;
}

void heart_beat()
{
        string enterprise_id;
        mapping enterprise_data;
        float new_stockvalue;
        float stockvalue_change;
        int randomvalue;
        int assets_scale;
        int global_randomvalue;

        global_randomvalue = range_random(-30, 30);

        if( sizeof(special_stockvalue) > 0 )
        {
                foreach(string reason, int svalue in special_stockvalue )
                {
                        CHANNEL_D->do_channel(this_object(), "stock", reason); 
                        global_randomvalue += svalue;
                }
                special_stockvalue = allocate_mapping(0);
        }

        if( global_randomvalue >= 25 )
                CHANNEL_D->do_channel(this_object(), "stock", "�����ܵ�����"HIR"��"NOR RED"��"NOR HIR"Ӱ�죬�����ձ�����������ơ�");
        else if( global_randomvalue <= -25 )
                CHANNEL_D->do_channel(this_object(), "stock", "�����ܵ�����"HIG"��"NOR GRN"��"NOR HIR"Ӱ�죬�����ձ����ƣ����");

        foreach(enterprise_id, enterprise_data in enterprises)
        {
                if( undefinedp(enterprise_data["enterprise_id_number"]) )
                        enterprises[enterprise_id]["enterprise_id_number"] = query_serial_number("enterprise_id_number");

                // ����Ԥ�ڹɼ۵ĵ���
                if( !random(500) )
                {
                        randomvalue = range_random(-1000, 1000);

                        // ÿ�θı���� 10%
                        stockvalue_change = enterprise_data["stockpredictvalue"] * randomvalue * 0.0001;

                        // ��Ϣ֪ͨ
                        if( !random(2) )
                        switch(randomvalue)
                        {
                                case 800..1000:
                                        CHANNEL_D->do_channel(this_object(), "stock", "����ʦԤ����ҵ����"+query_enterprise_color_id(enterprise_id)+"�Ĺɼ۳��ڶ��Կ��ܻ��д�����ǡ�");
                                        break;
                                case 500..799:
                                        CHANNEL_D->do_channel(this_object(), "stock", "����ʦԤ����ҵ����"+query_enterprise_color_id(enterprise_id)+"�Ĺɼ۳��ڶ��Կ��ܻ���С�����ǡ�");
                                        break;
                                case -799..-500:
                                        CHANNEL_D->do_channel(this_object(), "stock", "����ʦԤ����ҵ����"+query_enterprise_color_id(enterprise_id)+"�Ĺɼ۳��ڶ��Կ��ܻ���С���µ���");
                                        break;
                                case -1000..-800:
                                        CHANNEL_D->do_channel(this_object(), "stock", "����ʦԤ����ҵ����"+query_enterprise_color_id(enterprise_id)+"�Ĺɼ۳��ڶ��Կ��ܻ���С���µ���");
                                        break;
                        }

                        new_stockvalue = enterprise_data["stockpredictvalue"] + stockvalue_change;

                        assets_scale = sizeof(query_enterprise_assets(enterprise_id));

                        // �ɼۼ�����ҵ��ֵ scale
                        //new_stockvalue += pow(to_float(assets_scale+"."+to_string(assets_scale)[0..0]), 1.3);

                        if( new_stockvalue < STOCK_MIN_VALUE )
                                new_stockvalue = STOCK_MIN_VALUE;
                        else if( new_stockvalue > STOCK_MAX_VALUE )
                                new_stockvalue = STOCK_MAX_VALUE;

                        enterprises[enterprise_id]["stockpredictvalue"] = new_stockvalue;
                }


                // �ɼ۵���Ԥ�ڹɼ۵� 90%
                if( enterprise_data["stockvalue"]  < enterprise_data["stockpredictvalue"] * 0.9 )
                        randomvalue = range_random(-40, 80);
                // �ɼ۸���Ԥ�ڹɼ۵� 110%
                else if( enterprise_data["stockvalue"] > enterprise_data["stockpredictvalue"] * 1.1 )
                        randomvalue = range_random(-80, 40);
                else
                        randomvalue = range_random(-80, 80);

                randomvalue += global_randomvalue;

                // ÿ�α䶯��� 1.5%
                stockvalue_change = enterprise_data["stockvalue"] * randomvalue * 0.0001;

                new_stockvalue = enterprise_data["stockvalue"] + stockvalue_change;


                if( new_stockvalue < STOCK_MIN_VALUE )
                        new_stockvalue = STOCK_MIN_VALUE;
                else if( new_stockvalue > STOCK_MAX_VALUE )
                        new_stockvalue = STOCK_MAX_VALUE;

                if( randomvalue >= 200 )
                        CHANNEL_D->do_channel(this_object(), "stock", sprintf("��ҵ����%s�ɼ۴��� "HIR"��%.2f"NOR" ��(%.2f%%)����Ϊ "HIW"%.2f"NOR" �㡣",
                                query_enterprise_color_id(enterprise_id),
                                stockvalue_change,
                                randomvalue/100.,
                                new_stockvalue));
                else if( randomvalue <= -200 )
                        CHANNEL_D->do_channel(this_object(), "stock", sprintf("��ҵ����%s�ɼ��ش� "HIG"��%.2f"NOR" ��(%.2f%%)����Ϊ "HIW"%.2f"NOR" �㡣",
                                query_enterprise_color_id(enterprise_id),
                                -stockvalue_change,
                                -randomvalue/100.,
                                new_stockvalue));

/*
                if( stockvalue_change > 0. )
                        CHANNEL_D->do_channel(this_object(), "stock", sprintf("%-20s �ɼ� "HIR"��%5.2f"NOR"����Ϊ "HIW"%7.2f"NOR" �㡣", query_enterprise_color_id(enterprise_id), stockvalue_change, new_stockvalue));
                else if( stockvalue_change < 0. )
                        CHANNEL_D->do_channel(this_object(), "stock", sprintf("%-20s �ɼ� "HIG"��%5.2f"NOR"����Ϊ "HIW"%7.2f"NOR" �㡣", query_enterprise_color_id(enterprise_id), -stockvalue_change, new_stockvalue));
                else
                        CHANNEL_D->do_channel(this_object(), "stock", sprintf("%-20s �ɼ� "HIW"  %5.2f"NOR"����Ϊ "HIW"%7.2f"NOR" �㡣", query_enterprise_color_id(enterprise_id), stockvalue_change, new_stockvalue));
*/
                enterprises[enterprise_id]["stockvalue_change"] = stockvalue_change;
                enterprises[enterprise_id]["stockvalue"] = new_stockvalue;

                if( undefinedp(enterprises[enterprise_id]["stockvalue_minimum"]) )
                        enterprises[enterprise_id]["stockvalue_minimum"] = new_stockvalue;
                else if( new_stockvalue < enterprises[enterprise_id]["stockvalue_minimum"]+10. )
                        enterprises[enterprise_id]["stockvalue_minimum"] = new_stockvalue+10.;

                add_enterprise_to_mrtg(enterprise_id, enterprises[enterprise_id]["enterprise_id_number"], new_stockvalue);
        }
}

void set_enterprise_stockvalue(string enterprise_id, float value)
{
        enterprises[enterprise_id]["stockvalue"] = value;
}

void create()
{
	seteuid(getuid()); 
	set("channel_id", "��Ʊ����"); 

        if( !restore_object(DATA_PATH) )
        {
                enterprises = allocate_mapping(0);
                save();
        }

        set_heart_beat(6000);
}


string query_name()
{
        return "��ҵϵͳ(ENTERPRISE_D)";
}
