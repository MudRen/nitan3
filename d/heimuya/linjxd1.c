// ROOM : linjxd1.c
inherit ROOM;
void create()
{
  set("short","�ּ�С��");
        set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵�����ң�
����ɳɳ�����������㲻���������������ߺ�����һ��ɽ�ȡ� 
LONG );
  set("exits",([
      "south" : "/d/heimuya/linjxd2",
      "north" : "/d/heimuya/linjxd5",     
      "east"  : "/d/heimuya/road1",
      "west"  : "/d/heimuya/guang",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
