// Room: /u/poq/sdxl/dongkou.c ����
// by poq@jyqx 97/7
// alter dubei
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "����"NOR);
    set("long", 
"���³�����ϥ��һƬ�ž�������ǰ��һ����ɽ�������Ϸ����İ�����ȡ�"
);

    set("exits", ([
        "southeast" : __DIR__"xiaolu3",
        "enter" : __DIR__"shandong",
    ]));

    set("outdoors", "xiangyang");

    set("item_desc", ([
        "dong" : "ɽ�����������ģ��㿴�����κζ�����\n",
	]));

    setup();
    (CLASS_D("ultra") + "/dugu")->come_here();  
}

 
string long()
{
        object ob;   
        string msg;   

        msg = query("long"); 
        if (! objectp(ob = present("dugu qiubai", this_object())))   
                msg += "\n";
        else if (! ob->is_fighting())   
                msg += "ֻ��һ�����ڵ��ϣ����б���һ���񽣣����˸�"  
                       "ȥ�Ŀ���Ҳ��֪�����о�ʲô��\n";   
        else   
                msg += "ֻ��һ��������" +   
                       (ob->is_fighting(this_player()) ? "��" : "��") +   
                       "��ս����ʩչ������Ȼ��ŵ������������Ƿ�����˼��\n";   
           return sort_string(msg, 64, 4);   
}
