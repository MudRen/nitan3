//room: didao4.c
inherit ROOM;

void create()
{
  set("short","�ص���ͷ");
        set("long", @LONG
�����ǰ����һ���⣬���Ǳ��ж��죬ǰ��������еط���
LONG );
  set("exits",([
      "east"   :"/d/heimuya/didao1",
      "west"  :"/d/heimuya/didao3",
      "south" : "/d/heimuya/didao4",
      "southup" : "/d/heimuya/didao6",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
