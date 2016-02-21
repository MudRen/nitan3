
/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : mysql_schedule_d.c
 * Author : Clode@Revival World
 * Date   : 2005-12-24
 * Note   : MySQL Schedule ����
 *
 -----------------------------------------
 */

#include <daemon.h>
#include <map.h>
#include <citydata.h>

// ��ɢ����
void distributed_refresh_city_map(array data, string *all_sql)
{
        if( !sizeof(data) )
        {
                string sql;
                mixed handle;
                
                if( !intp(handle = MYSQL_D->connect()) )
                        return;
                        
                MYSQL_D->exec(handle, "DELETE FROM citymap");

                foreach(sql in all_sql)
                        MYSQL_D->exec(handle, sql);


                MYSQL_D->updatetime(handle, "citymap");
                MYSQL_D->close(handle);
                
                return;
        }
        else
        {
                string city;
                int num, x, y, floor;
                mapping citydata;
                string *sql_tmp;
                object room;

                city = data[0];
                num = data[1];

                citydata = CITY_D->query_city_data(city, num)["data"];
        
                sql_tmp = ({"INSERT INTO `citymap` VALUES("+
                        "'" + city + "'," + 
                        num + ","+
                        "'" + (CITY_D->query_city_idname(city)||"")+"',"+
                        "'" + (CITY_D->query_city_idname(city, num)||"")+"',"+
                        "NOW(),'"
                });
                
                for(y=0;y<100;y++)
                for(x=0;x<100;x++)
                {
                        if( !undefinedp(citydata[y][x][ROOM])  )

                        {
                                if( citydata[y][x][ROOM] == "wizhall" )
                                {
                                        sql_tmp += ({"bw"+(floor+1)+","});      
                                }
                                else
                                {
                                        room = load_object(CITY_ROOM_MODULE(city, num, x, y, citydata[y][x][ROOM]));
                                        floor = query("floor", room);
                                        sql_tmp += ({"bp"+(floor+1)+"o"+query("owner", room)+","});
                                }
                        }
                        else
                                sql_tmp += ({citydata[y][x][TYPE]+","});
                }
                
                sql_tmp += ({"')"});
        
                all_sql += ({ remove_ansi(implode(sql_tmp, "")) });
                
                data = data[2..];
                
                call_out((:distributed_refresh_city_map:), 2, data, all_sql);
        }
        
}


// Called by TIME_D
void refresh_city_map()
{
        string city;
        int num;
        array data = allocate(0);

        foreach(city in sort_array(CITY_D->query_cities(), (: CITY_D->query_city_info($1, "totalflourish") < CITY_D->query_city_info($2, "totalflourish") ? 1: -1 :)))
        for(num=0;CITY_D->city_exist(city, num);num++)
                data += ({ city, num });
        
        distributed_refresh_city_map(data, allocate(0));
}



void refresh_world_map()
{
        
        
}

// Called by TIME_D
void refresh_who()
{
        function filter;
        mixed handle;
        string sql = "";
        
        if( !intp(handle = MYSQL_D->connect()) )
                return;
        
        MYSQL_D->exec(handle, "DELETE FROM who");
        

        sql = "INSERT INTO `who` VALUES";
        
        filter = load_object("cmds/std/ppl/who")->query_sort_user_fp();
        foreach(object ob in sort_array(users(), filter) )
        {
                if( !environment(ob) || !ob->is_user_ob() ) continue;
                
                sql += "('"+
                        (CITY_D->query_city_name(query("city", ob))||"")+"','"+
                        (ENTERPRISE_D->query_enterprise_color_id(query("enterprise", ob))||"")+"','"+
                        (query("title", ob)||"")+"','"+
                        (query("nickname", ob)||"")+"','"+
                        ob->query_idname()+"','"+
                        (ob->query_status()||"")+"','"+
                        (query("picture", ob)||"http://www.revivalworld.org/rwpweb/images/nopicture.png")+"'),";
        }

        sql = remove_ansi(sql[0..<2]);

        
        MYSQL_D->exec(handle, sql);
        MYSQL_D->updatetime(handle, "who");
        MYSQL_D->close(handle);
}

int twmudlist_sort(mapping mnlmudlist, string mud1, string mud2)
{
        string mud1_chinese = mnlmudlist[mud1]["MUD_CHINESE_NAME"];
        string mud2_chinese = mnlmudlist[mud2]["MUD_CHINESE_NAME"];
        string mud1_english = mnlmudlist[mud1]["MUD_ENGLISH_NAME"];
        string mud2_english = mnlmudlist[mud2]["MUD_ENGLISH_NAME"];


        if( sizeof(mud1_chinese) != sizeof(mud2_chinese) )
                return sizeof(mud1_chinese) > sizeof(mud2_chinese) ? 1 : -1;
        
        return strcmp(mud1_chinese || mud1_english, mud2_chinese || mud2_english);
}

// Called by TIME_D
void refresh_twmudlist()
{
        mixed handle;
        string ipport;
        string ip;
        int port;
        int status;
        int users;
        string lasttime;
        string sql = "";
        mapping muds;
        mapping data;
        string *mudnamesort;
        
        if( !intp(handle = MYSQL_D->connect()) )
                return;
        
        muds = MNLMUDLIST_D->query_mnlmudlist();
        
        MYSQL_D->exec(handle, "DELETE FROM twmudlist");
        
        sql = "INSERT INTO `twmudlist` VALUES";
        

        mudnamesort = sort_array(keys(muds)-({0}), (: twmudlist_sort($(muds), $1, $2) :)) ;
                
        foreach(ipport in mudnamesort)
        {
                data  = muds[ipport];

                if( !stringp(ipport) || !mapp(data) ) continue;
                
                sscanf(ipport, "%s %d", ip, port);
                
                if( data["CONNECT_FAILED_TIMES"] > 0 )
                        status = 0;
                else
                        status = 1;
                
                if( data["USERS"] > 0 )
                        users = data["USERS"];
                else if( !data["USERS_COUNT_PARSE"] )
                        users = -1;
                else
                        users = 0;

                if( data["LAST_CONTACT_TIME"] )
                        lasttime = TIME_D->replace_ctime(data["LAST_CONTACT_TIME"]);
                else
                        lasttime = "";
                        
                sql += "('"+
                        (data["MUD_CHINESE_NAME"]||"--δ֪����--")+"','"+
                        (data["MUD_ENGLISH_NAME"]||"--Unknown--")+"','"+
                        ip+"',"+

                        port+","+
                        status+","+
                        users+",'"+
                        lasttime+"'),";
                
        }
        
        sql = remove_ansi(sql[0..<2]);
        MYSQL_D->exec(handle, sql);
        MYSQL_D->updatetime(handle, "twmudlist");
        MYSQL_D->close(handle);
}

void create()
{


}
string query_name()
{
        return "MYSQL �ų�ϵͳ(MYSQL_SCHEDULE_D)";
}

