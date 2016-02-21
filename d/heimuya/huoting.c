//ROOM neishi.c
inherit ROOM;
void init();
int do_move(string);
void create()
{
        set("short", "�ɵµ����");
        set("long", @LONG
������������̵ĺ���������ȥ���ǻҳ������м���һ������ (wan)���ƺ�
�йŹ֡�
LONG );
        set("exits", ([
                "east" : "/d/heimuya/house1",
                "west" : "/d/heimuya/restroom",
                "south":"/d/heimuya/chengdedian",
        ]));
        set("objects" , ([
             "/d/heimuya/npc/zish" : 4,
        ]));
        set("item_desc", ([
            "wan" : "����һ���Ժ��������µĹŶ����ܱ��¡�\n",
        ]));
//        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_circle", "circle");
        add_action("do_circle", "zhuan");
}

int do_circle(string arg)
{

        object me = this_player();
        object room;

        if ((arg != "wan") || !arg)
          return notify_fail("��Ҫ��ʲô��\n");
        if((int)me->query("str") < 12)
          return notify_fail("�������������ʲô��\n");
        if(!( room = find_object("/d/heimuya/didao1")) )
           room = load_object("/d/heimuya/didao1");
        if(!objectp(room))  return notify_fail("ERROR:not found 'didao1.c' \n");
        if (!query("exits/down"))
          {
          set("exits/down", "/d/heimuya/didao1");
          message_vision("$N��������������ǽ��¶����һ�������ĵĶ���.\n",me);                    
         room->set("exits/out", "/d/heimuya/huoting");
         return notify_fail("һ��Ҫץ��ʱ�䣬�ߺ������ϡ�\n");
        }
        if(!( room = find_object("/d/heimuya/didao1")) )
           room = load_object("/d/heimuya/didao1");
        if(!objectp(room))  return notify_fail("ERROR:not found 'didao1.c' \n");
        if (!query("exits/down"))
          {
          set("exits/down", "/d/heimuya/didao1");
          message_vision("$N�������룬ֻ����ǽ�򿪣�¶��һ��������
              �Ķ��ڡ�\n",me);
          room->set("exits/out", "/d/heimuya/huoting");
          message("vision", "���洫��һ��ᶯ���������һ���������˽�����
          \n", room);
          }
         else
          {
          delete("exits/down");
          message_vision("�ܿ����ְ����ԭλ����ǽ�ϵĶ����ֱ���ס�ˡ�\n",me);
          room->delete("exits/out");
          message("vision", "���洫��һ��ᶯ������������ڱ���ס�ˡ�\n", room);
          }
       return 1;
}
