// ROOM : linjxd3.c
inherit ROOM;
void create()
{
  set("short","�ּ�С��");
        set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵�����ң�
����ɳɳ�����������㲻��������
LONG );
  set("exits",([
      "south" : "/d/heimuya/linjxd4",
      "north" : "/d/heimuya/linjxd2",     
      "east"  : "/d/heimuya/linjxd5",
      "west"  : "/d/heimuya/linjxd5",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
