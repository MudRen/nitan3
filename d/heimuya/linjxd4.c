// ROOM : linjxd4.c
inherit ROOM;
void create()
{
  set("short","�ּ�С��");
        set("long", @LONG
������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵�����ң�
����ɳɳ�����������㲻��������
LONG );
  set("exits",([
      "south" : "/d/heimuya/linjxd6",
      "north" : "/d/heimuya/linjxd1",     
      "east"  : "/d/heimuya/linjxd2",
      "west"  : "/d/heimuya/linjxd5",
  ]));
        set("objects", ([
            CLASS_D("riyue") + "/renwoxing": 1,

        ]));

  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
