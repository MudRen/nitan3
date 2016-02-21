//                ��׼��������ʾ��                                   |
// ��С����ʱ������Ϸ��֧��
// by naihe  2003-06-19  ��ï��



#include <ansi.h>
inherit ITEM;


#define B1		"���ö�Ŀ�Ļƽ�"	// ��  - YEL, HIY
#define B2		"װ����ҵı���"	// ����  - MAG, HIM
#define B3		"��Ƕ��ʯ�Ľ�ʹ�"	// �ʹ�  - YEL, HIY
#define B4		"�ʺ����ʯ����"	// ����  - CYN, HIC
#define B5		"ʥ�������"		// ����  - WHT, HIW
#define B6		"���صİ׽�Ȩ��"	// Ȩ��  - WHT, HIW
#define B7		"����а���ʥʮ�ּ�"	// ʥ��  - HIM, HIM
#define B8		"Ԥʾδ��������ˮ��"	// ˮ��  - CYN, HIC
#define B9		"��Ƕ�챦ʯ������֮��"	// ����  - RED, HIR
#define B10		"��ϣ��ͬ�е������"	// ���  - GRN, HIG


string game_now = "�ȴ��ƶ�����";
string att_now = "not_ok";
int target_hp, target_damage;
string pic_me, pic_target;



void new_game_set( int amount, string mark );
void map();
void check_hp();
object get_me();
string get_msg( int x, int y, string type );
void xunbaotu();
void fight_start( string who );
void be_attack();
void target_check_hp();


