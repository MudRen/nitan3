// ROOM : linjxd5.c
inherit ROOM;
void create()
{
  set("short","�ּ�С��");
        set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵�����ң�
����ɳɳ�����������㲻����������Ȼ�㷢����������������â��һ����û����
LONG );
  set("exits",([
      "southup" : "/d/heimuya/dating1",
      "north" : "/d/heimuya/linjxd4",     
      "east"  : "/d/heimuya/linjxd3",
      "west"  : "/d/heimuya/linjxd5",
  ]));
  set("objects",([
      "/d/heimuya/npc/wolf" : 4 ,
  ]));
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
