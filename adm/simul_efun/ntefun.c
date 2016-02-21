
int range_random(int i, int j)
{
        return random(i<j?j-i+1:i-j+1)+((i<j)?i:j);
}

void add_slash(string path)
{
        if( path[<1] != '/' ) path += "/";
}

string *deep_path_list(string root)
{
        string file, *list=({});
        
        foreach( file in get_dir(root) )
        {
                if( file_size(root+file) == -2 )
                        list += deep_path_list(root+file+"/");
                else list += ({ root+file });
        }
        
        return list;
}

// ��ת arr ���У�ʹ���һ��Ԫ�ر�ɵ�һ��Ԫ�أ�Ԫ��λ����ȫ�Ե���
void reverse_array(string *arr)
{
        if( !arrayp(arr) || !sizeof(arr) )
                return;
                
        foreach( mixed element in arr )
                arr = ({ element }) + arr[0..<2];
}

/*
int mapping_eqv(mapping map1, mapping map2);

int array_eqv(mixed arr1, mixed arr2)
{
        int s_arr = sizeof(arr1);
        if( s_arr != sizeof(arr2) ) return 0;
        for(int i=0; i<s_arr; i++)
        {
                if( arrayp(arr1[i]) && arrayp(arr2[i]) )
                {
                        if( !array_eqv(arr1[i], arr2[i]) ) return 0;
                }
                else if( mapp(arr1[i]) && mapp(arr2[i]) )
                {
                        if( !mapping_eqv(arr1[i], arr2[i]) ) return 0;
                }
                else if( arr1[i] != arr2[i] ) return 0;
        }
        return 1;
}

int mapping_eqv(mapping map1, mapping map2)
{
        int m_arr = sizeof(map1);
        mixed m_keys1, m_keys2;

        if( m_arr != sizeof(map2) ) return 0;
        m_keys1 = keys(map1);
        m_keys2 = keys(map2);

        for(int i=0; i<m_arr; i++)
        {
                if( mapp(m_keys1[i]) && mapp(m_keys1[i]) )
                {
                        if( !mapping_eqv(m_keys1[i], m_keys2[i]) ) return 0;
                }
                else if( arrayp(m_keys1[i]) && arrayp(m_keys2[i]) )
                {
                        if( !array_eqv(m_keys1[i], m_keys2[i]) ) return 0;
                }
                else if( m_keys1[i] != m_keys2[i] )
                {
                        return 0;
                }
                
                // Value check
                if( mapp(map1[m_keys1[i]]) && mapp(map2[m_keys2[i]]) )
                {
                        if( !mapping_eqv(map1[m_keys1[i]], map2[m_keys2[i]]) ) return 0;
                }
                else if( arrayp(map1[m_keys1[i]]) && arrayp(map1[m_keys1[i]]) )
                {
                        if( !array_eqv(map1[m_keys1[i]], map2[m_keys2[i]]) ) return 0;
                }
                else if( map1[m_keys1[i]] != map2[m_keys2[i]] ) return 0;
        }
        return 1;
}
*/

// �� int ����Ԫ��ȫ�����
int int_array_addition(int *arr)
{
        int total;
        
        foreach( int i in arr )
                total+=i;

        return total;
}

// ����
// ([ elem1 : prob1, elem2 : prob2,... ]) 
mixed probability(mapping data)
{
        string *keys = keys(data);
        int *values = values(data);
        int prob, size = sizeof(data);
        
        while(size--)
        {
                prob = int_array_addition(values[0..size]);

                if( random(prob) < values[size] )
                        return keys[size];
        }
}

string big_number_check(mixed bn)
{
        int negtive;
        
        if( !bn ) return 0;
        
        if( intp(bn) )
                return bn+"";
        else if( !stringp(bn) )
                return 0;

        if( bn[0] == '-' )
        {
                bn = bn[1..];
                negtive = 1;
        }

        bn = replace_string(bn, ",", "");

/*
        if( bn[<1] == 'k' || bn[<1] == 'K' )
                bn = bn[0..<2]+"000";
        else if( bn[<1] == 'm' || bn[<1] == 'M' )
                bn = bn[0..<2]+"000000";
        else if( bn[<1] == 'g' || bn[<1] == 'G' )
                bn = bn[0..<2]+"000000000";
*/
        while(bn[0]=='0') bn = bn[1..];

        foreach(int i in bn)
                if( i < '0' || i > '9' )
                        return 0;

        if( bn == "" )
                return 0;
        else 
                return negtive ? "-"+bn : bn;
}

/*
���ƣ�
        object_parse() - ���ط��������������
�﷨��
        object object_parse(string arg, object* objects);
�÷���
        �����ִ� arg �����ݣ���������� objects ֮��ȡ����ȷ�����Ԫ��
        �����ش��������û���κ����Ԫ�ط�����������ش� 0��
        
        ����
                arg Ϊ "rice 2"
                �����Ѱ������� objects �еڶ������Ա���Ϊ rice �����
                ���ڶ��� id("rice") �ش� 1 ֵ�����     
*/
object object_parse(string arg, object* objects)
{
        int which = 1;
        int which_temp;
        string amount;
        string objectname;
        object ob;

        if( !arg || !arg[0] || !sizeof(objects) ) return 0;
        
        // ����ȡ�� which
        if( sscanf(arg, "%s %d", objectname, which) != 2 )
                objectname = arg;

        if( which < 1 ) return 0;

        // ��������﷨���� amount, ��ȡ�� amount �Ĳ���
        if( sscanf(objectname, "%s %s", amount, objectname) == 2 )
        {
                if( !big_number_check(amount) )
                        objectname = amount +" "+ objectname;
        }

        objectname = lower_case(objectname);

        which_temp = which;

        foreach(ob in objects)
                if( ob->query_id(1) == objectname && !(--which_temp) )
                        return ob;

        foreach(ob in objects)
                if( ob->id(objectname) && !(--which) )
                        return ob;

        return 0;
}

/*
���ƣ�
        process_function() - ����ִ�д�����������ݡ�
�﷨��
        void process_function(array arr);
�÷���
        ����˳��ִ�д������������, ����������Ϊ����������ӳ�
        ���������ټ���ִ�н�������Ԫ��, ��Ԫ��Ϊ��ʽָ�����ִ
        ���亯ʽ, ����ʽ�ش� -1, ���������ֹ���� process, ����
        ����Ԫ�ر㲻�ᱻִ�С�
        
        ex: arr = ({ 2, <function1>, 3, <function2>, <function3> })
        �� process_function(arr) ����ȼ���������ִ�� function1,
        �����ټ�� 3 ���������ִ�� function2 �� function3    
*/
void process_function(array fp)
{
        int second;

        if( !sizeof(fp) ) return;
        
        if( functionp(fp[0]) )
        {
                catch{
                        if( evaluate(fp[0]) == -1 )
                                return;
                };
        }
        
        if( intp(fp[0]) )
                second = fp[0];

        call_out((: process_function :), second, fp[1..]);
}

// �������﷨����
string *single_quote_parse(string p)
{
        int i, j, size;
        string *ret = allocate(0), *tmp = explode(p, " ");

        size = sizeof(tmp);

        for(i=0;i<size;i++,j++)
        {
                if( tmp[i][0] == '\'' )
                {
                        ret += ({ tmp[i][1..] });

                        while( ++i < size )
                        {
                                ret[j] += " "+tmp[i];

                                if( tmp[i][0] && tmp[i][<1] == '\'' )
                                {
                                        ret[j] = ret[j][0..<2];
                                        break;
                                }
                        }
                }
                else ret += ({ tmp[i] });
        }

        return ret - ({ "" });
}

