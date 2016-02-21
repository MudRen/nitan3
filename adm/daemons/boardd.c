// boardd.c
// Created by jjgod. 2002/01/29.
// Updated by jjgod. 2002/06/16.
// Finishd by jjgod. 2002/06/28.

// databased.c �ṩ�ĺ�����(* Ϊ��δ���)
// 
// �������
//   int    query_forum_id()       - ��ѯ���� ID
//   mixed  query_forum_info()     - ��ѯ������Ϣ
//   string query_mud_name()       - ��ѯ�û���('����-jjgod' ��ʽ)
//   string query_user_name()      - ��ѯ�û� ID('jjgod' ��ʽ)
//   int    query_user_id()        - ��ѯ�û����
//   int    query_post_id()        - ��ѯ���±��
//   int    query_topic_id()       - ��ѯ������

// ���¹���
//   mixed *query_all_topics()     - ������������(�������ظ�) -+
//   mixed *query_all_posts()      - ������������(�����ظ�)   -+- ���߸�ʽ��ͬ
//   mixed *query_post_info()      - ������������(���� POST_ID)
//   mixed *query_topic_info()     - ������������(���� TOPIC_ID)
//   mixed *query_new_post()       - ����δ������(���ݲ�ͬ���ģʽ�������������������)
//   mixed *query_post()           - �����û�ָ���ı���ҵ�Ӧ��������
//   int    query_topic_number()   - ��������ı��
//   int   *query_number_post()    - ��������ҵ����µ� POST_ID
//   int   *query_number_topic()   - ��������ҵ������ TOPIC_ID / POST_ID
//   mixed *query_post_data()      - ����ָ����������

// ���·����ظ���ɾ����
//   int   delete_topic()          - ɾ��ָ����ŵ�����
//   int   delete_post()           - ɾ��ָ����ŵ�����
//   int   reply_topic()           - �ظ�����
//   int   add_topic_view()        - ����������������
//   int   post_new_topic()        - ����������

#pragma optimize
#pragma save_binary

#ifdef DB_SAVE

#include <ansi.h>
#include <board.h>
#include <mudlib.h>

#include "/adm/etc/database.h"
#define DEBUG 

#ifdef STATIC_LINK
protected int db_handle = 0;
#endif

int    query_forum_id(object board);
int    query_post_id(int forum_id, int post_time);
int    query_topic_id(int forum_id, string title);
int    query_topic_number(object board, int topic_id);
int   *query_number_topic(object board, int num, int mode);
int   *query_number_post(object board, int num);
string query_user_name(int user_id);
string query_mud_name(int user_id);
mixed  query_forum_info(object board, string key);
mixed *query_all_replies(int topic_id, int first_post_id);
mixed *query_post_data(int post_id);

varargs mixed *query_post_info(int post_id, int raw);
varargs mixed *query_all_topics(object board, int raw);
varargs mixed *query_topic_info(int topic_id, int raw);
varargs int    add_topic_view(int topic_id, int count);

protected void log_error(string func, mixed err)
{
        log_file("boardd", sprintf("%s ERROR ** %s\n%O\n", func, ctime(time()), err));
}

int query_db_status()
{
        mixed *ret;
               
#ifdef STATIC_LINK
        ret = DATABASE_D->db_fetch_row("SHOW DATABASES");
        if (db_handle && arrayp(ret) && sizeof(ret) > 0)
                return 1;
#endif
        return 0;
}

#ifdef STATIC_LINK
protected void connect_to_database()
#else
protected int connect_to_database()
#endif
{
        mixed n;

        n = db_connect(DB_HOST, DATABASE, DB_USER);

        if (intp(n) && (n > 0))  // ���ӳɹ�
#ifdef STATIC_LINK
        {
                db_handle = n;
                return;
        }
#else
                return n;
#endif

        else
        {
                log_error("db_connect", n);
#ifdef STATIC_LINK
                call_out("connect_to_database", 30);
                return;
#endif
                return 0;
        }
}

protected void close_database(int db)
{
        mixed ret;

        if (! intp(db) || (db < 1))
                return 0;

        ret = db_close(db);

        if (intp(ret) && (ret == 1))
                return;

        else
                log_error("db_close", ret);
}

protected void create()
{
        seteuid(ROOT_UID);
#ifdef STATIC_LINK
        // connect_to_database();
        db_handle = DATABASE_D->query_db_handle();
#endif
}

