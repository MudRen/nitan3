/*****************************************************************************\
**                                                                           **
**  p9.c  ���ƾ�  ϵͳ��ׯ & ��һ��� �ۺϰ�                                 **
**        �ɶĴ�С�ƾţ�����ϵͳ��ׯ�������ׯ����߿� 8 ��ͬ��            **
**  by naihe 2004-3~4 �㶫ï��  �������������                               **
**                                                                           **
**  д��ʱ��ο��� p9room.c (by kafei)������������⣬������ǣ�������ǣ�   **
**  �κ�ʮ�������������Լ��������ͣ����޷��õ��κν�������������Լ��ķ�ʽ�� **
**  ������������ġ���ǳ��¶�ķ�ʽȥд��                                   **
**  ��Ȼ���������ʽд�ģ���Ҫ�޸Ĺ�������ʱ����Ҳ���ʮ�ֵļ��ˣ�����   **
**  ����ο���ǣ����Ĳ��ֵĴ����Ȼ�����������е���ô������������Ϸд�ú���   **
**  ������ȴ��д֮ǰ���ϲ������ˣ�                                           **
**                                                                           **
**  P.S:                                                                     **
**  �������ֵȣ����ݸ��˾��顢�������ϵ���Դ�������������������и�����   **
**  ������Ÿ�֪�κΣ� lovesb@21cn.com  ||  lonely@163.com(����֪ͨ)         **
**                QQ:  107507                                                **
**                                                                           **
**  zmud ���壺 ���� С��(12)/С��(10)                                       **
**                                                                           **
**  ���ڱ���Ϸ�Ľ��� / ��ע��                                                **
**      �����������ʷ�ƾõ�MUD���Ǯ�ѷ��ĳ��֣�������exp�ȣ�             **
**      Ҳ�Ѿ����������������׷����ˡ���������Ĳ���Ϸ�Ķ�ע               **
**      ʮ���ر𣬲�ʹ�ô�ͳ�ĶĽ����֮��ľɷ�����������                   **
**      �����ֽ������ķ�ʽ������MUD�Լ����»��ֶһ��Ĺ��򣬶�                **
**      �����Ϸ����������ϵͳ��ׯ��������һ�������Ϸ����ֻ               **
**      ���ԡ����֡����С�                                                   **
**      ����� GAME_SCORE_DATA �Ķ��壬���н����ļ������緿����NPC��cmds���� **
**      �����жһ��������������ò�����ǣ����ֵ��Ĭ�϶�����:                **
**              "naihe_game_data/game_score"                                 **
**      �����ԣ��κ���д�ĺͽ�д�ĸ�����78��С��Ϸ��������������淶��       **
**      ��Ȼ����Ҳ���Խ����ֵ��Ϊ��balance��֮��ģ�Ҳ��ֱ���Դ������ˣ�  **
**                                                                           **
**       ���ƾţ��й��˵Ķļ���������ʵ����˫�ؿ��飡(С�ƾź����ġ���)      **
**                                                                           **
\*****************************************************************************/

// �Σ����ĵػ��˸�����֮�󣬾�Ȼ������������ˣ� :)
// û�� ctime_new() ������MUD����ȡ����һ�е�ע�ͣ�
// string ctime_new() { return ctime(time()); }

#include <ansi.h>

// ------------------------------ �ɸ���֮���� ------------------------------

#define		GAME_ON			1		// ��Ϸ�Ƿ񿪷�
#define		GAME_NAME		"���ƾ� �ۺϰ�"	// ����Ϸ����
#define		GAME_VERSION		"V1.5"		// �汾�������Լ��鿴
#define		LOG_ON			1		// �Ƿ� log
#define		LOG_FILE_NAME		"p9_log"	// log �ļ�λ��

#define		GAME_SCORE_DATA		"naihe_game_data/game_score"
							// ���ּ�¼����� dbase ��
#define		GAME_SCORE_NAME		"��Ϸ��"	// ����
#define		BET_MIN			1		// ��СѺע
#define		BET_MAX			1000		// ���Ѻע
#define		WAIT_TIME_JOIN		20		// ��Ϸ׼����ʼ���ȴ�һ��ʱ�������Ҽ���
#define		WAIT_TIME_LINEUP	90		// ���ƾ�ʱ����һ����ʱ�����ҽ������У����飩
#define		WAIT_TIME_NEXTPAIR	15		// ���ƾ�ʱ��һ��ʱ�������ŵ���
#define		SYSTEM_SCORE		99999		// ϵͳ���֣������֮��ǿ��ֹͣ��ϵͳ��ׯ�Ķľ�
							// ��Ϊ�������������Ծ���ȷ��������������е����ò�����
							//     ���������ǻ�����Ҵ���Ӯ�û��֣���ô��ʱ����Ҫ
							//     ǿ��ֹͣ��ϵͳ��ׯ���Ա���Խ��Խ�
							// ���ֵ�������� 0 ����ϵͳ����ׯ��������һ�����Ϸ��
							// ����������� dvunix(211.91.166.197:2008) ���������ӵġ�

#define		IsTest			0		// 1 ����״̬��������ʱ�����Щ��ĳЩ�ط�����һ�£�
							// �� "naihe" �����ľ�ʱ�����ϴ�����ʱ�������
#define		ChannelColor		HIM		// Ƶ����ɫ������
#define		StartGameBusy		60

// --------------------------------------------------------------------------



// ���������ĸ�ʽ ctime()��������ʲô Sun Apr 27 00:44:44 2003 ֮��
// �� ctime() ........ ��ԶŪ����Ӣ�����ڡ��·ݴ�׳� �κ� ���׸�
// ����ͬ������ ............

// by naihe 2003-04-29
// �ı���һ�²����ĺ��壬����ǰ���޷����ݡ���tnnd
// by naihe 2004-03-24

string ctime_new( int arguments, int type )
{
        string msg, *temp;
        mapping to_cn_month, to_cn_week;
        int temp_xxx;

        to_cn_month = ([ "Jan":" 1��", "Feb":" 2��", "Mar":" 3��", "Apr":" 4��",
                         "May":" 5��", "Jun":" 6��", "Jul":" 7��", "Aug":" 8��", 
                         "Sep":" 9��", "Oct":"10��", "Nov":"11��", "Dec":"12��", ]);

        to_cn_week = ([ "Mon":"����һ", "Tue":"���ڶ�", "Wed":"������", "Thu":"������",
                        "Fri":"������", "Sat":"������", "Sun":"������", ]);

// 1���޲���
// 2��ָ����һ�������ò���Ϊʱ�����    ���磺 ctime_new(1058076012);
// 3��˫������˳����ȷ                  ���磺 ctime_new(1058076012, 1);

// ����3���������ȷ�ġ�������������Ҫ���о���

// 4��ָ����һ�������ò���Ϊ��Ϣ��ʽ�Ĳ���      ���磺ctime_new(1); ctime_new(2); ��
//    ����Ϊ�� ʱ����õ�ǰʱ�䣬��ʽ����ָ������ʽ
// 5��˫������˳����ȷ                ���磺 ctime_new(1,1058076012); ctime_new(0,1058076012);
//    ֮ǰ��д�� ctime_new.c ���������ʽ�ģ����ԡ���Ϊ�����Ŀ��ǲ��ܱ�����
//    ����Ϊ��λ�û���


// �޲�����ʱ��Ĭ�ϵ�ǰʱ�䣬����������Ϣ�ִ�
        if( !type && !arguments )
        {
                arguments = time();
                type = 8;
        }
// ǿ�������� // add by naihe 2003-07-13

// ��ʱ�����û�У��������Ǹ���С�����֣���ô����ζ�Ų��������˴����ˡ�
        if( !arguments || arguments < 3153600 )  // ���������һ��Ĵ����������
        {
                if( !type || type < 3153600 )  // �����  4  �������������OK :)
                {
                        type = arguments;
                        arguments = time();
                }
                else            // ����ֻ������λ�û����ˡ� ������OK :)
                {
                        temp_xxx = type;
                        type = arguments;
                        arguments = temp_xxx;
                }
        }

// �����ǿ�Ʋ���������ᱨBUG��������Ը����BUG��
        if( !arguments ) arguments = time();

        msg = efun::ctime( arguments );
        if( !msg ) return 0;

        temp = explode( msg , " ");

// ����ط�ԭ�����벻�������еĵط��� ctime(time()) return
// �Ķ�����ʽ���ԣ�����ǵ������� 1�գ�2�գ�����һ���ո�
// ������ô�� explode ֮�󣬾͵õ� sizeof() = 6 �� array��
// ���ҵĻ����ϣ�ctime(time()) ��������������Ϊ�� 01, 02
// �ȡ��ΰɣ�
// Ϊ�˰�ȫ��ȫ�ٰ�ȫ���������һ��Ԫ�أ����� " " ��ɾ����

        temp -= ({ "", " " });

        if( sizeof( temp ) != 5 ) return 0;

        switch( type )
        {
// ���ڼ�ʱ��		"2003�� 4��30�� 01:50:56"

                case 1 : return sprintf("%s��%s%s�� %s",
        temp[4], to_cn_month[ temp[1] ], temp[2], temp[3] );

// ������		"2003�� 4��30��"

                case 2 : return sprintf("%s��%s%s��",
        temp[4], to_cn_month[ temp[1] ], temp[2] );

// ���ڼ�����		"2003�� 4��30�� ������"

                case 3 : return sprintf("%s��%s%s�� %s",
        temp[4], to_cn_month[ temp[1] ], temp[2], to_cn_week[ temp[0] ] );
        }

// �������󣬻�ʡ���˸ò����Ļ�������������Ϣ
//      "2003�� 4��30�� 01:50:56 ������"

        return sprintf("%s��%s%s�� %s %s", temp[4], to_cn_month[ temp[1] ],
                         temp[2], temp[3], to_cn_week[ temp[0] ] );
}

int system_score;	// һ���򵥵ı��������ò��������¶��Ӻ���Ļ��ơ�

protected void game_log( string msg )
{
	if( !LOG_ON || !msg )
		return;

	log_file( LOG_FILE_NAME, msg );
}

void create()
{
        /*
	game_log( sprintf(
	"\n--------------------------------------------------------------------------------------------\n"
        "    �ƾŶľ��ļ��ڱ����룬�ָ�Ԥ��ϵͳ���� %d �㡣\n"
	"--------------------------------------------------------------------------------------------\n",
                SYSTEM_SCORE ));
        */
	system_score = SYSTEM_SCORE;
}

