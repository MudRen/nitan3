// updated by Lonely@nitan3

#define DATA_PATH		"/data/timed.o"

#include <ansi.h>
#include <localtime.h>
#include <mudlib.h>

#define MIN		0
#define HOUR		1
#define WDAY		2
#define MDAY		3
#define MON		4
#define YEAR		5

inherit F_DBASE;

int gametime;
nosave int realtime;

nosave int tick;
nosave mapping event = allocate_mapping(0);

nosave int *real_time = allocate(6);
nosave int *game_time = allocate(6);

void auto_relaim() 
{
        int i; 
        if (i = reclaim_objects()) 
                CHANNEL_D->do_channel( this_object(), "sys", 
                        sprintf("ϵͳ�Զ���� %d ��������", i)); 
}

void happy_game_new_year()
{
	shout(BEEP WHT "\n" + CHINESE_MUD_NAME + CHINESE_D->chinese_number(game_time[YEAR]) + "�������������������ڣ�����\n" NOR);
}

void happy_real_new_year()
{
        shout(BEEP WHT"\n��Ԫ" HIW+CHINESE_D->chinese_number(real_time[YEAR])+WHT"�������������������ڣ�����\n"NOR);
	shout(BEEP WHT"\n��Ԫ" HIW+CHINESE_D->chinese_number(real_time[YEAR])+WHT"�������������������ڣ�����\n"NOR);
	shout(BEEP WHT"\n��Ԫ" HIW+CHINESE_D->chinese_number(real_time[YEAR])+WHT"�������������������ڣ�����\n"NOR);
}

// ��Ϸʱ��Ĺ����ų�
nosave mapping game_crontab = ([
// "min hour wday mday mon year" : ({ function })
"0 0 * 0 0 *"		:
			({
				(: happy_game_new_year :),
			}),
]);

// ��ʵʱ��Ĺ����ų�
nosave mapping real_crontab = ([
// "min hour wday mday mon year" : ({ function })
"0 0 * 0 0 *"		: 
			({ 
				(: happy_real_new_year :),
			}),
"* * * * * *"         : 
			({ 
                                (: SCHEDULE_D->start_events() :),
			}),			   
]);

nosave mapping crontab_process = allocate_mapping(0);

// ��ȡ�� call_out ֮����, ���� 0.1 ��Ϊʱ�䵥λ
void add_event(function fevent, int delay_time)
{
	if( !sizeof(event) || !event[fevent] ) 
		event = ([ fevent : delay_time ]);
	else
		event[fevent] = delay_time;
}

// ִ���¼�
void exec_event(function fevent)
{
	if( objectp(function_owner(fevent)) )
		evaluate(fevent);

	map_delete(event, fevent);
}

string replace_ctime(int t)
{
	string month, ctime = ctime(t);

	switch(ctime[4..6])
	{
		case "Jan"	:	month = "01";break;
		case "Feb"	:	month = "02";break;
		case "Mar"	:	month = "03";break;
		case "Apr"	:	month = "04";break;
		case "May"	:	month = "05";break;
		case "Jun"	:	month = "06";break;
		case "Jul"	:	month = "07";break;
		case "Aug"	:	month = "08";break;
		case "Sep"	:	month = "09";break;
		case "Oct"	:	month = "10";break;
		case "Nov"	:	month = "11";break;
		case "Dec"	:	month = "12";break;
	}

	return sprintf("%s/%s/%s %s", month, (ctime[8]==' '?"0"+ctime[9..9]:ctime[8..9]), ctime[<4..<1], ctime[11..15]);
}

string season_period(int m)
{
	switch(m)
	{
		case 2..4:	return "��";
		case 5..7:	return "��";
		case 8..10:	return "��";
		case 11:	return "��";
		case 0..1:	return "��";
		default:	return 0;
	}
}

string week_period(int w)
{
	switch(w)
	{       
		case 0: 	return "��";
		case 1: 	return "һ";
		case 2: 	return "��";
		case 3: 	return "��";
		case 4: 	return "��";
		case 5: 	return "��";
		case 6: 	return "��";
		default:	return 0;
	}
}

string hour_period(int h)
{
	switch(h)
	{
		case 0..5: 	return "�賿";
		case 6..11: 	return "����";
		case 12:	return "����";
		case 13..18:	return "����";
		case 19..23:	return "����";
		default:	return 0;
	}
}

/* �ش�ʱ������ ({ �� ʱ �� �� �� �� }) */
int *query_gametime_array()
{
	return game_time;
}	

int *query_realtime_array()
{
	return real_time;
}

/* �ش���λʱ���ʾ ���� 3:39 */
string gametime_digital_clock()
{
	int h = game_time[HOUR];
	int m = game_time[MIN];

	return hour_period(h)+" "+(h==12 || (h%=12)>9?""+h:" "+h)+":"+(m>9?""+m:"0"+m);
}
string realtime_digital_clock()
{
	int h = real_time[HOUR];
	int m = real_time[MIN];

	return hour_period(h)+" "+(h==12 || (h%=12)>9?""+h:" "+h)+":"+(m>9?""+m:"0"+m);
}

string time_description(string title, int *t)
{
	return sprintf( NOR WHT+title+NOR"%s�꣬%s��%s��%s������%s��%s%s��%s��"NOR
	    ,t[YEAR]==1?"Ԫ":CHINESE_D->chinese_number(t[YEAR])
	    ,season_period(t[MON])
	    ,!t[MON]?"Ԫ":CHINESE_D->chinese_number(t[MON]+1)
	    ,CHINESE_D->chinese_number(t[MDAY]+1)
	    ,week_period(t[WDAY])
	    ,hour_period(t[HOUR])
	    ,CHINESE_D->chinese_number(t[HOUR] > 12 ? t[HOUR]%12 : t[HOUR])
	    ,CHINESE_D->chinese_number(t[MIN])
	);
}

