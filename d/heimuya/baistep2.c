//room: 
inherit ROOM;
void create()
{
  set("short","长廊");
        set("long", @LONG
这里是白虎堂的长廊。两边一片狼籍，看样子刚被洗劫一场，遍地横尸，残
不忍赌。
LONG );
  set("exits",([
     "north" : "/d/heimuya/baistep1",
      "south" : "/d/heimuya/baihutang",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
