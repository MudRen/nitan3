#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIG"��������"NOR,({ "shouyu" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "ֽ");
                set("material", "paper");
                set("long", "����һ�ſհ׵ķ���ר�����ͼ㡣\n");
        }
        set("owner", "���ȴ�ʦ");
}  