string game_time_description()
{
	return time_description(CHINESE_MUD_NAME, game_time);
}

string real_time_description()
{
	return time_description("��Ԫ", real_time);
}

int query_game_time()
{
	return gametime*60;
}

int query_real_time()
{
	return realtime;
}

int *analyse_time(int t)
{
	int *ret = allocate(6);
	string ctime;

	ctime = ctime(t);

	sscanf(ctime,"%*s %*s %d %d:%d:%*d %d",ret[MDAY], ret[HOUR], ret[MIN], ret[YEAR]);

	switch(ctime[0..2])
	{
		case "Sun": ret[WDAY] = 0; break;
		case "Mon": ret[WDAY] = 1; break;
		case "Tue": ret[WDAY] = 2; break;
		case "Wed": ret[WDAY] = 3; break;
		case "Thu": ret[WDAY] = 4; break;
		case "Fri": ret[WDAY] = 5; break;
		case "Sat": ret[WDAY] = 6; break;
		default	  : return 0;
	}

	switch(ctime[4..6])
	{
		case "Jan": ret[MON] = 0; break;
		case "Feb": ret[MON] = 1; break;
		case "Mar": ret[MON] = 2; break;
		case "Apr": ret[MON] = 3; break;
		case "May": ret[MON] = 4; break;
		case "Jun": ret[MON] = 5; break;
		case "Jul": ret[MON] = 6; break;
		case "Aug": ret[MON] = 7; break;
		case "Sep": ret[MON] = 8; break;
		case "Oct": ret[MON] = 9; break;
		case "Nov": ret[MON] = 10; break;
		case "Dec": ret[MON] = 11; break;
		default	  : return 0;
	}
	ret[MDAY] -= 1;
	return ret;
}

void process_crontab(mapping crontab, int *timearray)
{
	int i, j, row, divider, fit, timecost;
	string s, script, *timescript;
	string *tc, *fps;
	function fp;

	tc = keys(crontab);
	
        if( !sizeof(tc) ) return;
	
	for(row=0;row<sizeof(tc);row++)
	{
		reset_eval_cost();
		script = tc[row];
		fps = crontab[script];

		timescript = allocate(6);
		
                // %s%*(( |\t)+) ����˼�� %s(�ո� or \t ����)���� + ��������һ��һ�����Ϸ��ϵĵ�Ԫ
                if( sscanf(script, "%s%*(( |\t)+)%s%*(( |\t)+)%s%*(( |\t)+)%s%*(( |\t)+)%s%*(( |\t)+)%s",
			timescript[0],
			timescript[1],
			timescript[2],
			timescript[3],
			timescript[4],
                        timescript[5]) != 11 ) continue;

		for(i=0;i<6;i++)
		{
			fit = 0;

			foreach(s in explode(timescript[i], ","))
			{
				j = to_int(s);
				
				if( j )
				{
					if( j == timearray[i] )
					{
						fit = 1;
						break;
					}
				}
				else if( s == "*" || (sscanf(s, "*/%d", divider) && !(timearray[i]%divider)) )
				{
					fit = 1;
					break;
				}
			}
			
			if( !fit ) break;
		}
		
		if( !fit ) 
			continue;
		
		timecost = 0;	
		foreach( fp in fps )
			timecost += time_expression {
				catch(evaluate(fp));
			};
		
		if( timecost > 1000000 )
			CHANNEL_D->do_channel(this_object(), "sys", 
				sprintf("TIME_D: crontab '%s'(%.6f sec)", script, timecost/1000000.));

	}
}

// ��������ÿ��ִ�к�ʽ
void process_per_second()
{

	
}

void reset_gametime()
{
	gametime = -20000000;	
}

/* ��Ϸʱ��ÿһ����(��ʵ��ʱ��ÿ2.5��)ִ��һ�� process_gametime */
void process_gametime()
{
	game_time = analyse_time(++gametime * 60);
	game_time[YEAR] -= 1863;

	process_crontab(game_crontab, game_time);
}

/* ��ʵʱ��ÿһ����ִ��һ�� process_realtime */
void process_realtime()
{
	array localtime = localtime(realtime);
	
	real_time = ({ 
		localtime[LT_MIN], 
		localtime[LT_HOUR], 
		localtime[LT_WDAY], 
		localtime[LT_MDAY]-1, 
		localtime[LT_MON], 
		localtime[LT_YEAR] });
	
	process_per_second();

        if( !localtime[LT_SEC] )
		process_crontab(real_crontab, real_time);
}

// ÿ 1 ������һ��
// ʵ��һ�������Ϸһ��

void heart_beat()
{
	realtime = time();

	// ִ�� event ����
	if( sizeof(event) )
	foreach( function fevent, int delay_time in event )
		if( !--event[fevent] )
			exec_event(fevent);

	// ÿ 2 ���൱����Ϸһ����, time ÿ���� 1 ������Ϸһ����
	if( !(++tick % 2) ) 
		process_gametime();

	process_realtime();
}

void create()
{
        seteuid(ROOT_UID); 
        set("channel_id", "ʱ�侫��"); 
        write("ʱ�侫���Ѿ�������\n"); 
	if( !restore_object(DATA_PATH) )
		save_object(DATA_PATH);
	
	game_time = allocate(6);
	real_time = allocate(6);
	event = allocate_mapping(0);
	
	process_gametime();
        set_heart_beat(1);
}

int remove()
{
	return save_object(DATA_PATH);
}

string query_name()
{
	return "ʱ��ϵͳ(TIME_D)";
}
