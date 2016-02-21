// dbased.c ���ü�������ݿ�(���Լ�¼���еĳ�������Ʒ)
// ���ݿ��е�·����dbaseΪ�����ļ�·��Ϊ;����
// ����/d/city/kedian������󱣴������ݿ��еĽ��ǣ�
// /dbase/d/city/kedian�������������һ��mixed���ͣ��������
// restore���������õ�ʱ�򣬶�����뱣֤��receive_dbase_data
// �����������ձ��������ݿ��е����ݡ� �����󱣴��ʱ�����
// ����save_dbase_data����������Ҫ��������ݡ�
// write by Doing
// rewrite by Lonely add mysql

#include <ansi.h>

#pragma optimize
#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

#include "/adm/etc/database.h"

// �������ݵ�ӳ�����
mapping save_dbase;

// ���ú���announec_all_save_objectʱ��ı�־
#define ONLY_SAVE               0
#define DESTRUCT_OBJECT         1
nosave  int save_flag = ONLY_SAVE;

// �ڲ����õĺ���
protected int announce_all_save_object(int destruct_flag);

// �ṩ���ⲿ�ĺ���
mixed   query_data();
int     set_data(mixed data);
mixed   query_object_data(object ob);
int     set_object_data(object ob, mixed data);
mapping query_save_dbase();
string *query_saved_object();
int     clear_object(mixed ob);
int     remove(string euid);
void    mud_shutdown();

void create()
{
        seteuid(ROOT_UID);
        if (! restore() && ! mapp(save_dbase))
                save_dbase = ([]);

        // auto save per 15 minute (900s)
        set_heart_beat(450 + random(30));
}

// ���ݿ������������
int remove(string euid)
{
        if (previous_object() != find_object(SIMUL_EFUN_OB) ||
            ! is_root(euid))
        {
                // Must be called from simul_efun object
                return 0;
        }

        announce_all_save_object(save_flag);
        return 1;
}

// MUD��Ҫֹͣ����
void mud_shutdown()
{
        save_flag = DESTRUCT_OBJECT;
        destruct(this_object());
}

// ֪ͨ���е���Ҫ�������ݵĶ���
protected int announce_all_save_object(int destruct_flag)
{
        object ob;
        string *e;
        int i;

        if (mapp(save_dbase))
                e = keys(save_dbase);
        else
                e = ({ });
        // ֪ͨ���еĴ��̶��󱣴�����
        for (i = 0; i < sizeof(e); i++)
        {
                if (! stringp(e[i]))
                        // ��Ӧ�ò����ַ���
                        map_delete(save_dbase, e[i]);
                else
                if (objectp(ob = find_object(e[i])))
                {
                        // �ҵ��˴��̵Ķ���֪ͨ����
                        if (destruct_flag == DESTRUCT_OBJECT)
                                catch(destruct(ob));
                        else
                                catch(ob->save());
                }
        }

        save();
        return 1;
}

// �������ж���
int cleanup_all_save_object(int raw)
{
        //object ob;
        string *e;
        int i;

        if (mapp(save_dbase))
                e = keys(save_dbase);
        else
                return 1;

        // ֪ͨ���еĴ��̶��󱣴�����
        for (i = 0; i < sizeof(e); i++)
        {
                if (! stringp(e[i]))
                        // ��Ӧ�ò����ַ���
                        map_delete(save_dbase, e[i]);
                else
                if (file_size(e[i] + ".c") < 0)
                {
                        log_file("dbase", sprintf("data of (%s) cleaned because no found object.\n",
                                                  e[i]));
                        if (raw) map_delete(save_dbase, e[i]);
                }
        }

        save();
        return 1;
}

// �����������Զ��������е�����
protected int heart_beat()
{
        set_heart_beat(450 + random(30));
        announce_all_save_object(ONLY_SAVE);
}

string query_save_file() { return DATA_DIR + "dbased"; }

// ĳ�������ȡ�Լ��ļ�¼
mixed query_data()
{
        return query_object_data(previous_object());
}

// ĳ����������Լ��ļ�¼
int set_data(mixed data)
{
        return set_object_data(previous_object(), data);
}

// ��ȡĳ������ļ�¼
mixed query_object_data(mixed ob)
{
        string index;
        //mixed data;
        
        if (! ob) return 0;

        // ֻ��ROOT������Լ��ſ��Ա�����ȡ����
        if (! is_root(previous_object()) &&
            previous_object() != ob) return 0;

        if (stringp(ob))
        {
                index = ob;
                sscanf(index, "%s.c", index);
        } else
        if (objectp(ob))
                index = base_name(ob);
        else
                return 0;

#ifdef DB_SAVE
        mixed data;
        if (get_object(index)->is_item_make() ||
            get_object(index)->query("unique"))
        {
                if (! DATABASE_D->query_db_status())
                        DATABASE_D->connect_to_database();   
                        
                if (! DATABASE_D->query_db_status())
                        return save_dbase[index];

                data = DATABASE_D->db_restore_item(get_object(index));
                save_dbase[index] = data;
        }  
#endif
        return save_dbase[index];
}

// ����ĳ������ļ�¼
int set_object_data(mixed ob, mixed data)
{
        string index;

        if (! ob) return 0;

        // ֻ��ROOT������Լ��ſ��Ա�����ȡ����
        if (! is_root(previous_object()) &&
            previous_object() != ob) return 0;

        if (stringp(ob))
        {
                index = ob;
                sscanf(index, "%s.c", index);
        } else
        if (objectp(ob))
                index = base_name(ob);
        else
                return 0;

        if (! data)
        {
                map_delete(save_dbase, index);
                return 1;
        }
        
#ifdef DB_SAVE
        if (get_object(index)->is_item_make() || 
            get_object(index)->query("unique"))
        {
                if (! DATABASE_D->query_db_status())
                        DATABASE_D->connect_to_database();   
                
                DATABASE_D->db_remove_item(index);
                DATABASE_D->db_save_item(get_object(index)); 
        }      
#endif        
        save_dbase[index] = data;
        return 1;
}

// ��ȡ���ж���ļ�¼
mapping query_save_dbase()
{
        return save_dbase;
}

// ���ı��������ݵ����ж���
string *query_saved_object()
{
        return keys(save_dbase);
}

// ���һ������
int clear_object(mixed ob)
{
        string index;
        object xob;
        //object iob;

        // ����һ�����������ǰһ��ᱣ���Լ������ݣ�����һ�������ܵ�
        // ������Ҫ�ָ�����Ϊԭʼ״̬��ʱ��ͱ��������������Ȼ��
        // ����������ݡ�

        if (! ob) return 0;

        if (stringp(ob))
        {
                index = ob;
                sscanf(index, "%s.c", index);
                xob = find_object(index);
        } else
        if (objectp(ob))
        {
                xob = ob;
                index = base_name(xob);
        } else return 0;

        if (! is_root(previous_object()) &&
                previous_object() != xob) return 0;

#ifdef DB_SAVE
        object iob;
        if (objectp(iob = get_object(index)) && (iob->is_item_make() ||
            iob->query("unique")))
                DATABASE_D->db_remove_item(index);
                        
        if (iob) destruct(iob);
#endif
        if (xob) destruct(xob);
        map_delete(save_dbase, index);
        return 1;
}