varargs int help()
{
	string msg;

	msg = "--------------------------------------------------------
"BGRN+HIY"                    [ �� �� �� �� ]�������������������� "NOR"
--------------------------------------------------------

    �ƾ���Դ���й��Ĺ�����Ϸ��Ҳ�������������ʸУ��ƾ�Ҳ
�׳ơ����ơ����������ѽ��ͣ�������һ��ʮ����Ҫ��������
������ս���ĶĲ���Ϸ���ܵ���˵��һ���ƾŹ��� 32 ���ƣ���
��С����֮�֣�����ϰ���ϣ��� 32 �����ֱ���Ϊ�������࣬һ
�ࡰ���ӡ���һ�ࡰ���ӡ���\n";

	msg += "
    ���ӹ� 11 �ԣ�ÿ�� 2 ��������С�������£� 
"HIY"�졢�ء��ˡ��͡�÷������������ʡ���ͷ����ͷ������������"NOR"

    ���ӱ�����С���� 4 �Լ����������ƣ�����С�������£�
"HIY"�Ӿš��Ӱˡ����ߡ���ͷ�����塢����"NOR"

    ���ӡ��ֵ��Ӹ�һ�ԣ��� [��ͷ] �� [����] ������Ķ��ӣ�
��������������Щ���ƽз�������������ͬ��Ϊ�˷��㣬�����
�����������������ơ�����������ָ�<"HIY"p9 showcards"NOR">  �鿴
���е�ͼ��ʾ����\n";

	msg += "
    ���ƾ�ʱ���������ƣ�һ�飩Ϊ������λ��ׯ��֮���໥��
�϶�����Ӯ���������ƿ��ܿ������һЩ�����ӡ�������ܺ���
��ϵ����Ȼ������ɡ����ӡ���һ����Ҫ�Ȳ�����ɵġ�ɢ�ơ�
�󡣵���˫�����ƶ��ǡ�ɢ�ơ�������Խ��������ϵĵ�����ӣ�
��ȡ����֮�͵ĸ�λ����Ƚϣ�����Ϊʤ��\n";

	msg += "
    �����ɴ�С�������£�
"HIY"����"NOR"  --------   [��ͷ] + [����]
"HIY"˫�챦"NOR"  --------   ���� [��] ����ͬ���ԣ�
"HIY"˫�ر���˫�˱���˫�ͱ���÷���ԡ������ԡ���ʶԡ���ͷ�ԡ�
"HIY"��ͷ�ԡ������ԡ�����ԡ��ӾŶԡ��Ӱ˶ԡ����߶ԡ�����ԡ�
"HIY"����"NOR"    --------   [��]   + [�Ӿ�]
"HIY"����"NOR"    --------   [��]   + [�Ӿ�]
"HIY"���"NOR"    --------   [��]   + [��] �� [�Ӱ�]
"HIY"�ظ�"NOR"    --------   [��]   + [��] �� [�Ӱ�]\n"NOR;

	msg += "
    ����������鲻������������һ�ԣ�������ɢ�ơ���ɢ����
���Ǿŵ㣬��С����㡪���׳ơ���ʮ�����֣����˫�����Ƶ�
����ͬ�����ǵ���ͬ������Ƚ�������һ���ƣ��������ͬ����
������Ƚ�ʣ�µ�һ���ƣ�������ͬ������ׯ��ʤ�����磺

��+���  ��  ��+���  ��  ���� ���㣬ǰ�� [��]   ��ʤ��
��+����  ��  ��+����  ��  ���� �ŵ㣬ǰ�� [����] ��ʤ��
��+��    ��  ��+�Ӱ�  ��  ���� ��ܣ�ǰ�� [��]   ��ʤ��
��+��    ��  ��+��    ��  ��ȫһ���� ׯ��ʤ��\n";

	msg += "
    ���ƾ��������׶����淨��һ�����ƾš���һ��С�ƾš���
�ĵ��ǡ����ƾš���ʱ��ÿ��ȡ�����ƣ��������Լ������⽫
���Ϊ���飬���������š��������š������ƺ��Ⱥ�Ƚϣ�����
��ʤ��Ӯ�øþ֡��ġ����ƾš����ܳ���һ����ʤ��һ���Ƹ���
���Σ����;֡�
    ���ġ�С�ƾš�ʱ�ֲ�ͬ��ÿ��ֻȡ�����ƣ����ط��飬һ
���ƾͼ�ʤ����С�ƾ����׳ơ�һ�������ۡ�������ȡ����ȫ��
���Լ����ƣ�ȫƾ��������˼������С�ƾž��޺;֣�����Ҳ
����Ĵ̼���\n";

	msg += sprintf(
"--------------------------------------------------------
"BGRN+HIY"         [ %s(%s) ����Ϸ���� ]             "NOR"
--------------------------------------------------------\n", GAME_NAME, GAME_VERSION);

	msg += "
    �����Ϸ����������ǽ�����ͬ�������ƾŶľ֡���������
�˵�ϲ�ã�������ѡ���Լ���ׯ�����ɵ�����ׯ�������ѡ���
���ƾŻ�С�ƾţ������Ҫ��ׯ�Ļ������������ý��ܶ�ע�Ķ�
�ȡ����ò������������Ƶȵȡ���һ�У�����������������Ϸ��
ʼ��ָ�<"HIY"p9 new"NOR">֮�󣬻����ϸ����ʾ˵������ֻҪ������
ʾ�򵥵ؽ���һЩ���ã��Ϳ������ɵؿ�ʼ�ľ��ˡ�

    ��Ϸ����ϸָ����ܣ����������룺<"HIY"p9 help cmds"NOR"> ��ѯ��
    �����Ϸ�ṫ��һЩ��������Ϣ������������ᷳ�������룺
      <"HIY"p9 set no_p9_msg"NOR">  ��ô���������ٽӵ���Щ��Ϣ��

                                 By �κ�(naihe) 2004-04
--------------------------------------------------------\n";

	this_player()->start_more( msg );

	write( "
    ���ƾ� ��Ϸ����ͼ

   �� <- - - - -<- - - - -<- - - - -<- - - - -  ��
   ��                                           ��
   ��                          ��> û����Ҽ��� ��
 �޶ľ� -> ��ʼ -> �ȴ���Ҽ����                          ��> ���ƾţ���ҽ��Ʒֳ����驴
   ��                          ��> ����Ҽ��� -> ��ʼ�����Ʃ�                          ��
   ��                                                      ��> С�ƾţ���              ��
   ��                                                                  ��              ��
   �� <- - - - -<- - - - -<- - - - -<- - - - -<- - - - -<- -  ��ׯ�ȴ�С������÷� ������\n");

	return 1;
}

// ###################################################################
//      ################### �� �� �� �� �� �� ###################
//          #################################################

// ������Щֵ��Ӧ���� #define �ģ����� #define ֵ���ܻ��У��������ң������ˡ�
// �������ֻ����ô�д~

	// �����ƵĻ���˳��������ģ���������������б�������Ӧλ�á�ֵ��
string		*P9_BASE = ({
	"tian1","tian2","di1","di2","ren1","ren2","he1","he2", 
	"mh1","mh2","cs1","cs2","bd1","bd2","ft1","ft2",
	"ht1","ht2","161","162","151","152", 
	"91","92","81","82","71","72","6","51","52","3",
	});

	// ÿ���Ƶ���ʱ�����ƣ�˳������ P9_BASE ��Ӧ
string		*P9_NAME = ({
	"��", "��", "��", "��", "��", "��", "��", "��",
	"÷��", "÷��", "����", "����", "���", "���", "��ͷ", "��ͷ",
	"��ͷ", "��ͷ", "����", "����", "����", "����",
	 "�Ӿ�", "�Ӿ�", "�Ӱ�", "�Ӱ�", "����", "����", "��ͷ", "����", "����", "����",
	});

	// ÿ�����ϵĵ�����˳������ P9_BASE ��Ӧ
int		*P9_AMOUNT = ({
	12, 12, 2, 2, 8, 8, 4, 4,
	10, 10, 6, 6, 4, 4, 11, 11,
	10, 10, 7, 7, 6, 6, 
	9, 9, 8, 8, 7, 7, 6, 5, 5, 3,
	});

	// ÿ���ƵĴ�С�ж�ֵ�����ɶ�ʱ���ж�ֵ��˳������ P9_BASE ��Ӧ
	// Ҳ����˵�������Ҫ����ĳ�ֶ��ӡ���ĳ�ӵĴ�С���ڴ˶�Ӧ���ļ���
int		*P9_VALUE = ({
	99, 99, 88, 88, 77, 77, 66, 66,
	49, 49, 48, 48, 47, 47, 46, 46,
	45, 45, 44, 44, 43, 43,
	39, 39, 38, 38, 37, 37, 36, 35, 35, 34,
	});

	// ������ӵĴ�С�ж�ֵ
	// ����������ӵ��жϣ���ο� get_value() ����
mapping		SPECIAL_VALUE = ([
	"TianWang"	: 10,
	"DiWang"	: 9,
	"TianGang"	: 8,
	"DiGang"	: 7,
	]);

	// ���ӵ����ƣ�key ���� P9_VALUE ��Ӧ
mapping		PAIR_NAME = ([
	999:"����", 99:"˫�챦", 88:"˫�ر�", 77:"˫�˱�", 66:"˫�ͱ�",
	49:"÷����", 48:"������", 47:"��ʶ�", 46:"��ͷ��",
	45:"��ͷ��", 44:"������", 43:"�����",
	39:"�ӾŶ�", 38:"�Ӱ˶�", 37:"���߶�",
	36:"�����ˣ�û������������", 35:"�����", 34:"�����ˣ�û������������",

	//===== ������ӵ� key ���� SPECIAL_VALUE ͬ�� =====//
	10:"����", 9:"����", 8:"���", 7:"�ظ�",
	]);

	// key ���� P9_BASE Ԫ�ض�Ӧ��˳����
mapping		P9_PIC = ([
	"none"	: ({ "      "," /    ","      ","      ","    / ","      ", }),
// ����ͼ��
	"tian1" : ({ "��  ��","��  ��","��  ��","��  ��","��  ��","��  ��", }),
	"tian2" : ({ "��  ��","��  ��","��  ��","��  ��","��  ��","��  ��", }),
	"di1"	: ({ "  ��  ","      ","      ","      ","      ","  ��  ", }),
	"di2"	: ({ "  ��  ","      ","      ","      ","      ","  ��  ", }),
	"ren1"	: ({ "      ","��  ��","��  ��","��  ��","��  ��","      ", }),
	"ren2"	: ({ "      ","��  ��","��  ��","��  ��","��  ��","      ", }),
	"he1"	: ({ "  ��  ","      ","      ","    ��","  ��  ","��    ", }),
	"he2"	: ({ "  ��  ","      ","      ","    ��","  ��  ","��    ", }),
	"mh1"	: ({ "��  ��","  ��  ","��  ��","��  ��","  ��  ","��  ��", }),
	"mh2"	: ({ "��  ��","  ��  ","��  ��","��  ��","  ��  ","��  ��", }),
	"cs1"	: ({ "      ","  ��  ","  ��  ","��  ��","  ��  ","  ��  ", }),
	"cs2"	: ({ "      ","  ��  ","  ��  ","��  ��","  ��  ","  ��  ", }),
	"bd1"	: ({ "��  ��","      ","      ","      ","      ","��  ��", }),
	"bd2"	: ({ "��  ��","      ","      ","      ","      ","��  ��", }),
	"ft1"	: ({ "��  ��","  ��  ","��  ��","��  ��","��  ��","��  ��", }),
	"ft2"	: ({ "��  ��","  ��  ","��  ��","��  ��","��  ��","��  ��", }),
	"ht1"	: ({ "��  ��","��  ��","      ","��  ��","��  ��","��  ��", }),
	"ht2"	: ({ "��  ��","��  ��","      ","��  ��","��  ��","��  ��", }),
	"161"	: ({ "  ��  ","      ","      ","��  ��","��  ��","��  ��", }),
	"162"	: ({ "  ��  ","      ","      ","��  ��","��  ��","��  ��", }),
	"151"	: ({ "  ��  ","      ","      ","��  ��","  ��  ","��  ��", }),
	"152"	: ({ "  ��  ","      ","      ","��  ��","  ��  ","��  ��", }),
// ����ͼ��
	"91"	: ({ "    ��","  ��  ","��    ","��  ��","��  ��","��  ��", }),
	"92"	: ({ "��  ��","��  ��","      ","��  ��","  ��  ","��  ��", }),
	"81"	: ({ "    ��","  ��  ","��    ","��  ��","  ��  ","��  ��", }),
	"82"	: ({ "��  ��","      ","      ","��  ��","��  ��","��  ��", }),
	"71"	: ({ "��  ��","      ","      ","��  ��","  ��  ","��  ��", }),
	"72"	: ({ "    ��","  ��  ","��    ","��  ��","      ","��  ��", }),
	"6"	: ({ "��  ��","      ","      ","��  ��","      ","��  ��", }),
	"51"	: ({ "��  ��","      ","      ","    ��","  ��  ","��    ", }),
	"52"	: ({ "  ��  ","      ","      ","��  ��","      ","��  ��", }),
	"3"	: ({ "  ��  ","      ","      ","      ","      ","��  ��", }),
	]);

// ---------------------------------------------------------------------------------

// ����ƾź���ϵͳ�ĺ���
protected int			*get_value( string p1, string p2 );
protected string			get_cname( int *v );
protected int			which_one_is_bigger( int *v1, int *v2 );
protected varargs string		get_pic( string *card, int type, int need_name );
protected string			*get_random_all_cards();
protected varargs string		get_show_all_msg( string *v, int need_name );
protected string			*lineup( string *p );
protected string			*system_AI( string *p );


// ���������ƣ��������ǵġ���ֵ�������жϴ�С�����ݣ�
protected int *get_value( string p1, string p2 )
{
	int	pair_value, amount_value, big_value, small_value,
		p1_value, p2_value, p1_amount, p2_amount, t1, t2;

	// ���أ� int*
	// ({ ���ӵļ�ֵ���������ĵ��������Ƶļ�ֵ��С�Ƶļ�ֵ })

	t1 = member_array( p1, P9_BASE );	// ��� p1 �� P9_BASE ���λ��
	t2 = member_array( p2, P9_BASE );	// p2

	if( t1 == -1 || t2 == -1 )
		return 0;			// �����������

	p1_value = P9_VALUE[ t1 ];		// ��һ���Ƶļ�ֵ
	p2_value = P9_VALUE[ t2 ];		// �ڶ����Ƶļ�ֵ

	if( p1_value > p2_value )
	{
		big_value = p1_value;
		small_value = p2_value;
	}
	else
	{
		big_value = p2_value;
		small_value = p1_value;
	}

	p1_amount = P9_AMOUNT[ t1 ];
	p2_amount = P9_AMOUNT[ t2 ];

	amount_value = (p1_amount + p2_amount) % 10;

	// ������Ϊ���ӵļ�ֵ

	// ����
	if( (p1 == "3" && p2 == "6") || (p2 == "3" && p1 == "6") )
		pair_value = 999;

	// ���߼�ֵ��ͬ���Ķ���
	if( p1_value == p2_value )
		pair_value = p1_value;

	// ���ǵĻ����Ƿ��������
	if( !pair_value )
	{
		// ���⣺����
		if( (p1_amount == 12 && p2_amount == 9 )
		 || (p2_amount == 12 && p1_amount == 9 ) )
			pair_value = SPECIAL_VALUE[ "TianWang" ];
		// ���⣺����
		if( (p1_amount == 2 && p2_amount == 9 )
		 || (p2_amount == 2 && p1_amount == 9 ) )
			pair_value = SPECIAL_VALUE[ "DiWang" ];
		// ���⣺���
		if( (p1_amount == 12 && p2_amount == 8 )
		 || (p2_amount == 12 && p1_amount == 8 ) )
			pair_value = SPECIAL_VALUE[ "TianGang" ];
		// ���⣺�ظ�
		if( (p1_amount == 2 && p2_amount == 8 )
		 || (p2_amount == 2 && p1_amount == 8 ) )
			pair_value = SPECIAL_VALUE[ "DiGang" ];
	}
	return ({ pair_value, amount_value, big_value, small_value, });
}

// ���� get_value() ���ص�ֵ��ȡ���������Ƶĳƺ�
protected string get_cname( int *v )
{
	if( !v || sizeof(v) != 4 )
		return "----";

	if( !v[0] )	// �Ƕ���
	{
		if( !v[1] )
			return "��ʮ";
		return chinese_number(v[1])+"��";
	}

	if( undefinedp( PAIR_NAME[ v[0] ] ) )
		return "----";
	return PAIR_NAME[ v[0] ];
}

// �������� get_value() ���ص�ֵ���ж���ֵ�Ĵ�С
// ֵ1�󷵻�1��ֵ2�󷵻�2����ͷ���3��
protected int which_one_is_bigger( int *v1, int *v2 )
{
	int i;

	if( !v1 || !v2 || sizeof(v1) != 4 || sizeof(v2) != 4 )
		return 0;

	// �ȴ�С���� ���ӡ����������ƱȽϡ�С�ƱȽ�
	// ���ڡ�ԭ�򡱿�����������������ȥ��
	// �����׹������ң����Ƕ࿴�� help ��
	for( i=0; i<4; i++ )
	{
		if( v1[i] > v2[i] )
			return 1;
		else if( v1[i] < v2[i] )
			return 2;
	}
	return 3;
}

// �õ���ʾ����Ļ����ִ�
// ��֧�� 1-8 ���ƣ�����һ����Ļ�Ų��£��еĳ��Ȳ����������ң�
protected varargs string get_pic( string *card, int type, int need_name )
{
	// type 0: �޿�϶
	// type 1: �����Ƽ��п�϶
	// type 2: �ĸ��Ƽ��п�϶

	string msg = "";
	int i, j, size;

	if( !card || (size = sizeof(card)) > 8 )
		return "ֻ����ʾ 1-8 ���ƣ�\n";

	// ����ͷ��
	for( i=1;i<=size;i++ )
	{
		msg += "����������";
		switch( type )
		{
			case 1: if( i%2 == 0 )
					msg += "      ";
				break;
			case 2:	if( i%4 == 0 )
					msg += "      ";
				break;
		}
	}
	msg += "\n";

	// ���м�
	for( i=0;i<6;i++ )
	{
		for( j=0;j<size;j++ )
		{
			msg += sprintf( "��%s��", P9_PIC[card[j]][i] );
			switch( type )
			{
				case 1:	if( (j+1)%2 == 0 )
						msg += "      ";
					break;
				case 2:	if( (j+1)%4 == 0 )
						msg += "      ";
					break;
			}
		}
		msg += "\n";
	}
	//���ﲻ�� msg+="\n" ����������  -_-"

	// ��β
	for( i=1;i<=size;i++ )
	{
		msg += "����������";
		switch( type )
		{
			case 1:	if( i%2 == 0 )
					msg += "      ";
				break;
			case 2:	if( i%4 == 0 )
					msg += "      ";
				break;
		}
	}
	msg += "\n";

	// �������Ҫ���֣����
	if( !need_name )
		return msg;

	// �������������ʾ
	for( i=0;i<size;i++ )
	{
		if( member_array(card[i], P9_BASE) < 0 )
			msg += "          ";
		else 
			msg += sprintf( " [%|6s] ", P9_NAME[ member_array(card[i], P9_BASE) ] );
		switch( type )
		{
			case 1:	if( (i+1)%2 == 0 )
					msg += "      ";
				break;
			case 2:	if( (i+1)%4 == 0 )
					msg += "      ";
				break;
		}
	}
	msg += "\n";

	return msg;
}

// �õ�һ����������ƣ�����ÿ�ֿ���ǰ��ϴ�ơ���
protected string *get_random_all_cards()
{
	string t, *p1, *p2;
	int i;
	p1 = copy(P9_BASE);
	p2 = allocate(32);
	for( i=31; i>=0; i-- )
	{
		t = p1[ random(i+1) ];
		p1 -= ({ t });
		p2[i] = t;
	}
	return p2;
}

// �г������Ƶ�ͼ������ѡ����"need_name"������ֵʱ�������±����Ƶ���������
protected varargs string get_show_all_msg( string *v, int need_name )
{
	string msg = "";
	int i;

	if( !v || sizeof(v) != 32 )
		return "����Ĳ������������޷����ͼ����ʾ��\n";

	for( i=0;i<4;i++ )
	{
		msg += get_pic( v[i*8..(i+1)*8-1], 2, need_name );
	}
	return msg;
}

// ������������һ�£������ǰ��С���ں�  ����  �ء��죬���ų� �졢�� ���أ�
// ����Ӱ������ƵĴ�С��
protected string *lineup( string *p )
{
	int t1, t2;

	if( !p || sizeof(p) != 2 )
		return p;
	t1 = member_array( p[0], P9_BASE );	// ��� p1 �� P9_BASE ���λ��
	t2 = member_array( p[1], P9_BASE );	// p2
	if( t1 == -1 || t2 == -1 )
		return p;			// �����������

	if( P9_VALUE[t2] > P9_VALUE[t1] )
		return ({ p[1], p[0] });
	return p;
}

// ------------------ ����ϵͳ������ -------------------
// ���ڶĴ��ƾţ�����ϵͳ��ׯʱ��
// ����һ�� sizeof(4) �� string* ������ͬ����С�ġ�
// ������ϵͳ��4���Ʒ�Ϊ�����ʺϡ������飬������
// ˭��д����ǿ�ķ�����ѽ������ֱ������ô��ƴ�ͬ����ģ�
// ��������  naihe 04-4-1
// -----------------------------------------------------
protected string *system_AI( string *p )
{
	mapping card_case, values;
	int i, j, k;
	string *t;
	if( !p || sizeof(p) != 4 )
		return p;
	// 3��������ÿ�������ֿ�ͷβ��ת��ʵ�� 6 ����������
	card_case = ([
		"c1" : p,
		"c2" : ({ p[0],p[2],p[1],p[3], }),
		"c3" : ({ p[0],p[3],p[1],p[2], }),
	]);
	// ԭ�򣺲���Ӯ������͡��������������ӣ���Ӯһ����˵��
	// 1������Ȼ���ӣ�ȡ��Ȼ���ӣ�ʣ��������һ��
	// 2������Ȼ���ӣ�ȡ������ӣ�ʣ��������һ��
	// 3�����κζ��ӣ�ȡ������ϣ�ʣ��������һ��
	// 4���������ʱ������ô��ƴ�������bite
	// 5�������Ƿֱ������
	values = ([ ]);
	for( i=1;i<6;i+=2 )
	{
		j = (i+1)/2;
		t = card_case[ "c" + j ];
		values[ "v"+i ] 	= get_value( t[0], t[1] );
		values[ "v"+(i+1) ]	= get_value( t[2], t[3] );
	}
	// ����� case ����Ȼ���ӣ�������
	for( i=1;i<6;i+=2 )
	{
		j = (i+1)/2;
		if( values["v"+i][0] >= P9_VALUE[31] || values["v"+(i+1)][0] >= P9_VALUE[31] )
		{
			// ����ڴ�ͷ���β
			t = card_case["c"+j];
			if( random(2) )
				return t;
			return ({ t[2], t[3], t[0], t[1], });
		}
	}
	// ���������������ӣ�Ҳ������
	for( i=1;i<6;i+=2 )
	{
		j = (i+1)/2;
		if( values["v"+i][0] > 0 || values["v"+(i+1)][0] > 0 )
		{
			// ����ڴ�ͷ���β
			t = card_case["c"+j];
			if( random(2) )
				return t;
			return ({ t[2], t[3], t[0], t[1], });
		}
	}
	// ʲô��û�У�������ô��һ�Դ��ľͺ�
	for( k=8;k>=0;k-- )
	{
		for( i=1;i<6;i+=2 )
		{
			j = (i+1)/2;
			if( values["v"+i][1] > k || values["v"+(i+1)][1] > k )
			{
				// ����ڴ�ͷ���β
				t = card_case["c"+j];
				if( random(2) )
					return t;
				return ({ t[2], t[3], t[0], t[1], });
			}
		}
	}

	// ������õ�������������ܣ�����
	return p;
}

// ������ʦ���Ժ���
protected int do_wiz( string arg )
{
	object me = this_player();
	string *p1, *p2, *t;
	int i, *v1, *v2;

	if( !me || !wizardp(me) )
		return 0;

	if( !arg )
		arg = "!!!";

	switch( arg )
	{
		case "show all":
			write( CLR + "\n�ƾ�ȫ��ͼ��һ����\n" + get_show_all_msg( P9_BASE, 1 ) );
			return 1;
		case "show all random":
			write(CLR+"\n�ƾ�ȫ��ͼ��һ��(���)��\n"+get_show_all_msg(get_random_all_cards(),1));
			return 1;
		case "test":
			t = get_random_all_cards();
			p1 = ({ t[0], t[1], });
			p2 = ({ t[2], t[3], });
			p1 = lineup( p1 );
			p2 = lineup( p2 );
			v1 = get_value( p1[0], p1[1] );
			v2 = get_value( p2[0], p2[1] );

			write( sprintf(
				"�ƾ���ʦ���ԣ�һ��������жϲ���(С�ƾ�)��\n\n%s\n"
				"      [%|6s]                  [%|6s]\n\n",
				get_pic( p1+p2, 1, 1 ),
				get_cname( v1 ),
				get_cname( v2 ),
			));

			i = which_one_is_bigger( v1, v2 );
			if( i == 1 )
				write( "      "HIG"��Win!��"NOR"\n" );
			else if( i == 2 )
				write( "                                "HIG"��Win!��"NOR"\n");
			else if( i == 3 )
				write( "            -------- �;� --------\n");
			else write( "    ������δ֪�Ĵ���\n");

			return notify_fail( sprintf(
				"\n�ڲ��ж�ֵ�ο���\n"
				"[һ��]  ���ӣ�%2d  ������%d  ���ƣ�%2d  С�ƣ�%2d\n"
				"[����]  ���ӣ�%2d  ������%d  ���ƣ�%2d  С�ƣ�%2d\n",
				v1[0], v1[1], v1[2], v1[3],  
				v2[0], v2[1], v2[2], v2[3], ) );
		case "test system ai":
			t = get_random_all_cards();
			p1 = ({ t[0], t[1], t[2], t[3], });
			write( sprintf( 
				"�ƾ���ʦ���ԣ�һ��ϵͳׯ�ҵĲ��Բ���(���ƾ�)��\n\n���ƣ�\n\n%s\n",
				get_pic( p1 )
			));

			p2 = system_AI( p1 );
			p1 = lineup( ({ p2[0], p2[1]}) );
			p2 = lineup( ({ p2[2], p2[3]}) );
			v1 = get_value( p1[0], p1[1] );
			v2 = get_value( p2[0], p2[1] );
			write( sprintf(
				"������ϵͳ���к�\n\n%s\n"
				"      [%|6s]                  [%|6s]\n\n",
				get_pic( p1+p2, 1, 1 ),
				get_cname( v1 ),
				get_cname( v2 ),
			));
			return 1;
		default:
			return notify_fail( 
				"[ "+GAME_NAME+" ]֮��ʦ����ָ��ɼӲ�����\n"
				"\n"
				"[show all]          �鿴�����Ƶ�ͼ��\n"
				"[show all random]   �鿴����������Ƶ�ͼ��\n"
				"[test]              ����һ��������жϲ���(С�ƾ�)\n"
				"[test system ai]    ����һ��ϵͳׯ�ҵĲ��Բ���(���ƾ�)\n\n",
			);
//		case "ttt":
//			write( get_pic( ({"tian1","tian2","di2","he2","ft1", "82", "none", "none", }), 1, 1) );
//			return 1;
	}
	return 1;
}

//         #################################################
//     ##########################################################
// ###################################################################

// ��������Ϸ���򲿷�
// ���ƾ� ��Ϸ����

protected int filter_listener( object ob )
{
        if ( ob->query("naihe_game_data/p9/no_p9_msg") )
		return 0;
        return 1;
}

// ʡ�� *p ʱ����������ҷ�����Ϣ�������˲�������Ϣ�ĳ��⣩
// �� *p ʱ���� *p ���б���ҷ�����Ϣ��
protected varargs void message_p9( string msg, string *p )
{
	object listener_list, listener;
	string t;

	if( !msg )
		return;

	if( !p || !sizeof(p) )
	{
		listener_list = filter_array( users(), (: filter_listener :) );
		if( !listener_list || sizeof( listener_list ) < 1 )
			return;
		foreach( listener in listener_list )
		{
			tell_object( listener , ChannelColor"���ƾŶľ֡� " + msg + NOR);
		}
		return;
	}
	foreach( t in p )
	{
		if( t && (listener=find_player(t)) )
			tell_object( listener, ChannelColor"���ƾŶľ֡� " + msg + NOR);
	}
	return;
}

protected void set_del_no_msg_env( object me, string t )
{
	if( !me || !userp(me) )
		return;
	if( t == "set" )
	{
		if( !me->query( "naihe_game_data/p9/no_p9_msg" ) )
		{
			me->set("naihe_game_data/p9/no_p9_msg", "YES" );
			tell_object( me, "�������á������չ���["+GAME_NAME+"]����Ϣ����\n");
		}
		return;
	}
	if( me->query( "naihe_game_data/p9/no_p9_msg" ) )
	{
		me->delete( "naihe_game_data/p9/no_p9_msg" );
		tell_object( me, "����ȡ���ˡ������չ���["+GAME_NAME+"]����Ϣ�� �����á�\n");
	}
}

protected int	help_cmds();				// help commands
protected int	do_showcards();				// �鿴����ͼ����ʾ
protected int	do_check_now();				// ��ѯ���ڵ���Ϸ״̬
protected int	do_chk( string arg );			// ��Ҳ�ѯ���˻���
protected int	do_lineup_card( string arg );		// ��ҽ������У������ƾ�ʱ��Ч��
protected int	do_is_ready();				// ���׼�����ˣ������ƾ�ʱ��Ч��
protected int	do_join_game( int bet );		// ��Ҽ�����Ϸ

protected void	do_start_game();			// ׼�������ľ�
protected void	start_game_set( string inp );		// �����ľ�������
protected void	start_game_ok( object me );		// ���óɹ��������ľ�
protected void	game_running_start();			// ��Ϸ������ - ��ʼ
protected void	game_running_ready_open( string t );	// ��Ϸ������ - ׼������ (���ƾž�ʱ��)
protected void	game_running_open( int round );		// ��Ϸ������ - ���� (���ƾž�ʱ��������)
protected void	game_running_over();			// ��Ϸ������ - ���� (�ָ�����)

protected string	*system_host_get_special_card();	// ����ϵͳ��ׯ�һ��һ���ر����

string
	GameNow = "�޶ľ�",
	*CardsNow,
	*HostCard,
	*NoReadyPlayers,

	end1;

int
	HostScore,

	end2;

mapping
	GameSettings,
	PlayerCard,
	PlayerBet,
	PlayerPower,
	HostPower,

	end3;

protected void do_start_game()
{
	object me = this_player();
	int my_score;

	if( !me || !userp(me) )
		return;
	if( ! GAME_ON )
	{
		write( "�Բ�����Ϸ��ͣ���š�\n");
		return;
	}
	if( GameNow != "�޶ľ�" )
	{
		write( "��ֻ���� \"�޶ľ�\" ʱ��ʼ��Ϸ������״̬�� \""+GameNow+"\" ��\n");
		return;
	}
	my_score = me->query( GAME_SCORE_DATA );
	if( my_score < BET_MIN )
	{
		write( sprintf( "���%s̫���ˣ�������Ҫ %d �㡣\n",
			GAME_SCORE_NAME, BET_MIN ));
		return;
	}
	if( me->query("naihe_game_data/p9/freetime") > time() )
	{
		write( "����������һ�γɹ������ľֵ�ʱ��̫�̣����Ժ����ԡ�\n");
		if ( !IsTest || getuid(me) != "naihe" )
			return;
	}

	write( sprintf( 
		" ========================== ��׼����ʼһ���µ��ƾŶľ� ==========================\n"
		"�����ϣ��"HIR"��ϵͳ��ׯ�������� [big] �� [small] ѡ��Ĵ��ƾŻ�С�ƾţ���ֱ�ӿ�ʼ"NOR"��\n"
		"\n"
		"���򣬼�"HIM"���Լ���ׯ"NOR"����ô������Ҫ����������Щ���ã�\n"
		"1�������ľֵķ�ʽ��big = �Ĵ��ƾ�  small = ��С�ƾ�\n"
		"2���������ɲ��������(���������Լ�)����Χ�� 1 ~ 7\n"
		"3������ÿ������Ѻע���٣�������ֵķ�Χ�� %d ~ %d\n"
		"4������ÿ�����Ѻע���٣�������ֵķ�Χͬ�ϣ����Ҳ���С�ڡ�����Ѻע��\n"
		"\n"
		"���%s�� %d �㡣���������Լ���ׯ���뿴ָ��ʾ���� <"HIM"big 7 50 100"NOR">\n"
		"    ��ʾ���ĵ��Ǵ��ƾţ�������7�����棬����ÿ������Ѻ50�㣬���Ѻ100�㡣\n"
		" ================================================================================\n"
		"�����루ȡ�������� cancel����",
			BET_MIN, BET_MAX,GAME_SCORE_NAME,my_score,  ));

	input_to( "start_game_set" );
	return;
}

// ����Ϊ��������Ϸʱ��������ʾд������ϣ�Ӧ���ǹ��������ˣ�
protected void start_game_set( string inp )
{
	object me = this_player();
	int bet_min, bet_max, player_max,t;
	string game_type, id, name ;

	if( !me || !userp(me) )
		return;
	if( ! GAME_ON )
	{
		write( "�Բ�����Ϸ��ͣ���š�\n");
		return;
	}
	if( GameNow != "�޶ľ�" )
	{
		write(HIR"���ź������ľ����Ѿ����ˣ��ľ��Ѿ��ɱ��˿�ʼ�ˡ���ֱ������ <p9> ��ѯ��\n"NOR);
		return;
	}
	if( !inp )
		inp = "@#$@#$@#";

	if( inp == "cancel" || inp == "q" || inp == "Q" )
	{
		write( "�õģ�ȡ�������Ҫ�󣬶ľָֻ��˿��е�״̬��\n");
		return;
	}

	id = me->query("id");
	name = sprintf( "%s(%s)", me->query("name"), id );

	if( inp == "big" || inp == "small" )
	{
		// ���ׯ��Ǯ��̫���ˣ���ô��Ҳ�������ڸ������ò��������Ӯ��̫���ˣ�ϵͳֹͣ��ׯ��
		if( system_score < 1 )
		{
			write( HIR"�Բ���ϵͳ��ͣ��ׯ�����������Ϸ�����Լ���ׯ��\n"NOR
				"���������루ȡ��������cancel����", );
			input_to( "start_game_set" );
			return;
		}
		// ͬһ��Ҳ�ҪƵ����Ҫ��ׯ����
		me->set( "naihe_game_data/p9/freetime", time() + StartGameBusy );
		set_del_no_msg_env( me,"del" );

		// ����Ϸ���ü�¼����
		GameSettings = ([
			"host_id"	:	"SYSTEM",
			"host_name"	:	"ϵͳ",
			"p_amount"	:	7,
			"b_min"		:	BET_MIN,
			"b_max"		:	BET_MAX,
			"is_dp9"	:	inp == "big" ? 1 : 0,
		]);

		GameNow = "׼����ʼ�¶ľ�";
		HostScore = 0;
		start_game_ok( me );
		return;
	}

	// �����ׯ
	sscanf( inp, "%s %d %d %d", game_type, player_max, bet_min, bet_max );
	if( !game_type || !player_max || !bet_min || !bet_max )
	{
		write( "����ָ��ĸ�ʽ����ȷ����ȷ��������ĸ�ʽ�ǡ��ַ� ���� ���� ���֡����������ֲ���Ϊ 0 ��\n"
			"����ϸ�鿴˵������������������ָ�ȡ��������cancel����");
		input_to( "start_game_set" );
		return;
	}
	write( "\n" );
	if( !game_type || (game_type != "big" && game_type != "small" ) )
	{
		write( sprintf( 
		BLINK+HIR"%s"NOR" %d %d %d\n"
		"\"�Ĵ��ƾŻ���С�ƾ�\"�ľ����д�����ֻ���� \"big\" �� \"small\"��\n"
		"���������루ȡ��������cancel����",
			game_type, player_max, bet_min, bet_max,
			));
		input_to( "start_game_set" );
		return;
	}
	if( player_max < 1 || player_max > 7 )
	{
		write( sprintf( 
		"%s "BLINK+HIR"%d"NOR" %d %d \n"
		"\"����������\"�ľ����д������ķ�Χ�� 1 ~ 7 ��\n"
		"���������루ȡ��������cancel����",
			game_type, player_max, bet_min, bet_max,
			));
		input_to( "start_game_set" );
		return;
	}
	if( bet_min < BET_MIN || bet_min > BET_MAX )
	{
		write( sprintf(
		"%s %d "BLINK+HIR"%d"NOR" %d\n"
		"\"����Ѻע��\"�ľ����д������ķ�Χ�� %d ~ %d ��\n"
		"���������루ȡ��������cancel����",
			game_type, player_max, bet_min, bet_max, BET_MIN, BET_MAX,
			));
		input_to( "start_game_set" );
		return;
	}
	if( bet_max < bet_min || bet_max > BET_MAX )
	{
		write( sprintf(
		"%s %d %d "BLINK+HIR"%d"NOR"\n"
		"\"���Ѻע��\"�ľ����д������ķ�Χ�� %d ~ %d ��\n"
		"���������루ȡ��������cancel����",
			game_type, player_max, bet_min, bet_max, bet_min, BET_MAX,
			));
		input_to( "start_game_set" );
		return;
	}

	t = me->query( GAME_SCORE_DATA );
	if( t < bet_max * player_max )
	{
		write( sprintf(
			"��ϣ���Լ���ׯ���������������� %d ���˲���ľ֣���������� %d ���%s�Ź���Ǯ��ׯ��\n"
			"��Ļ��ֲ���(���� %d ��)������Խ������Ѻע��������������������\n"
			"���������루ȡ��������cancel����",
			player_max, bet_max*player_max, GAME_SCORE_NAME,t,
			));
		input_to( "start_game_set" );
		return;
	}

	// �ɹ���
	// ͬһ��Ҳ�ҪƵ����Ҫ��ׯ����
	me->set( "naihe_game_data/p9/freetime", time() + StartGameBusy );
	set_del_no_msg_env( me,"del" );


	// ����Ϸ���ü�¼����
	GameSettings = ([
		"host_id"	:	id,
		"host_name"	:	name,
		"p_amount"	:	player_max,
		"b_min"		:	bet_min,
		"b_max"		:	bet_max,
		"is_dp9"	:	game_type == "big" ? 1 : 0,
	]);

	// ���������ׯ������Ҫ�����ر������

	HostScore = bet_max * player_max;
	me->add( GAME_SCORE_DATA, -HostScore );
	write( sprintf( 
		HIG"����ׯ�ң�������涨�����Ѻע(ÿ��������Ѻ %d �� x %d ��)������뽻������ %d ���ׯ��Ѻ��\n"
		"���Ѿ������%s��۳��ˣ��ڶľֽ���������ܵû����������û���Ļ� :P���������ڻ��� %d �㡣\n",
		bet_max, player_max, HostScore, GAME_SCORE_NAME, me->query( GAME_SCORE_DATA ),
	));
	GameNow = "׼����ʼ�¶ľ�";
	start_game_ok( me );
	return;
}

protected void start_game_ok( object me )
{
	if( !me || !userp(me) || !GAME_ON || GameNow != "׼����ʼ�¶ľ�" )
		return;
	message_p9( sprintf(
		"\n---------------------------------------------------------------------------------------\n"
		"Ӧ %s Ҫ���� %s ��ׯ����ʼ��һ���ƾŶľ֣�\n"
		"�ĵ���%s"+ChannelColor+"����%s�ң�ÿ����ע %d ~ %d �㣡��ӮǮ�ľ���ѽ�� (p9 in ��ע)\n"
		"---------------------------------------------------------------------------------------\n",
			sprintf( "%s(%s)", me->query("name"), me->query("id") ),
			GameSettings[ "host_name" ],
			GameSettings[ "is_dp9" ] ? HIY"���ƾ�"NOR : HIG"С�ƾ�"NOR,
			chinese_number( GameSettings[ "p_amount" ] ),
			GameSettings[ "b_min" ],
			GameSettings[ "b_max" ],
	));

	// ����Ҫ�ı�������
	PlayerBet = ([ ]);
	PlayerCard = ([ ]);
	PlayerPower = ([ ]);
	HostPower = ([ ]);
	HostCard = ({ });
	NoReadyPlayers = ({ });

	GameNow = "�ȴ���Ҽ���";		// ��ʱ��������ҾͿ��Լ�����
	if( IsTest )
		call_out( "game_running_start", 5 );
	else
		call_out( "game_running_start", WAIT_TIME_JOIN );	// ֱ���� N �������
	return;
}

protected void game_running_start()
{
	string hid;
	object hob;
	// �ڶ�����ʹ��
	string *p, t;
	int i, is_dp9, i2;

	remove_call_out( "game_running_start" );
	if( !GAME_ON || GameNow != "�ȴ���Ҽ���" )
		return;

	GameNow = "�ľ�����ǰ���"; // ���״̬һɲ�Ǽ�����Ҳ��Ϊ�˷�ֹδ֪�ĳ�ͻ����(player join)

	// �Ƿ�������һλ��Ҳ���ľ֣�����Ϸ�޷���ʼ  ��>7 ʱ���BUG��ȡ�� game
	if( (i=sizeof(PlayerBet)) < 1 || i > 7 )
	{
		message_p9( "���ź��������ƾŶľ����˼���(��������)������ȡ����\n" );
		hid = GameSettings[ "host_id" ];
		if( hid != "SYSTEM" )  // ����������ׯ����ô���Ѿ�Ѻ���ˡ�ׯ��Ѻ�𡱡������Ǯ��������
		{
			if( hid )
				hob = find_player( hid );
			if( hob )
			{
				tell_object( hob, sprintf("��û���֮ǰѺ�µ�ׯ��Ѻ�� %d �㡣\n", HostScore ));
				hob->add( GAME_SCORE_DATA, HostScore );
			}
		}
		GameNow = "�޶ľ�";
		return;
	}

	// ��ô����ʼ
	GameNow = "�ľ����ڽ��У�[ȡ����]";
	if( GameSettings[ "is_dp9" ] )	// �����Ǳ�ʾ��� ���Ǵ��ƾš�
		is_dp9 = 1;
	message_p9( sprintf( "�ľֿ�ʼ�ˣ����� %d λ��Ҳ����� %s ��ׯ�� %s �ľ֣�\n",
			i, GameSettings[ "host_name" ], is_dp9 ? "���ƾ�" : "С�ƾ�",
		));

	p = keys( PlayerBet ); // ����б�

	// ��¼��־
	for( i=sizeof(p)-1;i>=0;i-- )
		i2 += PlayerBet[p[i]];
        game_log( sprintf( "\n%s ��ע���ͣ�%s(\"%s\")\n"
			   "   ׯ��[%s]  ��ʽ��[%s�ƾ�]  ���룺[%d��]  Ѻע��[%d��]  ϵͳ���֣�[%d]\n",
                        GameSettings["host_id"] == "SYSTEM" ? "��" : "��",  GAME_SCORE_NAME,
			GAME_SCORE_DATA, GameSettings["host_name"], is_dp9?"��":"С", sizeof(PlayerBet),
			i2, system_score,
		));
	CardsNow = get_random_all_cards();					// ϴ��

	// ׯ�������ƣ�����ׯ�ҵ�������һ�£�������ͨ�˵�˼ά
	HostCard = lineup( ({ CardsNow[0], CardsNow[1] }) ) + lineup( ({ CardsNow[2], CardsNow[3] }) );

	message_p9( sprintf( NOR+
		"\n---------------------------------------------------------------------------------------\n"
		"����ׯ�ҡ��õ��ˣ�\n"
		"%s"
		"---------------------------------------------------------------------------------------\n",
		is_dp9  ? get_pic( HostCard, 0, 1 )
			: get_pic( ({ HostCard[0], HostCard[1],}), 0, 1 ),
		), ({ GameSettings[ "host_id" ] }),
	);
	// �����ϵͳ��ׯ����Ҫ����һЩ�ر�ļ�¼��
	// ���ң�Ϊ���ֲ������ǣ�ׯ���л���õ�������ƣ�������ӮǮ�ļ��ʡ�
	// ���ң�����Ǵ��ƾŶľ֣�ׯ����Ҫ�Զ��������Լ����ơ�
	if( GameSettings[ "host_id" ] == "SYSTEM" )
	{
		HostScore += GameSettings[ "b_max" ] * 7;   // ׯ�ұ��� = ԭׯ�ұ��� + ���Ѻע
		system_score -= GameSettings[ "b_max" ] * 7; // ������һ����ֹ �������ò��������¶��Ӻ�� �����γ��ֵĻ���

		// 1/5 �Ļ���õ��ر����
		if( !random(5) )
		{
			if( IsTest )
				message_p9( sprintf( "ׯ���ر���ƣ�ԭ�����ǣ�%s %s %s %s\n",
					HostCard[0], HostCard[1],HostCard[2],HostCard[3],));
			HostCard = 0;
			HostCard = system_host_get_special_card();
			if( IsTest )
				message_p9( sprintf( "�����ر������ǣ�%s %s %s %s\n",
					HostCard[0], HostCard[1],HostCard[2],HostCard[3],));
		}
		// �ã�����Ǵ��ƾţ�����ׯ���Զ�����
		if( is_dp9 )
		{
			HostCard = system_AI( HostCard );
		}
	}
	else	// ����ׯ������ҿ��ƣ���ô������ӡ�δ׼���á��ı��
	{
		NoReadyPlayers += ({ GameSettings[ "host_id" ], });
	}

	/*// �ر�Ĳ�����Ҫ
	while( sizeof(PlayerBet) < 7 )
	{
		PlayerBet[ random(10000) + "" ] = 9;
	}*/

	i = 4;
	foreach( t in p )							// �������
	{
		// ������ƣ�����������һ��
		PlayerCard[ t ] = lineup( ({CardsNow[i],CardsNow[i+1]}) ) + lineup( ({CardsNow[i+2],CardsNow[i+3]}) );
		i += 4;
		message_p9( sprintf( NOR+
			"\n---------------------------------------------------------------------------------------\n"
			"������ [%s] �ҡ��õ��ˣ�\n"
			"%s"
			"---------------------------------------------------------------------------------------\n",
			chinese_number( i/4 ), is_dp9  ? get_pic( PlayerCard[t], 0, 1 )
				: get_pic( ({ PlayerCard[t][0], PlayerCard[t][1],}), 0, 1 ),
			), ({ t }),
		);
		PlayerPower[ t ] = 0;
		HostPower[ t ] = 0;
		NoReadyPlayers += ({ t });
	}

	// �ã����õ����ˣ������С�ƾţ��������ƣ�3�룩�����򣬵ȴ�һ��ʱ�䣬�ø�λ��ҽ�������
	if( !is_dp9 )
	{
		GameNow = "�ľ����ڽ��У�[��������]";
		message_p9( "��ֶĵ���С�ƾţ���һ�������ۡ������ƿ���\n", ({ GameSettings[ "host_id" ] }) + p );
		call_out( "game_running_open", 3, 1, );		// 3���ִ�У�����1 ��ʾ�жϵ�1��2����
		return;
	}
	// ���������ʾ��Ϣ������������Լ����ƣ��ȴ� N ������
	GameNow = "�ľ����ڽ��У�[�ȴ���ҽ��Ʒ���]";
	message_p9(
		"\n"
		"              ��ֶĵ��Ǵ��ƾţ���Ҫ�����ų�����Ϊ���ʵ����飨�ֱ�����ϡ����ţ���\n"
		"              ��ָ����� ["HIW"card 2 3 1 4"+ChannelColor+"] ��������ʽ���������ǡ�\n"
		"              ���������˼�ǣ��µ�˳���ǣ����ڵ��Ƶĵ� 2��3��1��4 �š�\n"
		"              ��ôҲ����˵�����ڵĵ� 2��3 �Ž���Ϊ ���ţ��� 1��4 ����Ϊ ���š�\n\n",
		({ GameSettings[ "host_id" ] }) + p );
	call_out( "game_running_ready_open", WAIT_TIME_LINEUP, "ʱ�䵽��" );
}

protected string *system_host_get_special_card()
{
	string *base, *c, t, t1, t2;
	int i;
	if( HostCard || !CardsNow || sizeof(CardsNow) != 32 )
		return 0;
	base = ({ "tian", "di", "ren", "he", "mh", "cs", "bd", "ft", "ht", "16", "15",
		"9", "8", "7", "5" });
	t = base[ random(sizeof(base)) ];
	t1 = t+"1";
	t2 = t+"2";
	// ��ϴ�õ����е�����������
	for( i=0;i<32;i++ )
	{
		if( CardsNow[i] == t1 )
			CardsNow[i] = CardsNow[0];
		if( CardsNow[i] == t2 )
			CardsNow[i] = CardsNow[1];
	}
	CardsNow[0] = t1;
	CardsNow[1] = t2;
	c = ({ CardsNow[0],CardsNow[1],CardsNow[2], CardsNow[3], });
	return c;
}


protected void game_running_ready_open( string t )
{
	remove_call_out( "game_running_ready_open" );
	if( !GAME_ON || GameNow != "�ľ����ڽ��У�[�ȴ���ҽ��Ʒ���]" || !GameSettings[ "is_dp9" ] )
		return;
	GameNow = "�ľ����ڽ��У�[��������]";
	message_p9( t+"�����ƿ���\n",  ({ GameSettings[ "host_id" ] }) + keys(PlayerCard) );
	call_out( "game_running_open", 1, 1);
}

// �����˰�
protected void game_running_open( int round )
{
	string *c, *tc, *p, t, ttt, win_id, lost_id, *cname, *cl, msg;
	int *v1, *v2, win_times, lost_times, i;

	remove_call_out( "game_running_open" );
	if( !GAME_ON || (GameNow != "�ľ����ڽ��У�[��������]" && GameNow != "�ľ����ڽ��У�[������]") )
		return;

	GameNow = "�ľ����ڽ��У�[������]";

	win_id = "";
	lost_id = "";

	// Ϊ����ʾͼƬ��Ҫһ�������Ƶı�Ǽ�¼�������ȼ�ׯ�ҵ�
	if( round == 1 )
	{
		c = ({ HostCard[0], HostCard[1], });
		if( GameSettings[ "is_dp9" ] )
			ttt = "����";
		else
			ttt = "";
	}
	else
	{
		c = ({ HostCard[2], HostCard[3], });
		ttt = "����";
	}

	c = lineup( c );		// ����һ�����Ĵ�С˳��
	v1 = get_value( c[0], c[1] );	// �õ�ׯ�ҵ��Ƶġ���ֵ����
	cname = ({ get_cname(v1) });	// �õ�����ӵ�����

	cl = ({ HIW });
	p = keys( PlayerBet );		// ����б�
	foreach( t in p )		// �����ׯ�ҽ���
	{
		if( round == 1 )	// �õ�Ҫ�Ƚϵ�����һ�����ȡ��������µİ�ȫ�ж��ˣ��� bug ���ҿɲ��ܰ�
			tc = ({ PlayerCard[t][0], PlayerCard[t][1], });
		else
			tc = ({ PlayerCard[t][2], PlayerCard[t][3], });
		tc = lineup( tc );			// �����С˳������һ��
		c += tc;				// ���⼸����Ǵս�ȥ����ʱ��Ҫ��ʾͼƬ��
		v2 = get_value( tc[0], tc[1] );		// �㵽���ġ���ֵ��
		cname += ({ get_cname(v2) });		// �㵽���ġ����ơ�
		if( which_one_is_bigger(v1,v2 ) == 2 )	// �������мҴ�
		{
			win_times ++;
			win_id += t + " ��";
			PlayerPower[ t ] ++;		// ��һ�ҵ� power ����Щ��
			cl += ({ BLINK+HIG });
		}
		else					// ����ʹ�Ǻͣ�Ҳ��ׯӮ
		{
			lost_times ++;
			lost_id += t + " ��";
			HostPower[ t ] ++;		// ׯ�ҵ� power ����Щ��
			cl += ({ HIR });
		}
	}

	// ���ˣ������ˣ�show ���������û���˲�����мң�ҲҪ��ʾ��λ
	while( sizeof(c) < 16 )		// ���Ҵ�
	{
		c += ({ "none", });
	}
	while( sizeof(p) < 7 )
	{
		p += ({ "----", });
	}
	while( sizeof(cname) < 8 )
	{
		cname += ({ "----" });
	}
	while( sizeof(cl) < 8 )
	{
		cl += ({ NOR });
	}

	// ������һ�ζ��������ͷ��
	// ��һ����ׯ��123�е����ֺ�Ѻע��
	t = sprintf( HIY"  %-16s  "NOR, "[ׯ�� "+GameSettings[ "host_id" ]+"]", );
	for( i=0;i<3;i++ )
	{
		t += sprintf( "      "HIY"%|10s"NOR" (%|6d) ",
			"["+p[i]+"]", PlayerBet[ p[i] ], );
	}
	msg = sprintf(
		"\n----------------------------------------------%s----------------------------------------------\n"
		"%s\n"
		"%s",
			ttt == "" ? "------------" : sprintf( "[%|10s]", ttt ),
			t, get_pic( ({c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7],}), 1, 1 ),
		);
	// ����⼸���Ƶ���������
	t = " ";
	for( i=0;i<4;i++ )
	{
		t += sprintf( "     %s%|8s"NOR"             ", cl[i], "["+cname[i]+"]" );
	}
	msg += t + "\n\n";

	// �ã���������4����  ��������
	t = "";
	for( i=3;i<7;i++ )
	{
		t += sprintf( ""HIY"%|10s"NOR" (%|6d)       ",
			"["+p[i]+"]", PlayerBet[ p[i] ], );
	}
	msg += sprintf(
		"%s\n"
		"%s",
			t, get_pic( ({c[8],c[9],c[10],c[11],c[12],c[13],c[14],c[15],}), 1, 1 ),
		);
	// ������漸���Ƶ���������
	t = " ";
	for( i=4;i<8;i++ )
	{
		t += sprintf( "     %s%|8s"NOR"             ", cl[i], "["+cname[i]+"]" );
	}
	msg += t + "\n\n";
	// ����ͳ�Ʊ���
	if( win_times == sizeof( PlayerBet ) )
	{
		msg += sprintf( HIG" ׯ��%s�� [%s]��ͨ�⣡\n"NOR, ttt, cname[0] );
	}
	else if( lost_times == sizeof(PlayerBet) )
	{
		msg += sprintf( HIY" ׯ��%s�� [%s]��ͨ�ԣ�\n"NOR, ttt, cname[0] );
	}
	else
	{
		msg += sprintf( HIW" ׯ��%s�� [%s]���� %s �� %d �ţ�\n"
			     "                    �� %s �� %d �š�\n"NOR,
			ttt, cname[0], lost_id, lost_times, win_id, win_times, );
	}

	msg +=
	  "---------------------------------------------------------------------------------------------------------\n";
	message_p9( NOR + msg, p+({ GameSettings[ "host_id"]}) );


	// ���ˣ�show ���ˣ������С�ƾţ�ͳ����Ϸ�����ƾţ���������žͼ����ȣ�����Ҳͳ����Ϸ
	if( GameSettings[ "is_dp9" ] && round == 1 )
	{
		message_p9 ( "�����������ŵ��ƣ�\n", p+({ GameSettings[ "host_id"]}) );
		if( IsTest )
			call_out( "game_running_open", 3, 2 );
		else
			call_out( "game_running_open", WAIT_TIME_NEXTPAIR, 2 );
		return;
	}

	GameNow = "�ľ���Ӯͳ����";
	if( IsTest )
		call_out( "game_running_over", 3 );
	else
		call_out( "game_running_over", WAIT_TIME_NEXTPAIR );
}

// ������ͳ�ƣ��ָ�����״̬
protected void game_running_over()
{
	string *p, t, Hmsg;
	object ob;
	int old_HostScore,i, i2;

	remove_call_out( "game_running_over" );
	if( !GAME_ON || GameNow != "�ľ���Ӯͳ����" )
		return;

	// Power �����
	Hmsg = "\n";
	p = keys( PlayerBet );
	foreach( t in p )
	{
		i = PlayerBet[t];
		if( i<BET_MIN || i>BET_MAX )
			i = BET_MIN;
		if( t )
			ob = find_player( t );
		if( !ob )					// �˲����ˣ�����Ȩ��
		{
			Hmsg += sprintf( HIY"��Ȩ��%s ���Ŷ����ܵ��ˡ�׬���� %d �� %s��\n"NOR, t, i, GAME_SCORE_NAME );
			continue;
		}
		if( HostPower[t] > PlayerPower[t] )		// ���������ˣ�������ʲô
		{
			message_p9( sprintf( HIR"�����ˣ������ %d �� %s��  :(    Ѻעǰ��[%d] ���ڣ�[%d]\n"NOR,
				i, GAME_SCORE_NAME,(i2=ob->query( GAME_SCORE_DATA )+i),(i2-i), ), ({t}) );
			Hmsg += sprintf( HIG"Ӯ�� %s ��׬���� %d �� %s��\n"NOR, t, i, GAME_SCORE_NAME);
		}
		else if( HostPower[t] < PlayerPower[t] )	// Ӯ�ˣ���ׯ��Ѻ���п۳�
		{
			message_p9( sprintf( HIG"��Ӯ�ˣ�Ӯ�� %d �� %s ����������  Ѻעǰ��[%d] ���ڣ�[%d]\n"NOR,
				i, GAME_SCORE_NAME,(i2=ob->query( GAME_SCORE_DATA )+i),(i2+i), ), ({t}) );
			Hmsg += sprintf( HIR"����� %s ������� %d �� %s��\n"NOR, t,i,GAME_SCORE_NAME);
			ob->add( GAME_SCORE_DATA, i*2 );	// ���������õ���
			HostScore -= i*2;
		}
		else						// �;�
		{
			message_p9( sprintf( HIW"�;֣��û��� %d �� %s �����ǰ׷Ѿ���  Ѻעǰ��[%d] ���ڣ�[%d]\n"NOR,
				i, GAME_SCORE_NAME,(i2=ob->query( GAME_SCORE_DATA )+i),i2, ), ({t}) );
			Hmsg += sprintf( HIW"�;֣� %s ��%d �� %s ����Ӯ����\n"NOR, t,i,GAME_SCORE_NAME);
			ob->add( GAME_SCORE_DATA, i );		// �ûر�Ǯ
			HostScore -= i;
		}
	}

	old_HostScore = GameSettings[ "b_max" ] * GameSettings[ "p_amount" ];
	i = HostScore - old_HostScore;

	if( (t=GameSettings[ "host_id" ]) != "SYSTEM" )		// �������ׯ��Ҫ�ر���һ��
	{
		if( t )
			ob = find_player( t );
		if( ob )
		{
			Hmsg += sprintf( "\n���ڿ���֮ǰѺ�µġ�ׯ��Ѻ���� %d �㣬���� %d �㡣%s"NOR"\n",
				old_HostScore, HostScore,
				i == 0 ? HIW"�պûر����Ǻǡ�" : i<0 ? HIR"���� "+i*-1+" �㣡" : HIG"Ӯ�� "+i+" �㡣 :)",);
			Hmsg += sprintf( "��ʼǰ��[%d]", ob->query( GAME_SCORE_DATA ) + old_HostScore );
			if( HostScore > 0 )
				ob->add( GAME_SCORE_DATA, HostScore );
			Hmsg += sprintf( "  ���ڣ�[%d]\n", ob->query( GAME_SCORE_DATA ) );
			message_p9( Hmsg, ({t}) );
		}
	}
	else
	{
		system_score += HostScore;
	}

	// ��¼
	game_log( sprintf( "---- �ľֽ�������ׯ��[%d]  ������[%d]  %s��%s\n",
			old_HostScore, HostScore,
			i==0 ? "ׯ�һر�" : i<0 ? "ׯ������ "+i*-1+" ��" : "ׯ��Ӯ�� "+i+" ��",
			t == "SYSTEM" ? "ϵͳ����ʣ�� "+system_score+" �㡣" : "",
		));
	GameNow = "�޶ľ�";
	message_p9( sprintf( "�� %s ��ׯ����һ���ƾŶľֽ����ˣ�\n", GameSettings["host_name"]));
}
// ��ϣ�һ��Ȧ��ѭ������


protected int do_check_now()
{
	string *gn_ok, *p, msg, t;
	int i;

	// ��Ϸ״̬�����������ͳһ    ���е� GameNow :
	//	"�޶ľ�",			"׼����ʼ�¶ľ�",		"�ȴ���Ҽ���",
	//	"�ľ�����ǰ���",		"�ľ����ڽ��У�[ȡ����]",	"�ľ����ڽ��У�[��������]",
	//	"�ľ����ڽ��У�[�ȴ���ҽ��Ʒ���]",	"�ľ���Ӯͳ����",

	gn_ok = ({ "�ȴ���Ҽ���", "�ľ����ڽ��У�[ȡ����]", "�ľ����ڽ��У�[�ȴ���ҽ��Ʒ���]", 
			"�ľ����ڽ��У�[��������]", "�ľ���Ӯͳ����",});

	msg = sprintf( "----------------------------------------------------------------------\n"
		BGRN+HIY"[ %s(%s) ״̬��ѯ ]\n\n"NOR
		"  ����״̬��["HIG"%s"NOR"]  ���%s��["HIY"%d"NOR"]  %s\n\n",
			GAME_NAME, GAME_VERSION, GameNow,
			GAME_SCORE_NAME, this_player()->query( GAME_SCORE_DATA ),
			wizardp(this_player()) ? "ϵͳ���֣�["HIM+system_score+NOR"]" : "", );

	// ��״̬�������б���ʱ����Ӷ���Ĳ�ѯ��Ϣ
	if( member_array( GameNow, gn_ok ) != -1 )
	{
		msg += sprintf( "  ׯ�ң�[%s]  ��ע��[%d - %d]  ���ˣ�[%d]  ��ʽ��[%s�ƾ�]  %s\n\n",
				GameSettings["host_name"], GameSettings["b_min"],
				GameSettings["b_max"], GameSettings["p_amount"],
				GameSettings["is_dp9"] ? "��" : "С",
				GameNow == "�ľ����ڽ��У�[�ȴ���ҽ��Ʒ���]" ?
					member_array( GameSettings["host_id"], NoReadyPlayers ) == -1 ?
						HIG"��"NOR : HIR"��"NOR : "", );
		if( PlayerBet && mapp(PlayerBet) )
		{
			p = keys( PlayerBet );
			for( i=0;i<sizeof(p);i++ )
			{
				if( GameNow == "�ľ����ڽ��У�[�ȴ���ҽ��Ʒ���]" )
				{
					if( member_array( p[i], NoReadyPlayers ) == -1 )
						t = HIG"���Ʒֺ�����"NOR;
					else t = HIR"��δ���Ʒֺ���"NOR;
				}
				else t = "";
				msg += sprintf( "  [�С�%s��]  %-10s   Ѻע��[%-12s %s\n",
					chinese_number(i+2),p[i], PlayerBet[p[i]] +"]", t);
			}
		}
	}

	return notify_fail( msg + "----------------------------------------------------------------------\n");
}

protected int do_lineup_card( string arg )
{
	object me = this_player();
	int *c, *c1, i;
	string id, *bc, *bc2;	// bc = base card

	if( !arg || !me || !userp(me) || !GAME_ON || GameNow != "�ľ����ڽ��У�[�ȴ���ҽ��Ʒ���]"
	 || !GameSettings[ "is_dp9" ] || !PlayerBet || !sizeof(PlayerBet)
	 || member_array( getuid(me), keys(PlayerBet)+({ GameSettings["host_id"]}) ) == -1 
	 )
		return 0;

	c = allocate(4);
	c1 = ({ 1, 2, 3, 4 });
	sscanf( arg, "card %d %d %d %d", c[0], c[1],c[2],c[3] );
	for( i=0;i<4;i++ )
	{
		if( c[i] < 1 || c[i] > 4 )
			return notify_fail("ָ�������ʽ�� [card ���� ���� ���� ����]\n"
					"���ַ�Χ�� 1-4 ֮�䣬���Ҳ�����ͬ��\n");
		c1 -= ({ c[i] });
		c[i] -= 1;
	}
	if( sizeof(c1) )
		return notify_fail("ָ�������ʽ�� [card ���� ���� ���� ����]\n"
					"���ַ�Χ�� 1-4 ֮�䣬���Ҳ�����ͬ��\n");
	if( (id=getuid(me)) == GameSettings["host_id"] )
	{
		HostCard = ({ HostCard[ c[0] ], HostCard[ c[1] ], HostCard[ c[2] ], HostCard[ c[3] ], });
		write( sprintf( "\n%s\n\n"
			"�����׼�����ˣ�������ָ����� [ok] ��ʾ��׼�����ˡ�������ʹ�ľָ��������ȥ��\n",
			get_pic( HostCard, 1, 1 ) ));
	}
	else
	{
		PlayerCard[ id ] = ({ PlayerCard[id][c[0]],PlayerCard[id][c[1]],
					PlayerCard[id][c[2]],PlayerCard[id][c[3]], });
		write( sprintf( "\n%s\n\n"
			"�����׼�����ˣ�������ָ����� [ok] ��ʾ��׼�����ˡ�������ʹ�ľָ��������ȥ��\n",
			get_pic( PlayerCard[id], 1, 1 ) ));
	}
	return 1;
}

protected int do_is_ready()
{
	object me = this_player();
	string t, *p;

	if( !me || !userp(me) )
		return 0;
	t = getuid(me);
	if( !GAME_ON || GameNow != "�ľ����ڽ��У�[�ȴ���ҽ��Ʒ���]" || !GameSettings[ "is_dp9" ]
	 || !PlayerBet || !sizeof(PlayerBet) )
		return 0;
	p = keys(PlayerBet) + ({ GameSettings["host_id"]} );
	if( member_array( t, p ) == -1 || member_array( t, NoReadyPlayers ) == -1 )
		return 0;

	NoReadyPlayers -= ({ t });
	set_del_no_msg_env( me,"del" );
	message_p9( sprintf( HIW"%s ׼�����ˣ�\n"NOR, t, ), p );
	if( sizeof( NoReadyPlayers ) < 1 )
	{
		remove_call_out( "game_running_ready_open" );
		call_out( "game_running_ready_open", 1, "�����˶�׼������" );
	}
	return 1;
}

protected int do_join_game( int bet )
{
	object me = this_player();
	string id;
	int i;

	if( !me || !userp(me) )
		return 0;

	if( !GAME_ON )
		return notify_fail("�Բ���["+GAME_NAME+"] ��ͣ���š�\n");
	if( GameNow != "�ȴ���Ҽ���" )
		return notify_fail("�Բ������ڵ�ʱ�������ܼ���ľ֡�\n");
	id = getuid(me);
	if( GameSettings["host_id"] == id )
		return notify_fail("��һ������ׯ�ҡ�\n");
	if( PlayerBet[ id ] )
		return notify_fail("���Ѿ�����ľ��ˣ�\n");
	if( sizeof(PlayerBet) >= GameSettings[ "p_amount" ] )
		return notify_fail("�Բ��𣬱��ֶľ��Ѿ������ˡ�\n");
	if( bet > (i=me->query( GAME_SCORE_DATA )) )
		return notify_fail( sprintf( 
			"���%sֻ�� %d ������Ѻ���� %d ��ô��ɡ�\n",
				GAME_SCORE_NAME, i, bet ) );
	if( bet < GameSettings[ "b_min" ] || bet > GameSettings[ "b_max" ] )
		return notify_fail( sprintf(
			"Ѻע��Χ�� %d - %d �㣡\n",
				GameSettings[ "b_min" ], GameSettings[ "b_max" ] ));
	// ok.
	me->add( GAME_SCORE_DATA, -bet );
	HostScore += bet;
	PlayerBet[ id ] = bet;
	// ������Ϸ����ң���ȻҪ������Ϸ����Ϣ
	set_del_no_msg_env( me,"del" );
	message_p9( sprintf( HIW"%s(%s)Ѻ����%s %d �������˶ľ֡�\n",
			me->query("name"), id, GAME_SCORE_NAME, bet, ));
	write( sprintf( "������˶ľ֣�Ѻ��%s %d �󣬻�ʣ�� %d ��\n",
		GAME_SCORE_NAME, bet, me->query( GAME_SCORE_DATA ) ));
	if( sizeof(PlayerBet) >= GameSettings[ "p_amount" ] )
	{
		remove_call_out( "game_running_start" );
		call_out( "game_running_start",1);
	}
	return 1;
}

protected int do_showcards()
{
	write( CLR + "\n�ƾ�ȫ��ͼ��һ����\n" + get_show_all_msg( P9_BASE, 1 ) );
	return 1;
}

protected int do_chk( string arg )
{
	object who;

	if( !arg || arg == "" )
		return notify_fail( "��Ҫ��ѯ˭��"+GAME_SCORE_NAME+"��\n");

	if( !(who=find_player(arg)) )
		return notify_fail( "���ڲ�û�� ["+arg+"] ���������ߡ�\n");

	write( sprintf( "%s(%s) ����%s�� %d\n",
		who->query("name"), who->query("id"), GAME_SCORE_NAME, who->query( GAME_SCORE_DATA ) ));
	return 1;
}

protected int help_cmds()
{
	write( sprintf( 
BGRN+HIY"[ %s(%s) ָ����� ]"NOR"

------[����]---------------[˵��]---------------------[��Чʱ��]---------

  check(��ʡ��)        ��ѯ�����Ч���֡���Ϸ״̬      ����ʱ��

  chk ����ID           ��ѯ���˵���Ч����              ����ʱ��

  set no_p9_msg        ���á������ձ���Ϸ�Ĺ�����Ϣ��  ����ʱ��

  unset no_p9_msg      ȡ������                        ����ʱ��

  showcards            �鿴�����Ƶ�ͼ��ʾ��            ����ʱ��

  new                  ����һ���µĶľ�                �޶ľ�ʱ

  in ��ע(����)        ��Ϊ�мҼ���ľ�                �ľ��ѿ�ʼ����
                                                       �ڵȴ���Ҽ���ʱ
  card ���д���        ���ƾŶľ�ʱ��������Ʒ���      ��Ϸ��ʼ������ʾ

  ok                   ���ƾŶľ�ʱ����ʾ���ѷֺ��顱  �� [card] ͬһʱ��

  wiz                  ��ʦ������������ʦʹ��          ����ʱ��

                                            By �κ�(naihe) 2004-04
-------------------------------------------------------------------------\n",
	GAME_NAME, GAME_VERSION ));
	return 1;
}


int main( object me, string arg )
{
	string t;
	int i;

	if( !me || !userp(me) )
		return 0;

//	����ط���Ҫ������жϣ��ɸ������Լ�ȥ��
//	if( !GAME_ON )
//		return notify_fail( sprintf( "[%s] ��ͣ���š�\n", GAME_NAME));

	if( !arg )
		arg = "check";

	// ������ȷ���ģ��� if() �ж�
	// ��ʦ����ָ��
	if( arg == "wiz" || sscanf(arg, "wiz %s", t) )
		return do_wiz( t );

	// �κ���Ҿ��ɲ�ѯ���˵Ļ���
	if( arg == "chk" || sscanf(arg, "chk %s", t) )
		return do_chk( t );

	// ����ʱ��ָ����Լ�
	if( sscanf( arg,"%*d %*d %*d %*d" ) )
		arg = "card "+arg;

	// ���ƾ�ʱ����ҿɽ��Ƶ�˳��ı䣬������
	if( strlen(arg) > 3 && arg[0..3] == "card" )
		return do_lineup_card( arg );

	// ����׼�����ˡ�
	if( arg == "ok" || arg == "ready" )
		return do_is_ready();

	// ������Ϸ
	if( arg == "in" || sscanf( arg, "in %d", i) )
		return do_join_game( i );
	// ͬ���Ǽ�����Ϸ��������ȷ��Ӣ��
	if( arg == "join" || sscanf( arg, "join %d", i)) 
		return do_join_game( i );

	// �̶������ģ������� switch() ���ж�
	switch( arg )
	{
		case "help":
			return help();

		case "help cmds":
		case "help cmd":
		case "help commands":
		case "help command":
			return help_cmds();

		case "set no_p9_msg":
			set_del_no_msg_env( me, "set" );
			return 1;

		case "unset no_p9_msg":
			set_del_no_msg_env( me, "del" );
			return 1;

		case "check":
			return do_check_now();

		case "showcards":
			return do_showcards();

		case "new":
		case "start":
			do_start_game(); // �ں� input_to() ���裬���Բ�ֱ�� return �ú���
			return 1;
	}

	write( "û�� \""+arg+"\" ������������Բ��� [help] �� [help cmds] ��ѯ˵����\n");
	return 1;
}
