// Room: /d/jyszhuang/mishi.c
// by Lonely

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������м��߰׹����� ֻ����빬����Ȼ���ݣ������ж����˻�ɳ;
�������ƺ�����·����������վ��һ�����õ�ס��ȥ·��

LONG   
        );

        set("exits", ([
                "down" : __DIR__"mishi2"
        ]));

        set("outdoors", "gaochang");
        setup();
}

void init()
{

        object ob, room;
        ob = this_player();
        room = this_object();

        if (ob->query("id") == "lonely" || !living(ob)) return;
    else if     ( present("map", ob)){
        message_vision(HIW"\nͻȻ֮�䣬ǰ��һ����ɭɭ������˵����
����Ȼ���е�֮ʿ!��ô���о���ɽׯ�Թ��ĵ�ͼ,�ѵ������⣿\n
����ɽׯ����ей��ĲƸ��𣿹��������������� \n
Ц����͸�����޵������ͱ�״��\n\n" NOR, ob);
        }
    else {
        message_vision(HIW"\nͻȻ֮�䣬ǰ��һ����ɭɭ������˵����
�ô�����ɽׯ�Թ�����! ֻ��һ�������Ϯ���������Ҳ�㲻���ˡ�
ԭ����һ���������������塣\n\n" NOR, ob);
        this_player()->die();
        }

}