protected int valid_caller()
{
        // ! ע�⣬��ʽվ��һ��Ҫ����������ɾ�� !
#ifdef DEBUG
        return 1;
#else
        // ! ע�⣬��ʽվ��һ��Ҫ����������ɾ�� !

        if (! previous_object() ||
           (previous_object() != find_object(SIMUL_EFUN_OB)) &&
           (! inherits(DATABASE_BOARD, previous_object())))
                return 0;

        else
                return 1;
#endif
}

/*
#ifdef STATIC_LINK
void remove(string id)
{
        if (! valid_caller())
                return;

        close_database(db_handle);
}
#endif
*/

int query_forum_id(object board)
{
        string forum_name;
        int forum_id;
        int db;
        mixed ret, *res;
        string sql;

        if (! valid_caller())
                return 0;

        if (! objectp(board))
                return 0;

        if (! stringp(forum_name = board->query("forum_name")))
        {
                log_error("query_forum_id", board->query("board_id") +
                          " have no forum name.");
                return 0;
        }

        if (intp(forum_id = board->query("forum_id")) && forum_id != 0)
                return forum_id;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT forum_id FROM %s WHERE forum_name = \"%s\"",
                      FORUMS_TABLE, forum_name);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("query_forum_id.db_exec", ret);

        if (sizeof(res = db_fetch(db, 1)) && intp(res[0]))
                forum_id = res[0];

#ifndef STATIC_LINK
                close_database(db);
#endif

        board->set("forum_id", forum_id);
        return forum_id;
}

// ��ѯ������Ϣ
mixed query_forum_info(object board, string key)
{
        int forum_id;
        int db;
        mixed ret, *res;
        string sql;

        if (! valid_caller())
                return 0;

        if (! objectp(board))
                return 0;
#ifndef DEBUG
        if (! undefinedp(ret = board->query(key)))
                return ret;
#endif
        if (! forum_id = query_forum_id(board))
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT %s FROM %s WHERE forum_id = %d",
                      key, FORUMS_TABLE, forum_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("query_forum_info.db_exec", ret);

        if (sizeof(res = db_fetch(db, 1)) && ! undefinedp(res[0]))
                ret = res[0];

#ifndef STATIC_LINK
                close_database(db);
#endif

#ifndef DEBUG
        board->set(key, ret);
#endif
        return ret;
}

// ��û���������ݿⱣ���û����ݵĹ�������Ҫ�޸� NAME_D ���ṩ���Ƶ�
// �� id ת��Ϊ name �Ĺ���
string query_mud_name(int user_id)
{
        string user_name = query_user_name(user_id);

        return sprintf("%s-%s", DATABASE_D->db_query_user(user_name, "name"),
                       user_name);
}

// �� Web ���ݿⱣ����û� id(���� 1��2 ������)ת��Ϊ mud �е� id��
// �� Web ��̳�ϵ��û���
string query_user_name(int user_id)
{
        int db;
        mixed ret, *res;
        string sql;
        string user_name;

        if (! valid_caller())
                return 0;

        if (! intp(user_id) || ! user_id)
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT username FROM %s WHERE user_id = %d",
                      USERS_TABLE, user_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("query_user_name.db_exec", ret);

        if (sizeof(res = db_fetch(db, 1)) && stringp(res[0]))
                ret = res[0];

#ifndef STATIC_LINK
                close_database(db);
#endif
        return ret;
}

// �������е�����(�ظ����������⣬����)
varargs mixed *query_all_topics(object board, int raw)
{
        int forum_id;
        int db, i;
        mixed ret, *res;
        string sql;

        if (! valid_caller())
                return 0;

        if (! objectp(board))
                return 0;

        if (! forum_id = query_forum_id(board))
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT topic_title, topic_id, topic_poster,"
                      " topic_time%s"
                      " FROM %s WHERE forum_id = %d ORDER BY topic_time",
                      raw ? "" : ", topic_views, topic_replies, topic_first_post_id",
                      TOPICS_TABLE, forum_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("query_all_topics.db_exec", ret);

        res = ({ });
        i = 1;
        while (sizeof(ret = db_fetch(db, i)))
        {
                res += ({ ret });
                i++;
        }
#ifndef STATIC_LINK
                close_database(db);
#endif
        return res;
}

