// SN:A=kGKih_o7K8S`G_
// cruise-ob.c

#include "/clone/misc/cruise-ob.h"

string long() 
{
        string msg; 
        
        msg = query("long"); 
        msg += "��������ȫ��(Koksaver)�����δ��Ͱ���
";
        msg += extra_long();
        
        return sort_string(msg, 64, 0); 
}

