//room: didao1.c
inherit ROOM;

void create()
{
  set("short","�ص�");
        set("long", @LONG
����һ���쳣�ľ������ȣ��������һ�ţ������ʲô���������Ƶ�������
�棬�㲻���뵽���ƺ���ÿ�����䶼��������ɱ����̫�ֲ��ˣ����ܺ�����Ϣ��
�������һ���붼����������ǽ����һ��͹������һ������(button)��
LONG );

  set("exits",([
      "east" : "/d/heimuya/didao2",
      "west" : "/d/heimuya/didao1",
      "south" : "/d/heimuya/didao5",
  ]));
        set("item_desc", ([
            "button" : "����һ��ʯͷ�ϵ�̳�����ͼ��͹�������˸о��е��������ƺ����԰���(push)��\n",
        ]));

  set("no_clean_up", 0);
  setup();
}
void init()
{
        add_action("do_push","push");
        add_action("do_push","an");
}

int do_push(string arg)
{

        object me = this_player();
        object room;

        if ((arg != "button") || !arg)
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }

        if((int)me->query("str") < 12)
        {
                write("�������������ʲô��\n");
                return 1;
        }

        if(!( room = find_object("/d/heimuya/huoting")) )
                room = load_object("/d/heimuya/huoting");

        if (!query("exits/out"))
        {
                set("exits/out", "/d/heimuya/huoting");
                message_vision("$N�����˻��أ�ֻ����ǽ�򿪣���������͸�������\n",me);
                room->set("exits/down", "/d/heimuya/didao1");
                message("vision", "��ǽ����һ��¸����죬¶��һ��������Ķ��ڡ�\n", room);
        }
        else
        {
                delete("exits/out");
                message_vision("�ܿ�����ֱ����ԭ���������ֱ���ס�ˡ�\n",me);
                room->delete("exits/down");
                message("vision", "��ǽ����һ��¸����죬���ڱ���ס�ˡ�\n", room);
        }
        return 1;
}