// ��ѯһ�� board ���е�����(�����ظ�)
// ({ ���±��, ����������, ���ߺ�, ����ʱ�� })
mixed *query_all_posts(object board)
{
        int forum_id;
        int db, i;
        mixed ret, *res;
        string sql;

        if (! valid_caller())
                return 0;

        if (! objectp(board))
                return 0;

        if (! forum_id = query_forum_id(board))
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT post_id, topic_id, poster_id, post_time"
                      " FROM %s WHERE forum_id = %d ORDER BY post_time",
                      POSTS_TABLE, forum_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("query_all_posts.db_exec", ret);

        res = ({ });
        i = 1;
        while (sizeof(ret = db_fetch(db, i)))
        {
                res += ({ ret });
                i++;
        }
#ifndef STATIC_LINK
                close_database(db);
#endif
        return res;
}

// ��ѯһƪ���µ���ϸ��Ϣ
// ({ ����, BBCODE ������, ���� })
varargs mixed *query_post_info(int post_id, int raw)
{
        int db;
        mixed ret, *res;
        string sql;

        if (! valid_caller())
                return 0;

        if (! intp(post_id) || ! post_id)
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT post_subject, bbcode_uid%s"
                      " FROM %s WHERE post_id = %d",
                      raw ? "" : ", post_text", TEXTS_TABLE,
                      post_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("query_post_info.db_exec", ret);

        if (sizeof(res = db_fetch(db, 1)))
                ret = res;
#ifndef STATIC_LINK
                close_database(db);
#endif
        return ret;
}

// ��ѯһƪ�������ϸ��Ϣ
// ({ ����, ���, �����߱��, ����ʱ��, �������, �ظ���, ������� })
varargs mixed *query_topic_info(int topic_id, int raw)
{
        int db;
        mixed ret, *res;
        string sql;

        if (! valid_caller())
                return 0;

        if (! intp(topic_id) || ! topic_id)
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT topic_title, topic_id, topic_poster,"
                      " topic_time%s"
                      " FROM %s WHERE topic_id = %d",
                      raw ? "" : ", topic_views, topic_replies, topic_first_post_id",
                      TOPICS_TABLE, topic_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("query_topic_info.db_exec", ret);

        if (sizeof(res = db_fetch(db, 1)))
                ret = res;
#ifndef STATIC_LINK
                close_database(db);
#endif
        return ret;
}

// ��ѯһ���������еĻظ�(����������)
// ({ ���±��, ����������, ���ߺ�, ����ʱ�� })
mixed *query_all_replies(int topic_id, int first_post_id)
{
        int db, i;
        mixed ret, *res;
        string sql;

        if (! valid_caller())
                return 0;

        if (! intp(topic_id) || ! topic_id)
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT post_id, topic_id, poster_id, post_time"
                      " FROM %s WHERE topic_id = %d AND post_id != %d"
                      " ORDER BY post_time",
                      POSTS_TABLE, topic_id, first_post_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("query_all_replies.db_exec", ret);

        res = ({ });
        i = 1;
        while (sizeof(ret = db_fetch(db, i)))
        {
                res += ({ ret });
                i++;
        }
#ifndef STATIC_LINK
                close_database(db);
#endif
        return res;
}

// ����һƪ����ı��
int query_topic_number(object board, int topic_id)
{
        int num, i, max;
        mixed *posts;

        posts = query_all_posts(board);
        max = sizeof(posts);

        for (i = 0; i < max; i++)
        {
                if (posts[i][TOPIC_ID] == topic_id)
                        return (i + 1);
        }
}

// �����û��������û� id
int query_user_id(string user_name)
{
        int db;
        mixed ret, *res;
        string sql;

        if (! valid_caller())
                return 0;

        if (! stringp(user_name))
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT user_id FROM %s WHERE username = \"%s\"",
                      USERS_TABLE, user_name);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("query_user_id.db_exec", ret);

        if (sizeof(res = db_fetch(db, 1)))
                ret = res[0];

#ifndef STATIC_LINK
                close_database(db);
#endif
        return ret;
}

