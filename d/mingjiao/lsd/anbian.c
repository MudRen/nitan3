// anbian.c ����
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;

void home( object ob );
void create()
{
        set("short", GRN"����"NOR);
        set("long", @LONG
ֻ����������֮����ľ�д䣬���ͦ�Σ������źü�����ɽ��������
ɽʯֱ�����뺣������ǳ̲��������ˮ���ȴ���Բ��ڰ��ߡ���ʱ�㿴
����Զ����һ����Ϊƽ������ʯ�����汻�����������š����ߵ���������
�֣���໹�м�������̫���С��(zi)������������һ���ܸߵ�ɽ�ڣ���
������һ��ɽ�塣��̲���м�ֻ����������������(tui)�º�ȥ��
LONG );
        set("exits", ([ 
                "eastup" : __DIR__"shanguang",
        ]));
        set("item_desc", ([
                "zi" :HIR"\t\t̤�����ߵ���������\n"NOR
        ]));
        set("boat", 1);
        set("outdoors", "���ߵ�");
        setup();
}

void init()
{
        // add_action("do_push","tui");
        add_action("do_enter","enter");
}

/*
int do_enter()
{
        object me, sea, *inv;
        int i;
        me = this_player();        
        if(!query("boat_on_sea")) return 0;
        if(!(sea = find_object("/clone/misc/sea")))
             sea = load_object("/clone/misc/sea");
        if(sea = find_object("/clone/misc/sea")){
             inv = all_inventory(sea);
             for(i= 0;i< sizeof(inv);i++){
                   if(inv[i]->query("boat_of") == base_name(this_object())){
                          message_vision("$N�����һ���ĵ��ϸߣ����¾ʹ����˺�����\n\n", me);
                          me->move(inv[i]);
                          message("vision",me->name()+"�����һ������������\n",environment(me), ({me}) );
                          return 1;
                   }
             }
        }
        else write("sea boat error, please call wizard. \n");
        return 1;
}       

int do_push(string arg)
{
        object me, ob;
        me = this_player();
        
        if( arg=="chuan" || arg=="��" ) {
            if(me->is_busy()) return notify_fail("����æ���ء�\n");
            if(!query("boat")) return notify_fail("�����Ѿ�û�к����ˡ�\n");
            if(query("boat_on_sea")) return notify_fail("�������Һ����أ���������ȥһ�ң����ǻ���ײ�ġ�\n");
            me->start_busy(5);
            add("boat", -1);
            message_vision("$Nʹ�����̵ľ����������ƽ��˴󺣣�������������ϴ�(enter)�ˡ�\n", me);
            EMOTE_D->do_emote(me,"touch", me->query("id"));
            me->add("jingli", -50);
            ob=new("/clone/misc/boat2");
            ob->set("boat_of", "/d/mingjiao/lsd/anbian");
            ob->set_temp("stepe", 98);
            ob->set_temp("steps", 5);
            ob->move("/clone/misc/sea");
            set("boat_on_sea", 1);
            return 1;
        }
}       

void reset()
{
        set("boat", 1);
        ::reset();
}
*/
int do_enter ( string arg )
{
        object ob ;
        string dir;
        if (! arg || arg != "chuan")
        {
                tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
                return 1 ;
        }
        ob = this_player () ;
        message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
        message_vision("�������𷫣��������������С�\n", ob);
        ob->move("/d/mingjiao/lsd/dahai") ;
        tell_object(ob, BLU "���ں��Ϻ�����������ҹ.......\n" NOR ) ;
        call_out("home", 10 , ob );
        return 1 ;
}
void home( object ob )
{
        tell_object(ob , "�����ڵִ����Ϻ����ߡ������´�����\n" ) ;
        ob->move("/d/beijing/haigang") ;
}


