#include <ansi.h>

inherit ROOM;

void home(object ob);

void create()
{
    set("short", "��̲");
        set("long", @LONG
��������������ˡ��ϱ���һ���޼ʵĴ󺣣���������һƬ��ľ�֡����ϵ�
�����ƺ���������, ��ʪ�ĺ����д���һ���ȳ�, �ּ�����һ�����صĻ���, ��
����ʮ�ֹ��졣���߲���һ�Ҵ�(chuan)��
LONG );

    set("item_desc", ([
        "chuan" : "�������ߵ�������ϵ�Ĵ󴬡����ϵĿ��˻����ֻҪ\n"
                  "�ϴ�(enter)�Ϳ��Ի���ԭ��\n",
    ]));
    set("exits",([
        "north" :__DIR__"lin1",
        "west" :__DIR__"stone",
    ]));
        set("navigate",1);
        set("opposite","/d/beijing/haigang");
    set("outdoors", "shenlong");
    setup();
}

void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ;
    string dir;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
    message_vision("�������𷫣��������������С�\n", ob);
    ob ->move(__DIR__"dahai") ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("home", 10 , ob );
    return 1 ;
}
void home( object ob )
{
    if (! objectp(ob))
	return;
        if (base_name(environment(ob)) != "/d/shenlong/dahai")
                return;
    tell_object(ob , "�����ڵִ�����ԭ��һ���������С������´�����\n" ) ;
    ob->move ("/d/beijing/haigang") ;
}


