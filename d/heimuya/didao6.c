//room: didao6.c
inherit ROOM;

void create()
{
  set("short","�ص���ͷ");
        set("long", @LONG
�����ǰ��һ������ǰ���Ǳ��ж��죬ǰ������������԰����֪��ʲô�ط���
LONG );
  set("exits",([
      "north"     : "/d/heimuya/xiaohuayuan",
      "northdown" : "/d/heimuya/didao4",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
