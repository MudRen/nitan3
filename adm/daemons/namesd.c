/**********************************************************************************
*                                                                                 *
*       NameD.c �������ɳ���                                                      *
*                                                                                 *
***********************************************************************************/

// By Zen(SnowMan.ZD) 19/09/2002
// Modified by Zen(SnowMan.ZD) 01/06/2003

// ͷ�ļ���ƴ�� <-> ����һһ��Ӧ��

#include <names.h>

protected nosave nomask int sur_size, f_size, m_size;
protected nosave nomask string *key_sur = ({ });
protected nosave nomask string *key_fname = ({ });
protected nosave nomask string *key_mname = ({ });

nomask int query_sur_size(){ return sur_size; }
nomask int query_f_size(){ return f_size; }
nomask int query_m_size(){ return m_size; }

void create() 
{ 
        seteuid( getuid() ); 
        key_sur = keys(sur_name);
        key_fname = keys(f_name);
        key_mname = keys(m_name);
        sur_size = sizeof(sur_name);
        f_size = sizeof(f_name);
        m_size = sizeof(m_name);
}

nomask string *query_s_name(string str)
{       
        if( str )
                return sur_name[str];

        return key_sur; 
}
nomask string *query_m_name(string str)
{       
        if( str )
                return m_name[str];

        return key_mname; 
}
nomask string *query_f_name(string str)
{       
        if( str )
                return f_name[str];

        return key_fname; 
}

void remove()
{
}

protected nomask string *selete_namestring(string key, int sex)
{ 
        if( sex )
                return f_name[key]; 
        return m_name[key];
} 

/*
����һ��mapping��
        ([ name : "xxx", id : ({ "xxx", "xxx" }) ])
        name Ϊ����������id Ϊƴ����
        �磺
                ([ name : "��ԲԲ", id : ({ "gao yuanyuan", "gao", "yuanyuan" }) ])
        
����ָ���İ�����
 gender = �Ա�, 1 = female, 0 = male.
 long_name = ���ӵ���Ŀ��long_name = -1�� ֻ��һ�����֣�long_name = 0���漴1-2�����֣�long_name > 0���������֡�
 name_a = ��
 name_b = ��
 name_c = �м���, �� һ���� �� ����

���ӣ�
        random_name(0, 0, 0, 0, 0) -> ���������������Ϊ���һ���������֡�
        random_name(1, 0, 0, 0, 0) -> ���Ů����������Ϊ���һ���������֡�
        random_name(0, 1, 0, 0, 0) -> ��������������������֡�
        random_name(0, -1, 0, 0, 0) -> ���������������һ���֡�
        random_name(1, 1, 0, 0, 0) -> ���Ů���������������֡�
        random_name(0, -1, 0, 0, 0) -> ���Ů����������һ���֡�
        
        random_name(0, 0, "��", 0, 0) -> ���գ���Ϊ���Ϊ���һ���������֡�
        random_name(0, 0, 0, "ǿ", 0) -> ���գ����������Ϊ���һ���������֣������һ����Ϊǿ��
        random_name(0, 1, "��", "ǿ", 0) -> ���գ������Ϊ�����֣����һ����Ϊǿ���м������
        random_name(0, 1, "��", 0, "ǿ") -> ���գ������Ϊ�����֣��м�һ����Ϊǿ����������
        
        random_name(0, 0, 0, 0, "ǿ") -> ���գ���������������������������֣��м�һ����Ϊǿ��
*/
varargs nomask mapping random_name(int gender, int long_name, string name_a, string name_b, string name_c)
{       
        string str, str2, key, *names, vor, nach;
        int i;

        // write("name_a = " + name_a + ", name_b = " + name_b + ", name_c = " + name_c + "\n");
        
        // �������ա�
        if( name_a ){
                if( member_array(name_a, key_sur) != -1 ){
                        str = name_a;
                        vor = sur_name[str];
                }
        }
        else {
                i = random(sur_size);
                str = key_sur[i];
                vor = sur_name[str];
        }
        
        // �����û������֡�
        if( !str || !vor )
                return 0;
        
        
        // �������м�����(��long_name)��������(��long_name)��
        if( name_b ){
                if( gender ){
                        i = f_size;
                        while( i-- ){
                                if( member_array(name_b, f_name[key_fname[i]]) != -1 ){
                                        str2 = name_b;
                                        nach = key_fname[i];
                                        break;
                                }
                        }
                }
                else {
                        i = m_size;
                        while( i-- ){
                                if( member_array(name_b, m_name[key_mname[i]]) != -1 ){
                                        str2 = name_b;
                                        nach = key_mname[i];
                                        break;
                                }
                        }
                }
        }
        
        else {  
                if( gender ){
                        i = random(f_size);
                        key = key_fname[i];
                }
                else {
                        i = random(m_size);
                        key = key_mname[i];
                }
        
                names = selete_namestring(key, gender);
                str2 = names[random(sizeof(names))];
                nach = key;
        }
        
        // �����û������֡�
        if( !str2 || !nach )
                return 0;
                
        // long_name = -1�� ֻ��һ�����֣�long_name = 0���漴1-2�����֣�long_name > 0���������֡�
        if( ((!random(3) && !long_name) || long_name > 0) && long_name >= 0 ){
                if( name_c ){
                        if( gender ){
                                i = f_size;
                                while( i-- ){
                                        if( member_array(name_c, f_name[key_fname[i]]) != -1 ){
                                                str2 = name_c + str2;
                                                nach = key_fname[i] + nach;
                                                break;
                                        }
                                }
                        }
                        else {
                                i = m_size;
                                while( i-- ){
                                        if( member_array(name_c, m_name[key_mname[i]]) != -1 ){
                                                str2 = name_c + str2;
                                                nach = key_mname[i] + nach;
                                                break;
                                        }
                                }
                        }
                }
                else {
                        if( gender ){
                                i = random(f_size);
                                key = key_fname[i];
                        }
                        else {
                                i = random(m_size);
                                key = key_mname[i];
                        }
                        names = selete_namestring(key, gender);
                        str2 = names[random(sizeof(names))] + str2;
                        nach = key + nach;
                }
        }

        return ([ "name": str + str2,  "id": ({ vor + " " + nach, vor, nach }) ]); 
}

// End Of File.

