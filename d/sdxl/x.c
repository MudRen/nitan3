#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("exits", ([
                "out"   : __DIR__"s",
        ]));

        set("long", @LONG
����һ��տ���ʯ�ң���Զ���и�һʯ�ʣ��㲻��������
�����������������������������߲�����ѧ���߾��硣��
��Լ����ǰ��ʯ�ڣ�bi�������ǿ���ʲô������
LONG);
        set("item_desc", ([
               "bi"  :   HIW "\n\t\t�o\n\t\t��\n\t\tʤ\n\t\t��\n\t\t��\n\n��" NOR,
        ]));                       
        
        set("no_clean_up", 0);
        setup();

}
void init()
{
        object ob;
        
        ob = find_object("/clone/book/dugubook");
        if (! ob) ob = load_object("/clone/book/dugubook");
        if (! environment(ob))
        {
                ob->move(this_object());
        }
}

