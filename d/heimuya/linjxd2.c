// ROOM : linjxd2.c
inherit ROOM;
void create()
{
  set("short","�ּ�С��");
        set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵�����ң�
����ɳɳ�����������㲻��������
LONG );
  set("exits",([
      "south" : "/d/heimuya/linjxd1",
      "north" : "/d/heimuya/linjxd3",     
      "east"  : "/d/heimuya/linjxd2",
      "west"  : "/d/heimuya/linjxd2",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
