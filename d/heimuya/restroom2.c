//restroom2.c
inherit ROOM;

void create()
{
  set("short","��Ϣ��");
        set("long", @LONG
�����Ǽ���Ϣ�ң��������Ŵ󴲡�������˯���ǳ������û���ܴ��š�����
��һ�����ȡ�
LONG );
  set("exits",([
      "north" : "/d/heimuya/chlang3",
  ]));
  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

