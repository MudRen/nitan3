//room: house1.c
//Updated by haiyan

inherit ROOM;

void create()
{
     set("short","����");
        set("long", @LONG
����һ�����ŵ�С�ᣬһ���ű���ŵ�һ��Ũ���Ļ��㡣���й���һ����Ů
���ͼ��ͼ�л��������װ��Ů����Ŀ���⣬�������ס����ﻹ��һ�Ų輸(tea
poy)���������ӣ������������廨���棬������һ�ȶ�����ͨ�������
LONG );

     set("exits",([
         "west" : "/d/heimuya/huoting",
     ]));

     set("valid_startroom", 1);
     set("item_desc", ([
         "teapoy": "���Ų輸�ƺ����������ƶ�����\n",
     ]));

     setup();
}

void init()
{
     add_action("do_move", "move");
     add_action("do_move", "push");
}

void close_path()
{
     if (! query("exits/enter"))   return;
     message("vision","�輸���Զ����˻�������ס����ڡ�\n", this_object());
     delete("exits/enter");
}

int do_move(string arg)
{
     if (! arg || arg != "teapoy" )
        return notify_fail("ʲô��\n");
     else
     {
        write("��Ѳ輸�ƿ���¶����һ��ͨ����\n");
        if (! query("exits/enter"))
        {
            set("exits/enter", __DIR__ "midao01");
            call_out("close_path", 5);
        }
        return 1;
     }
}
