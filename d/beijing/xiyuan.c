inherit ROOM;

void create()
{
        set("short", "����ϷԺ");
        set("long", @LONG
������Ǿ����������ĳ���ϷԺ���Ǿ��ǰ�����Ϣ�����ֵļ�����Ϸ
̨���漸��Ϸ�����ڳ�Ϸ��̨�º�ѹѹ��һƬ�����ˡ��������̨�µ�
�����ǽ���ס�����Ȳɡ�����һ��С��ͨ��ϷԺ�ĺ�̨��
LONG );
        set("exits", ([
                "north" : __DIR__"xiyuanup",
                "west"   : __DIR__"wang_10",
        ]));
        set("objects", ([
                __DIR__"npc/guanzhong" : 3,
                __DIR__"npc/xianren" : 1,
                __DIR__"npc/jumin1" : 1,
        ]));
        
        set("coor/x", 10); 
        set("coor/y", 310); 
        set("coor/z", 0); 

        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && userp(me))
        {               
                message_vision(  
                        "ֻ��������һƬ������������һ����ơ����˴���˵����"
                        "��һ�����뿴��λ" + RANK_D->query_respect(me)+ "���ݡ�\n",
                        this_player());
                return ::valid_leave(me, dir);
        }
        else return 1;
}


