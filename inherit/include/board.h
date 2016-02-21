// board.h

// ����ǰ׺
#define TABLE_PREFIX    "phpbb_"

#define TOPICS_TABLE    TABLE_PREFIX "topics"
#define FORUMS_TABLE    TABLE_PREFIX "forums"

#define POSTS_TABLE     TABLE_PREFIX "posts"
#define TEXTS_TABLE     TABLE_PREFIX "posts_text"

#define USERS_TABLE     TABLE_PREFIX "users"

#define DEBUG_MSG(x)    tell_object(find_player("lonely"), HIR + x + NOR);

#define POST_ID         0       // ���±��
#define TOPIC_ID        1       // ������
#define POSTER_ID       2       // ��������
#define POST_TIME       3       // ����ʱ��

#define POST_SUBJECT    0       // ���±���
#define BBCODE_UID      1       // bbcode �ļ�����
#define POST_TEXT       2       // ��������

#define TOPIC_TITLE     0       // �������
#define TOPIC_POSTER    2       // ��������
#define TOPIC_TIME      3       // ����ʱ��
#define TOPIC_VIEWS     4       // �����������
#define TOPIC_REPLIES   5       // ����ظ�
#define TOPIC_FIRST_ID  6       // �����������

// BBS ģʽ(��ʾ���е����£������ظ�)
int is_bbs_mode(object me) { return (me->query("env/board_mode") == 0); }
// Web ��̳ģʽ(ֻ��ʾ���⣬�ظ��ڲ쿴����ʱ����ʾ)
int is_web_mode(object me) { return (me->query("env/board_mode") == 1); }

// ��ʾ�ظ��ķ�ʽ
#define SHOW_NONE       0       // ����ʾ
#define SHOW_LAST       1       // ��ʾ���һƪ
#define SHOW_ALL        2       // ��ʾ����

// Web ��̳��ַ
#define WEB_URL         "http://www.mudbuilder.com/phpbb/"
#define FORUM_URL       WEB_URL "viewforum.php?f=%d"    // ����ҳ���ַ
#define TOPIC_URL       WEB_URL "viewtopic.php?t=%d"    // ����ҳ���ַ

