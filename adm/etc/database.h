// database.h

// �Ƿ������������
#define STATIC_LINK
// �Ƿ����״̬
// #define DEBUG
// �Ƿ������վ�����ע��
// #define REFUSE_NEW_PLAYER

protected mapping all_others_db = ([
        // "61.184.100.7" : "nitan.dx",
]);

protected mapping stations = ([
        "218.89.171.162" : "����̶����վ��",
        "61.184.100.7"   : "����̶�����š�",
        "202.110.119.87" : "����̶����ͨ��",
        "219.134.89.94"  : "����̶�����ڡ�",
]);

#ifndef DATABASE
protected string DATABASE               = "nitan";
#endif
#ifndef DB_USER
protected string DB_USER                = "nitan";
#endif
protected string USER_TABLE             = "users";
protected string IP_TABLE               = "ip";
protected string NEWS_TABLE             = "news";
protected string ITEM_TABLE             = "item";
protected string ITEM_OWNER_TABLE       = "item_owner";
protected string ITEM_MAGIC_SAN_TABLE   = "item_magic_san";

// ���õļ����㷨
protected string DB_CRYPT               = "PASSWORD";
