// SN:C53RN5ZOWFD1A?KO
// cruise-ob.c

#include "/clone/misc/cruise-ob.h"

string long() 
{
        string msg; 
        
        msg = query("long"); 
        msg += "�����Ŷ�С(Testc)�����δ��Ͱ���
";
        msg += extra_long();
        
        return sort_string(msg, 64, 0); 
}