// ��������ı��
int query_topic_id(int forum_id, string title)
{
        int db;
        mixed ret, *res;
        string sql;

        if (! valid_caller())
                return 0;

        if (! stringp(title))
                return 0;

        if (! intp(forum_id) || ! forum_id)
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT topic_id FROM %s WHERE forum_id = %d"
                      " AND topic_title = \"%s\"",
                      TOPICS_TABLE, forum_id, title);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("query_topic_id.db_exec", ret);

        if (sizeof(res = db_fetch(db, 1)))
                ret = res[0];

#ifndef STATIC_LINK
                close_database(db);
#endif
        return ret;
}

// �������µı��
int query_post_id(int forum_id, int post_time)
{
        int db;
        mixed ret, *res;
        string sql;

        if (! valid_caller())
                return 0;

        if (! intp(post_time) || ! post_time)
                return 0;

        if (! intp(forum_id) || ! forum_id)
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT post_id FROM %s WHERE forum_id = %d"
                      " AND post_time = %d",
                      POSTS_TABLE, forum_id, post_time);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("query_post_id.db_exec", ret);

        if (sizeof(res = db_fetch(db, 1)))
                ret = res[0];

#ifndef STATIC_LINK
                close_database(db);
#endif
        return ret;
}

// �� "127.0.0.1" ת��Ϊ 7F000001 ������ 16 ���Ƶ�ַ
string convert_to_ip(string ip)
{
        string *ips;
        string hex_ip;
        
        ips = explode(ip, ".");
        hex_ip = "";

        foreach (ip in ips)
                hex_ip += sprintf("%2'0'X", atoi(ip));

        return hex_ip;
}

