
//����������δ���ߵ�δ�����û�
#define UNREG_IDLE      90
//�Ƿ�ʹ��MYSQL���ݿ⼰�Ƿ�洢�û����ݵ�MYSQL�����ʹ�����ݿ���#undef DB_SAVE��
#undef DB_SAVE

//�Ƿ�洢�û����ݵ��ı��ļ�������� 1 �ͱ�ʾ�ǣ���������� 0 �ͱ�ʾ��
#define TX_SAVE         1
//�Ƿ�ʱΪ��ұ��浵��
#define AUTO_SAVE       1
// #define NO_QUIT_DROP

//������Ϸ����ҳ��ַ
#define URL "http://www.mudbuilder.com/"

//��������ж��ٸ�ͼ�����ʹ��
#define MAX_ICONS 2159

//��������Ʒ���������߱���
// #define AUTO_LOAD_ALL 1

//�ͻ���Ҫ��汾��
#define CURRENT_CLIENT_VERSION 2060

//�Դ���MYSQL���ַ�����ת��
#define DB_STR(x)    "'" + replace_string(x, "'", "''") + "'"

#define DM(x) "/adm/daemons/" x
#define TMI(x) (""+x+"")
#define TMA ""
#define TMB ""
#define INFO TMI
#define BASE_MENU "/adm/etc/base_menu.ini"
#define IP_ALLOW "/adm/etc/ip_allow.ini"
#define HEND sprintf("%c",18)

#define PTEXT(x) TMI("ptext "+x)
#define ALERT(x) TMI("alert "+x)
#define MTEXT(x) TMI("ptext "+x)
#define L_ITEM(x) RANK_D->new_short(x)
#define L_ICON(x) TMI("licon "+x)
#define CLEAN0  TMI("lbclear0")
#define ADD0(x) TMI("lbadd0 "+L_ITEM(x)+";")
#define REM0(x) TMI("lbrem0 "+L_ITEM(x)+";")
#define CLEAN1  TMI("lbclear1")
#define ADD1(x) TMI("lbadd1 "+L_ITEM(x)+";")
#define REM1(x) TMI("lbrem1 "+L_ITEM(x)+";")
#define CLEAN2  TMI("lbclear2")
#define ADD2(x) TMI("lbadd2 "+L_ITEM(x)+";")
#define REM2(x) TMI("lbrem2 "+L_ITEM(x)+";")
//���ﲻ���ж��壿

