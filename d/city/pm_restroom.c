#include <room.h>
#include <ansi.h>
#include <getconfig.h>
inherit ROOM;

int do_look(string arg);

void create()
{
    set("short", HIY"��Ϣ��"NOR);
        set("long", @LONG
����һ��װ�κ�����ɫ����ů��С���䣬�����ڷ��Ÿ���������档����
��Ƥɳ���������ʣ�������������ﶼ��������������һ�������ҵ���������
��Ϣ�Ҵ���ͨ���ɫ���ȣ���һ��ǽ����һ��С�ţ�ƽ�������ţ�ֻ����ÿ����
һ�ε���ͺڵ�����ʱ����ʦ�ŻὫ֮�򿪡�һ��СС������ (paizi)���ڶ���
ǽ�ϣ�������ʦ�����ڵ������׼��õġ�
LONG );

    set("no_fight",1);
    set("no_beg",1);
    set("no_steal",1);

    set("exits", ([
        "south"  : "/d/city/pm_road8",
    ]));

    set("no_clean_up", 0);
    setup();
}

void init()
{
    add_action("do_look","look");
    if (wiz_level(this_player()) > 2)
    {
        add_action("do_open","open");
        add_action("do_close","close");
    }
}

int do_open()
{
    if (query("exits/north"))
        return notify_fail("���Ѿ��ǿ��ŵ��ˡ�\n");
    set("exits/north","/clone/SHOP/pmc");
    message_vision(HIY"$N����һ�ƣ���ͨ������������С�ſ����ˡ�\n"NOR,this_player());
    shout(HIY + this_player()->name() +  "������������Ϣ��������ͨ�����������Ľ�ɫС�ţ�\n" NOR);
    write(HIY + "�㿪����������Ϣ��������ͨ�����������Ľ�ɫС�ţ�\n" NOR);
    return 1;
}

int do_close()
{
    if (!query("exits/north"))
        return notify_fail("���Ѿ��ǹ��ŵ��ˡ�\n");
    delete("exits/north");
    message_vision(HIY"$N˳��һ������ͨ������������С�Źر��ˡ�\n"NOR,this_player());
    return 1;
}

int do_look(string arg)
{
    int i;
    string msg;
    mapping *SHOP_record;

    if (arg != "paizi") return 0;
    if (!query("exits/north"))
    {
        write("������δ�������ڵ��ʱ�䡣\n");
        return 1;
    }

    SHOP_record = SHOP_D->query_SHOP();
    msg = HIC +LOCAL_MUD_NAME()+ HIY "�ڵ�" HIC " �����׼۱�\n"NOR;
    msg += HIC "-------------------------------------------------------------------------\n" NOR;
    msg += sprintf(HIW"%-20s%-20s%-20s\n"NOR,"�ڵ�ID","�ڵ�����","�����׼�");
    for (i = 0;i < sizeof(SHOP_record);i++)
        msg += sprintf(HIY"%-20s%-20s%-20d\n"NOR,
            SHOP_record[i]["id"],
            SHOP_record[i]["name"],
            SHOP_record[i]["price"]
            );
    msg += HIC "-------------------------------------------------------------------------\n" NOR;
    msg += HIC "һ�� " HIR + chinese_number(sizeof(SHOP_record)) + HIC " �Һڵ�\n";
    write(msg);
    return 1;
}