// ����������
int post_new_topic(object board, string title, string name, string text, string ip)
{
        int db;
        mixed ret;
        string sql;
        int forum_id;
        int poster_id;
        int topic_id;
        int post_id;
        int t;

        if (! valid_caller())
                return 0;

        if (! objectp(board))
                return 0;

        if (! forum_id = query_forum_id(board))
                return 0;

        if (! poster_id = query_user_id(name))
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        // ��������
        t = time();
        sql = sprintf("INSERT INTO %s (topic_title, topic_poster, topic_time, forum_id)"
                      " VALUES (\"%s\", %d, %d, %d)",
                      TOPICS_TABLE, title, poster_id, t, forum_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("post_new_topic.db_exec", ret);

        // ��������
        topic_id = query_topic_id(forum_id, title);
        sql = sprintf("INSERT INTO %s (topic_id, forum_id, poster_id, post_time, poster_ip)"
                      " VALUES (%d, %d, %d, %d, \"%s\")", 
                      POSTS_TABLE, topic_id, forum_id, poster_id, t, convert_to_ip(ip));
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("post_new_topic.db_exec", ret);
                
        // ������������
        post_id = query_post_id(forum_id, t);
        sql = sprintf("INSERT INTO %s (post_id, post_subject, bbcode_uid, post_text)"
                      " VALUES (%d, \"%s\", \"\", \"%s\")", 
                      TEXTS_TABLE, post_id, title, text);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("post_new_topic.db_exec", ret);
        
        // �趨���� id
        sql = sprintf("UPDATE %s SET topic_first_post_id = %d, topic_last_post_id ="
                      " %d WHERE topic_id = %d", TOPICS_TABLE, post_id, post_id, topic_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("post_new_topic.db_exec", ret);

        // �����û�������
        sql = sprintf("UPDATE %s SET user_posts = user_posts + 1 WHERE user_id ="
                      " %d", USERS_TABLE, poster_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("post_new_topic.db_exec", ret);

        // ���Ӱ������⡢������
        sql = sprintf("UPDATE %s SET forum_posts = forum_posts + 1, "
                      "forum_topics = forum_topics + 1, forum_last_post_id = "
                      "%d WHERE forum_id = %d",
                      FORUMS_TABLE, post_id, forum_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("post_new_topic.db_exec", ret);

#ifndef STATIC_LINK
                close_database(db);
#endif
        return 1;
}

// ����������������
varargs int add_topic_view(int topic_id, int count)
{
        int db;
        mixed ret;
        string sql;

        if (! valid_caller())
                return 0;

        if (! intp(topic_id) || ! topic_id)
                return 0;

        // Ĭ������һ��
        if (! count) count = 1;

        if (count <= 0)
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("UPDATE %s SET topic_views = topic_views + %d"
                      " WHERE topic_id = %d",
                      TOPICS_TABLE, count, topic_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("add_topic_view.db_exec", ret);

#ifndef STATIC_LINK
                close_database(db);
#endif
        return ret;
}

// ��ѯָ�� post_id ����������
mixed *query_post_data(int post_id)
{
        int db;
        mixed ret, *res;
        string sql;

        if (! valid_caller())
                return 0;

        if (! post_id)
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = sprintf("SELECT post_id, topic_id, poster_id, post_time"
                      " FROM %s WHERE post_id = %d",
                      POSTS_TABLE, post_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("query_post_data.db_exec", ret);

        if (sizeof(res = db_fetch(db, 1)))
                ret = res;

#ifndef STATIC_LINK
                close_database(db);
#endif
        return ret;
}

// �����û�ָ���ı���ҵ������ id
int *query_number_topic(object board, int num, int mode)
{
        mixed *posts;
        int max;

        if (! valid_caller())
                return 0;

        posts = mode ? query_all_posts(board)
                     : query_all_topics(board);

        if (! arrayp(posts) ||
            ! (max = sizeof(posts)) ||
            num > 0 && num > max - 1 ||
            num < 0 && -num > max)
                return 0;

        // �� num < 0���򷵻ص��������� id
        if (num < 0) return posts[max + num][TOPIC_ID];

        return posts[num][TOPIC_ID];
}

// �����û�ָ���ı���ҵ����µ� id
int *query_number_post(object board, int num)
{
        mixed *posts;
        int max;

        if (! valid_caller())
                return 0;

        posts = query_all_posts(board);

        if (! arrayp(posts) ||
            ! (max = sizeof(posts)) ||
            num > 0 && num > max - 1 ||
            num < 0 && -num > max - 1)
                return 0;

        // �� num < 0���򷵻ص��������� id
        if (num < 0) return posts[max + num][TOPIC_ID];

        return posts[num][POST_ID];
}

// �ظ�����
int reply_topic(object board, int topic_id, string name, string text, string ip)
{
        int db;
        mixed ret;
        string sql;
        int forum_id;
        int poster_id;
        int post_id;
        int t;

        if (! valid_caller())
                return 0;

        if (! objectp(board))
                return 0;

        if (! forum_id = query_forum_id(board))
                return 0;

        if (! poster_id = query_user_id(name))
                return 0;

        if (! topic_id)
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif
        t = time();

        // ��������
        sql = sprintf("INSERT INTO %s (topic_id, forum_id, poster_id, post_time, poster_ip)"
                      " VALUES (%d, %d, %d, %d, \"%s\")", 
                      POSTS_TABLE, topic_id, forum_id, poster_id, t, convert_to_ip(ip));
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("reply_topic.db_exec", ret);
                
        // ������������
        post_id = query_post_id(forum_id, t);
        sql = sprintf("INSERT INTO %s (post_id, post_subject, bbcode_uid, post_text)"
                      " VALUES (%d, \"%s\", \"\", \"%s\")", 
                      TEXTS_TABLE, post_id, "", text);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("reply_topic.db_exec", ret);
        
        // �趨β�� id���ظ���һ��ʱ�����
        sql = sprintf("UPDATE %s SET topic_replies = topic_replies + 1, "
                      "topic_last_post_id = %d, topic_time = %d WHERE topic_id = %d",
                      TOPICS_TABLE, post_id, t, topic_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("reply_topic.db_exec", ret);

        // �����û�������
        sql = sprintf("UPDATE %s SET user_posts = user_posts + 1 WHERE user_id ="
                      " %d", USERS_TABLE, poster_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("reply_topic.db_exec", ret);

        // ���Ӱ���������
        sql = sprintf("UPDATE %s SET forum_posts = forum_posts + 1, "
                      "forum_last_post_id = %d WHERE forum_id = %d",
                      FORUMS_TABLE, post_id, forum_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("reply_topic.db_exec", ret);

#ifndef STATIC_LINK
                close_database(db);
#endif
        return 1;
}

// ɾ������
int delete_topic(object board, int topic_id)
{
        int db;
        int forum_id;
        mixed ret;
        mixed *posts, *post;
        string sql;

        if (! valid_caller())
                return 0;

        if (! topic_id)
                return 0;

        if (! forum_id = query_forum_id(board))
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        // ɾ������
        sql = sprintf("DELETE FROM %s WHERE topic_id = %d",
                      TOPICS_TABLE, topic_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("delete_topic.db_exec", ret);

        // ɾ�����б���������������
        posts = query_all_posts(board);
        foreach (post in posts)
        {
                if (post[TOPIC_ID] == topic_id)
                {
                        sql = sprintf("DELETE FROM %s WHERE post_id = %d",
                                      TEXTS_TABLE, post[POST_ID]);
                        db_exec(db, sql);
                }
        }

        // ɾ�����б�����������
        sql = sprintf("DELETE FROM %s WHERE topic_id = %d", 
                      POSTS_TABLE, topic_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("delete_topic.db_exec", ret);

        // ���ٰ������⡢������
        sql = sprintf("UPDATE %s SET forum_posts = forum_posts - %d, "
                      "forum_topics = forum_topics - 1 WHERE forum_id = %d",
                      FORUMS_TABLE, sizeof(posts), forum_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("reply_topic.db_exec", ret);

#ifndef STATIC_LINK
                close_database(db);
#endif
        return 1;
}

// ɾ������
int delete_post(object board, int post_id)
{
        int db;
        int forum_id;
        mixed ret;
        string sql;
        mixed *pdata, *tinfo;

        if (! valid_caller())
                return 0;

        if (! post_id)
                return 0;

        if (! forum_id = query_forum_id(board))
                return 0;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        pdata = query_post_data(post_id);
        tinfo = query_topic_info(pdata[TOPIC_ID]);

        // ��Ϊ��������ɾ�������������������
        if (tinfo[TOPIC_FIRST_ID] == post_id)
                return delete_topic(board, pdata[TOPIC_ID]);

        // ɾ����������
        sql = sprintf("DELETE FROM %s WHERE post_id = %d", 
                      TEXTS_TABLE, post_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("delete_post.db_exec", ret);

        // ɾ�����б�����������
        sql = sprintf("DELETE FROM %s WHERE post_id = %d", 
                      POSTS_TABLE, post_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("delete_post.db_exec", ret);

        // ���ٰ������⡢������
        sql = sprintf("UPDATE %s SET forum_posts = forum_posts - 1"
                      " WHERE forum_id = %d",
                      FORUMS_TABLE, forum_id);
        ret = db_exec(db, sql);

        if (! intp(ret))
                log_error("reply_topic.db_exec", ret);

#ifndef STATIC_LINK
                close_database(db);
#endif
        return 1;
}

int db_count_user()
{
        int db;
        mixed ret, *res;

#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        // ret = db_exec(db, sprintf("SELECT COUNT(*) AS NUM FROM %s", USERS_TABLE));
        ret = db_exec(db, sprintf("SELECT MAX(user_id) FROM %s", USERS_TABLE));
        if (! intp(ret) || (ret < 1))
        {
                log_error("count_reg_user", ret);
                return 0;
        }

        res = db_fetch(db, 1);
        
#ifndef STATIC_LINK
        close_database(db);
#endif        
        return res[0];
}

int db_create_user(object user)
{       
        int db, user_id;
        mixed ret;
        string sql;
        
        if (! objectp(user))
                return 0;
                
#ifdef STATIC_LINK
        if (! db_handle)
                return 0;
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif                
        user_id = db_count_user() + 1;
        sql = "insert into phpbb_users set user_id = " + DB_STR(user_id) +
              ", username = " + DB_STR(user->query("id")) + ", user_password = " + 
              DB_STR(user->query("ad_password")) + ", user_email = " +
              DB_STR(user->query("email"));

        ret = db_exec(db, sql);

#ifndef STATIC_LINK
                close_database(db);
#endif
        if (! intp(ret))
        {
                log_error("db_create_user.db_exec", ret);
                return 0;
        }

        return ret;
}

int db_remove_player(string id) 
{
        int db;
        string sql;
        mixed ret;

        if (! stringp(id) || id == "")
                return 0;
                
#ifdef STATIC_LINK
        if (! db_handle)
        {
                return 0;
        }
        db = db_handle;
#else
        if (! (db = connect_to_database()))
                return 0;
#endif

        sql = "delete from phpbb_users where username='" + id + "'";
        ret = db_exec(db, sql);
        if (! intp(ret))
        {
                log_error("db_delete.db_exec", ret + "\n" + sql);
                return 0;
        }
        if (ret < 1) return 0;
#ifndef STATIC_LINK
        close_database(db);
#endif
        return ret;
}

#endif
