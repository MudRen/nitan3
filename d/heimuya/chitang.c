//room: 
inherit ROOM;

void create()
{
  set("short","����");
        set("long", @LONG
����һ��С������������������ԧ��������䣬�ر߻�����ֻ�׺�����ʳ��
LONG );

  set("exits",([
      "north" : "/d/heimuya/baihutang",
//      "west"  : "/d/heimuya/shenggu",
      "east"  :"/d/heimuya/chufang2",
  ]));
  set("objects",([
      "/d/dali/npc/xianhe" : 4,
  ]));
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

