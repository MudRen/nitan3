// Room: carol/heimuya

#include <ansi.h>
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_insert(string arg);
int do_push(string arg);
void goto_heimuya(object ob);

void create()
{
    set("short", "����ƺ");
        set("long", @LONG
�����ǰ�ɽ��һƬС��ƺ�����¶�����һ��·;���ɵ����Ѿ�û��·��ȥ��
��ǰ���羳����ͱڣ���ͷ�����������¶���ϡ������¥�������ɾ���������
���ƣ������������������ϴ���һ������(rope)������ȥ�����������»�ͨ��Ϣ
�Ĺ��ߣ������������ƺ���Լ��һ������(basket)�����µ�ǽ���ƺ���һ��ϻ��
(xiazi) �����ƺ�����һ����լ���治֪����Ǻá�
LONG );

    set("exits", ([
        "eastdown" : "/d/heimuya/shimen",
    ]));
    set("objects", ([
        CLASS_D("riyue") + "/zhang1" : 1,
    ]));

    set("outdoors", "heimuya");
    set("no_fight",1);
    set("item_desc", ([
        "basket": "����һ����������������Щ�Ź֡�\n",
        "rope"  : "���Ӿ������ӣ����������ϵĹ��ߡ�\n",
        "xiazi" : "����һ��ϻ�ӣ�������԰�(push)��ȥ��ϻ�ӵĲ�����һ����ס�\n",
    ]));

    setup();
}

void init()
{
    add_action("do_insert", "insert");
    add_action("do_push", "push");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object("/d/heimuya/basket")) )
            room = load_object("/d/heimuya/basket");
        if( room = find_object("/d/heimuya/basket") ) {
            if((int)room->query("insert_trigger")==0 ) {
                room->set("insert_trigger", 1);
                set("exits/enter", "/d/heimuya/basket");
                room->set("exits/out", __FILE__);
                message("vision", "���ȡ���һ���������е������ѱ��۶ϣ�ֻ��һ��"
                        "����(basket)����������㲻��һ����\n", this_object());
                set("item_desc", ([
                    "basket" : "����һ���������Ǵ�˵�еĽ�ͨ���ߡ�\n",
                ]));
                
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "��������õ��²�����\n",this_object() );
        }
        else
            message("vision", "ERROR: basket not found\n", this_object() );
    }
}

void on_board()
{
    object room, me = this_player();
    if( !query("exits/enter") ) return;
    tell_object(me, HIG"ֻ�������������ϣ������������ã�"
                "���ƺ�������һ���˼��ɾ����졣\n"NOR);

    if( room = find_object("/d/heimuya/basket") )
    {
        room->delete("exits/out");
    }
    delete("exits/enter");
    remove_call_out("arrive");
    call_out("arrive",20);
}

void arrive()
{
    object room;
    if( room = find_object("/d/heimuya/basket") )
    {
        room->set("exits/out", "/d/heimuya/up2");
        message("vision", "���һ�������ƺ�һ�´����ϵ��˵��ϡ�\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object("/d/heimuya/basket") )
    {
        room->delete("exits/out");
        room->delete("insert_trigger");
    }
}

int do_insert(string arg)
{
    string dir;
    object ob;
    object me;

    me=this_player();

    if( !arg || arg=="" )   return 0;

    if( arg=="��" )   arg = "card1";

    if( arg=="card1")
    {
        if( !objectp(ob = present(arg, me)) )
                return notify_fail("������û������������\n");
        if( !me->query_temp("mark/cards") )
                me->set_temp("mark/cards",1);
        if( me->query_temp("mark/cards")==4)
        {
                me->delete_temp("mark/cards");
                destruct(ob);
                check_trigger();
        }
        else    {
                me->add_temp("mark/cards",1);
                message("vision", "���һ�����㿴����������һ�ڡ�\n",me );
        }
    }
    else
    {
        if( !objectp(ob = present(arg, me)) )
                return notify_fail("������û������������\n");
        else    return notify_fail(ob->name() + "�������ײ��ϣ���ôҲ�岻��ȥ��\n");
    }
    return 1;
}

int do_push(string arg)
{
    object ob, myenv;
    ob = this_player();

    if( !arg || arg != "xiazi" )
         return notify_fail("��Ҫ push ʲô��\n");

    if (ob->query("family/family_name") == "�������")
    {
         message_vision("$N��ϻ�Ӱ��˼��£�ֻ����֨Ť֨Ť������������������һ���������\n", ob);
         message_vision("$Nһ�������˵��������������ؽ�����ȥ......\n", ob);
         myenv = environment(ob);
         ob->move ("/d/heimuya/basket");
         call_out("goto_heimuya", 10, ob);
         return 1;
    }
    else
         message_vision("$N��ϻ�Ӱ��˼��£�������ûʲô���á�\n",ob);
    return 1;
}

void goto_heimuya(object ob)
{
    tell_object(ob , "����ǰһ����һ������ɫ����������ǰ�����ǻԻ͡�\n");
    ob->move("/d/heimuya/chengdedian");
}

