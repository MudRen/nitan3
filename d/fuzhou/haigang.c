#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǳ����ıؾ�֮�أ�����ң��̨�壬�м��и�����������һ�����صĵ�
����������ȥ������������һֻ��(chuan)��
LONG );
        set("exits", ([
                "westup" : "/d/fuzhou/yongquan",
        ]));
        set("item_desc", ([
                "chuan" : "һ���󺣴�����Զ��û�����Ĵ��ɲ��С�\n",
        ]));
        set("objects", ([
                "/d/fuzhou/npc/boy": 2,
                "/d/fuzhou/npc/girl": 1,
        ]));
//      set("no_clean_up", 0);
        set("outdoors", "quanzhou");
        set("coor/x", 210);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
//      replace_program(ROOM);
}

void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ;
    //string dir;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
    message_vision("�������𷫣������򶫷����С�\n", ob);
    ob ->move("/d/fuzhou/dahai") ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("tpenghu", 10 , ob );
    return 1 ;
}
void tpenghu(object ob )
{
    tell_object(ob , "С�������˺ܾ�����û�з����κ�½�أ���û�취ֻ�÷��������ĵط���\n" ) ; 
    ob->move("/d/fuzhou/haigang");

}

