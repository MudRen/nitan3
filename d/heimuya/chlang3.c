//chlang3
inherit ROOM;

void create()
{
  set("short","����");
        set("long", @LONG
�����Ƿǳ����ɵĳ��ȣ��䱸ɭ�ϡ����߾����������ʥ���δ�С��ľ��ҡ�
LONG );
  set("exits",([
      "east"  : "/d/heimuya/shenggu",
      "west"  : "/d/heimuya/dating4",
      "south" : "/d/heimuya/restroom2",
  ]));                     
  set("no_fight",0);
  set("no_steal",0);
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