int finded_baowu( int which, string name )
{
	object me = get_me();
	int score;

	if( !me ) return 0;

	add("be_finded", 1);
	set("b"+ which, HIW + query("b"+ which) );
	map();
	write(HIC"��С����ʱ����  ̫�����ˣ������ҵ��� "+ name + " ��\n"NOR);

	if( query("be_finded") == 10 )
	{
		me->delete_temp("hanghai_gameing");
		game_now = "��Ϸ����";
		score = query("score");

		score += query("att_hp") * 500;
		score += query("att_jf") * 500;
		score += query("att_rs") * 500;
		score += query("att_yq") * 500;
		score += query("att_fd") * 500;

		score += query("hp") * 1000;

		if( score < 1 ) score = 1;
                me->add("combat_exp", 500);

		write(HIY"
=========================================
             ��С����ʱ����

    ��������ʮ���������Ϸʤ�������ˡ�
    ������յ÷��� "+score+" ��(�����ο�)��

    ������ 500 �� ����ֵ�Ľ�����
=========================================
\n"NOR);

		message_vision("$N�ɹ�������� С����ʱ�� ��Ϸ��\n", me);
		remove_call_out("del_me");
		call_out("del_me", 1);
	}

	return 1;
}


// ��á�me��
object get_me()
{
	object me;
	if( !query("owner_id") ) return 0;

	me = find_player( query("owner_id") );
	if( !me ) return 0;
	return me;
}

// ��ù�������
int damage( int type )  // 6-11
{
	if( !type || type<1 || type>5 ) type = 1;

	switch( type )
	{
		case 1:	return ( 6+random(6) );
		case 2:	return ( 12+random(6) );
		case 3:	return ( 18+random(6) );
		case 4:	return ( 24+random(6) );
		case 5:	return ( 30+random(6) );
	}

	return (6+random(6));
}

void del_me()
{
	destruct( this_object() );
}

void create()
{
	set_name(HIY"��γ�ǣ���Ϸ���ߣ�"NOR, ({"jingwei yi","yi"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "��С����ʱ������Ϸ����Ҫ���ߣ��������ſ��Խ�����Ϸ��

��ѯ���ڵ���Ϸ״̬�����룺 game check
�κ�ʱ�������Ϸ�����룺   game over
\n");
		set("unit", "��");
		set("value", 0);
	}

	set("no_get", 1);
	set("no_drop",1);
	set("no_steal",1);
	set("no_give",1);
	setup();
}


void init()
{
	add_action("do_game", "game");
	add_action("do_go", "go");
	add_action("do_liaowang", "liaowang");
	add_action("do_attack", "atk");
}


void new_game(object me)
{
	if( !me ) return del_me();

	set("owner_id", getuid(me));
	set("owner_name", me->query("name"));

// ******************************************
	new_game_set( 8, "����" );

// ******************************************
	new_game_set( 4, "��Զ��" );

// ******************************************
	new_game_set( 4, "����̽����" );

// ******************************************
	new_game_set( 4, "Ѱ��ͼ" );

// ******************************************
//	new_game_set( 2, "����" );
// ��Ҫ���е����ã�

// ******************************************
	new_game_set( 2, "��ɽ" );

// ******************************************
	new_game_set( 3, "����Ʒ" );

// ******************************************
	new_game_set( 6, "������" );

// ******************************************
	new_game_set( 6, "��������" );

// ******************************************
	new_game_set( 6, "���پ���" );

// ******************************************
	new_game_set( 6, "������" );

// ******************************************
	new_game_set( 6, "���鴬" );


// ���ﲿ��
// ******************************************
	new_game_set( 1, B1);
	new_game_set( 1, B2);
	new_game_set( 1, B3);
	new_game_set( 1, B4);
	new_game_set( 1, B5);
	new_game_set( 1, B6);
	new_game_set( 1, B7);
	new_game_set( 1, B8);
	new_game_set( 1, B9);
	new_game_set( 1, B10);

	new_game_set( 1, "��ǰ��ֻλ��");

	set("att_rb", 999999);
	set("att_hp", 1);
	set("att_jf", 1);
	set("att_rs", 1);
	set("att_yq", 1);
	set("att_fd", 1);
	set("hp", 100);

	write(">>>>>>>  ������������ֻ������ϡ�\n");
	me->set_temp("hanghai_gameing", "waiting_go");
	write("\n============ ���óɹ������ڽ�����Ϸ���� ============\n");


	set("b1", YEL"��"NOR);
	set("b2", YEL"����"NOR);
	set("b3", YEL"�ʹ�"NOR);
	set("b4", CYN"����"NOR);
	set("b5", WHT"����"NOR);
	set("b6", WHT"Ȩ��"NOR);
	set("b7", RED"ʥ��"NOR);
	set("b8", CYN"ˮ��"NOR);
	set("b9", RED"����"NOR);
	set("b10",GRN"���"NOR);

	call_out("game_start", 1);
}

void new_game_set( int amount, string mark )
{
	int x, y;
// ����� x, y �� x�������ڼ��ᣬy�Ǻ����ڼ�����

	while( amount-- )
	{
		x = 1 + random(10);
		y = 1 + random(16);

		if( query( "aaa(" +x+ "," +y+ ")" ) )
		{
			amount ++;
			continue;
		}

		set( "aaa(" +x+ "," +y+ ")" , mark );
		if( mark == "��ǰ��ֻλ��" )
		{
			set("now_x", x);
			set("now_y", y);
		}
		if( mark == "����" )
			set("island("+x+","+y+")", "new" );

	}
	write( ">>>>>>>  " + mark + " ������ϡ�\n");
}

void game_start()
{
	object me = get_me();
	if( !me ) return del_me();

	me->set_temp("hanghai_gameing", "ok");
	message_vision("$N������ С����ʱ�� ��Ϸ��\n", me);

	write("\n**************************************
������Ϸ�ɹ�����ϷĿ��ΪѰ��10�����
�ƶ�ָ���� MUD ����ͬ��ף��Ϸ��죡
**************************************\n\n");

	map();
}


////////////////////////////////////
/////////  ��Ҳ�������  ///////////
////////////////////////////////////

int do_game(string arg)
{
	object me = this_player(), who;
	who = get_me();

	if( !who || me != who ) return 0;

	if( !arg || ( arg!= "check" && arg != "ck" && arg != "over") )
		return 0;

	if( !me->query_temp("hanghai_gameing") )
		return 0;

	if( arg == "check" || arg == "ck" )
	{
		map();
		return 1;
	}

	if( arg == "over" )
	{
		me->delete_temp("hanghai_gameing");
		message_vision("$N��;�������˳��� С����ʱ�� ��Ϸ��\n", me);
		write(HIR"\n  #########  ���˳���Ϸ��ףһ����죡 #########\n\n"NOR);
		remove_call_out("del_me");
		call_out("del_me", 1);
		return 1;
	}
	return 1;
}

int do_go(string arg)
{
	object me = this_player(), who;
	int x, y, old_x, old_y, i;

	string *dirs = ({
"north", "south", "west", "east", "northwest", "northeast", "southwest", "southeast", });

	string here, msg;

	who = get_me();
	if( !who || who != me ) return 0;
	if( member_array( arg , dirs ) == -1 ) return 0;

	if( me->query_temp("hanghai_gameing") != "ok" )
                return notify_fail("���ڲ����ƶ������ڣ� "+ game_now + " ��\n");

	x = query("now_x");
	y = query("now_y");

	old_x = x;
	old_y = y;

	switch( arg )
	{
		case "north": x--; break;
		case "south": x++; break;
		case "west" : y--; break;
		case "east" : y++; break;
		case "northwest" : x--; y--; break;
		case "northeast" : x--; y++; break;
		case "southwest" : x++; y--; break;
		case "southeast" : x++; y++; break;
	}

	if( x<1 || y<1 || x>10 || y>16 )
                return notify_fail("��������Ѿ��޷�ǰ���ˣ�\n");

	set("be_finded(" +old_x+ "," +old_y+ ")", 1); 


	if( query( "island(" +old_x+ "," +old_y+ ")" ) == "new"
	|| query( "island(" +old_x+ "," +old_y+ ")" ) == "old" )
	{
		set("island(" +old_x+ "," +old_y+ ")", "old");
		set("aaa("+old_x+","+old_y+")", "�ɵĵ���");
	}

	if( !query( "island(" +old_x+ "," +old_y+ ")" ) )
		delete("aaa(" +old_x+ "," +old_y+ ")" );

	here = query( "aaa(" +x+ "," +y+ ")" );

	set("aaa(" +x+ "," +y+ ")", "��ǰ��ֻλ��");
	set("now_x", x);
	set("now_y", y);

// �����жϣ�����

	if( here == "����" )
	{
		add("att_hp", 1);
		add("att_jf", 1);
		add("att_rs", 1);
		add("att_yq", 1);
		add("att_fd", 1);
		add("hp", 20+random(11));
		if( query("hp") > 100 ) set("hp", 100);
		map();
		write(HIG"��С����ʱ����  ���ֵ��죡�õ��˵�ҩ�����ʹ�ֻ����\n"NOR);
		return 1;
	}

	if( here == "����Ʒ" )
	{
		add("hp", 20+random(11));
		if( query("hp") > 100 ) set("hp", 100);
		map();
		write(HIC"��С����ʱ����  �����޲����ϣ���ֻ�õ�������\n"NOR);
		return 1;
	}

	if( here == "��ɽ" )
	{
		add("hp", - (30+random(11)));
		map();
		write(HIR"��С����ʱ����  ��⣡ײ���˱�ɽ�����ܵ������ص��𻵡�\n"NOR);
		check_hp();
		return 1;
	}

	if( here == B1 )
		return finded_baowu( 1, B1 );
	if( here == B2 )
		return finded_baowu( 2, B2 );
	if( here == B3 )
		return finded_baowu( 3, B3 );
	if( here == B4 )
		return finded_baowu( 4, B4 );
	if( here == B5 )
		return finded_baowu( 5, B5 );
	if( here == B6 )
		return finded_baowu( 6, B6 );
	if( here == B7 )
		return finded_baowu( 7, B7 );
	if( here == B8 )
		return finded_baowu( 8, B8 );
	if( here == B9 )
		return finded_baowu( 9, B9 );
	if( here == B10 )
		return finded_baowu( 10, B10 );


	if( here == "��Զ��" )
	{
		game_now = "������ ��ָ� liaowang x y��";
		map();
		write(HIM"��С����ʱ����  ��������Զ�������� (liaowang x y) ָ��鿴�õ��ܱߺ�������Σ� \n"NOR);
		me->set_temp("hanghai_gameing", "wangyuanjing");
		return 1;
	}

	if( here == "����̽����" )
	{
		map();
		write(HIM"��С����ʱ����  �����˱���̽���ǣ�\n"NOR);


		msg = HIM"\n������̽���С����Զ�̽�� "+x+","+y+" ����������\n\n";

		msg += get_msg( x-1,y-1, "bjy" );
		msg += get_msg( x-1,y,   "bjy" );
		msg += get_msg( x-1,y+1, "bjy" );
		msg += get_msg( x,  y-1, "bjy" );
		msg += 	get_msg( x,  y,   "bjy" );
		msg += 	get_msg( x,  y+1, "bjy" );
		msg += 	get_msg( x+1,y-1, "bjy" );
		msg += 	get_msg( x+1,y,   "bjy" );
		msg += 	get_msg( x+1,y+1, "bjy" );

		msg += "\n̽��Σ�����򱨾���ϡ�\n\n"NOR;
		write( msg );
		return 1;
	}

	if( here == "Ѱ��ͼ" )
	{
		map();
		write(HIC"��С����ʱ����  ������Ѱ��ͼ��\n"NOR);
		xunbaotu();
		return 1;
	}


	if( here == "������" || here == "������" || here == "���پ���"
	 || here == "��������" || here == "���鴬" )
	{
		game_now = "�� "+ here+ " ս���У� �ȴ����˹���";
		me->set_temp("hanghai_gameing", "fighting");
		att_now = "not_ok";
		map();
		write(HIR"��С����ʱ����  ��⣡������ "+ here+ " ���������ս��״̬������\n"NOR);
		set("who_name", here);
		remove_call_out("fight_start");
		call_out("fight_start", 1, here);
		return 1;
	}


	map();
	write(HIW"��С����ʱ����  �������̣�ʲôҲû�з��֡���\n"NOR);
	return 1;
}

void map()
{
	string the_map = HIC"��С����ʱ����  -- "HIR"HP��"+query("hp")+"  ���"+ query("be_finded")+NOR"\n\n        ", temp_map, temp2;
	int x, y, temp = 0;

	for( x=1; x<11; x++ )
	{
		for( y=1; y<17; y++ )
		{
			if( temp == 16 )
			{
				temp = 0;
				the_map += "\n        ";
			}

			temp2 = "("+x+","+y+")";

			if( query( "be_finded"+temp2) )
				temp_map = HIC"��"NOR;
			else if( query("weixian"+temp2) )
				temp_map = HIR"��"NOR;
			else temp_map = HIC"��"NOR;
			if( query( "aaa"+temp2 ) == "����" )
				temp_map = HIG"��"NOR;
			if( query( "aaa"+temp2 ) == "�ɵĵ���" )
				temp_map = HIG"��"NOR;
			if( query( "aaa"+temp2 ) == "��ǰ��ֻλ��" )
				temp_map = BLINK+HIY"��"NOR;

			the_map += temp_map;
			temp++;
		}
	}

	the_map += "\n\n";

//	for( temp = 1;temp<11;temp++)
//	{
//		set("b"+temp, HIW+query("b"+temp) );
//	}

	the_map += sprintf( "          %s  %s  %s  %s  %s
          %s  %s  %s  %s  %s\n\n",
		query("b1"), query("b2"), query("b3"), 
		query("b4"), query("b5"), query("b6"), 
		query("b7"), query("b8"), query("b9"), 
		query("b10") );

	the_map += sprintf(HIW"  �ⲫ֮��(rb)����  ����(hp)��%d  �޸�(jf)��  %d
  ����ɵ�(fd)��%d   ��ǹ(yq)��%d  ȼ�յ�(rs)��%d\n"NOR,
		query("att_hp"), query("att_jf"), 
		query("att_fd"), query("att_yq"), query("att_rs") );




	write( HIY"================================================\n"NOR +the_map +
HIY"================================================\n"NOR"��ǰλ�ã�("+ query("now_x") + "," + query("now_y") + ")  ���ڣ� "+ game_now +" \n");

}

void check_hp()
{
	object me = get_me();
	int x, y, temp = 0;
	string the_map, temp_map, temp2;

	if( !me ) call_out("del_me", 1);

	if( query("hp") > 0 ) return;

	the_map = HIR"\n��С����ʱ����  -- ʧ�ܽ������(��Ѱ��"+query("be_finded")+"������)\n\n        "NOR;

	for( x=1; x<11; x++ )
	{
		for( y=1; y<17; y++ )
		{
			if( temp == 16 )
			{
				temp = 0;
				the_map += "\n        ";
			}

			temp2 = query("aaa("+x+","+y+")");
			temp_map = HIC"��"NOR;

			if( temp2 == "������" )
				temp_map = HIR"��"NOR;
			if( temp2 == "��������" )
				temp_map = HIR"��"NOR;
			if( temp2 == "���پ���" )
				temp_map = HIR"��"NOR;
			if( temp2 == "������" )
				temp_map = HIR"��"NOR;
			if( temp2 == "���鴬" )
				temp_map = HIR"��"NOR;
			if( temp2 == "��ɽ" )
				temp_map = HIW"��"NOR;


			if( temp2 == "����" )
				temp_map = HIG"��"NOR;
			if( temp2 == "�ɵĵ���" )
				temp_map = HIG"��"NOR;
			if( temp2 == "��ǰ��ֻλ��" )
				temp_map = BLINK+HIB"��"NOR;

			if( temp2 == B1 || temp2 == B2 || temp2 == B3
			 || temp2 == B4 || temp2 == B5 || temp2 == B6
			 || temp2 == B7 || temp2 == B8 || temp2 == B9 || temp2 == B10 )
				temp_map = HIY"��"NOR;

			if( temp2 == "��Զ��" )
				temp_map = HIM"��"NOR;
			if( temp2 == "����̽����" )
				temp_map = HIM"��"NOR;
			if( temp2 == "����Ʒ" )
				temp_map = HIM"��"NOR;
			if( temp2 == "Ѱ��ͼ" )
				temp_map = HIM"ͼ"NOR;

			the_map += temp_map;
			temp++;
		}
	}

	the_map += "\n\n";

	write( the_map );
	me->delete_temp("hanghai_gameing");
	game_now = "�Ѿ�������";


	message_vision("$N��Ϸʧ�ܣ��˳��� С����ʱ�� ��Ϸ��\n", me);
	remove_call_out("game_over_over");
	call_out("game_over_over", 1);
	return;
}

void game_over_over()
{
	write(HIR"
=========================================
             ��С����ʱ����

      ��Ĵ�ֻ�𻵵���Ҳ�޷�֧�֣�
          ���ڳ����˴�֮�У�
=========================================
\n"NOR);
	remove_call_out("del_me");
	call_out("del_me", 1);
	return;
}

int do_liaowang( string arg )
{
	object me = this_player(), who;
	int x, y;
	string msg;

	who = get_me();
	if( !who || who != me ) return 0;

	if( me->query_temp("hanghai_gameing") != "wangyuanjing" )
		return 0;

	if( !arg || sscanf( arg, "%d %d", x, y ) != 2 )
                return notify_fail("��������ȷ���꣡x -> �������ڼ���  y -> �������ڼ���\n");
	if( x<1 || x>10 || y<1 || y>16 )
                return notify_fail("��������ȷ���꣡x -> �������ڼ���  y -> �������ڼ���\n");


	msg = HIM"�����С���������鿴 "+x+","+y+" ����������\n\n";

	msg += get_msg( x-1,y-1, "wyj" );
	msg += get_msg( x-1,y,   "wyj" );
	msg += get_msg( x-1,y+1, "wyj" );
	msg += get_msg( x,  y-1, "wyj" );
	msg += 	get_msg( x,  y,   "wyj" );
	msg += 	get_msg( x,  y+1, "wyj" );
	msg += 	get_msg( x+1,y-1, "wyj" );
	msg += 	get_msg( x+1,y,   "wyj" );
	msg += 	get_msg( x+1,y+1, "wyj" );

	msg += "\n�鿴��ϡ�\n\n"NOR;

	write( msg );
	me->set_temp("hanghai_gameing", "ok");
	game_now = "�ȴ��ƶ�����";
	return 1;
}

string get_msg( int x, int y, string type )
{
	string msg;

	if( x<1 || x>10 || y<1 || y>16 ) return "";

	msg = query("aaa(" +x+ "," +y+ ")" );

	if( !msg )
	{
		if( type == "wyj" ) return "("+x+","+y+") -----------\n";
		return "";
	}

	if( msg == "��ɽ" || msg == "������" || msg == "��������"
	 || msg == "���پ���" || msg == "������" || msg == "���鴬" )
	{
		set("weixian("+x+","+y+")", 1);
		if( type == "wyj" ) return "("+x+","+y+") " + msg + "\n";
		return "("+x+","+y+") ��Σ��Ǳ����\n";
	}

	if( type == "wyj" ) return "("+x+","+y+") " + msg + "\n";
	else return "";
}

void xunbaotu()
{
	int x, y;
	string msg;

	for( x = 1; x<11; x++ )
	{
		for( y=1;y<17;y++)
		{
			msg = query("aaa(" +x+ "," +y+ ")" );
			if( msg == B1 || msg == B2 || msg == B3 || msg == B4
			 || msg == B5 || msg == B6 || msg == B7 || msg == B8
			 || msg == B9 || msg == B10 )
			{
				write( HIM"("+x+","+y+")    �ô����б��أ�\n"NOR);
				return;
			}
		}
	}
}

void fight_start( string who )
{
	switch( who )
	{
		case "������": pic_target = "��";target_damage=2; break;
		case "��������": pic_target = "��"; target_damage=4; break;
		case "���پ���": pic_target = "��"; target_damage=6; break;
		case "������": pic_target = "��"; target_damage=8; break;
		case "���鴬": pic_target = "��"; target_damage=10; break;
	}

	target_hp = 50+ random(31);
	pic_me = "��";

	remove_call_out("be_attack");
	call_out("be_attack", 1);
}

void be_attack()
{
	int damage;
	string pic1, pic2;

	damage = target_damage + random(3);
	add("hp", -damage);

	pic1 = HIR + pic_target + " " + query("who_name") + "("+ target_hp + ")"NOR;
	pic2 = sprintf("    "HIG"(%|4d)������ "HIR"��"NOR, query("hp"), pic_me);

	write( sprintf("
                     _ _ _ _ _ _ _ _ _ _       ATTACK!
            "HIR"-%-2d"NOR"    /                     `"HIY"��"NOR"
%s                        %s
�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�\n\n", damage, pic2,  pic1));

	write(HIY"��С����ʱ����  �ܵ��� "+query("who_name")+ " �Ĺ�������ֻ�� "+ damage +" ��\n"NOR);
	check_hp();
	call_out("can_att", 1);
}

void can_att()
{
	if( query("hp") < 1 ) return;

	write(HIY"��С����ʱ����  �ֵ��㹥���ˣ�(atk ��ʽ)\n"NOR);
	write( sprintf(HIG"����ʣ�ࣺ    rb:����    hp:%d    jf:%d    rs:%d    yq:%d    fd:%d\n"NOR,
		query("att_hp"), query("att_jf"), query("att_rs"), query("att_yq"), query("att_fd") ) );
	game_now = "�� "+ query("who_name")+ " ս���У� �ȴ�����ָ��";
	att_now = "ok";
}

int do_attack(string arg)
{
	object me = this_player(), who;
	string target_name = query("who_name"), pic1, pic2, temp;
	int damage;

	who = get_me();
	if( !who || who!=me ) return 0;

        if( att_now != "ok" ) return notify_fail("���ڲ������㹥����ʱ��\n");
	if( !arg || ( arg != "rb" && arg != "hp" && arg != "jf" && arg != "rs"
	 && arg != "yq" && arg != "fd" ) )
		return notify_fail("��ѡ����������ԣ�\n");

	if( query("att_"+ arg ) < 1 ) return notify_fail("���������Ѿ�û���ˣ�\n");
	add( "att_"+ arg , -1 );

	switch( arg )
	{
		case "rb":  temp = "�ⲫ֮��"; damage = damage(1); break;
		case "hp":
			temp = "����";
			if( target_name == "������" ) damage = damage(5);
			if( target_name == "��������" ) damage = damage(4);
			if( target_name == "���پ���" ) damage = damage(3);
			if( target_name == "������" ) damage = damage(2);
			if( target_name == "���鴬" ) damage = damage(1);
			break;
		case "jf":
			temp = "�޸�";
			if( target_name == "������" ) damage = damage(4);
			if( target_name == "��������" ) damage = damage(1);
			if( target_name == "���پ���" ) damage = damage(5);
			if( target_name == "������" ) damage = damage(3);
			if( target_name == "���鴬" ) damage = damage(2);
			break;
		case "rs":
			temp = "ȼ�յ�";
			if( target_name == "������" ) damage = damage(2);
			if( target_name == "��������" ) damage = damage(3);
			if( target_name == "���پ���" ) damage = damage(4);
			if( target_name == "������" ) damage = damage(1);
			if( target_name == "���鴬" ) damage = damage(5);
			break;
		case "yq":
			temp = "��ǹ";
			if( target_name == "������" ) damage = damage(1);
			if( target_name == "��������" ) damage = damage(5);
			if( target_name == "���پ���" ) damage = damage(2);
			if( target_name == "������" ) damage = damage(4);
			if( target_name == "���鴬" ) damage = damage(3);
			break;
		case "fd":
			temp = "����ɵ�";
			if( target_name == "������" ) damage = damage(3);
			if( target_name == "��������" ) damage = damage(2);
			if( target_name == "���پ���" ) damage = damage(1);
			if( target_name == "������" ) damage = damage(5);
			if( target_name == "���鴬" ) damage = damage(4);
			break;
	}

	target_hp -= damage;
	add("score", damage);

	pic1 = HIR"��" + " " + query("who_name") + "("+ target_hp + ")"NOR;
	pic2 = sprintf("    "HIG"(%|4d)������ %s"NOR, query("hp"), pic_me);


	write( sprintf("
       %|8s��    _ _ _ _ _ _ _ _ _ _
                   "HIY"��"NOR"                     \\    "HIR"-%d"NOR"
%s                        %s
�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�\n\n", temp,damage, pic2,  pic1));

	write(HIY"��С����ʱ����  ʹ�� "+ temp+ " �� "+query("who_name")+ " ���й������𺦶Է�  "+ damage +" ��\n"NOR);

	att_now = "not_ok";
	remove_call_out("target_check_hp");
	call_out("target_check_hp", 1);

	return 1;
}

void target_check_hp()
{
	object me = get_me();
	if( !me )
	{
		remove_call_out("del_me");
		call_out("del_me", 1);
		return;
	}

	if( target_hp < 1 )
	{
		game_now = "�ȴ��ƶ�����";
		add("hp", 1+(random(5)) );
		if( query("hp") > 100 ) set("hp", 100);
		map();
		write(HIG"\n��С����ʱ����  ����� "+query("who_name")+ " ������������Ĳ��������������ɣ�\n\n"NOR);
		me->set_temp("hanghai_gameing", "ok");
		add("score", 100);
		return;
	}

	be_attack();
}

