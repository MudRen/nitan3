// This file written by eval command. 
#define COST_TRIM     -8
#define EXPT_TRIM     -4
#include <ansi.h>
#include <command.h>
#include <function.h>
#include <localtime.h>
#include <origin.h>
#include <room.h>
#include <type.h>
#include <user.h>
#include <dbase.h>

inherit F_CLEAN_UP;

void create()
{
        mapping sinfo, einfo;
        int cost, time_exp; 
        float utime, stime, etime;
        string msg;
        object me = this_player();

        sinfo = rusage();
        cost = eval_cost();
        time_exp = time_expression {
NAME::create();
        };
        einfo = rusage();
        cost -= eval_cost();

        utime = to_float(einfo["utime"] - sinfo["utime"])/1000000;
        stime = to_float(einfo["stime"] - sinfo["stime"])/1000000;
        etime = to_float(time_exp + EXPT_TRIM)/1000000;

        msg  = sprintf("\nЧ������: %d\n", cost + COST_TRIM);
        msg += sprintf("ϵͳʱ��: %.6f s\n", stime);
        msg += sprintf("ʹ��ʱ��: %.6f s\n", utime);
        msg += sprintf("����ʱ��: %.6f s\n", etime);
        
        tell_object(me, msg);
}
