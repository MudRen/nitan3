// neck.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if (! clonep(this_object()))
	        set("armor_type", TYPE_NECK);

        ::setup();
}

string extra_long()  
{ 

        string str;  

        str =  "��Ʒ����    ��    ����\n"; 
         str += "��    ��    ��    ��Ȧ\n";  
        str += sprintf("��    ��    ��    %d\n", query("armor_prop/armor"));  
       str += sprintf("��    ��    ��    %d\n", this_object()->query_weight());
        str += sprintf("ʹ�÷�ʽ    ��    ����ָ�� wear %s װ����\n", query("id"));  
        str += sprintf("                  ����ָ�� remove %s ж�¡�\n", query("id"));  
        if (this_object()->query_autoload())  
                str += "���߶�ʧ    ��    ��\n";  
        else  
                str += "���߶�ʧ    ��    ��\n";  
        return str;  
 } 
