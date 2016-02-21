// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <login.h>
#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;

#define WAIT_HEART_BEAT  2

nosave int serial = 0;

//int is_login_ob() { return 1; }

void heart_beat();

void create()
{
        // ���ƶ��������� LOGON ����������������������
        // if (clonep()) call_out("time_out", 0);
}

void logon()
{
        remove_call_out("time_out");
        call_out("time_out", LOGIN_TIMEOUT);

        if (interactive(this_object()))
                set_temp("ip_number", query_ip_number(this_object()));

        LOGIN_D->logon(this_object());
}

// Don't destruct(this_object()) in the net_dead() interactive apply or
// there'll be error message: Double call to remove_interactive()
void net_dead()
{
        remove_call_out("time_out");
        call_out("time_out", 1);
}

void time_out()
{
        object body;

        if (objectp(body = query_temp("body_ob")))
        {
                if (! environment(body) && ! body->query("registered"))
                        destruct(body);
                return;
        }
        if (interactive(this_object()))
                write("\n���������߽���������ʱ��̫���ˣ��´���������ɡ�\n");
        destruct(this_object());
}

// This is used by F_SAVE to determinethe file name to save our data.
string query_save_file()
{
        string id;

        id = query("id", 1);
        if (! stringp(id)) return 0;
        return sprintf(DATA_DIR "login/%c/%s", id[0], id);
}

void receive_message(string type, string str)
{
        if (type != "write") return;
        
        if (this_object()->query_temp("big5"))
#ifdef LONELY_IMPROVED
                // str = gbtobig5(str);
                str = (string)LANGUAGE_D->toBig5(str);
#else
                str = (string)LANGUAGE_D->toBig5(str);
#endif                
        receive(str);
}

void terminal_type(string term_type)
{
        set_temp("terminal_type", term_type);
}

void window_size(int width, int height)
{
        set_temp("window_size", ({width, height}));
}
// Protect login object's data against hackers.
nomask mixed set(string prop, mixed data)
{
        if (geteuid(previous_object()) != ROOT_UID) return 0;
        return ::set(prop, data);
}

nomask mixed query_entire_dbase()
{
        if (geteuid(previous_object()) != ROOT_UID) return 0;
        return ::query_entire_dbase();
}

nomask mixed query(string prop, int raw)
{
        if (geteuid(previous_object()) != ROOT_UID &&
            prop == "/") return 0;
        return ::query(prop, raw);
}

string process_input(string str)
{
        if (this_object()->query_temp("big5"))
#ifdef LONELY_IMPROVED
                // str = big5togb(str);
                str = LANGUAGE_D->toGB(str);
#else
                str = LANGUAGE_D->toGB(str);
#endif                 
        return str;
}

#ifdef LONELY_IMPROVED
int save()
{
        int res;
        
#ifdef DB_SAVE
      	res = DATABASE_D->db_set_player(query("id", 1), "login_dbase",
          	save_variable(query_entire_dbase()));
#endif        
        if (TX_SAVE)
                res = ::save();

        return res;
}

int restore()
{
        //mapping dbase;
       // string  str;
        int     res = 0;
        
#ifdef DB_SAVE
    mapping dbase;
    string  str;
   	str = DATABASE_D->db_query_player(query("id", 1), "login_dbase");
    	if (str && stringp(str))
    	{
            	dbase = restore_variable(str);
          	if (mapp(dbase))
          	{
                    	set_dbase(dbase);
                 	res = 1;
             	}
     	}
#else
        if (TX_SAVE) 
                res = ::restore();
#endif
        if ((int)query_temp("restore_mysql"))
                res = ::restore();
                
        return res;
}
#endif
